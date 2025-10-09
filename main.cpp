//programa que trabaja con listas ligadas, contiene las funciones de reverse, equals y concatenar.
//A01739326 Belsy Aislinn Rueda Santiago, A01739755 Michelle Amanda Hernández Legaria, A01736333 María José Serrano Notario
//11/10/25

#include <iostream>
#include "lista.h"
#include "stack.h"
using namespace std;

//Funcion insertar al final
void insertaFinal(Node** head, int val) {
    Node* nuevo = new Node;
    nuevo->data = val;
    nuevo->next = nullptr;

    if (*head == nullptr) {
        *head = nuevo;
        return;
    }

    Node* temp = *head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = nuevo;
}

//Funcion imprimir lista
void imprimir(Node* head){
    Node* temp= head;
    while (temp !=nullptr){
        cout<< temp-> data<<endl;
        temp= temp->next;
    }
}

//funcion que reversa una lista ligada
template <typename T>
void reverse(Nodo<T>* head, int size){
    Stack<T> pila;
    int MAX = size;
    Nodo<T> *h2;
    while(head-> next!=NULL){
        h2 = head->next;
        pila.push(head->data);
        head = h2->next;
        if(!pila.empty()){
            inserta_al_Final(&pila, pila.top());
            }
        }
};


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
void concat(Node** l1,  Node* l2){
    if (*l1==nullptr){
        *l1=l2;
        return;
    }
    Node* temp=*l1;
    while(temp->next !=nullptr)
        temp=temp->next;

    temp->next=l2;
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
    Nodo* rev1= reverse(&head1, m);
    Nodo* rev2= reverse(&head2, n);

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
