#include<iostream>
#include<windows.h>
#include<MMsystem.h>
#include <graphics.h>
#include <queue>
#include <fstream>
using namespace std;

ifstream fin("citire.in");

/// CE MAI TREBUIE FACUT
/*
- implementare citire din fereastra grafica la meniu stergere
- adaugare sunete PlaySound(TEXT("yourMusicFile.wav"), NULL, SND_SYNC);
*/

// ---------- INITIALIZARE STRUCTURI DE DATE ----------
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

// ------------- DECLARARE FUNCTII INTERFATA------------
void fereastra();
void dimensiuneText(int element);
void meniuPrincipal();
void cleanup();
void interfataGrafica();

// ------------- DECLARARE FUNCTII LA LISTE SIMPLU INLANTUITE ------------
void meniuListeSimpluInlantuite();
void graficaCitireListeSimplu();
void creareListaSimpluInlantuita(nod*& prim, int n, int Valoarea[20]);
void citesteSir(char text[100], char afisare[100], int x, int y, bool stergere);
void citireListeSimpluInlantuite();
void descriereListaSimplu();
void listaVida(nod* prim);
void lungimeLista(nod* prim);
void inserareInceput(nod*& prim);
void adaugareSfarsit(nod*& prim, int val);
void inserareSfarsit(nod*& prim);
void inserareDupaNod(nod*& prim, int element_dat);
void meniuInserare();
void stergerePrimul(nod*& prim);
void stergerePrimaAparitie(nod*& prim, int element_dat);
void stergereToateAparitiile(nod*& prim, int element_dat);
void meniuStergere();
void afisareListaSimpluInlantuita(nod *prim);

// ------------- DECLARARE FUNCTII LA STIVE ------------
void meniuStive();
void citesteSir(char text[100], char afisare[100], int x, int y, bool stergere);
void descriereStiva();
void deseneazaOutline(int y);
void deseneazaElemente(stiva S);
void initializareStiva(stiva &S);
void esteVidaStiva(stiva S);
bool esteVida(stiva S); // functie de verificare, fara grafica
void golesteStiva(stiva &S);
void pop(stiva &S); // functie de eliminare fara grafica
void eliminareStiva();
void push(stiva &S, int element); // functie de inserare fara grafica
void adaugareStiva();
void afisareStiva(stiva S);


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

