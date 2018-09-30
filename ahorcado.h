#ifndef ahorcado_INCLUDED
#define ahorcado_INCLUDED
#include <iostream>
#include <string>

using namespace std;

class Ahorcado{
private:
    // Atributos
    std::string palabra;
    int intentos;
    int longitud = palabra.length();
    char *vector_palabra = new char[longitud];

public:
    // Metodos
    
    // Constructor con parametros
    // PRE: palabra_adivinar es una palabra valida de longitud mayor a 3, cant_int es un numero entero >= 3.
    // POST: crea un juego ahorcado, palabara_adivinar es la palabra a adivinar, cant_int es la cantidad de intentos que tiene el jugador.
    Ahorcado(std::string palabra_adivinar, int cant_int);
    
    //Consructor sin parametros
    // PRE:
    // POST: crea un juego vacio, con palabra vacia, y cantidad de intentos 0.
    Ahorcado();
    
    // Metodo asignarPalabra
    // PRE:
    // POST:
    void asignarPalabra(std::string palabra_adivinar);
    
    //Metodo obtener vector
    //PRE:
    //POST
    char* obtenerVector(std::string palabra_adivinar);
    
    // Metodo asignarIntentos
    // PRE:
    // POST:
    void asignarIntentos(int cant_int);
    
    // Metodo obtenerPalabra
    // PRE:
    // POST:
    std::string obtenerPalabra();
    
    // Metodo obtenerIntentos
    // PRE:
    // POST:
    int obtenerIntentos();
    
    // MŽtodo mostrarAhorcado
    // PRE:
    // POST:
    void mostrarAhorcado(int intentos, int fallos, std::string palabra_adivinar);
    
    // Destructor
    ~Ahorcado();
    
};

#endif // ahorcado_h
