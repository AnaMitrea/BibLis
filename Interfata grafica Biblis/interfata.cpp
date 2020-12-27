#include <iostream>
#include <fstream>
#include <graphics.h>
#include <winbgim.h>
using namespace std;

ifstream fin("citire.in");

// ---------- INITIALIZARE STRUCTURI DE DATE ----------
struct nod
{
    int valoare;
    struct nod* urm;
};

struct stiva
{
    struct nod* varf;
    unsigned int lungime;
};

nod *prim, *ultim;

// ------------- DECLARARE FUNCTII ------------
void fereastra();
void dimensiuneText(int element);
void creareListaSimpluInlantuita(nod*& prim, nod*& ultim);
void listaVida(nod* prim);
void lungimeLista(nod* prim);
void inserareInceput(nod*& prim, int val);
void inserareSfarsit(nod*& prim, int val);
void inserareDupaNod(nod*& prim, int element_dat, int val);
void meniuInserare();
void stergerePrimul(nod*& prim);
void stergerePrimaAparitie(nod*& prim, int element_dat);
void stergereToateAparitiile(nod*& prim, int element_dat);
void meniuStergere();
void afisareListaSimpluInlantuita(nod *prim);
void descriereListaSimplu();
void meniuListeSimpluInlantuite();
void meniuPrincipal();
void cleanup();
void interfataGrafica();


// ---------- INITIALIZARE FEREASTRA ----------
void fereastra()
{
    initwindow(1530, 795, " Meniu Biblioteca cu Liste ");
}

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

//------------- FUNCTIE VERIFICARE DACA ESTE LISTA VIDA --------------
void listaVida(nod* prim)
{
    settextstyle(4, HORIZ_DIR, 4);
    outtextxy(450, 100, " Verificare daca lista este vida");
    readimagefile("undo.jpg",30,730,250,780);

    delay(500);
    if (prim == NULL)
    {
        setcolor(LIGHTCYAN);
        settextstyle(4, HORIZ_DIR, 4);
        bgiout << "Primul nod este NULL deci lista introdusa este vida.";
        outstreamxy(240,350);
        setcolor(WHITE);
    }
    else
    {
        setcolor(LIGHTCYAN);
        settextstyle(4, HORIZ_DIR, 4);
        bgiout << "Primul nod este ";
        outstreamxy(60,350);
        setcolor(WHITE);
        delay(500);
        readimagefile("nod lista cu null.jpg",390, 330, 660, 400);

        dimensiuneText(prim->valoare);
        bgiout << prim->valoare;
        outstreamxy(400,350);

        delay(500);
        setcolor(LIGHTCYAN);
        settextstyle(4, HORIZ_DIR, 4);
        bgiout << "deci lista introdusa nu este vida. ";
        outstreamxy(700,350);
        setcolor(WHITE);
    }

    bool gata = false, buton = false;
    int x,y;
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
            if(x >= 30 && x <= 250 && y >= 730 && y <= 780) //buton
            {
                gata = true;
                buton = true;
            }
        }
    } while (!gata);

    if (buton == true)
    {
        cleardevice();
        meniuListeSimpluInlantuite();
    }
}

