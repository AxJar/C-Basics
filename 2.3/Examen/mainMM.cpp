// Axel Jarquin Morga
// A01636324

#include <iostream>
#include "Bici.h"
#include "BiciMecanica.h"
#include "BiciElectrica.h"

int main() {
    BiciMecanica bm("BMX",0.0);
    BiciElectrica be("BikeAir",0.0);
    cout<<bm;
    cout<<be;
    bm.acelera();
    be.acelera();
    bm.acelera();
    be.acelera();
    cout<<bm;
    cout<<be;
    return 0;
}
