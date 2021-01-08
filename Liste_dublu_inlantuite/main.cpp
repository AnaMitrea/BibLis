#include <iostream>
#include <windows.h>
#include <MMsystem.h>
#include <mmsystem.h>
#include <fstream>
#include <graphics.h>
#include <queue>

using namespace std;

// ---------- MEMORAREA UNEI LISTE DUBLU INLANTUITE ----------

struct nod_lista_dublu_inlantuita
{
    int element;    //ELEMENTUL MEMORAT
    nod_lista_dublu_inlantuita* urmator;    //NODUL URMATOR MEMORAT
    nod_lista_dublu_inlantuita* anterior;   //NODUL ANTERIOR MEMORAT
};

// ---------- MENIU PRINCIPAL SI ALTE ELEMENTE --------

void meniuPrincipal();
nod_lista_dublu_inlantuita* prim = NULL;    //DECLARAREA LISTEI VIDE PE CARE O VOM UTILIZA
int numarElemente;     //DECLARARE NUMAR DE ELEMENTE CITITE

// ---------- DECLARARE ANTET PENTRU FUNCTIILE UTILIZATE IN GRAFICA ----------

void fereastra();
void interfataGrafica();
void cleanup();
void sunet();
void dimensiuneText(int element);
void citesteSir(char text[100], char afisare[100], int x, int y, bool stergere);

// ---------- DECLARARE ANTET PENTRU FUNCTIILE UTILIZARE LA LISTE DUBLU INLANTUITE ----------

void meniuListeDubluInlantuite1();
void meniuListeDubluInlantuite2();
void descriereListaDubluInlantuita();
void citireElementeListaDubluInlantuita();
void creareListaDubluInlantuita(nod_lista_dublu_inlantuita* &prim,int n,int Valoarea[20]);

void meniuInserareListeDubluInlantuite();
void meniuStergereListeDubluInlantuite();
void meniuCautareListeDubluInlantuite();

void inserareElementListaDubluInlantuita(nod_lista_dublu_inlantuita* &prim, nod_lista_dublu_inlantuita* element_dat, int valoare);
void inserareInceputListaDubluInlantuita(nod_lista_dublu_inlantuita* &prim, int valoare);
void inserareFinalListaDubluInlantuita(nod_lista_dublu_inlantuita* &prim, int valoare);

void stergereElementListaDubluInlantuita(nod_lista_dublu_inlantuita* prim,nod_lista_dublu_inlantuita* nod_sters);

nod_lista_dublu_inlantuita* cautareValoareLD(nod_lista_dublu_inlantuita* prim, int valoare);
nod_lista_dublu_inlantuita* cautarePozitieLD(nod_lista_dublu_inlantuita* prim, int pozitie);

void afisareListaDubluInlantuitaInserare(nod_lista_dublu_inlantuita* prim);
void afisareListaDubluInlantuita(nod_lista_dublu_inlantuita* prim);
void afisareListaDubluInlantuitaCautare(nod_lista_dublu_inlantuita* prim,nod_lista_dublu_inlantuita* nodd);

// ---------- MEMORAREA UNEI COZI ----------

struct nod_coada
{
    int element_coada;      //ELEMENTUL NODULUI DIN COADA
    nod_coada* urmatorul_din_coada;    //NOD URMATOR IN COADA MEMORAT
};

// ---------- DECLARARE ANTET PENTRU FUNCTIILE UTILIZARE LA COADA ----------

nod_coada* nod_Nou_coada(int element_coada);
void meniuCoada1();
void meniuCoada2();
void descriereCoada();
int element_fata_coada(nod_coada* fata_cozii);
void push(nod_coada* &fata_cozii, nod_coada* &spatele_cozii, int element_coada);
int pop(nod_coada* &fata_cozii);
bool isEmpty(nod_coada* fata_cozii);
void afisareCoada(nod_coada* fata_cozii);




// ---------- MENIU PRINCIPAL ----------

void meniuPrincipal()
{   void sunet();
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
    {     mciSendString ("play sunet.mp3", NULL, 0, NULL);

        //meniuListeSimpluInlantuite();
    }
    else
        if (buton2 == true)
        {   mciSendString ("play sunet.mp3", NULL, 0, NULL);
            meniuListeDubluInlantuite1();

        }
        else
            if(buton3 == true)
            {    mciSendString ("play sunet.mp3", NULL, 0, NULL);
                // meniuStive();
            }
            else
                if(buton4 == true)
                {    mciSendString ("play sunet.mp3", NULL, 0, NULL);
                     meniuCoada1();
                }
}

// ---------- FUNCTII UTILIZATE PENTRU SCRIEREA GRAFICA ----------

// ---------- INITIALIZARE FEREASTRA GRAFICA ----------

void fereastra()
{
    initwindow(1400, 700, " Meniu Biblioteca cu Liste Dublu Inlantuite si Coada ");
    //initwindow(1530, 795, " Meniu Biblioteca cu Liste ");
}

// ---------- INTERFATA ----------

void interfataGrafica()
{
    fereastra();
    meniuPrincipal();
    cleanup();
}

// ---------- CLEANUP ----------

void cleanup()
{
    getch();
    closegraph();
}

// ---------- SUNET DE FUNDAL ----------

void sunet()
{
    mciSendString ("play song.mp3 repeat", NULL, 0, NULL);
}

// ---------- STABILIREA MARIMII TEXTULUI IN FUNCTIE DE NUMARUL DE CARACTERE ----------

void dimensiuneText(int element)
{
    if(element >= 0 && element < 100)
        settextstyle(3, HORIZ_DIR, 3);      // SELECTAREA STILULUI DE SCRIS,HORIZ_DIR (Left to right) SAU VERT_DIR (Bottom to top),
    else
        if(element >= 100 && element < 1000)
            settextstyle(3, HORIZ_DIR, 2);
        else
            if(element >=1000 && element <100000)
                settextstyle(3, HORIZ_DIR, 1);
}

// ---------- FUNCTIA DE CITIRE IN MOD GRAFIC ----------

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

// ---------- PROGRAMUL PRINCIPAL ----------

int main()
{
    interfataGrafica();
    return 0;
}

//-----------------MENIU PENTRU LISTE DUBLU INLANTUITE NR.1 --------------------

void meniuListeDubluInlantuite1()
{
    descriereListaDubluInlantuita();    //APELEAZA FEREASTRA DE DESCRIERE A LISTELOR DUBLU INLANTUITE
    citireElementeListaDubluInlantuita();   //APELEAZA FEREASTRA DE CITIRE A ELEMENTELOR PENTRU LISTE DUBLU INLANTUITE
}

