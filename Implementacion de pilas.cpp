#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
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

//Estructura del nodo a utilizar


int main(){

//Variables necesarias para gestionar el menu
bool menuShido = true;
int opcionMultiple;
string valPelicula;
string valGenerlo;
string valProductores;

do{

system("CLS");

cout << "Genero, Peliculas y Productores\n"<< endl;

cout <<"Opcion 1. Agregar elementos a las pilas."<< endl;
cout <<"Opcion 2. Modificar elementos en las pilas."<< endl;
cout <<"Opcion 3. Buscar elementos en las pilas."<< endl;
cout <<"Opcion 4. Eliminar elementos de las pilas."<< endl;
cout <<"Opcion 5. Listar los elementos en las listas."<< endl;
cout <<"Opcion 6. Salir.\n"<< endl;

cout <<"Ingrese una opcion: " << endl;
cin>>opcionMultiple;

switch (opcionMultiple){

    case 1:
        system("cls");
        cout<<"Opcion 1"<<endl;
        system("pause");
        break;

    case 2:
        system("cls");
        cout<<"Opcion 2"<<endl;
        system("pause");
        break;

    case 3:
        system("cls");
        cout<<"Opcion 3"<<endl;
        system("pause");
        break;

    case 4:
        system("cls");
        cout<<"Opcion 4"<<endl;
        system("pause");
        break;

    case 5:
        system("cls");
        cout<<"Opcion 5"<<endl;
        system("pause");
        break;

    case 6:
        system("CLS");
        menuShido = false;
        break;

    default:
        cout<<"Error: Ingrese una opcion correcta."<<endl;
        system("pause");
        break;
}
}while(menuShido == true);

return 0;
}