//------------- FUNCTIE PENTRU AFLAREA LUNGIMII LISTEI --------------
void lungimeLista(nod *prim)
{
    settextstyle(4, HORIZ_DIR, 4);
    outtextxy(275, 80, " Aflarea lungimii unei liste simplu-inlantuite");
    unsigned int lungime = 0;
    nod *p = prim;
    while (p != NULL)
    {
        lungime++;
        p = p->urm;
    }

    p = prim;
    unsigned int x = 20, y = 250;
    unsigned int xtext = 25, ytext = 265;
    int pozitie = 1;
    while (p != NULL)
    {
        if (x <= 1400)  // daca nu iese din ecran
        {
            // AFISAREA NODULUI CORESPUNZATOR
            if (p->urm == NULL)
                readimagefile("nod lista cu null.jpg", x, y, x + 270, y + 50);
            else
                readimagefile("nod lista.jpg", x, y, x + 200, y + 50);

            // DIMENSIUNEA TEXTULUI IN FIECARE NOD
            dimensiuneText(p->valoare);

            // AFISARE IN MODUL GRAFIC
            bgiout << p->valoare;
            outstreamxy(xtext, ytext);
            bgiout << pozitie;
            outstreamxy(xtext + 50, ytext - 40);


            // COORDONATELE URMATORULUI NOD
            x += 200;
            xtext += 200;

            p = p->urm;
            pozitie++;
            delay(500);
        }
        else
        {
            // COORDONATELE URMATORULUI RAND DACA SE AJUNGE LA CAPAT DE ECRAN
            x = 20;
            y += 100;
            xtext = 25;
            ytext += 100;
        }
    }
    // AFISARE IN FEREASTRA GRAFICA
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(500, 150, "Lungimea listei este: ");
    settextstyle(4, HORIZ_DIR, 4);
    bgiout << lungime << endl;
    outstreamxy(850, 145);
    delay(3000);
    cleardevice();
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
    bgiout << "nod *p = new nod;";
    outstreamxy(5,410);
    delay(500);
    bgiout << "p->info = val. dorita;";
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
    bar(0,403,308,727);
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
    bar(0,403,308,727);
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
        bar(0,403,308,727);
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
        setcolor(WHITE);
    }
    delay(6000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(311,0,1520,795);
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,403,308,727);
}

// ---------- MENIU FUNCTII INSERARE LA LISTE SIMPLU-INLANTUITE ----------
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

//------------- FUNCTII PENTRU STERGERE --------------
void stergerePrimul(nod *&prim)
{
    nod *p = prim->urm;
    delete prim;
    prim = p;
}

void stergerePrimaAparitie(nod *&prim, int element_dat)
{
    nod *p = prim;
    while(p != NULL)
    {
        if(p->valoare == element_dat)
        {
            nod *q = (p->urm)->urm;
            delete p->urm;
            p->urm = q;
            return;
        }
        p = p->urm;
    }
}

void stergereToateAparitiile(nod *&prim, int element_dat)
{
    nod *p = prim;
    while(p->urm != NULL)
    {
        if((p->urm)->valoare == element_dat)
        {
            nod *q = p->urm;
            p->urm = (p->urm)->urm;
            delete q;
        }
        else
            p = p->urm;
    }
    if(prim->valoare == element_dat)
    {
        nod *q = prim;
        prim = prim->urm;
        delete q;
    }
    //if(prim == NULL)
        //fout << "LISTA VIDA";
}

// ---------- MENIU FUNCTII STERGERE LA LISTE SIMPLU-INLANTUITE ----------
void meniuStergere()
{
    settextstyle(4, HORIZ_DIR, 4);
    outtextxy(10, 10, " Alege functia ");
    outtextxy(30, 50, " de stergere ");
    // BUTON 1
    readimagefile("stergere primul.jpg",10, 100, 300, 180);
    // BUTON 2
    readimagefile("stergere aparitie.jpg",10, 200, 300, 280);
    // BUTON 3
    readimagefile("stergere toate aparitiile.jpg",10, 300, 300, 380);
    // BUTON 4 - UNDO
    readimagefile("undo.jpg",30,730,250,780);

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
        stergerePrimul(prim);
        goto jump;  // RESET LA BUTON
    }
    else
        if (buton2 == true)
        {
            stergerePrimaAparitie(prim, 1);
            goto jump;  // RESET LA BUTON
        }
        else
            if (buton3 == true)
            {
                stergereToateAparitiile(prim, 2);
                goto jump;  // RESET LA BUTON
            }
            else
                if (buton4 == true)
                {
                    meniuListeSimpluInlantuite();
                }
}

