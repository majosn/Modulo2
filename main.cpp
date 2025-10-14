//programa que lee bitacora.txt, al,acena los datos en una lista doblemente ligada, ordena por ip o mes o mensaje y despliega los datos en el rango pedido por el usuario,
//devuelve un sorted.txt con los datos ordenados.
//A01739326 Belsy Aislinn Rueda Santiago, A01739755 Michelle Amanda Hernández Legaria, A01736333 María José Serrano Notario
//15/10/25

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <fstream>
#include <vector>

#include "mergeSortDLL.h"
#include "double_LL.h"

using::std::ifstream;
using std::getline;
using std::stringstream;

using namespace std;

map<string,int> meses = {
    {"Jan", 1},
    {"Feb", 2},
    {"Mar", 3},
    {"Apr", 4},
    {"May", 5},
    {"Jun", 6},
    {"Jul", 7},
    {"Aug", 8},
    {"Sep", 9},
    {"Oct", 10},
    {"Nov", 11},
    {"Dec", 12},
};

// Estructura que representa una entrada de la bitácora
struct Entrada{
    string mes;
    int dia;
    string hora;
    int ip1;
    int ip2;
    int ip3;
    int ip4;
    int ipPort;
    string mensaje;
};

bool condiciones(Entrada &e1, Entrada &e2){
    if (e1.ip1 != e2.ip1) return e1.ip1 < e2.ip1;
    if (e1.ip2 != e2.ip2) return e1.ip2 < e2.ip2;
    if (e1.ip3 != e2.ip3) return e1.ip3 < e2.ip3;
    if (e1.ip4 != e2.ip4) return e1.ip4 < e2.ip4;


    // si las ips son iguales, compara por mes
    if (e1.mes != e2.mes) return e1.mes < e2.mes;

    // si el mes es igual, compara por día
    if (e1.dia != e2.dia) return e1.dia < e2.dia;

    // si el día es igual, compara por mensaje
    return e1.mensaje < e2.mensaje;

}


template<typename T>
int main() {

    Nodo<T>* head = nullptr;
    Entrada entrada;
    char sp;

    ifstream txt("bitacora.txt");
    string linea;
    while (getline(txt,linea,'\n')) {
        ifstream doc("bitacora.txt");
        while(getline(doc,linea)){
            stringstream ss(linea);

            ss  >> entrada.mes >>entrada.dia >> entrada.hora
                >> entrada.ip1 >> sp >> entrada.ip2 >> sp
                >> entrada.ip3 >> sp >> entrada.ip4 >> sp
                >> entrada.ipPort;
            getline(ss, entrada.mensaje);

            inserta_al_Final(head&,entrada);
        }
    }

    //llamada a ordena

    ofstream sal("sorted.txt");

    //editar no esta listo
    for(auto e://lista ){
        sal << e.mes << " " << setfill('0') << setw(2) << e.dia << " "
            << e.hora << " "
            << e.ip1 << "." << e.ip2 << "."
            << e.ip3 << "." << e.ip4 << ":"
            << e.ipPort << e.mensaje << endl;
    }

    //input del rango de incidentes a buscar

    int mes1 = 1, mes2 = 1, dia1 = 1, dia2 = 1;

    cin >> mes1 >> dia1 >> mes2 >> dia2;



}

