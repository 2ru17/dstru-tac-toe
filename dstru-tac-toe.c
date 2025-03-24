/**
 * dstru-tac-toe.c
 * Implementation file for DSTRU-TAC-TOE game
 * CCDSTRU '24-'25 Final Machine Project
 */

// *Last edited by: 2ru17*

#include "dstru-tac-toe.h"

/* Global variables */
WinningPattern setC[4];  /* Set C as defined in specs */
WinningPattern setW[4];  /* Set W = C - T */
int wCount = 0;          /* Count of winning patterns in W */


// HELPER FUNCTION
/**
 * Helper function to check if two values are equal
 * @param a First value
 * @param b Second value
 * @return true if values are equal, false otherwise
 */
// ASSIGNED TO: 2ru17
bool areEqual(int a, int b) {
    return a == b;
}

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
    // Initialize all counts to zero
    game->UnoCount = 0;
    game->TresCount = 0;
    game->freeCount = MAX_POSITIONS;  // Initialize free count to max
    
    // Initialize all positions as free
    int i, j, pos = 0;
    for (i = 1; i <= 4; i++) {
        for (j = 1; j <= 4; j++) {
            game->freePositions[pos].x = i;
            game->freePositions[pos].y = j;
            pos++;
        }
    }
    
    // Initialize system variables
    game->turn = true;
    game->go = false;
    game->over = false;
    game->result = 0;

    //ADDED BY LANCE, INITIALIZING Position Uno[], Position Dos[], Position Tres[]
    for (i = 0; i < MAX_POSITIONS; i++) {
        game->Uno[i].x = 0;
        game->Uno[i].y = 0;
        game->Dos[i].x = 0;
        game->Dos[i].y = 0;
        game->Tres[i].x = 0;
        game->Tres[i].y = 0;
    }
}
// old code: 
// void initializeGame(GameState *game) {
//     // TODO: Initialize game state according to System Initialization
//     game->UnoCount = 0;
//     game->DosCount = 0;
//     game->TresCount = 0;
    
//    game->turn = true;
//    game->go = false;
//    game->over = false;
// }

/**
 * Initialize set C (winning patterns)
 * C = { {(1,1),(1,2),(1,3),(1,4)}, {(1,1),(2,2),(3,3),(4,4)}, 
 *       {(1,4),(2,3),(3,2),(4,1)}, {(4,1),(4,2),(4,3),(4,4)} }
 * @param patterns Array to store the winning patterns
 */
// ASSIGNED TO: poginilance
void initializeSetC(WinningPattern patterns[]) {
    // TODO: Initialize set C
    for (int i = 0; i < 4; i++){
        patterns[0].positions[i].x = 1;
        patterns[0].positions[i].y = i + 1;
        patterns[1].positions[i].x = i + 1;
        patterns[1].positions[i].y = i + 1;
        patterns[2].positions[i].x = i + 1;
        patterns[2].positions[i].y = 4 - i;
        patterns[3].positions[i].x = 4;
        patterns[3].positions[i].y = i + 1;
    }
}

/**
 * Initialize relation T on set A
 * T is a relation on A that is reflexive, symmetric, antisymmetric, and transitive
 */
 // ASSIGNED TO: 2ru17
 void initializeRelationT() {
    /* 
     * For a relation to be both symmetric and antisymmetric, it must be the identity relation
     * (where each element is only related to itself), since:
     * - Symmetric: If a T b, then b T a
     * - Antisymmetric: If a T b and b T a, then a = b
     * 
     * Since the only way to satisfy both properties is when a = b, we'll define T
     * as the identity relation on A = {1, 2, 3, 4}
     * 
     * This means T = {(1,1), (2,2), (3,3), (4,4)}
     * 
     * NOTE: This doesn't require an actual data structure in our implementation
     * since we can check if two positions are related by T simply by checking if they're equal
     * in the isRelatedByT function. But I documented this for clarity.
     */
    
    /* 
     * Since the relation T will be used by isRelatedByT function which checks if two positions
     * are identical (same x and y coordinates), we don't need to explicitly store the relation.
     * 
     * This function serves to document the properties of T rather than
     * set up data structs.
     *
     * The relation T is defined implicitly as:
     * Two positions y(x1,1) and (x2,y2) are related by T if and only if x1 = x2 and y1 = y2.
     * 
     */
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
    // Check if position is in Uno set
    int i = 0;
    bool isFree = true;
        
    // Check if position is in Uno
    while (isFree && i < game->UnoCount) {
        if (game->Uno[i].x == pos.x && game->Uno[i].y == pos.y)
            isFree = false;
        else
            i++;
    }
    
    // Check if position is in Tres
    i = 0;
    while (isFree && i < game->TresCount) {
        if (game->Tres[i].x == pos.x && game->Tres[i].y == pos.y)
            isFree = false;
        else
            i++;
    }

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

    while (!isPresent && i < count)
        if (set[i].x == pos.x && set[i].y == pos.y)
            isPresent = true;
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
    set[*count] = pos;
    (*count)++;
}

