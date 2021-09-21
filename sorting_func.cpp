#include <stdio.h>
// сортируем строки по алфавиту
#include "sort_functions.h"

void sorting_func (mystr* index, int strings_sum){
    int cow=1;

    while (cow<(strings_sum-1)){
        if (*index[cow-1].str >= *index[cow].str){
            char* midnight = index[cow-1].str;
            int midnight_len = index[cow-1].length;

            index[cow-1].str = index[cow].str;
            index[cow].str = midnight;

            index[cow-1].length = index[cow].length;
            index[cow].length = midnight_len;
        }

        cow++;
    }


    for (int i=0;i<strings_sum;i++){
        char* spec = index[i].str;
        for (int j=0;j<index[i].length;j++){
            printf("%c", *spec);
            spec++;
        }
        printf("\n");
    }

}
