#include "ahorcado.h"

// Constructor con parametros
Ahorcado::Ahorcado(std::string palabra_adivinar, int cant_int){
    palabra = pasarMayusculas(palabra_adivinar);
    intentos = cant_int;
    vector = new char[palabra.length()];
    guiones = new char[palabra.length()];
    for (int i = 0; i<palabra.length(); i++) {
        vector[i] = palabra[i];
        guiones[i] = '_';
    }
    std::cout << "Constructor con parametros almacenado en la direccion: " << this << std::endl << std::endl;
}

// Constructor sin parametros
Ahorcado::Ahorcado(){
    palabra = "";
    intentos = 0;
    std::cout << "Constructor sin parametros almacenado en la direccion: " << this << std::endl << std::endl;
}

// Metodo asignarPalabra
void Ahorcado::asignarPalabra(std::string palabra_adivinar){
    palabra = palabra_adivinar;
    vector = new char[palabra.length()];
    for (int i = 0; i<palabra.length(); i++) {
        vector[i] = palabra[i];
        guiones[i] = '_';
    }
}

// Metodo obtenerPalabra
std::string Ahorcado::obtenerPalabra(){
    return palabra;
}

// Metodo obtenerLongitud
int Ahorcado::obtenerLongitud(){
    return palabra.length();
}

// Metodo asignarIntentos
void Ahorcado::asignarIntentos(int cant_int){
    intentos = cant_int;
}

// Metodo obtenerIntentos
int Ahorcado::obtenerIntentos(){
    return intentos;
}

// Metodo ingresarLetra
char Ahorcado::ingresarLetra(){
    char letra;
    std::cout << "Ingresa una letra: ";
    std::cin >> letra;
    return toupper(letra);
}

// Metodo ingresarPalabra
std::string Ahorcado::ingresarPalabra(){
    std::string palabra_ingresada;
    
    std::cout<<"Ingrese la palabra: ";
    std::cin>>palabra_ingresada;
    
    return pasarMayusculas(palabra_ingresada);
}

// Metodo checkPalabra
bool Ahorcado::checkPalabra(std::string palabra_ingresada){
    for (int i = 0; i<palabra.length(); i++) {
        if (palabra_ingresada[i] != vector[i]) {
            return false;
        }
    }
    return true;
}

// Metodo checkLetra
bool Ahorcado::checkLetra(char letra){
    bool respuesta = false;
    for (int i = 0; i<palabra.length(); i++) {
        if (letra == vector[i]) {
            respuesta = true;
            guiones[i] = letra;
        }
    }
    return respuesta;
}

// Metodo pasarMayusculas
std::string Ahorcado::pasarMayusculas(std::string palabra){
    for(int i = 0; palabra[i]; i++)
        palabra[i] = toupper(palabra[i]);
    return palabra;
}

// Metodo mostrarTurno
void Ahorcado::mostrarTurno(int fallos){
    std::cout<<"Palabra: ";
    for (int i = 0; i<palabra.length(); i++) {
        std::cout<<guiones[i];
    }
    std::cout<<std::endl;
    
    std::cout<<"Fallos: "<<fallos<<"/"<<intentos;
    
    std::cout<<std::endl;
    
}

// Metodo jugar
bool Ahorcado::jugar(){
    int fallos = 0;
    int opcion;
    char letra;
    bool respuesta;
    
    while (fallos <= intentos) {
        mostrarTurno(fallos);
        
        std::cout<<"1) Ingresar una letra"<<std::endl<<"2) Ingresar palabra completa"<<std::endl;
        std::cout<<"Ingrese una de las opciones: ";
        std::cin>>opcion;
        std::cout<<std::endl;
        
        if (opcion == 1) {
            letra = ingresarLetra();
            respuesta = checkLetra(letra);
        }
        
        else{
            if (checkPalabra(ingresarPalabra()) == true) {
                return true;
            }
            return false;
        }
        
        if (respuesta == false) {
            ++fallos;
        }
        
    }
    return false;
}

void Ahorcado::mensaje_final(bool mensaje){
    if (mensaje == true) {
        std::cout<<"Felicidades, ganaste el juego!!"<<std::endl;
    }
    else{
        std::cout<<"Perdiste el juego."<<std::endl;
    }
}

// Destructor
Ahorcado::~Ahorcado(){
    std::cout << std::endl;
    std::cout << "Destructor almacenado en la direccion: " << this << std::endl << std::endl;
}



