#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *find_space(char *pszChar,char *sep){

	int i = 1;
	int n = 0;

	int *ptr = malloc( sizeof(int) );

	while (*pszChar){

		if ( *pszChar == *sep ){

			ptr[i] = n;
			i++;
		}
		
		pszChar++;
		n++;
	}

	if( i != 1 ){

		ptr[0] = i-1; // nombre d'espace trouvé
		return ptr;
	}
	else{

		ptr[0] = -1;
		return ptr;
	}
}

char *range(char *pszChar, int start,int end){

	int i = 0;
	int n = 0;

	int size = strlen(pszChar);

	char *new_char = malloc( sizeof(char) );

	while (i<size){

		if ( i >= start && i <= end ){

			new_char[n] = pszChar[i];

			i++;
			n++;
		
		}else{

			i++;
		}

	}

	new_char[n] = '\0';

	return new_char;
}

int main (int argc,char **argv){

	char *str = "ABCD EFG HIJ A BC";

	int *ptr = find_space(str," ");

	int n = ptr[0]; // nombre d'espace trouvé ou (-1) si rien trouvé

	printf("%s\n",str);

	if( n != -1 ){

		printf("sperator found: %d\n",n);

		int first_range = 0;

		for(int i=1;i<=n+1;i++){

			if( i < (n+1) ){

				printf("%s\n", range( str, first_range, ptr[i]-1) );
				first_range = ptr[i]+1;

			}else{

				printf("%s\n", range( str, first_range, strlen(str)-1 ) );
			}

		}

	}else{

		printf("no sperator found\n");
	}

	return 0;
}
