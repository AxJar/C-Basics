#include <iostream>
#include "Multimedio.h"
#include "MP3M.h"

int main() {
    MP3M mp3("Yesterday",80);
    cout<<mp3<<" Con un peso de: "<<mp3.getSize()<<"KB"<<endl;
    return 0;
};
