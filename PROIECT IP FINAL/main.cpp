#include <iostream>
#include <windows.h>
#include <MMsystem.h>
#include <mmsystem.h>
#include <fstream>
#include <graphics.h>
#include <queue>

using namespace std;

// ---------- MEMORAREA UNEI LISTE DUBLU INLANTUITE ----------

struct nod_lista_dublu_inlantuita //REALIZATA DE ANDREI
{
    int element;    //ELEMENTUL MEMORAT
    nod_lista_dublu_inlantuita* urmator;    //NODUL URMATOR MEMORAT
    nod_lista_dublu_inlantuita* anterior;   //NODUL ANTERIOR MEMORAT
};

// ---------- MENIU PRINCIPAL SI ALTE ELEMENTE --------
void deschidere();
void meniuPrincipal();
void descriereProiect1();
void descriereProiect2();
void descriereProiect3();
void descriereAutori();
void gifDiCaprio();
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

struct nod_coada //REALIZAT DE ANDREI
{
    int element_coada;      //ELEMENTUL NODULUI DIN COADA
    nod_coada* urmatorul_din_coada;    //NOD URMATOR IN COADA MEMORAT
};

// ---------- DECLARARE ANTET PENTRU FUNCTIILE UTILIZARE LA COADA ----------

nod_coada* creare_nod_nou_in_coada(int element_coada);
void meniuCoada1();
void meniuCoada2();
void descriereCoada();
int element_fata_coada(nod_coada* fata_cozii);
void push(nod_coada* &fata_cozii, nod_coada* &spatele_cozii, int element_coada);
int pop(nod_coada* &fata_cozii);
bool isEmpty(nod_coada* fata_cozii);
void afisareCoada(nod_coada* fata_cozii);

// ---------- MENIU DE DESCHIDERE ----------

void deschidere() //REALIZATA DE ANDREI
{
    cleardevice(); //FUNCTIE DE CURATAREA ECRANULUI

    sunet(); //APELAREA FUNCTIEI PENTRU MUZICA DE FUNDAL

    settextstyle(3, HORIZ_DIR, 5); //SELECTAREA TIPULUI DE SCRIS, DIRECTIEI SI A MARIMII ACESTUIA
    outtextxy(600, 100, " Bine ai venit! "); //SCRIEREA IN FEREASTRA GRAFICA A UNUI MESAJ DE INTAMPINARE

    // BUTON 1 - START
    readimagefile("start.jpg",600,210,910,280);

    // BUTON 2 -  DESPRE PROIECT
    readimagefile("despre proiect.jpg",600,310,910, 380);

    // BUTON 3 - DESPRE AUTORI
    readimagefile("despre autori.jpg",600,410,910, 480);

    // BUTON 4 - IESIRE DIN PROGRAM
    readimagefile("iesire.jpg",600,510,910, 580);

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
            if(x >= 600 && x <= 910 && y >= 210 && y <= 280)  // BUTON 1 - START
            {
                gata = true;
                buton1 = true;
            }
            else
                if(x >= 600 && x <= 910 && y >= 310 && y <= 380)  // BUTON 2 -  DESPRE PROIECT
                {
                    gata = true;
                    buton2 = true;
                }
                else
                    if(x >= 600 && x <= 910 && y >= 410 && y <= 480)  // BUTON 3 - DESPRE AUTORI
                    {
                        gata = true;
                        buton3 = true;
                    }
                    else
                        if(x >= 600 && x <= 910 && y >= 510 && y <= 580) // BUTON 4 - IESIRE DIN PROGRAM
                        {
                            gata = true;
                            buton4 = true;
                        }
        }
    } while (!gata);

    cleardevice();
    if (buton1 == true)
    {
        mciSendString ("play sunet.mp3", NULL, 0, NULL); //SUNET LA APASAREA BUTONULUI
        sunet();
        meniuPrincipal(); //APEL MENIU PRINCIPAL
    }
    else
        if (buton2 == true)
        {
            mciSendString ("play sunet.mp3", NULL, 0, NULL);
            sunet();
            descriereProiect1();//APEL DESCRIEREA PROIECTULUI
        }
        else
            if(buton3 == true)
            {
                mciSendString ("play sunet.mp3", NULL, 0, NULL);
                sunet();
                descriereAutori(); //APEL DESCRIEREA AUTORILOR PROIECTULUI
            }
            else
                if(buton4 == true)
                {
                    mciSendString ("play sunet.mp3", NULL, 0, NULL);
                    sunet();
                    cleardevice();
                    settextstyle(5, HORIZ_DIR, 5);
                    outtextxy(500,100,"Va dorim o zi buna!");
                    delay(500); //AMANA URMATOARELE OPERATII CU 0.5 SECUNDE
                    gifDiCaprio(); //APEL FUNCTIE DE AFISARE A UNUI GIF
                    closegraph(); //INCHIDEREA FERESTREI GRAFICE
                    exit(0);
                }
}

// ---------- MENIU PRINCIPAL ----------

void meniuPrincipal() // //REALIZATA DE ANA
{
    cleardevice();
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

    // BUTON 5 - Inapoi la meniul de deschidere
    readimagefile("inapoi albastru.jpg",600,610,910, 680);

    bool gata = false;
    bool buton1 = false, buton2 = false, buton3 = false, buton4 = false, buton5;
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
                        else
                            if(x >= 600 && x <= 910 && y >= 610 && y <= 680)  // Inapoi
                            {
                                gata = true;
                                buton5 = true;
                            }
        }
    } while (!gata);
    cleardevice();
    if (buton1 == true)
    {
        mciSendString ("play sunet.mp3", NULL, 0, NULL);
        sunet();
        //meniuListeSimpluInlantuite();
    }
    else
        if (buton2 == true)
        {
            mciSendString ("play sunet.mp3", NULL, 0, NULL);
            sunet();
            meniuListeDubluInlantuite1();//APEL MENIU LISTE DUBLU INLANTUITE 1
        }
        else
            if(buton3 == true)
            {
                mciSendString ("play sunet.mp3", NULL, 0, NULL);
                sunet();
                // meniuStive();
            }
            else
                if(buton4 == true)
                {
                    mciSendString ("play sunet.mp3", NULL, 0, NULL);
                    sunet();
                    meniuCoada1(); //APEL MENIU COADA 1
                }
                else
                    if(buton5 == true)
                    {
                        mciSendString ("play sunet.mp3", NULL, 0, NULL);
                        sunet();
                        deschidere(); //APEL MENIU DESCHIDERE
                    }
}

// ---------- DESCRIERE PROIECT PAGINA 1 ----------

void descriereProiect1() //REALIZATA DE ANDREI
{
    cleardevice();

     // BUTON PENTRU PAGINA URMATOARE
    readimagefile("inainte.jpg",720,650,920,690);

    // BUTON PENTRU PAGINA PRECEDENTA ADICA MENIUL PRINCIPAL
    readimagefile("pagina de deschidere.jpg",480,650,680,690);

    // INSERAREA UNEI POZE IN FEREASTRA GRAFICA
    readimagefile("biblia2.jpg",1000,100,1300,400);

    readimagefile("biblia1.jpg",100,390,500,630);

    // TITLUL FERESTREI
    settextstyle(3, HORIZ_DIR,4);
    outtextxy(500,50,"PROIECTUL BIBLIS");

    //TEXTUL DIN PARTEA DE SUS A PAGINII
    settextstyle(8, HORIZ_DIR,3);
    outtextxy(100,130,"     Cand am auzit prima data de numele proiectului nostru, ");
    outtextxy(100,160,"BIBLIS, primul gand ne-a purtat catre Sfanta Biblie. Ne  ");
    outtextxy(100,190,"intrebam oare la ce se refera acest proiect si am decis");
    outtextxy(100,220,"sa ne documentam mai mult. ");
    outtextxy(100,250,"     Primul gand nu a fost prea de ajutor, proiectul nostru ");
    outtextxy(100,280,"nu se referea nicicum la Noul sau Vechiul Testament,");
    outtextxy(100,310,"dar pentru ca a noastra cautare sa nu fie degeaba,iata ");
    outtextxy(100,340,"cateva cunostinte generale gasite:");

    //TEXTUL DIN PARTEA DE JOS A PAGINII
    outtextxy(520,420,"     Biblia se refera la Scripturile sacre din iudaism ");
    outtextxy(520,450,"si crestinism. Pentru evreii credinciosi,Biblia consta ");
    outtextxy(520,480,"din Vechiul Testament (o versiune a Bibliei ebraice) ");
    outtextxy(520,510,"impreuni cu Noul Testament.");
    outtextxy(520,540,"Biblia este cea mai raspandita carte din lume.");

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
                if(x >= 480 && x <= 680 && y >=650  && y <= 690)   // BUTON PENTRU PAGINA PRECEDENTA
                {
                    gata=true;
                    inapoi = true;
                }
        }
    } while (!gata);

    if (inainte == true)    // BUTON PENTRU PAGINA URMATOARE
    {
        mciSendString ("play sunet.mp3", NULL, 0, NULL); //SUNET LA APASAREA BUTONULUI
        sunet();
        descriereProiect2(); //APEL DESCRIERE PROIECT 2
    }
    else
        if(inapoi == true)   // BUTON PENTRU PAGINA PRECEDENTA ADICA MENIUL PRINCIPAL
        {
            mciSendString ("play sunet.mp3", NULL, 0, NULL); //SUNET LA APASAREA BUTONULUI
            sunet();
            deschidere();
        }
    cleardevice();
}

