#include "sort.h"
#include <cmath>

Sort::Sort(List *_list){
    list          = _list;
    supList       = nullptr;
    maxNumLine    = 0;
    minNumLine    = 0;
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

int Sort::GetNumFromNum(int num, int k){
    int res;
    for (int i = 0; i < k; i++){
        res = num % 10;
        num = num / 10;
    }

    return res;
}

void Sort::InitSupList(){
    maxNumLine = CountNumInNum(list->MaxValue());
    minNumLine = CountNumInNum(list->MinValue());

    int n   = abs(maxNumLine - minNumLine) + 1;
    supList = new List[n];

    for (Node *node = list->Head(); node != nullptr; node = node->next){
        int i = abs(CountNumInNum(node->value) - minNumLine);
        supList[i].Append(node->value);
    }
}

List Sort::SortNumbers(List list, int i){
    if (i < 1){
        return list;
    }

    List l[10];
    List res;

    for (Node *node = list.Head(); node != nullptr; node = node->next){
        int k = GetNumFromNum(abs(node->value), i);
        l[k].Append(node->value);
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
