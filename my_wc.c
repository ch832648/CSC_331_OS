/*
NAME: Caitlin Harris
DATE: 3/11/2020
PROGRAM: my_wc.c
DESCRIPTION:
-text file as specified by the user, counts the number of lines, words, and characters within the files based on the options 
(or the lack thereof), and prints out the values of each file on a single line, with each value separated by a single white space. 
The name of that file is printed out at the end of that line, separated by a single white space. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

//Total counts
int totalLines = 0;
int totalWords = 0;
int totalChars = 0;

//isLines: returns whether arg is -l
bool isLines(char charArray[]){
    if(strncmp("-l", charArray, 2) == 0){
        return true;
    }
    else{
        return false;
    }
}
//isWords: returns whether arg is -w
bool isWords(char charArray[]){
    if(strncmp("-w", charArray, 2) == 0){
        return true;
    }
    else{
        return false;
    }
}
//isChars: returns whether arg is -c
bool isChars(char charArray[]){
    if(strncmp("-c", charArray, 2) == 0){
        return true;
    }
    else{
        return false;
    }
}

void processFile(FILE *file){
int c; 
int prev = -1;
int lines, words, chars;
lines = words = chars = 0;

while((c = fgetc(file)) != EOF){
    //Test for word
    if(isspace(c) && prev > 0 && !isspace(prev))
        ++words;

    if(c == '\n')
        ++lines;
    //keep track of previous char
    prev = c;
    //update characters
        ++chars;
}
    //if the last word in the file is a char
    if(chars > 0){
        if(!isspace(prev)){
            ++words;
        }

    }
    //++lines;
    //add to the global sums
    totalLines += lines;
    totalWords += words;
    totalChars += chars;
}

int main(int argc, char *argv[]){


//check if no args were in the command line- ERROR
if(argc == 1){
    printf("my_wc: [option ...] [file ...]\n");
    exit(1);
}

//position of the first file and total arguments
int firstFile;
int totalArgs = 0;
//total line commands & lines flag
bool linesFlag = false;
int linesTotal = 0;
//total word commands & words flag
bool wordsFlag = false;
int wordsTotal = 0;
//total char commands & chars flag
bool charsFlag = false;
int charsTotal = 0;

//check user input for -l, -w, and -c
for(int i = 1; i < argc; i++){
    char *temp3 = argv[i];
    if(isLines(temp3)){
        totalArgs++;
        linesFlag = true;
        linesTotal++;
    }
    else if(isWords(temp3)){
        totalArgs++;
        wordsFlag = true;
        wordsTotal++;
    }
    else if(isChars(temp3)){
        totalArgs++;
        charsFlag = true;
        charsTotal++;
    }
    else{
        firstFile = i;
        break;
    }
}

//Loop through files, beginning at firstFile position
for(int k = firstFile; k < argc; k++){
    //process file
    char *fileName = argv[k];
    FILE *myFile = fopen(argv[k], "r");
    processFile(myFile);

    if(!myFile){
    //if we get an error code, exit program
    printf("my_wc: cannot open file\n");
    fclose(myFile);
    exit(1);
    }

    //No command options- ERROR
    if(firstFile == 1){
        printf("%d %d %d %s\n", totalLines, totalWords, totalChars, fileName);
        totalLines = totalWords = totalChars = 0;
        fclose(myFile);
    }
    //Too many command options- ERROR
    else if(totalArgs > 3){
        printf("my_wc: [option ...] [file ...]");
        fclose(myFile);
        exit(1);
    }
    //Duplicates- ERROR
    else if(linesTotal > 1 || wordsTotal > 1 || charsTotal > 1){
        printf("my_wc: [option ...] [file ...]");
        fclose(myFile);
        exit(1);
    }
    else{
        if(linesFlag == true){
            printf("%d ", totalLines);
        }
        if(wordsFlag == true){
            printf("%d ", totalWords);
        }
        if(charsFlag == true){
            printf("%d ", totalChars);
        }
        printf("%s\n", fileName);

        totalLines = totalWords = totalChars = 0;
        fclose(myFile);
    }

}
return 0;
    
} //END OF MAIN

