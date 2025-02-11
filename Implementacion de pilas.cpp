#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "concolor.h"

using namespace std;
//Lo de los colores lo saque de esta web: http://johny65corp.blogspot.com/2011/05/consola-con-colores-en-c.html

/*
Genero,Peliculas y Productores.

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

//Variables globales
int idgeneroG = 1;
int idproductorG = 1;
//Todo el codigo para trabajar con pelicula
struct nodoPelicula{
       string pelicula;
       string genero;
       string productor;
       struct nodoPelicula *sgte;
};

typedef struct nodoPelicula *Plista;

void bannerInsertar(){
                            //system("cls");
cout << white << "      ------------------------------------------" << endl;
cout << white << "      |                                        |"<< endl;
cout << white << "      |      Ingresando nuevos elementos       |"<< endl;
cout << white << "      |                                        |"<< endl;
cout << white << "      ------------------------------------------\n" << endl;
}

void bannerEliminar(){
            //system("cls");
cout << white << "      ------------------------------------------" << endl;
cout << white << "      |                                        |"<< endl;
cout << white << "      |           Eliminar elementos           |"<< endl;
cout << white << "      |                                        |"<< endl;
cout << white << "      ------------------------------------------\n" << endl;
}
void bannerListar(){
cout << white << "      ------------------------------------------" << endl;
cout << white << "      |                                        |"<< endl;
cout << white << "      |            Listar elementos            |"<< endl;
cout << white << "      |                                        |"<< endl;
cout << white << "      ------------------------------------------\n" << endl;
}

void bannerBuscar(){
cout << white << "      ------------------------------------------" << endl;
cout << white << "      |                                        |"<< endl;
cout << white << "      |          Busqueda de Pelicula          |"<< endl;
cout << white << "      |                                        |"<< endl;
cout << white << "      ------------------------------------------\n" << endl;
}

void insertarPelicula(Plista &lista1, string valor1, string valor2, string valor3)
{
    Plista t, p = new(struct nodoPelicula);

    p->pelicula= valor1;
	p->genero= valor2;
	p->productor = valor3;
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
          cout << white << "Genero: " << normal <<lista1->genero << endl << endl;
          cout << white << "Productor: " << normal <<lista1->productor << endl << endl;
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
        system("CLS");
        bannerBuscar();
        cout<< red <<"Error: Pelicula no encontrada." << normal << endl;
}

void eliminarElementoPelicula(Plista &lista1, string valor1)
{
    Plista p, ant;
    p = lista1;

    if(lista1!=NULL)
    {
        while(p!=NULL)
        {
            if(p->pelicula==valor1)
            {
                if(p==lista1)
                    lista1 = lista1->sgte;
                else
                    ant->sgte = p->sgte;

                delete(p);
                return;
            }
            ant = p;
            p = p->sgte;
        }
    }
    else
        cout<< red <<"Error: Lista vacia." << normal << endl;
}

//Todo el codigo para trabajar con genero
struct nodoGenero{
       string genero;
       int id;
       struct nodoGenero *sgte;
};

typedef struct nodoGenero *Glista;

string relaciongenero(Glista &lista2, int opc){
	Glista g = lista2;
    int i = 1, band = 0;

    while(g!=NULL)
    {
        if(g->id==opc)
        {
           return g->genero;
        }
        g = g->sgte;
        i++;
    }

    if(band==0)
        cout<< red <<"Error: Genero no encontrado." << normal << endl;
}

void insertarGenero(Glista &lista2, string valor1,int valor2)
{
    Glista t, g = new(struct nodoGenero);

    g->genero= valor1;
	g->id = valor2;
    g->sgte = NULL;
	idgeneroG++;
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
	bool vacio = true;
     while(lista2 != NULL)
     {
          cout <<' '<< i+1 <<") ";
          cout << white << "Genero: " << normal <<lista2->genero << endl << endl;
          lista2 = lista2->sgte;
          i++;
          vacio = false;
     }

    if(vacio)
    cout<< red << "Error: La lista esta vacia" << normal  << endl;

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
        cout<< red <<"Error: Genero no encontrado" << normal << endl;
}

void eliminarElementoGenero(Glista &lista2, string valor1)
{
    Glista g, ant;
    g = lista2;

    if(lista2!=NULL)
    {
        while(g!=NULL)
        {
            if(g->genero==valor1)
            {
                if(g==lista2)
                    lista2 = lista2->sgte;
                else
                    ant->sgte = g->sgte;

                delete(g);
                return;
            }
            ant = g;
            g = g->sgte;
        }
        idgeneroG--;
    }
    else
        cout << red <<"Error: Lista de generos vacia." << normal << endl;
}

//Todo el codigo para trabajar con productor
struct nodoProductor{
       string productor;
       int id;
       struct nodoProductor *sgte;
};

typedef struct nodoProductor *Prolista;

string relacionproductor(Prolista &lista3, int opc){
	Prolista g = lista3;
    int i = 1, band = 0;

    while(g!=NULL)
    {
        if(g->id==opc)
        {
           return g->productor;
        }
        g = g->sgte;
        i++;
    }

    if(band==0)
        cout<< red <<"Error: Productor no encontrado." << normal << endl;
}

void insertarProductor(Prolista &lista3, string valor1, int valor2)
{
    Prolista t, pro = new(struct nodoProductor);

    pro->productor= valor1;
	pro->id = valor2;
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
    idproductorG++;
}

void reportarListaProductor(Prolista lista3)
{
     int i = 0;
		bool vacio =  true;
     while(lista3 != NULL)
     {
          cout <<' '<< i+1 <<") ";
          cout << white << "Productor: " << normal <<lista3->productor << endl << endl;
          lista3 = lista3->sgte;
          i++;
          vacio = false;
     }

     if(vacio)
    cout << red << "Error: La lista esta vacia" << normal  << endl;

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
        cout<< red <<"Error: Productor no encontrado." << normal << endl;
}

void eliminarElementoProductores(Prolista &lista3, string valor1)
{
    Prolista pro, ant;
    pro = lista3;

    if(lista3!=NULL)
    {
        while(pro!=NULL)
        {
            if(pro->productor==valor1)
            {
                if(pro==lista3)
                    lista3 = lista3->sgte;
                else
                    ant->sgte = pro->sgte;

                delete(pro);
                return;
            }
            ant = pro;
            pro = pro->sgte;
        }
        idproductorG--;
    }
    else
        cout<< red <<"Error: Lista de productores vacia" << normal  << endl;
}

int main(){

//Variables necesarias para gestionar el menu
bool menuShido = true;
char opcionMultiple;
char OPTemporal;
bool submenu = true;
string valPelicula;
string valGenero;
string valProductores;
int optgenero;
int optproductor;
char optcgenero;
char optcproductor;

Glista lista2 = NULL; //Glista -> Lista de los generos
Plista lista1 = NULL; //Plista -> Lista de las peliculas
Prolista lista3 = NULL; //Prolista -> Lista de los productores

//Checkpoint para cargar partidas guardadas :v xdxdxdxdxxxdxdxd
menu:

do{

system("CLS");

cout << white << "          ------------------------------------------" << endl;
cout << white << "          |                  Listas                |"<< endl;
cout << white << "          |                                        |"<< endl;
cout << white << "          |    Genero, Peliculas y Productores     |"<< endl;
cout << white << "          ------------------------------------------\n" << endl;


cout << white << " -------------------------------------------------------------" << endl;
cout << white <<" |        1. " << normal <<"Agregar." << white << "          |"  <<"          4. " << normal <<"Eliminar."<< white <<"       |"<< endl;
cout << white <<" |        2. " << normal <<"Modificar."<< white << "        |" <<"          5. " << normal <<"Mostrar."<< white <<"        |"<< endl;
cout << white <<" |        3. " << normal <<"Buscar." << white << "           |" <<"          6. " << normal <<"Salir." << white <<"          |"<< endl;
cout << white << " -------------------------------------------------------------\n" << endl;


cout << white <<"Ingrese una opcion: " << normal;

opcionMultiple = getch();

switch (opcionMultiple){

//CASE 1: AGREGAR ELEMENTOS
    case '1':

        do{
            system("cls");
            bannerInsertar();

            cout << white <<"Opcion 1. " << normal <<"Agregar Pelicula."<< endl;
            cout << white <<"Opcion 2. " << normal <<"Agregar Genero."<< endl;
            cout << white <<"Opcion 3. " << normal <<"Agregar Productor."<< endl;
            cout << white <<"Opcion 4. " << normal <<"Retroceder."<< endl;
            OPTemporal = getch();
            system("cls");
                    switch (OPTemporal){
                        case '1':
                            bannerInsertar();

                            cout<<white<< "\n Pelicula: "<<normal;
                            getline(cin,valPelicula);
                            genero:
							system("cls");

							bannerInsertar();


                            reportarListaGenero(lista2);
                            cout << "\nEl genero esta en la lista? S/N" << endl;
                            optcgenero = getch();
                            //VALICADION PARA NO METERLE INCORRECTOS
                            if(optcgenero == 'S' ||optcgenero == 's' ||optcgenero == 'N' ||optcgenero == 'n'){
                                system("cls");
                            bannerInsertar();

                            switch(optcgenero){
                            	case 's':
                            	case 'S':
                            		reportarListaGenero(lista2);
                            		cout << "\nEscriba el numero que le corresponda: ";
                            		cin>>optgenero;
                            		valGenero = relaciongenero(lista2,optgenero);
                            		break;
                            	case 'n':
                            	case 'N':
                            		cout<< "\n Genero: ";
                            		getline(cin,valGenero);
                            		insertarGenero(lista2, valGenero,idgeneroG);
                            		goto genero;
                            		break;
							}
							}

                            else{

                                system("cls");
                                cout << red << "Error: Opcion seleccionada incorrecta\n" << normal <<endl;
                                system("pause");
                                goto genero;
                            }

							productor:
                            system("cls");
                            bannerInsertar();

                            reportarListaProductor(lista3);
                            cout << "\n El productor esta en la lista? S/N" << endl;

                            optcproductor = getch();
                            if(optcproductor == 'S' ||optcproductor == 's' ||optcproductor == 'N' ||optcproductor == 'n'){
                            system("cls");
                            bannerInsertar();

                            switch(optcproductor){
                            	case 's':
                            	case 'S':
                            		reportarListaProductor(lista3);
                            		cout << "\n Escriba el numero que le corresponda: ";
                            		cin>>optproductor;
                            		valProductores = relacionproductor(lista3,optproductor);
                            		break;
                            	case 'n':
                            	case 'N':
                            		cout<< "\n Productor: ";
                            		//getline(cin,valProductores);
                            		cin >> valProductores;
                            		insertarProductor(lista3, valProductores,idproductorG);
                            		goto productor;
                            		break;
							}
							       insertarPelicula(lista1,valPelicula,valGenero,valProductores);
                            }

                            else{
                               system("cls");
                                cout << red << "Error: Opcion seleccionada incorrecta\n" << normal <<endl;
                                system("pause");
                                goto productor;
                            }
                            break;

                        case '2':
                            bannerInsertar();
                            cout<< "\n Genero: ";
                            getline(cin,valGenero);
                            insertarGenero(lista2, valGenero,idgeneroG);
                            submenu = false;
                            break;

                        case '3':
                            bannerInsertar();
                            cout<< "\n Productor: ";
                            cin >> valProductores;
                            insertarProductor(lista3, valProductores, idproductorG);
                            submenu = false;
                            break;

                        case '4':
                            goto menu;
                    };

        }while(submenu = true);
        break;

        /*
        cout<< "\n Pelicula: ";
        getline(cin,valPelicula);
        insertarPelicula(lista1, valPelicula);
        */