// ---------- AFISAREA UNEI LISTE SIMPLU-INLANTUITE ----------
void afisareListaSimpluInlantuita(nod *prim)
{
    settextstyle(4, HORIZ_DIR, 4);
    outtextxy(350, 100, " Afisarea unei liste simplu-inlantuite");

    nod* p = prim;
    unsigned int x = 20, y = 250;
    unsigned int xtext = 25, ytext = 265;

    while (p != NULL)
    {
        if (x <= 1400)  // daca nu iese din ecran
        {
            // AFISAREA NODULUI CORESPUNZATOR
            if (p->urm == NULL)
                readimagefile("nod lista cu null.jpg", x, y, x + 270, y + 50);
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
        else
        {
            // COORDONATELE URMATORULUI RAND DACA SE AJUNGE LA CAPAT DE ECRAN
            x = 20;
            y += 100;
            xtext = 25;
            ytext += 100;
        }
    }
    delay(3000);
    cleardevice();
}

// ---------- POZA CU LISTA SI DESCRIEREA EI (inainte de functii) ----------
void descriereListaSimplu()
{
    cleardevice();
    readimagefile("next.jpg",640,710,850,790);
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(430,50, "Informatii despre liste simplu-inlantuite");
    settextstyle(4, HORIZ_DIR, 1);
    outtextxy(250, 150, "       Lista liniara este o structura de date logica, cu  date  omogene,  in care");
    outtextxy(250, 180, "fiecare  element  are  exact  un  element  predecesor si  exact  un  element");
    outtextxy(250, 210, "succesor, cu exceptia primului si al ultimului element.");
    outtextxy(250, 240, "       Lungimea unei liste reprezinta numarul de noduri din lista. O lista care");
    outtextxy(250, 270, "nu are niciun element se numeste lista vida.");
    outtextxy(250, 300, "       O modalitate  de implementare a  listelor este sub forma listelor liniare");
    outtextxy(250, 330, "alocate  dinamic. In  acest caz,  fiecare  element  al listei  este  o  variabila");
    outtextxy(250, 360, "dinamica;  aceasta  va  contine, pe langa informatia  utila si  informatia  de");
    outtextxy(250, 390, "legatura,  adica  adresa elementului  succesor  si,  eventual,  adresa  celui");
    outtextxy(250, 420, "precedent. Aceste adrese vor fi memorate prin intermediul pointerilor.");

    readimagefile("Poza Lista.jpg",550,450,950,650);

    bool gata = false, buton = false;
    int x,y;
    do
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
            if(x >= 640 && x <= 850 && y >= 710 && y <= 790)
            {
                gata = true;
                buton = true;
            }
        }
    } while (!gata);
    if (buton == true)
    {
        delay(0);
        cleardevice();
        return;
    }
    delay(40000);   // 1 sec =  1000 ms
    cleardevice();
}

