
# include <stdio.h>
int main(int argc, char const *argv[])
{
    printf("With arrays\n");
    int array[10];
    
    for(int i = 0; i < 10; i++)
    {
        array[i] = i*2;
    }
    
    for(int i = 9; i >= 0; i--)
    {
        printf("%d\n",array[i]);
    }
    
    printf("Now with pointers\n");

    int* array2 = array;
    for(int i = 9; i >= 0; i--)
    {
        printf("%d\n",*(array + i));
    }

    return 0;
}
