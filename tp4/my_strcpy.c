#include <stdio.h>
#include <stdlib.h>

 /*
 ** s1 : the string to copy
 ** return the new String copy.
 */
 char* my_strcpy(const char* s1)
 {
	int j;	int size = length(s1);

	char * tab;
	tab = calloc (size,sizeof(char));

	for(j=0; size >= j; j++)
	{
		tab[j] = s1[j];
	}


	return tab;
 }

 int main(int argc, char** argv)
{
	if (2 > argc)
	{
		printf("Nombre de parametres insuffisants\n");
		return 1;
	}

	char *value = argv[1];
	printf("%s ",my_strcpy(value));
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
