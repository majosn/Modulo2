//
// Created by majo on 10/11/25.
//

#ifndef ABB_H
#define ABB_H
#include "double_LL.h"

using namespace std;
#include <iostream>

template <typename T>
struct Node {
    T dato;
    Node<T>* izq;
    Node<T>* derecha;

    //constructor
    Node(T item) {
        dato = item;
        izq = NULL;
        derecha = NULL;
    }
};


Node<T>* inserta(Node<T>* nodo, int dato) {

    //si el arbol esta vacio
    if (nodo == NULL) {
        return new Node(dato);
    }

    //si el dato ya esta en el arbol regresa la llave
    if (nodo->dato == dato) {
        return nodo;
    }

    // si el dato es mayor se agrega a la izquierda
    if (nodo->dato < dato) {
        nodo->izq = inserta(nodo->izq, dato);
    }else if (nodo->dato > dato) {
        nodo->derecha = inserta(nodo->derecha, dato);
        // si es menor agrega a la derecha
    }
    return node;
}

template <typename T>
void inorden(Node<T>* root) {
    if (root != NULL) {
        inorden(root->izq);
        cout << root->dato << " ";
        inorden(root->derecha);
        //IRD inorden
    }
}


#endif //ABB_H
