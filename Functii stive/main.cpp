#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <fstream>

using namespace std;

ifstream fin("citire.in");


struct nod
{
    int info;
    nod * urm;
};

struct stiva
{
    nod* varf;
    int nrElemente;
};

// ---------- INITIALIZARE FEREASTRA ----------
void fereastra()
{
    initwindow(1200,700,"Functii STIVE");
}

// ---------- STIVA VIDA ? ----------
bool esteVidaStiva(stiva S)
{
    if (S.nrElemente == 0)
    {
        settextstyle(4, HORIZ_DIR, 5);
        outtextxy(320, 300, " Stiva este vida! ");
        return 1;
    }
    else
    {
        settextstyle(4, HORIZ_DIR, 5);
        outtextxy(320, 300, " Stiva nu este vida! ");
        return 0;
    }
}

// ---------- STIVA VIDA - functie fara text ----------
bool esteVida(stiva S)
{
    return (S.nrElemente == 0);
}

// ---------- INITIALIZARE STIVA ----------
void initializeaza(stiva& S)
{
    settextstyle(4, HORIZ_DIR, 5);
    outtextxy(320, 100, " S-a initializat stiva! ");
    S.varf = NULL;
    S.nrElemente = 0;
}

// --------- Functia Pop (eliminare din varful stivei) ----------
int pop(stiva &S)
{
    if (!esteVida(S))
    {
        int element;
        nod* varf_nou;
        element = S.varf->info;
        varf_nou = S.varf->urm;
        delete S.varf;
        S.varf = varf_nou;
        S.nrElemente--;
        return element;
    }
    else
    {
        settextstyle(4, HORIZ_DIR, 5);
        outtextxy(320, 100, " Eroare! Stiva este goala. ");
        return 0;
    }
}

// ------- Functie de golire a stivei -------
void goleste(stiva &S)
{
    int element;
    while (!esteVida(S))
        element = pop(S);
}

// ------- Functie de inserare in varful stivei -------
void push(stiva &S, int element)
{
    nod * nod_nou;
    if (esteVida(S))
    {
        S.nrElemente = 1;
        S.varf = new nod;
        S.varf->info = element;
        S.varf->urm = NULL;
    }
    else
    {
        S.nrElemente++;
        nod_nou = new nod;
        nod_nou->info = element;
        nod_nou->urm = S.varf;
        S.varf = nod_nou;
    }
}

// ------- Functie de afisare a stivei -------
void afiseaza(stiva S)
{
    nod* nod_curent;
    nod_curent = S.varf;
    while (nod_curent != NULL)
    {
        cout << nod_curent->info << ",";
        nod_curent = nod_curent->urm;
    }
    cout << endl;
}



int main()
{
    fereastra();


    int y = 620, nrelemente = 4;
    for(int i = 1; i <= nrelemente; i++)
    {
        delay(300);
        readimagefile("etaj1.jpg",100,y,300,y - 70);
        y -= 70;
    }


    //stiva S;
   // initializeaza(S);
    //push(S,6);

   //pop(S);

    // CLEANUP
    getch();
    closegraph();
    return 0;
}
