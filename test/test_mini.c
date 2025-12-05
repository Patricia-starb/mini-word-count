#include "wc.h"
#include <stdio.h>

int main(int argc, char* argn[]){
    if(argc > 1){
        const char* filename = argn[1];
        printf("%s:\n", filename);
        mini_wc(filename);
    }else {
        printf("Argument too little.\n");
    }
    return 0;
}