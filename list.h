#ifndef LIST_H
#define LIST_H

#include <iostream>

struct Node{
    int value;
    Node* next;
    Node* prevous;
};

class List
{
private:
    int size;
    Node *head;
    Node *tail;
    int min;
    int max;

public:
    List();
    List(const List &list);
    ~List();

    void Append(int _value);
    void Appendlist(List &list);
    void Delete(Node *node);
    void Print();
    void Clear();

    //getters
    Node* Head();
    Node* Tail();
    int Size();
    int MaxValue();
    int MinValue();

    //operator
    List &operator=(const List &right);
};

#endif // LIST_H
