#include "include.h"
#include "structure.h"

void loadImg()
{
    bloc.ground = IMG_Load("ground1.png");
    bloc.bloc = IMG_Load("bloc.png");
    bloc.image = bloc.ground;
    bloc.etat = 0;
}

void blocUpdate()
{
    if (input.right == 1)
    {
        bloc.etat = 1;
    }
    if (input.left == 1)
    {
        bloc.etat= 0;
    }
    if (bloc.etat == 0)
    {
        bloc.image = bloc.ground;
    }
    if (bloc.etat == 1)
    {
        bloc.image = bloc.bloc;
    }
}
