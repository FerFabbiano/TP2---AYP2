#ifndef ahorcado_INCLUDED
#define ahorcado_INCLUDED
#include <iostream>
#include <string>

class Ahorcado{
private:
	// Atributos
	
	std::string palabra;
	int intentos;
public:
	// Metodos
	
	// Constructor con parametros
	// PRE: palabra_adivinar es una palabra valida de longitud mayor a 3, cant_int es un numero entero >= 3.
	// POST: crea un juego ahorcado, palabara_adivinar es la palabra a adivinar, cant_int es la cantidad de intentos que tiene el jugador. 
	Ahorcado(std::string palabra_adivinar, int cant_int);
	
	// Consructor sin parametros
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

	// M�todo obtenerVector
	// PRE:
	// POST
	char* obtenerVector(std::string palabra_adivinar, int longitud);
	
	// M�todo asignarIntentos
	// PRE:
	// POST: 
	void asignarIntentos(int cant_int);

	// M�todo obtenerIntentos
	// PRE:
	// POST: 
	int obtenerIntentos();	


	// M�todo obtenerLongitud
	// PRE: recibe la palabra ingresada en forma de string
	// POST: devuelve la longitud de la palabra
	int obtenerLongitud(std::string palabra_adivinar);
	
    // M�todo obtenerFallos
    // PRE:
    // POST:
    int obtenerFallos();
    
    // M�todo mostrarAhorcado
    // PRE:
    // POST:
    void mostrarAhorcado(int intentos, int fallos, std::string palabra_adivinar);

	// M�todo arriesgarLetra
	// PRE:
	// POST:
	char arriesgar();

	// M�todo comprobarLetra
	// PRE: recibe la letra ingresada por el usuario y el vector que contiene la palabra y la longitud de la misma.
	// POST: devuelve true si la letra esta, false si no esta
	void comprobarIntento(char* vector, char cadena, int longitud);
	
	// Destructor
	~Ahorcado(); 
	
};

#endif // ahorcado_h
