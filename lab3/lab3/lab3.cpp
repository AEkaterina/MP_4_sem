#include <iostream>
#include <iomanip> 
#include <tchar.h>
#include <stdio.h>
#include "Salesman.h"

#define N 5         //���������� �������

int main()
{
    setlocale(LC_ALL, "rus");
    int n = 2;
    int matrix[N][N] = { //0   1    2    3     4        
                  {  INF,  2*n, 21+n,  INF,   n},    //  0
                  { n,   INF,  15+n,  68-n,  84-n},    //  1
                  { 2+n,  3*n,  INF,  86,   49+n},    //  2 
                  { 17+n,  58-n,  4*n,   INF,   3*n},    //  3
                  { 93-n,  66+n,  52,  13+n,    INF} };   //  4  
    int r[N];                     // ��������� 
    int s = salesman(
        N,          // [in]  ���������� ������� 
        (int*)matrix,          // [in]  ������ [n*n] ���������� 
        r           // [out] ������ [n] ������� 0 x x x x  

    );
    std::cout << std::endl << "-- ������ ������������ -- ";
    std::cout << std::endl << "-- ����������  �������: " << N;
    std::cout << std::endl << "-- ������� ���������� : ";
    for (int i = 0; i < N; i++)
    {
        std::cout << std::endl;
        for (int j = 0; j < N; j++)

            if (matrix[i][j] != INF) std::cout << std::setw(3) << matrix[i][j] << " ";

            else std::cout << std::setw(3) << "INF" << " ";
    }
    std::cout << std::endl << "-- ����������� �������: ";
    for (int i = 0; i < N; i++) std::cout << r[i] << "-->"; std::cout << 0;
    std::cout << std::endl << "-- ����� ��������     : " << s;
    std::cout << std::endl;
    system("pause");
    return 0;
}
