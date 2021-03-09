/*
NAME: Caitlin Harris
DATE: 3/11/2020
PROGRAM: my_cat.c
DESCRIPTION:
-Reads a text file and prints out the contents as is
-Can be one or more text files
-NONERROR CASES: exit w/ return 0, if no files exit program w/ 0
-FILE READ FAIL: "my_cat: cannot open file\n" exit w/ status code 1
-MULTIPLE FILES: files printed out in order until end of file or error is reached
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>

int main(int argc, char *argv[]){

//printf("Total number of files: %d\n", argc);
bool flag = false;
char c;

//create file
FILE *myFile;

for(int i = 1; i <argc; i++){

myFile = fopen(argv[i], "r");

if(argc == 1){
    //if file no files are specified in the command line
    break;
}
else if(errno >= 1 || myFile == NULL){
    //if we get an error code, break loop, exit program
    printf("my_cat: cannot open file\n");
    flag = true;
    break;
}
else{
    //if no error, print the contents and move onto the next file
    c = fgetc(myFile);

        while(c != EOF){
        printf("%c",c);
        c = fgetc(myFile);
        }
    fclose(myFile);
    }

}

//if there was an error, return 1
if(flag)
    return 1;
//else return 0
else
    return 0;    
}


