#include "Auxil.h"

namespace auxil
{
	void start()						//старт генератора
	{
		srand((unsigned)time(NULL));
	}

	double dget(double rmin, double rmax)			// получить случайное число double
	{
		return (double)rand() / RAND_MAX * (rmax - rmin) + rmin;
	}

	int iget(int rmin, int rmax)		// получить случайное число int
	{
		return (int)dget((double)rmin, (double)rmax);
	}
}