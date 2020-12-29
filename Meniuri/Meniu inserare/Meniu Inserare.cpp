#include <iostream>
#include <fstream>
#include <graphics.h>
#include <winbgim.h>
using namespace std;

ifstream fin("liste.in");

struct nod
{
    int valoare;
    struct nod* urm;
};
nod *prim, *ultim;

void dimensiuneText(int element);
void creareListaSimpluInlantuita(nod*& prim, nod*& ultim);
void inserareInceput(nod*& prim, int val);
void inserareSfarsit(nod*& prim, int val);
void inserareDupaNod(nod*& prim, int element_dat, int val);
void meniuInserare();


void dimensiuneText(int element)
{
     if(element >=0 && element<100)
        settextstyle(4, HORIZ_DIR, 3);
    else
        if(element >= 100 && element < 1000)
            settextstyle(4, HORIZ_DIR, 2);
        else
            if(element >=1000 && element <100000)
                settextstyle(4, HORIZ_DIR, 1);
}

//------------- FUNCTIE CREARE LISTA --------------
void creareListaSimpluInlantuita(nod*& prim, nod*& ultim)
{
    nod* p;
    int x;
    prim = ultim = NULL;
    while (fin >> x)
    {
        p = new nod;
        p->valoare = x;
        p->urm = NULL;
        if (prim == NULL)
            prim = p;
        else
            ultim->urm = p;
        ultim = p;
    }
}

//------------- FUNCTII PENTRU INSERARE --------------
void inserareInceput(nod*& prim, int val)
{
    settextstyle(4, HORIZ_DIR, 3);
    setcolor(LIGHTCYAN);
    outtextxy(440, 20, " Inserarea unui nod la inceputul unei liste simplu-inlantuite");
    setcolor(WHITE);
    delay(800);

    // INSERARE
    nod *p = new nod;
    p->valoare = val;
    p->urm = prim;

    // AFISAREA INSERARII
    setcolor(LIGHTMAGENTA);
    settextstyle(4, HORIZ_DIR, 1);
    bgiout << "nod *p = new nod";
    outstreamxy(5,410);
    delay(500);
    bgiout << "p->info = val. dorita";
    outstreamxy(5,430);
    delay(500);
    bgiout << "p->urm = prim;";
    outstreamxy(5,450);
    delay(1000);
    setcolor(WHITE);

    // COORDONATELE PRIMULUI NOD
    unsigned int x = 320, y = 100;
    unsigned int xtext = 325, ytext = 115;
    // CAZ PARTICULAR CAND LISTA ESTE VIDA
    if (prim == NULL)
        readimagefile("nod inserat lista cu null.jpg", x, y - 10, x + 270, y + 50);
    else
        readimagefile("nod inserat lista.jpg", x, y - 10, x + 200, y + 50);
    prim = p;
    p = prim;
    setcolor(LIGHTMAGENTA);
    bgiout << "*prim";
    outstreamxy(360,60);
    setcolor(WHITE);

    // DIMENSIUNEA TEXTULUI IN FIECARE NOD
    dimensiuneText(p->valoare);
    // AFISARE IN MODUL GRAFIC
    bgiout << p->valoare;
    outstreamxy(xtext, ytext);
    // AFISAREA INSTRUCTIUNILOR
    setcolor(LIGHTMAGENTA);
    delay(500);
    bgiout << "prim = p;";
    outstreamxy(5,470);
    delay(500);
    bgiout << "p = prim;";
    outstreamxy(145,470);
    setcolor(WHITE);

    // COORDONATELE URMATORULUI NOD
    x += 200;
    xtext += 200;
    p = p->urm;
    delay(500);
    setcolor(LIGHTMAGENTA);
    bgiout << "p = p->urm;";
    outstreamxy(5,490);
    setcolor(WHITE);

    while (p != NULL)
    {
        if (x > 1400)
        {
            // COORDONATELE URMATORULUI RAND DACA SE AJUNGE LA CAPAT DE ECRAN
            x = 320;
            y += 100;
            xtext = 325;
            ytext += 100;
        }
        else
            if (y > 795)
            {
                delay(2000);
                setfillstyle(SOLID_FILL,BLACK);
                bar(315,45,1520,795);
                delay(500);
                settextstyle(4, HORIZ_DIR, 4);
                setcolor(LIGHTRED);
                bgiout << "Eroare: Imposibil de afisat!";
                outstreamxy(590, 300);
                bgiout << "Prea multe valori in lista.";
                outstreamxy(600, 340);
                break;
            }
            else
                if (x <= 1400)  // daca nu iese din ecran
                {
                    // AFISAREA NODULUI CORESPUNZATOR
                    if (p->urm == NULL)
                        readimagefile("nod lista cu null.jpg", x, y, x + 200, y + 50);
                    else
                        readimagefile("nod lista.jpg", x, y, x + 200, y + 50);

                    // DIMENSIUNEA TEXTULUI IN FIECARE NOD
                    dimensiuneText(p->valoare);

                    // AFISARE IN MODUL GRAFIC
                    bgiout << p->valoare;
                    outstreamxy(xtext, ytext);

                    // COORDONATELE URMATORULUI NOD
                    x += 200;
                    xtext += 200;

                    p = p->urm;
                    delay(500);
                }
        // STERGERE CE AM SCRIS INAINTE
        setfillstyle(SOLID_FILL,BLACK);
        bar(5,490,250,510);
        delay(500);
        // RESCRIERE
        setcolor(LIGHTMAGENTA);
        settextstyle(4, HORIZ_DIR, 1);
        bgiout << "p = p->urm;";
        outstreamxy(5,490);
        setcolor(WHITE);
    }
    delay(6000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(311,0,1520,795);
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,403,308,795);
}

