/**
Made by Jurica Resetar
jurica_resetar@yahoo.com
**/

#include <stdio.h>
#include <stdlib.h>

int count_ones (char * pointer_to_memory, int size_of_stream_in_bits);

int main(){
    char test1 = 'A';
    char test2 [] ="Hello";
    printf ("First test: %d\n", count_ones(&test1, 8));
    printf ("Second test: %d\n", count_ones(&test1, 2));
    printf ("Third test: %d\n", count_ones(test2, 15));
    return 0;
}

int count_ones (char * pointer_to_memory, int size_of_stream_in_bits){

    if (!size_of_stream_in_bits) return 0;

    int i, j;
    int number_of_ones=0;
    char tempData;
    short  rest_of_bits=size_of_stream_in_bits%8;

     for (i=0; i<size_of_stream_in_bits/8; i++){
        tempData= *pointer_to_memory;
        pointer_to_memory++;
        for (j=0; j<8; j++){
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
