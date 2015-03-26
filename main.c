/**
This function was made by Jurica Resetar
Purpose: task for student internship at ARM
**/
#include <stdio.h>
#include <stdlib.h>
int count_ones (char * pointer_to_memory, int size_of_stream_in_bits);

int main()
{
    char * start;
    char test [2]= "AI";
    printf ("%d\n", count_ones(test, 11));
}

int count_ones (char * pointer_to_memory, int size_of_stream_in_bits){
    /**
    *Idea: see how many bytes you have to read
    *Make one loop and within read byte per byte
    *In last byte you have to be careful- do not
    *read to many bits
    *Count ones with mask (0x01) and in every loop pass
    *shift it for 1 in left
    **/
    int i, j;
    int number_of_ones=0;
    int number_of_bytes=size_of_stream_in_bits/8;   //Rest of bits (if numberOfBytsNot n*8)
    char tempData= *pointer_to_memory;
    int  rest_of_bits=size_of_stream_in_bits%8;

    for (i=0; i<number_of_bytes; i++){
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
