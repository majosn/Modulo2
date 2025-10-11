//programa que implementa la clase stack
//A01739326 Belsy Aislinn Rueda Santiago, A01739755 Michelle Amanda Hernández Legaria, A01736333 María José Serrano Notario
//11/10/25

#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;


template <typename T>
class Stack{
private:
    static const int MAX = 100;
    T datos[MAX];
    int tope;
public:

    Stack( ){
        tope = -1;
        //para un stack vacio
    }
    void push(T valor){
        if (isFull()){
        cout << "ERROR: stack lleno" << endl;
        return;
    }
        tope++;
        datos[tope] = valor;
        //push agrega un nuevo elemento; agrega al arreglo el elemento y actualiza el top
    };

    T top(){
        // Evita acceder a pila vacía
        if (isEmpty()){
            return T(); // regresa valor por defecto
        }
        return datos[tope];
        // regresa el contador de datos agragados al stack
    }

    T pop(){
        // Evita underflow
        if (isEmpty()){
            return T(); // evita basura
        }
        tope--;
        return datos[tope+1];
        //quita un elemento del stack;
    };

    bool isEmpty( ){
        return (tope == -1);
    };
    //revisa si esta vacio

    bool isFull( ){
        return (tope == MAX-1);
    }
};
//revisa si esta lleno
#endif //STACK_H
