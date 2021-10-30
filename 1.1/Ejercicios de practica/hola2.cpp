#include <iostream>
using namespace std;

int main(){
    float res1 = (3 + 5) / 7;
    cout << res1 << endl;
    float res2 = (3 + 5) / (float) 7;
    cout << res2 << endl;
    float res3 = (float) ( (3 + 5) / 7 );
    cout << res3 << endl;
    return 0;
}
