#ifndef MERGESORTDLL_H
#define MERGESORTDLL_H

#include "double_LL.h"
using namespace std;

// divide la lista doblemente ligada en dos mitades (O(n))
template <typename T>
void splitDLL(Nodo<T>* head, Nodo<T>** left, Nodo<T>** right) {
    if (!head || !head->getNext()) {
        *left = head;
        *right = nullptr;
        return;
    }

    Nodo<T>* slow = head;
    Nodo<T>* fast = head;
    //los dos nodos empiezan en el mismo lugar

    while (fast->getNext() && fast->getNext()->getNext()) {
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
    }
    //slow avanza de uno en uno, fast avanza en dos

    *left = head;
    *right = slow->getNext();
    slow->setNext(nullptr);
    if (*right) (*right)->setPrev(nullptr);
}


// fusiona dos mitades ordenadas de una lista doblemente ligada (O(n))
template <typename T>
Nodo<T>* mergeDLL(Nodo<T>* a, Nodo<T>* b, bool (*cmp)(const T&, const T&)) {
    if (!a) return b;
    if (!b) return a;

    Nodo<T>* head = nullptr;
    Nodo<T>* tail = nullptr;

    // selecciona el primer nodo
    if (cmp(a->getDato(), b->getDato())) {
        head = tail = a;
        a = a->getNext();
    } else {
        head = tail = b;
        b = b->getNext();
    }
    head->setPrev(nullptr);

    // fusionar resto de nodos
    while (a && b) {
        if (cmp(a->getDato(), b->getDato())) {
            tail->setNext(a);
            a->setPrev(tail);
            tail = a;
            a = a->getNext();
        } else {
            tail->setNext(b);
            b->setPrev(tail);
            tail = b;
            b = b->getNext();
        }
    }

    Nodo<T>* rest = (a) ? a : b;
    if (rest) {
        tail->setNext(rest);
        rest->setPrev(tail);
    }

    return head;
}

// MergeSort final (O(n log n))
template <typename T>
void mergeSortDLL(Nodo<T>** headRef, bool (*cmp)(const T&, const T&)) {
    Nodo<T>* head = *headRef;
    if (!head || !head->getNext()) return;

    Nodo<T>* left = nullptr;
    Nodo<T>* right = nullptr;

    splitDLL(head, &left, &right);

    mergeSortDLL(&left, cmp);
    mergeSortDLL(&right, cmp);

    *headRef = mergeDLL(left, right, cmp);
}

#endif // MERGESORTDLL_H