// ---------- DESCRIERE PROIECT PAGINA 2 ----------

void descriereProiect2() //REALIZATA DE ANDREI
{
    cleardevice();

     // BUTON PENTRU PAGINA URMATOARE
    readimagefile("inainte.jpg",720,650,920,690);

    // BUTON PENTRU PAGINA PRECEDENTA ADICA MENIUL PRINCIPAL
    readimagefile("inapoi alb.jpg",480,650,680,690);

    // INSERAREA UNEI IMAGINI
    readimagefile("Catedrala.jpg",100,100,350,450);

    readimagefile("atom.jpg",850,350,1300,650);

    // TITLUL PAGINII
    settextstyle(3, HORIZ_DIR,4);
    outtextxy(500,50,"PROIECTUL BIBLIS");

    //TEXTUL DIN PARTEA DE SUS A PAGINII
    settextstyle(8, HORIZ_DIR,3);
    outtextxy(370,140,"     Al doilea gand a fost direct sa cautam pe internet ");
    outtextxy(370,170,"cuvantul Biblis. Rezultatul ne-a surprins putin, am gasit ");
    outtextxy(370,200,"Biblis ca fiind o comuna din  landul Hessa, Germania.");
    outtextxy(370,230,"Cu o arhitectura frumoasa, Biserica Sf. Bartolomeu dateaza");
    outtextxy(370,260,"din anul 1865.In fiecare an, in iunie, Gurkenfest ");
    outtextxy(370,290,"(Festivalul Castravetilor) este deschis de catre Gurkenkanigin");
    outtextxy(370,320,"(Regina de castraveti) pentru bucuria vizitatorilor.");

    //TEXTUL DIN PARTEA DE JOS A PAGINII
    outtextxy(100,470,"  Biblis are Centrala Nucleara Biblis, situata");
    outtextxy(100,500," pe raul Rin, cu doua blocuri de reactoare.");
    outtextxy(100,530,"  La momentul deschiderii, Biblis era cea mai ");
    outtextxy(100,560,"mare centrala nucleara din lume si o etapa");
    outtextxy(100,590,"importanta ingenerarea de energie electrica.");

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
                if(x >= 480 && x <= 680 && y >=650  && y <= 690)   // BUTON PENTRU PAGINA PRECEDENTA
                {
                    gata=true;
                    inapoi = true;
                }
        }
    } while (!gata);

    if (inainte == true)    // BUTON PENTRU PAGINA URMATOARE
    {
        mciSendString ("play sunet.mp3", NULL, 0, NULL);
        sunet();
        descriereProiect3();
    }
    else
        if(inapoi == true)   // BUTON PENTRU PAGINA PRECEDENTA
        {
            mciSendString ("play sunet.mp3", NULL, 0, NULL);
            sunet();
            descriereProiect1();
        }
    cleardevice();
}

// ---------- DESCRIERE PROIECT PAGINA 3 ----------

void descriereProiect3() //REALIZATA DE ANDREI
{
    cleardevice();

    // IMAGINE CU BIBLIOTECA
    readimagefile("library.jpg",0,0,1400,700);

     // BUTON PENTRU PAGINA DE DESCHIDERE
    readimagefile("pagina de deschidere.jpg",720,650,920,690);

    // BUTON PENTRU PAGINA PRECEDENTA
    readimagefile("inapoi alb.jpg",480,650,680,690);

    // TITLUL PAGINII
    settextstyle(3, HORIZ_DIR,4);
    outtextxy(500,50,"PROIECTUL BIBLIS");

    // TEXTUL DE PE PAGINA
    settextstyle(3, HORIZ_DIR,3);
    outtextxy(400,130,"   Pana la urma am inteles ca proiectul presupune programarea    ");
    outtextxy(400,160,"unei biblioteci de functii pentru operatii cu liste implementate ");
    outtextxy(400,190,"   dinamic (simplu inlantuite, dublu-inlantuite, stive, cozi)    ");

    //EXEMPLU LISTE SIMPLU INLANTUITE
    outtextxy(300,220,"Liste simplu inlantuite");
    readimagefile("liste simplu inlantuite exemplu.jpg",100,260,600,400);

    //EXEMPLU LISTE DUBLU INLANTUITE
    outtextxy(1000,220,"Liste dublu inlantuite");
    readimagefile("Exemplu lista dublu inlantuita.jpg",800,260,1300,400);

    //EXEMPLU STIVE
    outtextxy(300,450,"Stiva");
    readimagefile("stive ex.jpg",250,500,400,600);

    //EXEMPLU COADA
    outtextxy(1050,450,"Coada");
    readimagefile("exemplu coada.jpg",1000,500,1150,650);

    bool gata = false, inainte = false, inapoi=false;
    int x,y;
    do
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
            if(x >= 720 && x <= 920 && y >=650  && y <= 690)    // BUTON PENTRU PAGINA DE DESCHIDERE
            {
                gata = true;
                inainte=true;
            }
            else
                if(x >= 480 && x <= 680 && y >=650  && y <= 690)   // BUTON PENTRU PAGINA PRECEDENTA
                {
                    gata=true;
                    inapoi = true;
                }
        }
    } while (!gata);

    if (inainte == true)    // BUTON PENTRU PAGINADE DESCHIDERE
    {
        mciSendString ("play sunet.mp3", NULL, 0, NULL);
        sunet();
        deschidere();
    }
    else
        if(inapoi == true)   // BUTON PENTRU PAGINA PRECEDENTA
        {
            mciSendString ("play sunet.mp3", NULL, 0, NULL);
            sunet();
            descriereProiect2();
        }
    cleardevice();
}

// ---------- DESCRIERE AUTORI ----------

