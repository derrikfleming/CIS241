#include "functions.h"

// remove duplicate characters in array word and return the resulting string
char * removeDuplicates(char * word){
  char * result;
  int len = strlen(word);
  result = (char	*)	malloc (len * sizeof(char));
  if (result == NULL){
    errorHandler(2);
  }
  char ch;
  for(int i = 0, j = 0; i < len; i++){
    ch = word[i];
    if(!targetFound(result, i, ch)){
      result[j] = ch;
      j++;
    }
  }

  return result;
}

// search the first num characters in array charArray for character target
// return a non-zero integer if found, otherwise, return 0
int targetFound(char * charArray, int num, char target){
  int found = 0;

  if(strchr(charArray,target))
    found = 1;

  return found;
}

// initialize the encrypt array with appropriate cipher letters according to the given key
void initializeEncryptArray(char * key, char * encrypt){
  char ch;
  for (int i = 0, j = 0, flag = 0; j < 26;){
    ch = key[i];
    if (ch == '\0' || flag == 1){
      if(flag == 0){
        flag = 1;
      }
      ch = 'Z' - j;
      j++;
    }
    if (strchr(encrypt,ch) == NULL){
      encrypt[i] = toupper(ch);
      i++;
    }
  }
}

void initializeDecryptArray(char * encrypt, char * decrypt){
  for (int i = 0; i < 26; i++){
    decrypt[encrypt[i] - 'A'] = i + 65;
  }
}

void processInput(char * substitute, FILE * fin, FILE * fout){
  char ch;
  while ( fscanf(fin, "%c", &ch) != EOF ){
    if(isupper(ch)){
      fprintf(fout, "%c", substitute[ch - 'A']);
    }
    else if(islower(ch)){
      fprintf(fout, "%c", tolower(substitute[ch - 'a']));
    }
    else
      fprintf(fout, "%c", ch);
	}
}

void errorHandler(int argIndex){
  switch(argIndex){
    case 0:
      printf("Error: Incorrect number of arguments received.\n\tPlease try again using the correct number of args.\n");
    case 1:
      printf("Error: Invalid program option.\n\tPlease try again using either 'd'/'D' or 'e'/'E'.\n");
    case 2:
      printf("Error: Memory could not be allocated.\n");
    case 3:
      printf("Error: Invalid input filename given for input.\n\tPlease use a valid filename for input.\n");
  }
  exit(1);
}
