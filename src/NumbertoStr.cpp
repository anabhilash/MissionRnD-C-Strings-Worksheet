/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
void number_to_str(float, char *, int);
int numRev(int);
int convert(char*, int, int);
void number_to_str(float number, char *str, int afterdecimal)
{
	int temp = 0, i = 0;
	temp = numRev((int)number);
	number = number - (int)number;
	if (temp < 0)
	{
		number = -number;
		temp = -temp;
		str[i] = '-';
		i++;
	}
	i = convert(str, i, temp);
	if (number > 0.0)
	{
		str[i] = '.';
		i++;
	}
	while (afterdecimal > 0)
	{
		number = number * 10;
		temp = (int)(number);
		str[i] = '0' + temp;
		number = number - (int)number;
		i++;
		afterdecimal--;
	}
	str[i] = '\0';
}
int numRev(int num)
{
	int temp = 0;
	while (num != 0)
	{
		temp = temp * 10 + (num % 10);
		num /= 10;

	}
	return temp;
}
int convert(char * str, int i, int temp)
{
	while (temp != 0)
	{
		str[i] = '0' + ((temp) % 10);
		temp /= 10;
		i++;
	}
	return i;
}




