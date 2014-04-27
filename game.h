/* 
 * File:   game.h
 * Author: ryanremer
 *
 * Created on 26 April 2014, 21:34
 */

#ifndef GAME_H
#define	GAME_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* GAME_H */

/*
 * contains takes in the mysteryWord array,its length and the user input
 * it returns how many times the input occurs in the array
 *
 */
int contains(char[], char, int);
/*
 * hideWord takes in the mysteryWord array and returns a new array pointer
 * based on the hideWord array but with all the letter replaced to underscores
 * 
 * 
 * every other element in the returned array is also made a space so the array can 
 * be printed correctly 
 * 
 * the new array has to be twice the length of the original because of the extra
 * spaces.
 * If a letter is found at the ith element in the mysteryWord at must be made an
 * underscore in the hiddenWord at the i*2 element as even elements are spaces.
 * 
 * spaces in the mysteryWord remain spaces in the hiddenWord they do not got made
 * into underscores.
 */
void hideWord(int,char [], char []);
/*changeWord takes in the user input
 * The Mystery word p[]
 * and the hidden word *a
// * 
 * for loop loops round the mystery word comparing every item to the input  
 * and if it is found it then displays the input in the hidden word array 
 * 
 * The first element in the Mystery word corresponds to the 1st in the hiddenArray
 * But the 2nd element corresponds to the 3rd in the hiddenArray due to there being spaces
 * in every other element;
 * 0   1   2   3
 *[B] [O]  [B] [S]  (Mystery word)p[]
 *[_] [ ]  [_] [ ]  (Hidden word)*a
 *
 * if the user input O it would be found in the 1st element of the MysteryArray
 * but would be added to the 2nd in the hiddenArray it is alway i*2
 * 
 * If the user enter a lower case letter it is converted to an uppercase and 
 * then compared to the array if it finds a match it is added to the hiddenWord array
 *
 *If the user enters a uppercase letter is converted to a lowercase 
 *
 *
 */
void changeWord(char [], char *, char,int);
/*Possible the worst looking function ever but it's fairly simple.
 * 
 * due to the varying length of the mystery word different amounts of spaces need
 * to be printed the function takes in the width of the game screen prints the
 * corresponding amount of spaces.
 * 
 * printHangMan takes in how many lives have been lost
 * and then prints out the corresponding hangman drawing
 */
void printHangMan(int);
/*engine is the function that loops the hangman game play
 * Variables
 *         Length-Is a int that stores the length of the mystery word
 *                it is used when searching char arrays
 *         lifeLost- Stores how many wrong guesses the user has had
 *          
 *         occurances - Stores how many times a users input is found in the mystery word
 *      
 *         wrongCharOccurances - Stores how many times a user has input a value
 *                                more then once.
 *  
 *          HiddenWords - The String that has the hidden version of the mystery word
 *          
 *          wrongChars - stores the letters inputted by the user that where not in the mystery word
 *          
 *                           
 *
 */
void engine(char [], char *);
void printScreen(int , char *, char [], char [], char []);
int randomNumber(int max);