//-----------------MENIU PENTRU LISTE DUBLU INLANTUITE NR.2 --------------------

void meniuListeDubluInlantuite2()
{
    cleardevice();
    settextstyle(3, HORIZ_DIR, 5);  // SELECTAREA STILULUI DE SCRIS
    outtextxy(200, 50, " Alege functia pentru listele dublu inlantuite ");

    // BUTON 1 - INSERAREA UNUI ELEMENT
    readimagefile("Inserare element dat.jpg",375,200,675,300);

    // BUTON 2 - STERGEREA UNUI ELEMENT
    readimagefile("Stergere element.jpg",725,200,1025,300);

    // BUTON 3 - CAUTAREA UNUI ELEMENT
    readimagefile("Cautarea unui element dat.jpg", 725, 350, 1025, 450);

    // BUTON 4 - CITIREA UNEI LISTE NOI
    readimagefile("citire lista noua ld.jpg", 375, 350, 675, 450);

    // BUTON 5 - MENIU PRINCIPAL
    readimagefile("meniu principal ld.jpg", 375, 500, 675, 600);

    // BUTON 6 - INAPOI LA FEREASTRA DE DESCRIERE A LISTELOR DUBLU INLANTUITE
    readimagefile("inapoi.jpg",725,500,1025,600);

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
            if (x >= 375 && x <= 675 && y >= 200 && y <= 300) // BUTON 1 - INSERAREA UNUI ELEMENT
            {
                gata = true;
                buton1 = true;
            }
            else

                if (x >= 725  && x <= 1025 && y >= 200 && y <= 300) // BUTON 2 - STERGEREA UNUI ELEMENT
                {
                    gata = true;
                    buton2 = true;
                }
                else
                    if (x >= 725 && x <= 1025 && y >= 350 && y <= 450) // BUTON 3 - CAUTAREA UNUI ELEMENT
                    {
                        gata = true;
                        buton3 = true;
                    }
                    else
                        if (x >= 375 && x <= 675 && y >=350  && y <= 450) // BUTON 4 - CITIREA UNEI LISTE NOI
                        {
                            gata = true;
                            buton4 = true;
                        }
                        else
                            if (x >= 375 && x <= 675 && y >= 500 && y <= 600) // BUTON 5 - MENIU PRINCIPAL
                            {
                                gata = true;
                                buton5 = true;
                            }
                            else
                                if (x >= 725 && x <= 1025 && y >= 500 && y <= 600) // BUTON 6 - INAPOI LA FEREASTRA DE DESCRIERE A LISTELOR DUBLU INLANTUITE
                                {
                                    gata = true;
                                    buton6 = true;
                                }
        }
    } while (!gata);

    cleardevice();

    if (buton1 == true)  //INSERAREA UNUI ELEMENT
    {
        mciSendString ("play sunet.mp3", NULL, 0, NULL);    //SUNET LA APASAREA BUTONULUI
        cleardevice();
        meniuInserareListeDubluInlantuite();
    }
    else
        if (buton2 == true)  //STERGEREA UNUI ELEMENT
        {
            mciSendString ("play sunet.mp3", NULL, 0, NULL);    //SUNET LA APASAREA BUTONULUI
            cleardevice();
            meniuStergereListeDubluInlantuite();
        }
        else
            if (buton3 == true)  //CAUTAREA UNUI ELEMENT
            {
                mciSendString ("play sunet.mp3", NULL, 0, NULL);    //SUNET LA APASAREA BUTONULUI
                cleardevice();
                meniuCautareListeDubluInlantuite();
            }
            else
                if (buton4 == true) //CITIREA UNEI LISTE NOI
                {
                    mciSendString ("play sunet.mp3", NULL, 0, NULL);    //SUNET LA APASAREA BUTONULUI
                    cleardevice();
                    citireElementeListaDubluInlantuita();
                }
                else
                    if (buton5 == true) //MENIU PRINCIPAL
                    {
                        mciSendString ("play sunet.mp3", NULL, 0, NULL);    //SUNET LA APASAREA BUTONULUI
                        cleardevice();
                        meniuPrincipal();
                    }
                    else
                        if (buton6 == true) //INAPOI LA FEREASTRA DE DESCRIERE A LISTELOR DUBLU INLANTUITE
                        {
                            mciSendString ("play sunet.mp3", NULL, 0, NULL);    //SUNET LA APASAREA BUTONULUI
                            cleardevice();
                            descriereListaDubluInlantuita();
                        }

}

// ---------- DESCRIERE LISTA DUBLU INLANTUITA ----------

void descriereListaDubluInlantuita()
{
    cleardevice();
    settextstyle(4, HORIZ_DIR, 3);  // SELECTAREA STILULUI DE SCRIS,HORIZ_DIR (Left to right) SAU VERT_DIR (Bottom to top),

    // SCRIEREA DOCUMENTATIEI
    outtextxy(330,50, "Informatii despre listele dublu inlantuite");
    settextstyle(4, HORIZ_DIR, 1);
    outtextxy(150, 150, "       Listele dublu inlantuite sunt structuri de date dinamice omogene. Ele au aceleasi");
    outtextxy(150, 180, "caracteristici de baza ca si listele liniare simplu inlantuite. Diferenta fata de aceastea");
    outtextxy(150, 210, "consta in faptul ca, pentru fiecare nod, se retine si adresa elementului anterior, ceea ce ");
    outtextxy(150, 240, "permite traversarea listei in ambele directii. Lista dublu inlantuita poate fi reprezentata");
    outtextxy(150, 270, "grafic astfel:");

    // EXEMPLU LISTA DUBLU INLANTUITA
    readimagefile("Exemplu lista dublu inlantuita.jpg",150,300,1250,650);

     // BUTON PENTRU PAGINA URMATOARE
    readimagefile("pagina urmatoare.jpg",720,650,920,690);

    // BUTON PENTRU PAGINA PRECEDENTA ADICA MENIUL PRINCIPAL
    readimagefile("inapoi.jpg",480,650,680,690);

    bool gata = false, inainte = false, inapoi=false;
    int x,y;
    do
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
            if(x >= 720 && x <= 920 && y >=650  && y <= 690)    // BUTON PENTRU PAGINA URMATOARE
            {
                gata = true;
                inainte=true;
            }
            else
                if(x >= 480 && x <= 680 && y >=650  && y <= 690)   // BUTON PENTRU PAGINA PRECEDENTA ADICA MENIUL PRINCIPAL
                {
                    gata=true;
                    inapoi = true;
                }
        }
    } while (!gata);

    if (inainte == true)    // BUTON PENTRU PAGINA URMATOARE
    {
        mciSendString ("play sunet.mp3", NULL, 0, NULL);    //SUNET LA APASAREA BUTONULUI
        cleardevice();
        citireElementeListaDubluInlantuita();
    }
    else
        if(inapoi == true)   // BUTON PENTRU PAGINA PRECEDENTA ADICA MENIUL PRINCIPAL
        {
            mciSendString ("play sunet.mp3", NULL, 0, NULL);    //SUNET LA APASAREA BUTONULUI
            cleardevice();
            meniuPrincipal();
        }

    delay(15000);   // 1 sec =  1000 ms
    cleardevice();
}