void graficaCitireListeSimplu()
{
    citireListeSimpluInlantuite();
    afisareListaSimpluInlantuita(prim);
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
    readimagefile("undo.jpg",30,730,250,780);
    settextstyle(4, HORIZ_DIR, 4);
    outtextxy(275, 80, " Aflarea lungimii unei liste simplu-inlantuite");
    nod *p = prim;
    unsigned int x = 20, y = 250;
    unsigned int xtext = 25, ytext = 265;
    unsigned int lungime = 0;
    while (p != NULL)
    {
        if (x > 1400) // daca ies din ecran
        {
            // COORDONATELE URMATORULUI RAND DACA SE AJUNGE LA CAPAT DE ECRAN
            x = 20;
            y += 100;
            xtext = 25;
            ytext += 100;
        }
        else
            if (y > 725) // daca ies din ecran
            {
                delay(2000);
                setfillstyle(SOLID_FILL,BLACK);
                bar(0,120,1520,728);
                delay(500);
                settextstyle(4, HORIZ_DIR, 4);
                setcolor(LIGHTRED);
                bgiout << "Eroare: Imposibil de afisat!";
                outstreamxy(460, 300);
                bgiout << "Prea multe valori in lista.";
                outstreamxy(480, 340);
                setcolor(WHITE);
                delay(1000);
                break;
            }
            else
                if (x <= 1400)  // daca nu ies din ecran
                {
                    lungime++;
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
                    bgiout << lungime;
                    outstreamxy(xtext + 50, ytext - 40);
                    // COORDONATELE URMATORULUI NOD
                    x += 200;
                    xtext += 200;
                    p = p->urm;
                    delay(500);
                }
    }
    // AFISARE IN FEREASTRA GRAFICA
    settextstyle(4, HORIZ_DIR, 3);
    setcolor(LIGHTCYAN);
    outtextxy(500, 150, "Lungimea listei este: ");
    settextstyle(4, HORIZ_DIR, 4);
    bgiout << lungime << endl;
    outstreamxy(850, 145);
    setcolor(WHITE);
    bool gata = false, buton = false;
    int xx,yy;
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            xx = mousex();
            yy = mousey();
            if(xx >= 30 && xx <= 250 && yy >= 730 && yy <= 780) //buton
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

//------------- FUNCTII PENTRU INSERARE --------------
void inserareInceput(nod*& prim)
{
    settextstyle(4, HORIZ_DIR, 3);
    setcolor(LIGHTCYAN);
    outtextxy(440, 20, " Inserarea unui nod la inceputul unei liste simplu-inlantuite");
    setcolor(WHITE);
    delay(800);

    // CITIREA ELEMENTELOR
    char afisare[100];
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(5,600," Ce element doriti");
    outtextxy(5,630,"    sa adaugati? " );
    citesteSir(" Elementul: ", afisare, 5, 660, false); //Functia de citire a textului in mod grafic in sirul afisare
    int val = atoi(afisare);  // conversie ascii -> int din sirul afisare

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
    settextstyle(4, HORIZ_DIR, 1);
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
    delay(2500);
    setfillstyle(SOLID_FILL,BLACK);
    bar(311,0,1520,795);
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,403,308,589);
    bar(0,592,308,729);
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

void inserareSfarsit(nod*& prim)
{
    settextstyle(4, HORIZ_DIR, 3);
    setcolor(LIGHTCYAN);
    outtextxy(440, 20, " Inserarea unui nod la sfarsitul unei liste simplu-inlantuite");
    setcolor(WHITE);
    delay(800);

    // CITIREA ELEMENTELOR
    char afisare[100];
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(5,600," Ce element doriti");
    outtextxy(5,630,"    sa adaugati? " );
    citesteSir(" Elementul: ", afisare, 5, 660, false); //Functia de citire a textului in mod grafic in sirul afisare
    int val = atoi(afisare);  // conversie ascii -> int din sirul afisare

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
    delay(2500);
    setfillstyle(SOLID_FILL,BLACK);
    bar(311,0,1520,795);
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,403,308,589);
    bar(0,592,308,729);
}

void inserareDupaNod(nod*& prim)
{
    settextstyle(4, HORIZ_DIR, 3);
    setcolor(LIGHTCYAN);
    outtextxy(580, 20, " Inserarea unui nod dupa un element dat");
    setcolor(WHITE);
    delay(800);

    // CITIREA ELEMENTELOR
    settextstyle(4, HORIZ_DIR, 2);
    char afisare1[100], afisare2[100];;
    outtextxy(5,600," Ce element doriti");
    outtextxy(5,620,"    sa adaugati? " );
    citesteSir(" Elementul: ", afisare1, 5, 640, false); //Functia de citire a textului in mod grafic in sirul afisare
    int val = atoi(afisare1);  // conversie ascii -> int din sirul afisare
    outtextxy(5,660," Dupa care element?");
    citesteSir(" Elementul: ", afisare2, 5, 680, false); //Functia de citire a textului in mod grafic in sirul afisare
    int el = atoi(afisare2);  // conversie ascii -> int din sirul afisare

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
        if (q->valoare == el)
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
    delay(2500);
    setfillstyle(SOLID_FILL,BLACK);
    bar(311,0,1520,795);
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,403,308,589);
    bar(0,592,308,729);
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
        inserareInceput(prim);
        goto jump;  // RESET LA BUTON
    }
    else
        if (buton2 == true)
        {
            inserareSfarsit(prim);
            goto jump;  // RESET LA BUTON
        }
        else
            if (buton3 == true)
            {
                inserareDupaNod(prim);
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
        // ----------- AFISARE ------------
    settextstyle(4, HORIZ_DIR, 3);
    setcolor(LIGHTCYAN);
    outtextxy(470, 20, " Stergerea primului nod din lista simplu-inlantuita");
    setcolor(WHITE);
    delay(800);
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
    nod* p = prim;
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
    bar(0,403,308,795);
}

