#ifndef SORT_H
#define SORT_H

#include "list.h"

class Sort
{
public:
    Sort(List *list);
    ~Sort();
    List *SortList();

private:
    List *supList;
    List *list;

    int maxNumLine;
    int minNumLine;

    int GetNumFromNum(int num, int k);
    int CountNumInNum(int num);
    void InitSupList();
    List SortNumbers(List list, int i);
};

#endif // SORT_H
