#include <stdio.h>
#include <stdlib.h>


int* array_remove(const int* arr1, unsigned int index, unsigned int* length)
{
    int i;
    int *result=(int*)malloc((*length)*sizeof(int));

    for (i=0;i<*length;i++){
        if(i==index)
        {
            result[i]=arr1[i+1];
            for(i=(index+1);i<*length;i++)
            {
                result[i]=arr1[i+1];
            }
            *length=*length-1;
            return result;
        }
        else
        {
            result[i]=arr1[i];
        }
    }

    return result;
}

 int main(int argc, char** argv)
{
	if (2 > argc)
	{
		printf("Nombre de parametres insuffisants\n");
		return 1;
	}
	int i,test=0;

	for(i=1;i<argc;i++)
    {
        if(*argv[i]=='-')
            test=1;
    }
    if (test==0)
    {
        printf("Nombre de parametres insuffisants\n");
		return 1;
    }

	int *arr1 =(int*)malloc((argc-3)*sizeof(int));

    int index=atoi(argv[argc-1]);

	unsigned int length=(argc-3);

    for(i=0;i<length;i++)
    {
        arr1[i]=atoi(argv[i+1]);
    }

int* result = array_remove(arr1,index,&length);

	for(i=0;i<(length);i++)
        printf("%d ", *(result+i));
    free(result);
    return 1;

}
