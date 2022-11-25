#include <iostream>
#include "list.h"
#include "sort.h"

using namespace std;

/*
 * Лексикографическая сортировка
 * 2N чисел
 * Можно разбить на пары
 * что произведения в парах ровны
 * Сделать разбиение если
 * а) натуральные
 * б) целые
*/

/*
 * 1024:
 * 1 * 1024
 * 2 * 512
 * 4 * 256
 * 8 * 128
 * 16 * 64
 * 32 * 32
 * 64 * 16
 * 128 * 8
 * 256 * 4
 * 512 * 2
 * 1024 * 1
 */

//int arr[] = {1, 2, 4, 8, 16, 32, 32, 64, 128, 256, 512, 1024};
int arr[] = {-1024, 2, 16, -1, 32, 128, 64, 32, -4, -256, 8, 512};

int main()
{
    int countNegative = 0;
    bool checkNegative = 0;
    int n = 12;

    List list;
    for (int i = 0; i < n; i++){
        list.Append(arr[i]);

        if (arr[i] < 0) countNegative++;
    }

    if (countNegative == 0 || countNegative != n / 2){
        cout << "case 1\n";
        checkNegative = 0;
    }

    //else{
    //    cout << "case 2\n";
    //    checkNegative = 1;
    //}

    Sort sort(&list, checkNegative);
    List *result = sort.SortList();

    //result->Print();
    //print task
    Node *head = result->Head();
    Node *tail = result->Tail();
    int k = 0;

    while (k != result->Size()/2){
        std::cout << head->value << " " << tail->value << "\n";
        head = head->next;
        tail = tail->prevous;
        k++;
    }

    std::cout << std::endl;

    delete result;

    return 0;
}