// ---------- FUNCTIA DE CITIRE ----------

void citireElementeListaDubluInlantuita()
{
    int Valoarea[20], n, i;
    char afisare[100], vectText[100], numar[100];

    setcolor(YELLOW);   // COLORARE TEXT
    setbkcolor(BLACK);  // COLORARE FUNDAL TEST
    settextstyle(3, HORIZ_DIR, 3);
    outtextxy(20, 10, "Va rugam introduceti numerele din lista");

    //FUNCTIA DE CITIRE A TEXTULUI IN MOD GRAFIC IN SIRUL AFISARE
    citesteSir("Cate numere doriti sa contina lista? (maxim 20) ", afisare, 20, 40, false);

    numarElemente = atoi(afisare);  // CONVERSIE DIN ASCII IN INT

    n = numarElemente;

    if(n>20)    //DACA NUMARUL DE ELEMENTE CARE VOR SA FIE CITITE ESTE MAI MARE DECAT 20 SE VA DA O EROARE
    {
        mciSendString ("play sunet.mp3", NULL, 0, NULL);
        outtextxy(400,40,"Ati introdus un numar mai mare de 20");
        delay(5000);
        cleardevice();
        citireElementeListaDubluInlantuita();   // REDESCHIDERE A FUNCTIEI DE CITIRE
    }
    else  {
                for (i=0; i<n; i++)
                {
                    itoa(i,numar,10);  // CONVERSIE DIN INT IN ASCII IN SIRUL numar
                    strcpy(vectText,"Nodul ");
                    strcat(vectText,numar);
                    strcat(vectText," are valoarea egala cu: ");

                    citesteSir(vectText,afisare, 30, 70 + 30 * i, false); // CITIREA VALORII CORESPUNZATOARE IN VECTOR PE POZITIA I

                    Valoarea[i] = atoi(afisare); // CONVERSIE DIN ASCII IN INT
                }

                creareListaDubluInlantuita(prim,n,Valoarea);
                cleardevice();
                meniuListeDubluInlantuite2();
          }

}

// ---------- CREARE LISTA DUBLU INLANTUITA ----------

void creareListaDubluInlantuita (nod_lista_dublu_inlantuita*& prim , int n , int Valoarea[20])
{
    for(int i=0;i<n;i++)
        inserareFinalListaDubluInlantuita( prim , Valoarea[i] );
}

//------------------MENIU INSERARE LD------------------
void meniuInserareListeDubluInlantuite()
{
    jump:
    cleardevice();
    afisareListaDubluInlantuitaInserare(prim);
    settextstyle(3, HORIZ_DIR, 4);
    outtextxy(937, 10, " Alege functia ");
    outtextxy(937, 50, "  de inserare ");
    // BUTON 1
    readimagefile("Inserare element dat la inceputul listei.jpg",860, 100, 1085, 180);
    // BUTON 2
    readimagefile("Inserare element dat la finalul listei.jpg",1125, 100, 1350, 180);
    // BUTON 3
    readimagefile("Inserarea unui element dat dupa o pozitie data.jpg",860, 200, 1085, 280);
    // BUTON 4
    readimagefile("Inserarea unui element dat dupa un element existent.jpg",1125, 200, 1350, 280);
    // BUTON 5
    readimagefile("inapoi.jpg",947,310,1238,390);
    // LINII DE DELIMTARE
    line(830,0,830,700);
    line(830,300,1400,300);
    line(830,400,1400,400);
    // LABEL PENTRU A RESETA BUTONUL

    bool gata = false;
    bool buton1 = false, buton2 = false, buton3=false, buton4 = false, buton5=false;
    int x,y;
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
            if(x >= 860 && x <= 1085 && y >= 100 && y <= 180) //buton 1
            {
                gata = true;
                buton1 = true;
            }
            else
                if(x >= 1125 && x <= 1350 && y >= 100 && y <= 180)  //buton 2
                {
                    gata = true;
                    buton2 = true;
                }
               else
                        if (x >=860 && x <= 1085 && y >= 200 && y <= 280)
                        {
                            gata = true;
                            buton3 = true;
                        }
                        else
                               if (x >=1125 && x <= 1350 && y >= 200 && y <= 280)
                                {
                                    gata = true;
                                    buton4 = true;
                                }
                                else
                                    if (x >=947 && x <= 1238 && y >= 310 && y <= 390)
                                    {
                                        gata = true;
                                        buton5 = true;
                                    }
        }
    } while (!gata);

    if (buton1 == true)
    {   mciSendString ("play sunet.mp3", NULL, 0, NULL);
        char afisare[100];
        settextstyle(3, HORIZ_DIR, 3);
        outtextxy(937,410,"Ce numar doriti");
        outtextxy(937,450,"  sa inserati? " );

        //Functia de citire a textului in mod grafic in sirul afisare
        citesteSir("numarul: ", afisare, 947, 480, false);

        int valoare= atoi(afisare);  // conversie ascii -> int din sirul afisare
        inserareInceputListaDubluInlantuita(prim, valoare);

        numarElemente++;
        goto jump;  // RESET LA BUTON
    }
    else
        if (buton2 == true)
        {   mciSendString ("play sunet.mp3", NULL, 0, NULL);
            char afisare[100];
        settextstyle(3, HORIZ_DIR, 3);
        outtextxy(937,410,"Ce numar doriti");
        outtextxy(937,430,"  sa inserati? " );

        //Functia de citire a textului in mod grafic in sirul afisare
        citesteSir("numarul: ", afisare, 937, 450, false);

        int valoare= atoi(afisare);  // conversie ascii -> int din sirul afisare
        inserareFinalListaDubluInlantuita(prim, valoare);
        numarElemente++;
        goto jump;  // RESET LA BUTON
        }
                else if (buton3 == true)
                       {   mciSendString ("play sunet.mp3", NULL, 0, NULL);
                           char afisare[100],afisare1[100];
                        settextstyle(3, HORIZ_DIR, 3);
                        outtextxy(937,410,"Ce numar doriti sa inserati");
                        outtextxy(937,450,"   si dupa pe ce pozitie?    " );
                        //Functia de citire a textului in mod grafic in sirul afisare
                        citesteSir("numarul: ", afisare, 947, 480, false);
                        citesteSir("pozitia: ", afisare1, 947, 510, false);
                        int valoare= atoi(afisare);  // conversie ascii -> int din sirul afisare
                        int pozitia= atoi(afisare1);
                        nod_lista_dublu_inlantuita *nod_cautat=cautarePozitieLD(prim,pozitia);
                        if(pozitia<numarElemente&&pozitia>=0)
                            {inserareElementListaDubluInlantuita(prim,nod_cautat,valoare);
                             numarElemente++;
                             goto jump;  // RESET LA BUTON
                            }
                         else { Beep(1000,100);
                                outtextxy(1000,530,"Nodul introdus");
                                outtextxy(1000,550,"  nu exista");
                                delay(5000);
                                goto jump;
                              }

                       }
                            else if (buton4 == true)
                                   {    mciSendString ("play sunet.mp3", NULL, 0, NULL);
                                        char afisare[100],afisare1[100];
                                        settextstyle(3, HORIZ_DIR, 3);
                                        outtextxy(937,410,"Ce numar doriti sa inserati");
                                        outtextxy(937,450,"   si dupa pe ce element?    " );
                                        //Functia de citire a textului in mod grafic in sirul afisare
                                        citesteSir("numarul: ", afisare, 947, 480, false);
                                        citesteSir("elementul: ", afisare1, 947, 510, false);
                                        int valoare= atoi(afisare);  // conversie ascii -> int din sirul afisare
                                        int elementul= atoi(afisare1);
                                        nod_lista_dublu_inlantuita *nod_cautat=cautareValoareLD(prim,elementul);

                                        if(nod_cautat!=NULL)
                                        {inserareElementListaDubluInlantuita(prim,nod_cautat,valoare);
                                        numarElemente++;
                                        goto jump;  // RESET LA BUTON
                                        }
                                        else { Beep(1000,100);
                                                outtextxy(1000,530,"Valoarea introdusa");
                                                outtextxy(1000,550,"    nu exista");
                                                delay(5000);
                                                goto jump;
                                              }

                                    }
                                        if (buton5 == true)
                                        {   mciSendString ("play sunet.mp3", NULL, 0, NULL);
                                            cleardevice();
                                            meniuListeDubluInlantuite2();
                                        }
}

