#include "ahorcado.cpp"


void pruebaConParametros();
//void pruebaSinParametros();

std::string convertir_mayusculas(std::string palabra);

int main() {
    
    pruebaConParametros();
    //pruebaSinParametros();
    
    return 0;
}

std::string convertir_mayusculas(std::string palabra){
    // Convierte y devuelve una palabra a mayusculas iteranto los caracteres.
    for(int i = 0; palabra[i]; i++)
        palabra[i] = toupper(palabra[i]);
    return palabra;
}

void pruebaConParametros(){
    // Se crea el objeto juego.
    Ahorcado juego1("hola", 3);
    std::string palabra;
    
    // Se obtiene la palabra ingresada por parametro en el objeto juego1.
    palabra = convertir_mayusculas(juego1.obtenerPalabra());
    
    cout << "La palabra a adivinar es: " << palabra << endl;
    cout << "El jugador dispone de " << juego1.obtenerIntentos() << " intentos para adivinar la palabra." << endl;
    
    // Prueba de obtencion de vector dinamico en base a string
    char* vector;
    vector = juego1.obtenerVector(palabra);
    
    
}

/*
 void pruebaSinParametros(){
 Ahorcado juego;
 juego.asignarIntentos(4);
 juego.asignarPalabra("hello!");
 cout << "Tiene " << juego.obtenerIntentos() << " intentos. " << endl;
 cout << "La palabra a adivinar es: " << convertir_mayusculas(juego.obtenerPalabra())<< endl;
 }
 */
