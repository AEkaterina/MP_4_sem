#include "Auxil.h"

namespace auxil
{
	void start()						//����� ����������
	{
		srand((unsigned)time(NULL));
	}

	double dget(double rmin, double rmax)			// �������� ��������� ����� double
	{
		return (double)rand() / RAND_MAX * (rmax - rmin) + rmin;
	}

	int iget(int rmin, int rmax)		// �������� ��������� ����� int
	{
		return (int)dget((double)rmin, (double)rmax);
	}
}