/*
NAME: Caitlin Harris
DATE: 3/11/2020
PROGRAM: my_grep.c
DESCRIPTION:
- search term passed with 0 or more files
-goes through lines of file, if word is found, the line is printed
-searching is case sensitive (foo != Foo)
-if no command line args: "my_grep: searchterm [file ...]\n", exit 1
-if file not openable: "my_grep: cannot open file\n", exit 1
-otherwise, program exits 0
-if [] empty string is passed, all lines are equal
-if no file is specified, my_grep should read from standard input
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>

 int main(int argc, char *argv[]){

//create file
FILE *myFile;
char *line = NULL;
size_t length = 0;
ssize_t read;

char *searchTerm = argv[1];

//no command line args
if(argc == 1){
    printf("my_grep: searchterm [file ...]\n");
    exit (1);
}
//only argument is the search term, compare with user input
else if (argc == 2){
    while((read = getline(&line, &length, stdin)) != -1){
            if(strstr(line, searchTerm) != NULL){
                printf("%s", line);
            }
        }

}
//if there is more than 2 args, begin at the first file
else if(argc > 2){

    for(int i = 2; i < argc; i++){
        //try to open file
        myFile = fopen(argv[i], "r");

        //if file cannot be opened, error message
        if (errno >= 1 || myFile == NULL){
         printf("my_grep: cannot open file\n");
         fclose(myFile);
         exit(1);
        }
        //read file lines, compare search term, return lines with search term
        while((read = getline(&line, &length, myFile)) != -1){
            if(strstr(line, searchTerm) != NULL){
                printf("%s", line);
            }
        }
        fclose(myFile);


    }
}
exit(0);
}




