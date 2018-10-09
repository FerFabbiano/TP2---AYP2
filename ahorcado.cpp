#include "ahorcado.h"
#include "funciones.h"

// Constructor con parametros
Ahorcado::Ahorcado(std::string palabra_adivinar, int cant_int){
    palabra = pasarMayusculas(palabra_adivinar);
    intentos = cant_int;
    longitud = palabra.length();
    utilizadas = new char[intentos + longitud];
    vector = new char[longitud];
    guiones = new char[longitud];
    for (int i = 0; i < longitud; i++) {
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
    std::cout << "Constructor sin parametros almacenado en la direccion: " << this << std::endl << std::endl;
    palabra = leerLinea(randomLinea());
    palabra = pasarMayusculas(palabra);
    std::cout << "Ingrese la cantidad de intentos que desea tener para adivinar: ";
    std::cin >> intentos;
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
}

// Metodo randomLinea
int Ahorcado::randomLinea(){
    srand(time(0));
    int randNum = rand()%14279;
    return randNum;
}

// Metodo leerLinea
std::string Ahorcado::leerLinea(int nroLinea){
    std::ifstream archivo;
    archivo.open("palabras.txt");
    std::string linea;
    for (int i = 0; i < nroLinea; i++) {
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
    
    std::cout << "Ingrese la palabra: ";
    std::cin >> palabra_ingresada;
    
    return pasarMayusculas(palabra_ingresada);
}

// Metodo checkIntento
bool Ahorcado::checkIntento(std::string palabra_ingresada){
    for (int i = 0; i < longitud; i++) {
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

// Método checkSiGanaste
bool Ahorcado::checkSiGanaste(){
    for (int i = 0; i < longitud; i++) {
        if (guiones[i] == '_'){
            return false;
        }
    }
    return true;
}

// Metodo mostrarTurno
void Ahorcado::mostrarTurno(float fallos){
    
    std::cout<<"Palabra: ";
    for (int i = 0; i < longitud; i++) {
        std::cout << guiones[i];
    }
    std::cout<<std::endl;
    
    std::cout << "Fallos: " << fallos << "/" << intentos << std::endl;
    
    std::cout << "Utilizadas: ";
    
    for (int i = 0; i <= intentos + longitud; i++) {
        std::cout << utilizadas[i] << " ";
    }
    
    std::cout << std::endl;
}

// Metodo jugar
bool Ahorcado::jugar(){
    float fallos = 0.0;
    int fallos_enteros = 0;
    float sumando = 0.0;
    sumando = convertirSumando(sumando);
    int opcion;
    char letra;
    bool respuesta;
    int contador = 0;
    std::string pregunta;
    
    while (fallos <= 6) {
        mostrarAhorcado(fallos);
        mostrarTurno(fallos_enteros);
        
        std::cout << "1) Ingresar una letra" << std::endl << "2) Ingresar palabra completa" << std::endl;
        std::cout << "Ingrese una de las opciones: ";
        std::cin >> opcion;
        std::cout << std::endl;
        
        if (opcion == 1) {
            letra = ingresarLetra();
            utilizadas[contador] = letra;
            contador ++;
            respuesta = checkIntento(letra);
        }
        
        else{
            std::cout << "ATENCION! Si ingresa mal la palabra, perdera el juego! Desea arriesgar la palabra igual? (s/n)";
            std::cout << std::endl;
            std::cin >> pregunta;
            if (pregunta == "n"){
                letra = ingresarLetra();
                utilizadas[contador] = letra;
                contador ++;
                respuesta = checkIntento(letra);
            }
            else{
                if (checkIntento(ingresarPalabra()) == true) {
                    return true;
                }
                return false;
            }
        }
        
        if (respuesta == false) {
            ++fallos_enteros;
            fallos = fallos + sumando;
        }
        
        if (checkSiGanaste() == true){
            return true;
        }
    }
    std::cout << std::endl;
    mostrarAhorcado(fallos);
    return false;
}

void Ahorcado::mensaje_final(bool mensaje){
    if (mensaje == true) {
        std::cout << std::endl;
        std::cout << "Felicidades, ganaste el juego!!, la palabra a adivinar era: "<<palabra<<"."<<std::endl;
    }
    else{
        std::cout << "Perdiste el juego.La palabra a adivinar era: "<<palabra<<"."<<std::endl;
    }
}

void Ahorcado::mostrarAhorcado(float fallos){
    std::string linea0 = " --------";
    std::string linea01 = "|";
    std::string linea1 = "|      -|-";
    std::string linea2 = "|     |   |";
    std::string linea3 = "|     |___|";
    std::string linea4 = "|       |";
    std::string linea51 = "|    ---|";
    std::string linea5 = "|    ---|---";
    std::string linea6 = "|       |";
    std::string linea71 = "|      /";
    std::string linea7 = "|      / \\";
    std::string linea8 = "|     /   \\";
    std::string linea81 = "|     /";
    
    if (fallos >= 0 && fallos < 1) {
        std::cout << linea0 << std::endl;
        std::cout << linea01 << std::endl;
        std::cout << linea01 << std::endl;
        std::cout << linea01 << std::endl;
        std::cout << linea01 << std::endl;
        std::cout << linea01 << std::endl;
        std::cout << linea01 << std::endl;
        std::cout << linea01 << std::endl;
        std::cout << linea01 << std::endl;
    }
    if (fallos >= 1 && fallos < 2) {
        std::cout << linea0 << std::endl;
        std::cout << linea1 << std::endl;
        std::cout << linea2 << std::endl;
        std::cout << linea3 << std::endl;
        std::cout << linea01 << std::endl;
        std::cout << linea01 << std::endl;
        std::cout << linea01 << std::endl;
        std::cout << linea01 << std::endl;
        std::cout << linea01 << std::endl;
    }
    if (fallos >= 2 && fallos < 3) {
        std::cout << linea0 << std::endl;
        std::cout << linea1 << std::endl;
        std::cout << linea2 << std::endl;
        std::cout << linea3 << std::endl;
        std::cout << linea4 << std::endl;
        std::cout << linea4 << std::endl;
        std::cout << linea6 << std::endl;
        std::cout << linea01 << std::endl;
        std::cout << linea01 << std::endl;
    }
    if (fallos >= 3 && fallos < 4) {
        std::cout << linea0 << std::endl;
        std::cout << linea1 << std::endl;
        std::cout << linea2 << std::endl;
        std::cout << linea3 << std::endl;
        std::cout << linea4 << std::endl;
        std::cout << linea51 << std::endl;
        std::cout << linea6 << std::endl;
        std::cout << linea01 << std::endl;
        std::cout << linea01 << std::endl;
    }
    if (fallos >= 4 && fallos < 5) {
        std::cout << linea0 << std::endl;
        std::cout << linea1 << std::endl;
        std::cout << linea2 << std::endl;
        std::cout << linea3 << std::endl;
        std::cout << linea4 << std::endl;
        std::cout << linea5 << std::endl;
        std::cout << linea6 << std::endl;
        std::cout << linea01 << std::endl;
        std::cout << linea01 << std::endl;
    }
    if (fallos >= 5 && fallos < 6) {
        std::cout << linea0 << std::endl;
        std::cout << linea1 << std::endl;
        std::cout << linea2 << std::endl;
        std::cout << linea3 << std::endl;
        std::cout << linea4 << std::endl;
        std::cout << linea5 << std::endl;
        std::cout << linea6 << std::endl;
        std::cout << linea71 << std::endl;
        std::cout << linea81 << std::endl;
    }
    if (fallos >= 6) {
        std::cout << linea0 << std::endl;
        std::cout << linea1 << std::endl;
        std::cout << linea2 << std::endl;
        std::cout << linea3 << std::endl;
        std::cout << linea4 << std::endl;
        std::cout << linea5 << std::endl;
        std::cout << linea6 << std::endl;
        std::cout << linea7 << std::endl;
        std::cout << linea8 << std::endl;
    }
    std::cout << std::endl;
}
 
// Metodo convertirSumando
float Ahorcado::convertirSumando(float sumando){
    sumando = 6.0/intentos;
    return sumando;
}

// Destructor
Ahorcado::~Ahorcado(){
    delete [] vector;
    delete [] guiones;
    delete [] utilizadas;
    
    std::cout << std::endl;
    std::cout << "Destructor almacenado en la direccion: " << this << std::endl << std::endl;
}