//-----------------MENIU PENTRU STERGEREA IN LISTE DUBLU INLANTUITE--------

void meniuStergereListeDubluInlantuite()
{
    jump:
    cleardevice();
    afisareListaDubluInlantuita(prim);
    readimagefile("inapoi.jpg",1100,410,1350,490);
    settextstyle(3, HORIZ_DIR, 4);
    outtextxy(1100, 10, " Alege functia ");
    outtextxy(1100, 50, "  de stergere ");
    // BUTON 1
    readimagefile("Stergerea primei aparitii a unei valori date.jpg",1100, 100, 1350, 180);
    // BUTON 2
    readimagefile("Stergerea unui element dupa o pozitie data.jpg",1100, 200, 1350, 280);
    // BUTON 3
    readimagefile("Stergere lista.jpg",1100,300,1350,380);
    // LINII DE DELIMTARE
    line(1090,0,1090,700);
    line(1090,400,1400,400);
    line(1090,500,1400,500);
    // LABEL PENTRU A RESETA BUTONUL

    bool gata = false;
    bool buton1 = false, buton2 = false, buton3 = false, buton4=false;
    int x,y;
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
            if(x >= 1100 && x <= 1350 && y >= 100 && y <= 180) //buton 1
            {
                gata = true;
                buton1 = true;
            }
            else
                if(x >= 1100 && x <= 1350 && y >= 200 && y <= 280)  //buton 2
                {
                    gata = true;
                    buton2 = true;
                }
               else

                        if (x >=1100 && x <= 1350 && y >= 300 && y <= 380) //inapoi
                        {
                            gata = true;
                            buton3 = true;
                        }
                        else   if (x >=1100 && x <= 1350 && y >= 410 && y <= 490) //inapoi
                                    {
                                        gata = true;
                                        buton4 = true;
                                    }
        }
    } while (!gata);

    if (buton1 == true)
    {   mciSendString ("play sunet.mp3", NULL, 0, NULL);
        char afisare[100];
        settextstyle(3, HORIZ_DIR, 3);
        outtextxy(1100,510,"Ce numar doriti");
        outtextxy(1100,540,"  sa stergeti? " );

        //Functia de citire a textului in mod grafic in sirul afisare
        citesteSir("numarul: ", afisare, 1110, 570, false);
        int valoare= atoi(afisare);  // conversie ascii -> int din sirul afisare
        nod_lista_dublu_inlantuita *nod_sters=cautareValoareLD(prim,valoare);
        if(nod_sters!=NULL)
        {   if(nod_sters==prim)
                  {if(nod_sters->urmator==NULL&&nod_sters->anterior==NULL)
                                        {prim=NULL;}
                                                 else
                                                        { nod_lista_dublu_inlantuita* sters = prim;
                                                         prim = prim->urmator;
                                                         prim->anterior = NULL;
                                                         delete sters;
                                                       }
                 }
                         else stergereElementListaDubluInlantuita(prim,nod_sters);
            numarElemente--;
           goto jump;  // RESET LA BUTON
        }
          else {Beep(1000,100);
                outtextxy(1100,600,"Valoarea introdusa");
                outtextxy(1100,630,"    nu exista");
                delay(5000);
                goto jump;
               }
    }
    else
        if (buton2 == true)
        {   mciSendString ("play sunet.mp3", NULL, 0, NULL);
            char afisare[100];
            settextstyle(3, HORIZ_DIR, 3);
            outtextxy(1100,510,"Ce nod doriti");
            outtextxy(1100,540," sa stergeti? ");

            //Functia de citire a textului in mod grafic in sirul afisare
            citesteSir("nodul: ", afisare, 1110, 570, false);

            int pozitie= atoi(afisare);  // conversie ascii -> int din sirul afisare
            nod_lista_dublu_inlantuita *nod_sters=cautarePozitieLD(prim,pozitie);
            if(pozitie>=0&&numarElemente>pozitie)
              {   if(pozitie==0)
                      {if(nod_sters->urmator==NULL&&nod_sters->anterior==NULL)
                                    {prim=NULL;}
                                else{
                                                     nod_lista_dublu_inlantuita* sters = prim;
                                                     prim = prim->urmator;
                                                     prim->anterior = NULL;
                                                     delete sters;
                                                    }}
                  else stergereElementListaDubluInlantuita(prim,nod_sters);
                  numarElemente--;
                  goto jump;  // RESET LA BUTON
              }
              else {Beep(1000,100);
                    outtextxy(1100,600,"Nodul introdus");
                    outtextxy(1100,630,"  nu exista");
                    delay(5000);
                    goto jump; // RESET LA BUTON
                   }
        }
         else
                if (buton3 == true)
                {   mciSendString ("play sunet.mp3", NULL, 0, NULL);
                    cleardevice();
                    prim=NULL;
                    goto jump;
                }
                    else
                        if (buton4 == true)
                        {   mciSendString ("play sunet.mp3", NULL, 0, NULL);
                            cleardevice();
                            meniuListeDubluInlantuite2();
                        }
}

