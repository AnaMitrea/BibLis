#include<iostream>
#include<windows.h>
#include<MMsystem.h>
#include <graphics.h>
#include <queue>
using namespace std;


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
void meniuStive();
void fereastra();
void citesteSir(char text[100], char afisare[100], int x, int y, bool stergere);
void dimensiuneText(int element);
void descriereStiva();
void deseneazaOutline(int y);
void deseneazaElemente(stiva S);
void initializareStiva(stiva &S);
void esteVidaStiva(stiva S);
void golesteStiva(stiva &S);
void pop(stiva &S);
void eliminareStiva();
void push(stiva &S, int element);
void adaugareStiva();
void afisareStiva(stiva S);

// ---------- INITIALIZARE FEREASTRA ----------
void fereastra()
{
    initwindow(1530, 795, " Meniu Stive ");
}

// ---------- FUNCTIE CITIRE  ----------
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
        delay(300);
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

// ---------- INITIALIZARE SI CREARE STIVA ----------
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
    delay(5000);
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
    outtextxy(730, 20, "Golire stiva");
    rectangle(370,100,1470,200);
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
                                //meniuPrincipal();
                                goto jump;
                            }
}

int main()
{
    fereastra();
    S.nrElemente = 0;
    S.varf = NULL;

    meniuStive();

    getch();
    closegraph();
    return 0;
}
