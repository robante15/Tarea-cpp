#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "concolor.h"

using namespace std;
//Lo de los colores lo saque de esta web: http://johny65corp.blogspot.com/2011/05/consola-con-colores-en-c.html

/*
Genero,Peliculas y Productores

Hacer un sistema que permita:
-Agregar
-Modificar
-Buscar
-Eliminar
-Listar
Elementos en 3 pilas.

Cada grupo debe de crear las 3 pilas y buscar la forma de relacionar las pilas.

La interfaz de usuario y las validaciones tienen un 40% de ponderación.
fecha de entrega Jueves 11.
*/

//Todo el codigo para trabajar con pelicula
struct nodoPelicula{
       string pelicula;
       struct nodoPelicula *sgte;
};

typedef struct nodoPelicula *Plista;

void insertarPelicula(Plista &lista1, string valor1)
{
    Plista t, p = new(struct nodoPelicula);

    p->pelicula= valor1;

    p->sgte = NULL;

    if(lista1==NULL)
    {
        lista1 = p;
    }
    else
    {
        t = lista1;
        while(t->sgte!=NULL)
        {
            t = t->sgte;
        }
        t->sgte = p;
    }
}

void reportarListaPelicula(Plista lista1)
{
     int i = 0;

     while(lista1 != NULL)
     {
          cout <<' '<< i+1 <<") ";
          cout << white << "Pelicula: " << normal <<lista1->pelicula << endl << endl;
          lista1 = lista1->sgte;
          i++;
     }
}

void buscarElementoPelicula(Plista lista1, string valor1)
{
    Plista p = lista1;
    int i = 1, band = 0;

    while(p!=NULL)
    {
        if(p->pelicula==valor1)
        {
            cout<<endl<<" Encontrada en posicion: "<< i <<endl;
            band = 1;
        }
        p = p->sgte;
        i++;
    }

    if(band==0)
        cout<<"\n\nError: Pelicula no encontrada."<< endl;
}


//Todo el codigo para trabajar con genero
struct nodoGenero{
       string genero;
       struct nodoGenero *sgte;
};

typedef struct nodoGenero *Glista;

void insertarGenero(Glista &lista2, string valor1)
{
    Glista t, g = new(struct nodoGenero);

    g->genero= valor1;

    g->sgte = NULL;

    if(lista2==NULL)
    {
        lista2 = g;
    }
    else
    {
        t = lista2;
        while(t->sgte!=NULL)
        {
            t = t->sgte;
        }
        t->sgte = g;
    }
}

void reportarListaGenero(Glista lista2)
{
     int i = 0;

     while(lista2 != NULL)
     {
          cout <<' '<< i+1 <<") ";
          cout << white << "Genero: " << normal <<lista2->genero << endl << endl;
          lista2 = lista2->sgte;
          i++;
     }
}

void buscarElementoGenero(Glista lista2, string valor1)
{
    Glista g = lista2;
    int i = 1, band = 0;

    while(g!=NULL)
    {
        if(g->genero==valor1)
        {
            cout<<endl<<" Encontrada en posicion "<< i <<endl;
            band = 1;
        }
        g = g->sgte;
        i++;
    }

    if(band==0)
        cout<<"\n\n Genero no encontrado..!"<< endl;
}

//Todo el codigo para trabajar con productor
struct nodoProductor{
       string productor;
       struct nodoProductor *sgte;
};

typedef struct nodoProductor *Prolista;

void insertarProductor(Prolista &lista3, string valor1)
{
    Prolista t, pro = new(struct nodoProductor);

    pro->productor= valor1;

    pro->sgte = NULL;

    if(lista3==NULL)
    {
        lista3 = pro;
    }
    else
    {
        t = lista3;
        while(t->sgte!=NULL)
        {
            t = t->sgte;
        }
        t->sgte = pro;
    }
}

void reportarListaProductor(Prolista lista3)
{
     int i = 0;

     while(lista3 != NULL)
     {
          cout <<' '<< i+1 <<") ";
          cout << white << "Productor: " << normal <<lista3->productor << endl << endl;
          lista3 = lista3->sgte;
          i++;
     }
}

void buscarElementoProductor(Prolista lista3, string valor1)
{
    Prolista pro = lista3;
    int i = 1, band = 0;

    while(pro!=NULL)
    {
        if(pro->productor==valor1)
        {
            cout<<endl<<" Encontrada en posicion "<< i <<endl;
            band = 1;
        }
        pro = pro->sgte;
        i++;
    }

    if(band==0)
        cout<<"\n\n Productor no encontrado..!"<< endl;
}

int main(){

//Variables necesarias para gestionar el menu
bool menuShido = true;
char opcionMultiple;
string valPelicula;
string valGenero;
string valProductores;

Glista lista2 = NULL; //Glista -> Lista de los generos
Plista lista1 = NULL; //Plista -> Lista de las peliculas
Prolista lista3 = NULL; //Prolista -> Lista de los productores

do{

system("CLS");

cout << white << "------------------------------------------" << endl;
cout << white << "|         Listas enlazadas simples       |"<< endl;
cout << white << "|                                        |"<< endl;
cout << white << "|    Genero, Peliculas y Productores     |"<< endl;
cout << white << "------------------------------------------\n" << endl;


cout << white <<"Opcion 1. " << normal <<"Agregar elementos a las pilas."<< endl;
cout << white <<"Opcion 2. " << normal <<"Modificar elementos en las pilas."<< endl;
cout << white <<"Opcion 3. " << normal <<"Buscar elementos en las pilas."<< endl;
cout << white <<"Opcion 4. " << normal <<"Eliminar elementos de las pilas."<< endl;
cout << white <<"Opcion 5. " << normal <<"Listar los elementos en las listas."<< endl;
cout << white <<"Opcion 6. " << normal <<"Salir.\n"<< endl;

cout << white <<"Ingrese una opcion: " << normal;

opcionMultiple = getch();

switch (opcionMultiple){

    case '1':
        system("cls");

        cout<< "\n Pelicula: ";
        getline(cin,valPelicula);
        insertarPelicula(lista1, valPelicula);


        cout<< "\n Genero: ";
        getline(cin,valGenero);
        insertarGenero(lista2, valGenero);

        cout<< "\n Productor: ";
        cin >> valProductores;
        insertarProductor(lista3, valProductores);

        system("pause");
        break;

    case '2':
        system("cls");
        system("pause");
        break;

    case '3':
        system("cls");
        cout<<"\n Valor a buscar: "; cin>> valGenero;
        buscarElementoGenero(lista2, valGenero);
        system("pause");
        break;

    case '4':
        system("cls");
        cout<<"Opcion 4"<<endl;
        system("pause");
        break;

    case '5':
        system("cls");
        cout << "\n\nMostrando la Informacion\n\n";
        reportarListaPelicula(lista1);
        reportarListaGenero(lista2);
        reportarListaProductor(lista3);
        system("pause");
        break;

    case '6':
        system("CLS");
        menuShido = false;
        break;

    default:
    	system("cls");
        cout<<"Error: Ingrese una opcion correcta."<<endl;
        system("pause");
        break;
}
}while(menuShido == true);

return 0;
}


