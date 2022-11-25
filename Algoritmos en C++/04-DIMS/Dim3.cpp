#include <iostream>
#include <string>
#include <array>

using std::cin;
using std::cout;
using std::string;
using std::array; 


main(){
    unsigned mes, vendedor, region;
    int imp, total=0;
    array <array <array <int,12>,3>,4> totales{0};
    array <string,12> meses{"Enero","Febrero","Marzo","Abril","Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre","Noviembre", "Diciembre"};

    while (cin >> imp >> mes >> vendedor >> region)
          totales.at(region).at(vendedor).at(mes) += imp;
    for (unsigned i=0; i<4; ++i)
        for (unsigned j=0; j<3; ++j)
         for (unsigned k=0; k<12; ++k ){
            cout << "Region: " << i << "\t" 
             << "Vendedor: " << j << "\t" 
             << "Mes: " << meses.at(k) << " $ " 
             << totales.at(i).at(j).at(k) << '\n';
    }
}