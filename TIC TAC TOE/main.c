#include <stdio.h>

void displayBoard(char board[3][3]);
int checkWinner(char board[3][3]);
int checkDraw(char board[3][3]);

int main()
{
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    int player = 1;
    int choice;
    int row, col;
    int winner = 0;

    while (winner == 0 && checkDraw(board) == 0)
    {
        displayBoard(board);

        printf("Player %d (%c), enter your choice: ",
               player, player == 1 ? 'X' : 'O');

        scanf("%d", &choice);

        if (choice < 1 || choice > 9)
        {
            printf("Invalid choice! Try again.\n");
            continue;
        }

        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O')
        {
            printf("Position already occupied! Try again.\n");
            continue;
        }

        if (player == 1)
            board[row][col] = 'X';
        else
            board[row][col] = 'O';

        winner = checkWinner(board);

        if (winner == 1)
        {
            displayBoard(board);
            printf("Player %d wins!\n", player);
            break;
        }

        player = (player == 1) ? 2 : 1;
    }

    if (winner == 0)
    {
        displayBoard(board);
        printf("The game is a draw!\n");
    }

    return 0;
}


void displayBoard(char board[3][3])
{
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}


int checkWinner(char board[3][3])
{
    int i;

    /* Check rows */
    for (i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
        {
            return 1;
        }
    }

    /* Check columns */
    for (i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
        {
            return 1;
        }
    }

    /* Check main diagonal */
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
    {
        return 1;
    }

    /* Check other diagonal */
    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
    {
        return 1;
    }

    return 0;
}


int checkDraw(char board[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return 0;
            }
        }
    }

    return 1;
}