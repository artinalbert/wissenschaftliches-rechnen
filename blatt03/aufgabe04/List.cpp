//
// Created by chris on 5/1/19.
//

#include "List.h"

List::List() {
    this->m_length = 0;
    this->m_head = nullptr;
}

List::~List() {
    Node *n = first();
    Node *new_node = nullptr;
    while(n != nullptr){
        new_node = next(n);
        delete n;
        n = new_node;
    }
    this->m_length = 0;
}

void List::append(int i){
    Node *node = new Node(i);
    if (this->m_head == nullptr) {
        this->m_head = node;
    } else {
        for (Node *n = first(); n != nullptr; n = next(n)) {
            if (n->getNext() == nullptr) {
                n->setNext(node);
                break;
            }
        }
    }
    this->m_length++;
}

Node *List::first() const {
    return this->m_head;
}

Node *List::next(const Node *n) const {
    return n->getNext();
}


void List::insert(Node *n, int i){
    Node *node = new Node(i);
    if(n == first()) {
        this->m_head = node;
        node->setNext(n);
    } else {
        for (Node *current = first(); current != nullptr; current = next(current)) {
            if (current->getNext() == n ){
                node->setNext(current->getNext());
                current->setNext(node);
                break;
            }
        }
    }
    this->m_length++;
}

void List::erase(Node *n) {
    if(this->m_head == n) {
        this->m_head = n->getNext();
        delete n;
    } else {
        for(Node *current = first(); current != nullptr; current = next(current)) {
            if(current->getNext() == n){
                current->setNext(current->getNext()->getNext());
                delete n;
            }
        }
    }
    this->m_length--;
}