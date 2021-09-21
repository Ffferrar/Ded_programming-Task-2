#include <stdio.h>
#include <stdlib.h>
//Ќ≈ќЅ’ќƒ»ћќ ƒќѕќЋЌя“№ ‘ј…Ћ ѕќ—Ћ≈ƒЌ»ћ —»ћ¬ќЋќћ /n BAGBAGBAG
#include "sort_functions.h"
int main()
{
    int size_f = 0, size_spec=0; // размер файла в байтах, размер файла в байтах без \r
    FILE *fp;
    fp=fopen("onegin_test_text.txt", "r");  //открываем файл

    fseek(fp, 0 , SEEK_END);                //перемещаем указатель в начало файла
    size_f = ftell(fp);                 //используем функцию ftell чтобы узнать размер файла, который кинем в fread
    fseek(fp, 0 , SEEK_SET);                // возвращаем указатель вначало

    char *mem= (char*)calloc(size_f, sizeof(char));    //это буфер, в котором хранитс€ прочитанный файл

        if(!mem)
        {
            printf ("calloc memory error");
            exit (1);
        }



    size_spec = fread(mem, sizeof(char), size_f-1, fp);    // кидает файл в буфер, получает количество символов

    mystr* index = (mystr*)calloc(counting_slashes(mem, size_spec), sizeof(mystr));   //динам массив двух структур


    file_strings(mem, size_spec, index);  //функци€ кладет в массив структур index указатель на начало строки и длину строки

    //осталось сделать функцию, принимающую index и сортирующую его

    sorting_func(index, counting_slashes(mem, size_spec));
    //printf("%d %d %d", 'a', 'A', 'z');
    return 0;
}