void descriereAutori() //REALIZATA DE ANDREI
{
     // POZA ANEI
    readimagefile("Ana Mitrea.jpg",30,100,325,500);

    // POZA LUI ANDREI
    readimagefile("Andrei Tablan.jpeg",1075,300,1350,600);

    // BUTON INAPOI
    readimagefile("inapoi alb.jpg",625,640,775,670);

    settextstyle(3, HORIZ_DIR, 4);

    // TITLUL PAGINII
    setbkcolor(BLUE);
    outtextxy(530,30, "Autorii proiectului");
    settextstyle(3, HORIZ_DIR, 2);
    setbkcolor(BLACK);

    //TEXT DESCRIERE ANA
    outtextxy(40,510, " Ana-Maria Mitrea, studenta");
    outtextxy(40,535, "la Facultatea de Informatica ");
    outtextxy(40,560, " din Iasi, anul 1, grupa A5");
    outtextxy(40,585, "      Informatii de contact:");
    outtextxy(40,610, "email: ana.mitrea@info.uaic.ro");

    //TEXT DESCRIERE ANDREI
    outtextxy(1080,170, "Andrei-Razvan Tablan, student");
    outtextxy(1080,195, " la Facultatea de Informatica ");
    outtextxy(1080,220, "  din Iasi, anul 1, grupa A5");
    outtextxy(1080,245, "      Informatii de contact:");
    outtextxy(1080,270, "email: andrei.tablan@info.uaic.ro");

    //TEXT VORBELE ANEI
    settextstyle(5, HORIZ_DIR, 2);
    outtextxy(340,120,"   „Mi-a placut foarte mult sa lucrez la acest proiect. A fost" );
    outtextxy(340,145,"o provocare interesanta si am imbratisast fiecare impediment cu");
    outtextxy(340,170,"multa pasiune pana cand l-am putut depasi. Proiectul nostru nu");
    outtextxy(340,195,"este perfect, cu siguranta sunt multe lucruri de imbunatatit dar");
    outtextxy(340,220,"am incercat tot ce am putut mai bun din noi! Sper sa va placa si");
    outtextxy(340,245,"asteptam cu mult drag feedback-ul din partea dumneavoastra.  ");
    outtextxy(340,270,"                                                     -Ana     ");

    //TEXT VORBELE LUI ANDREI
    outtextxy(420,450,"   „Mi-a placut foarte mult sa lucrez la acest proiect. A fost" );
    outtextxy(420,475,"o provocare interesanta si am imbratisast fiecare impediment cu");
    outtextxy(420,500,"multa pasiune pana cand l-am putut depasi. Proiectul nostru nu");
    outtextxy(420,525,"este perfect, cu siguranta sunt multe lucruri de imbunatatit dar");
    outtextxy(420,550,"am incercat tot ce am putut mai bun din noi! Sper sa va placa si");
    outtextxy(420,575,"asteptam cu mult drag feedback-ul din partea dumneavoastra.  ");
    outtextxy(420,600,"                                                -Andrei   ");

    bool gata = false, inapoi=false;
    int x,y;
    do
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
                if(x >= 625 && x <= 775 && y >=640  && y <= 670)   // BUTON PENTRU PAGINA PRECEDENTA
                {
                    gata=true;
                    inapoi = true;
                }
        }
    } while (!gata);

    if(inapoi == true)   // BUTON PENTRU PAGINA PRECEDENTA
    {
        mciSendString ("play sunet.mp3", NULL, 0, NULL);
        sunet();
        cleardevice();
        deschidere();
    }
    cleardevice();
}

// ---------- CREARE GIF PENTRU IESIRE ----------

void gifDiCaprio() // REALIZAT DE ANDREI
{
    //UN GIF SE POATE REALIZA PRIN CITIREA MAI MULTOR IMAGINI LA UN TIMP RELATIV SCURT (IN CAZUL CELUI PREZENTAT 0.1s)
    //GIFUL CREAT ARE 14 IMAGINI SI DISTANTA DINRE CITIREA LOR ESTE DE 0.1 SECUNDE
    //GIFUL SE REPETA DE DOUA ORI

    readimagefile("frame00.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame01.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame02.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame03.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame04.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame05.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame06.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame07.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame08.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame09.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame10.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame11.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame12.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame13.gif",100,200,1200,650);
    delay(100);

    readimagefile("frame00.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame01.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame02.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame03.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame04.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame05.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame06.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame07.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame08.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame09.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame10.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame11.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame12.gif",100,200,1200,650);
    delay(100);
    readimagefile("frame13.gif",100,200,1200,650);
    delay(100);
}

// ---------- FUNCTII UTILIZATE PENTRU SCRIEREA GRAFICA ----------

// ---------- INITIALIZARE FEREASTRA GRAFICA ----------

void fereastra() //REALIZATA DE ANDREI
{
    initwindow(1400, 700, " BIBLIS ");
}

// ---------- INTERFATA ----------

void interfataGrafica() //REALIZATA DE ANA
{
    fereastra();
    deschidere();
    cleanup();
}

// ---------- CLEANUP ----------

void cleanup() //REALIZATA DE ANA
{
    getch();
    closegraph();
}

// ---------- SUNET DE FUNDAL ----------

void sunet() //REALIZATA DE ANDREI
{
    mciSendString ("play song.mp3", NULL, 0, NULL);
}

// ---------- STABILIREA MARIMII TEXTULUI IN FUNCTIE DE NUMARUL DE CARACTERE ----------

void dimensiuneText(int element) //REALIZATA DE ANA
{
    if(element >= 0 && element < 100)
        settextstyle(3, HORIZ_DIR, 3);
    else
        if(element >= 100 && element < 1000)
            settextstyle(3, HORIZ_DIR, 2);
        else
            if(element >=1000 && element <100000)
                settextstyle(3, HORIZ_DIR, 1);
}

// ---------- FUNCTIA DE CITIRE IN MOD GRAFIC ----------

void citesteSir(char text[100], char afisare[100], int x, int y, bool stergere) //PRELUATA DIN MERGE SORT DATA DE DOMNUL PROF. PATRUT
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

void meniuListeDubluInlantuite1() //REALIZATA DE ANDREI
{
    descriereListaDubluInlantuita();    //APELEAZA FEREASTRA DE DESCRIERE A LISTELOR DUBLU INLANTUITE
    citireElementeListaDubluInlantuita();   //APELEAZA FEREASTRA DE CITIRE A ELEMENTELOR PENTRU LISTE DUBLU INLANTUITE
}

//-----------------MENIU PENTRU LISTE DUBLU INLANTUITE NR.2 --------------------

void meniuListeDubluInlantuite2() //REALIZATA DE ANDREI CU AJUTORUL ANEI
{
    cleardevice();
    settextstyle(3, HORIZ_DIR, 5);
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
        mciSendString ("play sunet.mp3", NULL, 0, NULL);
        sunet();
        cleardevice();
        meniuInserareListeDubluInlantuite();
    }
    else
        if (buton2 == true)  //STERGEREA UNUI ELEMENT
        {
            mciSendString ("play sunet.mp3", NULL, 0, NULL);
            sunet();
            cleardevice();
            meniuStergereListeDubluInlantuite();
        }
        else
            if (buton3 == true)  //CAUTAREA UNUI ELEMENT
            {
                mciSendString ("play sunet.mp3", NULL, 0, NULL);
                sunet();
                cleardevice();
                meniuCautareListeDubluInlantuite();
            }
            else
                if (buton4 == true) //CITIREA UNEI LISTE NOI
                {
                    mciSendString ("play sunet.mp3", NULL, 0, NULL);
                    sunet();
                    cleardevice();
                    citireElementeListaDubluInlantuita();
                }
                else
                    if (buton5 == true) //MENIU PRINCIPAL
                    {
                        mciSendString ("play sunet.mp3", NULL, 0, NULL);
                        sunet();
                        cleardevice();
                        meniuPrincipal();
                    }
                    else
                        if (buton6 == true) //INAPOI LA FEREASTRA DE DESCRIERE A LISTELOR DUBLU INLANTUITE
                        {
                            mciSendString ("play sunet.mp3", NULL, 0, NULL);
                            sunet();
                            cleardevice();
                            descriereListaDubluInlantuita();
                        }

}

// ---------- DESCRIERE LISTA DUBLU INLANTUITA ----------

