#include <iostream>
#include "Combi6.h"
#include "Knapsack.h"
#include <time.h>
#include <tchar.h>
#include <iomanip> 

#define ITEM_MAX_AMOUNT 20                // ?????????? ????????? (??)
#define KNAP_MAX_WEIGHT 300               // ??????????? ??????? (??)

//(2, 6, 10, 14) ?????????? ? ??????? (?????????? ????????? 12 ? 20 ??.); 

int main() {
    setlocale(LC_ALL, "rus");
    int v[] = { 25, 56, 67, 40, 20, 27, 37, 33, 33, 44, 53, 12,
               60, 75, 12, 55, 54, 42, 43, 14 },
        c[] = { 15, 26, 27, 43, 16, 26, 42, 22, 34, 12, 33, 30,
               12, 45, 60, 41, 33, 11, 14, 12 };
    short m[ITEM_MAX_AMOUNT];
    int maxcc = 0;
    clock_t t1, t2;
    std::cout << "\t?????? ? ???????\n     (???????????? ???????)\n";
    std::cout << std::setfill('-') << std::setw(40) << "\n";
    std::cout << "??????????? ???????: " << KNAP_MAX_WEIGHT << std::endl;
    std::cout << std::setfill('-') << std::setw(40) << "\n";
    std::cout << std::setfill(' ') << std::setw(15) << std::right << "??????????";
    std::cout << " | ";
    std::cout << std::setfill(' ') << std::setw(20) << std::left << "?????????????????";
    std::cout << std::endl << std::setfill(' ') << std::setw(15) << std::right << "?????????";
    std::cout << " | ";
    std::cout << std::setfill(' ') << std::setw(20) << std::left << "??????????";
    std::cout << std::setfill('-') << std::setw(40) << "\n";
    for (int i = 12; i <= ITEM_MAX_AMOUNT; i++)
    {
        t1 = clock();
        maxcc = knapsack_s(KNAP_MAX_WEIGHT, i, v, c, m);
        t2 = clock();
        std::cout << std::endl << std::setfill(' ') << std::setw(15) << std::right << i;
        std::cout << " | ";
        std::cout << std::setfill(' ') << std::setw(20) << std::left << t2 - t1;
    }
    std::cout << std::endl << std::endl;
    system("pause");
}