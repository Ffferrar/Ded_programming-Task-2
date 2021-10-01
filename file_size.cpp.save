#include <stdio.h>
#include <stdlib.h>
#include "sort_functions.h"

int file_size(FILE *fp)
{
    int size_f = 0;
    fseek(fp, 0 , SEEK_END);                //перемещаем указатель вконец файла
    size_f = ftell(fp);                 //используем функцию ftell чтобы узнать размер файла, который кинем в fread
    fseek(fp, 0 , SEEK_SET);                // возвращаем указатель вначало
    return size_f;
}