void inserareSfarsit(nod*& prim, int val)
{
    settextstyle(4, HORIZ_DIR, 3);
    setcolor(LIGHTCYAN);
    outtextxy(440, 20, " Inserarea unui nod la sfarsitul unei liste simplu-inlantuite");
    setcolor(WHITE);
    delay(800);
    // NOD NOU
    nod *p = new nod;
    p->valoare = val;
    p->urm = NULL;

    // AFISAREA INSTRUCTIUNILOR
    setcolor(LIGHTMAGENTA);
    settextstyle(4, HORIZ_DIR, 1);
    bgiout << "nod *p = new nod;";
    outstreamxy(5,410);
    delay(500);
    bgiout << "p->info = val. dorita;";
    outstreamxy(5,430);
    delay(500);
    bgiout << "p->urm = NULL;";
    outstreamxy(5,450);
    delay(1000);
    setcolor(WHITE);
    // INSERAREA LA SFARSIT
    if (prim == NULL)  // caz particular
        prim = p;
    else
    {
        nod *q = prim;
        while (q->urm != NULL)
        {
            q = q->urm;
        }
        q->urm = p;
    }
    p = prim;
    // COORDONATELE PRIMULUI NOD
    unsigned int x = 320, y = 100;
    unsigned int xtext = 325, ytext = 115;

    // AFISAREA INSTRUCTIUNILOR
    setcolor(LIGHTMAGENTA);
    bgiout << "p = prim;";
    outstreamxy(5,470);
    setcolor(WHITE);
    delay(500);

    setcolor(LIGHTMAGENTA);
    bgiout << "*prim";
    outstreamxy(360,60);
    setcolor(WHITE);
    while (p != NULL)
    {
        if (x > 1400)
        {
            // COORDONATELE URMATORULUI RAND DACA SE AJUNGE LA CAPAT DE ECRAN
            x = 320;
            y += 100;
            xtext = 325;
            ytext += 100;
        }
        else
            if (y > 795)
            {
                delay(2000);
                setfillstyle(SOLID_FILL,BLACK);
                bar(315,45,1520,795);
                delay(500);
                settextstyle(4, HORIZ_DIR, 4);
                setcolor(LIGHTRED);
                bgiout << "Eroare: Imposibil de afisat!";
                outstreamxy(590, 300);
                bgiout << "Prea multe valori in lista.";
                outstreamxy(600, 340);
                break;
            }
        else
            if (x <= 1400)  // daca nu iese din ecran
            {
                // AFISAREA NODULUI CORESPUNZATOR
                if (p->urm == NULL)
                    readimagefile("nod inserat lista cu null.jpg", x, y - 15, x + 200, y + 50);
                else
                    readimagefile("nod lista.jpg", x, y, x + 200, y + 50);

                // DIMENSIUNEA TEXTULUI IN FIECARE NOD
                dimensiuneText(p->valoare);

                // AFISARE IN MODUL GRAFIC
                bgiout << p->valoare;
                outstreamxy(xtext, ytext);

                // COORDONATELE URMATORULUI NOD
                x += 200;
                xtext += 200;

                p = p->urm;
                delay(500);
            }
        // STERGERE CE AM SCRIS INAINTE
        setfillstyle(SOLID_FILL,BLACK);
        bar(5,490,250,510);
        delay(500);
        // RESCRIERE
        setcolor(LIGHTMAGENTA);
        settextstyle(4, HORIZ_DIR, 1);
        bgiout << "p = p->urm;";
        outstreamxy(5,490);
        setcolor(WHITE);
    }
    delay(6000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(311,0,1520,795);
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,403,308,795);
}

