/* 
NAME: Caitlin Harris
DATE: 2/12/2020
FILE NAME: sort.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Swap Integers Function
void swap(int* xp, int* yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
//Selection Sort Function
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
  
    //move through unsorted array
    for (i = 0; i < n - 1; i++) { 
  
        //minimum element in unsorted array 
        min_idx = i; 
        for (j = i + 1; j < n; j++) 
            if (arr[j] < arr[min_idx]) 
                min_idx = j; 
  
        //Swap the found minimum element with the first element 
        swap(&arr[min_idx], &arr[i]); 
    } 
} 

// Function to print an array  
void printArray(int arr[], int total) 
{ 
    int i; 
    for (i = 0; i < total-1; i++){ 
        if(i != total-2)
        printf("%d ", arr[i]);
        else
        printf("%d", arr[i]);
    }
} 

int main(int argc, char *argv[]){

//open file
FILE *myFile;
myFile = fopen(argv[1], "r");

//total integers in file, counter, temporary value
int total = 0, i = 0, temp = 0;

//read file to get total count of integers
if(myFile != NULL){
    while(!feof(myFile)){
        fscanf(myFile, "%d", &temp);
        total++;
    }
}

//adjust pointer in the file
rewind(myFile);

//numArr: array to be sorted
int numArr[total];
int n = sizeof(numArr) / sizeof(numArr[0]);

//read integers from file and add to numArr
for(i = 0; i < total; i++){
    fscanf(myFile, "%d", &numArr[i]);
}

//close file
fclose(myFile);

//sort and print new array  
selectionSort(numArr, n); 
printArray(numArr, n); 

return 0;
    
}