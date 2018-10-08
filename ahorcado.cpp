#include "ahorcado.h"

// Constructor con parametros
Ahorcado::Ahorcado(std::string palabra_adivinar, int cant_int){
    palabra = pasarMayusculas(palabra_adivinar);
    intentos = cant_int;
    longitud = palabra.length();
    utilizadas = new char[intentos + longitud];
    vector = new char[longitud];
    guiones = new char[longitud];
    for (int i = 0; i<longitud; i++) {
        vector[i] = palabra[i];
        guiones[i] = '_';
    }
    for (int i = 0; i<=longitud + intentos; i++) {
        utilizadas[i] = ' ';
    }
    std::cout << "Constructor con parametros almacenado en la direccion: " << this << std::endl << std::endl;
}

// Constructor sin parametros
Ahorcado::Ahorcado(){
    palabra = leerLinea(randomLinea());
    palabra = pasarMayusculas(palabra);
    intentos = 5;
    longitud = palabra.length();
    utilizadas = new char[intentos + longitud];
    vector = new char[longitud];
    guiones = new char[longitud];
    for (int i = 0; i<longitud; i++) {
        vector[i] = palabra[i];
        guiones[i] = '_';
    }
    for (int i = 0; i<=longitud + intentos; i++) {
        utilizadas[i] = ' ';
    }
    std::cout << "Constructor sin parametros almacenado en la direccion: " << this << std::endl << std::endl;
}

std::string Ahorcado::pasarMayusculas(std::string palabra){
    for(int i = 0; palabra[i]; i++)
        palabra[i] = toupper(palabra[i]);
    return palabra;
}

// Metodo randomLinea
int Ahorcado::randomLinea(){
    srand(time(0));
    int randNum = rand()%1000;
    return randNum;
}

// Metodo leerLinea
std::string Ahorcado::leerLinea(int nroLinea){
    std::ifstream archivo;
    archivo.open("/Users/joaquinandresen/Desktop/Programación/Algoritmos y Programación II/TP2/TP2/palabras.txt");
    std::string linea;
    for (int i = 0; i<nroLinea; i++) {
        getline(archivo, linea);
    }
    archivo.close();
    return linea;
}

// Metodo asignarPalabra
void Ahorcado::asignarPalabra(std::string palabra_adivinar){
    palabra = palabra_adivinar;
    vector = new char[longitud];
    for (int i = 0; i < longitud; i++) {
        vector[i] = palabra[i];
        guiones[i] = '_';
    }
}

// Metodo obtenerPalabra
std::string Ahorcado::obtenerPalabra(){
    return palabra;
}

// Metodo obtenerLongitud
int Ahorcado::obtenerLongitud(){
    return longitud;
}

// Metodo asignarIntentos
void Ahorcado::asignarIntentos(int cant_int){
    intentos = cant_int;
}

// Metodo obtenerIntentos
int Ahorcado::obtenerIntentos(){
    return intentos;
}

// Metodo ingresarLetra
char Ahorcado::ingresarLetra(){
    char letra;
    std::cout << "Ingresa una letra: ";
    std::cin >> letra;
    return toupper(letra);
}

// Metodo ingresarPalabra
std::string Ahorcado::ingresarPalabra(){
    std::string palabra_ingresada;
    
    std::cout<<"Ingrese la palabra: ";
    std::cin>>palabra_ingresada;
    
    return pasarMayusculas(palabra_ingresada);
}

// Metodo checkIntento
bool Ahorcado::checkIntento(std::string palabra_ingresada){
    for (int i = 0; i<longitud; i++) {
        if (palabra_ingresada[i] != vector[i]) {
            return false;
        }
    }
    return true;
}

// Metodo checkIntento
bool Ahorcado::checkIntento(char letra){
    bool respuesta = false;
    for (int i = 0; i<longitud; i++) {
        if (letra == vector[i]) {
            respuesta = true;
            guiones[i] = letra;
        }
    }
    return respuesta;
}

bool Ahorcado::checkSiGanaste(){
    for (int i = 0; i < longitud; i++) {
        if (guiones[i] == '_'){
            return false;
        }
    }
    return true;
}

// Metodo mostrarTurno
void Ahorcado::mostrarTurno(int fallos){
    
    std::cout<<"Palabra: ";
    for (int i = 0; i < longitud; i++) {
        std::cout << guiones[i];
    }
    std::cout<<std::endl;
    
    std::cout << "Fallos: " << fallos << "/" << intentos << std::endl;
    
    std::cout << "Utilizadas: ";
    
    for (int i = 0; i<=intentos + longitud; i++) {
        std::cout << utilizadas[i] << " ";
    }
    
    std::cout << std::endl;
}

// Metodo jugar
bool Ahorcado::jugar(){
    int fallos = 0;
    int opcion;
    char letra;
    bool respuesta;
    int contador = 0;
    
    while (fallos < intentos) {
        mostrarTurno(fallos);
        
        std::cout << "1) Ingresar una letra"<<std::endl<<"2) Ingresar palabra completa"<<std::endl;
        std::cout << "Ingrese una de las opciones: ";
        std::cin >> opcion;
        std::cout << std::endl;
        
        if (opcion == 1) {
            letra = ingresarLetra();
            utilizadas[contador] = letra;
            contador++;
            respuesta = checkIntento(letra);
        }
        
        else{
            if (checkIntento(ingresarPalabra()) == true) {
                return true;
            }
            return false;
        }
        
        if (respuesta == false) {
            ++fallos;
        }
        
        if (checkSiGanaste() == true){
            return true;
        }
    }
    return false;
}

void Ahorcado::mensaje_final(bool mensaje){
    if (mensaje == true) {
        std::cout << "Felicidades, ganaste el juego!!, la palabra a adivinar era: "<<palabra<<"."<<std::endl;
    }
    else{
        std::cout << "Perdiste el juego."<<std::endl;
    }
}

// Destructor
Ahorcado::~Ahorcado(){
    delete [] vector;
    delete [] guiones;
    delete [] utilizadas;
    
    std::cout << std::endl;
    std::cout << "Destructor almacenado en la direccion: " << this << std::endl << std::endl;
}
