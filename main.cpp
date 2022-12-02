#include <iostream>
#include <fstream>
#include "list.h"
#include "sort.h"

/*
 * Лексикографическая сортировка
 * 2N чисел
 * Можно разбить на пары
 * что произведения в парах ровны
 * Сделать разбиение если
 * а) натуральные
 * б) целые
*/

bool ReadFromFile(char *f, List &list){
    std::fstream file;
    file.open(f, std::ios_base::in);

    int n = 0;
    file >> n;

    if (file.fail()){
        std::cout << "ERROR: fail read count numbers" << "\n";
        return 0;
    }
    for (int i = 0; i < n; i++){
        int num;
        file >> num;
        list.Append(num);
    }
    if (file.fail()){
        std::cout << "ERROR: fail read number" << "\n";
        return 0;
    }

    file.close();

    return 1;
}

int main(int argc, char **argv)
{
    if (argc < 2){
        std::cout << "ERROR: No main arguments" << std::endl;
        return 0;
    }
    List list;

    if (!ReadFromFile(argv[1], list)){
        std::cout << "ERROR: fail data reading" << std::endl;
        return 0;
    }

    Sort sort(&list);
    List *result = sort.SortList();
    //print task

    Node *head = result->Head();
    Node *tail = result->Tail();

    for (int i = 0; i != result->Size()/2; i++){
        std::cout << head->value << " " << tail->value << "\n";
        head = head->next;
        tail = tail->prevous;
    }
    std::cout << std::endl;

    delete result;

    return 0;
}
