// programa que lee bitacora.txt, almacena los datos en una lista doblemente ligada, 
// ordena por ip o mes o mensaje y despliega los datos en el rango pedido por el usuario,
// devuelve un sorted.txt con los datos ordenados.
// A01739326 Belsy Aislinn Rueda Santiago, A01739755 Michelle Amanda Hernández Legaria, A01736333 María José Serrano Notario
// 15/10/25

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include "double_LL.h"
#include "mergeSortDLL.h"
using namespace std;

/* traduce los meses del año a número (O(1)) */
static map<string,int> MES;
static void initMes(){
    MES["Jan"]=1; MES["Feb"]=2; MES["Mar"]=3; MES["Apr"]=4;
    MES["May"]=5; MES["Jun"]=6; MES["Jul"]=7; MES["Aug"]=8;
    MES["Sep"]=9; MES["Oct"]=10; MES["Nov"]=11; MES["Dec"]=12;
}

/* estructura que guarda los datos de cada línea (O(1)) */
struct Entrada{
    string mes; int dia; string hora;      
    int ip1, ip2, ip3, ip4, ipPort;        
    string mensaje;
};

/* traduce la ip en una sola clave numérica (O(1)) */
static inline unsigned int ipKey(int a,int b,int c,int d){
    return ( (static_cast<unsigned int>(a)<<24) |
             (static_cast<unsigned int>(b)<<16) |
             (static_cast<unsigned int>(c)<< 8) |
             (static_cast<unsigned int>(d)) );
}

/* traduce una ip tipo "a.b.c.d" en clave (O(1)) */
static bool parseIpToKey(const string& s, unsigned int& key){
    int a,b,c,d; char p1='.',p2='.',p3='.';
    stringstream ss(s);
    if(!(ss>>a>>p1>>b>>p2>>c>>p3>>d)) return false;
    if(p1!='.'||p2!='.'||p3!='.')     return false;
    if(a<0||a>255||b<0||b>255||c<0||c>255||d<0||d>255) return false;
    key = ipKey(a,b,c,d);
    return true;
}

/* compara dos entradas (O(1)) */
// compara primero las IP, luego el mes, día, hora y mensaje
static bool cmpEntrada(const Entrada& e1, const Entrada& e2){
    if(e1.ip1!=e2.ip1) return e1.ip1<e2.ip1;
    if(e1.ip2!=e2.ip2) return e1.ip2<e2.ip2;
    if(e1.ip3!=e2.ip3) return e1.ip3<e2.ip3;
    if(e1.ip4!=e2.ip4) return e1.ip4<e2.ip4;

    int m1 = MES[e1.mes], m2 = MES[e2.mes];
    if(m1!=m2)          return m1<m2;
    if(e1.dia!=e2.dia)  return e1.dia<e2.dia;
    if(e1.hora!=e2.hora) return e1.hora<e2.hora; 
    return e1.mensaje < e2.mensaje;
}

int main(){
    initMes();

    Nodo<Entrada>* head = NULL; // cabeza de la lista doble

    ifstream in("bitacora.txt");
    if(!in.is_open()){
        cerr<<"No se pudo abrir bitacora.txt\n";
        return 1;
    }

    /* lee línea por línea del archivo y guarda en la lista (O(n)) */
    string linea;
    while(getline(in,linea)){
        if(linea.empty()) continue;

        stringstream ss(linea);
        Entrada e; string ipFull;

        // traduce la línea en partes: mes, día, hora e ip
        if(!(ss >> e.mes >> e.dia >> e.hora >> ipFull)) continue;

        // guarda el resto de la línea como mensaje
        getline(ss, e.mensaje);
        if(!e.mensaje.empty() && e.mensaje[0]==' ') e.mensaje.erase(0,1);

        // separa ip en 4 partes y el puerto
        char d1='.',d2='.',d3='.',col=':';
        stringstream ips(ipFull);
        if(!(ips>>e.ip1>>d1>>e.ip2>>d2>>e.ip3>>d3>>e.ip4>>col>>e.ipPort)) continue;

        // si el mes no existe lo ignora
        if(MES.find(e.mes)==MES.end()) continue; 

        // guarda cada entrada al final de la lista doble (O(n))
        inserta_al_Final(&head, e);
    }
    in.close();

    // si no hay datos, crea archivo vacío y termina
    if(!head){
        ofstream("SortedData.txt").close();
        return 0;
    }

    /* ordena toda la lista con merge sort (O(n log n)) */
    mergeSortDLL(&head, cmpEntrada);

    /* recorre e imprime todo en archivo ascendente (O(n)) */
    ofstream out("SortedData.txt");
    for(Nodo<Entrada>* t=head; t; t=t->getNext()){
        const Entrada& r=t->getDato();
        out<<r.mes<<" "<<setw(2)<<setfill('0')<<r.dia<<" "<<r.hora<<" "
           <<r.ip1<<"."<<r.ip2<<"."<<r.ip3<<"."<<r.ip4<<":"<<r.ipPort
           <<" "<<r.mensaje<<"\n";
    }
    out.close();

    /* pide ip inicial y final del rango (O(1)) */
    string ipInicio, ipFin;
    if(!(cin>>ipInicio)) return 0;
    if(!(cin>>ipFin))    return 0;

    // traduce ambas ip a clave numérica
    unsigned int kIni=0, kFin=0;
    if(!parseIpToKey(ipInicio,kIni) || !parseIpToKey(ipFin,kFin)){
        cout<<"(formato de IP inválido)\n";
        return 0;
    }
    if(kIni>kFin){ unsigned int tmp=kIni; kIni=kFin; kFin=tmp; }

    /* recorre hasta el final para imprimir en orden descendente (O(n)) */
    Nodo<Entrada>* tail=head;
    while(tail && tail->getNext()) tail=tail->getNext();

    bool alguno=false;
    while(tail){
        const Entrada& r=tail->getDato();
        unsigned int k = ipKey(r.ip1,r.ip2,r.ip3,r.ip4);

        // compara si la ip está dentro del rango
        if(k>=kIni && k<=kFin){
            cout<<r.mes<<" "<<setw(2)<<setfill('0')<<r.dia<<" "<<r.hora<<" "
                <<r.ip1<<"."<<r.ip2<<"."<<r.ip3<<"."<<r.ip4<<":"<<r.ipPort
                <<" "<<r.mensaje<<"\n";
            alguno=true;
        }
        tail=tail->getPrev(); // recorre hacia atrás
    }

    if(!alguno) cout<<"(sin coincidencias en ese rango)\n";
    return 0;
}

