#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <dirent.h>
#include "game.h"
#include <sys/stat.h>

void printMenu(char choice[],char path[],char []);
void playGame(char path[]);
void printSettings();
void Randomline(FILE *ptrFile,char *address,char randomWord[],char cat[]);
void fileOrFolder(char path[],char choosen[]);
int isFile(char []);
int randomNumber(int);

#define Size 70

typedef int bool;
#define true 1
#define false 0


int main(int argc, char *argv[]) 
{
        
        char input[5] = " ";
        char *address = argv[1];     
        while(strcmp(input,"quit")!=0)
        {
            printMenu(input,address,input);
        }
	return 0;
}

void printMenu(char choice[],char path[],char input[])
{
    system("clear");
    printf("********************************\n");
    printf("*                              *\n");
    printf("*       type quit to quit      *\n");
    printf("*                              *\n");
    printf("*        **************        *\n");
    printf("*        *   Play     *        *\n");
    printf("*        **************        *\n");
    printf("*                              *\n");
    printf("*        **************        *\n");
    printf("*        *  Settings  *        *\n");
    printf("*        **************        *\n");
    printf("*                              *\n");
    printf("*                              *\n");
    printf("********************************\n");
    scanf("%s",input);
    
    if(strcmp(input,"play")== 0||strcmp(input,"Play")== 0)
    {       
        playGame(path);
    }
    else if(strcmp(input,"settings")== 0||strcmp(input,"Settings")== 0)
    {       
        printSettings();
    }
   
    
}
void playGame(char path[])
{
    FILE *ptrFile;
    char gameInput[Size] = "";
    char randomWord[Size] = "";
    char catWord[Size] = "";
    
    fileOrFolder(path,gameInput);
    Randomline(ptrFile,gameInput,randomWord,catWord);
    
    engine(randomWord,catWord);
    
}

void printSettings()
{
    system("clear");
    char userInput[Size];
    printf("********************************\n");
    printf("*                              *\n");
    printf("*                              *\n");
    printf("*      Enter file or folder    *\n");
    printf("*                              *\n");
    printf("*                              *\n");
    printf("*                              *\n");
    printf("*                              *\n");
    printf("*                              *\n");
    printf("*                              *\n");
    printf("********************************\n");
    scanf("%s",userInput);
    if(strstr(userInput,"back"))
    {
        
    }
    else
    {
         playGame(userInput);
    }
    
}
void Randomline(FILE *ptrFile,char *address,char randomWord[],char cat[])
{
   
    ptrFile = fopen(address,"r");
    if(ptrFile == NULL)
    {   
        perror("Not A Valid File!");
    }
    else
    {
        int count = 0;  
        int random = 0;    

        char tempLine[Size];

        fseek(ptrFile, 0,SEEK_END);   
        count = ftell(ptrFile);

        srand(time(NULL));
        random = rand()%count;
        fseek(ptrFile,random, SEEK_SET );


        fgets(tempLine,60,ptrFile); // skip a line incase random place is in middle of line
        fgets(randomWord,60,ptrFile);
        fseek(ptrFile,0,SEEK_SET);
        fgets(cat,60,ptrFile);

        fclose(ptrFile);
    }
    
    
    
    
}
void fileOrFolder(char path[],char choosen[])
{
    char *input[Size];
    int counter = 0;
    if(isFile(path) == true)
    {
        struct dirent *entry;
        DIR *dp;
        dp = opendir(path);
        int counter = 0;

        if (dp == NULL) 
        {
            perror("opendir1 ");
            
        }
        while((entry = readdir(dp)))
        {
            if(strstr(entry->d_name,".txt")!= NULL)
            {
                input[counter] = entry->d_name; 
                counter ++;
            }
        }

      closedir(dp);
      strcat(choosen,path);
      strcat(choosen,"/");
      int random = randomNumber(counter);
      strcat(choosen,input[random]);
    }
    else
    {
        strcat(choosen,path);
    }
  
}
bool isFile(char path[])
{
    struct stat s;
    stat(path, &s);   
    return S_ISDIR(s.st_mode)!=0;
    

}
int randomNumber(int max)
{
     srand(time(NULL));
     int random = rand()%max;
     return random;
}