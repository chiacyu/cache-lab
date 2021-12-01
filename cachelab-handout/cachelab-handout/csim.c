#include "cachelab.h"
#include<stdio.h>
#include<iostream>



typedef struct{
    int valid_bit;
    bool tag;
    int lru_counter;
}cache_line;


cache_line ** cache = malloc


int main()
{
    int hit_count;
    int miss_count;
    int eviction_count;
    
    FILE * pfile;
    pfile = fopen("tracefile.txt","r");
    
    char identifier;
    unsigned address;
    int size;

    while(fscanf(pfile," %c %x, %d",&identifier, &address, &size)>0)
    {

    }
    printSummary(hit_count, 0, 0);
    return 0;
}
