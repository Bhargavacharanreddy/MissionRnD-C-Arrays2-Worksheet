/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

#include<stdlib.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
struct transaction common[10];
int toNumber(char a[], int i, int j)/*to convert a string specified by the postions i to j to numbers*/
{
	int c, n;
	n = 0;
	for (c = i; c <= j; c++)
	{
		n = n * 10 + a[c] - '0';
	}
	return n;
}
int stringcmp(char *str1, char *str2, int i, int j)/*comparing the dates of both transactions*/
{

	int n1, n2;
	n1 = toNumber(str1, i, j);
	n2 = toNumber(str2, i, j);
	if (n2 == n1)
		return 1;
	else
		return 0;
}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	int count = 0, x = 0;
	if (ALen < 0 || BLen < 0 || A == NULL || B == NULL)/* for invalid inputs*/
		return NULL;

	for (int i = 0; i < ALen; i++)
	{

		for (int j = 0; j < BLen; j++)
		{
			count = 0;
			if (stringcmp(A[i].date, B[j].date, 6, 9))
				count++;
			if (stringcmp(A[i].date, B[j].date, 3, 4))
				count++;
			if (stringcmp(A[i].date, B[j].date, 0, 1))
				count++;
			if (count == 3)
			{

				common[x++] = A[i];/*intializing the transaction into the array of structure common*/
			}


		}
	}
	if (x == 0)
		return NULL;
	return common;/*returnig the result*/

}