//programa que trabaja con listas ligadas, contiene las funciones de reverse, equals y concatenar.
//A01739326 Belsy Aislinn Rueda Santiago, A01739755 Michelle Amanda Hernández Legaria, A01736333 María José Serrano Notario 
//11/10/25

#include <iostream>
#include 'lista.h'
#include 'stack.h'
using namespace std;

//funcion que reversa una lista ligada
template <typename T>
void reverse(){
    stack<T> pila;
    Nodo<T> *h;




};



int main() {

    //iniciadores de las head de la listas
    Nodo<int>* head1 = nullptr;
    Nodo<int>* head2 = nullptr;

    cin >> m;
//ciclo para llenar las listas
    for (int i = 0; i < m; i++) {
        int num_m = 0;
        cin >> num_m;
        inserta_al_Inicio(&head1, num_m);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num_n = 0;
        cin >> num_n;
        inserta_al_Inicio(&head2, num_n);
    }

//reverse

//equal
    
//concat


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
