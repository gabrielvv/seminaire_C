

#include <stdio.h>
#include <stdlib.h>
void quickSort(char *arr, int si, int ei);


short is_anagram(char *s1, char *s2)
{
    int n1 = length(s1);
    int n2 = length(s2);

    if (n1 != n2)
        return 0;

    quickSort (s1, 0, n1 - 1);
    quickSort (s2, 0, n2 - 1);

    int i;
    for(i = 0; i < n1;  i++)
        if (s1[i] != s2[i])
            return 0;

    return 1;
}


void exchange(char *a, char *b)
{
    char temp;
    temp = *a;
    *a   = *b;
    *b   = temp;
}


int partition(char A[], int si, int ei)
{
    char x = A[ei];
    int i = (si - 1);
    int j;

    for (j = si; j <= ei - 1; j++)
    {
        if(A[j] <= x)
        {
            i++;
            exchange(&A[i], &A[j]);
        }
    }
    exchange (&A[i + 1], &A[ei]);
    return (i + 1);
}


void quickSort(char A[], int si, int ei)
{
    int pi;    /* Partitioning index */
    if(si < ei)
    {
        pi = partition(A, si, ei);
        quickSort(A, si, pi - 1);
        quickSort(A, pi + 1, ei);
    }
}


void faire_combi(char * str, char * tmp, int len, int ind)
{
    int i;
    if (ind >= len)
        printf("%s\n", tmp);
        return;

    for (i = 0; i < len; i++)
    {
        if (str[i] == -1)
            continue;
        tmp[ind] = str[i];
        str[i] = -1;
        faire_combi(str, tmp, len, ind+1);
        str[i] = tmp[ind];
    }
}


void display_anagrams(char* s1)
{
    int len = length(s1);
    char * tmp = calloc(len + 1, sizeof(char));
    char * util = calloc(len + 1, sizeof(char));
    int i;
    for(i=0; i<len; i++)
        util[i]=s1[i];
    faire_combi(util, tmp, len, 0);


    free(tmp);
    free(util);
}


int main(int argc, char** argv)
{
    if (2 > argc)
    {
        printf("Nombre de parametres insuffisants\n");
        return 1;
    }

    char *value = argv[1];

    if(argc==2)
        display_anagrams(value);
    int i;
    if(argc )
        if(argc>2)
        {
            for(i=2; i<argc; i++)
            {
                char *value2 = argv[i];
                printf("%d",is_anagram(value,value2));
            }
        }
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
