
#include <stdio.h>
#include <stdlib.h>
#include "str_replace.h"
int length(const char *);


int length(const char * s) {
  int i;
  i=0;
  while(s[i]!='\0')
    ++i;
  return i;
}


char* replace(const char *input, char *pattern, char*replacement){


	int sizepat = length(pattern);
	int size = length(input);
	int sizerep = length(replacement);
	int ecart = sizepat - sizerep;
	char * tab = (char*)malloc((size)*sizeof(char));


	int i=0;
	int j;
	int k;
	int l;
	int cas = 0;
	int res =0;


	int mot = 1;


	for(i =0; input[i+cas]!='\0';i++){
		res = 0;


		if(i > 0 && (input[i] != ' ' &&
					 input[i] != '.' &&
					 input[i] != '?' &&
					 input[i] != ',' &&
					 input[i] != '-' &&
					 input[i] != '!' ) && (
					 input[i-1] == ' ' ||
					 input[i-1] == '.' ||
					 input[i-1] == '?' ||
					 input[i-1] == ',' ||
					 input[i-1] == '-' ||
					 input[i-1] == '!' )) mot++;

		for(j=0; j < sizepat; j++){
      //si res = taille pattern on actionne le remplacement
			if(pattern[j]==input[i+j+cas])res++;
			if(res == sizepat) {

				for(k = 0 ; k < sizerep ; k ++){
					tab[i++]=replacement[k];
				}
				cas += ecart;
			}
		}
		tab[i] = input[i+cas];
	}
	tab[i+1] = '\0';

	for(i=0; tab[i+((sizerep > sizepat)?0:1)] != '\0' ; i++){
		printf("%c",tab[i] );


	}
	printf("\n");


	return tab;
}
