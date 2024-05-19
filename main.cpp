#include "mbed.h"
#include <cstdio>

InterruptIn buttn(PC_13);// this is the input pc13 the blue button

volatile int myflag = 0; // Here I had to add the volatile function in front of the int as i was having a build error
//I Created an integer variable and called it my flag
void buttn_fall(){
    myflag = 1;
}

// main() runs in its own thread in the OS
int main()
{
    printf("This is mbed os v%d \r\n", MBED_VERSION);// Here i had to print the statement 
    buttn.fall(&buttn_fall);
    while (true) {
        if(myflag == 1){
            printf("button pressed!!\r\n");// Here i had to print the statement 
            myflag = 0;// Had to reset my flag
        }
    } // After many build errors and commits I got the build to Succeeded
}// I Improved the code performed a commit and published the code