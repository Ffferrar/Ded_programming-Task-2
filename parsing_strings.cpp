#include <stdio.h>
// запихиваем буфер в массив указателей на строки
#include "sort_functions.h"
void file_strings(char* mem, int size_, mystr* index){
    int cow=0;
    int cursor=0;
    int spec_counter=0; //счётчик для массива указателей index
                                                        //printf("%d - size_\n", size_);
    while (cow<size_){
        if (cow == (size_ -1)){
            index[spec_counter].str = &mem[cursor];
            index[spec_counter].length = cow - cursor;
        }                                                //printf("%c - mem[cow]\n", mem[cow]);
        if (mem[cow] == '\n'){
            index[spec_counter].str = &mem[cursor];     // заносим в index адрес. желательно сохранять и длину строки -> нужна структура
            index[spec_counter].length = cow - cursor;
                                                        //printf("%d\n", spec_counter);
                                                        //printf("%d \n",index[spec_counter].str);
            spec_counter++;
            cursor=cow+1;
        }
        cow++;
    }
}
