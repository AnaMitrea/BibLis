#include<iostream>
#include<windows.h>
#include<MMsystem.h>
#include <graphics.h>
#include <queue>
#include <fstream>
using namespace std;

ifstream fin("citire.in");

struct nod
{
    int valoare;
    struct nod* urm;
};
nod *prim, *ultim;

void dimensiuneText(int element);
void creareListaSimpluInlantuita(nod*& prim, nod*& ultim);
void adaugareSfarsit(nod*& prim, int val);
void stergerePrimul(nod*& prim);
void stergerePrimaAparitie(nod*& prim);
void stergereToateAparitiile(nod*& prim);
void meniuStergere();

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
void creareListaSimpluInlantuita(nod*& prim,int n,int Valoarea[20])
{
    for(int i = 0; i < n; i++)
        adaugareSfarsit(prim,Valoarea[i]);
}

void citesteSir(char text[100], char afisare[100], int x, int y, bool stergere)
{
    strcpy(afisare, "");
    char aux[100];
    char key[2];  // sirul in care se pastreaza tasta pe care o apasam la citire
    char tasta;   // tasta pe care se apasa
    char text2[100];
    key[0] = tasta;
    key[1] = '\0';
    strcat(afisare, key);
    strcpy(aux, afisare);
    strcat(aux, "_");
    setcolor(WHITE);
    strcpy(text2, text);
    strcat(text2, aux);
    outtextxy(x, y, text2);
    do
    {
        tasta = getch();
        if (tasta == 8) // backspace
            if (strlen(afisare) > 0)
            {
                setcolor(BLACK);
                strcpy(aux, afisare);
                strcat(aux, "_");
                strcpy(text2, text);
                strcat(text2, aux);
                outtextxy(x, y, text2);
                afisare[strlen(afisare) - 1] = '\0';
                strcpy(aux, afisare);
                strcat(aux, "_");
                strcpy(text2, text);
                strcat(text2, aux);
                outtextxy(x, y, text2);
                setcolor(WHITE);
                strcpy(text2, text);
                strcat(text2, aux);
                outtextxy(x, y, text2);
            }
            else
                Beep(1000,100);
        else
        {
            key[0] = tasta;
            key[1] = '\0';
            strcat(afisare, key);
            strcpy(aux, afisare);
            strcat(aux, "_");
            setcolor(WHITE);
            strcpy(text2, text);
            strcat(text2, aux);
            outtextxy(x, y, text2);
        }
    } while (tasta!=13);

    key[0] = tasta;
    key[1] = '\0';
    strcat(afisare, key);
    strcpy(aux, afisare);
    strcat(aux, "_");
    strcpy(text2, text);
    strcat(text2, aux);

    setcolor(BLACK);
    outtextxy(x,y,text2);

    if (!stergere)
    {
        strcpy(text2,text);
        strcat(text2,afisare);
        setcolor(WHITE);
        outtextxy(x,y,text2);
    }
}

void citireListeSimpluInlantuite()
{
    int Valoarea[20], n, i;
    char afisare[100], vectText[100], numar[100];
    // Colorare text
    setcolor(YELLOW);
    setbkcolor(BLACK);
    settextstyle(3, HORIZ_DIR, 3);
    outtextxy(20,10,"Va rugam introduceti numerele din lista");
    //Functia de citire a textului in mod grafic in sirul afisare
    citesteSir("Cate numere doriti sa contina lista? ", afisare, 20, 40, false);
    int nrElemente = atoi(afisare);  // conversie ascii -> int din sirul afisare
    n = nrElemente;
    for (i = 0; i < n; i++)
    {
        itoa(i,numar,10); // conversie int -> ascii in sirul "numar"
        strcpy(vectText,"Nodul ");
        strcat(vectText,numar);
        strcat(vectText," are valoarea egala cu: ");

        citesteSir(vectText,afisare, 30, 70 + 30 * i, false); // citire valoare corespunzatoare in vector pe poz i.

        Valoarea[i] = atoi(afisare); // valoarea lui Valoarea[i] in vector

       // evidentiaza(Valoarea[i], i, 1, LIGHTGREEN);
    }
    creareListaSimpluInlantuita(prim,n,Valoarea);
    cleardevice();
}

// functie in memorie
void adaugareSfarsit(nod*& prim, int val)
{
    nod *p = new nod;
    p->valoare = val;
    p->urm = NULL;
    if (prim == NULL)
        prim = p;
    else
    {
        nod *p_nou = prim;
        while (p_nou->urm != NULL)
        {
            p_nou = p_nou->urm;
        }
        p_nou->urm = p;
    }
}

