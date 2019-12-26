/* ******************************************************************
 * Name: Mo Felonda
 * Wisc ID: felonda, 9073207327
 * OS: macOS Catalina
 * IDE (or text editor): CLion
 * Compiler: CMake
 * How long did the assignment take you to complete in minutes: 180
 * What other resources did you consult (copy and paste links below):
 * N/A
 * ******************************************************************/
#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <ctime>
#include <cstdio>
#include "CAVE.h"
using namespace std;

class PLAYER {
    vector<int> position;
    vector<int> nextSquare;
    vector<int> shot;
    enum FACING {
        LEFT, RIGHT, UP, DOWN
    };
    FACING facing;
    bool arrow = true;
    bool gold = false;
    bool eaten = false;
    bool fell = false;
    bool escaped = false;
    int x;
    int y;

public:
    PLAYER();
    vector<int> Get_Position();
    string Get_Facing();
    void Turn_Left();
    void Turn_Right();
    vector<int> Get_Next_Square();
    void Move_Forward();
    bool Pickup_Gold(CAVE &cave);
    bool Shoot_Arrow(CAVE &cave);
    void Climb_Ladder();
    bool Has_Arrow();
    bool Has_Gold();
    bool Update_Player_Status(CAVE &cave);
    bool Escaped();
    bool Eaten();
    bool Fell();
};
#endif //PLAYER_H