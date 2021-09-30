#include <stdio.h>
#include <stdlib.h>
#include "sort_functions.h"

/** Strings' sorting program
    @version Vers 2.0
    @date 27.09.2021
    @brief Solving task #2 for the course "Professional Programming"
    @brief Realized straight and back sorting functions of txt files
*/

int main()
{
    int size_f = 0, size_spec = 0; // ������ ����� � ������, ������ ����� � ������ ��� \r
    printf("\tKozhanov Gleb, B05-120\nThe sorter of txt files\n\n");
    printf("Please, put your data by the path\n\n <C:\\Users\\Trying Python\\Desktop\\Ded Proffesional programming\\Onegin_task\\onegin_test_text.txt>\n\nResult you can see in the same folder, file <onegin_writing.txt>");
    FILE *fp;
    fp=fopen("onegin_test_text.txt", "r");  //��������� ����

    fseek(fp, 0 , SEEK_END);                //���������� ��������� � ������ �����
    size_f = ftell(fp);                 //���������� ������� ftell ����� ������ ������ �����, ������� ����� � fread
    fseek(fp, 0 , SEEK_SET);                // ���������� ��������� �������

    char *mem= (char*)calloc(size_f, sizeof(char));    //��� �����, � ������� �������� ����������� ����

        if(!mem)
        {
            printf ("calloc memory error");
            exit (1);
        }



    size_spec = fread(mem, sizeof(char), size_f-1, fp);    // ������ ���� � �����, �������� ���������� ��������

    mystr* index = (mystr*)calloc(counting_slashes(mem, size_spec), sizeof(mystr));   //���� ��� ���������� ������ ����������, ���� ������� ��������� � ������ ������

    file_strings(mem, size_spec, index);  //������� ������ � ������ �������� index ��������� �� ������ ������ � ����� ������
    int number_slashes = counting_slashes(mem, size_spec);

    back_sort_machine(index, number_slashes);
    fclose(fp);

    FILE *f;
    f=fopen("onegin_writing.txt", "w");
    for (int i=0;i<number_slashes;i++){
                    char* spec = index[i].str;
                    for (int j=0;j<index[i].length;j++){
                        fwrite(spec, sizeof(char), 1, f);
                        spec++;
                    }
                    fwrite(&("\n"), sizeof(char), 1, f);
    }
    fclose(f);
    return 0;
}
