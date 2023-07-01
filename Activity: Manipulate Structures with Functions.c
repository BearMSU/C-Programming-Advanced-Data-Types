#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };
/* function prototypes */
void readDate(struct date *);
void printDate(struct date);
struct date advanceDay(struct date);

int main(void) {
	struct date today, tomorrow;
	readDate(&today);
	printDate(today);
	tomorrow = advanceDay(today);
	printDate(tomorrow);
	return 0;
}
// Read Date Function
void readDate(struct date *nowptr) {
    scanf("%d%d%d", &((*nowptr).year), &((*nowptr).month), &((*nowptr).day));
}
// Print Date Function
void printDate(struct date now){
    printf("%02d/%02d/%4d \n", now.month, now.day, now.year);
}
// Structure Function to get next day
struct date advanceDay(struct date cal){
    int d = cal.day;
    int m = cal.month;
    int y = cal.year;
    int days;
    struct date row;
    // for number of days in which months
    if ((m==1) || (m==3) || (m==5) || (m==7) || (m==8) || (m==10) || (m==12)) {
        days = 31;
    } else if (m==2) {
        if (y%4==0) {
            days = 29; // leap year calculation
        } else {
            days = 28;
        }
    } else {
        days = 30;
    }
    // increase day by 1 unless we hit the end of the month, then move to first of next month
    if (d < days) {
        d++;
    } else {
        d = 1;
        if (m == 12) {
            m = 1; // move to January from December
            y++; // increment to the next year if going from December to January
        } else {
            m++; // increase month
        }
    }
    row.year = y;
    row.month = m;
    row.day = d;
    return(row);
}