//------------------MENIU PENTRU CAUTAREA IN LISTE DUBLU INLANTUITE-----

void meniuCautareListeDubluInlantuite()
{
    jump:
    cleardevice();
    afisareListaDubluInlantuita(prim);
    here:
    readimagefile("inapoi.jpg",1100,310,1350,390);
    settextstyle(3, HORIZ_DIR, 4);
    outtextxy(1100, 10, " Alege functia ");
    outtextxy(1100, 50, "  de cautare ");
    // BUTON 1
    readimagefile("Cautarea unui element dat dupa o pozitie.jpg",1100, 100, 1350, 180);
    // BUTON 2
    readimagefile("Cautarea unui element dat dupa o valoare.jpg",1100, 200, 1350, 280);
    // LINII DE DELIMTARE
    line(1090,0,1090,700);
    line(1090,300,1400,300);
    line(1090,400,1400,400);
    // LABEL PENTRU A RESETA BUTONUL
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
            if(x >= 1100 && x <= 1350 && y >= 100 && y <= 180) //buton 1
            {
                gata = true;
                buton1 = true;
            }
            else
                if(x >= 1100 && x <= 1350 && y >= 200 && y <= 280)  //buton 2
                {
                    gata = true;
                    buton2 = true;
                }
               else
                        if (x >=1100 && x <= 1350 && y >= 310 && y <= 390)
                        {
                            gata = true;
                            buton3 = true;
                        }
        }
    } while (!gata);

    if (buton1 == true)
    {   mciSendString ("play sunet.mp3", NULL, 0, NULL);
        char afisare[100];
        settextstyle(3, HORIZ_DIR, 3);
        outtextxy(1100,410,"Ce pozitie doriti");
        outtextxy(1100,440,"  sa cautati? " );

        //Functia de citire a textului in mod grafic in sirul afisare
        citesteSir("pozitia: ", afisare, 1110, 470, false);
        int valoare= atoi(afisare);  // conversie ascii -> int din sirul afisare
        if(valoare>=0&&valoare<numarElemente)
           {  cleardevice();
              nod_lista_dublu_inlantuita *nod_cautat=cautarePozitieLD(prim,valoare);
              afisareListaDubluInlantuitaCautare(prim,nod_cautat);
              goto here;  // RESET LA BUTON
           }
          else
              {Beep(1000,100);
                outtextxy(1100,500,"Nodul introdus");
                outtextxy(1100,530,"  nu exista");
                delay(5000);
                goto jump;
               }
    }
    else
        if (buton2 == true)
        {   mciSendString ("play sunet.mp3", NULL, 0, NULL);
            char afisare[100];
        settextstyle(3, HORIZ_DIR, 3);
        outtextxy(1100,410,"Ce valoare doriti");
        outtextxy(1100,440,"    sa cautati?  ");

        //Functia de citire a textului in mod grafic in sirul afisare
        citesteSir("valoarea: ", afisare, 1110, 470, false);

        int valoare= atoi(afisare);  // conversie ascii -> int din sirul afisare
           nod_lista_dublu_inlantuita *nod_cautat=cautareValoareLD(prim,valoare);
           if(nod_cautat!=NULL)
           {  cleardevice();
              afisareListaDubluInlantuitaCautare(prim,nod_cautat);
              goto here;  // RESET LA BUTON
           }
          else {Beep(1000,100);
                outtextxy(1100,500,"Valoarea introdusa");
                outtextxy(1100,530,"   nu exista      ");
                delay(5000);
                goto jump;
               }
        }
            else
                if (buton3 == true)
                {   mciSendString ("play sunet.mp3", NULL, 0, NULL);
                    cleardevice();
                    meniuListeDubluInlantuite2();
                }
}

// ---------- FUNCTII PENTRU INSERAREA IN LISTE DUBLU INLANTUITE ----------

