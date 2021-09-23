#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// сортируем строки по алфавиту
#include "sort_functions.h"



int compare(const void* x1,const void* x2){
    mystr a1 = *(mystr *) (x1);
    mystr a2 = *(mystr *) (x2);

    int length1 = a1.length;
    int length2 = a2.length;
    char *a1_str = a1.str;
    char *a2_str = a2.str;

    if (length1 < length2){
        for (int i=0;i<length1;i++){
            if (*a1_str < *a2_str){
                return 1;
                break;
            }

            if (*a1_str > *a2_str){
                return -1;
                break;
            }

            if (*a1_str == *a2_str){
                a1_str++;
                a2_str++;
                if (i == (length1 -1)){
                    return 1;
                    break;
                }
                continue;
            }
        }

    }
    else{
        for (int i=0;i<length2;i++){
            if (*a1_str > *a2_str){
                return 1;
                break;
            }

            if (*a1_str < *a2_str){
                return -1;
                break;
            }

            if (*a1_str == *a2_str){
                a1_str++;
                a2_str++;
                if (i == (length2 -1)){
                    return 1;
                    break;
                }
                continue;
            }
        }
    }

}

void sort_machine(mystr* index, int strings_sum){
        qsort(&index, strings_sum, sizeof(mystr), compare);

        for (int i=0;i<strings_sum;i++){
                char* spec = index[i].str;
                for (int j=0;j<index[i].length;j++){
                    printf("%c", *spec);
                    spec++;
                }
                printf("\n");
        }
}

/*void sorting_func (mystr* index, int strings_sum){
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
 */
