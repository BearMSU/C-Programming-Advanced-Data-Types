#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

void readDate(struct date *);
void printDate(struct date);

int main(void) {
	struct date today;
	readDate(&today);
	printDate(today);
	return 0;
}
// Function to read the data - This function dereferences the pointers to hold the days in memory
void readDate(struct date *dptr){
    scanf("%d", &(*dptr).year);
    scanf("%d", &(*dptr).month);
    scanf("%d", &(*dptr).day);
}
// This function prints the date in American format - note the %02d is to pad the 0 in front of single digits
void printDate(struct date now){
    printf("%02d/%02d/%d", now.month, now.day, now.year);
}
