#include "sort.h"
#include <cmath>

Sort::Sort(List *_list, bool _checkNegative){
    list          = _list;
    supList       = nullptr;
    result        = nullptr;
    maxNumLine    = 0; //CountNumInNum(_list->absMax);
    minNumLine    = 0; //CountNumInNum(_list->absMin);
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
    return n;
}

void Sort::InitSupList(){
    if (!checkNegavive){
        maxNumLine = CountNumInNum(list->absMax);
        minNumLine = CountNumInNum(list->absMin);
    }
    else{
        maxNumLine = CountNumInNum(list->MaxValue());
        maxNumLine = CountNumInNum(list->MinValue());
    }
    supList = new List[maxNumLine - minNumLine + 1];

    Node *node = list->Head();
    while (node != nullptr){
        int k = 0;
        if (!checkNegavive){
            k = CountNumInNum(abs(node->value));
        }
        supList[k - minNumLine].Append(node->value);
        node = node->next;
    }
}

void Sort::SortSupList(int i){
    int max = 0;
    int min = 0;
    if (!checkNegavive){
        max = supList[i].absMax;
        min = supList[i].absMin;
    }
    else {
        max = abs(supList[i].MaxValue());
        min = abs(supList[i].MinValue());
    }

    List sortlist[max - min + 1];
    Node *node = supList[i].Head();

    while (node!= nullptr){
        int n = 0;
        if (!checkNegavive){
            n = abs(node->value);
        }
        sortlist[n - min].Append(node->value);
        node = node->next;
    }

    for (int j = 0; j < max - min + 1; j++){

        result->Appendlist(sortlist[j]);
    }

}

List *Sort::SortList(){
    result = new List;

    InitSupList();

    for (int i = 0; i < maxNumLine - minNumLine + 1; i++){
        if (supList[i].Size() != 0){
            SortSupList(i);
        }
    }

    return result;
}
