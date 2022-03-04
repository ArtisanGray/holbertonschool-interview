#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * menger - draws a menger sponge
 * @level: parameter passed as level^ of sponge
 */
void menger(int level)
{
	int depth, i, j, k, ti, tj;

	depth = (int)pow(3, level);
	for (j = 0; j < depth; j++)
	{
		for (i = 0; i < depth; i++)
		{
			ti = i;
			tj = j;
			k = 0;
			while (ti && tj)
			{
				if (ti % 3 == 1 && tj % 3 == 1)
				{
					printf(" ");
					k = 1;
					break;
				}
				ti /= 3;
				tj /= 3;
			}
			if (!k)
				printf("#");
		}
		printf("\n");
	}
}