/**
 * Remove position from a set
 * @param pos Position to remove
 * @param set Array of positions representing the set
 * @param count Pointer to the number of positions in the set
 */
// ASSIGNED TO: janaquino8
void removePositionFromSet(Position pos, Position set[], int *count) {
    int i = 0;  

    // Find the position in the set
    while (i < *count) {
        if (set[i].x == pos.x && set[i].y == pos.y)
            break;
        i++;
    }

    // If position was found (i < *count), remove it
    if (i < *count) {
        // Shift all elements after the removed one
        while (i < *count - 1) {
            set[i] = set[i + 1];
            i++;
        }
        (*count)--;
    }
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
    int i, j, ctr = 0;
    bool found;

    for (i = 0; i < count1; i++) {
        j = 0;
        found = false;
        
        while (!found && j < count2) {
            if (set2[j].x == set1[i].x && set2[j].y == set1[i].y) {
                found = true;
                ctr++;
            }
            j++;
        }
    }

    return ctr == count1;
}

/**
* Update the set F = P - (Uno U Tres)
* Recalculates the free positions based on current Uno and Tres sets
* @param game Pointer to the current game state
*/
// ASSIGNED TO: lance203
void updateFreePositions(GameState *game) {
    // TODO: Update free positions
    game->freeCount = 0;
    Position pos;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            pos.x = i;
            pos.y = j;
            if (isPositionFree(game, pos)) {
                game->freePositions[game->freeCount].x = pos.x;
                game->freePositions[game->freeCount].y = pos.y;
                game->freeCount++;
                }
            }           
        }
    }

/**
 * Check if positions are related by relation T
 * T is a relation on A that is reflexive, symmetric, antisymmetric, and transitive
 * @param pos1 First position
 * @param pos2 Second position
 * @return true if pos1 is related to pos2 by T, false otherwise
 */
// ASSIGNED TO: lance203
bool isRelatedByT(Position pos1, Position pos2) {
    // TODO: Implement relation T (reflexive, symmetric, antisymmetric, transitive)
    bool related;
    if (pos1.x == pos2.x && pos1.y == pos2.y)
        related = true;
    else
        related = false;
    return related;
}

/**
 * NextPlayerMove state transition for Uno
 * Applies when: (turn ∧ go ∧ pos ∈ F)
 * Results in: Uno = Uno ∪ {pos} ∧ turn = ¬turn ∧ go = ¬go
 * @param game Pointer to the current game state
 * @param pos The position to occupy
 * @return true if move was successful, false otherwise
 */
// ASSIGNED TO: lance203
bool unoMove(GameState *game, Position pos) {
    bool moved;
    if (game->turn == true && game->go == true && isPositionValid(pos) == true && isPositionFree(game, pos) == true){
                addPositionToSet(pos, game->Uno, &(game->UnoCount));
                game->turn = false;
                game->go = false;
                moved = true;
            }
    else
        moved = false;
    
    return moved;
}

/**
 * NextPlayerMove state transition for Tres
 * Applies when: (turn ∧ ¬go ∧ pos ∈ F)
 * Results in: Tres = Tres ∪ {pos} ∧ go = ¬go
 * @param game Pointer to the current game state
 * @param pos The position to occupy
 * @return true if move was successful, false otherwise
 */
