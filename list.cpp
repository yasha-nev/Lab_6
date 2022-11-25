#include "list.h"
#include <cmath>

List::List(){
    head   = nullptr;
    tail   = nullptr;
    size   = 0;
    max    = 0;
    min    = 0;
    absMax = 0;
    absMin = 0;
}
List::List(const List &list){
    if (list.size != 0){
        List newlist;
        Node *node = list.head;
        while (node != nullptr){
            newlist.Append(node->value);
            node = node->next;
        }
        head = newlist.head;
        tail = newlist.tail;
        size = list.size;
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

Node *List::Head(){
    return head;
}

Node *List::Tail(){
    return tail;
}

int List::MaxValue(){
    return max;
}

int List::MinValue(){
    return min;
}

void List::Append(int _value){
    Node *node = new Node;
    node->value = _value;
    if (size == 0){
        absMax = abs(_value);
        absMin = abs(_value);
        max = _value;
        min = _value;

        head = node;
        tail = node;

        node->next    = nullptr;
        node->prevous = nullptr;
        node->id = 0;
        size++;
    }
    else{
        absMax = absMax > abs(_value) ? absMax : abs(_value);
        absMin = absMin < abs(_value) ? absMin : abs(_value);

        max = max > _value ? max : _value;
        min = min < _value ? min : _value;

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
    max = max > list.max ? max : list.max;
    min = min < list.min ? min : list.min;

    absMax = absMax > list.absMax ? absMax : list.absMax;
    absMin = absMin < list.absMin ? absMin : list.absMin;

    Node *node = list.head;
    if (!head){
        head = node;
    } else {
        node->prevous = tail;
        tail->next = node;
    }

    tail = list.tail;
    size += list.size;

    list.head = nullptr;
    list.tail = nullptr;
    list.size = 0;

}

void List::Insert(Node *past_node, int _value){
    if (size == 0){
        Append(_value);
        return;
    }
    Node *node = new Node;
    node->value = _value;

    node->next = past_node->next;
    past_node->next = node;
    node->prevous = past_node;

    if (past_node == tail){
        tail = node;
    }
    size++;
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
    Node *node = head;
    while (node != nullptr){
        std::cout << node->value << std::endl;
        node = node->next;
    }
}
