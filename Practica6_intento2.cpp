// Practica6_intento2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#pragma warning (disable : 4996)
using namespace std;

int main()
{
    setlocale(LC_ALL, "spanish");
    int opcion;
    int hp_caterpie = 150, hp_pikachu = 100;
    int punteria_pikachu = 65, punteria_caterpie = 48;
    int ataque_pikachu = 30, ataque_caterpie = 25;
    int exito_pikachu, exito_caterpie;
    int turno = 1, jugador = 1, oponente = 2, fin = 3;
    int captura, probabilidad_captura = 40;
    int accion_caterpie;
    srand(time(0));
    system("clear");
    cout<<"Bienvenido a Pokemon al peo. \nIba Ash caminando en las afueras de Pueblo Paleta cuando ¡un Caterpie aparecio!\n";
    cout<<"¡Pikachu ve!\n";
    while (hp_caterpie > 0 && turno != fin && hp_pikachu>0)
    {
        cout << "CATERPIE: " << hp_caterpie << endl;
        cout<<"PIKACHU : "<< hp_pikachu<<endl;
        if (turno == jugador)
        {
            cout << "Elija la acción:\n";
            cout<<"1. ATACAR\t2. OBJETO\n3. POKEBOLA\t4. HUIR\n";
            cin>>opcion;
            if (opcion == 1)
            {
                cout<<"¡PIKACHU uso PLACAJE!\n";
                exito_pikachu = ((rand() % 100) + 1);
                if (exito_pikachu < punteria_pikachu)
                {
                    hp_caterpie = hp_caterpie - ataque_pikachu;
                    cout<<"¡PIKACHU hizo "<<ataque_pikachu<< " de daño al CATERPIE enemigo!\n";
                    if (hp_caterpie <= 0)
                    {
                        cout<<"¡CATERPIE ha sido derrotado!";
                    }
                    turno = oponente;
                }
                else
                {
                    cout<<"¡PIKACHU ha fallado!\n";
                    turno = oponente;
                }
            }
            if (opcion == 2)
            {
                cout<<"¡No tienes objetos!\n";
                turno = jugador;
            }
            if (opcion == 3)
            {
                cout<<"¡Lanzaste una POKEBOLA!\n";
                captura = (rand() % 100) + 1;
                if (captura <= probabilidad_captura)
                {
                    cout<<"¡HAS CAPTURADO A CATERPIE!\n";
                    turno = fin;
                }
                else
                {
                    cout<<"¡Caterpie escapo de la POKEBOLA!\n";
                    turno = oponente;
                }
            }
            if (opcion == 4)
            {
                cout<<"¡No puedes huir!";
                turno = oponente;
            }
            if (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4)
            {
                cout<<"Opcion equivocada, vuelve a intentar.\n";
                turno = jugador;
            }
        }
        else if (turno == oponente)
        {
            cout<<"Turno de CATERPIE\n";
            accion_caterpie = (rand() % 2) + 1;
            if (accion_caterpie == 1)
            {
                cout<<"¡CATERPIE uso PLACAJE!\n";
                exito_caterpie = ((rand() % 100) + 1);
                if (exito_caterpie < punteria_caterpie)
                {
                    hp_pikachu = hp_pikachu - ataque_caterpie;
                    cout<<"¡CATERPIE hizo "<<ataque_caterpie<< " de daño a PIKACHU!\n";
                    if (hp_pikachu <= 0)
                    {
                        cout<<"PIKACHU ha sido derrotado...";
                    }
                    turno = jugador;
                }
                else
                {
                    cout<<"¡CATERPIE ha fallado!\n";
                    turno = jugador;
                }
            }
        }
         cout<<"\n\n";
    }
    cout<<"Ha terminado el juego, gracias por jugar.\n";
}


