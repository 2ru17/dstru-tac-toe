/**
 * dstru-tac-toe.c
 * Implementation file for DSTRU-TAC-TOE game
 * CCDSTRU '24-'25 Final Machine Project
 */

// *Last edited by: 2ru17*
// *Time edited (mm/dd/yy-hhmm): 03/20/25-1510*

#include "dstru-tac-toe.h"

/* Global variables */
WinningPattern setC[4];  /* Set C as defined in specs */
WinningPattern setW[4];  /* Set W = C - T */
int wCount = 0;          /* Count of winning patterns in W */

/**
* Initialize the system variables as per specifications
 * Follows the System Initialization rules:
 * - Uno = ∅
 * - Dos = ∅
 * - Tres = ∅
 * - turn = true
 * - go = false
 * - over = false
 * @param game Pointer to the game state to initialize
 */
// ASSIGNED TO: janaquino8
void initializeGame(GameState *game) {
     // TODO: Initialize game state according to System Initialization
     game->UnoCount = 0;
     game->DosCount = 0;
     game->TresCount = 0;
     
    game->turn = true;
    game->go = false;
    game->over = false;
}

/**
 * Initialize set C (winning patterns)
 * C = { {(1,1),(1,2),(1,3),(1,4)}, {(1,1),(2,2),(3,3),(4,4)}, 
 *       {(1,4),(2,3),(3,2),(4,1)}, {(4,1),(4,2),(4,3),(4,4)} }
 * @param patterns Array to store the winning patterns
 */
// ASSIGNED TO: poginilance
void initializeSetC(WinningPattern patterns[]) {
    // TODO: Initialize set C
}

/**
 * Initialize relation T on set A
 * T is a relation on A that is reflexive, symmetric, antisymmetric, and transitive
 */
// ASSIGNED TO: 2ru17
void initializeRelationT() {
    // TODO: Initialize relation T
}

/**
* Check if a position is valid (x,y in set A)
* A position is valid if both x and y are in set A: {1, 2, 3, 4}
* @param pos The position to check
* @return true if position is valid, false otherwise
*/
// ASSIGNED TO: janaquino8
bool isPositionValid(Position pos) {
    // TODO: Check if position is valid
    if (pos.x >= 1 && pos.x <= 4 && pos.y >= 1 && pos.y <= 4)
        return true;
    else
        return false;
}

/**
 * Check if a position is in set F (free positions)
 * A position is free if it's not in Uno or Tres
 * F = P − (Uno ∪ Tres)
 * @param game The current game state
 * @param pos The position to check
 * @return true if position is free, false otherwise
 */
// ASSIGNED TO: janaquino8
bool isPositionFree(const GameState *game, Position pos) {
    // TODO: Check if position is free
    int i = 0,
        j = 0;
        bool isFree = true;
        
    while (isFree && i < game->UnoCount)
        if (game->Uno[i].x == pos.x && game->Uno[i].y == pos.y)
            isFree = false;
        else
            i++;
    
    while (isFree && j < game->DosCount)
        if (game->Dos[j].x == pos.x && game->Dos[j].y == pos.y)
            isFree = false;
        else
            j++;

    return isFree;
}

/**
 * Check if position is in a set
 * @param pos Position to check
 * @param set Array of positions representing the set
 * @param count Number of positions in the set
 * @return true if position is in set, false otherwise
 */
// ASSIGNED TO: janaquino8
bool isPositionInSet(Position pos, Position set[], int count) {
    // TODO: Check if position is in set
    int i = 0;
    bool isPresent = false;

    while (isPresent == false && i < count)
        if (set[i].x == pos.x && set[i].y == pos.y)
            isPresent == true;
        else
            i++;

    return isPresent;
}

/**
 * Add position to a set
 * @param pos Position to add
 * @param set Array of positions representing the set
 * @param count Pointer to the number of positions in the set
 */
// ASSIGNED TO: janaquino8
void addPositionToSet(Position pos, Position set[], int *count) {
    // TODO: Add position to set
}

/**
 * Remove position from a set
 * @param pos Position to remove
 * @param set Array of positions representing the set
 * @param count Pointer to the number of positions in the set
 */
// ASSIGNED TO: janaquino8
void removePositionFromSet(Position pos, Position set[], int *count) {
    // TODO: Remove position from set
}

/**
 * Check if set1 is a subset of set2
 * @param set1 First set (array of positions)
 * @param count1 Number of positions in set1
 * @param set2 Second set (array of positions)
 * @param count2 Number of positions in set2
 * @return true if set1 is a subset of set2, false otherwise
 */
