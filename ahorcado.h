#ifndef ahorcado_INCLUDED
#define ahorcado_INCLUDED
#include <iostream>
#include <string>

class Ahorcado{
private:
	// Atributos
	std::string palabra;
	int intentos;
	int fallos;
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
	char* obtenerVector(std::string palabra_adivinar, int longitud);
	
	// Metodo asignarIntentos
	// PRE:
	// POST: 
	void asignarIntentos(int cant_int);

	// Metodo obtenerPalabra
	// PRE:
	// POST: 
	std::string obtenerPalabra();

	// Metodo obtenerLongitud
	//PRE: recibe la palabra ingresada en forma de string
	//POST: devuelve la longitud de la palabra
	int obtenerLongitud(std::string palabra_adivinar);
	
	// Metodo obtenerIntentos
	// PRE:
	// POST: 
	int obtenerIntentos();	

    // Metodo obtenerFallos
    // PRE:
    // POST:
    int obtenerFallos();
    
    // Metodo mostrarAhorcado
    // PRE:
    // POST:
    void mostrarAhorcado(int intentos, int fallos, std::string palabra_adivinar);

	//Metodo obtenerLetra
	//PRE:
	//POST:
	char obtenerLetra();

	// Metodo comprobarLetra
	// PRE: recibe la letra ingresada por el usuario y el vector que contiene la palabra y la longitud de la misma.
	// POST: devuelve true si la letra esta, false si no esta
	bool comprobarLetra(char* vector, char letra, int longitud);
	
	// Destructor
	~Ahorcado(); 
	
};

#endif // ahorcado_h