//------------- FUNCTII PENTRU STERGERE --------------
void stergerePrimul(nod *&prim)
{
        // ----------- AFISARE ------------
    settextstyle(4, HORIZ_DIR, 3);
    setcolor(LIGHTCYAN);
    outtextxy(530, 20, " Stergerea primului nod din lista simplu-inlantuita");
    rectangle(370,70,1470,130);
    setcolor(WHITE);
    delay(800);
    nod *p = prim;
    if (p == NULL)
    {
        setcolor(LIGHTRED);
        bgiout << "Lista este vida. Nu se poate sterge niciun nod.";
        outstreamxy(580, 90);
        setcolor(WHITE);
            // STERGERE PARTE DE ECRAN
        delay(2500);
        setfillstyle(SOLID_FILL,BLACK);
        bar(311,0,1520,795);
        setfillstyle(SOLID_FILL,BLACK);
        bar(0,403,308,589);
        return;
    }
        // AFISAREA INSTRUCTIUNILOR
    settextstyle(4, HORIZ_DIR, 1);
    setcolor(LIGHTMAGENTA);
    bgiout << "nod* p = prim;";
    outstreamxy(5,410);
    setcolor(WHITE);
        // Afisare "*prim"
    if (prim != NULL)
    {
        setcolor(LIGHTMAGENTA);
        bgiout << "*prim      *p";
        outstreamxy(320,60);
        setcolor(WHITE);
    }
        // COORDONATELE PRIMULUI NOD
    unsigned int x = 320, y = 100;
    unsigned int xtext = 325, ytext = 115;
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
        bar(5,430,250,450);
        delay(500);
        // RESCRIERE
        setcolor(LIGHTMAGENTA);
        settextstyle(4, HORIZ_DIR, 1);
        bgiout << "p = p->urm;";
        outstreamxy(5,430);
        setcolor(WHITE);
    }

    // ALGORITM STERGERE PRIMUL NOD
    p = prim->urm;
    delete prim;
    prim = p;
    delay(500);
    setcolor(LIGHTMAGENTA);
    settextstyle(4, HORIZ_DIR, 1);
    bgiout << "p = prim->urm;";
    outstreamxy(5,450);
    bgiout << "*p";
    outstreamxy(530,60);
    delay(500);
    bgiout << "delete prim;";
    outstreamxy(5,470);
    readimagefile("black.jpg",320, 59, 518, 150);
    delay(500);
    bgiout << "prim = p;";
    outstreamxy(5,490);
    bgiout << "*prim";
    outstreamxy(600,60);
    setcolor(WHITE);

    // STERGERE PARTE DE ECRAN
    delay(2500);
    setfillstyle(SOLID_FILL,BLACK);
    bar(311,0,1520,795);
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,403,308,589);
}

void stergerePrimaAparitie(nod *&prim)
{
        // ----------- AFISARE ------------
    settextstyle(4, HORIZ_DIR, 3);
    setcolor(LIGHTCYAN);
    outtextxy(420, 20, " Stergerea primei aparitii a unui nod din lista simplu-inlantuita");
    rectangle(370,70,1470,130);
    setcolor(WHITE);

    nod *p = prim;
    if (p == NULL)
    {
        setcolor(LIGHTRED);
        bgiout << "Lista este vida. Nu se poate sterge niciun nod.";
        outstreamxy(580, 90);
        setcolor(WHITE);
            // STERGERE PARTE DE ECRAN
        delay(2500);
        setfillstyle(SOLID_FILL,BLACK);
        bar(311,0,1520,795);
        setfillstyle(SOLID_FILL,BLACK);
        bar(0,403,308,589);
        return;
    }
    // CITIREA ELEMENTELOR
    char afisare[100];
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(5,600," Ce element doriti");
    outtextxy(5,630,"    sa stergeti? " );
    citesteSir(" Elementul: ", afisare, 5, 660, false); //Functia de citire a textului in mod grafic in sirul afisare
    int element_dat = atoi(afisare);  // conversie ascii -> int din sirul afisare
    delay(300);
    bool sters = false;
    while (p->urm != NULL)
    {
        if ((p->urm)->valoare == element_dat)
        {
            nod *q = p->urm;
            p->urm = (p->urm)->urm;
            delete q;
            sters = true;
            break;
        }
        p = p->urm;
    }
     if (prim->valoare == element_dat)
    {
        nod *q = prim;
        prim = prim->urm;
        delete q;
        sters = true;
    }
    if (sters == true)
    {
        setcolor(LIGHTRED);
        bgiout << "S-au sters valorile de " << element_dat << " din lista.";
        outstreamxy(640, 90);
        setcolor(WHITE);
    }
    else
        {
            setcolor(LIGHTRED);
            bgiout << "Nu s-a sters niciun element din lista.";
            outstreamxy(620, 90);
            setcolor(WHITE);
        }
    delay(800);
        // COORDONATELE PRIMULUI NOD
    unsigned int x = 320, y = 170;
    unsigned int xtext = 325, ytext = 185;
    p = prim;
    setcolor(LIGHTMAGENTA);
    settextstyle(4, HORIZ_DIR, 1);
    bgiout << "nod* p = prim;";
    outstreamxy(5,410);
    bgiout << "*prim     *p";
    outstreamxy(320,145);
    settextstyle(4, HORIZ_DIR, 3);
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
        bar(5,430,250,450);
        delay(500);
        // RESCRIERE
        setcolor(LIGHTMAGENTA);
        settextstyle(4, HORIZ_DIR, 1);
        bgiout << "p = p->urm;";
        outstreamxy(5,430);
        setcolor(WHITE);
    }
    // STERGERE PARTE DE ECRAN
    delay(2500);
    setfillstyle(SOLID_FILL,BLACK);
    bar(311,0,1520,795);
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,403,308,795);
}

