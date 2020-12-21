#include <iostream>
#include <fstream>
#include <graphics.h>
#include <winbgim.h>
using namespace std;

ifstream fin("citire.in");
ofstream fout("afisare.out");

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

// ---------- INITIALIZARE FEREASTRA ----------
void fereastra()
{
    initwindow(1510, 795, " Meniu Biblioteca cu Liste ");

}

// ---------- BUTON UNDO ----------
void butonUNDO()
{
    readimagefile("undo.jpg",20,700,250,760);

    /*
    bool gata = false;
    int x,y;
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
            if(x >= 20 && x <= 250 && y >= 630 && y <= 680)
            {
                gata = true;
            }
    }
    } while (!gata);
    */
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
void listaVida(nod*& prim)
{
    butonUNDO();
    settextstyle(4, HORIZ_DIR, 4);
    outtextxy(380, 100, " Verificare daca lista este vida");

    nod *p = prim;
    settextstyle(4, HORIZ_DIR, 3);
    if(p == NULL)
        outtextxy(600, 100, " Lista introdusa este vida.");
    else
        outtextxy(600, 100, " Lista introdusa nu este vida.");
}

//------------- FUNCTIE PENTRU AFLAREA LUNGIMII LISTEI --------------
void lungimeLista(nod *prim, nod *ultim)
{
    butonUNDO();
    unsigned int lungime = 0;
    nod *p = prim;
    while(p != ultim)
    {
        lungime++;
        p = p->urm;
    }
    if(p == ultim)
        lungime++;

    // AFISARE IN FEREASTRA GRAFICA
    outtextxy(370, 280, "Lungimea listei este: ");
    bgiout << lungime << endl;
    outstreamxy(720, 280);
}

//------------- FUNCTII PENTRU INSERARE --------------

void inserareInceput()
{
    butonUNDO();
}

void inserareSfarsit()
{
    butonUNDO();
}

void inserareDupaNod()
{
    butonUNDO();
}

// ---------- MENIU FUNCTII INSERARE LA LISTE SIMPLU-INLANTUITE ----------
void meniuInserare()
{
    butonUNDO();

    outtextxy(410, 100, " Alege functia de inserare ");

    // BUTON 1
    readimagefile("inserare inceput.jpg",440,210,800, 290);

    // BUTON 2
    readimagefile("inserare sfarsit.jpg",440,330,800, 410);

    // BUTON 3
    readimagefile("inserare dupa nod.jpg",440,450,800, 530);

    bool gata = false;
    bool buton1 = false, buton2 = false, buton3 = false;
    int x,y;
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
            if(x >= 440 && x <= 800 && y >= 210 && y <= 290) //buton 1
            {
                gata = true;
                buton1 = true;
            }
            else
                if(x >= 440 && x <= 800 && y >= 330 && y <= 410)  //buton 2
                {
                    gata = true;
                    buton2 = true;
                }
                else
                    if(x >= 440 && x <= 800 && y >= 450 && y <= 530) //buton 3
                    {
                        gata = true;
                        buton3 = true;
                    }
        }
    } while (!gata);
    cleardevice();
    if(buton1 == true)
    {
        outtextxy(320, 100, " Inserare la inceputul listei ");
        inserareInceput();
    }
    else
        if(buton2 == true)
        {
            outtextxy(320, 100, " Inserare la sfarsitul listei ");
            inserareSfarsit();
        }
        else
            if(buton3 == true)
            {
                outtextxy(400, 100, " Inserare dupa un nod dat ");
                inserareDupaNod();
            }
}

//------------- FUNCTII PENTRU STERGERE --------------

void stergerePrimul()
{
    butonUNDO();
}

void stergerePrimaAparitie()
{
    butonUNDO();
}

void stergereToateAparitiile()
{
    butonUNDO();
}

