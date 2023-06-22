/*
Day-4 L1 Activity
3. Write a C program using structures to calculate the difference between two time periods using a user-defined function.
*/
/*Source code:*/
#include <stdio.h>

struct TimeValue {
    int hours;
    int minutes;
    int seconds;
};

struct TimeValue timeDifferenceAnalyse(struct TimeValue t1, struct TimeValue t2) {
    struct TimeValue diff;

    if (t2.seconds > t1.seconds) {
        --t1.minutes;
        t1.seconds += 60;
    }

    diff.seconds = t1.seconds - t2.seconds;

    if (t2.minutes > t1.minutes) {
        --t1.hours;
        t1.minutes += 60;
    }

    diff.minutes = t1.minutes - t2.minutes;
    diff.hours = t1.hours - t2.hours;

    return diff;
}

int main() {
    struct TimeValue strt, end, difference;

    printf("Enter the start time (hh:mm:ss): ");
    scanf("%d:%d:%d", &strt.hours, &strt.minutes, &strt.seconds);

    printf("Enter the end time (hh:mm:ss): ");
    scanf("%d:%d:%d", &end.hours, &end.minutes, &end.seconds);

    difference = timeDifferenceAnalyse(end, strt);

    printf("Time difference: %d hours, %d minutes, %d seconds\n", difference.hours, difference.minutes, difference.seconds);

    return 0;
}

/*
Output for this code:
Enter the strt time (hh:mm:ss): 10:10:10
Enter the end time (hh:mm:ss): 11:11:11
Time difference: 1 hours, 1 minutes, 1 seconds
*/
