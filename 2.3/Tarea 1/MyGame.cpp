
#include <iostream>
#include "MyGame.h"

using namespace std;


void MyGame::start(){
    go.Logic();
    cout << "Press C to to continue next turn, or E to end the game: "<< endl;
    cin >> s;
    while(s != 'C' && 'E'){
        cout <<"invalid option, please press C to continue next turn, or E to end the game" << endl;
        cin >> s;
        if(s == 'E'){
            cout << "Thanks for playing!!!" << endl;
            return 0;
    while(turn <= 20){
        points = rDice.roll();
        t1 += points;
        turn++;
        if (t1 > 29){
            cout << turn << "1" <<points << "N" << "30" endl;
            cout<<"--GAME OVER--"<< endl;
            cout<<"Player 1 is the winner!!!!"<<endl;
            break;
        };
    tileValue = g.getTile(t1 - 1);
    if(tileValue == 'S' ){
        if(t1 - 3 >1){
            t1 = 1
        };
        else{
            t1 = t1 - 3;
        };
        };
    };
    else if(tileValue == 'L'){
        t1 += 3;
        if(t1 > 29){
            cout << turn << "1" <<points << "N" << "30" endl;
            cout<<"--GAME OVER--"<< endl;
            cout<<"Player 1 is the winner!!!!"<<endl;
            break;
        };
    };
};
cout << turn << "1" << points << tileValue << t1 << endl;
points = rDice.roll();
t2 += points;
turn++;
if(t2 > 29){
    cout << turn << "2" <<points << "N" << "30" endl;
    cout<<"--GAME OVER--"<< endl;
    cout<<"Player 2 is the winner!!!!"<<endl;
    break;
};
tileValue = g.getTile(t2 - 1);
if(tileValue == 'S'){
    if(t2 - 3 >1){
        t2 = 1;
    };    
    else{
        t2 = t2 - 3;
    };
    };
    };
else if(tileValue == 'L'){
    t1 += 3;
    if(t1 > 29){
        cout << turn << "2" <<points << "N" << "30" endl;
        cout<<"--GAME OVER--"<< endl;
        cout<<"Player 2 is the winner!!!!"<<endl;
        break;
        };
    };
};
cout << turn << "2" << points << tileValue << t1 << endl;
cin >> s;
while(s != 'C' && 'E'){
        cout <<"invalid option, please press C to continue next turn, or E to end the game" << endl;
        cin >> s;
        if(s == 'E'){
            cout << "Thanks for playing!!!" << endl;
            break;
if(turn == 20){
    cout << "The maximum number of turns has been reached";
};
};
return 0;
};