void descriereListaDubluInlantuita() //RALIZATA DE ANDREI CU AJUTORUL ANEI
{
    cleardevice();
    settextstyle(4, HORIZ_DIR, 3);

    //TITLUL FERESTREI
    outtextxy(330,50, "Informatii despre listele dublu inlantuite");
    settextstyle(4, HORIZ_DIR, 1);

    //SCRIEREA DOCUMENTATIEI DESPRE LISTELE DUBLU INLANTUITE //SURSA : pbinfo.ro
    outtextxy(150, 150, "       Listele dublu inlantuite sunt structuri de date dinamice omogene. Ele au aceleasi");
    outtextxy(150, 180, "caracteristici de baza ca si listele liniare simplu inlantuite. Diferenta fata de aceastea");
    outtextxy(150, 210, "consta in faptul ca, pentru fiecare nod, se retine si adresa elementului anterior, ceea ce ");
    outtextxy(150, 240, "permite traversarea listei in ambele directii. Lista dublu inlantuita poate fi reprezentata");
    outtextxy(150, 270, "grafic astfel:");

    // EXEMPLU LISTA DUBLU INLANTUITA
    readimagefile("Exemplu lista dublu inlantuita.jpg",150,300,1250,650);

     // BUTON PENTRU PAGINA URMATOARE
    readimagefile("pagina urmatoare.jpg",720,650,920,690);

    // BUTON PENTRU PAGINA PRECEDENTA
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
                if(x >= 480 && x <= 680 && y >=650  && y <= 690)   // BUTON PENTRU PAGINA PRECEDENTA
                {
                    gata=true;
                    inapoi = true;
                }
        }
    } while (!gata);

    if (inainte == true)    // BUTON PENTRU PAGINA URMATOARE
    {
        mciSendString ("play sunet.mp3", NULL, 0, NULL);
        sunet();
        cleardevice();
        citireElementeListaDubluInlantuita();
    }
    else
        if(inapoi == true)   // BUTON PENTRU PAGINA PRECEDENTA
        {
            mciSendString ("play sunet.mp3", NULL, 0, NULL);
            sunet();
            cleardevice();
            meniuPrincipal();
        }

    delay(15000);   // 1 sec =  1000 ms
    cleardevice();
}


// ---------- FUNCTIA DE CITIRE ----------

void citireElementeListaDubluInlantuita() //SCRISA DE ANDREI CU AJUTORUL PROBLEMEI MERGE SORT DATA DE DOMNUL PROF. PATRUT
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

    if(n>20)    //DACA NUMARUL DE ELEMENTE CARE VOR FI CITITE ESTE MAI MARE DECAT 20 SE VA AFISA O EROARE
    {
        mciSendString ("play sunet.mp3", NULL, 0, NULL);
        sunet();
        outtextxy(400,40,"Ati introdus un numar mai mare de 20");
        delay(5000);
        cleardevice();
        citireElementeListaDubluInlantuita();   // REDESCHIDERE A FUNCTIEI DE CITIRE
    }
    else
        {
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

void creareListaDubluInlantuita (nod_lista_dublu_inlantuita*& prim , int n , int Valoarea[20]) //REALIZATA DE ANDREI
{
    for(int i=0;i<n;i++)
        inserareFinalListaDubluInlantuita( prim , Valoarea[i] );
}

//------------------MENIU INSERARE LD------------------

void meniuInserareListeDubluInlantuite() //REALIZATA DE ANDREI
{
    //LABEL PENTRU RESETAREA BUTONULUI
    jump:

    cleardevice();

    afisareListaDubluInlantuitaInserare(prim); //APEL FUNCTIE DE AFISARE A LISTEI PENTRU MENIUL DE INSERARE

    //TITLU PENTRU MENIUL DE INSERARE
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

            if(x >= 860 && x <= 1085 && y >= 100 && y <= 180) // BUTON 1
            {
                gata = true;
                buton1 = true;
            }
            else
                if(x >= 1125 && x <= 1350 && y >= 100 && y <= 180)  // BUTON 2
                {
                    gata = true;
                    buton2 = true;
                }
               else
                        if (x >=860 && x <= 1085 && y >= 200 && y <= 280) // BUTON 3
                        {
                            gata = true;
                            buton3 = true;
                        }
                        else
                               if (x >=1125 && x <= 1350 && y >= 200 && y <= 280) // BUTON 4
                                {
                                    gata = true;
                                    buton4 = true;
                                }
                                else
                                    if (x >=947 && x <= 1238 && y >= 310 && y <= 390) // BUTON 5
                                    {
                                        gata = true;
                                        buton5 = true;
                                    }
        }

    } while (!gata);

    if (buton1 == true)
    {
        mciSendString ("play sunet.mp3", NULL, 0, NULL);
        sunet();

        char afisare[100]; //DECLARAREA SIRULUI CARE VA FI CITIT

        //SCRIERE INTREBARE IN COLTUL DIN DREAPTA JOS
        settextstyle(3, HORIZ_DIR, 3);
        outtextxy(937,410,"Ce numar doriti");
        outtextxy(937,450,"  sa inserati? " );

        //APELUL FUNCTIEI DE CITIRE PENTRU TEXTUL SCRIS DUPA "numarul:"
        citesteSir("numarul: ", afisare, 947, 480, false);

        int valoare = atoi(afisare);//CONVERSIA DIN ASCII A SIRULUI AFISARE IN INT

        inserareInceputListaDubluInlantuita(prim, valoare);

        //CONTORIZAM NUMARUL DE ELEMENTE CITITE DACA S-A FACUT INSERAREA
        numarElemente++;
        goto jump;  // RESET LA BUTON
    }
    else
        if (buton2 == true)
        {
            mciSendString ("play sunet.mp3", NULL, 0, NULL);
            sunet();

            char afisare[100];//DECLARAREA SIRULUI CARE VA FI CITIT

            //SCRIERE INTREBARE IN COLTUL DIN DREAPTA JOS
            settextstyle(3, HORIZ_DIR, 3);
            outtextxy(937,410,"Ce numar doriti");
            outtextxy(937,430,"  sa inserati? " );

            //APELUL FUNCTIEI DE CITIRE PENTRU TEXTUL SCRIS DUPA "numarul:"
            citesteSir("numarul: ", afisare, 937, 450, false);

            int valoare = atoi(afisare);//CONVERSIA DIN ASCII A SIRULUI AFISARE IN INT

            inserareFinalListaDubluInlantuita(prim, valoare);

            //CONTORIZAM NUMARUL DE ELEMENTE CITITE DACA S-A FACUT INSERAREA
            numarElemente++;

            goto jump;  // RESET LA BUTON
        }
        else
            if (buton3 == true)
            {
                mciSendString ("play sunet.mp3", NULL, 0, NULL);
                sunet();

                char afisare[100],afisare1[100];//DECLARAREA SIRURILOR CARE VOR FI CITITE

                //SCRIERE INTREBARE IN COLTUL DIN DREAPTA JOS
                settextstyle(3, HORIZ_DIR, 3);
                outtextxy(937,410,"Ce numar doriti sa inserati");
                outtextxy(937,450,"   si dupa pe ce pozitie?    " );

               //APELUL FUNCTIEI DE CITIRE PENTRU TEXTUL SCRIS DUPA "numarul:"
                citesteSir("numarul: ", afisare, 947, 480, false);
                //APELUL FUNCTIEI DE CITIRE PENTRU TEXTUL SCRIS DUPA "pozitia:"
                citesteSir("pozitia: ", afisare1, 947, 510, false);

                int valoare = atoi(afisare);//CONVERSIA DIN ASCII A SIRULUI afisare IN INT
                int pozitia = atoi(afisare1);//CONVERSIA DIN ASCII A SIRULUI afisare1 IN INT

                nod_lista_dublu_inlantuita *nod_cautat = cautarePozitieLD(prim,pozitia); //CAUTAM NODUL CU POZITIA CITITA

                if(pozitia < numarElemente && pozitia >= 0) //VERIFICAM DACA EXISTA POZITITA ICITITA
                {
                    inserareElementListaDubluInlantuita(prim,nod_cautat,valoare);

                    numarElemente++;
                    goto jump;  // RESET LA BUTON
                }
                else
                    {   //IN CAZ DE NU EXISTA POZITIA CITITA SCRIEM O EROARE SI RESETAM BUTONUL
                        Beep(1000,100);

                        outtextxy(1000,530,"Nodul introdus");
                        outtextxy(1000,550,"  nu exista");

                        delay(5000);
                        goto jump;
                    }

            }
            else
                if(buton4 == true)
                {
                    mciSendString ("play sunet.mp3", NULL, 0, NULL);
                    sunet();
                    char afisare[100],afisare1[100];

                    //SCRIERE INTREBARE IN COLTUL DIN DREAPTA JOS
                    settextstyle(3, HORIZ_DIR, 3);
                    outtextxy(937,410,"Ce numar doriti sa inserati");
                    outtextxy(937,450,"   si dupa pe ce element?    " );

                    citesteSir("numarul: ", afisare, 947, 480, false);
                    citesteSir("elementul: ", afisare1, 947, 510, false);

                    int valoare= atoi(afisare);
                    int elementul= atoi(afisare1);

                    nod_lista_dublu_inlantuita *nod_cautat=cautareValoareLD(prim,elementul);//CAUTAM NODUL CU POZITIA CITITA

                    if(nod_cautat!=NULL) //VERIFICAM DACA EXISTA ELEMENTUL CITIT
                    {
                        inserareElementListaDubluInlantuita(prim,nod_cautat,valoare);

                        numarElemente++;
                        goto jump;  // RESET LA BUTON
                    }
                    else { //IN CAZ DE NU EXISTA ELEMENTUL CITIT SCRIEM O EROARE SI RESETAM BUTONUL
                            Beep(1000,100);

                            outtextxy(1000,530,"Valoarea introdusa");
                            outtextxy(1000,550,"    nu exista");

                            delay(5000);
                            goto jump;
                         }

                }
                else
                    if (buton5 == true) //BUTONUL INAPOI
                    {
                        mciSendString ("play sunet.mp3", NULL, 0, NULL);
                        sunet();
                        cleardevice();
                        meniuListeDubluInlantuite2();
                    }
}

