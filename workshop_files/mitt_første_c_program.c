#include <stdlib.h>
#include <stdio.h>
#include "mitt_første_c_program.h"

int sum(int a, int b){
        return a+b;
}

int main(){
    printf("Hello, wordl!\n");

    int integer = 10;
    float someFloat = 10.5;
    double biggerFloat = 10.4;

    char letter = 'A';

    int letterValue = (int)letter;

    char myString[MaxWordLength] = "Hello, world!";

    Letter *name = "John"; 

    int* pointer = &integer;

    int* numbers = malloc(3); // [1,2,3,4...'\0'
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;


    printf("Integer: %d, pointer: %p\n", integer, (void*)pointer);

    printf("Character: %c, Pointer: %p\n", name[0], (void *)name);

    for (int i = 0; i < 5; i++)
    {
        printf("%c\n", name[i]);
    }
    

    while (*numbers != '\0'){   
        printf("%d\n", *numbers);
        numbers++;
    }
    
    int result = sum(1,2);

    printf("%d\n", result);
    printf("Size of a char: %d\n", sizeof(char));

    printf("Size of a int: %d\n", sizeof(int));

    printf("%s\n", name);
    free(numbers);
    return 0;
}