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

    Node *node = list.head;
    while (node != nullptr){
        Append(node->value);
        node = node->next;
    }
}

List::~List(){
    Node *node = tail;
    while (node != nullptr){
        Node *sup_node = node;
        node = node->prevous;
        if (sup_node){
            delete sup_node;
        }
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
        node->id = 0;
        size++;
    }
    else{
        int avalue = abs(_value);
        max = max < avalue ? avalue : max;
        min = min > avalue ? avalue : min;
        node->id = tail->id + 1;
        node->next = nullptr;
        node->prevous = tail;
        tail->next = node;
        tail = node;
        size++;
    }
}

void NodeSetValue(Node *node, int value){
    if (!node){
        return;
    }
    node->value = value;
}

void List::Appendlist(List &list){
    if (list.Head() == nullptr){
        return;
    }
    //Node *node = list.head;
    //while (node != nullptr){
    //    Append(node->value);
    //    node = node->next;
    //}

    Node *node = list.head;
    if (!head){
        head = node;
    } else {
        node->prevous = tail;
        tail->next = node;
    }
    max = max < abs(list.max) ? abs(list.max) : max;
    min = min < abs(list.min) ? abs(list.min) : min;

    tail = list.tail;
    size += list.size;

    list.head = nullptr;
    list.tail = nullptr;
    list.size = 0;

}

void List::Delete(Node *node)
{
    Node *sup_node = head;
    while (sup_node != nullptr){
        if (sup_node == node){
            break;
        }
        sup_node = sup_node->next;
    }
    if (sup_node == nullptr) return;
    else{
        if (node->prevous)
            node->prevous->next = node->next;

        if (node->next){
            node->next->prevous = node->prevous;
        }
        if (node == head){
            head = node->next;
        }
        if (node == tail){
            tail = node->prevous;
        }
        delete node;
        size--;
    }
}

void List::Print(){
    for (Node *node = head; node != nullptr; node = node->next){
        std::cout << node->value << std::endl;
    }
}
void List::Clear(){

    Node *node = tail;
    while (node != nullptr){
        Node *sup_node = node;
        node = node->prevous;
        if (sup_node){
            delete sup_node;
        }
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

    Node *node = right.head;

    while (node != nullptr){
        Append(node->value);
        node = node->next;
    }

    return *this;
}


