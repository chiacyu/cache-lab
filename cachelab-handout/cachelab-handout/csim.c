#include "cachelab.h"
#include<stdio.h>
#include<iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct{
    int valid_bit;
    int tag;
    int lru_counter;
}cache_line;

int h,v,s,E,b,t,S;
int hit_count;
int miss_count;
int eviction_count;
char *file_name;
cache_line ** Cache;

void cache_init(int S, int E, cache_line **cache){
    cache = (cache_line **)malloc(S * sizeof(cache_line *));
    for(int i=0 ; i<S ; i++){
        cache[i] = (cache_line *)malloc(E * sizeof(cache_line));
        for(int j=0 ; j<E ; j++){
            cache[i][j].lru_counter = 0;
            cache[i][j].tag = 0;
            cache[i][j].valid_bit = 0;
        }
    }
}

void memory_acess(unsigned int address){

    int cache_set_index = (address >> b) & (-1u >> (64 - s));
    int cache_tag_index = (address >> (b + s));

    for(int i=0 ; i<E ; i++){

        if( Cache[cache_set_index][i].tag == cache_tag_index ){
            
            hit_count+=1;
            Cache[cache_set_index][i].lru_counter += 1;
            return ;
        } 
    }

    for(int i=0 ; i<E ; i++){

        if(Cache[cache_set_index][i].valid_bit == 0){
            Cache[cache_set_index][i].tag = cache_tag_index;
            Cache[cache_set_index][i].valid_bit = 1;
            Cache[cache_set_index][i].lru_counter += 1;
            miss_count+=1;
            return;
        }
    }
    miss_count+=1;
    eviction_count+=1;

    int min_time_stamp = Cache[cache_set_index][0].lru_counter;
    int eviction_index;

    for (int i=0 ; i<E ; i++) {
        if (Cache[cache_set_index][i].lru_counter < min_time_stamp) {
            min_time_stamp = Cache[cache_set_index][i].lru_counter;
            eviction_index = i;
        }
    }

    Cache[cache_set_index][eviction_index].tag = cache_tag_index;
    Cache[cache_set_index][eviction_index].lru_counter+=1;
    return;
}

void command_parser(char *filename){

    FILE * pfile;
    pfile = fopen(filename,"r");
    
    char identifier;
    unsigned address;
    int size;

    while(fscanf(pfile," %c %x, %d",&identifier, &address, &size)>0)
    {
        switch (identifier) {
            
            case 'L':
                memory_acess(address);
                break;
            
            case 'M':
                memory_acess(address);

            case 'S':
                memory_acess(address);
                break;

            default:
                break;
        }

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



int main(int argc, char *argv[])
{
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
    cache_init(S, E, Cache);
    command_parser(file_name);


    printSummary(hit_count, miss_count, eviction_count);
    return 0;
}
