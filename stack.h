//programa que implementa la clase stack
//A01739326 Belsy Aislinn Rueda Santiago, A01739755 Michelle Amanda Hernández Legaria, A01736333 María José Serrano Notario
//11/10/25

#ifndef STACK_H
#define STACK_H
using namespace std;
#include <iostream>


template <typename T>
class Stack{
private:
    const static int MAX = 100;
    T datos[MAX];
    T tope;
public:

    Stack( ){
        tope = -1;
        //para un stack vacio
    }
    void push(T valor){
        tope++;
        datos[tope] = valor;
        //push agrega un nuevo elemento; agrega al arreglo el elemento y actualiza el top
    };

    T top(){
        return datos[tope];
        // regresa el contador de datos agragados al stack
    }

    T pop(){
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