//-----------------MENIU PENTRU STERGEREA IN LISTE DUBLU INLANTUITE--------

void meniuStergereListeDubluInlantuite() //REALIZATA DE ANDREI
{
    jump:

    cleardevice();

    afisareListaDubluInlantuita(prim);

    settextstyle(3, HORIZ_DIR, 4);
    outtextxy(1100, 10, " Alege functia ");
    outtextxy(1100, 50, "  de stergere ");

    // BUTON INAPOI
    readimagefile("inapoi.jpg",1100,410,1350,490);
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
            if(x >= 1100 && x <= 1350 && y >= 100 && y <= 180) //BUTON 1
            {
                gata = true;
                buton1 = true;
            }
            else
                if(x >= 1100 && x <= 1350 && y >= 200 && y <= 280)  //BUTON 2
                {
                    gata = true;
                    buton2 = true;
                }
               else

                        if (x >=1100 && x <= 1350 && y >= 300 && y <= 380) //BUTON 3
                        {
                            gata = true;
                            buton3 = true;
                        }
                        else   if (x >=1100 && x <= 1350 && y >= 410 && y <= 490) //BUTON INAPOI
                                    {
                                        gata = true;
                                        buton4 = true;
                                    }
        }
    } while (!gata);

    if (buton1 == true) // BUTON DE STERGERE A UNUI NUMAR
    {
        mciSendString ("play sunet.mp3", NULL, 0, NULL);
        sunet();

        char afisare[100];

        settextstyle(3, HORIZ_DIR, 3);
        outtextxy(1100,510,"Ce numar doriti");
        outtextxy(1100,540,"  sa stergeti? " );

        citesteSir("numarul: ", afisare, 1110, 570, false);

        int valoare= atoi(afisare);

        nod_lista_dublu_inlantuita *nod_sters = cautareValoareLD(prim,valoare); //CAUTAM VALOAREA INTRODUSA SI RETINEM NODUL CARE TREBUIE STERS

        if(nod_sters != NULL) //STERGEM NUMARUL DOAR DACA EXISTA
        {
            if(nod_sters == prim) //DACA NODUL CARE TREBUIE STERS COINCIDE CU PRIMUL NOD
            {
                if(nod_sters->urmator == NULL && nod_sters->anterior == NULL) // DACA ESTE DOAR UN SINGUR NOD IN LISTA
                    prim = NULL;
                else
                    {
                        nod_lista_dublu_inlantuita* sters = prim;
                        prim = prim->urmator;
                        prim->anterior = NULL;
                        delete sters;
                    }
            }
            else
                stergereElementListaDubluInlantuita(prim,nod_sters);

            numarElemente--; //DECREMENTAM NUMARUL DE ELEMENTE DIN LISTA

            goto jump;  // RESET LA BUTON
        }
        else
            {   //SE AFISEAZA O EROARE SI SE DA RESET LA BUTON
                Beep(1000,100);

                outtextxy(1100,600,"Valoarea introdusa");
                outtextxy(1100,630,"    nu exista");

                delay(5000);
                goto jump;
            }
    }
    else
        if (buton2 == true)
        {
            mciSendString ("play sunet.mp3", NULL, 0, NULL);
            sunet();

            char afisare[100];

            settextstyle(3, HORIZ_DIR, 3);
            outtextxy(1100,510,"Ce nod doriti");
            outtextxy(1100,540," sa stergeti? ");

            citesteSir("nodul: ", afisare, 1110, 570, false);

            int pozitie = atoi(afisare);

            nod_lista_dublu_inlantuita *nod_sters=cautarePozitieLD(prim,pozitie); //CAUTAM POZITIA CITITA SI SALVAM NODUL CORESPUNZATOR

            if(pozitie >= 0 && numarElemente > pozitie) //VERIFICAM DACA EXISTA POZITIA CITITA
            {
                if(pozitie == 0)//DACA NODUL DE STERS ESTE PRIMUL NOD
                {
                    if(nod_sters->urmator == NULL && nod_sters->anterior == NULL) //DACA NODUL DE STERS ESTE SINGURUL DIN LISTA
                        prim=NULL;
                    else
                        {
                            nod_lista_dublu_inlantuita* sters = prim;
                            prim = prim->urmator;
                            prim->anterior = NULL;
                            delete sters;
                        }
                }
                else stergereElementListaDubluInlantuita(prim,nod_sters);

                numarElemente--; //DECREMENTAM NUMARUL DE ELEMENTE DIN LISTA

                goto jump;  // RESET LA BUTON
            }
            else
                {   //SCRIEM O EROARE SI DAM RESET LA BUTON
                    Beep(1000,100);

                    outtextxy(1100,600,"Nodul introdus");
                    outtextxy(1100,630,"  nu exista");

                    delay(5000);
                    goto jump;

                }
        }
        else
            if (buton3 == true)//STERGEM TOATA LISTA
            {
                mciSendString ("play sunet.mp3", NULL, 0, NULL);
                sunet();
                cleardevice();

                prim = NULL;

                goto jump;
            }
            else
                if (buton4 == true)//MERGEM LA MENIUL PRECEDENT
                {
                    mciSendString ("play sunet.mp3", NULL, 0, NULL);
                    sunet();
                    cleardevice();
                    meniuListeDubluInlantuite2();
                }
}

//------------------MENIU PENTRU CAUTAREA IN LISTE DUBLU INLANTUITE-----

