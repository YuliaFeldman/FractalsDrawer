#include "Fractal.h"
#include <cmath>
#include <iostream>

/**
 * Helper function
 * @param x position in row
 * @param y position in column
 * @return true if '#' should be placed in this position
 */
bool SierpinskiCarpet::_helperFunc(long x, long y)
{
	while(x != 0 && y != 0)
	{
		if(x % 3 == 1 && y % 3 == 1)
		{
			return false;
		}
		x /= 3;
		y /= 3;
	}
	return true;
}

/**
 * Draws Sierpinski Carpet fractal
 */
void SierpinskiCarpet::draw()
{
	long i, j, p = (long)pow(3, _dim);

	for(i = 0; i < p; i++)
	{
		for(j = 0; j < p; j++)
		{
			if(SierpinskiCarpet::_helperFunc(i, j))
			{
				std::cout << "#";
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}

//_________________________________________________________________________________________

/**
 * Draws Sierpinski Sieve fractal
 */
void SierpinskiSieve::draw()
{
	long p = (long)pow(2, _dim);
	for(long y = 0; y < p; y++)
	{
		for(int x = 0; x < p; x++)
		{
			if((x & y) != 0)
			{
				std::cout << " ";
			}
			else
			{
				std::cout << "#";
			}
		}
		std::cout << std::endl;
	}

}

//_______________________________________________________________________________________

/**
 * Draws Cantor Dust fractal
 */
void CantorDust::draw()
{
	long p = (long)(pow(3, _dim));

	for(int i = 0; i < p; i++)
	{
		for(int j = 0; j < p; j++)
		{
			CantorDust::_helperFunc(i, j);
		}
		std::cout << std::endl;
	}
}

/**
 * Helper function
 * @param x position in row
 * @param y position in column
 */
void CantorDust::_helperFunc(long x, long y)
{
	if (x % 3 == 1 || y % 3 == 1)
	{
		std::cout << ' ';
		return;
	}

	else if (x == 0  && y == 0)
	{
		std::cout << '#';
		return;
	}
	CantorDust::_helperFunc(x / 3, y / 3);
}