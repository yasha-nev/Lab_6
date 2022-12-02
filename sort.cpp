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
    maxNumLine = CountNumInNum(list->MaxValue());
    minNumLine = CountNumInNum(list->MinValue());

    int n   = abs(maxNumLine - minNumLine) + 1;
    supList = new List[n];

    Node *node = list->Head();
    while (node != nullptr){
        int i = abs(CountNumInNum(node->value) - minNumLine);
        supList[i].Append(node->value);
        node = node->next;
    }
}

int power(int num, int k){
    int res;
    for (int i = 0; i < k; i++){
        res = num % 10;
        num = num / 10;
    }

    return res;
}

List Sort::SortNumbers(List list, int i){
    if (i < 1){
        return list;
    }

    List l[10];
    List res;

    Node *node = list.Head();
    while(node != nullptr){
        int k = power(abs(node->value), i);
        l[k].Append(node->value);
        node = node->next;
    }

    for (int j = 0; j < 10; j++){
        if (l[i].Size() > 1){
            List ll = SortNumbers(l[j], i-1);
            res.Appendlist(ll);
        }
        else{
            res.Appendlist(l[j]);
        }
    }
    return res;
}

List *Sort::SortList(){
    List *result = new List;

    InitSupList();
    for (int i = 0; i < abs(maxNumLine - minNumLine + 1); i++){
        if (supList[i].Size() != 0){
            List l = SortNumbers(supList[i], i+1);
            result->Appendlist(l);
        }
    }

    return result;
}
