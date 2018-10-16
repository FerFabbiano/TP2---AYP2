#include "empleado.cpp"
#include<iostream>
#include<string>

int main(){
    Director dire(123, "Mauricio Macri", 1000.0, "1991");
    dire.mostrarLegajo();
    dire.incrementarSalario();
    dire.mostrarSalario();
    return 0;
}