// optimizacion.h
#ifndef OPTIMIZACION_H
#define OPTIMIZACION_H

#include <vector>

struct Restriccion {
    double coef_x1;
    double coef_x2;
    double limite;
};

// Declaraciones de funciones
void ingresarPrecios();
void ingresarRestricciones();
void mostrarFuncionGanancia();

// Variables globales externas
extern double p1;
extern double p2;
extern std::vector<Restriccion> restricciones;

#endif 