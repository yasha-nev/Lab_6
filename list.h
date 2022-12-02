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

    void Delete(Node *node);
    void Appendlist(List &list);
    void Print();
    void Clear();

    //getters
    Node* Head();
    Node* Tail();
    int Size();
    int MaxValue();
    int MinValue();
    List &operator=(const List &right);
};

#endif // LIST_H
