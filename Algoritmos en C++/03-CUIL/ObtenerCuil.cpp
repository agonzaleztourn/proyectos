#include <cassert>
#include <iostream>
#include <string>
#include <array>

using namespace std;


enum struct Sexo{Femenino,Masculino};
void Pruebas();
Sexo DatoGenero(char);
string DatoDni(string);
void VerificarDni(string);
string ObtenerCuil(string,Sexo);

int main(){

    Pruebas();

    string dni;
    char sexo;   

    cout << "El numero de CUIL es:" + ObtenerCuil(DatoDni(dni),DatoGenero(sexo));        
}

Sexo DatoGenero( char sex){
    Sexo sexo;
    do {
    cout << "Ingrese el sexo como figura en el DNI: F o  M"<< endl;
    cin >> sex;
    }
    while (sex!= 'F' and sex!= 'M');
    sexo = sex=='F' ? Sexo::Femenino : Sexo::Masculino;
    return sexo;
}

string DatoDni(string input){
    string dni;
    do { 
        cout << "Ingrese su DNI con 8 digitos:"<< endl;
        cin >> input;
    } 
    while(input.length() != 8);
    VerificarDni(input);
    return dni=input;   
}
void VerificarDni(string dni){
    for (auto c:dni) assert(isdigit(c));
    
}
string ObtenerCuil(string dni, Sexo sexo){
       string Cuil;
       array <unsigned,10> Num; /*Num es un arreglo que guarda los digitos obtenidos para sexo y dni*/
       array <unsigned,10> Factores{5, 4, 3, 2, 7, 6, 5, 4, 3, 2};
       unsigned Verificador=0;
       unsigned Verificador_chequeado=0;
       Cuil += sexo==Sexo::Femenino? "27" : "20";
       Cuil += dni;
       for (unsigned i=0; i<10; ++i ){
          Num.at(i)= (Cuil.at(i)-'0')*Factores.at(i);
          Verificador += Num.at(i);
       }       
        Verificador = 11-Verificador%11; /*El digito verificador debe ser menor a 10, en caso de que sea 10 es 1 y si es 11 es 0*/
        Verificador_chequeado = Verificador < 10 ? Verificador:
                                Verificador == 10 ? 1: 0;

       Cuil += to_string(Verificador_chequeado);

       return Cuil.substr(0,2)+"-"+Cuil.substr(2,8)+"-"+Cuil.substr(10,1);        
}
void Pruebas(){

    assert(ObtenerCuil("36075712",Sexo::Femenino)== "27-36075712-4");
    assert(ObtenerCuil("37162575",Sexo::Masculino)== "20-37162575-6");
    assert(ObtenerCuil("08634668",Sexo::Masculino)== "20-08634668-1");
    assert(ObtenerCuil("45786987",Sexo::Masculino)== "20-45786987-9");
    assert(ObtenerCuil("45786987",Sexo::Femenino)== "27-45786987-3");
    assert(ObtenerCuil("33698547",Sexo::Femenino)== "27-33698547-7");
    

    
}