//CASE 2: MODIFICAR ELEMENTOS
    case '2':
        system("cls");
            cout << white << "      ------------------------------------------" << endl;
            cout << white << "      |                                        |"<< endl;
            cout << white << "      |    Modificando elementos existentes    |"<< endl;
            cout << white << "      |                                        |"<< endl;
            cout << white << "      ------------------------------------------\n" << endl;
            cout << red << "WORK IN PROGRESS" << normal << endl;
            system("Pause");
            goto menu;
        //cout<<"\n Genero a modificar: "; cin>> valGenero;
        //modificarElementoGenero(lista2, valGenero);
        system("pause");
        break;

//CASE 3: BUSCAR PELICULA
    case '3':
        system("cls");
        bannerBuscar();
        cout<< white <<"Pelicula a buscar: " << normal;
        cin>> valPelicula;
        buscarElementoPelicula(lista1, valPelicula);
        system("pause");
        break;

//CASE 4: ELIMINAR ELEMENTOS
    case '4':
        do{
            system("cls");
            bannerEliminar();
            cout << white <<"Opcion 1. " << normal <<"Eliminar Pelicula."<< endl;
            cout << white <<"Opcion 2. " << normal <<"Eliminar Genero."<< endl;
            cout << white <<"Opcion 3. " << normal <<"Eliminar Productor."<< endl;
            cout << white <<"Opcion 4. " << normal <<"Retroceder."<< endl;
            OPTemporal = getch();
            system("cls");
                    switch (OPTemporal){
                        case '1':
                            bannerEliminar();
                            cout<< white << "Pelicula: " << normal;
                            getline(cin,valPelicula);
                            eliminarElementoPelicula(lista1, valPelicula);
                            break;

                        case '2':
                            bannerEliminar();
                            cout<< white <<"Genero: " << normal;
                            getline(cin,valGenero);
                            eliminarElementoGenero(lista2, valGenero);
                            break;

                        case '3':
                            bannerEliminar();
                            cout<< white << "Productor: " << normal;
                            getline(cin,valProductores);
                            eliminarElementoProductores(lista3, valProductores);
                            submenu = false;
                            break;

                        case '4':
                            goto menu;
                    };

        }while(submenu = true);
        break;

