#include <stdio.h>
#include <stdlib.h> // Declares memory allocation
#include <ctype.h>  // To transform the characters
#include "venuja.h" // Custom header file



int main()
{
    printf("\nWelcome to the Tic Tac Toe game!\n");

    char winner = ' ';
    char response = ' ';
    char currentPlayer = PLAYER1; // initialized to player 1

    do
    {
        winner = ' '; // reset the winner and response for a new game
        response = ' ';
        
        // Get the user input for the grid size:
        do
        {
        printf("\nEnter the size of the board (3 < Grid Size < 10): ");
        scanf("%d", &gridSize);

        if(gridSize < 3 || gridSize > 10)
        {
            printf("\nInvalid grid size. Please enter a size between 3 and 10.\n");
            continue;
        }
        } while (gridSize < 3 || gridSize > 10);

        computerizeGrid();
        clean();
        
        // Loop to countinue the game until there's a winner or no more free spaces in the grid:
        while(winner == ' ' && checkGrid() != 0)
        {
            

            play(currentPlayer,"it23225510.txt", grid, gridSize);
            printGrid();
            winner = checkWinner(gridSize);
            
            // Break the rule if there's a winner or no more free spaces:
            if( winner != ' ' || checkGrid() == 0)
            {
                break;
            }
            // Switch to the second player:
            currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;

            play(currentPlayer,"it23225510.txt", grid, gridSize);
            printGrid();
            winner = checkWinner(gridSize);
            if(winner != ' ' || checkGrid() == 0)
            {
                break;
            }

            currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;
        }

        printGrid();
        theWinner(winner);

        // Save the final state of the game as a text file:
        saveFile("it23225510.txt", grid, gridSize);

        // ask if the player wants to play again after the previous one ends:
        printf("\nWould you like to play again? (Y/N): ");
        scanf(" %c", &response);
        response = toupper(response);
    } while (response == 'Y');

    printf("Thanks for playing!");

    // Free the dynamically allocated memory for the grid:
    for(int i = 0; i < gridSize; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}