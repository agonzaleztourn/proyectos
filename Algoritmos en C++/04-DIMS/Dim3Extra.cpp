#include <iostream>
#include <string>
#include <array>

using std::cin;
using std::cout;
using std::string;
using std::array; 

array <array <array <int,12>,3>,4> LeerDatos(int,int,int);
void MostrarTotales(array <array <array <int,12>,3>,4>);
enum struct region{Norte,Sur,Este,Oeste};
region RepresentarRegion(int);

main(){
    int mes,vendedor,region;
    array <array <array <int,12>,3>,4> totales = LeerDatos(mes,vendedor,region);
    MostrarTotales(totales);
    
}
array <array <array <int,12>,3>,4> LeerDatos(int mes, int vendedor, int region){
    int imp, total=0;
    array <array <array <int,12>,3>,4> totales{0};
    
    while (cin >> imp >> mes >> vendedor >> region)
          totales.at(region).at(vendedor).at(mes) += imp;
    return totales;
}
region RepresentarRegion(int region){
    return region == 0 ? region::Norte :
           region == 1 ? region::Sur :
           region == 2 ? region::Este : region::Oeste;
}
string NombreVendedor(int vend){
    string vendedor;
    cout << "Ingrese el nombre del vendedor" << vend;
    cin >> vendedor;
    return vendedor;
}
void MostrarTotales(array <array <array <int,12>,3>,4> totales){
    //array <string,12> meses{"Enero","Febrero","Marzo","Abril","Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre","Noviembre", "Diciembre"};

    for (unsigned i=0; i<4; ++i)
        for (unsigned j=0; j<3; ++j)
         for (unsigned k=0; k<12; ++k ){
            cout << '\n'<< i << "\t" 
                 << j << "\t" 
                 << k << "\t"<< " $ "  
                 << totales.at(i).at(j).at(k) << '\n';
         }

}
int GetVendedorConMasVentas(int mes,int region){
    
}