// ---------- MENIU PENTRU LISTE SIMPLU-INLANTUITE ----------
void meniuListeSimpluInlantuite()
{
    // POZA CU LISTA SI DESCRIEREA EI
    descriereListaSimplu();

    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(400, 50, " Alege functia pentru liste simplu-inlantuite ");

    // BUTON 1 - CREARE LISTA
    readimagefile("creare lista.jpg",600,100,910,150);

    // BUTON 2 - VERIF LISTA VIDA
    readimagefile("vida.jpg",600,200,910,250);

    // BUTON 3 - LUNGIME LISTA
    readimagefile("lungime lista.jpg", 600, 300, 910, 350);

    // BUTON 4 - FUNCTII INSERARE
    readimagefile("inserare.jpg",600,400,910,450);

    // BUTON 5 - FUNCTII STERGERE
    readimagefile("stergere.jpg",600,500,910, 550);

    // BUTON 6 - AFISAREA LISTEI
    readimagefile("afisare.jpg",600, 600,910, 650);

    // BUTON 7 - UNDO
    readimagefile("undo.jpg",30,730,250,780);

    bool gata = false;
    bool buton1 = false, buton2 = false, buton3 = false, buton4 = false, buton5 = false, buton6 = false, undo = false;
    int x,y;
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
            if (x >= 600 && x <= 910 && y >= 100 && y <= 150) //buton 1 - creare
            {
                gata = true;
                buton1 = true;
            }
            else
                if (x >= 600 && x <= 910 && y >= 200 && y <= 250)  //buton 2 - vida
                {
                    gata = true;
                    buton2 = true;
                }
                else
                    if (x >= 600 && x <= 910 && y >= 300 && y <= 350) //buton 3 - Lungime lista
                    {
                        gata = true;
                        buton3 = true;
                    }
                    else
                        if (x >= 600 && x <= 910 && y >= 400 && y <= 450)  //buton 4 - inserari
                        {
                            gata = true;
                            buton4 = true;
                        }
                        else
                            if (x >= 600 && x <= 910 && y >= 500 && y <= 550)  //buton 4 - stergeri
                            {
                                gata = true;
                                buton5 = true;
                            }
                            else
                                if( x >= 600 && x <= 910 && y >= 600 && y <= 650)  //buton 4 - stergeri
                                {
                                    gata = true;
                                    buton6 = true;
                                }
                            else
                                if (x >= 30 && x <= 730 && y >= 250 && y <= 780)
                                {
                                    gata = true;
                                    undo = true;
                                }
        }
    } while (!gata);
    cleardevice();

    if (buton1 == true)  // Creare lista
    {
        creareListaSimpluInlantuita(prim, ultim);
    }
    else
        if (buton2 == true)  // Verificare daca lista este vida
        {
            creareListaSimpluInlantuita(prim, ultim);
            listaVida(prim);
        }
        else
            if (buton3 == true)  // Functie pt aflarea lungimii listei
            {
                creareListaSimpluInlantuita(prim, ultim);
                lungimeLista(prim);
            }
            else
                if (buton4 == true)  // Functii la INSERARE element in liste
                {
                    creareListaSimpluInlantuita(prim, ultim);
                    meniuInserare();
                }
                else
                    if (buton5 == true)  // Functii la STERGERE element din liste
                    {
                        creareListaSimpluInlantuita(prim, ultim);
                        meniuStergere();
                    }
                    else
                        if (buton6 == true)   // Afisarea unei liste
                        {
                            afisareListaSimpluInlantuita(prim);
                        }
                        else
                            if (undo == true)
                            {
                                cleardevice();
                                meniuPrincipal();
                            }
}

void meniuPrincipal()
{
    // ---------- TITLU MENIU ----------
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(560, 100, " Alege structura de date ");

    // ---------- MENIU PRINCIPAL CU STRUCTURI DE DATE ----------
    // BUTON 1 - Liste simplu inlantuite
    readimagefile("liste s i.jpg",600,210,910,280);

    // BUTON 2 -  Liste dublu inlantuite
    readimagefile("liste d i.jpg",600,310,910, 380);

    // BUTON 3 - Stive
    readimagefile("stive.jpg",600,410,910, 480);

    // BUTON 4 - Cozi
    readimagefile("cozi.jpg",600,510,910, 580);

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
            if(x >= 600 && x <= 910 && y >= 210 && y <= 280)  // Liste simplu-inlantuite
            {
                gata = true;
                buton1 = true;
            }
            else
                if(x >= 600 && x <= 910 && y >= 310 && y <= 380)  // Liste dublu-inalntuite
                {
                    gata = true;
                    buton2 = true;
                }
                else
                    if(x >= 600 && x <= 910 && y >= 410 && y <= 480)  // Stive
                    {
                        gata = true;
                        buton3 = true;
                    }
                    else
                        if(x >= 600 && x <= 910 && y >= 510 && y <= 580)  // Cozi
                        {
                            gata = true;
                            buton4 = true;
                        }
        }
    } while (!gata);
    cleardevice();
    if (buton1 == true)
    {
        meniuListeSimpluInlantuite();
    }
    else
        if (buton2 == true)
        {
            outtextxy(260, 100, " Alege functia pentru liste dublu-inlantuite ");
            // meniuListeDubluInlantuite();
        }
        else
            if(buton3 == true)
            {
                outtextxy(400, 100, " Alege functia pentru stive ");
                // meniuStive();
            }
            else
                if(buton4 == true)
                {
                    outtextxy(400, 100, " Alege functia pentru cozi");
                    // meniuCozi();

                }
}

// ---------- CLEANUP ----------
void cleanup()
{
    getch();
    closegraph();
}

// ---------- INTERFATA ----------
void interfataGrafica()
{
    fereastra();
    meniuPrincipal();
    cleanup();
}

int main()
{
    nod *prim, *ultim;
    interfataGrafica();

    return 0;
}
