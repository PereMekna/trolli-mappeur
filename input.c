#include "include.h"
#include "structure.h"

void getInput()
{
    SDL_Event event;
    SDL_GetMouseState(&input.mousepos.x, &input.mousepos.y);
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT : exit(EXIT_SUCCESS); break;
            case SDL_KEYDOWN :
            switch (event.key.keysym.sym)
            {
                case SDLK_ESCAPE : exit(EXIT_SUCCESS); break;
                case SDLK_LEFT : input.left = 1; break;
                case SDLK_RIGHT : input.right = 1; break;
                case SDLK_UP : input.up = 1; break;
                case SDLK_DOWN : input.down = 1; break;
                case SDLK_KP_PLUS : input.plus = 1; break;
                case SDLK_KP_MINUS : input.moins = 1; break;
            };break;
            case SDL_MOUSEBUTTONDOWN :
            switch (event.button.button)
            {
                case SDL_BUTTON_LEFT : input.mouse1 = 1;break;
                case SDL_BUTTON_RIGHT : input.mouse2 = 1;break;
            };break;
            case SDL_KEYUP :
            switch (event.key.keysym.sym)
            {
                case SDLK_ESCAPE : exit(EXIT_SUCCESS); break;
                case SDLK_LEFT : input.left = 0; break;
                case SDLK_RIGHT : input.right = 0; break;
                case SDLK_UP : input.up = 0; break;
                case SDLK_DOWN : input.down = 0; break;
                case SDLK_KP_PLUS : input.plus = 0; break;
                case SDLK_KP_MINUS : input.moins = 0; break;
            };break;
            case SDL_MOUSEBUTTONUP :
            switch (event.button.button)
            {
                case SDL_BUTTON_LEFT : input.mouse1 = 0;break;
                case SDL_BUTTON_RIGHT : input.mouse2 = 0;break;
            };break;
        }
    }
}
