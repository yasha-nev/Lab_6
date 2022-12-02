#ifndef SORT_H
#define SORT_H

#include "list.h"

class Sort
{
public:
    Sort(List *list, bool checkNegative);
    ~Sort();
    List *SortList();

private:
    List *supList;
    List *list;

    int maxNumLine;
    int minNumLine;

    bool checkNegavive;

    int CountNumInNum(int num);
    void InitSupList();
    List SortNumbers(List list, int i);
    void SortSupList(int i);
};

#endif // SORT_H
