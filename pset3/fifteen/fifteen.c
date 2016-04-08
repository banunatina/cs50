/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void swap(int* a, int* b);
void draw(void);
bool move(int tile);
bool won(void);


int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // TODO
    int row;
    int col;
    int value = (d * d) - 1;
    // for each row
    for (row = 0; row < d; row++)
    {
      // for each column
      for (col = 0; col < d; col++)
      {
        board[row][col] = value;
        value--;
        // swaps 1 and 2 if the board is uneven
        if (d % 2 == 0)
        {
          board[d - 1][d - 2] = 2;
          board[d - 1][d - 3] = 1;
        }
      }
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO
    int row;
    int col;
    // prints the top boundary of board
    for (int c = 0; c < d; c++) 
    {
        printf("----");
    }
    printf("\n");
    // for every row
    
    for (row = 0; row < d; row++)
    {
      printf("|");
      // for each column
      for (col = 0; col < d; col++)
      {
        // if value doesn't exist, print _
        if (board[row][col] == 0)
        {
          printf(" _ ");
        }
        else
        {
        // else print value
          if (board[row][col] < 10) 
          {
            printf("  %i", board[row][col]);
          }
          else if (board[row][col] < 100)
          {
            printf(" %i", board[row][col]);  
          }
        }
         
        if (col == d - 1)
        {
           printf("|\n");
           for ( int k = 0; k < d; k++)
           {
                printf("----");   
           }
           printf("\n");
        } 
        else 
        {
          printf("|");
        }
      }
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // TODO
    int row;
    int col;
    int* empty_address;
    int* tile_address;
    // checks tile above, left, and right if empty
    for (col = 0; col < d; col++) 
    {
        for (row = 0; row < d; row++) 
        {
            // if we have found the tile
            if (board[col][row] == tile) 
            {
                tile_address = &board[col][row];
                // if empty, swap
                //check above tile if it's on the board
                if (row - 1 >= 0 && board[col][row - 1] == 0) 
                {
                    empty_address = &board[col][row - 1];
                    // do the swap
                    swap(empty_address, tile_address);
                    return true;
                }
                
                // check tile below
                if (row + 1 < d && board[col][row + 1] == 0)
                {
                    empty_address = &board[col][row + 1];
                    // do the swap
                    swap(empty_address, tile_address);
                    return true;
                }
                
                // check tile right
                if (col + 1 < d && board[col + 1][row] == 0)
                {
                    empty_address = &board[col + 1][row];
                    // do the swap
                    swap(empty_address, tile_address);
                    return true;
                }
                
                //check tile left
                if (col - 1 >= 0 && board[col - 1][row] == 0)
                {
                    empty_address = &board[col - 1][row];
                    // do the swap
                    swap(empty_address, tile_address);
                    return true;
                }
                
            }
        }
    }

    // else return false
    return false;
}

/*
 * HELPER SWAP FUNCTION
 * takes address to a and address to b
 */

void swap(int* a, int* b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}
/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // TODO
    // for each row and each column
    int row;
    int col;
    int i = 0;
    for (col = 0; col < d; col++)
    {
    // (except last row last column)
        for (row = 0; row < d; row++)
        {
      // if i is not the same as value
            i += 1;
            if (board[col][row] != i)
            {
                if (col != d - 1 && row != d - 1)
                {
                    return false;
                }
            }
        }
    }
    
    return true;
    
}