void stergerePrimaAparitie(nod *&prim, int element_dat)
{
        // ----------- AFISARE ------------
    settextstyle(4, HORIZ_DIR, 3);
    setcolor(LIGHTCYAN);
    outtextxy(400, 20, " Stergerea primei aparitii a unui nod din lista simplu-inlantuita");
    rectangle(370,70,1470,130);
    delay(300);
    nod *p = prim;
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
        bgiout << "S-a sters prima valoare de " << element_dat << " din lista.";
        outstreamxy(620, 90);
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

void stergereToateAparitiile(nod *&prim, int element_dat)
{
    // ----------- AFISARE ------------
    settextstyle(4, HORIZ_DIR, 3);
    setcolor(LIGHTCYAN);
    outtextxy(370, 20, " Stergerea tuturor aparitiilor unui nod din lista simplu-inlantuita");
    rectangle(370,70,1470,130);
    delay(300);

    nod *p = prim;
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
    bar(0,403,308,795);
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
    readimagefile("undo.jpg",30,730,250,780);
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
    jump:
    bool gata = false, buton = false;
    int xx,yy;
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            xx = mousex();
            yy = mousey();
            if(xx >= 30 && xx <= 250 && yy >= 730 && yy <= 780)
            {
                gata = true;
                buton = true;
            }
        }
    } while (!gata);
    if (buton == true)
    {
        meniuListeSimpluInlantuite();
        goto jump;
    }
    delay(2500);
    cleardevice();
}

