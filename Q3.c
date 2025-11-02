#include <stdio.h>

#define ROWS 3
#define COLS 3

#define POWER_ON 1
#define OVERLOAD 2
#define MAINTENANCE 4

void update(int grid[ROWS][COLS]);
void query(int grid[ROWS][COLS]);
void diagnostic(int grid[ROWS][COLS]);

int main() {
    int grid[ROWS][COLS] = {0};
    int ch;

    do {
        printf("\n 1. Update Sector\n");
        printf("2. Query Sector\n");
        printf("3. Run Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                update(grid);
                break;
            case 2:
                query(grid);
                break;
            case 3:
                diagnostic(grid);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    } while(ch != 4);

    return 0;
}

void update(int grid[ROWS][COLS]) {
    int r, c, bit, act;
    printf("Enter row and col: ");
    scanf("%d %d", &r, &c);

    if(r < 0 || r >= ROWS || c < 0 || c >= COLS) {
        printf("Invalid sector\n");
        return;
    }

    printf("0=Power  1=Overload  2=Maintenance\n");
    printf("Enter which to change: ");
    scanf("%d", &bit);
    printf("1=Set  0=Clear: ");
    scanf("%d", &act);

    int mask = 1 << bit;
    if(act == 1)
        grid[r][c] |= mask;
    else
        grid[r][c] &= ~mask;

    printf("Updated (%d,%d)\n", r, c);
}

void query(int grid[ROWS][COLS]) {
    int r, c;
    printf("Enter row and col: ");
    scanf("%d %d", &r, &c);

    if(r < 0 || r >= ROWS || c < 0 || c >= COLS) {
        printf("Invalid sector\n");
        return;
    }

    int val = grid[r][c];
    printf("\nSector (%d,%d):\n", r, c);
    printf("Power: %s\n", (val & POWER_ON) ? "ON" : "OFF");
    printf("Overload: %s\n", (val & OVERLOAD) ? "YES" : "NO");
    printf("Maintenance: %s\n", (val & MAINTENANCE) ? "YES" : "NO");
}

void diagnostic(int grid[ROWS][COLS]) {
    int over = 0, main = 0;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(grid[i][j] & OVERLOAD)
                over++;
            if(grid[i][j] & MAINTENANCE)
                main++;
        }
    }

    printf("\nOverloaded sectors: %d\n", over);
    printf("Maintenance needed: %d\n", main);
}
