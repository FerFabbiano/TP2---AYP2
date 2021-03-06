#include "ahorcado.h"
using namespace std;


void pruebaConParametros();
void pruebaSinParametros();
std::string convertir_mayusculas(std::string palabra);

int main() {
	
	pruebaConParametros();
	pruebaSinParametros();
	
	return 0;
}

std::string convertir_mayusculas(std::string palabra){
	for(int i = 0; palabra[i]; i++) 
      palabra[i] = toupper(palabra[i]);
    return palabra;
}

void pruebaConParametros(){
	Ahorcado juego1("hola", 3);
	std::string palabra;
	
	palabra = convertir_mayusculas(juego1.obtenerPalabra());
	
	cout << "La palabra a adivinar es: " << palabra << endl;
	cout << "El jugador dispone de " << juego1.obtenerIntentos() << " intentos para adivinar la palabra." << endl;
	
	juego1.asignarPalabra("chau");
	juego1.asignarIntentos(4);
	std::string palabra_nueva = juego1.obtenerPalabra();
	int nuevo_intentos = juego1.obtenerIntentos();
	
	palabra_nueva = convertir_mayusculas(palabra_nueva);
	
	cout << endl;
	cout << "La nueva palabra a adivinar es: " << palabra_nueva << endl;
	cout << "El jugador dispone de " << nuevo_intentos << " intentos para adivinar la nueva palabra." << endl;
}

void pruebaSinParametros(){
	Ahorcado juego;
	juego.asignarIntentos(4);
	juego.asignarPalabra("hello!");
	cout << "Tiene " << juego.obtenerIntentos() << " intentos. " << endl;
	cout << "La palabra a adivinar es: " << convertir_mayusculas(juego.obtenerPalabra())<< endl;
}



