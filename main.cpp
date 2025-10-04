//programa que trabaja con listas ligadas, contiene las funciones de insertar al inicio, al final, eliminar al inicio y al final.
//A0000000 X, A00000000 X, A01736333 María José Serrano Notario 
//04/10/25

#include using namespace std;

template<class T>
Class Nodo{ 
    T dato; Nodo* next;
        public; 
    T getDato(){ return this ->dato; }
    void setDato(T dato){ 
        this->dato = dato;
    }
    Nodo* getNext(){ return this->next; } 
    void setNext(Nodo* next){ this->next = next; } 
    Nodo(T dato, Nodo* next){ this->dato = dato; this->next = next; }

};

//Función insertar al inicio
template void inserInicio(Nodo** cabeza, T dato) { 
    Nodo* nuevo = new Nodo(dato); nuevo->setNext(*cabeza); *cabeza = nuevo; 
}
