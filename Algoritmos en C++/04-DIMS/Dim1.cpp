#include <iostream>
#include <string>
#include <array>

using std::cin;
using std::cout;
using std::string;
using std::array; 

 
main(){
    unsigned mes;
    int imp, total=0;
    array <int,12> totales{0};
    array <string,12> meses{"Enero","Febrero","Marzo","Abril","Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre","Noviembre", "Diciembre"};

    while (cin >> imp >> mes)
          totales.at(mes) += imp;
    
    for (unsigned i=0; i<12; ++i ){
        cout << "Mes " << meses.at(i) << ": $ " << totales.at(i) << '\n';
    }
}
