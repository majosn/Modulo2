//programa que trabaja con listas ligadas, contiene las funciones de reverse, equals y concatenar.
//A01739326 Belsy Aislinn Rueda Santiago, A01739755 Michelle Amanda Hernández Legaria, A01736333 María José Serrano Notario
//11/10/25

#include <iostream>
#include "lista.h"
#include "stack.h"
using namespace std;


//funcion que reversa una lista ligada
template <typename T>
void reverse(Nodo<T>* head) {
    //los nodos se almacenaran en una pila
    Stack<T> pila;
    Nodo<T>* tmp = head;

    while(tmp!=NULL) {
        //hasta el ultimo nodo, se agregaran a la pila, invirtiendo el orden
        pila.push(tmp->getDato());
        tmp = tmp->getNext();
    }
    tmp = head;
    // el ultimo nodo se convierte en head
    while(!pila.isEmpty()) {
        //hasta que la pila este vacia se vuelven a ligar los nodos
        tmp->setDato(pila.pop());
        tmp = tmp->getNext();
    }
}


//equal
template <typename T>
bool equals(Nodo<T>* a, Nodo<T>* b) {
    while (a != nullptr && b != nullptr) {
        if (a->getDato() != b->getDato()) return false;
        a = a->getNext();
        b = b->getNext();
    }
    return (a == nullptr && b == nullptr);
}

//concat
template <typename T>
void concat(Nodo<T>** l1, Nodo<T>* l2){
    if (*l1 == nullptr){
        *l1 = l2;
        return;
    }
    Nodo<T>* temp = *l1;
    while (temp->getNext() != nullptr)
        temp = temp->getNext();
    temp->setNext(l2);
}


int main(){
    //iniciadores de las head de la listas
    Nodo<int>* head1 = nullptr;
    Nodo<int>* head2 = nullptr;

    int m, n, val;

    //Entradad de la lista 1
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>val;
        inserta_al_Final(&head1, val);
    };

    //Entrada de lista 2
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>val;
        inserta_al_Final(&head2, val);
    };

    //Invertir listas
    reverse(head1);
    Nodo<int>* rev1 = head1;
    reverse(head2);
    Nodo<int>* rev2 = head2;

    imprime(rev1);
    imprime(rev2);

    //Concat reverse list1+ revers list2

    Nodo* copyRev1= rev1;
    Nodo* copyRev2=rev2;

    concat(&copyRev2,copyRev1);
    imprime(copyRev2);

    /*
    //verificar si las listas son iguales
    cout<<(equals(rev1,rev2) ? "true":"false")<<endl,
    */

    return 0;
}
