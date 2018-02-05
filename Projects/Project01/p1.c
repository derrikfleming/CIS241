#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "functions.h"


int main(int argc, char * argv[]){
  int MAXNUM = 26;
  char * encrypt, * decrypt, * key;
  char choice;
	FILE * fin, * fout;

  //check argument count
  if (argc != 5)
    errorHandler(0);

  choice = toupper(*argv[1]);
  key = removeDuplicates(argv[2]);

  fin = fopen(argv[3], "r");
  fout = fopen(argv[4],"w");
  encrypt = (char	*)	malloc (MAXNUM * sizeof(char));
  //allocation check
  if (encrypt == NULL)
    errorHandler(2);

  //encrypt option
  if (choice == 'E'){
    encryptKeyMaker(key, encrypt);
    processFile(encrypt, fin, fout);
  }
  //decrypt option
  else if (choice == 'D'){
    decrypt = (char	*)	malloc (MAXNUM * sizeof(char));
    if(decrypt == NULL)
      errorHandler(2);
    encryptKeyMaker(key, encrypt);
    decryptKeyMaker(encrypt, decrypt);
    processFile(decrypt, fin, fout);
    free(decrypt);
  }
  //invalid choice
  else
    errorHandler(1);

  free(encrypt);
  fclose(fin);
	fclose(fout);
}
