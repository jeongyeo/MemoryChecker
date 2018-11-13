/* 
 * Name: Jeongyeon Park
 * E-mail: jeongyeo@uoguelph.ca
 * Program name: main.c
 * ID: 1006554
 * Created on February 19, 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include "memcheck.h"

int main(){
    char *ptr1, *ptr2, *ptr3;
    ptr1= malloc( 27 );
    ptr2 = malloc( 31 );
    ptr3 = malloc( 37 );
    free( NULL );
    free( ptr1 );
    free( ptr3 );
    return 0;
}

