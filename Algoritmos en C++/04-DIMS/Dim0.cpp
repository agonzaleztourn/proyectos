#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string; 

main(){
    int imp, total=0;

    while (cin >> imp)
        total += imp;
    
    cout << "El total de ventas es de: $ " << total << '\n';
}
