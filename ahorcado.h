#ifndef ahorcado_INCLUDED
#define ahorcado_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

class Ahorcado{
private:
    // Atributos
    
    std::string palabra;
    int intentos;
    char* vector;
    char* guiones;
    char* utilizadas;
    int longitud;
    
public:
    // Metodos
    
    // Constructor con parametros
    // PRE: palabra_adivinar es una palabra valida de longitud mayor a 3, cant_int es un numero entero >= 3.
    // POST: crea un juego ahorcado, palabara_adivinar es la palabra a adivinar, cant_int es la cantidad de intentos que tiene el jugador.
    Ahorcado(std::string palabra_adivinar, int cant_int);
    
    // Constructor sin parametros
    // PRE:
    // POST: crea un juego vacio, con palabra vacia, y cantidad de intentos 0.
    Ahorcado();
    
    // Metodo asignarPalabra
    // PRE:
    // POST:
    void asignarPalabra(std::string palabra_adivinar);
    
    // Metodo obtenerPalabra
    // PRE:
    // POST:
    std::string obtenerPalabra();
    
    std::string pasarMayusculas(std::string palabra);
    
    // Metodo asignarIntentos
    // PRE:
    // POST:
    void asignarIntentos(int cant_int);
    
    // Metodo obtenerIntentos
    // PRE:
    // POST:
    int obtenerIntentos();
    
    
    // Metodo obtenerLongitud
    // PRE: recibe la palabra ingresada en forma de string
    // POST: devuelve la longitud de la palabra
    int obtenerLongitud();
    
    // Metodo ingresarLetra
    // PRE:
    // POST:
    char ingresarLetra();
    
    // Metodo ingresarPalabra
    std::string ingresarPalabra();
    
    // Metodo mostrarTurno
    // PRE:
    // POST:
    void mostrarTurno(int fallos);
    
    // Metodo checkIntento
    // PRE:
    // POST:
    bool checkIntento(std::string palabra_ingresada);
    
    // Metodo checkIntento
    // PRE:
    // POST:
    bool checkIntento(char letra);
    
    // Metodo checkSiGanaste
    // PRE:
    // POST:
    bool checkSiGanaste();
    
    // Metodo jugar
    // PRE:
    // POST:
    bool jugar();
    
    // Metodo mensajeFinal
    // PRE:
    // POST:
    void mensaje_final(bool mensaje);
    
    // Metodo leerLinea
    std::string leerLinea(int nroLinea);
    
    // Metodo randomLinea
    int randomLinea();
    
    // Destructor
    ~Ahorcado();
    
};

#endif // ahorcado_h
