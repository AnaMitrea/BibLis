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
            if(x >= 20 && x <= 250 && y >= 700 && y <= 760)
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
    fout << "Lungimea listei este: " << lungime << '\n';
    delay(3000);
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
    delay(3000);
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
    delay(3000);
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
                readimagefile("nod inserat lista.jpg", x, y - 10, x + 200, y + 50);
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
    delay(3000);
    cleardevice();
}

// ---------- MENIU FUNCTII INSERARE LA LISTE SIMPLU-INLANTUITE ----------
void meniuInserare()
{
    butonUNDO();
    outtextxy(550, 100, " Alege functia de inserare ");

    // BUTON 1
    readimagefile("inserare inceput.jpg",600,210,900, 290);

    // BUTON 2
    readimagefile("inserare sfarsit.jpg",600,330,900, 410);

    // BUTON 3
    readimagefile("inserare dupa nod.jpg",600,450,900, 530);

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
            if(x >= 600 && x <= 900 && y >= 210 && y <= 290) //buton 1
            {
                gata = true;
                buton1 = true;
            }
            else
                if(x >= 600 && x <= 900 && y >= 330 && y <= 410)  //buton 2
                {
                    gata = true;
                    buton2 = true;
                }
                else
                    if(x >= 600 && x <= 900 && y >= 450 && y <= 530) //buton 3
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
        inserareInceput(prim,1);
    }
    else
        if(buton2 == true)
        {
            outtextxy(320, 100, " Inserare la sfarsitul listei ");
            inserareSfarsit(prim,1);
        }
        else
            if(buton3 == true)
            {
                outtextxy(400, 100, " Inserare dupa un nod dat ");
                inserareDupaNod(prim, 2, 3);
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
    if(prim == NULL)
        fout << "LISTA VIDA";
}


// ---------- MENIU FUNCTII STERGERE LA LISTE SIMPLU-INLANTUITE ----------
void meniuStergere()
{
    butonUNDO();
    outtextxy(550, 100, " Alege functia de stergere ");

    // BUTON 1
    readimagefile("stergere primul.jpg",600,210,900, 290);

    // BUTON 2
    readimagefile("stergere aparitie.jpg",600,330,900, 410);

    // BUTON 3
    readimagefile("stergere toate aparitiile.jpg",600,450,900, 530);

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
            if(x >= 600 && x <= 900 && y >= 210 && y <= 290) //buton 1
            {
                gata = true;
                buton1 = true;
            }
            else
                if(x >= 600 && x <= 900 && y >= 330 && y <= 410)  //buton 2
                {
                    gata = true;
                    buton2 = true;
                }
                else
                    if(x >= 600 && x <= 900 && y >= 450 && y <= 530) //buton 3
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
        stergerePrimul(prim);
    }
    else
        if(buton2 == true)
        {
            outtextxy(320, 100, " Stergere prima aparitie a unui nod dat ");
            stergerePrimaAparitie(prim,10);
        }
        else
            if(buton3 == true)
            {
                outtextxy(400, 100, " Stergere toate aparitiile unui nod dat ");
                stergereToateAparitiile(prim,10);
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
    delay(3000);
    cleardevice();
}

// ---------- POZA CU LISTA SI DESCRIEREA EI (inainte de functii) ----------
void descriereListaSimplu()
{
    butonUNDO();
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

    // CLEANUP
    delay(2000);   // 1 sec =  1000 ms
    cleardevice();
}

// ---------- MENIU PENTRU LISTE SIMPLU-INLANTUITE ----------
void meniuListeSimpluInlantuite()
{
    cleardevice();
    butonUNDO();
    // POZA CU LISTA SI DESCRIEREA EI
    descriereListaSimplu();
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(400, 50, " Alege functia pentru liste simplu-inlantuite ");

    // BUTON 1 - CREARE LISTA    nefacut inca
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
            if(x >= 600 && x <= 910 && y >= 100 && y <= 150) //buton 1 - creare
            {
                gata = true;
                buton1 = true;
            }
            else
                if(x >= 600 && x <= 910 && y >= 200 && y <= 250)  //buton 2 - vida
                {
                    gata = true;
                    buton2 = true;
                }
                else
                    if(x >= 600 && x <= 910 && y >= 300 && y <= 350) //buton 3 - Lungime lista
                    {
                        gata = true;
                        buton3 = true;
                    }
                    else
                        if(x >= 600 && x <= 910 && y >= 400 && y <= 450)  //buton 4 - inserari
                        {
                            gata = true;
                            buton4 = true;
                        }
                        else
                            if(x >= 600 && x <= 910 && y >= 500 && y <= 550)  //buton 4 - stergeri
                            {
                                gata = true;
                                buton5 = true;
                            }
                            else
                                if(x >= 600 && x <= 910 && y >= 600 && y <= 650)  //buton 4 - stergeri
                                {
                                    gata = true;
                                    buton6 = true;
                                }
        }
    } while (!gata);
    cleardevice();

    if (buton2 == true)  // Creare lista
    {
        creareListaSimpluInlantuita(prim, ultim);
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
}

// ---------- MENIU PRINCIPAL ----------
void butoaneMeniuPrincipal()
{

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

void meniu()
{
    // ---------- TITLU MENIU ----------
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(560, 100, " Alege structura de date ");

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
