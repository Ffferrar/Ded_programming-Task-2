#include <stdio.h>
// ���������� ����� � ������ ���������� �� ������
#include "sort_functions.h"

void file_strings(char* mem, int size_, mystr* index){
    int cow=0;
    int cursor=0;
    int spec_counter=0; //������� ��� ������� ���������� index
                                                        //printf("%d - size_\n", size_);
    while (cow<size_){
                                                        //printf("%c - mem[cow]\n", mem[cow]);
        if (mem[cow] == '\n'){
            index[spec_counter].str = &mem[cursor];     // ������� � index �����. ���������� ��������� � ����� ������ -> ����� ���������
            index[spec_counter].length = cow - cursor;
                                                        //printf("%d\n", spec_counter);
                                                        //printf("%d \n",index[spec_counter].length);
            spec_counter++;
            cursor=cow+1;
        }
        cow++;
    }
}