// ASSIGNED TO: lance203
bool tresMove(GameState *game, Position pos) {
    // TODO: Implement Tres move
    bool moved;
    if (game->turn == true && game->go == false && isPositionValid(pos) == true && isPositionFree(game, pos) == true){
                addPositionToSet(pos, game->Tres, &(game->TresCount));
                game->go = true;
                moved = true;
            }
    else
        moved = false;
    
    return moved;
}

/**
 * NextPlayerMove state transition for position removal
 * Applies when: (¬turn ∧ pos ∈ Uno ∪ Tres)
 * Results in: Uno = Uno − {pos} ∧ Tres = Tres − {pos} ∧ turn = ¬turn
 * @param game Pointer to the current game state
 * @param pos The position to remove
 * @return true if removal was successful, false otherwise
 */
// ASSIGNED TO: lance203
bool removePosition(GameState *game, Position pos) {
    // TODO: Implement position removal
    //IF WE WILL FOLLOW THE CONCEPT OF TRES & UNO ARE IN ONE SIMILAR POSITION, USE VER 1
    //IF WE WILL FOLLOW THE CONCEPT OF DOS TAKES EITHER TRES OR UNO, USE VER 2

    bool removed;
    /*VER 1
    if (game->turn == false && game->go == false){
        for (int i = 0; i < MAX_POSITIONS; i++){
            if (game->Uno[i].x == game->Tres[i].x && game->Uno[i].y == game->Tres[i].y){
                game->Uno[i].x = 0;
                game->Tres[i].x = 0;
                game->Uno[i].y = 0;
                game->Tres[i].y = 0;
                game->turn == true;
                removed = true;
            }
            else
                removed = false;
        }    
    }

    else
        removed = false;
    */
    
    //VER 2
    if (game->turn == false && game->go == false){
            if (isPositionInSet(pos, game->Uno, game->UnoCount) == true){
                removePositionFromSet(pos, game->Uno, &(game->UnoCount));
                addPositionToSet(pos, game->Dos, &(game->DosCount));
                game->turn = true;
                removed = true;
            }
            
            else if (isPositionInSet(pos, game->Tres, game->TresCount) == true){
                removePositionFromSet(pos, game->Tres, &(game->TresCount));
                addPositionToSet(pos, game->Dos, &(game->DosCount));
                game->turn = true;
                removed = true;
            }

            else
                removed = false;
    }
    else
        removed = false;
    return removed;
}

/**
 * Process NextPlayerMove based on current system state
 * Determines which state transition to apply based on current state
 * @param game Pointer to the current game state
 * @param pos The position selected
 * @return true if the move was processed successfully, false otherwise
 */
// ASSIGNED TO: lance203
bool processMove(GameState *game, Position pos) {
    // TODO: Process move according to system state
    bool process;
    if (tresMove(game, pos) == true || unoMove(game, pos) == true || removePosition(game, pos) == true)
        process = true;
    else
        process = false;
    return process;
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
    // We need to check if any winning pattern in set W is a subset of the player's positions
    for (int i = 0; i < wCount; i++) {
        bool isWinning = true;
        
        // Check if all positions in this winning pattern are contained in player's positions
        for (int j = 0; j < WINNING_SET_SIZE; j++) {
            bool found = false;
            for (int k = 0; k < count; k++) {
                if (areEqual(setW[i].positions[j].x, positions[k].x) && 
                    areEqual(setW[i].positions[j].y, positions[k].y)) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                isWinning = false;
                break;
            }
        }
        if (isWinning) {
            return true;
        }
    }
    
    return false;
}
/**
 * Check if F is empty
 * F is empty when all positions are occupied by either Uno or Tres
 * @param game The current game state
 * @return true if F is empty, false otherwise
 */
