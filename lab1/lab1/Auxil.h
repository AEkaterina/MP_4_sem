#pragma once
#include <cstdlib>
#include <ctime>

namespace auxil
{
	void start();							// старт  генератора случайных чисел
	double dget(double rmin, double rmax);	// случайное число double
	int iget(int rmin, int rmax);			// случайное число int
}