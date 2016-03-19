/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stdlib.h>
#include<stdio.h>
struct transaction
{
	int amount;
	char date[11];
	char description[20];
};
int toNum(char a[], int i, int j)
{
	int c, sign, offset, n;
	n = 0;
	for (c = i; c <= j; c++)
	{
		n = n * 10 + a[c] - '0';
	}
	return n;
}
int strcmpfromitoj(char *str1, char *str2, int i, int j)
{

	int n1, n2;
	n1 = toNum(str1, i, j);
	n2 = toNum(str2, i, j);
	//printf("%d %d\n",n1,n2);
	if (n2>n1)
		return 1;
	else
		return 0;
}

int countGreaterNumbers(struct transaction *Arr, int len, char *date)
{

	if (len < 0 || date == '\0' || date == NULL)
		return -1;
	int count = 0, flag = 0;

	for (int i = 0; i < len; i++)
	{

		if (strcmpfromitoj(date, Arr[i].date, 6, 9))
		{
			count++; flag = 1;
		}
		else continue;
		if (strcmpfromitoj(date, Arr[i].date, 3, 4) && flag != 1)
		{

			count++;
			flag = 1;
		}
		if (strcmpfromitoj(date, Arr[i].date, 0, 1) && flag != 1)
		{
			count++;
			flag = 1;
		}
		flag = 0;

	}
	return count;
}