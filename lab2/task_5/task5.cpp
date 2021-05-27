#include <iostream>
#include "Combi5.h"
#include "knapsack.h"
#include "Auxil.h"

#define ITEM_MAX 18
#define KNAP_MAX_WEIGHT 300

/*(¬ариант 2, 6, 10, 14) упрощенную о рюкзаке (веса предметов и их стоимость сгенерировать случайным образом:
вместимость рюкзака 300 кг, веса предметов 10 Ц 300 кг, стоимость предметов 5 Ц 55 у.е.; количество предметов Ц 18 шт.);*/

int main()
{
    setlocale(LC_ALL, "rus");
    int item_weight[ITEM_MAX],         // вес предмета каждого типа
        item_price[ITEM_MAX];           // стоимость предмета каждого типа  
    short item_instance[ITEM_MAX];      // количество предметов каждого типа  {0,1}   

    auxil::start();
    for (int i = 0; i < ITEM_MAX; i++) {
        item_weight[i] = (double)auxil::iget(10, 300);
        item_price[i] = (double)auxil::iget(5, 55);
    }

    int optimal_weight = knapsack_s(KNAP_MAX_WEIGHT, ITEM_MAX, item_weight, item_price, item_instance);


    std::cout << std::endl << "-------- «адача о рюкзаке --------- ";
    std::cout << std::endl << "- количество предметов(шт) : " << ITEM_MAX;
    std::cout << std::endl << "- вместимость рюкзака(кг)  : " << KNAP_MAX_WEIGHT;

    std::cout << std::endl << "- размеры предметов(кг)    : ";
    for (int i = 0; i < ITEM_MAX; i++) std::cout << item_weight[i] << " ";
    std::cout << std::endl << "- стоимости предметов(y.e.)  : ";
    for (int i = 0; i < ITEM_MAX; i++) std::cout << item_price[i] << " ";
    std::cout << std::endl << "- оптимальна€ стоимость рюкзака(y.e.) : " << optimal_weight;
    std::cout << std::endl << "- вес рюкзака(кг): ";
    int s = 0; for (int i = 0; i < ITEM_MAX; i++) s += item_instance[i] * item_weight[i];
    std::cout << s;
    std::cout << std::endl << "- выбраны предметы: ";
    for (int i = 0; i < ITEM_MAX; i++) std::cout << " " << item_instance[i];
    std::cout << std::endl << std::endl;

    system("pause");
    return 0;
}
