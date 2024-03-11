#include <iostream>
using namespace std;


void operation ( int *operacion ) {

 int op1, op2;
 int r_sum;
 int r_rest;
 int r_div;
 int r_mult;

    switch ( *operacion )
    
    {
     case 1:
        cout << "\n--- Operacion Suma ---\nIngrese los operandos:" << endl;
        cout << "\n-- Primer operando --" << endl;
        cout << "-> ";
        cin >> op1;
        cout << "\n-- Segundo operando --" << endl;
        cout << "-> ";
        cin >> op2;

        r_sum = op1 + op2;

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

        r_rest = op1 + op2;

        cout << "\nEl resultado de la operacion es: " << r_sum << endl;
    
    break;

default:
    break;
}

}


int main () {

 int operacion;


    cout << "Bienvenido a la calculadora basica\n" << endl;
    cout << "Ingrese la opcion para operar" << endl;
    cout << "\n1 -> Suma\n2 -> Resta\n3 -> Division\n4 -> Multiplicacion\n" << endl;
    cout << "-> ";
    cin >> operacion;

    operation ( &operacion );

    return 0;
}