//Inserare la inceputul listei dublu inlantuite
void inserareInceputListaDubluInlantuita(nod_lista_dublu_inlantuita* &prim, int valoare)
{
    //Creeam noul nod si ii atribuim valoarea din paramentru
    nod_lista_dublu_inlantuita *numar = new nod_lista_dublu_inlantuita;
    numar->element = valoare;
    numar->urmator = prim; //Mutam sageata catre primul element din lista
    numar->anterior = NULL;
    if(prim != NULL)
        prim->anterior = numar; // Actualizam sageata primului element din lista

    prim = numar; //Inlocuim primul element din lista
}
//Inserare la finalul listei dublu inlantuite
void inserareFinalListaDubluInlantuita(nod_lista_dublu_inlantuita* &prim, int valoare)
{
    //Creeam noul nod si ii atribuim valoarea din paramentru
    nod_lista_dublu_inlantuita *numar = new nod_lista_dublu_inlantuita;
    numar->element = valoare;
    numar->urmator = NULL;
    numar->anterior = NULL;

    if (prim == NULL) // In cazul in care lista noastra este vida, punem elementul in lista
        prim = numar;
    else
    {
        //Parcurgem lista pana la final
        nod_lista_dublu_inlantuita *nod_curent = prim;
        while (nod_curent->urmator != NULL)
            nod_curent = nod_curent->urmator;

        //Mutam sageata ultimului element catre elementul creat anterior
        nod_curent->urmator = numar;
        numar->anterior = nod_curent;
    }
}
//Inserare dupa un element dat
void inserareElementListaDubluInlantuita(nod_lista_dublu_inlantuita* &prim, nod_lista_dublu_inlantuita* element_dat, int valoare)
{
    //Creeam noul nod si ii atribuim valoarea din paramentru
    nod_lista_dublu_inlantuita *elem_creat = new nod_lista_dublu_inlantuita;
    elem_creat->element = valoare;
    elem_creat->urmator = NULL;
    elem_creat->anterior = NULL;

    if (prim == NULL)
    {
        prim = elem_creat;
        return;
    }
    if (element_dat->urmator == NULL)
    {   elem_creat->urmator = NULL;
        elem_creat->anterior = element_dat;
        element_dat->urmator = elem_creat;
        return;
    }
    if (prim == element_dat)
    {   elem_creat->urmator=prim->urmator;
        elem_creat->anterior=prim;
        prim->urmator=elem_creat;
        return;
    }

    elem_creat->urmator = element_dat->urmator;
    elem_creat->anterior = element_dat;
    element_dat->urmator->anterior = elem_creat;
    element_dat->urmator = elem_creat;
}

//------------------FUNCTII PENTRU STERGEREA IN LISTE DUBLU INLANTUITE-------------------

void stergereElementListaDubluInlantuita(nod_lista_dublu_inlantuita* prim,nod_lista_dublu_inlantuita* nod_sters)
{
    if(prim==NULL)return;
        else if(nod_sters->urmator==NULL)
                       { nod_sters->anterior->urmator=NULL;
                         delete nod_sters;
                         return;
                       }
                else { nod_sters->anterior->urmator=nod_sters->urmator;
                       nod_sters->urmator->anterior=nod_sters->anterior;
                       delete nod_sters;
                       return;
                     }
}

//------------------FUNCTII PENTRU CAUTAREA IN LISTE DUBLU INLANTUITE---

//Cautarea unui element dupa o valoare data LD
nod_lista_dublu_inlantuita* cautareValoareLD(nod_lista_dublu_inlantuita* prim, int valoare)
{   nod_lista_dublu_inlantuita *p=prim;
    while (p != NULL && p->element != valoare)
        p = p->urmator;
    return p;

}
//Cautarea unui element dupa o pozitie data LD

nod_lista_dublu_inlantuita* cautarePozitieLD(nod_lista_dublu_inlantuita* prim, int pozitie)
{   nod_lista_dublu_inlantuita *p=prim;
    int i = 0;  //Pozitia curenta
    //Parcurgem lista pana la pozitia curenta, sau
    //pana ajungem la ultimul element al listei
    while (p != NULL && i < pozitie)
    {
        p = p->urmator;
        i++;
    }
    //In cazul in care am gasit pozitia ceruta, o returnam
    if (i == pozitie)
        return p;
    else
        return NULL;
}

// ---------- AFISAREA UNEI LISTE DUBLU INLANTUITE PENTRU INSERARE ----------