// ASSIGNED TO: janaquino8
bool isSubset(Position set1[], int count1, Position set2[], int count2) {
    // TODO: Check if set1 is subset of set2
    int i = 0,
        j = 0,
        ctr = 0;

    return 999;
}

/**
* Update the set F = P - (Uno U Tres)
* Recalculates the free positions based on current Uno and Tres sets
* @param game Pointer to the current game state
*/
// ASSIGNED TO: poginilance
void updateFreePositions(GameState *game) {
    // TODO: Update free positions
}

/**
 * Check if positions are related by relation T
 * T is a relation on A that is reflexive, symmetric, antisymmetric, and transitive
 * @param pos1 First position
 * @param pos2 Second position
 * @return true if pos1 is related to pos2 by T, false otherwise
 */
// ASSIGNED TO: poginilance
bool isRelatedByT(Position pos1, Position pos2) {
    // TODO: Implement relation T (reflexive, symmetric, antisymmetric, transitive)
    return 999;
}

/**
 * NextPlayerMove state transition for Uno
 * Applies when: (turn ∧ go ∧ pos ∈ F)
 * Results in: Uno = Uno ∪ {pos} ∧ turn = ¬turn ∧ go = ¬go
 * @param game Pointer to the current game state
 * @param pos The position to occupy
 * @return true if move was successful, false otherwise
 */
// ASSIGNED TO: poginilance
bool unoMove(GameState *game, Position pos) {
    // TODO: Implement Uno move
    return 999;
}

/**
 * NextPlayerMove state transition for Tres
 * Applies when: (turn ∧ ¬go ∧ pos ∈ F)
 * Results in: Tres = Tres ∪ {pos} ∧ go = ¬go
 * @param game Pointer to the current game state
 * @param pos The position to occupy
 * @return true if move was successful, false otherwise
 */
// ASSIGNED TO: poginilance
bool tresMove(GameState *game, Position pos) {
    // TODO: Implement Tres move
    return 999;
}

/**
 * NextPlayerMove state transition for position removal
 * Applies when: (¬turn ∧ pos ∈ Uno ∪ Tres)
 * Results in: Uno = Uno − {pos} ∧ Tres = Tres − {pos} ∧ turn = ¬turn
 * @param game Pointer to the current game state
 * @param pos The position to remove
 * @return true if removal was successful, false otherwise
 */
// ASSIGNED TO: poginilance
bool removePosition(GameState *game, Position pos) {
    // TODO: Implement position removal
    return 999;
}

/**
 * Process NextPlayerMove based on current system state
 * Determines which state transition to apply based on current state
 * @param game Pointer to the current game state
 * @param pos The position selected
 * @return true if the move was processed successfully, false otherwise
 */
// ASSIGNED TO: poginilance
bool processMove(GameState *game, Position pos) {
    // TODO: Process move according to system state
    return 999;
}

/**
 * Check if a player's positions contain a winning pattern from set W = C - T
 * @param game The current game state
 * @param positions Array of positions occupied by the player
 * @param count Number of positions in the array
 * @return true if player has won, false otherwise
 */
// ASSIGNED TO: 2ru17
bool checkWinCondition(const GameState *game, Position positions[], int count) {
    // TODO: Check win condition
    return 999;
}

/**
 * Check if F is empty
 * F is empty when all positions are occupied by either Uno or Tres
 * @param game The current game state
 * @return true if F is empty, false otherwise
 */
// ASSIGNED TO: 2ru17
bool isFEmpty(const GameState *game) {
    // TODO: Check if F is empty
    return 999;
}

/**
 * Update over variable and determine result
 * over ↔ (Uno ∈ W ∨ Tres ∈ W ∨ F = ∅)
 * result ∈ {Uno Wins, Dos Wins, Tres Wins}
 * (over ∧ Uno ∈ W) → result = Uno Wins
 * (over ∧ F = ∅) → result = Dos Wins
 * (over ∧ Tres ∈ W) → result = Tres Wins
 * @param game Pointer to the current game state
 */
// ASSIGNED TO: 2ru17
void updateGameOver(GameState *game) {
    // TODO: Update game over status
}

/**
 * Calculate set W = C - T
 * W contains the winning patterns
 * @param C Array of winning patterns in set C
 * @param W Output array for calculated set W
 * @param wCount Pointer to store the count of patterns in W
 */
// ASSIGNED TO: 2ru17
 void calculateSetW(WinningPattern C[], WinningPattern W[], int *wCount) {
    // TODO: Calculate set W = C - T
}

/**
 * Display the current game state
 * Shows the grid with occupied positions and current game status
 * @param game The current game state
 */
// ASSIGNED TO: janaquino8
void displayGameState(const GameState *game) {
    // TODO: Display game state
}
