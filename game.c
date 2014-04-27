/* File: hangman.c
 * StudentID: 2113274
 *
 * Bonus Attempted: N
 *
 * This program implements the game, Hangman. 
 *
 * Comments
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "game.h"


#define Size 70
#define wordLength 30
#define ClearLength 40

typedef int bool;
#define true 1
#define false 0

void engine(char mysteryWord[], char *cat) 
{

    int Length = strlen(mysteryWord);
    int lifeLost = 0;
    int occurances = 0;
    int wrongCharOccurances = 0;
    char input = '\n'; // made to \n so it will be ignored in the first loop

    char HiddenWords[wordLength * 2] = "";// Initialize all to 0
    char wrongChars[11] = ""; //InitializeArray(wrongChars,11); 
    
    hideWord(Length,mysteryWord, HiddenWords);

    while (lifeLost < 10 && contains(HiddenWords, '_', Length * 2) > 0) 
    {
        printScreen(lifeLost, cat, mysteryWord, HiddenWords, wrongChars);
        scanf("\n%c", &input); // /n*c added so that new line char is ignored when enter button is pressed      
        if (lifeLost < 10 && input != '\n')
        {

            occurances = contains(mysteryWord, input, Length); // check if users guess is right
            wrongCharOccurances = contains(wrongChars,input,Length); //check if user has had the same guess before
            if(wrongCharOccurances == 0) // if user has not entered input before
            {
                if (occurances == 0) // If input is a wrong answer 
                {
                  wrongChars[lifeLost] = input;
                  lifeLost = lifeLost + 1;
                }
                 else 
                 {
                  changeWord(mysteryWord, HiddenWords, input,Length);
                 }
            }
        }


    }
    if (lifeLost == 10)
        
    {
        printScreen(lifeLost, cat, mysteryWord, HiddenWords, wrongChars);
        printf("You Lose!");
    }
    else {

        printScreen(lifeLost, cat, mysteryWord, HiddenWords, wrongChars);
        printf("You Win!\n");
    }
}

void hideWord(int length,char mysteryWord[], char word[])
{
    
    for (int i = 0; i <= length - 1; i++) 
    {

        if (isalpha(mysteryWord[i]) != 0) 
        {          
            word[i * 2] = '_';
            if(i!=0)
            {
                word[(i*2)-1]= ' ';                
            }
        } else 
        {
            word[i * 2] = mysteryWord[i];
            if(i!=0)
            {
                word[(i*2)-1]= ' ';                
            }
            
        }


    }



}


void changeWord(char mysteryWord[], char *hiddenWord, char input,int length) 
{

    char flipInput; // input case is flipped
    
   
    if (isupper(input) != 0) 
    {
        flipInput = tolower(input);
    } 
    else 
    {
        flipInput = toupper(input);
    }
    for (int i = 0; i < length; i++)
    {
        if (mysteryWord[i] == input) // compares every element to user input
        {
            
            hiddenWord[i*2] = input;
        } else if (mysteryWord[i] == flipInput) // compares element to lowered Input
        {
         
            hiddenWord[i*2] = flipInput;

        }



    }
}

int contains(char mysteryWord[], char input, int arrayLength)
{
    int a = 0;
    if (isalpha(input) == false && input != '_') 
    {
        return -1;
    }
    char flipInput;
    
    if (isupper(input) != 0)
    {
        flipInput = tolower(input);
    } 
    else 
    {
        flipInput = toupper(input);
    }

    for (int i = 0; i < arrayLength; i++)
    {
        if (mysteryWord[i] == input || mysteryWord[i] == flipInput) 
        {
            a = a + 1;
        }

    }

    return a;


}

void printHangMan(int livesUsed)
{
    switch (livesUsed) {
        case 0:
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            break;
        case 1:
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf(" ___________\n");
            break;
        case 2:

            printf("\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|___________\n");
            break;
        case 3:
            printf("___________\n");
            printf("|/\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|___________\n");
            break;
        case 4:
            printf("___________\n");
            printf("|/    |\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|___________\n");
            break;
        case 5:
            printf("___________\n");
            printf("|/    |\n");
            printf("|     O\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|___________\n");
            break;
        case 6:
            printf("___________\n");
            printf("|/    |\n");
            printf("|     O\n");
            printf("|     | \n");
            printf("|\n");
            printf("|\n");
            printf("|___________\n");
            break;
        case 7:
            printf("___________\n");
            printf("|/    |\n");
            printf("|     O\n");
            printf("|     |\\ \n");
            printf("|\n");
            printf("|\n");
            printf("|___________\n");
            break;
        case 8:
            printf("___________\n");
            printf("|/    |\n");
            printf("|     O\n");
            printf("|    /|\\ \n");
            printf("|\n");
            printf("|\n");
            printf("|___________\n");
            break;
        case 9:
            printf("___________\n");
            printf("|/    |\n");
            printf("|     O\n");
            printf("|    /|\\ \n");
            printf("|      \\\n");
            printf("|\n");
            printf("|___________\n");
            break;
        case 10:
            printf("___________\n");
            printf("|/    |\n");
            printf("|     O\n");
            printf("|    /|\\ \n");
            printf("|    / \\\n");
            printf("|\n");
            printf("|___________\n");
            break;




    }
}

void printScreen(int lifeLost, char *cat, char mysteryWords[], char HiddenWords[], char wrongChars[])
{
    system("clear");
    printf(" HangMan! \n");
    printHangMan(lifeLost);
    printf(" %s ", cat);
    printf(" %s \n", wrongChars);
    printf(" %s \n", HiddenWords);
}





