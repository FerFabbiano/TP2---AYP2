#ifndef ahorcado_INCLUDED
#define ahorcado_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

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
    // Crea 3 vectores dinámicos (2 de la longitud de la palabra, y uno de la longitud de la cantidad de intentos mas la longitud de la palabra.
    // Completa uno de los vectores con guiones.
    Ahorcado(std::string palabra_adivinar, int cant_int);
    
    // Constructor sin parametros
    // PRE:
    // POST: crea un Ahorcado, la palabra es elegida aleatoriamente, y la cantidad de intentos son ingresados por el usuario (numero entero >= 3)
    Ahorcado();
    
    // Metodo asignarPalabra
    // PRE: Recibe una palabra valida.
    // POST: Asigna la palabra recibida al atributo palabra_adivinar y crea un vector de guiones de la longitud de la palabra.
    void asignarPalabra(std::string palabra_adivinar);
    
    // Metodo obtenerPalabra
    // PRE: -
    // POST: Devuelve la palabra que debe adivinar el usuario.
    std::string obtenerPalabra();
    
    // Metodo asignarIntentos
    // PRE: Recibe un numero entero >= 3.
    // POST: Asigna el numero recibido por parametro al atributo intentos.
    void asignarIntentos(int cant_int);
    
    // Metodo obtenerIntentos
    // PRE: -
    // POST: Devuelve la cantidad de intentos que tiene el usuario para adivinar la palabra. Es un número entero >= 3.
    int obtenerIntentos();
    
    
    // Metodo obtenerLongitud
    // PRE: recibe la palabra ingresada en forma de string.
    // POST: devuelve la longitud de la palabra.
    int obtenerLongitud();
    
    // Metodo ingresarLetra
    // PRE: -
    // POST: Devuelve la letra ingresada por el usuario, en mayusculas.
    char ingresarLetra();
    
    // Metodo ingresarPalabra
    // PRE: -
    // POST: Devuelve un string en mayúsculas, que es la palabra que arriesgo el usuario.
    std::string ingresarPalabra();
    
    // Metodo mostrarTurno
    // PRE: ---
    // POST: Imprime por pantalla la cantidad de fallos que le quedan al usuario, la palabra con las letras que adivino y las letras utilizadas.
    void mostrarTurno(float fallos);
    
    // Metodo checkIntento
    // PRE: Recibe un string valido con la palabra que arriesgo el usuario.
    // POST: Devuele false si la palabra arriesgada es distinta a la palabra a adivinar, devuelve true caso contrario.
    bool checkIntento(std::string palabra_ingresada);
    
    // Metodo checkIntento
    // PRE: Recibe un char valido con la letra arriesgada por el usuario.
    // POST: Devuelve true si la letra arriesgada esta en la palabra a adivinar, y
    // reemplaza la letra en el lugar correspondiente en la palabra con guiones. Devuelve false caso contrario.
    bool checkIntento(char letra);
    
    // Metodo checkSiGanaste
    // PRE: -
    // POST: Devuelve true si el usuario completó la palabra, devuelve false caso contrario.
    bool checkSiGanaste();
    
    // Metodo jugar
    // PRE: -
    // POST: Devuelve true si el jugador gana, false caso contrario.
    bool jugar();
    
    // Metodo mensajeFinal
    // PRE: Recibe un booleano.
    // POST: Imprime un mensaje por pantalle de acuerdo al valor recibido.
    void mensaje_final(bool mensaje);
    
    // Metodo leerLinea
    // PRE: Recibe el número de linea del archivo en el que se encuentra la palabra a adivinar.
    // POST: Devuelve un string, que es la palabra que deberá adivinar el usuario.
    std::string leerLinea(int nroLinea);
    
    // Metodo randomLinea
    // PRE: -
    // POST: Devuelve un número aleatorio, que representa el número de linea en el que se buscará la palabra a adivinar.
    int randomLinea();
    
    // M�todo mostrarAhorcado
    // PRE: Recibe un numero del tipo flotante.
    // POST: Imprime por pantalla las diferentes partes del cuerpo a medida que el usuario va fallando.
    void mostrarAhorcado(float fallos);
    
    // Metodo convertirSumando
    float convertirSumando(float sumando);
    
    // Destructor
    ~Ahorcado();
    
};

#endif
