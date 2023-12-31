#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


void printArr(int arr[], int size);
void initAges(int arr[], int size);
void userInput(int *size);
void sortArray(int arr[], int size);

void mode(int ages[], int size);

float median(int ages[], int size);

float mean(int ages[], int size);

int main(){

    srand(time(NULL));
    int size = 10;

    userInput(&size);


    int ages[size];

    initAges(ages, size);

    if(size < 31){

        printArr(ages, size);

    }

    sortArray(ages, size);


    printf("Medelvardet: %.1f ar\n", mean(ages, size));
    printf("Median: %.1f ar\n", median(ages, size)); 
    mode(ages, size);


    return 0;
}

void userInput(int *size){
    

    while(1){

        printf("Hur manga personer vill du gora statistik for? ");
        scanf("%d", size);

        if(*size < 1000 && *size > 0)
        {

            break;

        }else{

            printf("Valj ett nummer mellan 1 och 999\n");

        }

    }


}

void initAges(int ages[], int size){

    for (int i = 0; i < size; i++)
    {
        ages[i] = rand() % 21 + 20;
    }

}

void sortArray(int arr[], int size){
    
    int temp = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            
            if(arr[j] < arr[j + 1]){
                
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

            }

        }
        
    }
    

}


void printArr(int arr[], int size){

    for (int i = 0; i < size; i++)
    {
        if(i == size - 1){

            printf("%d", arr[i]);
            break;

        }
        printf("%d, ", arr[i]);
    }
    
    printf("\n");

}


void mode(int ages[], int size){
    

    printf("Typvardet: ");
    int mode[size], occurences[size], largestOccurance = 0;
    
    for (int i = 0; i < size; i++)
    {

        occurences[i] = 0;
        mode[i] = 0;

        for (int j = i + 1; j < size; j++)
        {  

            if(ages[i] == ages[j]){
                occurences[i]++;
            }

        }

        if(occurences[i] > largestOccurance)
        {
            largestOccurance = occurences[i];
        }

    
    }


    int modeIter = 0;
    for (int i = 0; i < size; i++)
    {  

        if(occurences[i] >= largestOccurance){
            mode[modeIter] = ages[i];
            modeIter++;
        }

    }

    printArr(mode, modeIter);
    
    
    
    
    
    
}


float median(int ages[], int size){

    if(size % 2 == 0){

        float left = ages[(size / 2) - 1], right = ages[(size / 2)];
        return (left + right) / 2;

    }else{

        return ages[(int)(size / 2)];

    }

}

float mean(int ages[], int size){

    float allAges = 0;

    for (int i = 0; i < size; i++)
    {
        allAges += ages[i];
    }
    

    return allAges / size;


}