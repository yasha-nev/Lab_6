#ifndef LIST_H
#define LIST_H

#include <iostream>

struct Node{
    int value;
    int id;
    Node* next;
    Node* prevous;
};

class List
{
private:


    int max;
    int min;
    int size;
    Node *head;
    Node *tail;

public:
    List();
    List(const List &list);
    ~List();

    int absMax;
    int absMin;

    void Append(int _value);
    void Insert(Node *node, int _value);
    void Delete(Node *node);
    void Appendlist(List &list);
    void NodeSetValue(Node *node, int value);
    void Print();

    //getters
    Node* Head();
    Node* Tail();
    int Size();
    int MaxValue();
    int MinValue();
};

#endif // LIST_H
