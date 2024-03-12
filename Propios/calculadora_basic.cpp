#include <iostream>
#include <string>
using namespace std;


void operation ( int *operacion ) {

 int op1, op2;                                                                  // declaracion de variables locales
 int r_sum;
 int r_rest;
 int r_div;
 int r_mult;

    switch ( *operacion )
    
    {
     case 1:                                                                    // operacion suma
        cout << "\n--- Operacion Suma ---\nIngrese los operandos:" << endl;
        cout << "\n-- Primer operando --" << endl;
        cout << "-> ";
        cin >> op1;                                                             // ingreso del primer operando ( usuario )
        cout << "\n-- Segundo operando --" << endl;
        cout << "-> ";
        cin >> op2;                                                             // ingreso del segundo operando ( usuario )

        r_sum = op1 + op2;                                                      // operacion, resultado en variable r_sum

        cout << "\nEl resultado de la operacion es: " << r_sum << endl;      
    break;
     
     case 2:
        cout << "\n--- Operacion Resta ---\nIngrese los operandos:" << endl;
        cout << "\n-- Primer operando --" << endl;
        cout << "-> ";
        cin >> op1;
        cout << "\n-- Segundo operando --" << endl;
        cout << "-> ";
        cin >> op2;

        r_rest = op1 - op2;

        cout << "\nEl resultado de la operacion es: " << r_rest << endl;
    
    break;
     
     case 3:
        cout << "\n--- Operacion Division ---\nIngrese los operandos:" << endl;
        cout << "\n-- Primer operando --" << endl;
        cout << "-> ";
        cin >> op1;
        cout << "\n-- Segundo operando --" << endl;
        cout << "-> ";
        cin >> op2;

        r_div = op1 / op2;

        cout << "\nEl resultado de la operacion es: " << r_div << endl;

    break;

     case 4:
        cout << "\n--- Operacion Multiplicacion ---\nIngrese los operandos:" << endl;
        cout << "\n-- Primer operando --" << endl;
        cout << "-> ";
        cin >> op1;
        cout << "\n-- Segundo operando --" << endl;
        cout << "-> ";
        cin >> op2;

        r_mult = op1 * op2;

        cout << "\nEl resultado de la operacion es: " << r_mult << endl;

    break;

default:
    break;
}

}


int main () {

 int operacion;
 string respuestaUsuario;
 string respuestaCorrecta = "si,Si,SI";

    cout << "Bienvenido a la calculadora basica\n" << endl;                             // menu para el usuario
    cout << "Ingrese la opcion para operar" << endl;
    cout << "\n1 -> Suma\n2 -> Resta\n3 -> Division\n4 -> Multiplicacion\n" << endl;
    cout << "-> ";                                                                      // ingreso de dato por el usuario
    cin >> operacion;                                                                   // asignacion a la variable (dato de usuario)

    operation ( &operacion );                                                           // llamado a la funcion

    cout << "\nQuiere hacer otro calculo? (Si o No)\n" << endl;
    cout << "-> ";
    cin >> respuestaUsuario;


    if ( respuestaUsuario.compare(respuestaCorrecta) )                                  // chance de hacer un calculo mas, si el usuario desea
    {
        cout << "\nIngrese la opcion para operar" << endl;
        cout << "\n1 -> Suma\n2 -> Resta\n3 -> Division\n4 -> Multiplicacion\n" << endl;
        cout << "-> ";
        cin >> operacion;

        operation ( &operacion );

        cout << "\n ---- Gracias por usar esta calculadora ----\n" << endl;             // mensaje de cierre del programa

    } else {
        cout << "Gracias por usar esta calculadora\n" << endl;
    }
    
    

    return 0;
}