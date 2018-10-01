#include "ahorcado.cpp"
using namespace std;

int main() {
    
    // Se crea el objeto juego.
    Ahorcado juego1("hola", 3);
    
    juego1.mensaje_final(juego1.jugar());
    
    return 0;
}