// NU ESTE COMPLETA
void inserareDupaNod(nod*& prim, int element_dat, int val)
{
    settextstyle(4, HORIZ_DIR, 3);
    setcolor(LIGHTCYAN);
    outtextxy(580, 20, " Inserarea unui nod dupa un element dat");
    setcolor(WHITE);
    delay(800);

    // NOD NOU
    nod *p = new nod;
    p->valoare = val;
    p->urm = NULL;

    // AFISAREA INSTRUCTIUNILOR
    setcolor(LIGHTMAGENTA);
    settextstyle(4, HORIZ_DIR, 1);
    bgiout << "nod *p = new nod;";
    outstreamxy(5,410);
    delay(500);
    bgiout << "p->info = val. dorita;";
    outstreamxy(5,430);
    delay(500);
    bgiout << "p->urm = NULL;";
    outstreamxy(5,450);
    delay(500);

    // COORDONATELE PRIMULUI NOD
    unsigned int x = 320, y = 100;
    unsigned int xtext = 325, ytext = 115;
    bool inserat = false;
    nod *q = prim;

    bgiout << "nod *q = prim;";
    outstreamxy(5,470);
    setcolor(WHITE);
    delay(500);

    if (prim == NULL) // daca e vida, primul element = elementul inserat
    {
        prim = p;
        setcolor(LIGHTRED);
        bgiout << "Lista este vida! Elementul inserat va fi primul element.";
        outstreamxy(560, 70);
        setcolor(LIGHTMAGENTA);
        delay(600);

        // STERGERE CE AM SCRIS INAINTE DE IF
        setfillstyle(SOLID_FILL,BLACK);
        bar(5,470,250,490);
        bgiout << "prim = p;";
        outstreamxy(5,470);
        delay(500);
        bgiout << "*prim";
        outstreamxy(360,120);
        setcolor(WHITE);

        // AFISARE IMAGINE NOD
        readimagefile("nod inserat lista cu null.jpg", x, y + 50, x + 300, y + 110);
        settextstyle(4, HORIZ_DIR, 4);

        // AFISARE VAL NOD
        dimensiuneText(p->valoare);
        bgiout << p->valoare;
        outstreamxy(xtext, ytext + 60);

        // STERGERE ECRAN
        delay(6000);
        setfillstyle(SOLID_FILL,BLACK);
        bar(311,0,1520,795);
        setfillstyle(SOLID_FILL,BLACK);
        bar(0,403,308,795);
        return;
    }
    while (q != NULL)
    {
        if (q->valoare == element_dat)
        {
            p->urm = q->urm;
            q->urm = p;
            inserat = true;
        }
        q = q->urm;
    }
    q = prim;
    while (q != NULL)
    {
        if (x > 1400)
        {
            // COORDONATELE URMATORULUI RAND DACA SE AJUNGE LA CAPAT DE ECRAN
            x = 320;
            y += 100;
            xtext = 325;
            ytext += 100;
        }
        else
            if (y > 795)
            {
                delay(2000);
                setfillstyle(SOLID_FILL,BLACK);
                bar(315,45,1520,795);
                delay(500);
                settextstyle(4, HORIZ_DIR, 4);
                setcolor(LIGHTRED);
                bgiout << "Eroare: Imposibil de afisat!";
                outstreamxy(590, 300);
                bgiout << "Prea multe valori in lista.";
                outstreamxy(600, 340);
                break;
            }
            else
                if (x <= 1400)  // daca nu iese din ecran
                {
                    if (q->urm == NULL)
                        readimagefile("nod lista cu null.jpg", x, y, x + 250, y + 50);
                    else
                        readimagefile("nod lista.jpg", x, y, x + 200, y + 50);
                    if (q->valoare == val)
                        readimagefile("nod inserat lista.jpg", x, y - 10, x + 200, y + 50);
                    // DIMENSIUNEA TEXTULUI IN FIECARE NOD
                    dimensiuneText(q->valoare);

                    // AFISARE IN MODUL GRAFIC
                    bgiout << q->valoare;
                    outstreamxy(xtext, ytext);

                    // COORDONATELE URMATORULUI NOD
                    x += 200;
                    xtext += 200;

                    q = q->urm;
                    delay(500);
                }
    }
    if (inserat == false)
    {
        settextstyle(4, HORIZ_DIR, 3);
        setcolor(LIGHTRED);
        outtextxy(545, 55, " Nu s-a inserat nodul in lista simplu-inlantuita!");
    }
    delay(6000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(311,0,1520,795);
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,403,308,795);
}

