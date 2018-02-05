#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

// remove duplicate characters in array word and return the resulting string
char * removeDuplicates(char * word);

// search the first num characters in array charArray for character target
// return a non-zero integer if found, otherwise, return 0
int targetFound(char * charArray, int num, char target);

// initialize the encrypt array with appropriate cipher letters according to the given key
void encryptKeyMaker(char * key, char * encrypt);

// initialize decrypt array with appropriate substitute letters based on the encrypt array
void decryptKeyMaker(char * encrypt, char * decrypt);

// initialize decrypt array with appropriate substitute letters based on the encrypt array
void processFile(char * substitute, FILE * inf, FILE * outf);

// process data from the input file and write the result to the output file
// pass the encrypt array to parameter substitute if encryption is intended
// pass the decrypt array to parameter substitute if decryption is intended
void decryptFile(char * substitute, FILE * inf, FILE * outf);

//prints out user-friendly error message
void errorHandler(int errIndex);

#endif //FUNCTIONS_H
