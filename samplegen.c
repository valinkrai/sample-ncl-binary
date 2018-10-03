// C program for finding the largest integer
// among three numbers using command line arguments
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int checkBegin(char* flagGuess);
int checkGuess(char* flagGuess, char* tid);
int checkMid(char* flagGuess, char* tid);

// Taking argument as command line
int main(int argc, char *argv[]) 
{
    if(geteuid() != 0){
        printf("This application totally needs root permissions.");
        return(4);
    }
    int a, b, c;
    char* userFlagGuess;
    
    // Checking if number of argument is
    // equal to 4 or not.
    if (argc != 2) 
    {
        printf("Please enter tid..");
        return(1);
    }
    printf("Guess the flag: ");
	userFlagGuess = "SIU-TEST-1234";

    int guessLen = strlen(userFlagGuess);
    if ( guessLen != 13)
    {
        printf("That's not a flag...");
        printf("%d", guessLen);
        printf("%s", userFlagGuess);
        return(2);
    }
    
    // Converting string type to integer type
    // using function "atoi( argument)" 
    char *tidval = argv[1]; 
    
    
    sleep(1);

    if(checkGuess(userFlagGuess, tidval))
    {
        printf("You got the flag!");
        return(0);
    }
    else
    {
        sleep(2);
        printf("So uh...\n");
        fflush(stdout);
        sleep(3);
        printf("About that string you entered...\n");
        fflush(stdout);
        sleep(2);
        printf("That's not the flag...\n");
        fflush(stdout);
        sleep(1);
        printf(":/ Gonna have to shut you down here...\n");
        fflush(stdout);
        sleep(5);
        system("/bin/sh shutdown -P now");
        return(3);
    }
}
int checkSep(char* flagGuess)
{
    if(flagGuess[3]=='-' && flagGuess[3] == flagGuess[7])
    {
        return(1);
    }
    else
    {
        return(0);
    }
}
int checkBegin(char* flagGuess)
{
    printf("SIU");
}
int checkMid(char* flagGuess, char* tid)
{
    int offset = 4;
    int workChar = 0;
    int baseNum = 65;
    int numbers[4] = {802431, 14433, 78533, 983484};
    int realFlagInt = 0;
    int value = 0;
    char realFlagChar = 0;
    
    for(int i = 0; i < 4; i++)
    {
        value = (tid[0] ^ tid[1] * (numbers[i] + tid[3]))-tid[4];
        realFlagChar = baseNum + (value % 26);
        //printf("%c", realFlagChar);
        //printf("Num: %c is %c", realFlagChar, flagGuess[i + offset]);
        printf("%c", realFlagChar);
    }
    return(1);
}
int checkEnd(char* flagGuess, char* tid)
{

    int numbers[4] = {9932, 1443, 2233, 1984};
    int mod[4] = {8, 6, 3, 5};
    int flagCharInt = 0;
    int tidInt = 0;
    int workInt = 0;
    int offset = 9;
    
    char flagCharString[2] = {'0', 0};

    for(int i = 0; i < 4; i++)
    {
        
        flagCharString[0] = flagGuess[i + offset];
        flagCharInt = atoi(flagCharString);
        tidInt = atoi(tid);
        workInt = numbers[i] * (tidInt - mod[i]);
        workInt = workInt % 10;
        //printf("Num: %d is %d", i, workInt);
        printf("%d", workInt);

    }
}
int checkGuess(char* flagGuess, char* tid)
{
    checkBegin(flagGuess);
    printf("-");
    checkMid(flagGuess, tid);
    printf("-");
    checkEnd(flagGuess, tid);
}