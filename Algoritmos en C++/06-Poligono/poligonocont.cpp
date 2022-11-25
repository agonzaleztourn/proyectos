/*Author: @agonzaleztourn */

#include <iostream>
#include <cassert>
#include <string>
#include <array>
#include <cmath>

using namespace std;

struct Punto{double x , y;};
struct Poligono{
    array<Punto, 100> puntos;
    unsigned n{0};   
    };
    
void AddVertice(Poligono&, unsigned, Punto);
Punto GetVertice(const Poligono&, unsigned);
void SetVertice(Poligono&, unsigned, Punto);
void RemoveVertice(Poligono&, unsigned);
unsigned GetCantidadLados(const Poligono&);
double GetPerimetro(const Poligono&);
double DistanciaEntreDosPuntos(Punto ,Punto);
void pruebas();
void ejemplo();
void Coordenadas_poligono(const Poligono&);
int main(){
   
   pruebas();
   ejemplo(); 

}

void AddVertice(Poligono& p, unsigned n, Punto a){ /*modificar,agregar ubicacion donde agregar el vertice*/
    for (int i =p.n ; i> n-1; i--){
        Punto valor = p.puntos.at(i-1);
        p.puntos.at(i) = valor;
    }
    p.puntos.at(n-1)=a;
    p.n +=1;
}    
Punto GetVertice(Poligono& p,unsigned n){    
    return p.puntos.at(n - 1);
}
void SetVertice(Poligono& p, unsigned n, Punto a){
    p.puntos.at(n-1).x = a.x;
    p.puntos.at(n-1).y = a.y;
    
}
void RemoveVertice(Poligono& p,unsigned n){
    for (n-1; n-1 < p.n -1 ; n++)
        p.puntos.at(n-1)=p.puntos.at(n);
    p.n-=1;    
}
unsigned GetCantidadLados(const Poligono& p){ 
    return p.n < 2 ? 0 : p.n == 2 ? 1 : p.n;
}    
double GetPerimetro(const Poligono& p){
    double perimetro=0;    
    for (unsigned i=0; i < p.n - 1 ; i++){
        perimetro+=DistanciaEntreDosPuntos(p.puntos.at(i), p.puntos.at(i+1));
    }
    perimetro+=DistanciaEntreDosPuntos(p.puntos.at(p.n - 1), p.puntos.at(0));
    return perimetro;
}
double DistanciaEntreDosPuntos(Punto a, Punto b){
    return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2));
}
void Coordenadas_poligono(const Poligono& p){
    cout << "Coordenadas del poligono P:"s << endl;
    for (unsigned i=0; i < p.n ; i++){
        cout << "Punto " << i+1 << ": " << p.puntos.at(i).x << ',' << p.puntos.at(i).y << endl;
    }
}
void ejemplo(){
    /*Datos a utilizar*/
    //Poligono q;
    //AddVertice(q,1,{-1,1}); 
    //Coordenadas_poligono(q);
    
    Poligono p{{{1,1}},1};

    cout << "-------------------" << endl;
    cout << "Test de Poligono"s << endl;
    cout << "-------------------" << endl;
    /* Pruebas*/
    Coordenadas_poligono(p);
    cout << "Agregar al poligono p el punto {-1,1} en la posicion 2: "s << endl;
    AddVertice(p,2,{-1,1});    
    
    Coordenadas_poligono(p);
    cout << "-------------------" << endl;
    cout << "Agregar al poligono p el punto {-1,-1} en la posicion 3: "s << endl;
    AddVertice(p,3,{-1,-1});
    
    Coordenadas_poligono(p);  
    cout << "-------------------" << endl;  
    cout << "Agregar al poligono p el punto {1,-1} en la posicion 4: "s << endl;
    AddVertice(p,4,{1,-1});
    
    Coordenadas_poligono(p);
    cout << "-------------------" << endl;
    
    cout << "Cantidad de lados del poligono p: "s << GetCantidadLados(p) << endl;
    cout << "Obtener perimetro del poligono p:"s << endl;
    
    cout << GetPerimetro(p) << endl;
    cout << "-------------------" << endl;
    cout << "Remover vertice posicion tres"s << endl;
    RemoveVertice(p,3);
    
    Coordenadas_poligono(p);
    cout << "-------------------" << endl;
    cout << "Setear vertice del poligono p en posicion dos con el punto {2,-2}:"s << endl;
    SetVertice(p,2,{2,-2});
    
    Coordenadas_poligono(p);
    cout << "-------------------" << endl;
    cout << "Obtener el valor del punto en la posicion 1"s << endl;
    
    cout << "Punto 1: " << GetVertice(p,1).x << ',' << GetVertice(p,1).y << endl; 
    cout << "-------------------" << endl;
    cout << "Obtener el valor del punto en la posicion 3"s << endl;
    
    cout << "Punto 3: " << GetVertice(p,3).x << ',' << GetVertice(p,3).y << endl; 
    cout << "-------------------" << endl;
    
}
void pruebas(){
    //Poligono q{0,0};
    //AddVertice(q,1,{-1,1}); 
    //Coordenadas_poligono(q);
    
    Poligono p{{{1,1}},1};
    AddVertice(p,2,{-1,1});    
    assert(p.puntos.at(1).x==-1);
    assert(p.puntos.at(1).y==1);
    assert(p.n==2);
    AddVertice(p,3,{-1,-1});
    assert(p.puntos.at(2).x==-1);
    assert(p.puntos.at(2).y==-1);
    assert(p.n==3);
    AddVertice(p,4,{1,-1});
    assert(p.puntos.at(3).x==1);
    assert(p.puntos.at(3).y==-1);
    assert(p.n==4);
    assert(GetCantidadLados(p)==4);
    assert(GetPerimetro(p)==8);
    RemoveVertice(p,3);
    assert(p.puntos.at(2).x==1);
    assert(p.puntos.at(2).y==-1);
    assert(p.n==3);
    SetVertice(p,2,{2,-2});
    assert(p.puntos.at(1).x==2);
    assert(p.puntos.at(1).y==-2);
    assert(GetVertice(p,1).x==1);
    assert(GetVertice(p,1).y==1);
    assert(GetVertice(p,3).x==1);
    assert(GetVertice(p,3).y==-1);
}