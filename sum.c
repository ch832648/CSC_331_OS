/* 
NAME: Caitlin Harris
DATE: 2/12/2020
FILE NAME: sum.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]){

FILE *myFile;
myFile = fopen(argv[1], "r");

int numArr[10];
int sum = 0;
int i;

//Error message if file fails
if(myFile == NULL){
    printf("Error when trying to read file");
    exit(0);
}

else{
//read integers from file and add to sum
for(i = 0; i < 10; i++){
    fscanf(myFile, "%d", &numArr[i]);
    sum+=numArr[i];
}
}
//close file
fclose(myFile);
//print sum
printf("%d", sum);

return 0;
}