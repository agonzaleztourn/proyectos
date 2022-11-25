#include <iostream>
#include <string>
#include <array>

using std::cin;
using std::cout;
using std::string;
using std::array; 


main(){
    unsigned mes, vendedor;
    int imp, total=0;
    array < array <int,12>,3 > totales{0};
    array <string,12> meses{"Enero","Febrero","Marzo","Abril","Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre","Noviembre", "Diciembre"};

    while (cin >> imp >> mes >> vendedor)
          totales.at(vendedor).at(mes) += imp;
    for (unsigned i=0; i<3; ++i)
       for (unsigned j=0; j<12; ++j ){
        cout << "Vendedor: " << i << "\t" 
             << "Mes: " << meses.at(j) << " $ " 
             << totales.at(i).at(j) << '\n';
    }
}