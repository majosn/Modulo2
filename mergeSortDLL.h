#ifndef MERGESORTDLL_H
#define MERGESORTDLL_H

#include "double_LL.h"
using namespace std;

// Método de los dos punteros (slow y fast)
template <typename T>
void splitDLL(Nodo<T>* head, Nodo<T>** left, Nodo<T>** right) {
    // Si la lista está vacía o solo tiene un nodo
    if (!head || !head->getNext()) {
        *left = head;
        *right = nullptr;
        return;
    }

    // Se crean dos punteros
    Nodo<T>* slow = head; // Avanza de uno en uno
    Nodo<T>* fast = head; // Avanza de dos en dos

    // Mientras el rápido no llegue al final
    while (fast->getNext() && fast->getNext()->getNext()) {
        slow = slow->getNext();             // avanza 1
        fast = fast->getNext()->getNext();  // avanza 2
    }

    // slow queda en el nodo del medio
    *left = head;            // Primera mitad
    *right = slow->getNext(); // Segunda mitad

    // Se separan las dos listas
    slow->setNext(nullptr);
    if (*right) (*right)->setPrev(nullptr);
}

//Función que fusiona dos mitades ordenadas de una lista doblemente ligada
//O(n)
template <typename T>
Nodo<T>* mergeDLL(Nodo<T>* a, Nodo<T>* b, int (*cmp)(const T&, const T&)) {
    if (!a) return b;
    if (!b) return a;

    Nodo<T>* head = nullptr;
    Nodo<T>* tail = nullptr;

    //Se selecciona el primer nodo (menor según el comparador)
    if (cmp(a->getDato(), b->getDato()) <= 0) {
        head = tail = a;
        a = a->getNext();
    } else {
        head = tail = b;
        b = b->getNext();
    }
    head->setPrev(nullptr);

    //Se fusiona el resto de los nodos
    while (a && b) {
        if (cmp(a->getDato(), b->getDato()) <= 0) {
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

    //Si quedan elementos en alguna mitad, se agregan al final
    Nodo<T>* rest = (a) ? a : b;
    if (rest) {
        tail->setNext(rest);
        rest->setPrev(tail);
    }

    return head;
}

//MergeSort final
//O(n log n)
template <typename T>
void mergeSortDLL(Nodo<T>** headRef, int (*cmp)(const T&, const T&)) {
    Nodo<T>* head = *headRef;

    //Caso base: lista vacía o con un solo nodo
    if (!head || !head->getNext()) return;

    Nodo<T>* left = nullptr;
    Nodo<T>* right = nullptr;

    //Se divide la lista en dos mitades
    splitDLL(head, &left, &right);

    //Se ordena cada mitad de forma recursiva
    mergeSortDLL(&left, cmp);
    mergeSortDLL(&right, cmp);

    //Se fusionan las dos mitades ya ordenadas
    *headRef = mergeDLL(left, right, cmp);
}

#endif // MERGESORTDLL_H
