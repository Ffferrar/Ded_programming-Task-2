int counting_slashes(char* data, int data_size);


struct mystr
{
    char* str;
    int length;
};
void file_strings(char* mem, int size_, mystr* index);
int compare(const void* x1,const void* x2);
void sort_machine(mystr* index, int strings_sum);
void sorting_func (mystr* index, int strings_sum);
