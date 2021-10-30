#ifndef MYGAME_H_INCLUDED
#define MYGAME_H_INCLUDED
#include "Player.h"
#include "Dice.h"
#include "Tile.h"
#include "Player.h"
#include "MyGameA.h"
#include "Turn.h"
#include <iostream>

using namespace std;

class MyGame:public MyGameA{
    public:
        Dice dice;
        char option{}, gameType{};
        int tiles{}, players{}, snakes{}, ladders{}, penalty{}, reward{},Turns{}, turno = 1;
        void start(){
            int cont_snakes = 0;
            int cont_ladders = 0;
            bool game = true;
            cout << "Elige una opcion \n A: Juego por Default   \n M: Juego Personalizado " << endl;
            cin >> option;
            if (option == 'M'){
                cout << "Ingrese el numero de casillas para el tablero: \n";
                cin >> tiles;
                cout << "Ingrese el numero de serpientes a colocar en el tablero: \n";
                cin >> snakes;
                cout << "Ingrese el numero de escaleras a colocar en el tablero: \n";
                cin >> ladders;
                cout << "Ingrese el numero de casillas que se deben retroceder si se cae en una serpiente: \n";
                cin >> penalty;
                cout << "Ingrese el numero de casillas adicionales que se avanzaran si se cae en una escalera: \n";
                cin >> reward;
                cout << "Ingrese el numero de jugadores \n";
                cin >> players;
                cout << "Ingrese le numero maximo de turnos para la simulacion del juego: \n";
                cin >> Turns;
                cout << "Ingrese el tipo de Juego: M) Manual  A) Automatico \n";
                cin >> gameType;
            }
            else{
                tiles = 30;
                snakes = 6;
                ladders = 6;
                penalty = 6;
                reward = 6;
                players = 2;
                Turns = 30;
            }
            for (int i = 0; i < tiles; i++){
                switch (rand() % 3){
                    case 0:
                        if (cont_snakes < snakes){
                            tile[i].type = 'S';
                            cont_snakes++;
                        }
                        else{
                            tile[i].type = 'N';
                        }
                        break;
                    case 1:
                        if (cont_snakes < ladders){
                            tile[i].type = 'L';
                            cont_ladders++;
                        }
                        else{
                            tile[i].type ='N';
                        }
                    default:
                        tile[i].type = 'N';
                        break;
                }
                tile[i].position = i + 1;
                tile[i].penalty= penalty;
                tile[i].reward = reward;
            };
            for (int i = 0; i < players; i++){
                player[i].id = i + 1;
                player[i].position = 1;
            };
            turno = 1;
            while (game){
                if (gameType == 'M'){
                    cout << "Press C to continue next turn, or E to end the game:";
                    cin >> option;
                    if (option == 'E'){
                        cout << "Thanks for playing!!!";
                        endgame(0, true);
                    }
                    else if(option == 'C'){
                        if (turn()){
                            game = false;
                    }
                    }
                }
                else{
                    if (turn()){
                        game = false;
                    };
                };
            }
        }
        bool turn(){
            int dice1;
            for (int i = 0; i < players; i++){
                dice1 = dice.GetDice();
                if (this->player[i].position + dice1 >= tiles || turno > Turns){
                    return endgame(i + 1, false);
                }
                else{
                    cout << endl << turno;
                    int a,b,c;
                    char d;
                    basic_string<char> e;
                    a = i+1;
                    b = player[1].position;
                    c = dice1;
                    player[i].position += dice1;
                    player[i].position += this->special(tile[player[i].position - 1].type);
                    d = tile[player[i].position - 1].type;
                    e = player[i].position;
                    char tipo = tile[player[i].position - 1].type;
                    Turn *t(a, b, c, d, e);
                    cout << t;
                }
            };
            turno++;
            return false;
        };
        bool endgame(int player, bool stop) const{
            if (stop){
                cout << "GAME OVER";
            }
            else {
                    if (turno == Turns) {
                        cout << "The maximum number of Turns has been reached...";
                    }
                    cout << "Player " << player << " wins!";
                }
            return true;
        }
        int special(char type){
            if (type == 'S'){
                return this->tile[0].penalty * -1;
            }
            else if (type == 'L'){
                return this->tile[0].penalty;
            }
            else{
                return 0;
            }
        }
};

#endif 
