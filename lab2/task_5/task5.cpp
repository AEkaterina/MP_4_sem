#include <iostream>
#include "Combi5.h"
#include "knapsack.h"
#include "Auxil.h"

#define ITEM_MAX 18
#define KNAP_MAX_WEIGHT 300

/*(������� 2, 6, 10, 14) ���������� � ������� (���� ��������� � �� ��������� ������������� ��������� �������:
����������� ������� 300 ��, ���� ��������� 10 � 300 ��, ��������� ��������� 5 � 55 �.�.; ���������� ��������� � 18 ��.);*/

int main()
{
    setlocale(LC_ALL, "rus");
    int item_weight[ITEM_MAX],         // ��� �������� ������� ����
        item_price[ITEM_MAX];           // ��������� �������� ������� ����  
    short item_instance[ITEM_MAX];      // ���������� ��������� ������� ����  {0,1}   

    auxil::start();
    for (int i = 0; i < ITEM_MAX; i++) {
        item_weight[i] = (double)auxil::iget(10, 300);
        item_price[i] = (double)auxil::iget(5, 55);
    }

    int optimal_weight = knapsack_s(KNAP_MAX_WEIGHT, ITEM_MAX, item_weight, item_price, item_instance);


    std::cout << std::endl << "-------- ������ � ������� --------- ";
    std::cout << std::endl << "- ���������� ���������(��) : " << ITEM_MAX;
    std::cout << std::endl << "- ����������� �������(��)  : " << KNAP_MAX_WEIGHT;

    std::cout << std::endl << "- ������� ���������(��)    : ";
    for (int i = 0; i < ITEM_MAX; i++) std::cout << item_weight[i] << " ";
    std::cout << std::endl << "- ��������� ���������(y.e.)  : ";
    for (int i = 0; i < ITEM_MAX; i++) std::cout << item_price[i] << " ";
    std::cout << std::endl << "- ����������� ��������� �������(y.e.) : " << optimal_weight;
    std::cout << std::endl << "- ��� �������(��): ";
    int s = 0; for (int i = 0; i < ITEM_MAX; i++) s += item_instance[i] * item_weight[i];
    std::cout << s;
    std::cout << std::endl << "- ������� ��������: ";
    for (int i = 0; i < ITEM_MAX; i++) std::cout << " " << item_instance[i];
    std::cout << std::endl << std::endl;

    system("pause");
    return 0;
}
