/* 
NAME: Caitlin Harris
DATE: 2/12/2020
FILE NAME: payroll.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]) {

//command line arguements: name, hours, pay
char *first_name = argv[1];
char *last_name = argv[2];
int hours_worked = (atof(argv[3]) + 0.5);
double hourly_rate = atof(argv[4]);
double total_payment = 0;

//calculate total pay
total_payment = hours_worked * hourly_rate;
//print total payment
printf("%s, %s: %.2lf", last_name, first_name, total_payment);

return 0;

}