void afisareListaDubluInlantuitaInserare(nod_lista_dublu_inlantuita* prim)
{
    settextstyle(3, HORIZ_DIR, 6);
    setbkcolor(BLUE);
    outtextxy(50, 20, "Lista reprezentata grafic este");
    setbkcolor(BLACK);

    nod_lista_dublu_inlantuita* p = prim;
    unsigned int x = 20, y = 120;
    unsigned int xtext = 30, ytext = 140;
    if(p==NULL){outtextxy(100,150,"LISTA ESTE VIDA");readimagefile("SAD.jpg",180,200,700,600);}
    while (p != NULL)
    {
        if (x <= 660)  // daca nu iese din ecran
        {
            // AFISAREA NODULUI CORESPUNZATOR
            if (p->urmator == NULL&&p->anterior == NULL)
                readimagefile("nod singur lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                 else { if(p->anterior == NULL) {readimagefile("nod inceput lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                                                 readimagefile("sageti.jpg", x+150, y, x + 200, y + 60);}
                        else {if(p->urmator == NULL)
                                readimagefile("nod sfarsit lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                              else {readimagefile("nod mijloc lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                                    readimagefile("sageti.jpg", x+150, y, x + 200, y + 60);}
                             }
                        }

            // DIMENSIUNEA TEXTULUI IN FIECARE NOD
            dimensiuneText(p->element);

            // AFISARE IN MODUL GRAFIC
            bgiout << p->element;
            outstreamxy(xtext+50, ytext);

            // COORDONATELE URMATORULUI NOD
            x += 200;
            xtext += 200;

            p = p->urmator;
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
}

// ---------- AFISAREA UNEI LISTE DUBLU-INLANTUITE PENTRU STERGERE ----------

void afisareListaDubluInlantuita(nod_lista_dublu_inlantuita *prim)
{
    settextstyle(3, HORIZ_DIR, 6);
    setbkcolor(BLUE);
    outtextxy(50, 20, "Lista reprezentata grafic este");
    setbkcolor(BLACK);
    nod_lista_dublu_inlantuita* p = prim;
    unsigned int x = 20, y = 120;
    unsigned int xtext = 30, ytext = 140;
    if(p==NULL){outtextxy(100,150,"LISTA ESTE VIDA");readimagefile("SAD.jpg",180,200,700,600);}
    while (p != NULL)
    {
        if (x <= 960)  // daca nu iese din ecran
        {
            // AFISAREA NODULUI CORESPUNZATOR
            if (p->urmator == NULL&&p->anterior == NULL)
                readimagefile("nod singur lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                 else { if(p->anterior == NULL) {readimagefile("nod inceput lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                                                 readimagefile("sageti.jpg", x+150, y, x + 200, y + 60);}
                        else {if(p->urmator == NULL)
                                readimagefile("nod sfarsit lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                              else {readimagefile("nod mijloc lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                                    readimagefile("sageti.jpg", x+150, y, x + 200, y + 60);}
                             }
                        }

            // DIMENSIUNEA TEXTULUI IN FIECARE NOD
            dimensiuneText(p->element);

            // AFISARE IN MODUL GRAFIC
            bgiout << p->element;
            outstreamxy(xtext+50, ytext);

            // COORDONATELE URMATORULUI NOD
            x += 200;
            xtext += 200;

            p = p->urmator;
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

}

//--------------------------AFISARE LISTA DUBLU INLANTUITA PENTRU CAUTARE-------

void afisareListaDubluInlantuitaCautare(nod_lista_dublu_inlantuita* prim,nod_lista_dublu_inlantuita* nodd)
{
     settextstyle(3, HORIZ_DIR, 6);
    setbkcolor(BLUE);
    outtextxy(50, 20, "Lista reprezentata grafic este");
    setbkcolor(BLACK);

    nod_lista_dublu_inlantuita* p = prim;
    nod_lista_dublu_inlantuita* q = nodd;
    unsigned int x = 20, y = 120;
    unsigned int xtext = 30, ytext = 140;
    if(p==NULL){outtextxy(100,150,"LISTA ESTE VIDA");readimagefile("SAD.jpg",180,200,700,600);}
    while (p != NULL)
    {
        if (x <= 960)  // daca nu iese din ecran
        {
            // AFISAREA NODULUI CORESPUNZATOR
            if (p->urmator == NULL&&p->anterior == NULL)
                 {if(p->element==q->element)readimagefile("Element cautat singur.jpg", x, y-10, x + 150, y + 60);
                      else readimagefile("nod singur lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                 }
                 else { if(p->anterior == NULL) {if(p->element==q->element)
                                                  {readimagefile("Element cautat primul.jpg", x, y-10, x + 150, y + 60);
                                                   readimagefile("sageti.jpg", x+150, y, x + 200, y + 60);
                                                  }
                                                 else {readimagefile("nod inceput lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                                                       readimagefile("sageti.jpg", x+150, y, x + 200, y + 60);
                                                      }
                                                }
                        else {if(p->urmator == NULL)
                                {if(p->element==q->element)readimagefile("Element cautat ultimul.jpg", x, y-10, x + 150, y + 60);
                                  else readimagefile("nod sfarsit lista dublu inlantuita.jpg", x, y, x + 150, y + 60);}
                              else {if(p->element==q->element){readimagefile("Element cautat interior.jpg", x, y-10, x + 150, y + 60);
                                                 readimagefile("sageti.jpg", x+150, y, x + 200, y + 60);}
                                    else {readimagefile("nod mijloc lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                                          readimagefile("sageti.jpg", x+150, y, x + 200, y + 60);}
                                    }
                             }
                        }

            // DIMENSIUNEA TEXTULUI IN FIECARE NOD
            dimensiuneText(p->element);

            // AFISARE IN MODUL GRAFIC
            bgiout << p->element;
            outstreamxy(xtext+50, ytext);

            // COORDONATELE URMATORULUI NOD
            x += 200;
            xtext += 200;

            p = p->urmator;
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
}

// ---------- FUNCTII PENTRU COADA ----------

// ---------- UN NOU NOD DIN COADA DECLARAT ----------

nod_coada* nod_Nou_coada(int element_coada)
{
    nod_coada* nod_nou_coada = new nod_coada();
    nod_nou_coada -> element_coada = element_coada;
    nod_nou_coada -> urmatorul_din_coada = NULL;
    return nod_nou_coada;
}

// ---------- MENIU COADA 1 ----------

void meniuCoada1()
{
    descriereCoada();
    meniuCoada2();
}

// ---------- MENIU COADA 2 ----------

void meniuCoada2()
{   nod_coada* fata_cozii = NULL;
    nod_coada* spatele_cozii = NULL;

    jump:
    cleardevice();
    settextstyle(3, HORIZ_DIR, 4);
    outtextxy(400, 30, "O coada la gustari pentru catei");
    settextstyle(3, HORIZ_DIR, 3);
    readimagefile("treat.jpg",50,100,200,250);
    readimagefile("inapoi coada.jpg",20,600,180,680);
    readimagefile("stergere element coada.jpg",220,600,380,680);
    readimagefile("adauga un element coada.jpg",420,600,580,680);
    readimagefile("element fata cozii.jpg",920,600,1080,680);
    line(0,580,1400,580);
    line(200,580,200,700);
    line(400,580,400,700);
    line(900,580,900,700);
    afisareCoada(fata_cozii);
    here:
    bool gata = false;
    bool buton1 = false, buton2 = false, buton3 = false, inapoi = false;
    int x,y;
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();

            if (x >= 220 && x <= 380 && y >= 600 && y <= 680) //BUTON 1 - STERGERE ELEMENT COADA
            {
                gata = true;
                buton1 = true;
            }
            else
                if (x >= 420 && x <= 580 && y >= 600 && y <= 680)  //BUTON 2 - ADAUGAREA UNUI ELEMENT
                {
                    gata = true;
                    buton2 = true;
                }
                else
                    if (x >= 920 && x <= 1080 && y >=600 && y <=680 ) //BUTON 3 - FRONT
                    {
                        gata = true;
                        buton3 = true;
                    }
                            else
                                if (x >= 20 && x <= 150 && y >= 630 && y <= 680)
                                {
                                    gata = true;
                                    inapoi = true;
                                }
        }
    } while (!gata);

    if (buton1 == true)  // STERGERE
    { mciSendString ("play sunet.mp3", NULL, 0, NULL);
      pop(fata_cozii);
      goto jump;
    }
    else
        if (buton2 == true) //PUSH
        { mciSendString ("play sunet.mp3", NULL, 0, NULL);
         char afisare[100];
         outtextxy(600,600,"Ce catel doriti");
         outtextxy(600,620," sa adaugati? " );

         //Functia de citire a textului in mod grafic in sirul afisare
         citesteSir(" catel nr. ", afisare, 600, 640 , false);

         int valoare= atoi(afisare);  // conversie ascii -> int din sirul afisare
         push(fata_cozii, spatele_cozii, valoare);
         goto jump;
         // RESET LA BUTON

        }
        else
            if (buton3 == true)  // FRONT
            { mciSendString ("play sunet.mp3", NULL, 0, NULL);
              if(element_fata_coada(fata_cozii))
             {mciSendString ("play bark.mp3", NULL, 0, NULL);
              readimagefile("dog.jpg", 1100, 580, 1190,700);
              // DIMENSIUNEA TEXTULUI IN FIECARE NOD
              dimensiuneText(element_fata_coada(fata_cozii));
              // AFISARE IN MODUL GRAFIC
              bgiout << element_fata_coada(fata_cozii);
              outstreamxy(1100+25,580+30);
              goto here;
             // RESET LA BUTON
             }
            else {outtextxy(1100,600,"Coada este goala");
                  goto here;}
            }
            else
                    if (inapoi == true)  //BACK
                            { mciSendString ("play sunet.mp3", NULL, 0, NULL);
                              cleardevice();
                              meniuCoada1();
                            }
}

// ---------- NOTIUNI TEORETICE DESPRE COADA ----------

void descriereCoada()
{
    cleardevice();
    readimagefile("next.jpg",640,710,850,790);
    settextstyle(3, HORIZ_DIR, 4);
    outtextxy(430,50, "Informatii despre coada");
    settextstyle(3, HORIZ_DIR, 3);
    outtextxy(120, 100, "    Coada (queue) este o structura de date abstracta in care operatia");
    outtextxy(120, 130, " de adaugare se realizeaza la un capat, iar cea de eliminare se");
    outtextxy(120, 160, " realizeaza la celalalt capat.");
    outtextxy(120, 190, "    In timpul operatiilor cu coada avem acces la un singur element, cel");
    outtextxy(120, 220, " aflat la inceputul cozii, adica elementul care urmeaza sa se elimine.");
    outtextxy(120, 250, "    Cu o coada se pot face urmatoarele operatii:");
    outtextxy(120, 280, "    -initializarea cozii: crearea unei cozi vide;");
    outtextxy(120, 310, "    -verificarea faptului ca o coada este sau nu vida;");
    outtextxy(120, 340, "    -adaugarea unui nou element in coada. Operatia se numeste push;");
    outtextxy(120, 370, "    -eliminarea unui element din coada. Operatia se numeste pop;");
    outtextxy(120, 400, "    -identificarea valorii elementului de la inceputul cozii: accesul ");
    outtextxy(120, 430, "     la acel element. Operatia se numeste front.");
    outtextxy(120, 460, "    Operatiile cu coada sunt similare cu modul in care functioneaza coada");
    outtextxy(120, 490, " la casa de bilete a unui cinematograf.Spectatorii vin si se aseaza in ");
    outtextxy(120, 520, " ordine la coada, ordinea in care cumpara biletele este aceea in care au sosit.");
    outtextxy(120, 550, "    Deoarece operatiile de eliminare se fac in aceeasi ordine ca cele de ");
    outtextxy(120, 580, " adaugare, coada este o structura de date de tip FIFO : First In First Out.");

    readimagefile("exemplu coada.jpg",910,100,1250,480);
    //---------BUTON PENTRU PAGINA URMATOARE-----------------
    readimagefile("inapoi coada.jpg",910,510,1060,580);
    //-------------BUTON INAPOI----------------------------------
    readimagefile("next coada.jpg",1110,510,1260,580);

    bool gata = false, inainte = false, inapoi = false;
    int x,y;
    do
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
            if(x >= 910 && x <= 1060 && y >=510  && y <= 580)
            {
                gata = true;
                inapoi = true;
            }
            else   if (x >= 1110 && x <= 1260 && y >= 510 && y <= 580)
                                {
                                    gata = true;
                                    inainte = true;
                                }
        }
    } while (!gata);
    if (inainte == true)
    {   mciSendString ("play sunet.mp3", NULL, 0, NULL);
        cleardevice();
        return;
    }
    else if(inapoi == true)
        {mciSendString ("play sunet.mp3", NULL, 0, NULL);
         cleardevice();
         meniuPrincipal();
        }
    delay(15000);   // 1 sec =  1000 ms
    cleardevice();
}

// ---------- FUNCTIE PENTRU STABILIREA DACA ESTE SAU NU COADA GOALA ----------

bool isEmpty(nod_coada* fata_cozii)
{
    return fata_cozii == NULL;
}

// ---------- INTRODUCEREA UNUI ELEMENT LA COADA ----------

void push(nod_coada* &fata_cozii, nod_coada* &spatele_cozii, int element_coada)
{
    nod_coada* nod_nou_coada = nod_Nou_coada(element_coada);

    if(spatele_cozii != NULL)
        spatele_cozii -> urmatorul_din_coada = nod_nou_coada;

    spatele_cozii = nod_nou_coada;
    if(fata_cozii == NULL)
        fata_cozii = nod_nou_coada;
}

// ---------- ELIMINAREA UNUI ELEMENT DIN COADA ----------

int pop(nod_coada* &fata_cozii)
{
    if(isEmpty(fata_cozii))
        return 0;
    nod_coada* copie_fata_cozii = fata_cozii;
    fata_cozii = fata_cozii -> urmatorul_din_coada;
    int element_de_scos_din_coada = copie_fata_cozii -> element_coada;
    delete copie_fata_cozii;
    return element_de_scos_din_coada;
}

// ---------- GENERAREA ELEMENTULUI DIN FATA COZII ----------

int element_fata_coada(nod_coada* fata_cozii)
{
    if(isEmpty(fata_cozii))
        return 0;
    return fata_cozii -> element_coada;
}

// ---------- AFISAREA COZII ----------

void afisareCoada(nod_coada* fata_cozii)
{
    if(isEmpty(fata_cozii)){outtextxy(300,100,"Nu este niciun catel la coada");readimagefile("SAD.jpg",180,200,600,500);}
    else
    {
    setbkcolor(BLACK);
    nod_coada* p = fata_cozii;
    unsigned int x = 200, y = 100;
    unsigned int xtext = 210, ytext = 110;

    while (p != NULL)
    {
        if (x <= 1250)  // daca nu iese din ecran
        {   //LATRAT DE CATEL
            mciSendString ("play bark1.mp3", NULL, 0, NULL);
            // AFISAREA NODULUI CORESPUNZATOR
            readimagefile("dog.jpg", x, y, x + 100, y + 150);


            // DIMENSIUNEA TEXTULUI IN FIECARE NOD
            dimensiuneText(p->element_coada);

            // AFISARE IN MODUL GRAFIC
            bgiout << p->element_coada;
            outstreamxy(xtext+25, ytext+40);

            // COORDONATELE URMATORULUI NOD
            x += 102;
            xtext += 102;

            p = p->urmatorul_din_coada;
            delay(500);
        }
        else
        {
            // COORDONATELE URMATORULUI RAND DACA SE AJUNGE LA CAPAT DE ECRAN
            x = 20;
            y += 200;
            xtext = 25;
            ytext += 210;
        }
     }

 }
}


// ---------- SFARSIT PROGRAM ----------
