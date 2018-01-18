#include <stdio.h>
#include <ctype.h>

int main () {
  char ch;
  puts("Enter text (Ctrl-D to quit).");
	int wordCount = 0;
	int symSeqCount = 0;
	int foundSym = 0;
	int foundLetter = 0;

  while ( ch = getchar(), ch != EOF ) {	
		if (ch == ' '){
			foundLetter = 0;
			foundSym = 0;
		}
		if ((ch == '_' || isalpha(ch) || isdigit(ch)) && ch != ' '){
			if(foundLetter == 0){
				wordCount++;
			}
			foundLetter = 1;
		}
		else if (ispunct(ch)){ 
			if(foundSym == 0)
				symSeqCount++;
			foundSym = 1;
		}
	}

	printf("Word Count: %d, Symbol Seq Count: %d", wordCount, symSeqCount);
  return 0;
}
