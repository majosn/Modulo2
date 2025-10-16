// Lista doblemente ligada 
#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

#include <iostream>
using namespace std;

/* clase nodo que guarda un dato y sus punteros anterior y siguiente (O(1)) */
template <typename T>
class Nodo {
private:
    T dato;          // valor que guarda el nodo
    Nodo* next;      // puntero al siguiente
    Nodo* prev;      // puntero al anterior
public:
    // crea un nuevo nodo con su dato (O(1))
    Nodo(const T& d) : dato(d), next(NULL), prev(NULL) {}

    // traduce: regresa o cambia el dato, siguiente o anterior (todas O(1))
    T& getDato() { return dato; }
    const T& getDato() const { return dato; }
    void setDato(const T& d) { dato = d; }

    Nodo* getNext() { return next; }
    const Nodo* getNext() const { return next; }
    void setNext(Nodo* n) { next = n; }

    Nodo* getPrev() { return prev; }
    const Nodo* getPrev() const { return prev; }
    void setPrev(Nodo* p) { prev = p; }
};

/* inserta un nuevo nodo al inicio de la lista (O(1)) */
// traduce: crea el nodo y lo pone como la nueva cabeza
template <typename T>
void inserta_al_Inicio(Nodo<T>** cabeza, const T& dato) {
    Nodo<T>* nuevo = new Nodo<T>(dato);
    if (*cabeza == NULL) { 
        *cabeza = nuevo; 
        return; 
    }
    nuevo->setNext(*cabeza);
    (*cabeza)->setPrev(nuevo);
    *cabeza = nuevo;
}

/* inserta un nuevo nodo al final de la lista (O(n)) */
// traduce: recorre toda la lista hasta el final y agrega el nodo ahí
template <typename T>
void inserta_al_Final(Nodo<T>** cabeza, const T& dato) {
    Nodo<T>* nuevo = new Nodo<T>(dato);
    if (*cabeza == NULL) { 
        *cabeza = nuevo; 
        return; 
    }
    Nodo<T>* t = *cabeza;
    while (t->getNext()) t = t->getNext(); // recorre toda la lista
    t->setNext(nuevo);
    nuevo->setPrev(t);
}

/* elimina el primer nodo de la lista (O(1)) */
// traduce: borra el nodo de la cabeza y mueve el inicio al siguiente
template <typename T>
void elimina_al_Inicio(Nodo<T>** cabeza) {
    if (*cabeza == NULL) { 
        cout << "ERROR\n"; 
        return; 
    }
    Nodo<T>* t = *cabeza;
    *cabeza = t->getNext();
    if (*cabeza) (*cabeza)->setPrev(NULL);
    delete t;
}

/* elimina el último nodo de la lista (O(n)) */
// traduce: recorre hasta el último nodo y lo borra
template <typename T>
void elimina_al_Final(Nodo<T>** cabeza) {
    if (*cabeza == NULL) { 
        cout << "ERROR\n"; 
        return; 
    }
    Nodo<T>* t = *cabeza;

    // si solo hay un nodo
    if (!t->getNext()) { 
        *cabeza = NULL; 
        delete t; 
        return; 
    }

    // recorre hasta el final
    while (t->getNext()) t = t->getNext();

    // desconecta y borra el último
    t->getPrev()->setNext(NULL);
    delete t;
}

#endif // DOUBLE_LL_H

