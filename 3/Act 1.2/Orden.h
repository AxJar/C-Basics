//
// Created by Axel JM on 06/09/2021.
//

#ifndef ACT_1_2_ORDEN_H
#define ACT_1_2_ORDEN_H
#include <vector>

class Orden {
public:
    static void ordIntercambio(std::vector<int> & );
    static void ordBurbuja(std::vector<int> &);
    static void ordMerge(std::vector<int>&, int l, int r);

private:
    static void swap(int*, int*);
    static void merge(std::vector<int>&, int, int, int);
};



#endif //ACT_1_2_ORDEN_H
