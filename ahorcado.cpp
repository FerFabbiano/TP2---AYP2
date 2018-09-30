#include "ahorcado.h"


// Constructor con parametros
Ahorcado::Ahorcado(std::string palabra_adivinar, int cant_int){
	palabra = palabra_adivinar;
	intentos = cant_int;
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
}

// Metodo obtenerVector
char* obtenerVector(std::string palabra_adivinar){
	int longitud = palabra_adivinar.lenght();
	char* vector_palabra = new char[longitud];
    for(int i = 0; palabra_adivinar[i]; i++){
	    vector_palabra[i] = palabra_adivinar[i];
    }
	return vector_palabra;
}

// Metodo asignarIntentos
void Ahorcado::asignarIntentos(int cant_int){
	intentos = cant_int;
}

// Metodo obtenerPalabra
std::string Ahorcado::obtenerPalabra(){
	return palabra;
}

// Metodo obtenerIntentos
int Ahorcado::obtenerIntentos(){
	return intentos;
}

// Destructor
Ahorcado::~Ahorcado(){
	std::cout << std::endl;
	std::cout << "Destructor almacenado en la direccion: " << this << std::endl << std::endl;
}



