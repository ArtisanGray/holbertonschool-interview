#include "palindrome.h"

/**
 * is_palindrome - checks whether integer is a palindrome
 * @n: number passed as parameter
 * Return: 1 if it is, 0 otherwise
*/
int is_palindrome(unsigned long n)
{
	unsigned long flip = 0, m = n;

	while (mid != 0)
	{
		flip = (flip * 10) + (mid % 10);
		mid = mid / 10;
	}
	if (flip == n)
		return (1);
	return (0);
}
