/*
L1-Day6
3. Data Viewer:
Write an application to view the log stored in data.csv
Example, say you have the following data in data.csv

------------------------------------

EntryNo,sensorNo,Temperature,Humidity,Light,

1,S1,36.5,100,50,10:30:50
2,S3,30,100,50,10:30:55
3,S2,-6.6,100,10,10:31:00
------------------------------------

a. Write a function to extract each line in the .csv file and store it in an array of structures. 

b. Also implement functions to display the contents of the array of structures.
*/

/*Source Code:*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY 100
#define MAX_LINE_LENGTHMEASURE 100

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[10];
} LogEntry;

LogEntry logEntries[MAX_ENTRY];
int numEntries = 0;

void extractData(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char line[MAX_LINE_LENGTHMEASURE];
    while (fgets(line, sizeof(line), file)) {
        char* token;
        token = strtok(line, ",");
        
        logEntries[numEntries].entryNo = atoi(token);
        token = strtok(NULL, ",");
        strcpy(logEntries[numEntries].sensorNo, token);
        token = strtok(NULL, ",");
        logEntries[numEntries].temperature = atof(token);
        token = strtok(NULL, ",");
        logEntries[numEntries].humidity = atoi(token);
        token = strtok(NULL, ",");
        logEntries[numEntries].light = atoi(token);
        token = strtok(NULL, ",");
        strcpy(logEntries[numEntries].timestamp, token);
        
        numEntries++;
    }

    fclose(file);
}

void displayData() {
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTimestamp\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%d\t%s\t%.2f\t\t%d\t\t%d\t%s\n", logEntries[i].entryNo, logEntries[i].sensorNo,
               logEntries[i].temperature, logEntries[i].humidity, logEntries[i].light, logEntries[i].timestamp);
    }
}

int main() {
    extractData("data.csv");
    displayData();
    
    return 0;
}

/*Output for this code:
Failed to open the file.
EntryNo SensorNo        Temperature     Humidity        Light   Timestamp
*/