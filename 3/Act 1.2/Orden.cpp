//
// Created by Axel JM on 06/09/2021.
//

#include "Orden.h"
#include <vector>
using namespace std;

void Orden::ordIntercambio(vector<int> &theV)
{
    int i, j, aux; /* se realizan n-1 pasadas, a[o] ... a[n-2] */
    for (i = 0; i <= theV.size() - 2; i++)/* coloca mínimo de a[i+1]...a[n-1] en a[i] */
        for (j = i + 1; j <= theV.size() - 1; j++)
            if (theV[i] > theV[j])
            {
                aux = theV[i];
                theV[i] = theV[j];
                theV[j] = aux;
            }
}

void Orden::ordBurbuja(vector<int> &theV)
{
    int i, j;
    for (i = 0; i < theV.size() ; i++)

        // Last i elements are already in place
        for (j = i+1; j < theV.size() ; j++)
            if (theV[i] > theV[j])
                swap(&theV[i], &theV[j]);
}


void Orden::ordMerge(vector<int> &theV, int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        ordMerge(theV, l, m);
        ordMerge(theV, m + 1, r);

        merge(theV, l, m, r);
    }
}



void Orden::merge(vector<int> &theV, int start, int mid, int end) {
    int start2 = mid + 1;

    // If the direct merge is already sorted
    if (theV[mid] <= theV[start2]) {
        return;
    }

    // Two pointers to maintain start
    // of both arrays to merge
    while (start <= mid && start2 <= end) {

        // If element 1 is in right place
        if (theV[start] <= theV[start2]) {
            start++;
        }
        else {
            int value = theV[start2];
            int index = start2;

            // Shift all the elements between element 1
            // element 2, right by 1.
            while (index != start) {
                theV[index] = theV[index - 1];
                index--;
            }
            theV[start] = value;

            // Update all the pointers
            start++;
            mid++;
            start2++;
        }

    }
}


void Orden::swap(int* val1, int* val2)
{
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}
