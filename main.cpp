#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
#include <string>
#include "optimizacion.h"
using namespace std;

// Definiciones de variables globales
double p1 = 0.0;
double p2 = 0.0;
vector<Restriccion> restricciones;

// Opción 1: ingreso de precios de venta 
void ingresarPrecios() {
    cout << "\n--- Ingreso de Precios de Venta ---" << endl;

    while (true) {
        cout << "Ingrese el precio de cada mesa (x1) (USD): ";
        try {
            cin >> p1;
            if (cin.fail() || p1 <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
               
            }
            break;
       
            cout << "Error: " << endl;
        }
    

    

// Opción 2: Ingreso de restricciones 
void ingresarRestricciones() {
    if (p1 == 0.0 || p2 == 0.0) {
        cout << "\nError: Primero debe ingresar los precios de venta (Opción 1)." << endl;
        return;
    }

    cout << "\n--- Ingreso de Restricciones de Producción ---" << endl;
    cout << "Formato de restricción: a*x1 + b*x2 = c" << endl;

    int numRestricciones;
    cout << "\n¿Cuántas restricciones desea ingresar? ";
    while (!(cin >> numRestricciones) || numRestricciones <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada inválida. Ingrese un número entero positivo: ";
    }

    for (int i = 0; i < numRestricciones; ++i) {
        Restriccion r;
        cout << "\nRestricción #" << i + 1 << ":" << endl;

        cout << "Coeficiente para x1 (mesas): ";
        while (!(cin >> r.coef_x1)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Ingrese un número real: ";
        }

        cout << "Coeficiente para x2 (sillas): ";
        while (!(cin >> r.coef_x2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Ingrese un número real: ";
        }

        cout << "Límite de la restricción (valor después de =): ";
        while (!(cin >> r.limite) || r.limite < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Ingrese un número real no negativo: ";
        }

        restricciones.push_back(r);
    }

    cout << "\nRestricciones registradas:" << endl;
    for (const auto& r : restricciones) {
        cout << r.coef_x1 << "x1 + " << r.coef_x2 << "x2 = " << r.limite << endl;
    }
}

// Opción 3: Mostrar función de ganancia
void mostrarFuncionGanancia() {
    if (p1 == 0.0 || p2 == 0.0) {
        cout << "\nError: Primero debe ingresar los precios de venta (Opción 1)." << endl;
        return;
    }

    cout << fixed << setprecision(2);
    cout << "\n--- Función de Ganancia ---" << endl;
    cout << "Función de ganancia: Maximizar Z = " << p1 << "x1 + " << p2 << "x2" << endl;
}

// Menú de opciones  
int main() {
    int opcion;
    
    do {
        cout << "\n--- Menú de Optimización ---" << endl;
        cout << "1. Ingresar precios de venta" << endl;
        cout << "2. Ingresar restricciones de producción" << endl;
        cout << "3. Mostrar función de ganancia" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opción: ";
        
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                ingresarPrecios();
                break;
            case 2:
                ingresarRestricciones();
                break;
            case 3:
                mostrarFuncionGanancia();
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
        
    } while (opcion != 4);
    
    return 0;
}
