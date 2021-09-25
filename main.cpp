#include <stdio.h>
#include <stdlib.h>

#include "sort_functions.h"
int main()
{
    int size_f = 0, size_spec = 0; // размер файла в байтах, размер файла в байтах без \r
    FILE *fp;
    fp=fopen("onegin_test_text.txt", "r");  //открываем файл

    fseek(fp, 0 , SEEK_END);                //перемещаем указатель в начало файла
    size_f = ftell(fp);                 //используем функцию ftell чтобы узнать размер файла, который кинем в fread
    fseek(fp, 0 , SEEK_SET);                // возвращаем указатель вначало

    char *mem= (char*)calloc(size_f, sizeof(char));    //это буфер, в котором хранится прочитанный файл

        if(!mem)
        {
            printf ("calloc memory error");
            exit (1);
        }



    size_spec = fread(mem, sizeof(char), size_f-1, fp);    // кидает файл в буфер, получает количество символов

    mystr* index = (mystr*)calloc(counting_slashes(mem, size_spec), sizeof(mystr));   //пока что одномерный массив указателей, надо сделать двумерным с длиной строки

    file_strings(mem, size_spec, index);  //функция кладет в массив структур index указатель на начало строки и длину строки
    int number_slashes = counting_slashes(mem, size_spec);
    sort_machine(index, number_slashes);
    fclose(fp);

    FILE *f;
    f=fopen("onegin_writing.txt", "w");
    for (int i=0;i<number_slashes;i++){
                    char* spec = index[i].str;
                    for (int j=0;j<index[i].length;j++){
                        fwrite(spec, sizeof(char), 1, f);
                        //printf("%c", *spec);
                        spec++;
                    }
                    fwrite(&("\n"), sizeof(char), 1, f);
    }
    fclose(f);
    return 0;
}