// ---------- POZA CU LISTA SI DESCRIEREA EI (inainte de functii) ----------
void descriereListaSimplu()
{
    cleardevice();
    readimagefile("undo.jpg",30,730,250,780);
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

    bool gata = false, butonNext = false, butonUndo = false;
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
                butonNext = true;
            }
            else
                if (x >= 30 && x <= 250 && y >= 730 && y <= 780)
                {
                    gata = true;
                    butonUndo = true;
                }
        }
    } while (!gata);
    if (butonNext == true)
    {
        cleardevice();
        return;
    }
    else
        if (butonUndo == true)
        {
            cleardevice();
            meniuPrincipal();
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
        graficaCitireListeSimplu();
    }
    else
        if (buton2 == true)  // Verificare daca lista este vida
        {
            listaVida(prim);
        }
        else
            if (buton3 == true)  // Functie pt aflarea lungimii listei
            {
                lungimeLista(prim);
            }
            else
                if (buton4 == true)  // Functii la INSERARE element in liste
                {
                    meniuInserare();
                }
                else
                    if (buton5 == true)  // Functii la STERGERE element din liste
                    {
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

// ----------------  STIVE  -------------
void deseneazaOutline(int y)
{
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    rectangle(700,750,1000,760); // baza - ramane aceeasi la toate stivele
    floodfill(701,755, YELLOW);
    rectangle(700,y,710,750); // stanga - coordonata y se schimba in functie de cate elemente sunt in stiva.
    floodfill(701,y + 1, YELLOW);
    rectangle(990,y,1000,750); // dreapta - coordonata y se schimba in functie de cate elemente sunt in stiva.
    floodfill(991,y + 1, YELLOW);
    setcolor(WHITE);
}

// Grafica desenare elementele din stiva
void deseneazaElemente(stiva S)
{
    nod* top = S.varf;
    /*
    inaltimea fiecarei pozei = 40px
    distanta dintre poze = 5px
    */
    // ADAUGARE POZE
    if (S.nrElemente <= 11)
    {
        // MARGINILE STIVEI
        deseneazaOutline(700 - (S.nrElemente * 45));
        int h = 0;
        for (int i = 1; i <= S.nrElemente; i++)
        {
            readimagefile("stiva.jpg",730,700 - h,970,740 - h);
            h += 45;
            S.varf = S.varf->urm;
            delay(200);
        }
        int hmax = 700 - h + 55;
        for (int i = 1; i <= S.nrElemente; i++)
        {
            settextstyle(4, HORIZ_DIR, 3);
            bgiout << top->valoare;
            outstreamxy(800,hmax);
            delay(300);
            hmax += 45;
            top = top->urm;
        }
    }
    else
    {
        deseneazaOutline(500);
        settextstyle(4, HORIZ_DIR, 3);
        delay(500);
        setcolor(WHITE);
        outtextxy(377,130,"Eroare! S-a depasit numarul maxim de elemente. Imposibil de afisat.");
    }
}

// ---------- INITIALIZARE STIVA ----------
void initializareStiva(stiva& S)
{
    settextstyle(4, HORIZ_DIR, 4);
    setcolor(LIGHTCYAN);
    outtextxy(630, 20, " Initializare Stiva");
    delay(400);
    outtextxy(980, 20, ".");
    delay(400);
    outtextxy(1000, 20, ".");
    delay(400);
    outtextxy(1020, 20, ".");
    setcolor(WHITE);

    delay(1000);
    deseneazaOutline(200);

    S.varf = NULL;
    S.nrElemente = 0;

    delay(1000);
    setcolor(LIGHTMAGENTA);
    settextstyle(4, HORIZ_DIR, 2);
    bgiout << "stiva S;";
    outstreamxy(10, 470);
    bgiout << "S.varf = NULL;";
    outstreamxy(10, 490);
    delay(500);
    bgiout << "S.nrElemente = 0;";
    outstreamxy(10, 510);
    setcolor(WHITE);

    // STERGERE CE AM SCRIS
    delay(6000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(305,0,1520,795);
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,465,295,725);
}

// ---------- STIVA VIDA ? ----------
void esteVidaStiva(stiva S)
{
    settextstyle(4, HORIZ_DIR, 4);
    setcolor(LIGHTCYAN);
    outtextxy(600, 20, " Verificare stiva vida");
    delay(400);
    outtextxy(1020, 20, ".");
    delay(400);
    outtextxy(1040, 20, ".");
    delay(400);
    outtextxy(1060, 20, ".");
    rectangle(370,100,1470,200);
    setcolor(WHITE);
    if (S.nrElemente == 0)
    {
        delay(500);
        deseneazaOutline(400);
        delay(500);
        settextstyle(4, HORIZ_DIR, 3);
        bgiout << "Stiva are 0 elemente.";
        outstreamxy(680, 110);
        delay(800);
        setcolor(LIGHTRED);
        outtextxy(635, 150, " Stiva introdusa este vida! ");
        setcolor(WHITE);
    }
    else
    {
        delay(500);
        deseneazaElemente(S);
        delay(500);
        settextstyle(4, HORIZ_DIR, 3);
        outtextxy(680, 140, " Stiva nu este vida! ");
    }

    // STERGERE CE AM SCRIS
    delay(6000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(305,0,1520,795);
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,465,295,725);
}

// ---------- STIVA VIDA - functie fara text ----------
bool esteVida(stiva S)
{
    return (S.nrElemente == 0);
}

//--------- ALGORITM ELIMINARE ELEMENT DIN MEMORIE ---------
void pop(stiva &S)
{
    int element;
    if (!esteVida(S))
    {
        nod* varf_nou;
        element = S.varf->valoare;
        varf_nou = S.varf->urm;
        delete S.varf;
        S.varf = varf_nou;
        S.nrElemente--;
        return;
    }
    else return;
}

// --------- Functia eliminare in mod grafic----------
void eliminareStiva()
{
    // TITLU + DREPTUNGHIUL UNDE SE VA SCRIE INFORMATIA - DACA S-A ELIMINAT SAU NU
    settextstyle(4, HORIZ_DIR, 4);
    setcolor(LIGHTCYAN);
    outtextxy(600, 20, "Eliminare element din stiva");
    rectangle(370,100,1470,200);
    setcolor(WHITE);
    delay(1000);
    // ALGORITMUL DE ELIMINARE
    if (!esteVida(S))
    {
        int top = S.varf->valoare;
        // DESENARE STIVA
        deseneazaElemente(S);
        delay(500);
        pop(S);
        // AFISAREA GRAFICA
        setcolor(LIGHTMAGENTA);
        settextstyle(4, HORIZ_DIR, 1);
        bgiout << "nod* vf_nou;";
        outstreamxy(10, 470);
        delay(500);
        bgiout << "el = S.varf->valoare;";
        outstreamxy(10, 500);
        delay(500);
        bgiout << "vf_nou = S.varf->urm;";
        outstreamxy(10, 530);
        delay(500);
        bgiout << "delete S.varf;";
        outstreamxy(10, 560);
        delay(500);
        readimagefile("black.jpg", 730, 700 - (S.nrElemente * 45), 970, 740 - (S.nrElemente * 45));
        delay(500);
        bgiout << "S.varf = vf_nou;";
        outstreamxy(10, 590);
        delay(500);
        bgiout << "S.nrElemente--;";
        outstreamxy(10, 620);
        delay(500);
        setcolor(WHITE);
        settextstyle(4, HORIZ_DIR, 3);
        bgiout << "S-a eliminat " << top << " din varful stivei.";
        outstreamxy(640, 130);
    }
    else
    {
        delay(500);
        deseneazaOutline(400);
        delay(1000);
        settextstyle(4, HORIZ_DIR, 3);
        bgiout << "Stiva are 0 elemente.";
        outstreamxy(390, 110);
        delay(800);
        setcolor(LIGHTRED);
        outtextxy(390, 140, "Eroare! Nu se poate elimina niciun element. Stiva este goala.");
        setcolor(WHITE);
    }

    // STERGERE CE AM SCRIS
    delay(10000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(305,0,1520,795);
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,465,295,725);
}

//--------- ALGORITM ADAUGARE ELEMENT IN MEMORIE ---------
void push(stiva &S, int el)
{
    nod* nod_nou;
    if (esteVida(S))
    {
        S.nrElemente = 1;
        S.varf = new nod;
        S.varf->valoare = el;
        S.varf->urm = NULL;
    }
    else
    {
        S.nrElemente++;
        nod_nou = new nod;
        nod_nou->valoare = el;
        nod_nou->urm = S.varf;
        S.varf = nod_nou;
    }
}

// ------- Functie de inserare in grafica -------
void adaugareStiva()
{
    // TITLU + DREPTUNGHIUL UNDE SE VA SCRIE INFORMATIA - DACA S-A ADAUGAT SAU NU
    settextstyle(4, HORIZ_DIR, 4);
    setcolor(LIGHTCYAN);
    outtextxy(600, 20, "Adaugare element in stiva");
    rectangle(370,100,1470,200);
    rectangle(1150,500,1470,700);  // partea de citire
    setcolor(WHITE);
    delay(1000);
    // CITIREA ELEMENTELOR
    char afisare[100];
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(1160,510," Ce element doriti");
    outtextxy(1160,540,"    sa adaugati? " );
    citesteSir(" Elementul: ", afisare, 1155, 600, false); //Functia de citire a textului in mod grafic in sirul afisare
    int val = atoi(afisare);  // conversie ascii -> int din sirul afisare
    push(S,val);
    // ALGORITMUL
    if (!esteVida(S))
    {
        // DESENARE STIVA
        deseneazaElemente(S);
        delay(500);
        int top = S.varf->valoare;
        // AFISAREA GRAFICA
        setcolor(LIGHTMAGENTA);
        settextstyle(4, HORIZ_DIR, 1);
        bgiout << "S.nrElemente++;";
        outstreamxy(10, 470);
        delay(500);
        bgiout << "vf_nou = new nod;";
        outstreamxy(10, 500);
        delay(500);
        deseneazaOutline(700 - S.nrElemente * 45);
        delay(500);
        readimagefile("stiva.jpg",730,700 - (S.nrElemente - 1) * 45,970,740 - (S.nrElemente - 1) * 45);
        delay(500);
        setcolor(LIGHTMAGENTA);
        bgiout << "vf_nou->valoare = el;";
        outstreamxy(10, 530);
        delay(500);
        setcolor(WHITE);
        settextstyle(4, HORIZ_DIR, 3);
        bgiout << top;
        outstreamxy(800, 710 - (S.nrElemente - 1) * 45);
        delay(500);
        settextstyle(4, HORIZ_DIR, 1);
        setcolor(LIGHTMAGENTA);
        bgiout << "vf_nou->urm = S.varf;";
        outstreamxy(10, 560);
        delay(500);
        bgiout << "S.varf = vf_nou;";
        outstreamxy(10, 590);
        delay(500);
        setcolor(WHITE);
        settextstyle(4, HORIZ_DIR, 3);
        bgiout << "S-a adaugat " << top << " in varful stivei.";
        outstreamxy(640, 130);
    }
    else
    {
        delay(500);
        deseneazaOutline(400);
        delay(500);
        settextstyle(4, HORIZ_DIR, 3);
        bgiout << "Stiva are 0 elemente.";
        outstreamxy(390, 110);
        delay(800);
        int top = S.varf->valoare;
        // AFISAREA GRAFICA
        setcolor(LIGHTMAGENTA);
        settextstyle(4, HORIZ_DIR, 1);
        bgiout << "S.nrElemente = 1;";
        outstreamxy(10, 470);
        delay(500);
        bgiout << "S.varf = new nod;";
        outstreamxy(10, 500);
        delay(500);
        bgiout << "S.varf->valoare = el;";
        outstreamxy(10, 530);
        delay(500);
        bgiout << "S.varf->urm = NULL;";
        outstreamxy(10, 560);
        delay(500);
        setcolor(WHITE);
        settextstyle(4, HORIZ_DIR, 3);
        bgiout << "S-a adaugat " << top << " in varful stivei.";
        outstreamxy(640, 130);

    }
    // STERGERE CE AM SCRIS
    delay(5000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(305,0,1520,795);
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,465,295,725);
}

// ------- Functie de golire a stivei -------
void golesteStiva(stiva &S)
{
    // TITLU + DREPTUNGHIUL UNDE SE VA SCRIE INFORMATIA - DACA S-A ELIMINAT SAU NU
    settextstyle(4, HORIZ_DIR, 4);
    setcolor(LIGHTCYAN);
    rectangle(370,100,1470,200);
    outtextxy(720, 20, "Golire stiva");
    delay(400);
    outtextxy(960, 20, ".");
    delay(400);
    outtextxy(980, 20, ".");
    delay(400);
    outtextxy(1000, 20, ".");
    setcolor(WHITE);
    delay(1000);
    // ALGORITMUL DE GOLIRE
    if(esteVida(S))
    {
        delay(500);
        deseneazaOutline(400);
        delay(1000);
        settextstyle(4, HORIZ_DIR, 3);
        bgiout << "Stiva are 0 elemente.";
        outstreamxy(390, 110);
        delay(800);
        setcolor(LIGHTRED);
        outtextxy(390, 140, "Eroare! Nu se poate goli stiva.");
        setcolor(WHITE);

        // STERGERE CE AM SCRIS
        delay(4000);
        setfillstyle(SOLID_FILL,BLACK);
        bar(305,0,1520,795);
        setfillstyle(SOLID_FILL,BLACK);
        bar(0,465,295,725);
        return;
    }
    deseneazaElemente(S);
    while (!esteVida(S))
    {
        int top = S.varf->valoare;
        // DESENARE STIVA
        delay(500);
        pop(S);
        delay(500);
        // AFISARE GRAFICA
        setcolor(LIGHTMAGENTA);
        settextstyle(4, HORIZ_DIR, 1);
        bgiout << "pop(S);";
        outstreamxy(10, 470);
        delay(500);
        readimagefile("black.jpg", 730, 700 - (S.nrElemente * 45), 970, 740 - (S.nrElemente * 45));
        delay(500);
        readimagefile("black.jpg", 10,470,110,495); // stergere "pop(s)"
        setcolor(WHITE);
        settextstyle(4, HORIZ_DIR, 3);
        readimagefile("black.jpg", 371,101,1469,199); // stergere din chenar
        bgiout << "S-a eliminat " << top << " din varful stivei.";
        outstreamxy(640, 130);
        delay(2000);
    }
    // STERGERE CE AM SCRIS
    delay(6000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(305,0,1520,795);
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,465,295,725);
}

// ------- Functie de afisare a stivei -------
void afisareStiva(stiva S)
{
    settextstyle(4, HORIZ_DIR, 4);
    setcolor(LIGHTCYAN);
    outtextxy(580, 20, "Afisarea elementelor din stiva");
    setcolor(WHITE);
    delay(500);

    deseneazaElemente(S);

    // STERGERE CE AM SCRIS
    delay(6000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(305,0,1520,795);
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,465,295,725);
}

// ---------- POZA CU LISTA SI DESCRIEREA EI (inainte de functii) ----------
void descriereStiva()
{
    cleardevice();
    readimagefile("next.jpg",640,710,850,790);
    readimagefile("undo.jpg",30,730,250,780);
    settextstyle(4, HORIZ_DIR, 3);
    setcolor(LIGHTCYAN);
    outtextxy(570,50, "Informatii despre Stive");
    setcolor(WHITE);
    settextstyle(4, HORIZ_DIR, 1);
    outtextxy(250, 100, "       Stiva (stack)  este o  structura de date liniara abstracta,  pentru care sunt");
    outtextxy(250, 130, "definite operatiile  de  adaugare a unui  element si eliminare a unui element si");
    outtextxy(250, 160, "aceste operatii se realizeaza la un singur capat al structurii, numit varful stivei.");
    outtextxy(250, 190, "       In  timpul  operatiilor cu  stiva avem  acces numai  la  elementul din varful");
    outtextxy(250, 220, "stivei. Deoarece operatiile cu elementele stivei se fac la acelasi capat, spunem");
    outtextxy(250, 250, "ca stiva este o structura de date de tip LIFO - Last In First Out.");
    readimagefile("stiva descriere.jpg",480,300,890,650);
    bool gata = false, butonNext = false, butonUndo = false;
    int x,y;
    do
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
            if (x >= 640 && x <= 850 && y >= 710 && y <= 790)
            {
                gata = true;
                butonNext = true;
            }
            else
                if (x >= 30 && x <= 250 && y >= 730 && y <= 780)
                {
                    gata = true;
                    butonUndo = true;
                }
        }
    } while (!gata);
    if (butonNext == true)
    {
        cleardevice();
        return;
    }
    else
        if (butonUndo == true)
        {
            cleardevice();
            meniuPrincipal();
        }
    delay(40000);   // 1 sec =  1000 ms
    cleardevice();
}