// ASSIGNED TO: 2ru17
bool isFEmpty(const GameState *game) {
    // F is empty when the sum of Uno and Tres counts equals MAX_POSITIONS (16)
    return (game->UnoCount + game->TresCount == MAX_POSITIONS);
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
    // Check if Uno has won
    bool unoWins = checkWinCondition(game, game->Uno, game->UnoCount);
    
    // Check if Tres has won
    bool tresWins = checkWinCondition(game, game->Tres, game->TresCount);
    
    // Check if F is empty (all positions occupied)
    bool fEmpty = isFEmpty(game);
    
    // Update over and result according to the rules
    game->over = (unoWins || tresWins || fEmpty);
    if (game->over) {
        if (unoWins) {
            game->result = 1; // Uno Wins
        } else if (fEmpty) {
            game->result = 2; // Dos Wins
        } else if (tresWins) {
            game->result = 3; // Tres Wins
        }
    } else {
        game->result = 0; // Game is still ongoing
    }
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
    // Initialize the count to 0
    *wCount = 0;
    
    // For each pattern in C
    for (int i = 0; i < 4; i++) {
        bool includePattern = true;
        // Check if all positions in this pattern are related by T
        for (int j = 0; j < WINNING_SET_SIZE; j++) {
            for (int k = j + 1; k < WINNING_SET_SIZE; k++) {
                // For a position to be related by T, they must be the same position
                // If any two positions in the pattern are NOT the same, we include the pattern in W
                if (C[i].positions[j].x != C[i].positions[k].x || 
                    C[i].positions[j].y != C[i].positions[k].y) {
                    includePattern = false;
                    break;
                }
            }
            if (!includePattern) break;
        }
        
        // If the pattern has different positions (not all related by T), add to W
        if (!includePattern) {
            W[*wCount] = C[i];
            (*wCount)++;
        }
    }
}

/**
 * Assigns placements in grid depending on the position of each player
 * @param Player Array of the positions occupied by the player
 * @param count The number of occupied positions of the player
 * @param grid The grid of the placements of each player
 * @param token The token representing the number of the player
 */
// ASSIGNED TO: janaquino8
void printInGrid(Position Player[], int count, int grid[][GRID_SIZE], int token) {
    int i;

    for (i = 0; i < count; i++) {
        // Adjusting indices for 0-based array access
        int x = Player[i].x - 1;
        int y = Player[i].y - 1;
        
        if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) {
            grid[x][y] = token;
        }
    }
}
// old code:
// void printInGrid(Position Player[], int count, int grid[][GRID_SIZE], int token) {
//     int i, x, y;

//     for (i = 0; i < count; i++)
//     {
//         x = Player[i].x;
//         y = Player[i].y;

//         grid[x][y] = token;
//     }
// }

/**
 * Display the current game state
 * Shows the grid with occupied positions and current game status
 * @param game The current game state
 */
// ASSIGNED TO: janaquino8
void displayGameState(const GameState *game) {
    int i, j;
    int grid[GRID_SIZE][GRID_SIZE] = {0};

    printInGrid(game->Uno, game->UnoCount, grid, 1);
    printInGrid(game->Tres, game->TresCount, grid, 3);

    printf("\n=== CURRENT GAME STATE ===\n\n");
    
    // Print column headers
    printf("    ");
    for (j = 1; j <= GRID_SIZE; j++) {
        printf(" %d  ", j);
    }
    printf("\n");
    
    // Print grid
    for (i = 0; i < GRID_SIZE; i++) {
        // Print row number
        printf(" %d  ", i + 1);
        
        for (j = 0; j < GRID_SIZE; j++) {
            char symbol;
            switch(grid[i][j]) {
                case 1: symbol = 'X'; break;  // Uno
                case 3: symbol = 'O'; break;  // Tres
                default: symbol = ' '; break; // Empty
            }
            printf("[%c]", symbol);
            
            if (j < GRID_SIZE - 1)
                printf(" ");
        }
        printf("\n");
        
        if (i < GRID_SIZE - 1)
            printf("    ---------------\n");  // Improved readability
    }
    
    printf("\nGame Status:\n");
    printf("Turn: %s\n", game->turn ? "Player's Turn" : "Removal");
    printf("Go: %s\n", game->go ? "Uno's Turn" : "Tres's Turn");
    printf("Over: %s\n", game->over ? "Yes" : "No");
    
    if (game->over) {
        printf("Result: ");
        switch (game->result) {
            case 1: printf("Uno Wins!\n"); break;
            case 2: printf("Dos Wins!\n"); break;
            case 3: printf("Tres Wins!\n"); break;
            default: printf("Undetermined\n"); break;
        }
    }
    printf("\n");
}
