//legajo, nombre y apellido, salario y antigüedad.
#include<string>
#include<iostream>

class Empleado{
private:
    int legajo;
    std::string nombre_apellido;
    double salario;
    std::string antiguedad;
public:
    Empleado(int legajo, std::string nombre_apellido, double salario, std::string antiguedad);

    void mostrarLegajo();

    void mostrarNombreApellido();

    void mostrarSalario();

    void mostrarAntiguedad();

    virtual void incrementarSalario();
};


class Director: public Empleado{
public:
    Director(int legajo, std::string nombre_apellido, double salario, std::string antiguedad);

    void incrementarSalario();
};