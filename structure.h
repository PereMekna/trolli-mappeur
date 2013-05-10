#define WIN_LARGEUR 768
#define WIN_HAUTEUR 640
#define BLOC_DIM 64


typedef enum
{
    EMPTY, GROUND, WALL
} typebloc;

typedef struct Screen
{
    SDL_Surface *showable;
} Screen;

Screen screen;

typedef struct input
{
    int right;
    int left;
    int up;
    int down;
    int space;
    int shift;
    int mouse1;
    int mouse2;
    SDL_Rect mousepos;
    int plus;
    int moins;
} Input;

Input input;

typedef struct bloc
{
    SDL_Surface *image;
    SDL_Surface *ground;
    SDL_Surface *bloc;
    int etat;
    SDL_Rect pos;
} Bloc;

Bloc bloc;

typedef struct map
{
    typebloc tile[30][30];
    SDL_Rect startPos;
} Map;

Map map;
