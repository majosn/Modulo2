//programa que implementa listas doblemente ligadas.
//A01739326 Belsy Aislinn Rueda Santiago, A01739755 Michelle Amanda Hernández Legaria, A01736333 María José Serrano Notario
//15/10/25

#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

using namespace std;
#include <iostream>

template <typename T>
class Nodo {
private:
    T dato;
    Nodo* next;
    Nodo* prev;

public:
    // Constructor
    // O(1)
    Nodo(T dato) {
        this->dato = dato;
        this->next = nullptr;
        this->prev = nullptr;
    }

    T getDato() {
        return dato;
    }

    void setDato(T dato) {
        this->dato = dato;
    }

    Nodo* getNext() {
        return next;
    }

    void setNext(Nodo* next) {
        this->next = next;
    }
    Nodo* getPrev() {
        return prev;
    }
    void setPrev(Nodo* prev) {
        this->prev = prev;
    }
};


//Función insertar al inicio
//o(1)
template <typename T>
void inserta_al_Inicio(Nodo<T>** cabeza, T dato) {
    Nodo<T>* nuevo = new Nodo<T>(dato);

    if (cabeza == nullptr) {
        cabeza = nuevo;
        return;
    }
    nuevo->next = cabeza;
    cabeza->prev = nuevo;
    cabeza = nuevo;
}


// Funcion inserta al final
template <typename T>
void inserta_al_Final(Nodo<T>** cabeza, T dato) {
    Nodo<T>* nuevo = new Nodo<T>(dato);

    if (cabeza == nullptr) {
        cabeza = nuevo;
        return;
    }

    Nodo<T>* temp = cabeza;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = nuevo;
    nuevo->prev = temp;

}


//Función elimina al inicio
//o(1)
template <typename T>
void elimina_al_Inicio(Nodo<T>** cabeza) {

    if (cabeza == nullptr) {
        cout << "ERROR" << endl;
        return;
    }

    // Update the head pointer and delete the first node.
    Nodo<T>* temp = cabeza;
    cabeza = cabeza->next;
    if (cabeza != nullptr) {
        cabeza->prev = nullptr;
    }
    delete temp;
}


//Función elimina al final
//o(n)
template <typename T>
void elimina_al_Final(Nodo<T>** cabeza) {

    if (cabeza == nullptr) {
        cout << "ERROR" << endl;
        return;
    }

    Nodo<T>* temp = cabeza;
    if (temp->next == nullptr) {
        cabeza = nullptr;
        delete temp;
        return;
    }

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->prev->next = nullptr;
    delete temp;
}

//Imprime
//o(n)
template <typename T>
void imprime(Nodo<T>* cabeza) {
    Nodo<T>* temp = cabeza;
    while (temp != nullptr) {
        cout << temp->data << "\n";
        temp = temp->next;
    }
    cout << endl;
}



#endif //DOUBLE_LL_H
