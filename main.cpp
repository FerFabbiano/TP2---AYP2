#include "ahorcado.cpp"

int main() {
    
    // Se crea el objeto juego.
    Ahorcado juego1;
    
    juego1.mensaje_final(juego1.jugar());
    
    return 0;
}

std::string pasarMayusculas(std::string palabra){
    for(int i = 0; palabra[i]; i++)
        palabra[i] = toupper(palabra[i]);
    return palabra;
}
