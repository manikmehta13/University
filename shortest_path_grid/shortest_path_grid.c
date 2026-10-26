#include <stdio.h>

#define ROWS 10
#define COLS 10
#define MAX_CELLS (ROWS * COLS)

char grid[ROWS][COLS + 1] = {
    "S...#.....",
    ".##.#.###.",
    "...#...#..",
    "##.###.#..",
    "...#...#..",
    ".#...#....",
    ".###.####.",
    "...#......",
    ".#...###..",
    ".....#...E"
};

int visited[ROWS][COLS];
int parent[ROWS][COLS];
int queue[MAX_CELLS];
int path[ MAX_CELLS ];

int rowMove[4] = {-1, 1, 0, 0};
int colMove[4] = {0, 0, -1, 1};

int isValid(int row, int col)
{
    return row >= 0 && row < ROWS &&
           col >= 0 && col < COLS &&
           grid[row][col] != '#' &&
           !visited[row][col];
}

int findStart(int *startRow, int *startCol)
{
    int r, c;

    for (r = 0; r < ROWS; r++)
    {
        for (c = 0; c < COLS; c++)
        {
            if (grid[r][c] == 'S')
            {
                *startRow = r;
                *startCol = c;
                return 1;
            }
        }
    }

    return 0;
}

int findEnd(int *endRow, int *endCol)
{
    int r, c;

    for (r = 0; r < ROWS; r++)
    {
        for (c = 0; c < COLS; c++)
        {
            if (grid[r][c] == 'E')
            {
                *endRow = r;
                *endCol = c;
                return 1;
            }
        }
    }

    return 0;
}

int shortestPath(int startRow, int startCol, int endRow, int endCol)
{
    int front = 0, rear = 0;
    int start = startRow * COLS + startCol;
    int end = endRow * COLS + endCol;
    int current, row, col, nextRow, nextCol;
    int i;

    for (i = 0; i < ROWS * COLS; i++)
    {
        visited[i / COLS][i % COLS] = 0;
        parent[i / COLS][i % COLS] = -1;
    }

    queue[rear++] = start;
    visited[startRow][startCol] = 1;

    while (front < rear)
    {
        current = queue[front++];
        row = current / COLS;
        col = current % COLS;

        if (current == end)
            return 1;

        for (i = 0; i < 4; i++)
        {
            nextRow = row + rowMove[i];
            nextCol = col + colMove[i];

            if (isValid(nextRow, nextCol))
            {
                visited[nextRow][nextCol] = 1;
                parent[nextRow][nextCol] = current;
                queue[rear++] = nextRow * COLS + nextCol;
            }
        }
    }

    return 0;
}

void displayGrid(void)
{
    int r, c;

    for (r = 0; r < ROWS; r++)
    {
        for (c = 0; c < COLS; c++)
            printf("%c ", grid[r][c]);

        printf("\n");
    }
}

void displayPath(int startRow, int startCol, int endRow, int endCol)
{
    int current = endRow * COLS + endCol;
    int start = startRow * COLS + startCol;
    int count = 0;
    int i, row, col;

    while (current != start && current != -1)
    {
        path[count++] = current;
        row = current / COLS;
        col = current % COLS;
        current = parent[row][col];
    }

    path[count++] = start;

    for (i = count - 1; i >= 0; i--)
    {
        row = path[i] / COLS;
        col = path[i] % COLS;

        if (grid[row][col] != 'S' && grid[row][col] != 'E')
            grid[row][col] = '*';
    }

    printf("\nGrid with shortest path (*):\n");
    displayGrid();

    printf("\nPath coordinates (row, column; starting from 0):\n");
    for (i = count - 1; i >= 0; i--)
    {
        row = path[i] / COLS;
        col = path[i] % COLS;
        printf("(%d, %d)", row, col);

        if (i > 0)
            printf(" -> ");
    }

    printf("\nTotal moves: %d\n", count - 1);
}

int main(void)
{
    int startRow, startCol, endRow, endCol;

    printf("=== SHORTEST PATH IN A GRID ===\n\n");
    printf("Legend: S = Start, E = End, # = Wall, . = Empty, * = Path\n\n");

    printf("Original grid:\n");
    displayGrid();

    if (!findStart(&startRow, &startCol) ||
        !findEnd(&endRow, &endCol))
    {
        printf("\nError: Grid must contain both S and E.\n");
        return 1;
    }

    if (shortestPath(startRow, startCol, endRow, endCol))
    {
        displayPath(startRow, startCol, endRow, endCol);
    }
    else
    {
        printf("\nNo path exists from S to E.\n");
    }

    return 0;
}
