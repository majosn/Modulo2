//programa que lee bitacora.txt, al,acena los datos en una lista doblemente ligada, ordena por ip o mes o mensaje y despliega los datos en el rango pedido por el usuario,
//devuelve un sorted.txt con los datos ordenados.
//A01739326 Belsy Aislinn Rueda Santiago, A01739755 Michelle Amanda Hernández Legaria, A01736333 María José Serrano Notario
//15/10/25

#include <iostream>
#include <iomanip>
#include <string>
#include <map>

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





int main() {


}

