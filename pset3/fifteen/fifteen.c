/**
 * fifteen.c
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
    FILE *file = fopen("log.txt", "w");
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
        int tile = get_int();
        
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
    // iterate over the grid
    for (int r = 0; r < d; r++)
    {
        for (int c = 0; c < d; c++)
        {
            // calculate the value of each cell with math
            board[r][c] = ((d * d) - (d * r) - c - 1);
        }
    }
    // initialize the blank at right bottom corener
    // give the blank a value of 0
    board[d - 1][d - 1] = 0;
    
    // if dimension is even, swap 1 and 2
    if (d % 2 == 0)
    {
        board[d - 1][d - 2] = 2;
        board[d - 1][d - 3] = 1;
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    clear();
    // iterate over the grid
    for (int r = 0; r < d; r++)
    {
        for (int c = 0; c < d; c++)
        {
            // if cell has 0, then it is blank
            // hence print "_"
            if (board[r][c] == 0)
            {
                printf("__   ");
            }
            // else print the respective element
            else
            {
                printf("%2i   ", board[r][c]);
            }
        }
        printf("\n\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    int blank_r;
    int blank_c;
    int to_swit_r;
    int to_swit_c;
    
    
    // iterate over the grid
    for (int r = 0; r < d; r++)
    {
        for (int c = 0; c < d; c++) 
        {
            // if cell is 0, then it is blank
            if (board[r][c] == 0)
            {
                // take coordinates of blank as 2 variables
                blank_r = r;
                blank_c = c;
            }
            
            if (board[r][c] == tile)
            {
                // take coordinates of to_shift as 2 variables
                to_swit_r = r;
                to_swit_c = c;
            }
        }
    }
    
    
    // only 2 cases possible for a valid shift
    // both have either same row or column
    
    // if row same
    if (blank_r == to_swit_r)
    {
        // check if difference in rows is 1 or -1
        // this signifies them being adjacent
        if (blank_c - to_swit_c == 1 || blank_c - to_swit_c == -1)
        {
            // if satisfied, then swap
            board[blank_r][blank_c] = board[to_swit_r][to_swit_c];
            board[to_swit_r][to_swit_c] = 0;
            return true;
        }
        else 
        {
            return false;
        }
    }
    // if column same
    else if (blank_c == to_swit_c)
    {
        // check if difference in rows is 1 or -1
        // this signifies them being adjacent
        if (blank_r - to_swit_r == 1 || blank_r - to_swit_r == -1)
        {
            // if satisfied, then swap
            board[blank_r][blank_c] = board[to_swit_r][to_swit_c];
            board[to_swit_r][to_swit_c] = 0;
            return true;
        }
        else 
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    if (board[d - 1][d - 1] != 0)
    {
        return false;
    }
    // iterate over the grid
    for (int r = 0; r < d; r++)
    {
        for (int c = 0; c < d; c++)
        {
            if (r == (d - 1) && c == (d - 1))
            {
                return true;
            }
            
            if (board[r][c] != ((d * r) + c + 1))
            {
                return false;
            }
        }
    }
    return true;
}
