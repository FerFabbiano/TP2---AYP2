#include "empleado.h"
#include<iostream>

Empleado::Empleado(int legajo, std::string nombre_apellido, double salario, std::string antiguedad){
    this -> legajo = legajo;
    this -> nombre_apellido = nombre_apellido;
    this -> salario = salario;
    this -> antiguedad = antiguedad;
}


void Empleado::mostrarLegajo(){
    std::cout << legajo << std::endl;
}

void Empleado::mostrarNombreApellido(){
    std::cout << nombre_apellido << std::endl;
}

void Empleado::mostrarSalario(){
    std::cout << salario << std::endl;
}

void Empleado::mostrarAntiguedad(){
    std::cout << antiguedad << std::endl;
}

void Empleado::incrementarSalario(){}
    /* A los jefes se les incrementa un 10%,
    a los directores un 15% y a los empleados admin. un 20% */


Director::Director(int legajo, std::string nombre_apellido, double salario, std::string antiguedad): Empleado(legajo, nombre_apellido, salario, antiguedad){
}

void Director::incrementarSalario(){
    salario += salario * 0.05;
    
}