#include "list.h"
#include <cmath>

List::List(){
    head   = nullptr;
    tail   = nullptr;
    size   = 0;
    max    = 0;
    min    = 0;
}

List::List(const List &list){
    head   = nullptr;
    tail   = nullptr;
    size   = 0;
    max    = 0;
    min    = 0;

    for (Node *node = list.head; node != nullptr; node = node->next){
        Append(node->value);
    }
}

List::~List(){
    Node *supNode = nullptr;
    for (Node *node = tail;node != nullptr; node = node->next){
        if (supNode) delete supNode;
        supNode = node;
    }
}

int List::Size(){
    return size;
}

int List::MaxValue(){
    return max;
}

int List::MinValue(){
    return min;
}

Node *List::Head(){
    return head;
}

Node *List::Tail(){
    return tail;
}

void List::Append(int _value){
    Node *node = new Node;
    node->value = _value;
    if (size == 0){
        head = node;
        tail = node;

        max  = abs(_value);
        min  = abs(_value);

        node->next    = nullptr;
        node->prevous = nullptr;
        size++;
    }
    else{
        int avalue = abs(_value);
        max = max < avalue ? avalue : max;
        min = min > avalue ? avalue : min;

        node->next = nullptr;
        node->prevous = tail;

        tail->next = node;
        tail = node;
        size++;
    }
}

void List::Appendlist(List &list){
    if (list.Head() == nullptr){
        return;
    }

    if (!head){
        head = list.head;
    } else {
        list.head->prevous = tail;
        tail->next = list.head;
    }

    max = max < abs(list.max) ? abs(list.max) : max;
    min = min < abs(list.min) ? abs(list.min) : min;

    tail = list.tail;
    size += list.size;

    list.head = nullptr;
    list.tail = nullptr;
    list.size = 0;
}

void List::Delete(Node *_node)
{
    Node * node;
    for (node = head; node  != nullptr; node  = node ->next){
        if (node == _node){
            break;
        }
    }

    if (node == nullptr) return;
    else{
        if (_node->prevous)
            _node->prevous->next = _node->next;

        if (_node->next){
            _node->next->prevous = _node->prevous;
        }
        if (_node == head){
            head = _node->next;
        }
        if (_node == tail){
            tail = _node->prevous;
        }
        delete _node;
        size--;
    }
}

void List::Print(){
    for (Node *node = head; node != nullptr; node = node->next){
        std::cout << node->value << std::endl;
    }
}

void List::Clear(){
    Node *supNode = nullptr;
    for (Node *node = tail;node != nullptr; node = node->next){
        if (supNode) delete supNode;
        supNode = node;
    }
    head   = nullptr;
    tail   = nullptr;
    size   = 0;
    max    = 0;
    min    = 0;
}

List &List::operator=(const List &right){
    if (this == &right) {
        return *this;
    }
    Clear();

    for (Node *node = right.head; node != nullptr; node = node->next){
        Append(node->value);
    }

    return *this;
}


