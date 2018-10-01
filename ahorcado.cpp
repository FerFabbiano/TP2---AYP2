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

// Metodo obtenerPalabra
std::string Ahorcado::obtenerPalabra(){
	return palabra;
}

// Metodo obtenerLongitud
int Ahorcado::obtenerLongitud(std::string palabra_adivinar){
	return palabra_adivinar.length();
}

// Metodo obtenerVector
char* Ahorcado::obtenerVector(std::string palabra_adivinar, int longitud){
	char* vector_palabra = new char[longitud];
    for(int i = 0; i <= longitud; i++){
	    vector_palabra[i] = palabra_adivinar[i];
    }
	return vector_palabra;
}

// Metodo asignarIntentos
void Ahorcado::asignarIntentos(int cant_int){
	intentos = cant_int;
}

// Metodo obtenerIntentos
int Ahorcado::obtenerIntentos(){
	return intentos;
}

//Metodo obtenerFallos
int Ahorcado::obtenerFallos(){
    return intentos;
}

// Metodo arriesgar
char Ahorcado::arriesgar(){
	char letra;
	std::cout << "Ingresa una cadena de longitud 1 o " << Ahorcado::obtenerLongitud(palabra) << ": " << std::endl;
	std::cin >> letra;
	return letra;
}

// Metodo comprobarIntento
void Ahorcado::comprobarIntento(char* vector, char cadena, int longitud){
	int cont = 0;
	for(int i = 0; i < longitud; i++){
		if(vector[i] == cadena){
			std::cout << "La cadena esta!" << std::endl; // aca habria que hacer un vector de tamaño (longitud) e ir marcando ahi la posicion donde se encuentra la letra que coincide
			cont += 1;
		}
	}
	if(cont == 0){
		std::cout << "La cadena no esta!" << std::endl;
	}		
}

// M�todo mostrarAhorcado
void Ahorcado::mostrarAhorcado(int intentos, int fallos, std::string palabra_adivinar){
    std::string linea0 = " --------";
    std::string linea01 = "|                 ";
    std::string linea1 = "|      -|-";
    std::string linea2 = "|     |   |       ";
    std::string linea3 = "|     |___|";
    std::string linea4 = "|       |         ";
    std::string linea51 = "|    ---|         ";
    std::string linea5 = "|    ---|---      ";
    std::string linea6 = "|       |         ";
    std::string linea71 = "|      /";
    std::string linea7 = "|      / \\";
    std::string linea8 = "|     /   \\";
    std::string linea81 = "|     /";
    
    if (fallos == 0) {
        std::cout<<linea01<<std::endl;
        std::cout<<linea01<<std::endl;
        std::cout<<linea01<<palabra_adivinar<<std::endl;
        std::cout<<linea4<<std::endl;
        std::cout<<linea4<<std::endl;
        std::cout<<linea6<<"Intentos: "<<intentos<<std::endl;
        std::cout<<linea01<<std::endl;
        std::cout<<linea01<<std::endl;
    }
    if (fallos == 1) {
        std::cout<<linea1<<std::endl;
        std::cout<<linea2<<palabra_adivinar<<std::endl;
        std::cout<<linea3<<std::endl;
        std::cout<<linea4<<std::endl;
        std::cout<<linea4<<"Intentos: "<<intentos<<std::endl;
        std::cout<<linea6<<std::endl;
        std::cout<<linea01<<std::endl;
        std::cout<<linea01<<std::endl;
    }
    if (fallos == 2) {
        std::cout<<linea1<<std::endl;
        std::cout<<linea2<<palabra_adivinar<<std::endl;
        std::cout<<linea3<<std::endl;
        std::cout<<linea4<<std::endl;
        std::cout<<linea51<<"Intentos: "<<intentos<<std::endl;
        std::cout<<linea6<<std::endl;
        std::cout<<linea01<<std::endl;
        std::cout<<linea01<<std::endl;
    }
    if (fallos == 3) {
        std::cout<<linea1<<std::endl;
        std::cout<<linea2<<palabra_adivinar<<std::endl;
        std::cout<<linea3<<std::endl;
        std::cout<<linea4<<std::endl;
        std::cout<<linea5<<"Intentos: "<<intentos<<std::endl;
        std::cout<<linea6<<std::endl;
        std::cout<<linea01<<std::endl;
        std::cout<<linea01<<std::endl;
    }
    if (fallos == 4) {
        std::cout<<linea1<<std::endl;
        std::cout<<linea2<<palabra_adivinar<<std::endl;
        std::cout<<linea3<<std::endl;
        std::cout<<linea4<<std::endl;
        std::cout<<linea5<<"Intentos: "<<intentos<<std::endl;
        std::cout<<linea6<<std::endl;
        std::cout<<linea71<<std::endl;
        std::cout<<linea81<<std::endl;
    }
    if (fallos == 5) {
        std::cout<<linea1<<std::endl;
        std::cout<<linea2<<palabra_adivinar<<std::endl;
        std::cout<<linea3<<std::endl;
        std::cout<<linea4<<std::endl;
        std::cout<<linea5<<"Intentos: "<<intentos<<std::endl;
        std::cout<<linea6<<std::endl;
        std::cout<<linea7<<std::endl;
        std::cout<<linea8<<std::endl;
    }
}

// Destructor
Ahorcado::~Ahorcado(){
	std::cout << std::endl;
	std::cout << "Destructor almacenado en la direccion: " << this << std::endl << std::endl;
}