// MENIU INSERARE FUNCTII
void meniuInserare()
{
    readimagefile("undo.jpg",30,730,250,780);
    settextstyle(4, HORIZ_DIR, 4);
    outtextxy(10, 10, " Alege functia ");
    outtextxy(30, 50, " de inserare ");
    // BUTON 1
    readimagefile("inserare inceput.jpg",10, 100, 300, 180);
    // BUTON 2
    readimagefile("inserare sfarsit.jpg",10, 200, 300, 280);
    // BUTON 3
    readimagefile("inserare dupa nod.jpg",10, 300, 300, 380);
    // LINII DE DELIMTARE
    line(310,795,310,0);
    line(0,400,310,400);

    // LABEL PENTRU A RESETA BUTONUL
    jump:
    bool gata = false;
    bool buton1 = false, buton2 = false, buton3 = false, buton4 = false;
    int x,y;
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
            if(x >= 10 && x <= 300 && y >= 100 && y <= 180) //buton 1
            {
                gata = true;
                buton1 = true;
            }
            else
                if(x >= 10 && x <= 300 && y >= 200 && y <= 280)  //buton 2
                {
                    gata = true;
                    buton2 = true;
                }
                else
                    if(x >= 10 && x <= 300 && y >= 300 && y <= 380) //buton 3
                    {
                        gata = true;
                        buton3 = true;
                    }
                    else
                        if (x >=30 && x <= 730 && y >= 250 && y <= 780)
                        {
                            gata = true;
                            buton4 = true;
                        }
        }
    } while (!gata);

    if (buton1 == true)
    {
        inserareInceput(prim,1000);
        goto jump;  // RESET LA BUTON
    }
    else
        if (buton2 == true)
        {
            inserareSfarsit(prim,1);
            goto jump;  // RESET LA BUTON
        }
        else
            if (buton3 == true)
            {
                inserareDupaNod(prim, 2, 3);
                goto jump;  // RESET LA BUTON
            }
            else
                if (buton4 == true)
                {
                    meniuListeSimpluInlantuite();
                }
}

int main()
{
    initwindow(1530, 795, " Meniu Inserare ");
    creareListaSimpluInlantuita(prim,ultim);
    meniuInserare();

    getch();
    closegraph();
    return 0;
}
