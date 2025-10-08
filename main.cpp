//programa que trabaja con listas ligadas, contiene las funciones de reverse, equals y concatenar.
//A01739326 Belsy Aislinn Rueda Santiago, A01739755 Michelle Amanda Hernández Legaria, A01736333 María José Serrano Notario 
//11/10/25

#include <iostream>
#include 'lista.h'
#include 'stack.h'
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
void reverse(){
    stack<T> pila;
    Nodo<T> *h;

};

//equal
    
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
    Node* list1= nullptr;
    Node* list2= nullptr;

    int m, n, val;

    //Entradad de la lista 1
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>val;
        insertaFinal (&list1, val);
    };

    //Entrada de lista 2
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>val;
        insertaFinal (&list2, val);
    };

    
    //Invertir listas
    Node* rev1= reverse(&list1);
    Node* rev2= reverse(&list2);

    imprimir(rev1);
    imprimir(rev2);
    
    
    //Concat reverse list1+ revers list2

    Node* copyRev1= rev1;
    Node* copyRev2=rev2;

    concat(&copyRev2,copyRev1);
    imprimir (copyRev2);

    /*
    //verificar si las listas son iguales
    cout<<(equals(rev1,rev2) ? "true":"false")<<endl,
    */

    return 0;
}


    //para la memoria (liberacion)
    Nodo<int>* actual = head;
    while (actual != nullptr) {
       Nodo<int>* tmp = actual;
        actual = actual->getNext();
        delete tmp;
    }
    head = nullptr;
    return 0;

}
