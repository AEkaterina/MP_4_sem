#include <iostream>
#include <iomanip> 
#include <tchar.h>
#include <stdio.h>
#include "Salesman.h"

#define N 5         //количество городов

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
    int r[N];                     // результат 
    int s = salesman(
        N,          // [in]  количество городов 
        (int*)matrix,          // [in]  массив [n*n] расстояний 
        r           // [out] массив [n] маршрут 0 x x x x  

    );
    std::cout << std::endl << "-- Задача коммивояжера -- ";
    std::cout << std::endl << "-- количество  городов: " << N;
    std::cout << std::endl << "-- матрица расстояний : ";
    for (int i = 0; i < N; i++)
    {
        std::cout << std::endl;
        for (int j = 0; j < N; j++)

            if (matrix[i][j] != INF) std::cout << std::setw(3) << matrix[i][j] << " ";

            else std::cout << std::setw(3) << "INF" << " ";
    }
    std::cout << std::endl << "-- оптимальный маршрут: ";
    for (int i = 0; i < N; i++) std::cout << r[i] << "-->"; std::cout << 0;
    std::cout << std::endl << "-- длина маршрута     : " << s;
    std::cout << std::endl;
    system("pause");
    return 0;
}
