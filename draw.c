#include "include.h"
#include "structure.h"

void draw()
{

    SDL_FillRect(screen.showable, NULL, SDL_MapRGB(screen.showable->format, 120, 25, 30));
    blocUpdate();
    scrollMap();
    updateMap();
    drawMap();
    SDL_BlitSurface(bloc.image, NULL, screen.showable, &input.mousepos);
    SDL_Flip(screen.showable);
}


void drawMap()
{
    int i, j;
    SDL_Rect postmp;
    for (i = 0; i < 30 ; i++)
    {
        for (j = 0; j < 30; j++)
        {
            if (map.tile[i][j] == GROUND)
            {
                postmp.x = i*BLOC_DIM - map.startPos.x;
                postmp.y = j*BLOC_DIM;
                SDL_BlitSurface(bloc.ground, NULL, screen.showable, &postmp);
            }
            if (map.tile[i][j] == WALL)
            {
                postmp.x = i*BLOC_DIM - map.startPos.x;
                postmp.y = j*BLOC_DIM;
                SDL_BlitSurface(bloc.bloc, NULL, screen.showable, &postmp);
            }
        }
    }
}

void updateMap()
{
    int i, j;
    i = (input.mousepos.x + map.startPos.x)/BLOC_DIM;
    j = input.mousepos.y/BLOC_DIM;
    if (input.mouse1 == 1)
    {
        if (bloc.etat == 0) map.tile[i][j] = GROUND;
        if (bloc.etat == 1) map.tile[i][j] = WALL;
    }
    if (input.mouse2 == 1)
    {
        map.tile[i][j] = EMPTY;
    }
}

void initMap()
{
    map.startPos.x = 0;
    map.startPos.y = 0;
}

void scrollMap()
{
    if (input.plus == 1)
    {
        map.startPos.x += 5;
    }
    if (map.startPos.x > 4)
    {
        if (input.moins == 1)
        {
            map.startPos.x -= 5;
        }
    }
}
