#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store match results
struct play {
    char HomeName[20];
    char GuestName[20];
    int Hgole;  // Home team goals
    int Ggole;  // Guest team goals
} p[8];

// Structure to store team statistics
struct team {
    char club[20];
    int MP;     // Matches Played
    int W;      // Wins
    int L;      // Losses
    int D;      // Draws
    int GF;     // Goals For
    int GA;     // Goals Against
    int GD;     // Goal Difference
    int Pts;    // Points
} t[16];

// Function to update team statistics
void Stats(int i, char *p, int goalsFor, int goalsAgainst) {
    strcpy(t[i].club, p);
    t[i].MP = 1;
    t[i].GF += goalsFor;
    t[i].GA += goalsAgainst;
    t[i].GD = t[i].GF - t[i].GA;

    if (goalsFor > goalsAgainst) { // Win
        t[i].W++;
        t[i].Pts += 3;
    } else if (goalsFor == goalsAgainst) { // Draw
        t[i].D++;
        t[i].Pts++;
    } else { // Loss
        t[i].L++;
    }
}

int main()
{
    FILE *f, *f2;

    // Open input file containing match results
    f = fopen("C:\\Users\\RAD-SYSTEM\\Desktop\\f\\play1.txt", "r");
    if (f == NULL)
        printf("Error: Could not open play1.txt\n");
    else {
        printf("play1.txt opened successfully\n");

        // Read match data from file
        for (int i = 0; i < 8; i++) {
            fscanf(f, "%s %s %9d %9d\n", p[i].HomeName, p[i].GuestName, &p[i].Hgole, &p[i].Ggole);
            printf("%15s %12s %9d %9d\n", p[i].HomeName, p[i].GuestName, p[i].Hgole, p[i].Ggole);
        }

        // Update statistics for each team
        for (int i = 0; i < 8; i++) {
            Stats(2 * i, p[i].HomeName, p[i].Hgole, p[i].Ggole);
            Stats(2 * i + 1, p[i].GuestName, p[i].Ggole, p[i].Hgole);
        }

        // Create output file for team statistics
        f2 = fopen("C:\\Users\\RAD-SYSTEM\\Desktop\\f\\team.txt", "w+");
        if (f2 == NULL)
            printf("Error: Could not create team.txt\n");
        else {
            printf("team.txt created successfully\n");
            fputs("Club\t\t\t MP W L D GF GA GD Pts\n", f2);

            // Write team statistics to file
            for (int i = 0; i < 16; i++) {
                fprintf(f2, "%s \t\t %d %d %d %d %d %d %d %d\n",
                        t[i].club, t[i].MP, t[i].W, t[i].L, t[i].D,
                        t[i].GF, t[i].GA, t[i].GD, t[i].Pts);
            }

            fclose(f);
            fclose(f2);
            return 0;
        }
    }
}
