#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// сортируем строки по алфавиту в обратном порядке
#include "sort_functions.h"
/**
    @brief Comparator for back sorting function
*/
int back_compare(const void* x1, const void* x2){
    mystr a1 = *(mystr *) (x1);
    mystr a2 = *(mystr *) (x2);

    int length1 = a1.length;
    int length2 = a2.length;
    char *a1_str = a1.str + length1;
    char *a2_str = a2.str + length2;
    for (int i = 0; i < length1; i++){

        if (otrezok(*a1_str, 65, 90)){      //проверяем на заглавные
            *a1_str += 32;
        }

        if (otrezok(*a2_str, 65, 90)){
            *a2_str += 32;
        }

        if (otrezok(*a1_str, 91, 96) || otrezok(*a1_str, 33, 64) || otrezok(*a1_str, 123, 126)){                 //проверяем на знаки пунктуации
            if ( not otrezok(*a2_str, 91, 96) || otrezok(*a2_str, 33, 64) || otrezok(*a2_str, 123, 126)){
                return 1;
            }
            else { continue; }
        }

        else if (otrezok(*a2_str, 91, 96) || otrezok(*a2_str, 33, 64) || otrezok(*a2_str, 123, 126)){                 //проверяем на знаки пунктуации
            if (not otrezok(*a1_str, 91, 96) || otrezok(*a1_str, 33, 64) || otrezok(*a1_str, 123, 126)){
                return 1;
            }
            else { continue; }
        }

        else if (*a1_str < *a2_str){
            return -1;
        }

        else if (*a1_str > *a2_str){
            return 1;
        }

        else if (*a1_str == *a2_str){
            a1_str--;
            a2_str--;
            if ((i == (length1 - 1)) && ( (length1 - 1) == (length2 - 1) )){
                return 0;
            }
            if (i == (length1 - 1)){
                return -1;
            }

            if (i == (length2 - 1)){
                return 1;
            }

            continue;
        }
    }
}


void back_sort_machine (mystr* index, int strings_sum){
        qsort(index, strings_sum, sizeof(mystr), back_compare);
}
