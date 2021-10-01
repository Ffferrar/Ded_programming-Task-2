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
    FILE *fp = NULL;
    fp = fopen("onegin_test_text.txt", "r");  //��������� ����

    // ToDo: create func  ANDREY_-_DONE
    size_f = file_size(fp);

    char *mem = (char*) calloc (size_f, sizeof (char));    //��� �����, � ������� �������� ����������� ����

        if (!mem)
        {
            printf("calloc memory error");
            return 1; // return ANDREY_-_DONE
        }


    size_spec = fread(mem, sizeof(char), size_f-1, fp);    // ������ ���� � �����, �������� ���������� ��������
    // ToDo: fclose? ANDREY_-_DONE
    fclose(fp);

    mystr* index_straight = (mystr*) calloc (counting_slashes(mem, size_spec), sizeof(*index_straight)); //sizeof *index ANDREY_-_DONE //���� ��� ���������� ������ ����������, ���� ������� ��������� � ������ ������
    mystr* index_back = (mystr*) calloc (counting_slashes(mem, size_spec), sizeof(*index_back)); //������� ��������� ������, ����� ������ ������ ����������
    mystr* index = (mystr*) calloc (counting_slashes(mem, size_spec), sizeof(*index));

    file_strings(mem, size_spec, index_straight);  //������� ������ � ������ �������� index ��������� �� ������ ������ � ����� ������
    file_strings(mem, size_spec, index_back);
    file_strings(mem, size_spec, index);

    int number_slashes = counting_slashes(mem, size_spec);

    // ToDo: front, back, orig in one file ANDREY_-_DONE
    back_sort_machine(index_back, number_slashes);
    sort_machine(index_straight, number_slashes);

    FILE *f = NULL;
    f = fopen("onegin_writing.txt", "w");

    fprintf(f, "STRAIGHT SORTING\n");
    for (int i = 0; i < number_slashes; i++){

            char* spec = index_straight[i].str;

            fwrite(spec, sizeof(char), index_straight[i].length, f); // ToDo: No cycle, use len ANDREY_-_DONE


            fwrite("\n", sizeof(char), 1, f); // ToDo: Why &("")? ANDREY_-_DONE
    }

    fwrite("\n", sizeof(char), 1, f);

    fprintf(f, "BACK SORTING\n");
    for (int i = 0; i < number_slashes; i++){
            char* spec = index_back[i].str;

            fwrite(spec, sizeof(char), index_back[i].length, f); // ToDo: No cycle, use len ANDREY_-_DONE


            fwrite("\n", sizeof(char), 1, f); // ToDo: Why &("")? ANDREY_-_DONE
    }

    fwrite("\n", sizeof(char), 1, f);

    fprintf(f, "NO SORTING\n");
    for (int i = 0; i < number_slashes; i++){
            char* spec = index[i].str;

            fwrite(spec, sizeof(char), index[i].length, f); // ToDo: No cycle, use len ANDREY_-_DONE

            fwrite("\n", sizeof(char), 1, f); // ToDo: Why &("")? ANDREY_-_DONE
    }

    fwrite("\n", sizeof(char), 1, f);
    fclose(f);
    return 0;
}
