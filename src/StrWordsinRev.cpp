/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void strRev(char *, int,int);
void str_words_in_rev(char *input, int len)
{
	int i = 0, init = 0, fin = 0;
	if (input != NULL&&len > 0)
	{
		strRev(input, 0, len - 1);

		for (i = 0; input[i] != '\0'; i++)
		{
			while (input[i] == ' '){ i++; }
			init = i;
			if (i != len)
			{
				while (input[i] != ' ' && input[i] != '\0'){ i++; }
				fin = i - 1;
				strRev(input, init, fin);
			}
			i--;
		}

	}
}
void strRev(char * input, int init, int fin)
{
	char temp;
	while (init<fin)
	{
		temp = input[init];
		input[init] = input[fin];
		input[fin] = temp;
		init++;
		fin--;

	}

}
