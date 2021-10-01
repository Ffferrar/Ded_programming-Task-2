#include <stdio.h>
// запихиваем буфер в массив указателей на строки
#include "sort_functions.h"

/** @brief Function creates an array of structures
    @brief Structure mystr has two types: char* and int

    @param [in] mem buffer with file's content
    @param [in] size_ number of characters in the file
    @param [out] index array of structures
*/
void file_strings(char* mem, int size_, mystr* index){
    int cow = 0;
    int cursor = 0;
    int spec_counter = 0; //счётчик для массива указателей index
                                                        //printf("%d - size_\n", size_);
    while (cow<size_){
        if (cow == (size_ - 1)){
            index[spec_counter].str = mem + cursor; // ANDREY_-_DONE ToDo: &mem[cursor] = &*(mem + cursor) = mem + cursor
            index[spec_counter].length = cow - cursor;
        }
                                                       //printf("%c - mem[cow]\n", mem[cow]);
        if (mem[cow] == '\n'){
            index[spec_counter].str = mem + cursor;     // заносим в index адрес. желательно сохранять и длину строки -> нужна структура
            index[spec_counter].length = cow - cursor;
                                                        //printf("%d\n", spec_counter);
                                                        //printf("%d \n",index[spec_counter].str);
            spec_counter++;
            cursor = cow+1;
        }
        cow++;
    }
}
