#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//removed to set LEN via command line args for testing via make
//#define LEN 4

char* strnsub (char *p, int n);

int main(int argc, char * argv[]){
    int LEN;
    char line[] = "His textbook was bought from that bookstore";
    int lineLen = strlen(line);
    char *p1, *p2;

    if(argc == 2)
      LEN = atoi(argv[1]);
    else{
      printf("Incorrect argument passed. Default value (LEN = 4) used.");
      LEN = 4;
    }

    //set p1 to the beginning of string line;
    int i = 0;
    int j = 1;
    p1 = strnsub(&line[i],LEN);

    while (i < lineLen){
      p2 = strnsub(&line[j],LEN);

      while (j < lineLen){
        // use strncmp() to compare
        if (strncmp(p1,p2,LEN) == 0) {
            printf("The original string is:\n%s\n", line);
            printf("The first substring: %s\n", strnsub(p1, LEN));
            printf("The second substring: %s\n", strnsub(p2, LEN));
            return 0;
        }
        j++;
        if (j < lineLen)
          p2 = strnsub(&line[j],LEN);
      }
      i++;
      j = i + 1;
      if(i < lineLen)
        p1 = strnsub(&line[i],LEN);
    }
    printf("No repeated patterns of length %d in the following string:\n%s\n",
            LEN, line);
    return 0;
}


// returns a string with the first n characters of string p

char* strnsub (char *p, int n){
    char * str = malloc(sizeof(char) * n);

    strncpy(str, p, n);

    return str;
}
