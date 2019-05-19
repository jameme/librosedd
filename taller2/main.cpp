#include <iostream>
#include <stdlib.h>
using namespace std;
struct nodo{
       int dato;
       string nombre,autor;
       nodo *sig;};


class Libro{
private:int pag;
        string nombre;
        string autor;
public:Libro();
       Libro(int,string,string);
       void setpag(int);
       void setnombre(string);
       void setautor(string);
       int getpag();
       string getnombre();
       string getautor();             };
 Libro::Libro(){}
 Libro::Libro(int _pag,string _nom,string _aut){
  this->pag=_pag;
  this->nombre=_nom;
  this->autor=_aut;}
  void Libro::setpag(int _pag){
  this->pag=_pag;}
  void Libro::setnombre(string _nombre){
  this->nombre=_nombre;}
  void Libro::setautor(string _aut){
  this ->autor=_aut;}
  int Libro::getpag(){return pag;}
  string Libro::getnombre(){return nombre;}
  string Libro::getautor(){return autor;}



void insertarpila(nodo *&pila,int n,string nom,string aut)
 {   nodo *nuevonodo=new nodo();
     nuevonodo->dato=n;
     nuevonodo->nombre=nom;
     nuevonodo->autor=aut;
     nuevonodo->sig=pila;
     pila=nuevonodo;
     cout<<"los datos fueron agregados correctamente"<<endl;
 }
 void sacarpila(nodo *&pila,int &pag,string &nom,string &aut)
 { nodo *aux=pila;
   pag=aux->dato;
   nom=aux->nombre;
   aut=aux->autor;
 pila=aux->sig;
 delete aux;
 }



int main()
{   int pag,cont=0,i=0,aux;
    string nom,aut,aux1,aux2;
    char respuesta;
    nodo *pila=NULL;
    nodo *pilaordenada=NULL;
    int a[100];
    string b[100],c[100];

    do{cout << "Ingrese titulo del libro (sin espacios) :";cin>>nom;
    cout <<"Ingrese autor del libro (sin espacios): ";cin>>aut;
    cout <<"Ingrese cantidad de paginas "; cin>>pag;
    Libro l1(pag,nom,aut);
    insertarpila(pila,l1.getpag(),l1.getnombre(),l1.getautor());
    cont++;
    cout<<"---------------------------"<<endl;
    cout<<"¿Desea agregar otro libro? (s/n) "; cin>>respuesta; }
    while(respuesta=='s'||respuesta=='S' );
    while (pila!=NULL&&i<cont){
        sacarpila(pila,pag,nom,aut);
        a[i]=pag;
        b[i]=nom;                   //sacando la informacion de la pila y asignandoselo a los arreglos
        c[i]=aut;
         i++;
        }

        for(i=0;i<cont;i++)
            {for(int  x=0;x<cont;x++){
                if(a[i]<a[x]){
                   aux=a[i];
                   a[i]=a[x];
                    a[x]=aux;
                    aux1=b[i];        //Ordenando datos en los arreglos
                   b[i]=b[x];
                    b[x]=aux1;
                    aux2=c[i];
                   c[i]=c[x];
                    c[x]=aux2;


           }
        }}
        for(i=0;i<cont;i++)
           {insertarpila(pilaordenada,a[i],b[i],c[i]);}
        while(pilaordenada!=NULL){
        sacarpila(pilaordenada,pag,nom,aut);{
                cout<<"\n Libro:"<<nom;
                cout <<"\n Autor :"<<aut;                   //mostrar los nodos de la pila ordenada
                cout <<"\n Paginas :"<<pag;}
                }




  return 0;
}