void meniuStive()
{
    descriereStiva();
    readimagefile("undo.jpg",30,730,250,780);
    settextstyle(4, HORIZ_DIR, 4);
    outtextxy(0, 10, " Alege functia ");
    readimagefile("init stiva.jpg",30, 50, 270, 100); // BUTON 1
    readimagefile("stiva vida.jpg",30, 120, 270, 170); // BUTON 2
    readimagefile("golire.jpg",30, 190, 270, 240); // BUTON 3
    readimagefile("pop.jpg",30, 260, 270, 310); // BUTON 4
    readimagefile("push.jpg",30, 330, 270, 380); // BUTON 5
    readimagefile("afis stiva.jpg",30, 400, 270, 450); // BUTON 6

    // LINII DE DELIMTARE
    line(300,795,300,0);
    line(0,460,300,460);

    // LABEL PENTRU A RESETA BUTONUL
    jump:
    bool gata = false;
    bool buton1 = false, buton2 = false, buton3 = false, buton4 = false, buton5 = false, buton6 = false, butonUndo = false;
    int x,y;
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
            if(x >= 30 && x <= 270 && y >= 50 && y <= 100) // initilizare
            {
                gata = true;
                buton1 = true;
            }
            else
                if(x >= 30 && x <= 270 && y >= 120 && y <= 170)  // stiva vida
                {
                    gata = true;
                    buton2 = true;
                }
                else
                    if(x >= 30 && x <= 270 && y >= 199 && y <= 240) // golire stiva
                    {
                        gata = true;
                        buton3 = true;
                    }
                    else
                        if(x >= 30 && x <= 270 && y >= 260 && y <= 310) // pop
                        {
                            gata = true;
                            buton4 = true;
                        }
                        else
                            if(x >= 30 && x <= 270 && y >= 330 && y <= 380) // push
                            {
                                gata = true;
                                buton5 = true;
                            }
                            else
                                if(x >= 30 && x <= 270 && y >= 400 && y <= 450) // afisare
                                {
                                    gata = true;
                                    buton6 = true;
                                }
                                else
                                    if (x >=30 && x <= 730 && y >= 250 && y <= 780) // revenire la meniul principal
                                    {
                                        gata = true;
                                        butonUndo = true;
                                    }
        }
    } while (!gata);
    if (buton1 == true)
    {
        initializareStiva(S);
        goto jump;  // RESET LA BUTON
    }
    else
        if (buton2 == true)
        {
            esteVidaStiva(S);
            goto jump;
        }
        else
            if (buton3 == true)
            {
                golesteStiva(S);
                goto jump;
            }
            else
                if (buton4 == true)
                {
                    eliminareStiva();
                    goto jump;
                }
                else
                    if (buton5 == true)
                    {
                        adaugareStiva();
                        goto jump;
                    }
                    else
                        if (buton6 == true)
                        {
                            afisareStiva(S);
                            goto jump;
                        }
                        else
                            if (butonUndo == true)
                            {
                                cleardevice();
                                meniuPrincipal();
                                goto jump;
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
            // meniuListeDubluInlantuite();
        }
        else
            if(buton3 == true)
            {
                 meniuStive();
            }
            else
                if(buton4 == true)
                {
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
    interfataGrafica();
    return 0;
}
