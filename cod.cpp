#include <iostream>
#include <cmath>

double encontra_raiz(double low, double high){
    double middle = (low+high)/2;
    double E = 0.0001;
    double funcao = pow(middle, 3)-middle-2;
    double fLow = pow(low, 3)-low-2;

    if ( fabs(funcao) <= E) { return(middle); }

    if (funcao * fLow < 0) {
        return(encontra_raiz(low, middle));
    } else if(funcao * fLow > 0) {
        return(encontra_raiz(middle, high)); 
    } else {
        return middle;
    }
    
}

int main() {
    double low = 1;
    double high = 2;
    double pos = encontra_raiz(low, high);

    std::cout << "Raiz = " << pos;

    return 0;
}