// ---------- MENIU FUNCTII STERGERE LA LISTE SIMPLU-INLANTUITE ----------
void meniuStergere()
{
    butonUNDO();
    outtextxy(450, 100, " Alege functia de stergere ");

    // BUTON 1
    readimagefile("stergere primul.jpg",440,210,800, 290);

    // BUTON 2
    delay(100);
    readimagefile("stergere aparitie.jpg",440,330,800, 410);

    // BUTON 3
    delay(150);
    readimagefile("stergere toate aparitiile.jpg",440,450,800, 530);

    bool gata = false;
    bool buton1 = false, buton2 = false, buton3 = false;
    int x,y;
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
            if(x >= 440 && x <= 800 && y >= 210 && y <= 290) //buton 1
            {
                gata = true;
                buton1 = true;
            }
            else
                if(x >= 440 && x <= 800 && y >= 330 && y <= 410)  //buton 2
                {
                    gata = true;
                    buton2 = true;
                }
                else
                    if(x >= 440 && x <= 800 && y >= 450 && y <= 530) //buton 3
                    {
                        gata = true;
                        buton3 = true;
                    }
        }
    } while (!gata);
    cleardevice();
    if(buton1 == true)
    {
        outtextxy(320, 100, " Stergere primul nod al listei");
        stergerePrimul();
    }
    else
        if(buton2 == true)
        {
            outtextxy(320, 100, " Stergere prima aparitie a unui nod dat ");
            stergerePrimaAparitie();
        }
        else
            if(buton3 == true)
            {
                outtextxy(400, 100, " Stergere toate aparitiile unui nod dat ");
                stergereToateAparitiile();
            }
}

// ---------- AFISAREA UNEI LISTE SIMPLU-INLANTUITE ----------
void afisareListaSimpluInlantuita(nod *prim)
{
    butonUNDO();
    outtextxy(350, 100, " Afisarea unei liste simplu-inlantuite");
    nod* p = prim;
    int x = 100;
    while (p != NULL)
    {
        fout << p->valoare << ' ';
        bgiout << p->valoare;
        outstreamxy(x, 280);
        p = p->urm;
        x += 20;
    }
}

// ---------- POZA CU LISTA SI DESCRIEREA EI (inainte de functii) ----------
void descriereListaSimplu()
{
    cleardevice();
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(300,50, "Informatii despre liste simplu-inlantuite");
    settextstyle(4, HORIZ_DIR, 1);
    outtextxy(120, 150, "       Lista liniara este o structura de date logica, cu  date  omogene,  in care");
    outtextxy(120, 180, "fiecare  element  are  exact  un  element  predecesor si  exact  un  element");
    outtextxy(120, 210, "succesor, cu exceptia primului si al ultimului element.");
    outtextxy(120, 240, "       Lungimea unei liste reprezinta numarul de noduri din lista. O lista care");
    outtextxy(120, 270, "nu are niciun element se numeste lista vida.");
    outtextxy(120, 300, "       O modalitate  de implementare a  listelor este sub forma listelor liniare");
    outtextxy(120, 330, "alocate  dinamic. In  acest caz,  fiecare  element  al listei  este  o  variabila");
    outtextxy(120, 360, "dinamica;  aceasta  va  contine, pe langa informatia  utila si  informatia  de");
    outtextxy(120, 390, "legatura, adica adresa elementului succesor si, eventual, adresa elementului");
    outtextxy(120, 420, "precedent. Aceste adrese vor fi memorate prin intermediul pointerilor.");

    readimagefile("Poza Lista.jpg",400,450,800,650);

    // CLEANUP
    delay(2000);   // 1 sec =  1000 ms
    cleardevice();
}

