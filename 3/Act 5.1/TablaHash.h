
#ifndef ACT_5_1_TABLAHASH_H
#define ACT_5_1_TABLAHASH_H
#include <iostream>
#include <list>
#include <sstream>

using namespace std;

class TablaHash {
private:
    list<int>* table;
    int t_e;
public:
    TablaHash(int n) {
        t_e = n;
        table = new list<int>[t_e];
    }
    int HashKaux2(int len, string Index, int cant) {
        string index;
        int index_num;
        if (len % 2 == 0) {
            index = Index[(len / 2) - 1];
            index += Index[(len / 2)];
            stringstream ind(index);
            ind >> index_num;
            if (index_num > cant) {
                index_num = index_num % cant;
                return index_num;
            }
            else {
                return index_num;
            }
        }
        else if (len % 2 != 0) {
            index = Index[(len / 2)];
            stringstream ind(index);
            ind >> index_num;
            if (index_num > cant) {
                index_num = index_num % cant;
                return index_num;
            }
            else {
                return index_num;
            }
        }
    }

    int HashK2(int value, int cant) {
        int indice = (value * value);
        string ind = to_string(indice);
        int length = ind.length();
        indice = HashKaux2(length, ind, cant);
        return indice;
    }

    void insertHash(int key) {
        table[HashK2(key, t_e)].push_back(key);
    }

    void printC() { // O (n^2)
        for (int i = 0; i < t_e; i++) {
            cout << "Indice " << i << ": ";
            for (int element : table[i])
                cout << element << " -> ";

            cout << endl;
        }
    }
};



#endif //ACT_5_1_TABLAHASH_H
