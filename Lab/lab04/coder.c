#include <ctype.h>
#include <stdio.h>

void encode(FILE *, FILE *);
void decode(FILE *, FILE *);

int main(int argc, char* argv[])
{
	char choice;
	FILE *fin, *fout;

	/* check on the user input */
	if (argc != 4)
	{
		printf ("Usage: coder option (e|d) infile, outfile\n");
		return 1;
	}

	choice = argv[1][0];

	/* open the files */
  fin = fopen(argv[2], "r");
	fout = fopen(argv[3], "w");

    	if (fin ==  NULL || fout == NULL)
	{
		printf("File could not be opened\n");
		return 1;
	}

	/* do the encode or decode */
	if (choice == 'e')
		encode(fin, fout);
	else if (choice == 'd')
		decode(fin, fout);
	else
	{
		printf("InEncode: Wrong option (must be e or d) from input!\n");
		return 1;
	}

	return 0;
}

/* encode contents of fin into short ints and save results in file fout */
void encode(FILE * fin, FILE * fout)
{
	char c0,c1,c2,c3;
	unsigned int num;

	while ( fscanf(fin, "%c%c%c%c", &c0, &c1, &c2, &c3) == 4 )
	{
		num = 0;
		num |= c0;
 		num = num << 8;
		num |= c1;
		num = num << 8;
		num |= c2;
		num = num << 8;
		num |= c3;
		fprintf(fout, "%d ", num);
	}

	fclose(fin);
	fclose(fout);
}

/* decode contents of fin (integers) into original form */
void decode(FILE * fin, FILE * fout)
{
	char c0, c1, c2, c3;
	unsigned int num;

	while ( fscanf(fin, "%u ", &num) != EOF)
	{
		c3 = (char) num;
		num = num >> 8;
		c2 = (char) num;
		num = num >> 8;
		c1 = (char) num;
		num = num >> 8;
		c0 = (char) num;

		fprintf(fout, "%c%c%c%c", c0, c1, c2, c3);
	}
	fprintf(fout, "\n");
	fclose(fin);
	fclose(fout);
}
