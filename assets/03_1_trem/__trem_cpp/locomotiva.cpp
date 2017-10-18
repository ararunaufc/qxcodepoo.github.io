#include "locomotiva.h"

int Locomotiva::getMaxVagoes()
{
    return maxVagoes;
}

void Locomotiva::setMaxVagoes(int value)
{
    maxVagoes = value;
}

Locomotiva::Locomotiva(int mv)
{
    maxVagoes = mv;
}

