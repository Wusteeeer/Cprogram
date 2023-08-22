#include <stdio.h>
#include <stdlib.h>


int* reverse(int arr[], int size){

    int iter = 0;

    int temp[size];

    //Adds the last element of arr to the first element of temp
    for (int i = size - 1; i >= 0; i--)
    {

        temp[iter] = arr[i];

        iter++;
    }
    
    //Assigns all values of temp to arr
    for (int i = 0; i < size; i++)
    {
        arr[i] = temp[i];
    }
    
    return arr;

}

int main(){

    int* ptr;

    ptr = (int*)calloc(3, sizeof(int));

    ptr[0] = 1;
    ptr[1] = 2;
    ptr[2] = 3;


    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", ptr[i]);
    }

    ptr = (int*)realloc(ptr, 1);

    ptr[3] = 19;
    for (int i = 0; i < 4; i++)
    {
        printf("%d\n", ptr[i]);
    }


    

    return 0;
}