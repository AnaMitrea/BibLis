#include <iostream>
#include <fstream>
#include <graphics.h>
#include <winbgim.h>
using namespace std;

ifstream fin("citire1.in");
ofstream fout("afisare1.out");

// ---------- INITIALIZARE STRUCTURI DE DATE ----------
struct nod
{
    int valoare;
    struct nod* urm;
};

/*
struct stiva
{
    struct nod* varf;
    unsigned int lungime;
};
*/

//nod *prim, *ultim;

// ---------- INITIALIZARE FEREASTRA ----------
void fereastra()
{
    initwindow(1510, 795, " Operatii cu liste simplu inlantuite ");
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

int lungimeaListeiSimpluInlantuite(nod *prim)
{
    unsigned int lungime = 0;
    nod *p = prim;
    while(p != NULL)
    {
        lungime++;
        p = p->urm;
    }
    return lungime;
}

// ------------ LISTA VIDA -------------
void listaVida(nod*& prim)
{
    settextstyle(4, HORIZ_DIR, 4);
    outtextxy(400, 100, " Verificare daca lista este vida");

    delay(1000);
    settextstyle(4, HORIZ_DIR, 4);
    if(prim == NULL)
        outtextxy(430, 300, " Lista introdusa este vida! ");
    else
        outtextxy(410, 300, " Lista introdusa nu este vida! ");
    delay(4000);
    cleardevice();
}

void afisarelungimeLista(nod *prim)
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
    fout << "Lungimea listei este: " << lungime << '\n';

    delay(4000);
    cleardevice();
}

//------------- FUNCTII PENTRU INSERARE --------------
void inserareInceput(nod*& prim, int val)
{
    settextstyle(4, HORIZ_DIR, 4);
    outtextxy(170, 100, " Inserarea unui nod la inceputul unei liste simplu-inlantuite");

    unsigned int x = 20, y = 250;
    unsigned int xtext = 25, ytext = 265;

    // INSERARE
    nod *p = new nod;
    p->valoare = val;
    p->urm = prim;
    if (prim == NULL)
        readimagefile("nod inserat lista cu null.jpg", x, y - 10, x + 200, y + 50);
    else
        readimagefile("nod inserat lista.jpg", x, y - 10, x + 200, y + 50);
    prim = p;
    p = prim;

    // DIMENSIUNEA TEXTULUI IN FIECARE NOD
    dimensiuneText(p->valoare);

    // AFISARE IN MODUL GRAFIC
    fout << p->valoare << ' ';
    bgiout << p->valoare;
    outstreamxy(xtext, ytext);;

    // COORDONATELE URMATORULUI NOD
    x += 200;
    xtext += 200;
    p = p->urm;

    while (p != NULL)
    {
        if (x <= 1400)  // daca nu iese din ecran
        {
            fout << p->valoare << ' ';

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
    fout << '\n';
    delay(4000);
    cleardevice();
}

void inserareSfarsit(nod*& prim, int val)
{
    settextstyle(4, HORIZ_DIR, 4);
    outtextxy(170, 100, " Inserarea unui nod la sfarsitul unei liste simplu-inlantuite");

    // INSERAREA
    nod *p = new nod;
    p->valoare = val;
    p->urm = NULL;
    if (prim == NULL)
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

    // AFISAREA FUNCTIEI IN MODUL GRAFIC
    p = prim;
    unsigned int x = 20, y = 250;
    unsigned int xtext = 25, ytext = 265;

    while (p != NULL)
    {
        if(x <= 1400)  // daca nu iese din ecran
        {
            fout << p->valoare << ' ';

            // AFISAREA NODULUI CORESPUNZATOR
            if (p->urm == NULL)
                readimagefile("nod inserat lista cu null.jpg", x, y - 10, x + 270, y + 50);
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
    fout << '\n';
    delay(4000);
    cleardevice();
}

// NU ESTE COMPLETA
void inserareDupaNod(nod*& prim, int element_dat, int val)
{
    settextstyle(4, HORIZ_DIR, 4);
    outtextxy(40, 100, " Inserarea unui nod dupa un element dat intr-o lista simplu-inlantuita");
    delay(350);

    nod *p = new nod;
    p->valoare = val;
    p->urm = NULL;

    unsigned int x = 20, y = 250;
    unsigned int xtext = 25, ytext = 265;
    bool inserat = false;
    nod *q = prim;

    if (prim == NULL) // daca e vida, primul element = elementul inserat
    {
        prim = p;
        readimagefile("nod inserat lista cu null.jpg", 450, 250, 1000, 400);
        settextstyle(4, HORIZ_DIR, 4);

        // AFISARE IN MODUL GRAFIC
        bgiout << p->valoare;
        outstreamxy(470, 320);
        fout << "Nodul inserat dupa "<< element_dat << " este " << p->valoare << endl;
        return;
    }
    while (q != NULL)
    {
        if (x <= 1400)  // daca nu iese din ecran
        {
            fout << q->valoare << ' ';

            if (q->valoare == element_dat)
            {
                p->urm = q->urm;
                q->urm = p;
                readimagefile("nod lista.jpg", x, y - 10, x + 200, y + 50);
                inserat = 1;
            }
            else
            {
                if (q->urm == NULL)
                    readimagefile("nod lista cu null.jpg", x, y, x + 250, y + 50);
                else
                    readimagefile("nod lista.jpg", x, y, x + 200, y + 50);
            }
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
        else
        {
            // COORDONATELE URMATORULUI RAND
            x = 20;
            y += 100;
            xtext = 25;
            ytext += 100;
        }
    }
    if (inserat == false)
    {
        settextstyle(4, HORIZ_DIR, 3);
        outtextxy(360, 180, " Nu s-a inserat nodul in lista simplu-inlantuita!");
    }
    delay(4000);
    cleardevice();
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
    if(prim == NULL)
        fout << "LISTA VIDA";
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
            fout << p->valoare << ' ';

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
    delay(4000);
    cleardevice();
}

int main()
{
    nod *prim, *ultim;

    fereastra();

    creareListaSimpluInlantuita(prim,ultim);

    listaVida(prim);

    inserareInceput(prim, 500);
    inserareSfarsit(prim, 900);
    inserareDupaNod(prim, 200, 59);

    afisarelungimeLista(prim);

    //afisareListaSimpluInlantuita(prim);

    getch();
    closegraph();

    return 0;
}
