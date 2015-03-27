/**
Made by Jurica Resetar
jurica_resetar@yahoo.com
**/

#include <stdio.h>
#include <stdlib.h>

int count_ones (int * pointer_to_memory, int size_of_stream_in_bits);

int main(){
    char test1 = 'A';
    char test2 [] ="Hello";
    int test3 []= {0,1,2,3,4};
    printf ("First test: %d\n", count_ones(&test1, 8));
    printf ("Second test: %d\n", count_ones(&test1, 2));
    printf ("Third test: %d\n", count_ones(test2, 15));
    printf ("Fourth test: %d\n", count_ones(test3, 159));
    return 0;
}

int count_ones (int * pointer_to_memory, int size_of_stream_in_bits){

    if (!size_of_stream_in_bits) return 0;

    int i, j;
    int number_of_ones=0;
    int tempData;
    short  rest_of_bits=size_of_stream_in_bits%32;

     for (i=0; i<size_of_stream_in_bits/32; i++){
        tempData= *pointer_to_memory;
        pointer_to_memory++;
        for (j=0; j<32; j++){
            tempData & 1<<j ? number_of_ones++: number_of_ones;
      }
    }

    if (rest_of_bits){
        tempData= *pointer_to_memory;
        for (j=0; j<rest_of_bits; j++){
            tempData & 1<<j ? number_of_ones++: number_of_ones;
      }
    }
    return number_of_ones;
}
