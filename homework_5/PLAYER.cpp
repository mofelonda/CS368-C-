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
#include "CAVE.h"
#include "PLAYER.h"
using namespace std;

/**
 * Constructor; initializes player position.
 */
PLAYER::PLAYER() {
    x = 1;
    y = 1;
    position = {x, y}; // Begin at square (1,1)
    facing = RIGHT; // Begin facing to the right
}

/**
 * Returns the coordinates of the player's current position.
 *
 * @return vector of the player position
 */
vector<int> PLAYER::Get_Position() {
    return position;
}

/**
 * Returns a string with the word "left", "right", "up", or "down."
 */
string PLAYER::Get_Facing() {
    switch (facing) {
        case LEFT:
            return "left";
        case RIGHT:
            return "right";
        case UP:
            return "up";
        case DOWN:
            return "down";
        default:
            return "";
    }
}

/**
 * Turns the player 90 degrees counter-clockwise.
 */
void PLAYER::Turn_Left() {
    switch (facing) {
        case LEFT:
            facing = DOWN;
            break;
        case RIGHT:
            facing = UP;
            break;
        case UP:
            facing = LEFT;
            break;
        case DOWN:
            facing = RIGHT;
            break;
        default:
            break;
    }
}

/**
 * Turns the player 90 degrees clockwise.
 */
void PLAYER::Turn_Right() {
    switch (facing) {
        case LEFT:
            facing = UP;
            break;
        case RIGHT:
            facing = DOWN;
            break;
        case UP:
            facing = RIGHT;
            break;
        case DOWN:
            facing = LEFT;
            break;
        default:
            break;
    }
}

/**
 * Returns the coordinates of the square in front of the player.
 *
 * @return vector of the next square
 */
vector<int> PLAYER::Get_Next_Square() {
    nextSquare = position;
    switch (facing) {
        case LEFT:
            nextSquare[1]--;
            break;
        case RIGHT:
            nextSquare[1]++;
            break;
        case UP:
            nextSquare[0]--;
            break;
        case DOWN:
            nextSquare[0]++;
            break;
        default:
            break;
    }
    return nextSquare;
}

/**
 * Changes the position of the player when he or she steps forward one square.
 */
void PLAYER::Move_Forward() {
    position = Get_Next_Square();
    x = position[0];
    y = position[1];
}

/**
 * If there is gold in the player square, then it is picked up and removed from the data structure.
 *
 * @param cave data structure
 * @return true if gold is picked up
 */
bool PLAYER::Pickup_Gold(CAVE &cave) {
    if (cave.Square_Contains_Gold(position)) {
        gold = true; // Pick up the gold
        cave.Remove_Gold(position); // Remove gold from data structure
        return true;
    }
    return false;
}

/**
 * The player shoots their only arrow in the direction they are facing.
 * If the arrow hits the wumpus, the wumpus is killed.
 *
 * @param cave data structure
 * @return true if the wumpus is killed
 * @return false if the wumpus is alive or the player's arrow has already been shot
 */
bool PLAYER::Shoot_Arrow(CAVE &cave) {
    if (!arrow) { // Stop here if player's arrow has already been shot
        return false;
    }
    arrow = false; // Arrow has been shot
    shot = position; // Arrow begins at player
    switch (facing) {
        case LEFT:
            shot[1]--; // Begin loop at square in front of player
            while (cave.Is_Square_Valid(shot)) {
                if (cave.Shoot_Square(shot)) {
                    return true; // Wumpus has been killed
                }
                shot[1]--; // Arrow still flying, continue loop
            }
            break;
        case RIGHT:
            shot[1]++; // Begin loop at square in front of player
            while (cave.Is_Square_Valid(shot)) {
                if (cave.Shoot_Square(shot)) {
                    return true; // Wumpus has been killed
                }
                shot[1]++; // Arrow still flying, continue loop
            }
            break;
        case UP:
            shot[0]--; // Begin loop at square in front of player
            while (cave.Is_Square_Valid(shot)) {
                if (cave.Shoot_Square(shot)) {
                    return true; // Wumpus has been killed
                }
                shot[0]--; // Arrow still flying, continue loop
            }
            break;
        case DOWN:
            shot[0]++; // Begin loop at square in front of player
            while (cave.Is_Square_Valid(shot)) {
                if (cave.Shoot_Square(shot)) {
                    return true; // Wumpus has been killed
                }
                shot[0]++; // Arrow still flying, continue loop
            }
            break;
    }
    return false; // Arrow has hit the wall, so the wumpus is alive
}

/**
 * Changes the player's status from alive to escaped.
 */
void PLAYER::Climb_Ladder() {
    escaped = true;
}

/**
 * Returns status of arrow.
 *
 * @return true if player still has their arrow
 */
bool PLAYER::Has_Arrow() {
    return arrow;
}

/**
 * Returns status of gold.
 *
 * @return true if gold has been picked up
 */
bool PLAYER::Has_Gold() {
    return gold;
}

/**
 *  If the player is in a square with a living wumpus then the player is eaten.
 *  If the player is in a square with a pit then the player falls.
 *  If the player is still alive at the end of this turn the function returns true.
 *
 *  @param cave data structure
 *  @return true if the player is still alive
 *  @return false if the player has been eaten or has fallen
 */
bool PLAYER::Update_Player_Status(CAVE &cave) {
    if (cave.Square_Contains_Living_Wumpus(position)) {
        eaten = true;
        return false; // Player has been eaten
    }
    if (cave.Square_Contains_Pit(position)) {
        fell = true;
        return false; // Player has fallen to their death
    }
    return true; // Player is still alive
}

/**
 * Returns status of escaped.
 *
 * @return true if player has climbed the ladder
 */
bool PLAYER::Escaped() {
    return escaped;
}

/**
 * Returns status of eaten.
 *
 * @return true if player has been eaten
 */
bool PLAYER::Eaten() {
    return eaten;
}

/**
 * Returns status of fell.
 *
 * @return true if player has fallen
 */
bool PLAYER::Fell() {
    return fell;
}