void stergereToateAparitiile(nod *&prim)
{
    // ----------- AFISARE ------------
    settextstyle(4, HORIZ_DIR, 3);
    setcolor(LIGHTCYAN);
    outtextxy(420, 20, " Stergerea tuturor aparitiilor unui nod din lista simplu-inlantuita");
    rectangle(370,70,1470,130);
    setcolor(WHITE);

    nod *p = prim;
    if (p == NULL)
    {
        setcolor(LIGHTRED);
        bgiout << "Lista este vida. Nu se poate sterge niciun nod.";
        outstreamxy(580, 90);
        setcolor(WHITE);
            // STERGERE PARTE DE ECRAN
        delay(2500);
        setfillstyle(SOLID_FILL,BLACK);
        bar(311,0,1520,795);
        setfillstyle(SOLID_FILL,BLACK);
        bar(0,403,308,589);
        return;
    }
    // CITIREA ELEMENTELOR
    char afisare[100];
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(5,600," Ce element doriti");
    outtextxy(5,630,"    sa stergeti? " );
    citesteSir(" Elementul: ", afisare, 5, 660, false); //Functia de citire a textului in mod grafic in sirul afisare
    int element_dat = atoi(afisare);  // conversie ascii -> int din sirul afisare
    delay(300);

    bool sters = false;
    while (p->urm != NULL)
    {
        if ((p->urm)->valoare == element_dat)
        {
            nod *q = p->urm;
            p->urm = (p->urm)->urm;
            delete q;
            sters = true;
        }
        else
            p = p->urm;
    }
    if (prim->valoare == element_dat)
    {
        nod *q = prim;
        prim = prim->urm;
        delete q;
        sters = true;
    }
    if (sters == true)
    {
        setcolor(LIGHTRED);
        bgiout << "S-au sters valorile de " << element_dat << " din lista.";
        outstreamxy(640, 90);
        setcolor(WHITE);
    }
    else
        {
            setcolor(LIGHTRED);
            bgiout << "Nu s-a sters niciun element din lista.";
            outstreamxy(620, 90);
            setcolor(WHITE);
        }
    delay(800);
        // COORDONATELE PRIMULUI NOD
    unsigned int x = 320, y = 170;
    unsigned int xtext = 325, ytext = 185;
    p = prim;
    setcolor(LIGHTMAGENTA);
    settextstyle(4, HORIZ_DIR, 1);
    bgiout << "nod* p = prim;";
    outstreamxy(5,410);
    bgiout << "*prim     *p";
    outstreamxy(320,145);
    settextstyle(4, HORIZ_DIR, 3);
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
        bar(5,430,250,450);
        delay(500);
        // RESCRIERE
        setcolor(LIGHTMAGENTA);
        settextstyle(4, HORIZ_DIR, 1);
        bgiout << "p = p->urm;";
        outstreamxy(5,430);
        setcolor(WHITE);
    }
    // STERGERE PARTE DE ECRAN
    delay(2500);
    setfillstyle(SOLID_FILL,BLACK);
    bar(311,0,1520,795);
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,403,308,589);
}

// ---------- MENIU FUNCTII STERGERE LA LISTE SIMPLU-INLANTUITE ----------
void meniuStergere()
{
    readimagefile("undo.jpg",50,730,250,780);
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
    line(0,590,310,590);

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
            stergerePrimaAparitie(prim);
            goto jump;  // RESET LA BUTON
        }
        else
            if (buton3 == true)
            {
                stergereToateAparitiile(prim);
                goto jump;  // RESET LA BUTON
            }
            else
                if (buton4 == true)
                {
                    //meniuListeSimpluInlantuite();
                }
}

int main()
{
    initwindow(1530, 795, " Meniu Biblioteca cu Liste ");
    meniuStergere();
    getch();
    closegraph();
    return 0;
}