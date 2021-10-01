int counting_slashes(char* data, int data_size);

struct mystr
{
    char* str;
    int length; // ToDo: size_t
};
int file_size(FILE *fp);

void file_strings(char* mem, int size_, mystr* index);
int compare(const void* x1,const void* x2);

void sort_machine(mystr* index, int strings_sum);
void back_sort_machine (mystr* index, int strings_sum);

void sorting_func (mystr* index, int strings_sum);
int otrezok (char letter, int x1, int x2);
