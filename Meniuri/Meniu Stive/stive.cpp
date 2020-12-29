#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <fstream>
using namespace std;

ifstream fin("citire stive.in");

struct nod
{
    int valoare;
    nod * urm;
};

struct stiva
{
    nod* varf;
    int nrElemente;
};
stiva S;

// ------- DECLARARI FUNCTII ---------
void fereastra();
void dimensiuneText(int element);
void descriereStiva();
void deseneazaOutline(int y);
void initializeaza(stiva& S);
void esteVidaStiva(stiva S);
void goleste(stiva &S);
void pop(stiva &S);
void push(stiva &S, int element);
void afiseaza(stiva S);


// ---------- INITIALIZARE FEREASTRA ----------
void fereastra()
{
    initwindow(1530, 795, " Meniu Stive ");
}

void dimensiuneText(int element)
{
     if(element >=0 && element<100)
        settextstyle(4, HORIZ_DIR, 3);
    else
        if(element >= 100	 && element < 1000)
            settextstyle(4, HORIZ_DIR, 2);
        else
            if(element >=1000 && element <100000)
                settextstyle(4, HORIZ_DIR, 1);
}

void deseneazaOutline(int y)
{
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    rectangle(700,600,1000,610); // baza - ramane aceeasi la toate stivele
    floodfill(750, 605, YELLOW);
    rectangle(700,y,710,600); // stanga - coordonata y se schimba in functie de cate elemente sunt in stiva.
    floodfill(705, 401, YELLOW);
    rectangle(990,y,1000,600); // dreapta - coordonata y se schimba in functie de cate elemente sunt in stiva.
    floodfill(991, 401, YELLOW);
    setcolor(WHITE);
}

// ---------- INITIALIZARE STIVA ----------
void initializeaza(stiva& S)
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
    delay(1000);
    setcolor(LIGHTMAGENTA);
    settextstyle(4, HORIZ_DIR, 2);
    bgiout << "stiva S;";
    outstreamxy(10, 470);
    bgiout << "S.varf = NULL;";
    outstreamxy(10, 490);
    S.nrElemente = 0;
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
    setcolor(WHITE);
    if (S.nrElemente == 0)
    {
        delay(500);
        settextstyle(4, HORIZ_DIR, 3);
        bgiout << "Stiva are 0 elemente.";
        outstreamxy(680, 300);
        delay(800);
        setcolor(LIGHTRED);
        outtextxy(635, 350, " Stiva introdusa este vida! ");
        setcolor(WHITE);
    }
    else
    {
        settextstyle(4, HORIZ_DIR, 5);
        outtextxy(320, 300, " Stiva nu este vida! ");
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

// --------- Functia Pop (eliminare din varful stivei) ----------
void pop(stiva &S)
{
    settextstyle(4, HORIZ_DIR, 4);
    setcolor(LIGHTCYAN);
    outtextxy(600, 20, "Eliminare element din stiva");
    rectangle(370,100,1470,200);
    setcolor(WHITE);
    delay(1000);

    // ALGORITMUL de eliminare
    int element, y;
    if (!esteVida(S))
    {
        deseneazaOutline(400);
        nod* varf_nou;
        element = S.varf->valoare;
        varf_nou = S.varf->urm;
        delete S.varf;
        S.varf = varf_nou;
        S.nrElemente--;
        bgiout << "S-a eliminat " << element << " din varful stivei.";
        outstreamxy(600, 400);
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

// ------- Functie de inserare in varful stivei -------
void push(stiva &S, int element)
{
    nod * nod_nou;
    if (esteVida(S))
    {
        S.nrElemente = 1;
        S.varf = new nod;
        S.varf->valoare = element;
        S.varf->urm = NULL;
    }
    else
    {
        S.nrElemente++;
        nod_nou = new nod;
        nod_nou->valoare = element;
        nod_nou->urm = S.varf;
        S.varf = nod_nou;
    }
}

// ------- Functie de golire a stivei -------
void goleste(stiva &S)
{
    while (!esteVida(S))
        pop(S);
}

// ------- Functie de afisare a stivei -------
void afiseaza(stiva S)
{
    nod* nod_curent;
    nod_curent = S.varf;
    while (nod_curent != NULL)
    {
        cout << nod_curent->valoare << ",";
        nod_curent = nod_curent->urm;
    }
    cout << endl;
}

// ---------- POZA CU LISTA SI DESCRIEREA EI (inainte de functii) ----------
void descriereStiva()
{
    cleardevice();
    readimagefile("next.jpg",640,710,850,790);
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

void meniuStive()
{
    descriereStiva();
    readimagefile("undo.jpg",30,730,250,780);
    settextstyle(4, HORIZ_DIR, 4);
    outtextxy(0, 10, " Alege functia ");
    //outtextxy(1230, 10, " Alege functia ");
    // BUTON 1
    readimagefile("init stiva.jpg",30, 50, 270, 100);
    // BUTON 2
    readimagefile("stiva vida.jpg",30, 120, 270, 170);
    // BUTON 3
    readimagefile("golire.jpg",30, 190, 270, 240);
    // BUTON 4
    readimagefile("pop.jpg",30, 260, 270, 310);
    // BUTON 5
    readimagefile("push.jpg",30, 330, 270, 380);
    // BUTON 6
    readimagefile("afis stiva.jpg",30, 400, 270, 450);

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
        initializeaza(S);
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
                goleste(S);
                goto jump;
            }
            else
                if (buton4 == true)
                {
                    pop(S);
                    goto jump;
                }
                else
                    if (buton5 == true)
                    {
                        push(S, 6);
                        goto jump;
                    }
                    else
                        if (buton6 == true)
                        {
                            afiseaza(S);
                            goto jump;
                        }
                        else
                            if (butonUndo == true)
                            {
                                //meniuPrincipal();
                                goto jump;
                            }
}

int main()
{

    fereastra();
    meniuStive();

    /* LINII DE DELIMTARE
    line(300,795,300,0);  // linie verticala
    line(0,460,300,460); // linie orizontala
    initializeaza(S);
    */

    getch();
    closegraph();
    return 0;
}
