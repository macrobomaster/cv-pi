#include <stdio.h>
#include "videoutil.hpp"
#include "serialsend.hpp"
#include <time.h>
#include <unistd.h>
int main(int argc, char** argv )
{

    //serialsend ts;
    //while(1){
    videoutil vu;
    //sleep(0.2);
    //ts.testsend();
    //}
    vu.videocap();
    return  0;
}






