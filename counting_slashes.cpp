#include <stdio.h>

int counting_slashes(char* data, int data_size){
    int x = 0;
    int spec_counter = 0;   //������� ����� �����
    while (x<data_size){
        if (data[x]=='\n'){
            spec_counter++;
        }
        x++;
    }
    return (spec_counter+1);
}
