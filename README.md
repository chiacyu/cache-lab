## [Cache Lab Implementation and Blocking](http://www.cs.cmu.edu/afs/cs/academic/class/15213-f14/www/recitations/rec7.pdf)
This project is a assignment from [Computer Systems：A Programmer's Perspective](http://csapp.cs.cmu.edu/3e/home.html).
In this project we would stimulate the behavior of cache in modern computers.



- Before running the autograders, compile your code:
    linux> make

- Check the correctness of your simulator:
    linux> ./test-csim

- Check the correctness and performance of your transpose functions:

    linux> ./test-trans -M 32 -N 32\
    linux> ./test-trans -M 64 -N 64\
    linux> ./test-trans -M 61 -N 67

- Check everything at once (this is the program that your instructor runs):
    linux> ./driver.py    

******
Files:
******


You will modifying and handing in these two files
- csim.c       Your cache simulator
- trans.c      Your transpose function

Tools for evaluating your simulator and transpose function
- Makefile     Builds the simulator and tools
- README       This file
- driver.py*   The driver program, runs test-csim and test-trans
- cachelab.c   Required helper functions
- cachelab.h   Required header file
- csim-ref*    The executable reference cache simulator
- test-csim*   Tests your cache simulator
- test-trans.c Tests your transpose function
- tracegen.c   Helper program used by test-trans
- traces/      Trace files used by test-csim.c
