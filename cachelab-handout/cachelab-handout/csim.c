#include "cachelab.h"
#include<stdio.h>
#include<iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int h,v,s,E,b,t,S;
char *file_name;

typedef struct{
    int valid_bit;
    int tag;
    int lru_counter;
}cache_line;

void cache_init(int S, int E, int b){

}



void command_parser(char *filename){

    FILE * pfile;
    pfile = fopen(filename,"r");
    
    char identifier;
    unsigned address;
    int size;

    while(fscanf(pfile," %c %x, %d",&identifier, &address, &size)>0)
    {

    }

}

void print_usage(){
    printf("Usage: ./csim-ref [-hv] -s <s> -E <E> -b <b> -t <tracefile>\n"
           "• -h: Optional help flag that prints usage info\n"
           "• -v: Optional verbose flag that displays trace info\n"
           "• -s <s>: Number of set index bits (S = 2s is the number of sets)\n"
           "• -E <E>: Associativity (number of lines per set)\n"
           "• -b <b>: Number of block bits (B = 2bis the block size)\n"
           "• -t <tracefile>: Name of the valgrind trace to replay\n"  
    );
}


void memory_acess(unsigned long address){

}




int main(int argc, char *argv[])
{
    int hit_count;
    int miss_count;
    int eviction_count;
    int opt;

    while( (opt = getopt(argc, argv, "hv:s:E:b:t:")) != -1){
        switch (opt) {
            case 'h':
                h = 1;
                print_usage();
                break;

            case 'v':
                v = 1;
                break;

            case 's':
                s = atoi(optarg);
                break;

            case 'E':
                E = atoi(optarg);
                break;

            case 'b':
                b = atoi(optarg);
                break;

            case 't':
                strcpy(file_name, optarg);
                break;

            default:
                print_usage();
                break;
        }   
    }
    if( s<0 || E<0 || b<0 || file_name==NULL){
        return -1;
        printf("The argument must greater than 0");
    }

    S = 1 << s;
    

    printSummary(hit_count, 0, 0);
    return 0;
}
