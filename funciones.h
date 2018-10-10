#include <string>
#define RESET           0
#define BRIGHT          1
#define DIM             2
#define UNDERLINE       3
#define BLINK           4
#define REVERSE         7
#define HIDDEN          8
#define BLACK           0
#define RED             1
#define GREEN           2
#define YELLOW          3
#define BLUE            4
#define MAGENTA         5
#define CYAN            6
#define WHITE           7

// Función textColor
// PRE: Recibe un numero entero que representa el color elegido.
// POST: Cambia el color de la consola.
void textcolor(int colorLetra);

// Funcion pasarMayusculas
// PRE: Recibe un string valido.
// POST: Convierte el string a mayusculas. 
std::string pasarMayusculas(std::string palabra);

