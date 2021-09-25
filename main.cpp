#include <stdio.h>
#include <stdlib.h>

#include "sort_functions.h"
int main()
{
    int size_f = 0, size_spec = 0; // ������ ����� � ������, ������ ����� � ������ ��� \r
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