// ---------- MENIU PENTRU LISTE SIMPLU-INLANTUITE ----------
void meniuListeSimpluInlantuite()
{
    butonUNDO();

    // POZA CU LISTA SI DESCRIEREA EI
    descriereListaSimplu();
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(250, 50, " Alege functia pentru liste simplu-inlantuite ");

    // BUTON 1 - CREARE LISTA    nefacut inca
    readimagefile("creare lista.jpg",440,100,750,150);

    // BUTON 2 - VERIF LISTA VIDA
    readimagefile("vida.jpg",440,200,750,250);

    // BUTON 3 - LUNGIME LISTA
    readimagefile("lungime lista.jpg", 440, 300, 750, 350);

    // BUTON 4 - FUNCTII INSERARE
    readimagefile("inserare.jpg",440,400,750,450);

    // BUTON 5 - FUNCTII STERGERE
    readimagefile("stergere.jpg",440,500,750, 550);

    // BUTON 6 - AFISAREA LISTEI
    readimagefile("afisare.jpg",440, 600,750, 650);

    bool gata = false;
    bool buton1 = false, buton2 = false, buton3 = false, buton4 = false, buton5 = false, buton6 = false;
    int x,y;
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
            if(x >= 440 && x <= 750 && y >= 100 && y <= 150) //buton 1 - creare
            {
                gata = true;
                buton1 = true;
            }
            else
                if(x >= 440 && x <= 750 && y >= 200 && y <= 250)  //buton 2 - vida
                {
                    gata = true;
                    buton2 = true;
                }
                else
                    if(x >= 440 && x <= 750 && y >= 300 && y <= 350) //buton 3 - Lungime lista
                    {
                        gata = true;
                        buton3 = true;
                    }
                    else
                        if(x >= 440 && x <= 750 && y >= 400 && y <= 450)  //buton 4 - inserari
                        {
                            gata = true;
                            buton4 = true;
                        }
                        else
                            if(x >= 440 && x <= 750 && y >= 500 && y <= 550)  //buton 4 - stergeri
                            {
                                gata = true;
                                buton5 = true;
                            }
                            else
                                if(x >= 440 && x <= 750 && y >= 600 && y <= 650)  //buton 4 - stergeri
                                {
                                    gata = true;
                                    buton6 = true;
                                }
        }
    } while (!gata);
    cleardevice();

    if (buton2 == true)  // Creare lista
    {
        //creareLista();
    }
    else
        if (buton2 == true)  // Verificare daca lista este vida
        {
            listaVida(prim);
        }
        else
            if (buton3 == true)  // Functie pt aflarea lungimii listei
            {
                lungimeLista(prim, ultim);
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
}

// ---------- MENIU PRINCIPAL ----------
void butoaneMeniuPrincipal()
{

    // BUTON 1 - Liste simplu inlantuite
    readimagefile("liste s i.jpg",440,210,750,280);

    // BUTON 2 -  Liste dublu inlantuite
    readimagefile("liste d i.jpg",440,310,750, 380);

    // BUTON 3 - Stive
    readimagefile("stive.jpg",440,410,750, 480);

    // BUTON 4 - Cozi
    readimagefile("cozi.jpg",440,510,750, 580);


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
            if(x >= 440 && x <= 750 && y >= 210 && y <= 280)  // Liste simplu-inlantuite
            {
                gata = true;
                buton1 = true;
            }
            else
                if(x >= 440 && x <= 750 && y >= 310 && y <= 380)  // Liste dublu-inalntuite
                {
                    gata = true;
                    buton2 = true;
                }
                else
                    if(x >= 440 && x <= 750 && y >= 410 && y <= 480)  // Stive
                    {
                        gata = true;
                        buton3 = true;
                    }
                    else
                        if(x >= 440 && x <= 750 && y >= 510 && y <= 580)  // Cozi
                        {
                            gata = true;
                            buton4 = true;
                        }
        }
    } while (!gata);
    cleardevice();
    if(buton1 == true)
    {
        meniuListeSimpluInlantuite();
    }
    else
        if(buton2 == true)
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

void meniu()
{
    // ---------- TITLU MENIU ----------
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(400, 100, " Alege structura de date ");

    // ---------- MENIU PRINCIPAL CU STRUCTURI DE DATE ----------
    butoaneMeniuPrincipal();
}

// ---------- INTERFATA ----------
void interfataGrafica()
{
    fereastra();
    meniu();
}

// ---------- CLEANUP ----------
void cleanup()
{
    getch();
    closegraph();
}

int main()
{
    nod *prim, *ultim;

    interfataGrafica();
    cleanup();

    return 0;
}
