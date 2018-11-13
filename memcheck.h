/* 
 * Name: Jeongyeon Park
 * E-mail: jeongyeo@uoguelph.ca
 * Program name: memcheck.h
 * ID: 1006554
 * Created on February 19, 2018
 */

#ifndef MEMCHECK_H
#define MEMCHECK_H

#include <stdlib.h>

#define malloc(size)            memcheck_malloc(size, __FILE__, __LINE__)
#define calloc(nitems, size)    memcheck_calloc(nitems, size, __FILE__, __LINE__)
#define realloc(ptr, newsize)   memcheck_realloc(ptr, newsize, __FILE__, __LINE__)
#define free(ptr)               memcheck_free(ptr, __FILE__, __LINE__)
#define main()                  memcheck_main()

void *memcheck_malloc(size_t size, char *file, int line);
void *memcheck_calloc(size_t nitems, size_t size, char *file, int line);
void *memcheck_realloc(void *ptr, size_t newsize, char *file, int line);
void memcheck_free(void *ptr, char *file, int line);
int memcheck_main();

#endif /* MEMCHECK_H */

