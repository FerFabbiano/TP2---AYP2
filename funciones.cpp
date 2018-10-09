#include "funciones.h"
#include <string>
#include <iostream>

std::string pasarMayusculas(std::string palabra){
    for(int i = 0; palabra[i]; i++)
        palabra[i] = toupper(palabra[i]);
    return palabra;
}

void textcolor(int colorLetra){
    char command[13];
    
    /* Command is the control command to the terminal */
    sprintf(command, "%c[%d;%d;%dm", 0x1B, RESET, colorLetra + 30, BLACK + 40);
    std::cout << command;
}
