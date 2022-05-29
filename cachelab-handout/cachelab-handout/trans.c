/* 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
void transpose_32(int M, int N, int A[N][M], int B[M][N]){
     int i,j;
     int r1,r2,r3,r4,r5,r6,r7,r8;
     for(i=0 ; i<M ; i++){
         for(j=0 ; j<N ; j+=8){

             r1 = A[j][i];
             r2 = A[j+1][i];
             r3 = A[j+2][i];
             r4 = A[j+3][i];
             r5 = A[j+4][i];
             r6 = A[j+5][i];
             r7 = A[j+6][i];
             r8 = A[j+7][i];

             B[i][j] = r1;
             B[i][j+1] = r2;
             B[i][j+2] = r3;
             B[i][j+3] = r4;
             B[i][j+4] = r5;
             B[i][j+5] = r6;
             B[i][j+6] = r7;
             B[i][j+7] = r8;
         }
     }
 }




char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
    int i,j;
    int r1,r2,r3,r4,r5,r6,r7,r8;

    if( M == 32){
        transpose_32(M, N, A, B);
    }
    else if( M == 64){
        transpose_32(M, N, A, B);
    }
    else{

    }
}

/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 


/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc); 

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc); 

}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

