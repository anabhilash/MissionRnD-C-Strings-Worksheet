/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31
int  giveword(char *, int i, int *, int *);
int find(char *, int, int, char *);
int compare(char *, int, int, int, int, char *);
char *array[SIZE];
char ** commonWords(char *str1, char *str2)
{
	int i, init = 0, fin = 0, error = 0, found = 0,j=0,k=0;
	
	for (i = 0; i<SIZE; i++)
	{
		array[i] = (char *)malloc(SIZE + 1);
	}
	if (str1 != NULL&&str2 != NULL)
	{
		for (i = 0; str1[i] != '\0'; i++)
		{
			error = giveword(str1, i, &init, &fin);
			i = fin;
			if (!error)
			{
				found = find(str1, init, fin, str2);
				if (found == 1)
				{
					j = 0;
					while (init <= fin)
					{
						array[k][j] = str1[init];
						init++;
						j++;
					}
					array[k][j] = '\0';

					k++;
				}

			}
			else
			{
				break;
			}
		}
		if (k != 0)
			return array;
		else
			return NULL;

	}
	else
		return NULL;
}
int find(char *str1, int init1, int fin1, char * str2)
{
	int init2, fin2, i = 0, error = 0, found = 0;
	for (i = 0; str2[i] != '\0'; i++)
	{
		error = giveword(str2, i, &init2, &fin2);
		i = fin2;
		if (!error)
		{
			if ((fin1 - init1) == (fin2 - init2))
			{
				found = compare(str1, init1, fin1, init2, fin2, str2);
				if (found)
					break;
			}
		}
		else
		{
			break;
		}
	}
	return found;
}

int compare(char *str1, int init1, int fin1, int init2, int fin2, char *str2)
{
	int found = 1;
	while (init1 <= fin1)
	{
		if (str1[init1] != str2[init2])
		{
			found = 0;
			break;
		}
		init1++;
		init2++;
	}
	return found;
}

int  giveword(char *str1, int i, int *init, int *fin)
{
	while (str1[i] == ' '){ i++; }
	if (str1[i] == '\0')
	{
		return 1;
	}
	*init = i;
	while (str1[i] != ' ' && str1[i] != '\0'){ i++; }
	*fin = i - 1;
	return 0;

}