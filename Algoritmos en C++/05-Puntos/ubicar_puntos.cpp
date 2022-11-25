#include <iostream>
#include <cassert>
#include <string>
#include <array>

using namespace std;

enum struct Region{cuadrante_I, cuadrante_II, cuadrante_III, cuadrante_IV, eje_x, eje_y, origen};
struct Punto{double x , y;};
Region obtenerRegion(Punto p);
string solucion_region(Region);
Punto obtenerPunto(double,double);
void test();

int main(){
    
    test();
    double x,y;
        
    while (cin >> x >> y)
        cout << "("<< x << "," << y <<") = "<< solucion_region(obtenerRegion(obtenerPunto(x,y))) << endl;  
     
}

Region obtenerRegion(Punto p){
    return
          p.x > 0 and p.y > 0 ? Region::cuadrante_I:
          p.x > 0 and p.y < 0 ? Region::cuadrante_IV:
          p.x < 0 and p.y > 0 ? Region::cuadrante_II:
          p.x < 0 and p.y < 0 ? Region::cuadrante_III:
          p.x == 0 and p.y !=0 ? Region::eje_y:
          p.x != 0 and p.y == 0 ? Region::eje_x:
                                  Region::origen; 
}
string solucion_region(Region x){
    return x == Region::cuadrante_I ? "Cuadrante I" : 
           x == Region::cuadrante_II ? "Cuadrante II":
           x == Region::cuadrante_III? "Cuadrante III":
           x == Region::cuadrante_IV ? "Cuadrante IV":
           x == Region::eje_x ? "Eje x":
           x == Region::eje_y ? "Eje y":
           "Origen";
    
}
Punto obtenerPunto(double x, double y){
          
    Punto puntoDado{x,y};
    return puntoDado;

}
void test(){
    Punto a{0,0};
    Punto b{1.5,2.6};
    Punto c{1,-2.8};
    Punto d{1.9,0};
    Punto e{-1,0};
    Punto f{-1,2.7};
    Punto g{-1.9,-2};
    Punto h{0,2.5};
    Punto i{0,-2};

    assert(Region::origen == obtenerRegion(a));
    assert(Region::cuadrante_I == obtenerRegion(b));
    assert(Region::cuadrante_IV == obtenerRegion(c));
    assert(Region::eje_x == obtenerRegion(d));
    assert(Region::eje_x == obtenerRegion(e));
    assert(Region::cuadrante_II == obtenerRegion(f));
    assert(Region::cuadrante_III == obtenerRegion(g));
    assert(Region::eje_y == obtenerRegion(h));
    assert(Region::eje_y == obtenerRegion(i));
    
}