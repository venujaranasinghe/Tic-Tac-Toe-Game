#include <stdio.h>
#include <stdlib.h>

// ~Content of the header file~ 
// Function Declarations:
void computerizeGrid();             
void clean(); 
void printGrid();
int checkGrid();
void play(char currentPlayer, const char *filename, char **grid, int gridSize);
char checkWinner(int gridSize);
void theWinner(char winner);
void saveFile(const char *filename, char **grid, int gridSize);

// Setup the game:
char **grid;
int gridSize;
const char PLAYER1 = 'X'; // Constant representing the player 1
const char PLAYER2 = 'O'; // Constant representing the player 2

// Function to save the final state of grid in a text file:
void saveFile(const char *filename, char **grid, int gridSize) 
{
     FILE *file = fopen(filename, "a");

    if (file == NULL) 
    {
        printf("Not able to open the file!\n");
        return;
    }
    fprintf(file, "The states of Tic Tac Toe Game!\n");
    fprintf(file, "Grid size: %d\n", gridSize);

   // Writing the content of the grid:
    for (int i = 0; i < gridSize; i++) 
    {
        for (int j = 0; j < gridSize; j++) 
        {
            fprintf(file, "%c ", grid[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);

}

// Function to dynamically allocate the memory for the titactoe grid:
void computerizeGrid()
{
   grid = (char **)malloc(gridSize * sizeof(char *));
   for (int i = 0; i < gridSize; i++)
   {
      grid[i] = (char *)malloc(gridSize * sizeof(char));
      for (int j = 0; j < gridSize; j++)
      {
         grid[i][j] = ' ';
      }
   }
}

// Function to reset the grid by filling it with empty cells:
void clean()
{
   for (int i = 0; i < gridSize; i++)
   {
      for (int j = 0; j < gridSize; j++)
      {
         grid[i][j] = ' ';
      }
   }
}

// Function to print the grid for the game:
void printGrid()
{
   for (int i = 0; i < gridSize; i++)
   {
      for (int j = 0; j < gridSize; j++)
      {
         printf("| %c ", grid[i][j]);
         if (j < gridSize - 1)
         {
            printf("");
         }
         printf("|"); // Horizontal lines
      }
      printf("\n");
      if (i < gridSize - 1)
      {
         for (int k = 0; k < gridSize - 1; k++)
         {
            printf("-----"); // Vertical lines
         }
         printf("-----\n"); // Vertical lines
      }
   }
   printf("\n");
}

// Function to check if the grid s fully occupied:
int checkGrid()
{
   int freeSpaces = gridSize * gridSize;
   
   // Calculate the count of empty spaces:
   for (int i = 0; i < gridSize; i++)
   {
      for (int j = 0; j < gridSize; j++)
      {
         if (grid[i][j] != ' ')
         {
            freeSpaces--;
         }
      }
   }
   return freeSpaces;
}

// Function to process the player's movement:
void play(char currentPlayer, const char *filename, char **grid, int gridSize)
{
   int x, y;

   do
   {
      printf("Enter row # between 1-%d for Player %c: ", gridSize, currentPlayer);
      scanf("%d", &x);
      x--;
      printf("Enter column # between 1-%d for Player %c: ", gridSize, currentPlayer);
      scanf("%d", &y);
      y--;

      // Check the validity of the movement:
      if (x < 0 || x >= gridSize || y < 0 || y >= gridSize || grid[x][y] != ' ')
      {
         printf("Invalid move!\n");
      }
      else
      {
         grid[x][y] = currentPlayer;
         saveFile("it23225510.txt", grid, gridSize);
         break;
      }
   } while (grid[x][y] != ' ');
}

// Function to determine the winner:
char checkWinner(int gridSize) 
{
    // Check rows in the grid:
    for (int i = 0; i < gridSize; i++) 
    {
        int row = 1;
        for (int j = 1; j < gridSize; j++) 
        {
            if (grid[i][j] != grid[i][0] || grid[i][0] == ' ') 
            {
                row = 0;
                break;
            }
        }
        if (row == 1) 
        {
            return grid[i][0];
        }
    }

    // Check columns in the grid:
    for (int i = 0; i < gridSize; i++) 
    {
        int columns = 1;
        for (int j = 1; j < gridSize; j++) 
        {
            if (grid[j][i] != grid[0][i] || grid[0][i] == ' ')
            {
                columns = 0;
                break;
            }
        }
        if (columns == 1) 
        {
            return grid[0][i];
        }
    }

    // Check diagonals in the grid:
    int diagonal1 = 1;
    int diagonal2 = 1;
    for (int i = 1; i < gridSize; i++) 
    {
        if (grid[i][i] != grid[0][0] || grid[0][0] == ' ') 
        {
            diagonal1 = 0;
        }
        if (grid[i][gridSize - 1 - i] != grid[0][gridSize - 1] || grid[0][gridSize - 1] == ' ') 
        {
            diagonal2 = 0;
        }
    }
    if (diagonal1 == 1) 
    {
        return grid[0][0];
    }
    if (diagonal2 == 1) 
    {
        return grid[0][gridSize - 1];
    }

    return ' '; // There's no winner yet
}

// Function to print the winner of game:
void theWinner(char winner)
{
   if (winner == PLAYER1) 
   {
      printf("Player 1 Wins!");
   }
   else if (winner == PLAYER2)
   {
      printf("Player 2 Wins!");
   }
   else
   {
      printf("It's a Tie!");
   }
}

