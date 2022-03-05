#include "Priority_Queue.h"

int main()
{
    setlocale(LC_ALL, "");
    Priority_Queue My_Queue;
    int key = 0;
    do
    {
        cout << "\nВыберите действие [1..7]:";
        cout << "\n1) Работа методов: конструкторы без параметров, копирования, перемещения.";
        cout << "\n2) Работа методов: копирующий и перемещающий операторы присваивания.";
        cout << "\n3) Работа методов: определение числа элементов в очереди, имеющих конкретный приоритет, и общего количества элементов.";
        cout << "\n4) Работа методов: проверка на пустоту очереди.";
        cout << "\n5) Работа методов: вставка элемента со значением и приоритетом.";
        cout << "\n6) Работа методов: удаление элемента из очереди.";
        cout << "\n7) Работа методов: получение информации о приоритете и значении элемента, стоящего в голове очереди.";
        cout << "\n0) Завершение программы\n-->";
        cin >> key;

        switch (key)
        {
        case 1:
        {
            system("cls");
            Priority_Queue My_Queue_2(My_Queue);
            My_Queue_2.print();

            break;
        }
        

        case 2:
        {
            system("cls");
            Priority_Queue My_Queue_3;
            My_Queue_3 = My_Queue;
            My_Queue_3.print();

            break;
        }


        case 3:
        {
            system("cls");
            My_Queue.count_priority();
            My_Queue.count_all();

            break;
        }
        case 4:
        {
            system("cls");
            My_Queue.empty();

            break;
        }
        case 5:
        {
            system("cls");
            My_Queue.push();

            break;
        }

        case 6:
        {
            system("cls");
            My_Queue.pop();

            break;
        }

        case 7:
        {
            system("cls");
            My_Queue.get_front();

            break;
        }
        }
    } 
    while (key != 0);
    system("pause");

    return 0;
}