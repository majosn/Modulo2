//programa que trabaja con listas ligadas, contiene las funciones de insertar al inicio, al final, eliminar al inicio y al final.
//A0000000 X, A01739755 Michelle Amanda Hernández Legaria, A01736333 María José Serrano Notario 
//04/10/25

#include <iostream>
using namespace std;

template <typename T>
class Nodo {
private:
    T dato;
    Nodo* next;

public:
    // Constructor
    // O(1)
    Nodo(T dato, Nodo* next = nullptr) {
        this->dato = dato;
        this->next = next;
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
};

//Función insertar al inicio
template <typename T>
void inserInicio(Nodo<T>** cabeza, T dato) {
    Nodo<T>* nuevo = new Nodo<T>(dato);         // O(1)
    nuevo->setNext(*cabeza);                    // O(1)
    *cabeza = nuevo;                            // O(1)
}


//Función inserta al final

//Función elimina al inicio

//Función elimina al final

//Imprime
template <typename T>
void imprime(Nodo<T>* cabeza) {
    Nodo<T>* actual = cabeza;
    while (actual != nullptr) {                 // O(n)
        cout << actual->getDato() << "\n";
        actual = actual->getNext();
    }
}