void meniuCautareListeDubluInlantuite() //REALIZATA DE ANDREI
{
    //LABEL PENTRU A RESETA BUTONUL
    jump:

    cleardevice();
    afisareListaDubluInlantuita(prim);

    //LABEL PENTRU A RESETA BUTONUL CAND NU MAI E NEVOIE DE AFISARE
    here:

    settextstyle(3, HORIZ_DIR, 4);
    outtextxy(1100, 10, " Alege functia ");
    outtextxy(1100, 50, "  de cautare ");

    // BUTON INAPOI
    readimagefile("inapoi.jpg",1100,310,1350,390);
    // BUTON 1
    readimagefile("Cautarea unui element dat dupa o pozitie.jpg",1100, 100, 1350, 180);
    // BUTON 2
    readimagefile("Cautarea unui element dat dupa o valoare.jpg",1100, 200, 1350, 280);

    // LINII DE DELIMTARE
    line(1090,0,1090,700);
    line(1090,300,1400,300);
    line(1090,400,1400,400);

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

            if(x >= 1100 && x <= 1350 && y >= 100 && y <= 180) //BUTON 1
            {
                gata = true;
                buton1 = true;
            }
            else
                if(x >= 1100 && x <= 1350 && y >= 200 && y <= 280)  //BUTON 2
                {
                    gata = true;
                    buton2 = true;
                }
                else
                    if (x >=1100 && x <= 1350 && y >= 310 && y <= 390) //BUTON INAPOI
                    {
                        gata = true;
                        buton3 = true;
                    }
        }

    } while (!gata);

    if (buton1 == true)
    {
        mciSendString ("play sunet.mp3", NULL, 0, NULL);
        sunet();
        char afisare[100];

        settextstyle(3, HORIZ_DIR, 3);
        outtextxy(1100,410,"Ce pozitie doriti");
        outtextxy(1100,440,"  sa cautati? " );

        citesteSir("pozitia: ", afisare, 1110, 470, false);

        int valoare = atoi(afisare);

        if(valoare >= 0 && valoare < numarElemente) //VERIFICAM DACA POZITIA INTRODUSA EXISTA
           {
               cleardevice();
               nod_lista_dublu_inlantuita *nod_cautat = cautarePozitieLD(prim,valoare);
               afisareListaDubluInlantuitaCautare(prim,nod_cautat);

               goto here;  // RESET LA BUTON SI SARE UNDE NU MAI E NEVOIE DE AFISARE DEOARECE DEJA AM AFISAT
           }
          else
              {
                  Beep(1000,100);

                  outtextxy(1100,500,"Nodul introdus");
                  outtextxy(1100,530,"  nu exista");

                  delay(4000);
                  goto jump;
               }
    }
    else
        if (buton2 == true)
        {
            mciSendString ("play sunet.mp3", NULL, 0, NULL);
            sunet();

            char afisare[100];

            settextstyle(3, HORIZ_DIR, 3);
            outtextxy(1100,410,"Ce valoare doriti");
            outtextxy(1100,440,"    sa cautati?  ");

            citesteSir("valoarea: ", afisare, 1110, 470, false);

            int valoare = atoi(afisare);

            nod_lista_dublu_inlantuita *nod_cautat=cautareValoareLD(prim,valoare);

            if(nod_cautat != NULL) //VERIFICAM DACA EXISTA VALOAREA INTRODUSA
            {
                cleardevice();
                afisareListaDubluInlantuitaCautare(prim,nod_cautat);
                goto here;  // RESET LA BUTON UNDE NU MAI ARE NEVOIE DE AFISARE
            }
              else {    //DAM O EROARE SI DAM RESET LA PAGINA
                        Beep(1000,100);

                        outtextxy(1100,500,"Valoarea introdusa");
                        outtextxy(1100,530,"   nu exista      ");

                        delay(4000);
                        goto jump;
                   }
        }
        else
            if (buton3 == true) //BUTON INAPOI
            {
                mciSendString ("play sunet.mp3", NULL, 0, NULL);sunet();;
                cleardevice();
                meniuListeDubluInlantuite2();
            }
}

// ---------- FUNCTII PENTRU INSERAREA IN LISTE DUBLU INLANTUITE ----------

//INSERAREA LA INCEPUTUL UNEI LISTE DUBLU INLANTUITE
void inserareInceputListaDubluInlantuita(nod_lista_dublu_inlantuita* &prim, int valoare) //REALIZATA DE ANDREI
{
    //CREAM NODUL NOU
    nod_lista_dublu_inlantuita *Element = new nod_lista_dublu_inlantuita;
    Element->element = valoare;
    Element->urmator = prim; //II ATRIBUIM URMATORULUI ELMENT AL ELEMENTULUI CREAT NODUL DE INCEPUT DIN LISTA
    Element->anterior = NULL;
    if(prim != NULL)
        prim->anterior = Element; // II ATRIBUIM ELEMENTULUI ANTERIOR PRIMULUI ELEMENT DIN LISTA ELEMENTUL CREAT

    prim = Element; //INLOCUIM PRIMUL ELEMENT DIN LISTA
}

//INSERAREA LA FINALUL LISTE DUBLU INLANTUITE
void inserareFinalListaDubluInlantuita(nod_lista_dublu_inlantuita* &prim, int valoare) //REALIZATA DE ANDREI
{
    //CREAM NOUL NOD SI II ATRIBUIM VALOAREA PARAMETRULUI valoare DAT LA APELUL FUNCTIEI
    nod_lista_dublu_inlantuita *Element = new nod_lista_dublu_inlantuita;
    Element->element = valoare;
    Element->urmator = NULL;
    Element->anterior = NULL;

    if (prim == NULL) // IN CAZUL IN CARE LISTA ESTE VIDA PUNEM ELEMENTUL IN
        prim = Element;
    else
    {
        //PARCURGEM LISTA PANA LA FINAL
        nod_lista_dublu_inlantuita *nod_curent = prim;
        while (nod_curent->urmator != NULL)
            nod_curent = nod_curent->urmator;

        //POZITIONAL ELEMENTUL CREAT PE ULTIMUL LOC AL LISTEI
        nod_curent->urmator = Element;
        Element->anterior = nod_curent;
    }
}

