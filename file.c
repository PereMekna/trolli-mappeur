#include "include.h"
#include "structure.h"

void saveMap()
{
    FILE *fichier;
    int i, j;
    fichier = fopen("save.txt", "w");
    for (i = 0; i < 30 ; i++)
    {
        for (j = 0; j < 30 ; j++)
        {
            fprintf(fichier, "%d ", map.tile[i][j]);
        }
        fprintf(fichier, "\n");
    }
    fclose(fichier);
}

void loadMap()
{
    FILE *fichier;
    int i, j;
    fichier = fopen("save.txt", "r");
    for (i = 0; i < 30 ; i++)
    {
        for (j = 0; j < 30 ; j++)
        {
           fscanf(fichier, "%d", &map.tile[i][j]);
        }
    }
    fclose(fichier);
}

