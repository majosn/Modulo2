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
    int MAX=100;
    T datos[MAX];
    T tope;
public:

    Stack( ){
        top = -1;
    //para un stack vacio
}
    void push(T valor){
        top++;
        datos[top] = valor;
//push agrega un nuevo elemento; agrega al arreglo el elemento y actualiza el top
    };

    T top(){
        return datos[top];
    // regresa el contador de datos agragados al stack
    }

    T pop(){
        top--;
        return datos[top+1];
    //quita un elemento del stack;
    };

    bool isEmpty( ){
        return (top == -1);
    };
//revisa si esta vacio

    bool isFull( ){
        return (top == MAX-1);
    }
};
//revisa si esta lleno

#endif //STACK_H
