#include <stdio.h>
#include "wc.h"

void calculate(char __char__, int* __line, int* __word, int* __char_count, int* in_word){
    switch(__char__){
        case '\0':
            if(*in_word)
                (*__word)++;
            break;
        case '\n':
            *__line += 1;
            if(*in_word){
                (*__word)++;
                *in_word = 0;
            }           
            break;
        case ' ':
        case '\t':
            (*__char_count)++;
            if(*in_word){
                (*__word)++;
                *in_word = 0;
            }
            break;
        default:
            (*__char_count) += 1;
            (*in_word) = 1;
            break;
    }
    return;
}

void mini_wc(const char* filename){
    FILE* fp = fopen(filename, "r");
    if(!fp){
        perror("Open failure");
        return;
    }
    char buffer[MAX_BLOCK];
    int lines, words, chars, in_word;
    lines = words = chars = in_word = 0;
    while(1){
        size_t frdr = fread(buffer, sizeof(char), (MAX_BLOCK - 1), fp);
        printf("%lu\n", frdr);
        if(!frdr){
            if(!fp){
                perror("fread failure");
                fclose(fp);
                return;
            }
            break;
        }
        buffer[frdr] = '\0';
        for(size_t index = 0; index <= frdr; index++){
            calculate(buffer[index], &lines, &words, &chars, &in_word);
        }
        lines++;               
    }
    printf("Lines:%d\nwords:%d\nchar:%d\n", lines, words, chars);
    fclose(fp);
}