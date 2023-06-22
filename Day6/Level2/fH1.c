/*
L2-Day6
1.Write a c program to sort the above "data.csv" based on the "Temperature" field in descending order

a. Use only file handling concepts

b. Use array of structures and file handling
*/

/*Source Code:*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

struct WeatherData {
    char date[20];
    char time[10];
    float temperature;
};

int compareTemperature(const void* a, const void* b) {
    const struct WeatherData* dataA = (const struct WeatherData*)a;
    const struct WeatherData* dataB = (const struct WeatherData*)b;
    
    if (dataA->temperature < dataB->temperature)
        return 1;
    else if (dataA->temperature > dataB->temperature)
        return -1;
    else
        return 0;
}

int main() {
    FILE* file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }
    
    struct WeatherData weatherData[100];
    char line[MAX_LINE_LENGTH];
    int count = 0;
    
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        char* token = strtok(line, ",");
        
        strcpy(weatherData[count].date, token);
        token = strtok(NULL, ",");
        
        strcpy(weatherData[count].time, token);
        token = strtok(NULL, ",");
        
        weatherData[count].temperature = atof(token);
        
        count++;
    }
    

    fclose(file);
    
    qsort(weatherData, count, sizeof(struct WeatherData), compareTemperature);
    
    file = fopen("sorted_data.csv", "w");
    if (file == NULL) {
        printf("Failed to create the sorted_data.csv file.\n");
        return 1;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%s,%.2f\n", weatherData[i].date, weatherData[i].time, weatherData[i].temperature);
    }
    
    fclose(file);
    
    printf("Sorting completed. The sorted data has been written to sorted_data.csv.\n");
    
    return 0;
}
/*
Output for this code:
Failed to open the file.
*/