//INSERARE DUPA UN ELEMENT DAT
void inserareElementListaDubluInlantuita(nod_lista_dublu_inlantuita* &prim, nod_lista_dublu_inlantuita* element_dat, int valoare) //REALIZATA DE ANDREI
{
    //CREAM NOUL NOD SI II ATRIBUIM VALOAREA DATA LA APELUL FUNCTIEI
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
    {
        elem_creat->urmator = NULL;
        elem_creat->anterior = element_dat;
        element_dat->urmator = elem_creat;
        return;
    }

    if (prim == element_dat)
    {
        elem_creat->urmator=prim->urmator;
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

void stergereElementListaDubluInlantuita(nod_lista_dublu_inlantuita* prim,nod_lista_dublu_inlantuita* nod_sters) //REALIZATA DE ANDREI
{
    if(prim == NULL) return;  //DACA LISTA ESTE VIDA
    else
        if(nod_sters->urmator == NULL)  //DACA NODUL DE STERS ESTE LA CAPATUL LISTEI
        {
            nod_sters->anterior->urmator = NULL;
            delete nod_sters;
            return;
        }
        else
            {
                nod_sters->anterior->urmator = nod_sters->urmator;
                nod_sters->urmator->anterior = nod_sters->anterior;
                delete nod_sters;
                return;
            }
}

//------------------FUNCTII PENTRU CAUTAREA IN LISTE DUBLU INLANTUITE---

//CAUTAREA UNUI ELEMENT DUPA O VALOARE DATA INTR-O LISTA DUBLU INLANTUITA
nod_lista_dublu_inlantuita* cautareValoareLD(nod_lista_dublu_inlantuita* prim, int valoare) //REALIZATA DE ANDREI
{
    nod_lista_dublu_inlantuita *p = prim; //FACEM O COPIE A PRIMULUI NOD DIN LISTA

    while (p != NULL && p->element != valoare) //PARCURGEM LISTA PANA CAND GASIM VALOAREA CERUTA
        p = p->urmator;

    return p; //RETURNAM NODUL CARE CONTINE VALOAREA CERUTA

}

//CAUTAREA UNUI ELEMENT DUPA O POZITIE DATA INTR-O LISTA DUBLU INLANTUITA
nod_lista_dublu_inlantuita* cautarePozitieLD(nod_lista_dublu_inlantuita* prim, int pozitie) //REALIZATA DE ANDREI
{
    nod_lista_dublu_inlantuita *p=prim; //FACEM O COPIE A PRIMULUI NOD DIN LISTA
    int i = 0;  //POZITIA DE INCEPUT A PRIMULUI ELEMENT

    while (p != NULL && i < pozitie) //PARCURGEM LISTA PANA LA POZITIA CURENTA, SAU PANA AJUNGEM LA ULTIMUL ELEMENT AL LISTEI
    {
        p = p->urmator;
        i++;
    }

    if (i == pozitie) //IN CAZUL IN CARE AM GASIT POZITIA CURENTA O RETURNAM
        return p;
    else
        return NULL;
}

// ---------- AFISAREA UNEI LISTE DUBLU INLANTUITE PENTRU INSERARE ----------

void afisareListaDubluInlantuitaInserare(nod_lista_dublu_inlantuita* prim) //REALIZATA DE ANDREI
{
    settextstyle(3, HORIZ_DIR, 6);
    setbkcolor(BLUE);
    outtextxy(50, 20, "Lista reprezentata grafic este");
    setbkcolor(BLACK);


    nod_lista_dublu_inlantuita* p = prim;//CREAM O COPIE A PRIMULUI NOD

    unsigned int x = 20, y = 120; //COORDONATELE DE INCEPUT PENTRU AFISAREA IMAGINILOR CORESPUNZATOARE
    unsigned int xtext = 30, ytext = 140; //COORDONATELE DE INCEPUT PENTRU AFISAREA VALORILOR CORESPUNZATOARE

    if(p == NULL)
    {
        outtextxy(100,150,"LISTA ESTE VIDA");
        readimagefile("SAD.jpg",180,200,700,600);
    }

    while (p != NULL)
    {
        if (x <= 660)
        {
            // AFISAREA NODULUI CORESPUNZATOR
            if (p->urmator == NULL && p->anterior == NULL)
                readimagefile("nod singur lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
            else
                {
                    if(p->anterior == NULL)
                    {
                        readimagefile("nod inceput lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                        readimagefile("sageti.jpg", x+150, y, x + 200, y + 60);
                    }
                    else
                        {
                            if(p->urmator == NULL)
                                readimagefile("nod sfarsit lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                            else
                                {
                                    readimagefile("nod mijloc lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                                    readimagefile("sageti.jpg", x+150, y, x + 200, y + 60);
                                }
                        }
                }

            // DIMENSIUNEA TEXTULUI IN FIECARE NOD
            dimensiuneText(p->element);

            // AFISARE IN MODUL GRAFIC
            bgiout << p->element;
            outstreamxy(xtext+50 , ytext);

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

void afisareListaDubluInlantuita(nod_lista_dublu_inlantuita *prim) //REALIZATA DE ANDREI CU AJUTORUL ANEI
{
    settextstyle(3, HORIZ_DIR, 6);
    setbkcolor(BLUE);
    outtextxy(50, 20, "Lista reprezentata grafic este");
    setbkcolor(BLACK);

    nod_lista_dublu_inlantuita* p = prim;

    unsigned int x = 20, y = 120;
    unsigned int xtext = 30, ytext = 140;

    if(p == NULL)
        {
            outtextxy(100,150,"LISTA ESTE VIDA");
            readimagefile("SAD.jpg",180,200,700,600);
        }
    while (p != NULL)
    {
        if (x <= 960)  // DACA NU IESE DIN ECRANUL DESTINAT AFISARII
        {
            // AFISAREA NODULUI CORESPUNZATOR
            if (p->urmator == NULL && p->anterior == NULL)
                readimagefile("nod singur lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
            else
                {
                    if(p->anterior == NULL)
                    {
                        readimagefile("nod inceput lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                        readimagefile("sageti.jpg", x+150, y, x + 200, y + 60);
                    }
                    else
                        {
                            if(p->urmator == NULL)
                                readimagefile("nod sfarsit lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                            else
                                {
                                    readimagefile("nod mijloc lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                                    readimagefile("sageti.jpg", x+150, y, x + 200, y + 60);
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

//--------------------------AFISARE LISTA DUBLU INLANTUITA PENTRU CAUTARE-------

void afisareListaDubluInlantuitaCautare(nod_lista_dublu_inlantuita* prim,nod_lista_dublu_inlantuita* nodd) //REALIZATA DE ANDREI
{
    settextstyle(3, HORIZ_DIR, 6); //SELECTAM FONTUL, DIRECTIA SI MARIMEA TEXTULUI
    setbkcolor(BLUE); //SELECTAM FUNDALUL SCRISULUI
    outtextxy(50, 20, "Lista reprezentata grafic este");
    setbkcolor(BLACK);

    nod_lista_dublu_inlantuita* p = prim; //FACEM O COPIE NODULUI INITIAL DIN LISTA
    nod_lista_dublu_inlantuita* q = nodd; //FACEM O COPIE NODULUI PRIMIT LA CAUTARE

    unsigned int x = 20, y = 120; //VOM FOLOSI ACESTE VARIABILE PENTRU A AFISA IMAGINEA
    unsigned int xtext = 30, ytext = 140; //VOM FOLOSI ACESTE VARIABILE PENTRU A AFISA VALOAREA

    if(p == NULL)
        {
            outtextxy(100,150,"LISTA ESTE VIDA");
            readimagefile("SAD.jpg",180,200,700,600);
        }

    while (p != NULL)
    {
        if (x <= 960)  //DACA NU IESE DIN ECRANUL DESTINAT SCRIERII
        {
            // AFISAREA NODULUI CORESPUNZATOR
            if (p->urmator == NULL && p->anterior == NULL)
            {   //DACA PRIM ARE ACELASI ELEMENT CU ELEMENTUL CAUTAT DE NOI DAT IN ANTETUL FUNCTIEI VOM AFISA O IMAGINE CU O SAGEATA
                if(p->element == q->element)
                    readimagefile("Element cautat singur.jpg", x, y-10, x + 150, y + 60);
                else
                    readimagefile("nod singur lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
            }
            else
                {
                    if(p->anterior == NULL)
                    {   //DACA PRIM ARE ACELASI ELEMENT CU ELEMENTUL CAUTAT DE NOI DAT IN ANTETUL FUNCTIEI VOM AFISA O IMAGINE CU O SAGEATA
                        if(p->element == q->element)
                        {
                            readimagefile("Element cautat primul.jpg", x, y-10, x + 150, y + 60);
                            readimagefile("sageti.jpg", x+150, y, x + 200, y + 60);
                        }
                        else
                            {
                                readimagefile("nod inceput lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                                readimagefile("sageti.jpg", x+150, y, x + 200, y + 60);
                            }
                    }
                    else
                        {
                            if(p->urmator == NULL)
                            {   //DACA PRIM ARE ACELASI ELEMENT CU ELEMENTUL CAUTAT DE NOI DAT IN ANTETUL FUNCTIEI VOM AFISA O IMAGINE CU O SAGEATA
                                if(p->element == q->element)
                                    readimagefile("Element cautat ultimul.jpg", x, y-10, x + 150, y + 60);
                                else
                                    readimagefile("nod sfarsit lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                            }
                            else
                                {   //DACA PRIM ARE ACELASI ELEMENT CU ELEMENTUL CAUTAT DE NOI DAT IN ANTETUL FUNCTIEI VOM AFISA O IMAGINE CU O SAGEATA
                                    if(p->element == q->element)
                                    {
                                        readimagefile("Element cautat interior.jpg", x, y-10, x + 150, y + 60);
                                        readimagefile("sageti.jpg", x+150, y, x + 200, y + 60);
                                    }
                                    else
                                        {
                                            readimagefile("nod mijloc lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                                            readimagefile("sageti.jpg", x+150, y, x + 200, y + 60);
                                        }
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



// ---------- MENIU COADA 1 ----------

void meniuCoada1() //REALIZATA DE ANDREI
{
    descriereCoada();   // APELAM FUNCTIA DE EDESCRIERE A COZII
    meniuCoada2();      // APELAM FUNCTIA UNDE SUNT GASITE
}

// ---------- MENIU COADA 2 ----------

void meniuCoada2() //REALIZATA DE ANDREI
{
    //DECLARAM PRIMUL SI ULTIMUL NOD DIN COADA
    nod_coada* fata_cozii = NULL;
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
                    if (x >= 920 && x <= 1080 && y >=600 && y <=680 ) //BUTON 3 - ELEMENTUL DIN FATA COZII
                    {
                        gata = true;
                        buton3 = true;
                    }
                    else
                        if (x >= 20 && x <= 150 && y >= 630 && y <= 680) //BUTON 4 - INAPOI LA MENIU
                        {
                            gata = true;
                            inapoi = true;
                        }
        }

    } while (!gata);

    if (buton1 == true)  // BUTON 1 - STERGERE ELEMENT COADA
    {
        mciSendString ("play sunet.mp3", NULL, 0, NULL);sunet();
        pop(fata_cozii); // STERGEM PRIMUL ELEMENT DIN COADA
        goto jump;
    }
    else
        if (buton2 == true) //BUTON 2 - ADAUGAREA UNUI ELEMENT
        {
            mciSendString ("play sunet.mp3", NULL, 0, NULL);sunet();

            char afisare[100];
            outtextxy(600,600,"Ce catel doriti");
            outtextxy(600,620," sa adaugati? " );

            //CITESTE IN MOD GRAFIC IN SIRUL afisare ELEMENTELE
            citesteSir(" catel nr. ", afisare, 600, 640 , false);

            int valoare= atoi(afisare);  // FACE CONVERSIA SIRULUI afisare DIN ASCII IN INT

            push(fata_cozii, spatele_cozii, valoare); // ADAUGAM ELEMENTUL CITIT IN COADA

            goto jump; // RESET LA BUTON
        }
        else
            if (buton3 == true)  // BUTON 3 - ELEMENTUL DIN FATA COZII
            {
                mciSendString ("play sunet.mp3", NULL, 0, NULL);sunet();;
                if(element_fata_coada(fata_cozii))
                {
                    mciSendString ("play bark.mp3", NULL, 0, NULL);

                    // IMAGINE CATEL
                    readimagefile("dog.jpg", 1100, 580, 1190,700);

                    // DIMENSIUNEA TEXTULUI IN FIECARE NOD
                    dimensiuneText(element_fata_coada(fata_cozii));

                    // AFISARE IN MODUL GRAFIC A ELEMENTULUI DIN FATA COZII
                    bgiout << element_fata_coada(fata_cozii);
                    outstreamxy(1125,610);

                    goto here; // RESET LA BUTON

                }
                else
                    {
                        outtextxy(1100,600,"Coada este goala");
                        goto here; // RESET LA BUTON
                    }
            }
            else
                if (inapoi == true)  //BUTON 4 - INAPOI LA MENIU
                {
                    mciSendString ("play sunet.mp3", NULL, 0, NULL);sunet();
                    cleardevice();
                    meniuCoada1();
                }
}

// ---------- NOTIUNI TEORETICE DESPRE COADA ----------

void descriereCoada() //REALIZATA DE ANDREI
{
    cleardevice();

    settextstyle(3, HORIZ_DIR, 4); //SELECTAM FONTUL, DIRECTIA SI MARIMEA TEXTULUI
    outtextxy(430,50, "Informatii despre coada"); //TITLUL PAGINIII

    settextstyle(3, HORIZ_DIR, 3); //SELECTAM FONTUL, DIRECTIA SI MARIMEA TEXTULUI CE URMEAZA SA FIE SCRIS
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

    // CITIREA IMAGINII CARE REPREZINTA UN EXEMPLU DE COADA
    readimagefile("exemplu coada.jpg",910,100,1250,480);

    // CITIREA BUTONULUI PENTRU PAGINA ANTERIOARA
    readimagefile("inapoi coada.jpg",910,510,1060,580);

    // CITIREA BUTONULUI PENTRU PAGINA URMATOARE
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
            if(x >= 910 && x <= 1060 && y >=510  && y <= 580) //BUTONUL PENTRU PAGINA ANTERIOARA
            {
                gata = true;
                inapoi = true;
            }
            else
                if (x >= 1110 && x <= 1260 && y >= 510 && y <= 580) //BUTONUL PENTRU PAGINA URMATOARE
                {
                    gata = true;
                    inainte = true;
                }
        }

    } while (!gata);

    if (inainte == true) //BUTONUL PENTRU PAGINA URMATOARE
    {
        mciSendString ("play sunet.mp3", NULL, 0, NULL);sunet();
        cleardevice();
        meniuCoada2(); //SE DESCHIDE MENIUL URMATOR (CEL CU FUNCTIILE PENTRU COADA)
    }
    else
        if(inapoi == true) //BUTONUL PENTRU PAGINA ANTERIOARA
        {
            mciSendString ("play sunet.mp3", NULL, 0, NULL);sunet();
            cleardevice();
            meniuPrincipal(); //SE DESCHIDE MENIUL PRINCIPAL
        }

    cleardevice();
}

// ---------- FUNCTIE PENTRU STABILIREA DACA ESTE SAU NU COADA GOALA ----------

bool isEmpty(nod_coada* fata_cozii)//REALIZATA DE ANDREI
{
    return fata_cozii == NULL;
}

// ---------- INTRODUCEREA UNUI ELEMENT IN COADA ----------

void push(nod_coada* &fata_cozii, nod_coada* &spatele_cozii, int element_coada) //REALIZATA DE ANDREI
{
    nod_coada* nod_nou_coada = creare_nod_nou_in_coada(element_coada); //CREEM UN NOD NOU IN COADA SI II ATRIBUIM ELEMENTUL DAT

    if(spatele_cozii != NULL)
        spatele_cozii -> urmatorul_din_coada = nod_nou_coada;  //PUNEM NODUL NOU IN SPATELE COZII
    spatele_cozii = nod_nou_coada;

    if(fata_cozii == NULL)
        fata_cozii = nod_nou_coada; //DACA COADA ESTE GOALA PUNEM ELEMENTUL NOU CREAT IN FATA COZII CARE ESTE SIMULTAN
}

// ---------- ELIMINAREA UNUI ELEMENT DIN COADA ----------

int pop(nod_coada* &fata_cozii) //REALIZATA DE ANDREI
{
    if(isEmpty(fata_cozii)) //DACA COADA ESTE GOALA RETURNAM 0
        return 0;

    nod_coada* copie_fata_cozii = fata_cozii;  //COPIEM FATA COZII
    fata_cozii = fata_cozii -> urmatorul_din_coada;  //STERGEM ELEMENTUL DIN FATA COZII
    int element_de_scos_din_coada = copie_fata_cozii -> element_coada; //COPIEM ELEMENTUL DIN FATA COZII

    delete copie_fata_cozii; //STERGEM COPIA REALIZATA

    return element_de_scos_din_coada; //RETURNAM ELEMENTUL DIN COADA
}

// ---------- GENERAREA ELEMENTULUI DIN FATA COZII ----------

int element_fata_coada(nod_coada* fata_cozii) //REALIZATA DE ANDREI
{
    if(isEmpty(fata_cozii)) //DACA COADA ESTE GOALA RETURNAM 0
        return 0;

    return fata_cozii -> element_coada; // RETURNAM ELEMENTUL DIN FATA COZII
}

// ---------- COREAREA UNUI NOD NOU IN COADA ----------

nod_coada* creare_nod_nou_in_coada(int element_coada) //REALIZATA DE ANDREI
{
    nod_coada* nod_nou_coada = new nod_coada(); //CREAM UN NOD NOW DE TIP nod_coada
    nod_nou_coada -> element_coada = element_coada; //ATRIBUIM ELEMENTULUI NOULUI NOD CREAT ELEMENTUL DAT
    nod_nou_coada -> urmatorul_din_coada = NULL; //II ASOCIEM URMATORULUI ELEMENT DIN COADA A ELEMENTULUI CREAT VALOARAEA NULL
    return nod_nou_coada; // RETURNAM NODUL CREAT
}

// ---------- AFISAREA COZII ----------

void afisareCoada(nod_coada* fata_cozii) //REALIZATA DE ANDREI
{
    if(isEmpty(fata_cozii))     //VERIFICAM DACA COADA ESTE GOALA
    {
        outtextxy(300,100,"Nu este niciun catel la coada"); //DACA RASPUNSUL ESTE AFIRMATIV AFISAM UN MEASJ
        readimagefile("SAD.jpg",180,200,600,500);           //IMPREUNA CU O IMAGINE
    }
    else
        {
            setbkcolor(BLACK);
            nod_coada* p = fata_cozii;  //COPIEM IN p FATA COZI
            unsigned int x = 200, y = 100;  //VOM FOLOSI ACESTE VARIABILE PENTRU A AFISA IMAGINEA
            unsigned int xtext = 210, ytext = 110;  //VOM FOLOFI ACESTE VARIABILE PENTRU A AFISA PE FIECARE IMAGINE UN NUMA

            while (p != NULL)
            {
                if (x <= 1250)  // DACA NU IESE DIN ECRAN
                {
                    // LATRAT DE CATEL
                    mciSendString ("play bark1.mp3", NULL, 0, NULL);

                    // AFISAREA NODULUI CORESPUNZATOR
                    readimagefile("dog.jpg", x, y, x + 100, y + 150);

                    // DIMENSIUNEA TEXTULUI IN FIECARE NOD
                    dimensiuneText(p->element_coada);

                    // AFISARE IN MODUL GRAFIC A ELEMENTULUI DIN COADA
                    bgiout << p->element_coada;
                    outstreamxy(xtext+25, ytext+40);

                    // COORDONATELE URMATORULUI NOD
                    x += 102;
                    xtext += 102;

                    // TRECEM LA URMATORUL ELEMENT DIN COADA
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