//CASE 5: LISTAR ELEMENTOS
    case '5':
        system("cls");
        do{
            system("cls");
            bannerListar();
            cout << white <<"Opcion 1. " << normal <<"Mostrar Peliculas."<< endl;
            cout << white <<"Opcion 2. " << normal <<"Mostrar Generos."<< endl;
            cout << white <<"Opcion 3. " << normal <<"Mostrar Productores."<< endl;
            cout << white <<"Opcion 4. " << normal <<"Retroceder."<< endl;
            OPTemporal = getch();
            system("cls");
                    switch (OPTemporal){
                        case '1':
                            system("cls");
                            bannerListar();
                            cout << white << "Mostrando las Peliculas"<< normal <<endl;
                            reportarListaPelicula(lista1);
                            system("pause");
                            break;

                        case '2':
                            system("cls");
                            bannerListar();
                            cout << white << "Mostrando los Generos" << normal << endl;
                            reportarListaGenero(lista2);
                            system("pause");
                            break;

                        case '3':
                            system("cls");
                            bannerListar();
                            cout << white << "Mostrando la Informacion"<< normal << endl;
                            reportarListaProductor(lista3);
                            system("pause");
                            break;

                        case '4':
                            goto menu;
                            break;
                    };

        }while(submenu = true);
        break;

    case '6':
        system("CLS");
        menuShido = false;
        break;

    default:
    	system("cls");
        cout<< red <<"Error: Ingrese una opcion correcta." << normal <<endl;
        system("pause");
        break;
}
}while(menuShido == true);

return 0;
}
