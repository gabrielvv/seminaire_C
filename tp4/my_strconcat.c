#include <stdio.h>
#include <stdlib.h>


 /*
 ** s1 : the string to copy
 ** return the new String copy.
 */
 char* my_strconcat(const char* v1, const char* v2)
 {
	int j = 0,k = 0;
	int sizev1 = length(v1);
	int sizev2 = length(v2);
	int size = 0;


	if (v1[0] == '"')
		j++;
	else if (v1[sizev1] == '"')
		sizev1--;
	else if(v2[sizev2] == '"')
		sizev2--;
	else if (v2[2] == '"')
		k++;


	size = sizev1 + sizev2;


	char * tab;
	tab = calloc (size,sizeof(char));



	for(j; sizev1 >= j; j++)
	{
		tab[j] = v1[j];
	}


	for(k; sizev2 >= k; k++)
	{
		tab[sizev1+k] = v2[k];
	}


	return tab;
 }



 int main(int argc, char** argv)
{
	if (3 > argc)
	{
		printf("Nombre de parametres insuffisants\n");
		return 1;
	}

	const char *value = argv[1];
	const char *value_2 = argv[2];

	printf("%s ",my_strconcat(value, value_2));
}


int length(char *t)
{
    int taille = 0;
    do
    {
        taille ++;
    }
    while(t[taille] != '\0');
    return taille+1;
}
