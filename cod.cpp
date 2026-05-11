#include <iostream>
#include <cmath>

double encontra_raiz(double low, double high){
    double middle = (low+high)/2;
    double E = 0.0001;
    double funcao = pow(middle, 3)-middle-2;
    double fLow = pow(low, 3)-low-2;

    if ( abs(funcao) <= E or funcao == 0) { return(middle); }

    if (funcao * (fLow-low-2) < 0) {
        return(encontra_raiz(low, middle));
    } else if(funcao * low > 0) {
        return(encontra_raiz(middle, high)); }
}

int main() {
    double low = -1;
    double high = 2;
    double pos = encontra_raiz(low, high);
    
    std::cout("\nRaiz = ", pos);
    
    return 0;
}