//programa que trabaja con listas ligadas, contiene las funciones de insertar al inicio, al final, eliminar al inicio y al final.
//A01739326 Belsy Aislinn Rueda Santiago, A01739755 Michelle Amanda Hernández Legaria, A01736333 María José Serrano Notario 
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
void inserta_al_Inicio(Nodo<T>** cabeza, T dato) {
    Nodo<T>* nuevo = new Nodo<T>(dato);         // O(1)
    nuevo->setNext(*cabeza);                    // O(1)
    *cabeza = nuevo;                            // O(1)
}



// Funcion inserta al final
template <typename T>
void inserta_al_Final(Nodo<T>** cabeza, T dato) {
    Nodo<T>* nuevo = new Nodo<T>(dato);          // O(1) 

    if (*cabeza == nullptr) {                    // O(1) 
        *cabeza = nuevo;                         // O(1) 
        return;                                  // O(1)
    }

    Nodo<T>* actual = *cabeza;                   // O(1) 
    while (actual->getNext() != nullptr) {       // O(n) 
        actual = actual->getNext();              // O(1) 
    }

    actual->setNext(nuevo);                      // O(1) 
}


//Función elimina al inicio
//o(1)
template <typename T>
void Elimina_al_Inicio(Nodo<T>** cabeza) {
    if(*cabeza == nullptr)
        cout << "ERROR" << endl;
    else
        Nodo<T> * tmp = *cabeza;
        *cabeza = (*cabeza)->getNext()
        delete tmp;
}


//Función elimina al final
//o(n)
template <typename T>
void Elimina_al_Final(Nodo<T>** cabeza) {
    if (*cabeza == nullptr) {
        return;
    }

    if ((*cabeza)->getNext() == nullptr) {
        delete *cabeza;
        *cabeza = nullptr;
        return;
    }

    Nodo<T>* tmp = *cabeza;

    Nodo<T>* last = nullptr;

    while (actual->getNext() != nullptr) {
        last = tmp;
        tmp = tmp->getNext(); // 'actual' avanza.
    }

    last->setNext(nullptr);

    delete tmp;

}





//Imprime
template <typename T>
void Imprime(Nodo<T>* cabeza) {
    Nodo<T>* actual = cabeza;
    while (actual != nullptr) {                 // O(n)
        cout << actual->getDato() << "\n";
        actual = actual->getNext();
    }
}
