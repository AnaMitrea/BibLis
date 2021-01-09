#pragma once

#include <iostream>
#include <windows.h>
#include <MMsystem.h>
#include <graphics.h>
#include <queue>
#include <mmsystem.h>
using namespace std;

struct nod
{
    int valoare;
    struct nod* urm;
};

struct stiva
{
    struct nod* varf;
    unsigned int nrElemente;
};
nod *prim;
stiva S;

