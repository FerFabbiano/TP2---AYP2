#include "ahorcado.h"

// Constructor con par�metros
Ahorcado::Ahorcado(std::string palabra_adivinar, int cant_int){
	palabra = palabra_adivinar;
	intentos = cant_int;
	std::cout << "Constructor con parametros almacenado en la direccion: " << this << std::endl << std::endl;
}

// Constructor sin par�metros
Ahorcado::Ahorcado(){
	palabra = "";
	intentos = 0;
	std::cout << "Constructor sin parametros almacenado en la direccion: " << this << std::endl << std::endl;
	
}

// M�todo asignarPalabra
void Ahorcado::asignarPalabra(std::string palabra_adivinar){
	palabra = palabra_adivinar;
}

// M�todo asignarIntentos
void Ahorcado::asignarIntentos(int cant_int){
	intentos = cant_int;
}

// M�todo obtenerPalabra
std::string Ahorcado::obtenerPalabra(){
	return palabra;
}

// M�todo obtenerIntentos
int Ahorcado::obtenerIntentos(){
	return intentos;
}

// Destructor
Ahorcado::~Ahorcado(){
	std::cout << std::endl;
	std::cout << "Destructor almacenado en la direccion: " << this << std::endl << std::endl;
}



