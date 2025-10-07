//programa que trabaja con listas ligadas, contiene las funciones de reverse, equals y concatenar.
//A01739326 Belsy Aislinn Rueda Santiago, A01739755 Michelle Amanda Hernández Legaria, A01736333 María José Serrano Notario 
//11/10/25
//editar
#include <iostream>
#include 'lista.h'
using namespace std;




int main() {
    //iniciadores de las head de la listas
    Nodo<int>* head1 = nullptr;
    Nodo<int>* head2 = nullptr;

    cin >> m;
    cin >> n;

    for (int i = 0; i < m; i++) {
        int num_m;
        cin >> num_m;
        inserta_al_Inicio(&head1, num_m);
    }

    for (int i = 0; i < n; i++) {
        int num_n;
        cin >> num_n;
        inserta_al_Inicio(&head2, num_n);
    }

    int funciones;
    int num = 0;
    //menu
    do {
        cin >> funciones;
        switch (funciones) {
            case 1:
            //inserta al inicio
                cin >> num;
                inserta_al_Inicio(&head, num);
                break;
            case 2:
            //inserta al final
                cin >> num;
                inserta_al_Final(&head, num);
                break;
            case 3:
            //elimina al inicio
                elimina_al_Inicio(&head);
                break;
            case 4:
            //elimina al final
                elimina_al_Final(&head);
                break;
            case 5:
            //print
                imprime(head);
                break;
            case 0:
            //salida
                break;
            default:
                break;
        }
    } while (funciones != 0);

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
