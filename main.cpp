#include "ahorcado.cpp"
#include "funciones.cpp"

void textcolor(int colorLetra);
std::string pasarMayusculas(std::string palabra);

int main() {
    
    textcolor(YELLOW);
    
    // Se crea el objeto juego.
    Ahorcado juego1;
    
    bool resultado;
    
    textcolor(GREEN);
    
    resultado = juego1.jugar();
    
    if (resultado == false) {
        textcolor(RED);
    }
    else{
        textcolor(BLUE);
    }
    
    juego1.mensaje_final(resultado);
    
    return 0;
}
