/*Author: @agonzaleztourn */

#include <iostream>
#include <cassert>
#include <string>
#include <cmath>

using namespace std;

struct Punto{double x , y;};

struct Nodo{
    Punto val;
    Nodo* siguiente{nullptr};
};

struct Poligono{
    Nodo* primerElemento{nullptr};   
};

    
void AddVertice(Poligono&, unsigned, Punto);
Punto GetVertice(const Poligono&, unsigned);
void SetVertice(Poligono&, unsigned,  Punto);
void RemoveVertice(Poligono&, unsigned);
unsigned GetCantidadLados(const Poligono&);
double GetPerimetro(const Poligono&);
double DistanciaEntreDosPuntos(Punto , Punto);
void pruebas();
void ejemplo();
void Coordenadas_poligono(const Poligono&);
bool Error_perimetro(Poligono&,double);

int main(){
    
    pruebas();
    ejemplo();

}

void AddVertice(Poligono& poligono, unsigned posicion, Punto punto){
    Nodo* p{poligono.primerElemento};
    if (posicion == 1){
        Nodo* nuevo_nodo = new Nodo;
        nuevo_nodo -> val = punto;
        nuevo_nodo -> siguiente = p;
        poligono.primerElemento=nuevo_nodo;
    }
    else {
        for (unsigned i=2; i != posicion; i++){
            p = p -> siguiente;
        }
        Nodo* nuevo_nodo = new Nodo;
        nuevo_nodo -> val = punto;
        nuevo_nodo -> siguiente = p->siguiente;
        p->siguiente = nuevo_nodo;
    }
    
}
void RemoveVertice(Poligono& poligono, unsigned posicion){
    Nodo* aux = poligono.primerElemento;
    Nodo* aEliminar;

    if (posicion==1){
        aEliminar= poligono.primerElemento;
        poligono.primerElemento = poligono.primerElemento ->siguiente;
        delete aEliminar;
    }
    else{
        for (unsigned i=2; i != posicion; i++){
            aux = aux -> siguiente;   
        }  
        aEliminar= aux ->siguiente;
        aux -> siguiente = aux ->siguiente ->siguiente;
        delete aEliminar;       
    }
}
Punto GetVertice(const Poligono& poligono, unsigned posicion){
    Nodo* aux = poligono.primerElemento;

    if (posicion==1){
        return poligono.primerElemento ->val;
    }
     else{
        for (unsigned i=1; i != posicion; i++){
            aux = aux -> siguiente;   
        }  
        return aux ->val;       
    }
}
void SetVertice(Poligono& poligono, unsigned posicion, Punto punto){
    Nodo* aux = poligono.primerElemento;
    if (posicion==1){
        poligono.primerElemento ->val = punto;
    }
    else{
       for (unsigned i=1; i != posicion; i++){
            aux = aux -> siguiente;   
        }
        aux ->val = punto;
    }
}
unsigned GetCantidadLados(const Poligono& poligono){
    unsigned puntos=0;
    Nodo* aux = poligono.primerElemento;
    while (aux != nullptr){
        puntos +=1;
        aux = aux ->siguiente;
    }
    return puntos < 2 ? 0 : puntos == 2 ? 1 : puntos ;
}
double DistanciaEntreDosPuntos( Punto a , Punto b){
    return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2));
}
double GetPerimetro(const Poligono& poligono){
    double perimetro=0;
    unsigned cantidadLados= GetCantidadLados(poligono);
    unsigned cantidadPuntos;
    cantidadPuntos = cantidadLados == 1 ? 2 : cantidadLados;
    Nodo* inicio = poligono.primerElemento;
    Nodo* final= nullptr;

    for (unsigned i=1; i < cantidadPuntos ; i++){
        perimetro += DistanciaEntreDosPuntos(inicio->val, inicio ->siguiente ->val);
        inicio = inicio ->siguiente;
        final = inicio;
    }    
    perimetro += DistanciaEntreDosPuntos(poligono.primerElemento ->val, final ->val);
    return perimetro;
}
void Coordenadas_poligono(const Poligono& p){
    cout << "Coordenadas del poligono P:"s << endl;
    Nodo* aux= p.primerElemento;
    unsigned i=0;
    while (aux != nullptr){
        
        cout << "Punto " << i+1 << ": " << (aux ->val).x << ',' << (aux ->val).y << endl;
        aux = aux->siguiente;
        i++;
    }
}
bool Error_perimetro(Poligono& p, double perimetro){
    double perimetro_calculo = GetPerimetro(p);
    return std::abs(perimetro_calculo - perimetro) <= 0.00001;
}
void ejemplo(){
    /*Datos a utilizar*/
   
    Poligono p;
    //p.primerElemento = new Nodo;
    //p.primerElemento ->val = {1,1};
    //p.primerElemento ->siguiente = nullptr;
    
    cout << "-------------------" << endl;
    cout << "Test de Poligono"s << endl;
    cout << "-------------------" << endl;
    /* Pruebas*/
    Coordenadas_poligono(p);
    cout << "Agregar al poligono p el punto {1,1} en la posicion 1: "s << endl;
    AddVertice(p,1,{1,1});
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
    cout << "Obtener perimetro del poligono p:" << endl;
    
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
    
    cout << "Punto 3: "s << GetVertice(p,3).x << ',' << GetVertice(p,3).y << endl; 
    cout << "-------------------" << endl;
    cout << "Obtener perimetro del poligono p:"s << endl;
    
    cout << GetPerimetro(p) << endl;
    RemoveVertice(p,1);
    RemoveVertice(p,2);
    RemoveVertice(p,3);
    Coordenadas_poligono(p);
}
void pruebas(){
    Poligono q;
    AddVertice(q,1,{1,1});
    assert(q.primerElemento->val.x==1);
    assert(q.primerElemento->val.y==1);
    
    Poligono p;
    //p.primerElemento = new Nodo;
    //p.primerElemento ->val = {1,1};
    //p.primerElemento ->siguiente = nullptr;
    AddVertice(p,1,{1,1});
    assert(p.primerElemento->val.x==1);
    assert(p.primerElemento->val.y==1);
    AddVertice(p,2,{-1,1});
    assert(p.primerElemento->siguiente->val.x==-1);
    assert(p.primerElemento->siguiente->val.y==1);
    AddVertice(p,3,{-1,-1});
    assert(p.primerElemento->siguiente->siguiente->val.x==-1);
    assert(p.primerElemento->siguiente->siguiente->val.y==-1);
    AddVertice(p,4,{1,-1});
    assert(p.primerElemento->siguiente->siguiente->siguiente->val.x==1);
    assert(p.primerElemento->siguiente->siguiente->siguiente->val.y==-1);
    assert(GetCantidadLados(p)==4);
    assert(GetPerimetro(p)==8);
    RemoveVertice(p,3);
    assert(p.primerElemento->siguiente->siguiente->val.x==1);
    assert(p.primerElemento->siguiente->siguiente->val.y==-1);
    SetVertice(p,2,{2,-2});
    assert(p.primerElemento->siguiente->val.x == 2);
    assert(p.primerElemento->siguiente->val.y == -2);
    assert(GetVertice(p,1).x==1);
    assert(GetVertice(p,1).y==1);
    assert(GetVertice(p,3).x==1);
    assert(GetVertice(p,3).y==-1);
    assert(Error_perimetro(p,6.57649));
    RemoveVertice(p,3);
    RemoveVertice(p,2);
    RemoveVertice(p,1);
    
    
}