// Contains the main function for the DSTRU-TAC-TOE game.
// Authors: 2ru17, Janaquino08, Lance003
// Date: March 2025

#include "dstru-tac-toe.h"

int main() {
    GameState game;
    Position movePosition;
    WinningPattern patterns[4]; // FIXED: Changed to 4 as there are only 4 winning patterns defined
    bool validInput = false;
    
    // Initialize the game
    initializeGame(&game);
    initializeSetC(patterns);
    initializeRelationT();
    
    // Game introduction
    printf("=== DSTRU-TAC-TOE ===\n");
    printf("4x4 Tic-Tac-Toe with Set Theory Implementation\n");
    printf("Players: Uno (X), Dos (removal), Tres (O)\n\n");
    
    // Main game loop
    while (!game.over) {
        // Display current game state
        displayGameState(&game);
        
        // Determine current player and prompt for move
        if (game.turn) {
            // Player's turn to place a marker
            if (game.go) {
                printf("Uno's turn (X). Enter position (row column): ");
            } else {
                printf("Tres's turn (O). Enter position (row column): ");
            }
            
            validInput = false;
            while (!validInput) {
                if (scanf("%d %d", &movePosition.x, &movePosition.y) != 2) {
                    printf("Invalid input. Please enter two numbers.\n");
                    // Clear input buffer
                    while (getchar() != '\n');
                    continue;
                }
                
                // Check if position is valid and free
                if (!isPositionValid(movePosition)) {
                    printf("Invalid position. Rows and columns must be between 1 and 4.\n");
                } else if (!isPositionFree(&game, movePosition)) {
                    printf("Position already occupied. Choose another position.\n");
                } else {
                    validInput = true;
                }
                
                if (!validInput) {
                    printf("Try again: ");
                }
            }
        } else {
            // Dos's turn to remove a position
            printf("Dos's turn (removal). Enter position to remove (row column): ");
            
            validInput = false;
            while (!validInput) {
                if (scanf("%d %d", &movePosition.x, &movePosition.y) != 2) {
                    printf("Invalid input. Please enter two numbers.\n");
                    // Clear input buffer
                    while (getchar() != '\n');
                    continue;
                }
                
                // Check if position is valid and can be removed
                if (!isPositionValid(movePosition)) {
                    printf("Invalid position. Rows and columns must be between 1 and 4.\n");
                } else if (isPositionFree(&game, movePosition)) {
                    printf("Position is already free. Choose an occupied position.\n");
                } else {
                    validInput = true;
                }
                
                if (!validInput) {
                    printf("Try again: ");
                }
            }
        }
        
        // Process the move
        if (!processMove(&game, movePosition)) {
            printf("Invalid move. Please try again.\n");
            continue;
        }
        
        // Check if game is over
        updateGameOver(&game);
    }
    
    // Display final game state
    displayGameState(&game);
    
    // Announce results
    switch (game.result) {
        case 1:
            printf("Uno wins!\n");
            break;
        case 2:
            printf("Dos wins!\n");
            break;
        case 3:
            printf("Tres wins!\n");
            break;
        default:
            printf("Game ended without a winner.\n");
    }
    
    return 0;
}