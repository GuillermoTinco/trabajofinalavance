#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <string.h>
#include <fstream>
#include <conio.h>

typedef int entero;
typedef string letras;
typedef void nada;
typedef bool tof;
typedef float decimal;
typedef char caracter;


nada gotoxy(entero x, entero y){
    HANDLE Manipulador;
    COORD Coordenadas;
    Manipulador = GetStdHandle(STD_OUTPUT_HANDLE);
    Coordenadas.X = x;
    Coordenadas.Y = y;
    SetConsoleCursorPosition(Manipulador, Coordenadas);
}

nada Centrar_Texto(letras texto){
entero size_texto = (texto);
gotoxy(40-(size_texto /2), 0);
printf("%s", texto);

}

nada Izquierda_Texto(letras texto){
entero size_texto = strlen(texto);
gotoxy(80 - size_texto, 0);
printf("%s", texto);
}

nada Derecha_Texto(letras texto){
gotoxy(0, 0);
printf("%s", texto);
}

int main() {
    return 0;

}