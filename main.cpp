#include <stdio.h>
#include <stdlib.h>
//���������� ��������� ���� ��������� �������� /n BAGBAGBAG
#include "sort_functions.h"
int main()
{
    int size_f = 0, size_spec=0; // ������ ����� � ������, ������ ����� � ������ ��� \r
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

    mystr* index = (mystr*)calloc(counting_slashes(mem, size_spec), sizeof(mystr));   //����� ������ ���� ��������


    file_strings(mem, size_spec, index);  //������� ������ � ������ �������� index ��������� �� ������ ������ � ����� ������

    //�������� ������� �������, ����������� index � ����������� ���

    sorting_func(index, counting_slashes(mem, size_spec));
    //printf("%d %d %d", 'a', 'A', 'z');
    return 0;
}
