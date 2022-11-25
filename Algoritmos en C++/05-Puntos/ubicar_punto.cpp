#include <iostream>
#include <cassert>
#include <string>


using namespace std;

enum struct Region{cuadrante_I, cuadrante_II, cuadrante_III, cuadrante_IV, eje_x, eje_y, origen};
struct Punto{double x , y;};
Region obtenerRegion(Punto p);
string obtenerRegionEnString(Region);
Punto obtenerPunto();
void test();

int main(){
    
    test();
    
    string sol = obtenerRegionEnString(obtenerRegion(obtenerPunto()));   
    cout << "El punto se encuentra en:" << sol << endl;
     
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
string obtenerRegionEnString(Region x){
    return x == Region::cuadrante_I ? "Cuadrante I" : 
           x == Region::cuadrante_II ? "Cuadrante II":
           x == Region::cuadrante_III? "Cuadrante III":
           x == Region::cuadrante_IV ? "Cuadrante IV":
           x == Region::eje_x ? "Eje x":
           x == Region::eje_y ? "Eje y":
           "Origen";
    
}
Punto obtenerPunto(){
    Punto p;
    
    cout << "Ubicar punto en el plano: ingrese a continuacion las coordenadas del punto" << endl;
    cout << "ingrese la cordenada x:" << endl;
    cin >> p.x;
    cout << "ingrese la cordenada y:" << endl;
    cin >> p.y;       
    
    return p;

}
void test(){
    
    assert(Region::origen == obtenerRegion({0,0}));
    assert(Region::cuadrante_I == obtenerRegion({1.5,2.6}));
    assert(Region::cuadrante_IV == obtenerRegion({1,-2.8}));
    assert(Region::eje_x == obtenerRegion({1.9,0}));
    assert(Region::eje_x == obtenerRegion({-1,0}));
    assert(Region::cuadrante_II == obtenerRegion({-1,2.7}));
    assert(Region::cuadrante_III == obtenerRegion({-1.9,-2}));
    assert(Region::eje_y == obtenerRegion({0,2.5}));
    assert(Region::eje_y == obtenerRegion({0,-2}));
    assert(Region::origen != obtenerRegion({1,0}));
    assert(Region::cuadrante_I != obtenerRegion({-1.5,2.6}));
    assert(Region::cuadrante_IV != obtenerRegion({-1,-2.8}));
    assert(Region::eje_x != obtenerRegion({0,4}));
    assert(Region::eje_y != obtenerRegion({-1,0}));
    assert(Region::cuadrante_II != obtenerRegion({1,2.7}));
    assert(Region::cuadrante_III != obtenerRegion({-1.9,2}));
}