/*
L2 Activity-Day 4
1. Data Parser:
   A data logger transmits the data in ascii format as shown below
   "S1-T:36.5-H:100-L:50"
   Write a function to populate all the data in an array of structure. The output should be like
   Sensor Info:
   ---------------------
   Sensor ID: S1
   Temperature: 36.5 C
   Humidity: 100
   Light Intensity: 50%
   ---------------------
*/
/*Source code:*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENSOR_INFO 100

typedef struct {
    char sensorID[3];
    float temperature;
    int humidity;
    int lightIntensity;
} SensorInfo;

void parseData(const char* data, SensorInfo* sensorInfo) {
    char buffer[100];
    strcpy(buffer, data);
    
    
    char* token = strtok(buffer, "-: ");
    
    
    while (token != NULL) {
        if (strcmp(token, "S") == 0) {
            
            token = strtok(NULL, "-: ");
            strncpy(sensorInfo->sensorID, token, 2);
            sensorInfo->sensorID[2] = '\0';  
        } else if (strcmp(token, "T") == 0) {
          
            token = strtok(NULL, "-: ");
            sensorInfo->temperature = atof(token);
        } else if (strcmp(token, "H") == 0) {
            
            token = strtok(NULL, "-: ");
            sensorInfo->humidity = atoi(token);
        } else if (strcmp(token, "L") == 0) {
           
            token = strtok(NULL, "-: ");
            sensorInfo->lightIntensity = atoi(token);
        }
        
        token = strtok(NULL, "-: ");
    }
}

int main() {
    const char* data = "S1-T:36.5-H:100-L:50";
    SensorInfo sensorInfo;
    
    parseData(data, &sensorInfo);
    
    printf("Sensor Info:\n");
    printf("---------------------\n");
    printf("Sensor ID: %s\n", sensorInfo.sensorID);
    printf("Temperature: %.1f C\n", sensorInfo.temperature);
    printf("Humidity: %d\n", sensorInfo.humidity);
    printf("Light Intensity: %d%%\n", sensorInfo.lightIntensity);
    printf("---------------------\n");
    
    return 0;
}
