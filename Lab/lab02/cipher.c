#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char encrypt(char ch, int k);

int main(int argc, char* argv[]){
	int choice, key, len;
	char ch;
	int * key_arr;
	char * str;
	FILE *fin, *fout;

	if (argc != 5){
		printf ("Usage: cipher option key infile, outfile\n");
		printf ("Option 1 for encryption and 2 for decryption");
		exit(1);
	}

	choice = atoi(argv[1]);
	str = argv[2];
	len = strlen(str);

	key_arr	=	(int	*)	malloc (len	*	sizeof(int));
	if(key_arr == NULL)
		printf("Memory not allocated.");

	for(int i = 0; i < len; i++){
		key = toupper(str[i]) - 'A';

		if (choice == 2)
			key = -key;

		key_arr[i] = key;
	}

	fin = fopen(argv[3], "r");
	fout = fopen(argv[4], "w");

	if (fin ==  NULL || fout == NULL) {
		printf("File could not be opened\n");
		exit(1);
	}

	for(int i = 0; fscanf(fin, "%c", &ch) != EOF; i++){
		fprintf(fout, "%c", encrypt(ch, key_arr[i % len]));
	}

	fclose(fin);
	fclose(fout);
	free(key_arr);

	return 0;
}

char encrypt(char ch, int k){
	if ( k < 0 )
		k = k + 26;

	if ( isupper(ch) )
		return (ch - 'A' + k) % 26 + 'A';

	if ( islower(ch) )
		return (ch - 'a' + k) % 26 + 'a';

	return ch;
}
