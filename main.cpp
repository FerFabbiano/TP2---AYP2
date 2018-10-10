#include "ahorcado.h"
#include "funciones.h"

int main() {
    
    textcolor(YELLOW);
    
    // Se crea el objeto juego.
    Ahorcado juego1;
    
    bool resultado;
    
    textcolor(GREEN);
    
    resultado = juego1.jugar();
    
    juego1.mensaje_final(resultado);
    
    return 0;
}
