/*
Desc:"Obtener Cantidad de dias, dados un mes y un año.
      El rango de años es de 1583 a 3021"
Name: Grupo:
            - Conte, Hernan Antonio
            - Desiderioscioli, Tomas
            - Gonzalez Tourn Agustina
            - Mamani Inca, Anthony Emanuel
            - Marino, Ezequiel Matias
            - Maunus, John-fritz
Date: 27/06/21
*/

#include <cassert>
#include <iostream>
#include <string>

using namespace std;


bool esBisiesto(int);
int getCantidadDias(int, int);

int getInputMes();
int getInputAnio();
void printResult(int month,int year);
void doTest();


int main(){
    doTest();
    int month, year;
    month = getInputMes();
    month == 2 ? year = getInputAnio() : year = 0;
    printResult(month,year);
}

int getCantidadDias(int x, int y){
 return
    x == 2 and not esBisiesto(y) ? 28 :
    x == 2 and esBisiesto(y) ? 29 :
    x == 4 or x == 6 or x == 9 or x == 11 ? 30 :
    31;
}

bool esBisiesto(int y){
    return y % 4 == 0 and (y % 100 != 0 or y % 400 == 0);
}

int getInputMes(){
    int mes;
    cout <<"Ingrese el mes:";
    cin >> mes;
    return mes < 1 or mes > 12 ? -1 : mes;
}

int getInputAnio(){
    int year;
    cout << "Ingrese el año:";
    cin >> year;
    return year < 1583 or year > 3021 ? -1 : year;
}

void printResult(int month,int year){
    string res =
            month == -1 ? "Mes fuera de rango. Se permiten enteros del 1 al 12 inclusive." :
            year == -1 ? "Año fuera de rango. Se permiten enteros del 1583 al 3021 inclusive." :
            "El mes " + to_string(month) +  " tiene: " + to_string(getCantidadDias(month, year)) + " dias.";
    cout << res;
}

void doTest(){
    
    // Test Año Bisiesto
    assert(getCantidadDias(1, 2020) == 31);
    assert(getCantidadDias(2, 2020) == 29);
    assert(getCantidadDias(3, 2020) == 31);
    assert(getCantidadDias(4, 2020) == 30);
    assert(getCantidadDias(5, 2020) == 31);
    assert(getCantidadDias(6, 2020) == 30);
    assert(getCantidadDias(7, 2020) == 31);
    assert(getCantidadDias(8, 2020) == 31);
    assert(getCantidadDias(9, 2020) == 30);
    assert(getCantidadDias(10, 2020) == 31);
    assert(getCantidadDias(11, 2020) == 30);
    assert(getCantidadDias(12, 2020) == 31);

    // Test Año no Bisiesto
    assert(getCantidadDias(1, 2021) == 31);
    assert(getCantidadDias(2, 2021) == 28);
    assert(getCantidadDias(3, 2021) == 31);
    assert(getCantidadDias(4, 2021) == 30);
    assert(getCantidadDias(5, 2021) == 31);
    assert(getCantidadDias(6, 2021) == 30);
    assert(getCantidadDias(7, 2021) == 31);
    assert(getCantidadDias(8, 2021) == 31);
    assert(getCantidadDias(9, 2021) == 30);
    assert(getCantidadDias(10, 2021) == 31);
    assert(getCantidadDias(11, 2021) == 30);
    assert(getCantidadDias(12, 2021) == 31);

    // Test Año  Bisiesto y No Bisiesto, mes Febrero
    assert(getCantidadDias(2, 2020) == 29);
    assert(getCantidadDias(2, 2021) == 28);

    // Test de funcionalidad de esBisiesto
    assert(esBisiesto(2020) == true);
    assert(esBisiesto(2021) == false);
    assert(esBisiesto(2000) == true);
    assert(esBisiesto(1900) == false);
    assert(esBisiesto(1600) == true);
    
    //Tests de casos limites

    assert(getCantidadDias(1, 1583) == 31);
    assert(getCantidadDias(2, 1583) == 28);
    assert(getCantidadDias(3, 1583) == 31);
    assert(getCantidadDias(4, 1583) == 30);
    assert(getCantidadDias(5, 1583) == 31);
    assert(getCantidadDias(6, 1583) == 30);
    assert(getCantidadDias(7, 1583) == 31);
    assert(getCantidadDias(8, 1583) == 31);
    assert(getCantidadDias(9, 1583) == 30);
    assert(getCantidadDias(10, 1583) == 31);
    assert(getCantidadDias(11, 1583) == 30);
    assert(getCantidadDias(12, 1583) == 31);


    assert(getCantidadDias(1, 3021) == 31);
    assert(getCantidadDias(2, 3021) == 28);
    assert(getCantidadDias(3, 3021) == 31);
    assert(getCantidadDias(4, 3021) == 30);
    assert(getCantidadDias(5, 3021) == 31);
    assert(getCantidadDias(6, 3021) == 30);
    assert(getCantidadDias(7, 3021) == 31);
    assert(getCantidadDias(8, 3021) == 31);
    assert(getCantidadDias(9, 3021) == 30);
    assert(getCantidadDias(10, 3021) == 31);
    assert(getCantidadDias(11, 3021) == 30);
    assert(getCantidadDias(12, 3021) == 31);

}

