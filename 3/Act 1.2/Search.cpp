//
// Created by Axel JM on 12/09/2021.
//

#include "Search.h"
using namespace std;

int Search::busqBinaria(vector<int>& vec, int clave) {
    int central, bajo, alto, valorCentral;
    bajo = 0;
    alto = vec.size() - 1;
    while (bajo <= alto) {
        central = (bajo + alto) / 2;
        valorCentral = vec[central];
        if (clave == valorCentral)
            return central;
        else if (clave < valorCentral)
            alto = central - 1;
        else
            bajo = central + 1;
    }
    return -1;
}

int Search::busqSecuencial(std::vector<int>& vec, int clave){
    int i = 0;
    while ((i < vec.size() && (clave != vec[i]))){
        i++;
    }
    if (i < vec.size()){
        return i;
    }
    else{
        return -1;
    }
    return 0;
}
