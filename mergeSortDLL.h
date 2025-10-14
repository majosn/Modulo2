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
