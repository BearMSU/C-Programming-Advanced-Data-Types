#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

void printDate(struct date);
void readDate(struct date *);

int main(void) {
	struct date today;
	readDate(&today);
	printDate(today);
	return 0;
}
// this is essentially the same as the previous solution, except putting it all in one statement.
void readDate(struct date *nowptr) {
    scanf("%d%d%d", &((*nowptr).year), &((*nowptr).month), &((*nowptr).day));
}
// this is also the same as the previous solution, except the year was padded for four zeros using %4d
void printDate(struct date now) {
    printf("%02d/%02d/%4d\n", now.month, now.day, now.year);
}
