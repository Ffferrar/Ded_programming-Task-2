#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ��������� ������ �� ��������
#include "sort_functions.h"

/**
    @brief Function Otrezok shows belonging to the segment of two symbols
    @param [in] letter symbol
    @param [in] x1 first part of segment
    @param [in] x2 second part of segment

    @return true or false
*/

int otrezok (char letter, int x1, int x2){       //������� �������������� �������
    if ((letter <= x2) && (letter >= x1)){
        return 1;
    }
    else{
        return 0;
    }
}

 /**
    @brief Comparator for straight sorting function
*/

int compare(const void* x1, const void* x2){
    mystr a1 = *(mystr *) (x1);
    mystr a2 = *(mystr *) (x2);

    int length1 = a1.length;
    int length2 = a2.length;
    char *a1_str = a1.str;
    char *a2_str = a2.str;

    int tolower1 = *a1_str;       //������ ���������� ��� ���������� �������� � ������
    int tolower2 = *a2_str;

    for (int i = 0; i < length1; i++){

        if (otrezok(*a1_str, 65, 90)){      //��������� �� ���������
            tolower1 += 32;                  // ToDo: lower, tolower???, DON'T CHANGE ORIGINAL TEXT! ANDREY_-_DONE
        }

        if (otrezok(*a2_str, 65, 90)){
            tolower2 += 32;
        }

        if (otrezok(*a1_str, 91, 96) || otrezok(*a1_str, 33, 64) || otrezok(*a1_str, 123, 126)){                 //��������� �� ����� ����������
            if ( ! otrezok(*a2_str, 91, 96) || otrezok(*a2_str, 33, 64) || otrezok(*a2_str, 123, 126)){  // ToDo: ! ANDREY_-_DONE
                return 1;
            }
            else { continue; }
        }

        else if (otrezok(*a2_str, 91, 96) || otrezok(*a2_str, 33, 64) || otrezok(*a2_str, 123, 126)){            //��������� �� ����� ����������
            if (! otrezok(*a1_str, 91, 96) || otrezok(*a1_str, 33, 64) || otrezok(*a1_str, 123, 126)){
                return 1;
            }
            else { continue; }
        }

        // ToDo: Next code: a1 - a2 ANDREY_-_DONE
        else {return (tolower1 - tolower2);}
    }
}

/**
    @brief Sort_machine calls sorting qsort
*/
void sort_machine(mystr* index, int strings_sum){
        qsort(index, strings_sum, sizeof(mystr), compare);
}
