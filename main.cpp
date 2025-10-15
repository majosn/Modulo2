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

// Función comparadora para el Merge Sort
bool cmpEntrada(const Entrada &e1, const Entrada &e2) {
    if (e1.ip1 != e2.ip1) return e1.ip1 < e2.ip1;
    if (e1.ip2 != e2.ip2) return e1.ip2 < e2.ip2;
    if (e1.ip3 != e2.ip3) return e1.ip3 < e2.ip3;
    if (e1.ip4 != e2.ip4) return e1.ip4 < e2.ip4;

    // Si las IP son iguales, compara por mes
    if (e1.mes != e2.mes) return e1.mes < e2.mes;

    // Si el mes es igual, compara por día
    if (e1.dia != e2.dia) return e1.dia < e2.dia;

    // Si el día también es igual, compara por mensaje
    return e1.mensaje < e2.mensaje;
}



int main() {
    Nodo<Entrada>* head = nullptr;
    Entrada entrada;
    string linea;

    ifstream txt("bitacora.txt");
    if (!txt.is_open()) return 1;

    while (getline(txt, linea)) {
        stringstream ss(linea);
        string ipCompleta;

        ss >> entrada.mes >> entrada.dia >> entrada.hora >> ipCompleta;
        getline(ss, entrada.mensaje);
        if (!entrada.mensaje.empty() && entrada.mensaje[0] == ' ') entrada.mensaje.erase(0,1);

        // Separar IP y puerto
        char dot, colon;
        stringstream ipStream(ipCompleta);
        ipStream >> entrada.ip1 >> dot >> entrada.ip2 >> dot >> entrada.ip3 >> dot >> entrada.ip4 >> colon >> entrada.ipPort;

        // Insertar en lista
        inserta_al_Final(&head, entrada);
    }
    txt.close();

    // Ordenar lista ascendente
    mergeSortDLL(&head, cmpEntrada);

    // Guardar archivo sorted.txt
    ofstream sal("sorted.txt");
    Nodo<Entrada>* temp = head;
    while (temp) {
        Entrada e = temp->getDato();
        sal << e.mes << " " << setw(2) << setfill('0') << e.dia << " "
            << e.hora << " "
            << e.ip1 << "." << e.ip2 << "." << e.ip3 << "." << e.ip4 << ":"
            << e.ipPort << " " << e.mensaje << endl;
        temp = temp->getNext();
    }
    sal.close();

    // Leer IP inicial y final directamente
    string ipInicio, ipFin;
    cin >> ipInicio;
    cin >> ipFin;

    // Mostrar registros dentro del rango en orden descendente
    Nodo<Entrada>* tail = head;
    while (tail && tail->getNext()) tail = tail->getNext();

    while (tail) {
        Entrada e = tail->getDato();
        string ipStr = to_string(e.ip1) + "." + to_string(e.ip2) + "." + to_string(e.ip3) + "." + to_string(e.ip4);
        if (ipStr >= ipInicio && ipStr <= ipFin) {
            cout << e.mes << " " << setw(2) << setfill('0') << e.dia << " "
                 << e.hora << " "
                 << ipStr << ":" << e.ipPort << " " << e.mensaje << endl;
        }
        tail = tail->getPrev();
    }

    return 0;
}

