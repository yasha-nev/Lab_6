#include "sort.h"
#include <cmath>

Sort::Sort(List *_list, bool _checkNegative){
    list          = _list;
    supList       = nullptr;
    maxNumLine    = 0;
    minNumLine    = 0;
    checkNegavive = _checkNegative;
}

Sort::~Sort(){
    delete[] supList;
}

int Sort::CountNumInNum(int num){
    int n = 0;
    int supNum = abs(num);
    while (supNum > 0){
        supNum = supNum / 10;
        n++;
    }
    if (checkNegavive){
        n = n * num/abs(num);
    }
    return n;
}

void Sort::InitSupList(){
    if (!checkNegavive){
        maxNumLine = CountNumInNum(list->AbsMaxValue());
        minNumLine = CountNumInNum(list->AbsMinValue());
    }
    else{
        maxNumLine = CountNumInNum(list->MaxValue());
        minNumLine = CountNumInNum(list->MinValue());
    }

    int n   = abs(maxNumLine - minNumLine) + 1;
    supList = new List[n];

    Node *node = list->Head();
    while (node != nullptr){
        int i = abs(CountNumInNum(node->value) - minNumLine);
        supList[i].Append(node->value);
        node = node->next;
    }
}

void Sort::SortSupList(int i){
    int max = 0;
    int min = 0;

    if (!checkNegavive){
        max = supList[i].AbsMaxValue();
        min = supList[i].AbsMinValue();
    }
    else {
        max = supList[i].MaxValue();
        min = supList[i].MinValue();
    }
    int k = abs(max - min + 1);
    List sortlist[k];

    Node *node = supList[i].Head();

    while (node!= nullptr){
        int num = node->value;
        if (!checkNegavive){
            num = abs(node->value);
        }

        int n = abs(num - min);
        sortlist[n].Append(node->value);
        node = node->next;
    }

    for (int j = 0; j < max - min + 1; j++){
        result->Appendlist(sortlist[j]);
    }
}

List *Sort::SortList(){
    result = new List;

    InitSupList();
    for (int i = 0; i < abs(maxNumLine - minNumLine + 1); i++){
        if (supList[i].Size() != 0){
            SortSupList(i);
        }
    }

    return result;
}
