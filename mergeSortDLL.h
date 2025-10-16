#ifndef MERGESORTDLL_H
#define MERGESORTDLL_H

#include "double_LL.h"

/* divide la lista doble en dos mitades (O(n)) */
// usa dos punteros: slow (avanza 1) y fast (avanza 2)
// al terminar, slow queda en el centro
template <typename T>
void splitDLL(Nodo<T>* head, Nodo<T>** left, Nodo<T>** right) {
    if (!head || !head->getNext()) { 
        *left = head; 
        *right = NULL; 
        return; 
    }

    Nodo<T>* slow = head;
    Nodo<T>* fast = head;

    // recorre la lista hasta que fast llegue al final
    while (fast->getNext() && fast->getNext()->getNext()) {
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
    }

    // separa en dos mitades
    *left = head;
    *right = slow->getNext();
    slow->setNext(NULL);
    if (*right) (*right)->setPrev(NULL);
}

/* fusiona dos mitades ya ordenadas (O(n)) */
// compara elemento por elemento y une las dos mitades
template <typename T>
Nodo<T>* mergeDLL(Nodo<T>* a, Nodo<T>* b, bool (*cmp)(const T&, const T&)) {
    if (!a) return b;
    if (!b) return a;

    Nodo<T>* head = NULL;
    Nodo<T>* tail = NULL;

    // elige el primer nodo de la lista resultante
    if (cmp(a->getDato(), b->getDato())) { 
        head = tail = a; 
        a = a->getNext(); 
    } else { 
        head = tail = b; 
        b = b->getNext(); 
    }
    head->setPrev(NULL);

    // recorre y fusiona comparando los datos
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

    // si quedan elementos en una lista, los agrega al final
    Nodo<T>* rest = (a) ? a : b;
    if (rest) { 
        tail->setNext(rest); 
        rest->setPrev(tail); 
    }

    return head;
}

/* ordena toda la lista usando merge sort (O(n log n)) */
// divide la lista en mitades, ordena recursivamente y fusiona
template <typename T>
void mergeSortDLL(Nodo<T>** headRef, bool (*cmp)(const T&, const T&)) {
    Nodo<T>* head = *headRef;
    if (!head || !head->getNext()) return;

    Nodo<T>* left = NULL;
    Nodo<T>* right = NULL;

    // divide la lista en dos partes
    splitDLL(head, &left, &right);

    // ordena ambas partes recursivamente
    mergeSortDLL(&left, cmp);
    mergeSortDLL(&right, cmp);

    // fusiona las dos mitades ya ordenadas
    *headRef = mergeDLL(left, right, cmp);
}

#endif // MERGESORTDLL_H

