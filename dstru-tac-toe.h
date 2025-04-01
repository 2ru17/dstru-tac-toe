/**
 * dtru-tac-toe.h
 * Header file for DSTRU-TAC-TOE game
 * CCDSTRU '24-'25 Final Machine Project
 */
// *Last edited by: janaquino8*

#ifndef DSTRU_TAC_TOE_H
#define DSTRU_TAC_TOE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Constants */
#define GRID_SIZE 4
#define WINNING_SET_SIZE 4
#define MAX_POSITIONS 16  /* Total positions in the grid (4x4) */

/* Position structure representing (x,y) in set P: A × A */
typedef struct {
    int x;  /* Row (1-4) */
    int y;  /* Column (1-4) */
} Position;

/* Game State Structure */
typedef struct {
    /* Sets of positions */
    Position Uno[MAX_POSITIONS];     /* Positions occupied by Uno */
    int UnoCount;                    /* Number of positions in Uno */
    Position Dos[MAX_POSITIONS];     /* Positions occupied by Dos */
    int DosCount;                    /* Number of positions in Dos */
    Position Tres[MAX_POSITIONS];    /* Positions occupied by Tres */
    int TresCount;                   /* Number of positions in Tres */
    Position freePositions[MAX_POSITIONS];  /* Free positions F (F = P - (Uno U Tres)) */
    int freeCount;                   /* Number of free positions */
    
    /* System variables as defined in specs */
    bool turn;       /* true for player's turn, false for removal */
    bool go;         /* true for Uno's turn, false for Tres's turn */
    bool over;       /* true when game ends */
    int result;      /* 1 = Uno Wins, 2 = Dos Wins, 3 = Tres Wins, 0 = ongoing */
} GameState;

/* Winning Pattern Structure (elements of set C) */
typedef struct {
    Position positions[WINNING_SET_SIZE];
} WinningPattern;

/*********************************************
 * INITIALIZATION AND SETUP FUNCTIONS
 *********************************************/
void initializeGame(GameState *game);
void initializeSetC(WinningPattern patterns[]);
void initializeRelationT();

/*********************************************
 * SET OPERATIONS AND POSITION FUNCTIONS
 *********************************************/
bool areEqual(int a, int b);
bool isPositionValid(Position pos);
bool isPositionFree(const GameState *game, Position pos);
bool isPositionInSet(Position pos, Position set[], int count);
void addPositionToSet(Position pos, Position set[], int *count);
void removePositionFromSet(Position pos, Position set[], int *count);
bool isSubset(Position set1[], int count1, Position set2[], int count2);
void updateFreePositions(GameState *game);
bool isRelatedByT(Position pos1, Position pos2);

/*********************************************
 * GAME STATE TRANSITION FUNCTIONS
 *********************************************/
bool unoMove(GameState *game, Position pos);
bool tresMove(GameState *game, Position pos);
bool removePosition(GameState *game, Position pos);
bool processMove(GameState *game, Position pos);

/*********************************************
 * GAME CONDITION AND OUTCOME FUNCTIONS
 *********************************************/
bool checkWinCondition(const GameState *game, Position positions[], int count);
bool isFEmpty(const GameState *game);
void updateGameOver(GameState *game);
void calculateSetW(WinningPattern C[], WinningPattern W[], int *wCount);

/*********************************************
 * DISPLAY AND USER INTERFACE FUNCTIONS
 *********************************************/
void printInGrid(const Position Player[], int count, int grid[][GRID_SIZE], int token);
void displayGameState(const GameState *game);

#endif /* DSTRU_TAC_TOE_H */
