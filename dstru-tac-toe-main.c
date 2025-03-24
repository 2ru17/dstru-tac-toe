/**
 * dstru-tac-toe-main.c
 * Contains the main function for the DSTRU-TAC-TOE game.
 * Authors: 2ru17, Janaquino08, Lance003
 * Date: March 2025
 */

 #include "dstru-tac-toe.c"

 /**
  * Main function for the DSTRU-TAC-TOE game
  * Handles game initialization, main loop, and result display
  */
 int main() {
     GameState game;
     Position movePosition;
     WinningPattern patterns[4];
     bool validInput = false;
     
     // Initialize the game
     initializeGame(&game);
     initializeSetC(patterns);
     initializeRelationT();
     
     // Game introduction
     printf("\n\n");
     printf("=======================================\n");
     printf("=          DSTRU-TAC-TOE             =\n");
     printf("=======================================\n");
     printf("A 4x4 Tic-Tac-Toe with Set Theory Implementation\n\n");
     printf("PLAYERS:\n");
     printf("  - Uno (X): Places X markers\n");
     printf("  - Dos (R): Removes any marker from the board\n");
     printf("  - Tres (O): Places O markers\n\n");
     
     printf("WINNING CONDITIONS:\n");
     printf("  - Uno wins: Creating a winning pattern with X markers\n");
     printf("  - Dos wins: If the board is filled with no winner\n");
     printf("  - Tres wins: Creating a winning pattern with O markers\n\n");
     
     printf("Press Enter to start...");
     getchar(); // Wait for user input before starting
     
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
                     printf("Invalid input. Please enter two numbers (e.g., 1 3).\n");
                     // Clear input buffer
                     while (getchar() != '\n');
                     printf("Try again: ");
                     continue;
                 }
                 
                 // Clear the rest of the line
                 int c;
                 while ((c = getchar()) != '\n' && c != EOF);
                 
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
                     printf("Invalid input. Please enter two numbers (e.g., 2 4).\n");
                     // Clear input buffer
                     while (getchar() != '\n');
                     printf("Try again: ");
                     continue;
                 }
                 
                 // Clear the rest of the line
                 int c;
                 while ((c = getchar()) != '\n' && c != EOF);
                 
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
             printf("Press Enter to continue...");
             getchar();
             continue;
         }
         
         // Check if game is over
         updateGameOver(&game);
     }
     
     // Display final game state
     displayGameState(&game);
     
     // Announce results with more detailed messages
     printf("\n=======================================\n");
     printf("=            GAME OVER               =\n");
     printf("=======================================\n\n");
     
     switch (game.result) {
         case 1:
             printf("Uno (X) wins! Successfully created a winning pattern.\n");
             break;
         case 2:
             printf("Dos (Removal) wins! The board is full with no winning pattern.\n");
             break;
         case 3:
             printf("Tres (O) wins! Successfully created a winning pattern.\n");
             break;
         default:
             printf("Game ended without a winner. This should not happen!\n");
     }
     
     printf("\nThanks for playing DSTRU-TAC-TOE!\n");
     printf("Press Enter to exit...");
     getchar(); // Wait for user to exit
     
     return 0;
 }
