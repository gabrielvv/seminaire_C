#include <stdio.h>

short is_palindrome(char* input)
{


    int z;
    int y=0;
    int size = length(input);
    char input2[size];
    for(z=0; z<size; z++)
    {
        if(input[z] != ' ')
        {
            if(input[z]>='A' && input[z]<='Z')
            {
                input2[y]=input[z]+32;
                y++;
            }
            else
            {
                input2[y]=input[z];
                y++;
            }
        }
    }
    input2[y] = '\0';
    for (z=0, y=length(input2)-1; z < length(input2)/2; ++z, --y)
    {
        if (input2[z] != input2[y])
        {
            return 0;
        }
    }
    return 1;
}


int main(int argc, char** argv)
{
    if (2 > argc)
    {
        printf("Nombre de parametres insuffisants\n");
        return 1;
    }


    char *value = argv[1];


    printf("%d", is_palindrome(value));
    return 0;
}


int length(char *t)
{
    int taille = 0;
    do
    {
        taille ++;
    }
    while(t[taille] != '\0');
    return taille;
}
