#ifndef ahorcado_h
#define ahorcado_h
#include <iostream>
#include <string>

class Ahorcado{
private:
	std::string palabra;
	int intentos;
public:
	// Métodos
	
	// Constructor con parámetros
	// PRE: palabra_adivinar es una palabra válida de longitud mayor a 3, cant_int es un numero entero >= 3.
	// POST: crea un juego ahorcado, palabara_adivinar es la palabra a adivinar, cant_int es la cantidad de intentos que tiene el jugador. 
	Ahorcado(std::string palabra_adivinar, int cant_int);
	
	//Consructor sin parámetros
	// PRE: 
	// POST: crea un juego vacio, con palabra vacia, y cantidad de intentos 0.
	Ahorcado();
	
	// Método asignarPalabra
	// PRE:
	// POST: 
	void asignarPalabra(std::string palabra_adivinar);
	
	// Método asignarIntentos
	// PRE:
	// POST: 
	void asignarIntentos(int cant_int);

	// Método obtenerPalabra
	// PRE:
	// POST: 
	std::string obtenerPalabra();
	
	// Método obtenerIntentos
	// PRE:
	// POST: 
	int obtenerIntentos();	
	
	// Destructor
	~Ahorcado(); 
	
};

#endif // ahorcado_h
