#include "include.h"
#include "structure.h"

int main(int argc, char *argv[])
{
    int continuer = 1;
    SDL_Init(SDL_INIT_VIDEO);
    screen.showable = SDL_SetVideoMode(WIN_LARGEUR, WIN_HAUTEUR, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    initMap();
    loadImg();
    while (continuer)
    {
        getInput();
        draw();
        if (input.up == 1)
        {
            saveMap();
        }
        else if (input.down == 1)
        {
            loadMap();
        }
    }
    SDL_FreeSurface(screen.showable);
    SDL_Quit();
    return 0;
}
