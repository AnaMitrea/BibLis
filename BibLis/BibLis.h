#pragma once

#include "Libraries.h"

/// ---------- MENIU PRINCIPAL SI ALTE ELEMENTE ( realizat de ambii coechipieri) --------

void BibLis();
void sunet();
void deschidere();
void meniuPrincipal();
void descriereProiect1();
void descriereProiect2();
void descriereProiect3();
void descriereAutori();
void gifDiCaprio();
void dimensiuneTextAna(int element);
void dimensiuneTextAndrei(int element);
void citesteSir(char text[100], char afisare[100], int x, int y, bool stergere);  //PRELUATA DIN MERGE SORT DATA DE DOMNUL PROF. PATRUT BOGDAN

/// ------------- DECLARARE FUNCTII LA LISTE SIMPLU INLANTUITE ( realizat de Ana ) ------------

void meniuListeSimpluInlantuite();
void meniuInserare();
void meniuStergere();
void graficaCitireListeSimplu();
void creareListaSimpluInlantuita(nod*& prim, int n, int Valoarea[20]);
void citireListeSimpluInlantuite();
void descriereListaSimplu();
void listaVida(nod* prim);
void lungimeLista(nod* prim);
void inserareInceput(nod*& prim);
void adaugareSfarsit(nod*& prim, int val);
void inserareSfarsit(nod*& prim);
void inserareDupaNod(nod*& prim);
void stergerePrimul(nod*& prim);
void stergerePrimaAparitie(nod*& prim);
void stergereToateAparitiile(nod*& prim);
void afisareListaSimpluInlantuita(nod *prim);

/// ---------- DECLARARE ANTET PENTRU FUNCTIILE UTILIZARE LA LISTE DUBLU INLANTUITE ( realizat de Andrei ) ----------

void meniuListeDubluInlantuite1();
void meniuListeDubluInlantuite2();
void descriereListaDubluInlantuita();
void citireElementeListaDubluInlantuita(); //SCRISA DE ANDREI CU AJUTORUL PROBLEMEI MERGE SORT DATA DE DOMNUL PROF. PATRUT BOGDAN
void creareListaDubluInlantuita(nod_lista_dublu_inlantuita* &Prim,int n,int Valoarea[20]);

void meniuInserareListeDubluInlantuite();
void meniuStergereListeDubluInlantuite();
void meniuCautareListeDubluInlantuite();

void inserareElementListaDubluInlantuita(nod_lista_dublu_inlantuita* &Prim, nod_lista_dublu_inlantuita* element_dat, int valoare);
void inserareInceputListaDubluInlantuita(nod_lista_dublu_inlantuita* &Prim, int valoare);
void inserareFinalListaDubluInlantuita(nod_lista_dublu_inlantuita* &Prim, int valoare);

void stergereElementListaDubluInlantuita(nod_lista_dublu_inlantuita* Prim,nod_lista_dublu_inlantuita* nod_sters);

nod_lista_dublu_inlantuita* cautareValoareLD(nod_lista_dublu_inlantuita* Prim, int valoare);
nod_lista_dublu_inlantuita* cautarePozitieLD(nod_lista_dublu_inlantuita* Prim, int pozitie);

void afisareListaDubluInlantuitaInserare(nod_lista_dublu_inlantuita* Prim);
void afisareListaDubluInlantuita(nod_lista_dublu_inlantuita* Prim);
void afisareListaDubluInlantuitaCautare(nod_lista_dublu_inlantuita* Prim,nod_lista_dublu_inlantuita* nodd);

/// ------------- DECLARARE FUNCTII LA STIVE ( realizat de Ana ) ------------

void meniuStive();
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

/// ---------- DECLARARE ANTET PENTRU FUNCTIILE UTILIZARE LA COADA ( realizat de Andrei ) ----------

nod_coada* creare_nod_nou_in_coada(int element_coada);
void meniuCoada1();
void meniuCoada2();
void descriereCoada();
int element_fata_coada(nod_coada* fata_cozii);
void push(nod_coada* &fata_cozii, nod_coada* &spatele_cozii, int element_coada);
int pop(nod_coada* &fata_cozii);
bool isEmpty(nod_coada* fata_cozii);
void afisareCoada(nod_coada* fata_cozii);


// ---------- INTERFATA ----------
void BibLis()
{
    initwindow(1530, 795, " BibLis ");
    deschidere();
    getch();
    closegraph();
}

// ---------- SUNET DE FUNDAL ----------

void sunet()
{
    mciSendString ("play sunete/song.mp3", NULL, 0, NULL);
}

// ---------- MENIU DE DESCHIDERE ----------

void deschidere()
{
    cleardevice(); //FUNCTIE DE CURATAREA ECRANULUI

    sunet(); //APELAREA FUNCTIEI PENTRU MUZICA DE FUNDAL

    settextstyle(3, HORIZ_DIR, 5); //SELECTAREA TIPULUI DE SCRIS, DIRECTIEI SI A MARIMII ACESTUIA
    outtextxy(600, 100, " Bine ai venit! "); //SCRIEREA IN FEREASTRA GRAFICA A UNUI MESAJ DE INTAMPINARE

    // BUTON 1 - START
    readimagefile("imagini/start.jpg",600,210,910,280);

    // BUTON 2 -  DESPRE PROIECT
    readimagefile("imagini/despre proiect.jpg",600,310,910, 380);

    // BUTON 3 - DESPRE AUTORI
    readimagefile("imagini/despre autori.jpg",600,410,910, 480);

    // BUTON 4 - IESIRE DIN PROGRAM
    readimagefile("imagini/iesire.jpg",600,510,910, 580);

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
        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL); //SUNET LA APASAREA BUTONULUI
        sunet();
        meniuPrincipal(); //APEL MENIU PRINCIPAL
    }
    else
        if (buton2 == true)
        {
            mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
            sunet();
            descriereProiect1();//APEL DESCRIEREA PROIECTULUI
        }
        else
            if(buton3 == true)
            {
                mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                sunet();
                descriereAutori(); //APEL DESCRIEREA AUTORILOR PROIECTULUI
            }
            else
                if(buton4 == true)
                {
                    mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
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

void meniuPrincipal()
{
    closegraph();
    initwindow(1530, 795, " BibLis ");
    cleardevice();
    // ---------- TITLU MENIU ----------
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(560, 100, " Alege structura de date ");
    // ---------- MENIU PRINCIPAL CU STRUCTURI DE DATE ----------
    // BUTON 1 - Liste simplu inlantuite
    readimagefile("imagini/liste s i.jpg",600,210,910,280);
    // BUTON 2 -  Liste dublu inlantuite
    readimagefile("imagini/liste d i.jpg",600,310,910, 380);
    // BUTON 3 - Stive
    readimagefile("imagini/stive.jpg",600,410,910, 480);
    // BUTON 4 - Cozi
    readimagefile("imagini/cozi.jpg",600,510,910, 580);
    // BUTON 5 - Inapoi la meniul de deschidere
    readimagefile("imagini/inapoi albastru.jpg",600,610,910, 680);

    bool gata = false;
    bool buton1 = false, buton2 = false, buton3 = false, buton4 = false, buton5 = false;
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
        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
        sunet();
        meniuListeSimpluInlantuite();
    }
    else
        if (buton2 == true)
        {
            mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
            closegraph();
            initwindow(1400, 700, " BibLis ");
            sunet();
            meniuListeDubluInlantuite1();//APEL MENIU LISTE DUBLU INLANTUITE 1
        }
        else
            if(buton3 == true)
            {
                mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                sunet();
                meniuStive();
            }
            else
                if(buton4 == true)
                {
                    mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                    closegraph();
                    initwindow(1400, 700, " BibLis ");
                    sunet();
                    meniuCoada1(); //APEL MENIU COADA 1
                }
                else
                    if(buton5 == true)
                        {
                            mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                            sunet();
                            deschidere(); //APEL MENIU DESCHIDERE
                        }
}

// ---------- DESCRIERE PROIECT PAGINA 1 ----------

void descriereProiect1()
{
    cleardevice();

     // BUTON PENTRU PAGINA URMATOARE
    readimagefile("imagini/inainte.jpg",720,650,920,690);

    // BUTON PENTRU PAGINA PRECEDENTA ADICA MENIUL PRINCIPAL
    readimagefile("imagini/pagina de deschidere.jpg",480,650,680,690);

    // INSERAREA UNEI POZE IN FEREASTRA GRAFICA
    readimagefile("imagini/biblia2.jpg",1000,100,1300,400);

    readimagefile("imagini/biblia1.jpg",100,390,500,630);

    // TITLUL FERESTREI
    settextstyle(3, HORIZ_DIR,4);
    outtextxy(500,50,"PROIECTUL BIBLIS");

    //TEXTUL DIN PARTEA DE SUS A PAGINII
    settextstyle(8, HORIZ_DIR,3);
    outtextxy(100,130,"     Cand am auzit Prima data de numele proiectului nostru, ");
    outtextxy(100,160,"BIBLIS, Primul gand ne-a purtat catre Sfanta Biblie. Ne  ");
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
        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL); //SUNET LA APASAREA BUTONULUI
        sunet();
        descriereProiect2(); //APEL DESCRIERE PROIECT 2
    }
    else
        if(inapoi == true)   // BUTON PENTRU PAGINA PRECEDENTA ADICA MENIUL PRINCIPAL
        {
            mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL); //SUNET LA APASAREA BUTONULUI
            sunet();
            deschidere();
        }
    cleardevice();
}

// ---------- DESCRIERE PROIECT PAGINA 2 ----------

void descriereProiect2()
{
    cleardevice();

     // BUTON PENTRU PAGINA URMATOARE
    readimagefile("imagini/inainte.jpg",720,650,920,690);

    // BUTON PENTRU PAGINA PRECEDENTA ADICA MENIUL PRINCIPAL
    readimagefile("imagini/inapoi alb.jpg",480,650,680,690);

    // INSERAREA UNEI IMAGINI
    readimagefile("imagini/Catedrala.jpg",100,100,350,450);

    readimagefile("imagini/atom.jpg",850,350,1300,640);

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
        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
        sunet();
        descriereProiect3();
    }
    else
        if(inapoi == true)   // BUTON PENTRU PAGINA PRECEDENTA
        {
            mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
            sunet();
            descriereProiect1();
        }
    cleardevice();
}

// ---------- DESCRIERE PROIECT PAGINA 3 ----------

void descriereProiect3()
{
    cleardevice();

     // BUTON PENTRU PAGINA DE DESCHIDERE
    readimagefile("imagini/pagina de deschidere.jpg",720,650,920,690);

    // BUTON PENTRU PAGINA PRECEDENTA
    readimagefile("imagini/inapoi alb.jpg",480,650,680,690);

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
    readimagefile("imagini/liste simplu inlantuite exemplu.jpg",100,260,600,400);

    //EXEMPLU LISTE DUBLU INLANTUITE
    outtextxy(1000,220,"Liste dublu inlantuite");
    readimagefile("imagini/Exemplu lista dublu inlantuita.jpg",800,260,1300,400);

    //EXEMPLU STIVE
    outtextxy(300,450,"Stiva");
    readimagefile("imagini/stive ex.jpg",250,500,400,600);

    //EXEMPLU COADA
    outtextxy(1050,450,"Coada");
    readimagefile("imagini/exemplu coada.jpg",1000,500,1150,650);

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
        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
        sunet();
        deschidere();
    }
    else
        if(inapoi == true)   // BUTON PENTRU PAGINA PRECEDENTA
        {
            mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
            sunet();
            descriereProiect2();
        }
    cleardevice();
}

// ---------- DESCRIERE AUTORI ----------

void descriereAutori()
{
     // POZA ANEI
    readimagefile("imagini/Ana Mitrea.jpg",30,100,325,500);

    // POZA LUI ANDREI
    readimagefile("imagini/Andrei Tablan.jpeg",1075,300,1350,600);

    // BUTON INAPOI
    readimagefile("imagini/inapoi alb.jpg",625,640,775,670);

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
    settextstyle(5, HORIZ_DIR, 3);
    outtextxy(340,120,"   A fost o placere deosebita sa fac parte din aceasta echipa si" );
    outtextxy(340,145,"ca am avut ocazia sa lucrez la asemenea proiect interesant. Am");
    outtextxy(340,170,"invatat foarte multe lucruri utile despre aceasta biblioteca");
    outtextxy(340,195,"grafica - Graphics.h si despre cum o pot utiliza in scop");
    outtextxy(340,220," educational si interactiv. Sper ca am facut o treaba buna ");
    outtextxy(340,245,"si ca proiectul va fi folosit in scop educational pentru alti");
    outtextxy(340,270,"studenti dornici de a invata despre aceste structuri de date.");
    outtextxy(340,295,"                                      -Ana   ");

    //TEXT VORBELE LUI ANDREI
    outtextxy(340,450,"   Mi-a placut foarte mult sa lucrez la acest proiect. A fost" );
    outtextxy(340,475,"o provocare interesanta si am imbratisast fiecare impediment cu");
    outtextxy(340,500,"multa pasiune pana cand l-am putut depasi. Proiectul nostru nu");
    outtextxy(340,525,"este perfect, cu siguranta sunt multe lucruri de imbunatatit dar");
    outtextxy(340,550,"am incercat tot ce am putut mai bun din noi! Sper sa va placa");
    outtextxy(340,575,"si asteptam cu mult drag feedback-ul din partea dumneavoastra.");
    outtextxy(340,600,"                                     -Andrei   ");

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
        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
        sunet();
        cleardevice();
        deschidere();
    }
    cleardevice();
}

// ---------- CREARE GIF PENTRU IESIRE ----------

void gifDiCaprio()
{
    //UN GIF SE POATE REALIZA PRIN CITIREA MAI MULTOR IMAGINI LA UN TIMP RELATIV SCURT (IN CAZUL CELUI PREZENTAT 0.1s)
    //GIFUL CREAT ARE 14 IMAGINI SI DISTANTA DINRE CITIREA LOR ESTE DE 0.1 SECUNDE
    //GIFUL SE REPETA DE DOUA ORI

    readimagefile("imagini/frame00.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame01.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame02.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame03.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame04.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame05.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame06.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame07.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame08.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame09.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame10.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame11.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame12.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame13.gif",100,200,1200,650);
    delay(100);

    readimagefile("imagini/frame00.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame01.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame02.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame03.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame04.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame05.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame06.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame07.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame08.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame09.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame10.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame11.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame12.gif",100,200,1200,650);
    delay(100);
    readimagefile("imagini/frame13.gif",100,200,1200,650);
    delay(100);
}

// ---------- STABILIREA MARIMII TEXTULUI IN FUNCTIE DE NUMARUL DE CARACTERE ----------

void dimensiuneTextAndrei(int element)
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

void dimensiuneTextAna(int element)
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

/// --------------- LISTE SIMPLU-INLANTUITE --------------

// ---------- MENIU PENTRU LISTE SIMPLU-INLANTUITE ----------
void meniuListeSimpluInlantuite()
{
    // POZA CU LISTA SI DESCRIEREA EI
    descriereListaSimplu();

    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(400, 50, " Alege functia pentru liste simplu-inlantuite ");

    // BUTON 1 - CREARE LISTA
    readimagefile("imagini/creare lista.jpg",600,100,910,150);

    // BUTON 2 - VERIF LISTA VIDA
    readimagefile("imagini/vida.jpg",600,200,910,250);

    // BUTON 3 - LUNGIME LISTA
    readimagefile("imagini/lungime lista.jpg", 600, 300, 910, 350);

    // BUTON 4 - FUNCTII INSERARE
    readimagefile("imagini/inserare.jpg",600,400,910,450);

    // BUTON 5 - FUNCTII STERGERE
    readimagefile("imagini/stergere.jpg",600,500,910, 550);

    // BUTON 6 - AFISAREA LISTEI
    readimagefile("imagini/afisare.jpg",600, 600,910, 650);

    // BUTON 7 - UNDO
    readimagefile("imagini/undo.jpg",30,730,250,780);

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
        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
        sunet();
        graficaCitireListeSimplu();
    }
    else
        if (buton2 == true)  // Verificare daca lista este vida
        {
            mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
            sunet();
            listaVida(prim);
        }
        else
            if (buton3 == true)  // Functie pt aflarea lungimii listei
            {
                mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                sunet();
                lungimeLista(prim);
            }
            else
                if (buton4 == true)  // Functii la INSERARE element in liste
                {
                    mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                    sunet();
                    meniuInserare();
                }
                else
                    if (buton5 == true)  // Functii la STERGERE element din liste
                    {
                        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                        sunet();
                        meniuStergere();
                    }
                    else
                        if (buton6 == true)   // Afisarea unei liste
                        {
                            mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                            sunet();
                            afisareListaSimpluInlantuita(prim);
                        }
                        else
                            if (undo == true)
                            {
                                mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                                sunet();
                                cleardevice();
                                meniuPrincipal();
                            }
}

void descriereListaSimplu()
{
    cleardevice();
    readimagefile("imagini/undo.jpg",30,730,250,780);
    readimagefile("imagini/next.jpg",640,710,850,790);
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

    readimagefile("imagini/Poza Lista.jpg",550,450,950,650);

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
        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
        sunet();
        cleardevice();
        return;
    }
    else
        if (butonUndo == true)
        {
            mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
            sunet();
            cleardevice();
            meniuPrincipal();
        }
    delay(40000);   // 1 sec =  1000 ms
    cleardevice();
}

void meniuInserare()
{
    readimagefile("imagini/undo.jpg",30,730,250,780);
    settextstyle(4, HORIZ_DIR, 4);
    outtextxy(10, 10, " Alege functia ");
    outtextxy(30, 50, " de inserare ");
    // BUTON 1
    readimagefile("imagini/inserare inceput.jpg",10, 100, 300, 180);
    // BUTON 2
    readimagefile("imagini/inserare sfarsit.jpg",10, 200, 300, 280);
    // BUTON 3
    readimagefile("imagini/inserare dupa nod.jpg",10, 300, 300, 380);
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
        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
        sunet();
        inserareInceput(prim);
        goto jump;  // RESET LA BUTON
    }
    else
        if (buton2 == true)
        {
            mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
            sunet();
            inserareSfarsit(prim);
            goto jump;  // RESET LA BUTON
        }
        else
            if (buton3 == true)
            {
                mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                sunet();
                inserareDupaNod(prim);
                goto jump;  // RESET LA BUTON
            }
            else
                if (buton4 == true)
                {
                    mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                    sunet();
                    meniuListeSimpluInlantuite();
                }
}

// ---------- MENIU FUNCTII STERGERE LA LISTE SIMPLU-INLANTUITE ----------
void meniuStergere()
{
    settextstyle(4, HORIZ_DIR, 4);
    outtextxy(10, 10, " Alege functia ");
    outtextxy(30, 50, " de stergere ");
    // BUTON 1
    readimagefile("imagini/stergere primul.jpg",10, 100, 300, 180);
    // BUTON 2
    readimagefile("imagini/stergere aparitie.jpg",10, 200, 300, 280);
    // BUTON 3
    readimagefile("imagini/stergere toate aparitiile.jpg",10, 300, 300, 380);
    // BUTON 4 - UNDO
    readimagefile("imagini/undo.jpg",30,730,250,780);
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
        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
        sunet();
        stergerePrimul(prim);
        goto jump;  // RESET LA BUTON
    }
    else
        if (buton2 == true)
        {
            mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
            sunet();
            stergerePrimaAparitie(prim);
            goto jump;  // RESET LA BUTON
        }
        else
            if (buton3 == true)
            {
                mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                sunet();
                stergereToateAparitiile(prim);
                goto jump;  // RESET LA BUTON
            }
            else
                if (buton4 == true)
                {
                    mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                    sunet();
                    meniuListeSimpluInlantuite();
                }
}

//------------- FUNCTIE CREARE LISTA --------------
void creareListaSimpluInlantuita(nod*& prim,int n,int Valoarea[20])
{
    for(int i = 0; i < n; i++)
        adaugareSfarsit(prim,Valoarea[i]);
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

void listaVida(nod* prim)
{
    settextstyle(4, HORIZ_DIR, 4);
    outtextxy(450, 100, " Verificare daca lista este vida");
    readimagefile("imagini/undo.jpg",30,730,250,780);

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
        delay(300);
        readimagefile("imagini/nod lista cu null.jpg",390, 330, 660, 400);

        dimensiuneTextAna(prim->valoare);
        bgiout << prim->valoare;
        outstreamxy(400,350);

        delay(300);
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
        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
        sunet();
        cleardevice();
        meniuListeSimpluInlantuite();
    }
}

void lungimeLista(nod *prim)
{
    readimagefile("imagini/undo.jpg",30,730,250,780);
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
                        readimagefile("imagini/nod lista cu null.jpg", x, y, x + 270, y + 50);
                    else
                        readimagefile("imagini/nod lista.jpg", x, y, x + 200, y + 50);
                    // DIMENSIUNEA TEXTULUI IN FIECARE NOD
                    dimensiuneTextAna(p->valoare);
                    // AFISARE IN MODUL GRAFIC
                    bgiout << p->valoare;
                    outstreamxy(xtext, ytext);
                    bgiout << lungime;
                    outstreamxy(xtext + 50, ytext - 40);
                    // COORDONATELE URMATORULUI NOD
                    x += 200;
                    xtext += 200;
                    p = p->urm;
                    delay(300);
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
        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
        sunet();
        cleardevice();
        meniuListeSimpluInlantuite();
    }
}

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
    delay(300);
    bgiout << "p->info = val. dorita";
    outstreamxy(5,430);
    delay(300);
    bgiout << "p->urm = prim;";
    outstreamxy(5,450);
    delay(500);
    setcolor(WHITE);

    // COORDONATELE PRIMULUI NOD
    unsigned int x = 320, y = 100;
    unsigned int xtext = 325, ytext = 115;
    // CAZ PARTICULAR CAND LISTA ESTE VIDA
    if (prim == NULL)
        readimagefile("imagini/nod inserat lista cu null.jpg", x, y - 10, x + 270, y + 50);
    else
        readimagefile("imagini/nod inserat lista.jpg", x, y - 10, x + 200, y + 50);
    prim = p;
    p = prim;
    setcolor(LIGHTMAGENTA);
    bgiout << "*prim";
    outstreamxy(360,60);
    setcolor(WHITE);

    // DIMENSIUNEA TEXTULUI IN FIECARE NOD
    dimensiuneTextAna(p->valoare);
    // AFISARE IN MODUL GRAFIC
    bgiout << p->valoare;
    outstreamxy(xtext, ytext);
    // AFISAREA INSTRUCTIUNILOR
    setcolor(LIGHTMAGENTA);
    settextstyle(4, HORIZ_DIR, 1);
    delay(300);
    bgiout << "prim = p;";
    outstreamxy(5,470);
    delay(300);
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
                        readimagefile("imagini/nod lista cu null.jpg", x, y, x + 200, y + 50);
                    else
                        readimagefile("imagini/nod lista.jpg", x, y, x + 200, y + 50);

                    // DIMENSIUNEA TEXTULUI IN FIECARE NOD
                    dimensiuneTextAna(p->valoare);

                    // AFISARE IN MODUL GRAFIC
                    bgiout << p->valoare;
                    outstreamxy(xtext, ytext);

                    // COORDONATELE URMATORULUI NOD
                    x += 200;
                    xtext += 200;

                    p = p->urm;
                    delay(300);
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
    delay(4000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(311,0,1520,795);
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,403,308,589);
    bar(0,592,308,729);
}

void adaugareSfarsit(nod*& prim, int val)  // functie in memorie
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
    delay(300);
    bgiout << "p->info = val. dorita;";
    outstreamxy(5,430);
    delay(300);
    bgiout << "p->urm = NULL;";
    outstreamxy(5,450);
    delay(400);
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
    delay(300);

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
                    readimagefile("imagini/nod inserat lista cu null.jpg", x, y - 15, x + 200, y + 50);
                else
                    readimagefile("imagini/nod lista.jpg", x, y, x + 200, y + 50);

                // DIMENSIUNEA TEXTULUI IN FIECARE NOD
                dimensiuneTextAna(p->valoare);

                // AFISARE IN MODUL GRAFIC
                bgiout << p->valoare;
                outstreamxy(xtext, ytext);

                // COORDONATELE URMATORULUI NOD
                x += 200;
                xtext += 200;

                p = p->urm;
                delay(300);
            }
        // STERGERE CE AM SCRIS INAINTE
        setfillstyle(SOLID_FILL,BLACK);
        bar(5,490,250,510);
        delay(300);
        // RESCRIERE
        setcolor(LIGHTMAGENTA);
        settextstyle(4, HORIZ_DIR, 1);
        bgiout << "p = p->urm;";
        outstreamxy(5,490);
        setcolor(WHITE);
    }
    delay(4000);
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
    delay(300);
    bgiout << "p->info = val. dorita;";
    outstreamxy(5,430);
    delay(300);
    bgiout << "p->urm = NULL;";
    outstreamxy(5,450);
    delay(300);

    // COORDONATELE PRIMULUI NOD
    unsigned int x = 320, y = 100;
    unsigned int xtext = 325, ytext = 115;
    bool inserat = false;
    nod *q = prim, *nodInserat, *nodInseratUrm;

    bgiout << "nod *q = prim;";
    outstreamxy(5,470);
    setcolor(WHITE);
    delay(300);

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
        readimagefile("imagini/nod inserat lista cu null.jpg", x, y + 50, x + 300, y + 110);
        settextstyle(4, HORIZ_DIR, 4);

        // AFISARE VAL NOD
        dimensiuneTextAna(p->valoare);
        bgiout << p->valoare;
        outstreamxy(xtext, ytext + 60);

        // STERGERE ECRAN
        delay(4000);
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
            nodInserat = p;
            nodInseratUrm = p->urm;
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
                        readimagefile("imagini/nod lista cu null.jpg", x, y, x + 250, y + 50);
                    else
                        readimagefile("imagini/nod lista.jpg", x, y, x + 200, y + 50);
                    if (nodInserat->valoare == val && nodInseratUrm == q->urm)
                        readimagefile("imagini/nod inserat lista.jpg", x, y - 10, x + 200, y + 50);
                    // DIMENSIUNEA TEXTULUI IN FIECARE NOD
                    dimensiuneTextAna(q->valoare);

                    // AFISARE IN MODUL GRAFIC
                    bgiout << q->valoare;
                    outstreamxy(xtext, ytext);

                    // COORDONATELE URMATORULUI NOD
                    x += 200;
                    xtext += 200;

                    q = q->urm;
                    delay(300);
                }
    }
    if (inserat == false)
    {
        settextstyle(4, HORIZ_DIR, 3);
        setcolor(LIGHTRED);
        outtextxy(545, 55, " Nu s-a inserat nodul in lista simplu-inlantuita!");
        setcolor(WHITE);
    }
    delay(4000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(311,0,1520,795);
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,403,308,589);
    bar(0,592,308,729);
}

void stergerePrimul(nod *&prim)
{
        // ----------- AFISARE ------------
    settextstyle(4, HORIZ_DIR, 3);
    setcolor(LIGHTCYAN);
    outtextxy(530, 20, " Stergerea primului nod din lista simplu-inlantuita");
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
        delay(2000);
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
                        readimagefile("imagini/nod lista cu null.jpg", x, y, x + 200, y + 50);
                    else
                        readimagefile("imagini/nod lista.jpg", x, y, x + 200, y + 50);
                    // DIMENSIUNEA TEXTULUI IN FIECARE NOD
                    dimensiuneTextAna(p->valoare);
                    // AFISARE IN MODUL GRAFIC
                    bgiout << p->valoare;
                    outstreamxy(xtext, ytext);
                    // COORDONATELE URMATORULUI NOD
                    x += 200;
                    xtext += 200;
                    p = p->urm;
                    delay(300);
                }
        // STERGERE CE AM SCRIS INAINTE
        setfillstyle(SOLID_FILL,BLACK);
        bar(5,430,250,450);
        delay(300);
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
    delay(300);
    setcolor(LIGHTMAGENTA);
    settextstyle(4, HORIZ_DIR, 1);
    bgiout << "p = prim->urm;";
    outstreamxy(5,450);
    bgiout << "*p";
    outstreamxy(530,60);
    delay(300);
    bgiout << "delete prim;";
    outstreamxy(5,470);
    readimagefile("imagini/black.jpg",320, 59, 518, 150);
    delay(300);
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
        delay(2000);
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
    delay(500);
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
                delay(300);
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
                        readimagefile("imagini/nod lista cu null.jpg", x, y, x + 200, y + 50);
                    else
                        readimagefile("imagini/nod lista.jpg", x, y, x + 200, y + 50);
                    // DIMENSIUNEA TEXTULUI IN FIECARE NOD
                    dimensiuneTextAna(p->valoare);
                    // AFISARE IN MODUL GRAFIC
                    bgiout << p->valoare;
                    outstreamxy(xtext, ytext);
                    // COORDONATELE URMATORULUI NOD
                    x += 200;
                    xtext += 200;
                    p = p->urm;
                    delay(300);
                }
        // STERGERE CE AM SCRIS INAINTE
        setfillstyle(SOLID_FILL,BLACK);
        bar(5,430,250,450);
        delay(300);
        // RESCRIERE
        setcolor(LIGHTMAGENTA);
        settextstyle(4, HORIZ_DIR, 1);
        bgiout << "p = p->urm;";
        outstreamxy(5,430);
        setcolor(WHITE);
    }
        // STERGERE PARTE DE ECRAN
    delay(4000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(311,0,1520,795);
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,403,308,589);
    bar(0,592,308,729);
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
                        readimagefile("imagini/nod lista cu null.jpg", x, y, x + 200, y + 50);
                    else
                        readimagefile("imagini/nod lista.jpg", x, y, x + 200, y + 50);
                    // DIMENSIUNEA TEXTULUI IN FIECARE NOD
                    dimensiuneTextAna(p->valoare);
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
    delay(4000);
    setfillstyle(SOLID_FILL,BLACK);
    bar(311,0,1520,795);
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,403,308,589);
    bar(0,592,308,729);
}

void afisareListaSimpluInlantuita(nod *prim)
{
    readimagefile("imagini/undo.jpg",30,730,250,780);
    settextstyle(4, HORIZ_DIR, 4);
    outtextxy(370, 100, " Afisarea unei liste simplu-inlantuite");

    nod* p = prim;
    unsigned int x = 20, y = 250;
    unsigned int xtext = 25, ytext = 265;

    while (p != NULL)
    {
        if (x <= 1400)  // daca nu iese din ecran
        {
            // AFISAREA NODULUI CORESPUNZATOR
            if (p->urm == NULL)
                readimagefile("imagini/nod lista cu null.jpg", x, y, x + 270, y + 50);
            else
                readimagefile("imagini/nod lista.jpg", x, y, x + 200, y + 50);

            // DIMENSIUNEA TEXTULUI IN FIECARE NOD
            dimensiuneTextAna(p->valoare);

            // AFISARE IN MODUL GRAFIC
            bgiout << p->valoare;
            outstreamxy(xtext, ytext);

            // COORDONATELE URMATORULUI NOD
            x += 200;
            xtext += 200;

            p = p->urm;
            delay(300);
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
        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
        sunet();
        meniuListeSimpluInlantuite();
        goto jump;
    }
    delay(2500);
    cleardevice();
}

/// -------------------- LISTE DUBLU-INLANTUITE ------------------

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
    settextstyle(3, HORIZ_DIR, 5);
    outtextxy(200, 50, " Alege functia pentru listele dublu inlantuite ");

    // BUTON 1 - INSERAREA UNUI ELEMENT
    readimagefile("imagini/Inserare element dat.jpg",375,200,675,300);

    // BUTON 2 - STERGEREA UNUI ELEMENT
    readimagefile("imagini/Stergere element.jpg",725,200,1025,300);

    // BUTON 3 - CAUTAREA UNUI ELEMENT
    readimagefile("imagini/Cautarea unui element dat.jpg", 725, 350, 1025, 450);

    // BUTON 4 - CITIREA UNEI LISTE NOI
    readimagefile("imagini/citire lista noua ld.jpg", 375, 350, 675, 450);

    // BUTON 5 - MENIU PRINCIPAL
    readimagefile("imagini/meniu principal ld.jpg", 375, 500, 675, 600);

    // BUTON 6 - INAPOI LA FEREASTRA DE DESCRIERE A LISTELOR DUBLU INLANTUITE
    readimagefile("imagini/inapoi.jpg",725,500,1025,600);

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
        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
        sunet();
        cleardevice();
        meniuInserareListeDubluInlantuite();
    }
    else
        if (buton2 == true)  //STERGEREA UNUI ELEMENT
        {
            mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
            sunet();
            cleardevice();
            meniuStergereListeDubluInlantuite();
        }
        else
            if (buton3 == true)  //CAUTAREA UNUI ELEMENT
            {
                mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                sunet();
                cleardevice();
                meniuCautareListeDubluInlantuite();
            }
            else
                if (buton4 == true) //CITIREA UNEI LISTE NOI
                {
                    mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                    sunet();
                    cleardevice();
                    citireElementeListaDubluInlantuita();
                }
                else
                    if (buton5 == true) //MENIU PRINCIPAL
                    {
                        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                        sunet();
                        cleardevice();
                        meniuPrincipal();
                    }
                    else
                        if (buton6 == true) //INAPOI LA FEREASTRA DE DESCRIERE A LISTELOR DUBLU INLANTUITE
                        {
                            mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                            sunet();
                            cleardevice();
                            descriereListaDubluInlantuita();
                        }

}

// ---------- DESCRIERE LISTA DUBLU INLANTUITA ----------

void descriereListaDubluInlantuita()
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
    readimagefile("imagini/Exemplu lista dublu inlantuita.jpg",150,300,1250,650);

     // BUTON PENTRU PAGINA URMATOARE
    readimagefile("imagini/pagina urmatoare.jpg",720,650,920,690);

    // BUTON PENTRU PAGINA PRECEDENTA
    readimagefile("imagini/inapoi.jpg",480,650,680,690);

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
        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
        sunet();
        cleardevice();
        citireElementeListaDubluInlantuita();
    }
    else
        if(inapoi == true)   // BUTON PENTRU PAGINA PRECEDENTA
        {
            mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
            sunet();
            cleardevice();
            meniuPrincipal();
        }

    delay(15000);   // 1 sec =  1000 ms
    cleardevice();
}

// ---------- FUNCTIA DE CITIRE ----------

void citireElementeListaDubluInlantuita()
{
    Prim = NULL;
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
        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
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

            creareListaDubluInlantuita(Prim,n,Valoarea);
            cleardevice();
            meniuListeDubluInlantuite2();
          }
}

// ---------- CREARE LISTA DUBLU INLANTUITA ----------

void creareListaDubluInlantuita (nod_lista_dublu_inlantuita*& Prim , int n , int Valoarea[20])
{
    for(int i=0;i<n;i++)
        inserareFinalListaDubluInlantuita( Prim , Valoarea[i] );
}

//------------------MENIU INSERARE LD------------------

void meniuInserareListeDubluInlantuite()
{
    //LABEL PENTRU RESETAREA BUTONULUI
    jump:

    cleardevice();

    afisareListaDubluInlantuitaInserare(Prim); //APEL FUNCTIE DE AFISARE A LISTEI PENTRU MENIUL DE INSERARE

    //TITLU PENTRU MENIUL DE INSERARE
    settextstyle(3, HORIZ_DIR, 4);
    outtextxy(937, 10, " Alege functia ");
    outtextxy(937, 50, "  de inserare ");

    // BUTON 1
    readimagefile("imagini/Inserare element dat la inceputul listei.jpg",860, 100, 1085, 180);
    // BUTON 2
    readimagefile("imagini/Inserare element dat la finalul listei.jpg",1125, 100, 1350, 180);
    // BUTON 3
    readimagefile("imagini/Inserarea unui element dat dupa o pozitie data.jpg",860, 200, 1085, 280);
    // BUTON 4
    readimagefile("imagini/Inserarea unui element dat dupa un element existent.jpg",1125, 200, 1350, 280);
    // BUTON 5
    readimagefile("imagini/inapoi.jpg",947,310,1238,390);

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
        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
        sunet();

        char afisare[100]; //DECLARAREA SIRULUI CARE VA FI CITIT

        //SCRIERE INTREBARE IN COLTUL DIN DREAPTA JOS
        settextstyle(3, HORIZ_DIR, 3);
        outtextxy(937,410,"Ce numar doriti");
        outtextxy(937,450,"  sa inserati? " );

        //APELUL FUNCTIEI DE CITIRE PENTRU TEXTUL SCRIS DUPA "numarul:"
        citesteSir("numarul: ", afisare, 947, 480, false);

        int valoare = atoi(afisare);//CONVERSIA DIN ASCII A SIRULUI AFISARE IN INT

        inserareInceputListaDubluInlantuita(Prim, valoare);

        //CONTORIZAM NUMARUL DE ELEMENTE CITITE DACA S-A FACUT INSERAREA
        numarElemente++;
        goto jump;  // RESET LA BUTON
    }
    else
        if (buton2 == true)
        {
            mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
            sunet();

            char afisare[100];//DECLARAREA SIRULUI CARE VA FI CITIT

            //SCRIERE INTREBARE IN COLTUL DIN DREAPTA JOS
            settextstyle(3, HORIZ_DIR, 3);
            outtextxy(937,410,"Ce numar doriti");
            outtextxy(937,430,"  sa inserati? " );

            //APELUL FUNCTIEI DE CITIRE PENTRU TEXTUL SCRIS DUPA "numarul:"
            citesteSir("numarul: ", afisare, 937, 450, false);

            int valoare = atoi(afisare);//CONVERSIA DIN ASCII A SIRULUI AFISARE IN INT

            inserareFinalListaDubluInlantuita(Prim, valoare);

            //CONTORIZAM NUMARUL DE ELEMENTE CITITE DACA S-A FACUT INSERAREA
            numarElemente++;

            goto jump;  // RESET LA BUTON
        }
        else
            if (buton3 == true)
            {
                mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                sunet();

                char afisare[100],afisare1[100];//DECLARAREA SIRURILOR CARE VOR FI CITITE

                //SCRIERE INTREBARE IN COLTUL DIN DREAPTA JOS
                settextstyle(3, HORIZ_DIR, 3);
                outtextxy(937,410,"Ce numar doriti sa inserati");
                outtextxy(937,450,"    si dupa ce pozitie?    " );

               //APELUL FUNCTIEI DE CITIRE PENTRU TEXTUL SCRIS DUPA "numarul:"
                citesteSir("numarul: ", afisare, 947, 480, false);
                //APELUL FUNCTIEI DE CITIRE PENTRU TEXTUL SCRIS DUPA "pozitia:"
                citesteSir("pozitia: ", afisare1, 947, 510, false);

                int valoare = atoi(afisare);//CONVERSIA DIN ASCII A SIRULUI afisare IN INT
                int pozitia = atoi(afisare1);//CONVERSIA DIN ASCII A SIRULUI afisare1 IN INT

                nod_lista_dublu_inlantuita *nod_cautat = cautarePozitieLD(Prim,pozitia); //CAUTAM NODUL CU POZITIA CITITA

                if(pozitia < numarElemente && pozitia >= 0) //VERIFICAM DACA EXISTA POZITITA ICITITA
                {
                    inserareElementListaDubluInlantuita(Prim,nod_cautat,valoare);

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
                    mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                    sunet();
                    char afisare[100],afisare1[100];

                    //SCRIERE INTREBARE IN COLTUL DIN DREAPTA JOS
                    settextstyle(3, HORIZ_DIR, 3);
                    outtextxy(937,410,"Ce numar doriti sa inserati");
                    outtextxy(937,450,"    si dupa ce element?    " );

                    citesteSir("numarul: ", afisare, 947, 480, false);
                    citesteSir("elementul: ", afisare1, 947, 510, false);

                    int valoare= atoi(afisare);
                    int elementul= atoi(afisare1);

                    nod_lista_dublu_inlantuita *nod_cautat=cautareValoareLD(Prim,elementul);//CAUTAM NODUL CU POZITIA CITITA

                    if(nod_cautat!=NULL) //VERIFICAM DACA EXISTA ELEMENTUL CITIT
                    {
                        inserareElementListaDubluInlantuita(Prim,nod_cautat,valoare);

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
                        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                        sunet();
                        cleardevice();
                        meniuListeDubluInlantuite2();
                    }
}

//-----------------MENIU PENTRU STERGEREA IN LISTE DUBLU INLANTUITE--------

void meniuStergereListeDubluInlantuite()
{
    jump:

    cleardevice();

    afisareListaDubluInlantuita(Prim);

    settextstyle(3, HORIZ_DIR, 4);
    outtextxy(1100, 10, " Alege functia ");
    outtextxy(1100, 50, "  de stergere ");

    // BUTON INAPOI
    readimagefile("imagini/inapoi.jpg",1100,410,1350,490);
    // BUTON 1
    readimagefile("imagini/Stergerea Primei aparitii a unei valori date.jpg",1100, 100, 1350, 180);
    // BUTON 2
    readimagefile("imagini/Stergerea unui element dupa o pozitie data.jpg",1100, 200, 1350, 280);
    // BUTON 3
    readimagefile("imagini/Stergere lista.jpg",1100,300,1350,380);

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
        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
        sunet();

        char afisare[100];

        settextstyle(3, HORIZ_DIR, 3);
        outtextxy(1100,510,"Ce numar doriti");
        outtextxy(1100,540,"  sa stergeti? " );

        citesteSir("numarul: ", afisare, 1110, 570, false);

        int valoare= atoi(afisare);

        nod_lista_dublu_inlantuita *nod_sters = cautareValoareLD(Prim,valoare); //CAUTAM VALOAREA INTRODUSA SI RETINEM NODUL CARE TREBUIE STERS

        if(nod_sters != NULL) //STERGEM NUMARUL DOAR DACA EXISTA
        {
            if(nod_sters == Prim) //DACA NODUL CARE TREBUIE STERS COINCIDE CU PrimUL NOD
            {
                if(nod_sters->urmator == NULL && nod_sters->anterior == NULL) // DACA ESTE DOAR UN SINGUR NOD IN LISTA
                    Prim = NULL;
                else
                    {
                        nod_lista_dublu_inlantuita* sters = Prim;
                        Prim = Prim->urmator;
                        Prim->anterior = NULL;
                        delete sters;
                    }
            }
            else
                stergereElementListaDubluInlantuita(Prim,nod_sters);

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
            mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
            sunet();

            char afisare[100];

            settextstyle(3, HORIZ_DIR, 3);
            outtextxy(1100,510,"Ce nod doriti");
            outtextxy(1100,540," sa stergeti? ");

            citesteSir("nodul: ", afisare, 1110, 570, false);

            int pozitie = atoi(afisare);

            nod_lista_dublu_inlantuita *nod_sters=cautarePozitieLD(Prim,pozitie); //CAUTAM POZITIA CITITA SI SALVAM NODUL CORESPUNZATOR

            if(pozitie >= 0 && numarElemente > pozitie) //VERIFICAM DACA EXISTA POZITIA CITITA
            {
                if(pozitie == 0)//DACA NODUL DE STERS ESTE PrimUL NOD
                {
                    if(nod_sters->urmator == NULL && nod_sters->anterior == NULL) //DACA NODUL DE STERS ESTE SINGURUL DIN LISTA
                        Prim=NULL;
                    else
                        {
                            nod_lista_dublu_inlantuita* sters = Prim;
                            Prim = Prim->urmator;
                            Prim->anterior = NULL;
                            delete sters;
                        }
                }
                else stergereElementListaDubluInlantuita(Prim,nod_sters);

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
                mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                sunet();
                cleardevice();

                Prim = NULL;

                goto jump;
            }
            else
                if (buton4 == true)//MERGEM LA MENIUL PRECEDENT
                {
                    mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                    sunet();
                    cleardevice();
                    meniuListeDubluInlantuite2();
                }
}

//------------------MENIU PENTRU CAUTAREA IN LISTE DUBLU INLANTUITE-----

void meniuCautareListeDubluInlantuite()
{
    //LABEL PENTRU A RESETA BUTONUL
    jump:

    cleardevice();
    afisareListaDubluInlantuita(Prim);

    //LABEL PENTRU A RESETA BUTONUL CAND NU MAI E NEVOIE DE AFISARE
    here:

    settextstyle(3, HORIZ_DIR, 4);
    outtextxy(1100, 10, " Alege functia ");
    outtextxy(1100, 50, "  de cautare ");

    // BUTON INAPOI
    readimagefile("imagini/inapoi.jpg",1100,310,1350,390);
    // BUTON 1
    readimagefile("imagini/Cautarea unui element dat dupa o pozitie.jpg",1100, 100, 1350, 180);
    // BUTON 2
    readimagefile("imagini/Cautarea unui element dat dupa o valoare.jpg",1100, 200, 1350, 280);

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
        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
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
               nod_lista_dublu_inlantuita *nod_cautat = cautarePozitieLD(Prim,valoare);
               afisareListaDubluInlantuitaCautare(Prim,nod_cautat);

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
            mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
            sunet();

            char afisare[100];

            settextstyle(3, HORIZ_DIR, 3);
            outtextxy(1100,410,"Ce valoare doriti");
            outtextxy(1100,440,"    sa cautati?  ");

            citesteSir("valoarea: ", afisare, 1110, 470, false);

            int valoare = atoi(afisare);

            nod_lista_dublu_inlantuita *nod_cautat=cautareValoareLD(Prim,valoare);

            if(nod_cautat != NULL) //VERIFICAM DACA EXISTA VALOAREA INTRODUSA
            {
                cleardevice();
                afisareListaDubluInlantuitaCautare(Prim,nod_cautat);
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
                mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);sunet();;
                cleardevice();
                meniuListeDubluInlantuite2();
            }
}

// ---------- FUNCTII PENTRU INSERAREA IN LISTE DUBLU INLANTUITE ----------

//INSERAREA LA INCEPUTUL UNEI LISTE DUBLU INLANTUITE
void inserareInceputListaDubluInlantuita(nod_lista_dublu_inlantuita* &Prim, int valoare)
{
    //CREAM NODUL NOU
    nod_lista_dublu_inlantuita *Element = new nod_lista_dublu_inlantuita;
    Element->element = valoare;
    Element->urmator = Prim; //II ATRIBUIM URMATORULUI ELMENT AL ELEMENTULUI CREAT NODUL DE INCEPUT DIN LISTA
    Element->anterior = NULL;
    if(Prim != NULL)
        Prim->anterior = Element; // II ATRIBUIM ELEMENTULUI ANTERIOR PrimULUI ELEMENT DIN LISTA ELEMENTUL CREAT

    Prim = Element; //INLOCUIM PrimUL ELEMENT DIN LISTA
}

//INSERAREA LA FINALUL LISTE DUBLU INLANTUITE
void inserareFinalListaDubluInlantuita(nod_lista_dublu_inlantuita* &Prim, int valoare)
{
    //CREAM NOUL NOD SI II ATRIBUIM VALOAREA PARAMETRULUI valoare DAT LA APELUL FUNCTIEI
    nod_lista_dublu_inlantuita *Element = new nod_lista_dublu_inlantuita;
    Element->element = valoare;
    Element->urmator = NULL;
    Element->anterior = NULL;

    if (Prim == NULL) // IN CAZUL IN CARE LISTA ESTE VIDA PUNEM ELEMENTUL IN
        Prim = Element;
    else
    {
        //PARCURGEM LISTA PANA LA FINAL
        nod_lista_dublu_inlantuita *nod_curent = Prim;
        while (nod_curent->urmator != NULL)
            nod_curent = nod_curent->urmator;

        //POZITIONAL ELEMENTUL CREAT PE ULTIMUL LOC AL LISTEI
        nod_curent->urmator = Element;
        Element->anterior = nod_curent;
    }
}

//INSERARE DUPA UN ELEMENT DAT
void inserareElementListaDubluInlantuita(nod_lista_dublu_inlantuita* &Prim, nod_lista_dublu_inlantuita* element_dat, int valoare)
{
    //CREAM NOUL NOD SI II ATRIBUIM VALOAREA DATA LA APELUL FUNCTIEI
    nod_lista_dublu_inlantuita *elem_creat = new nod_lista_dublu_inlantuita;
    elem_creat->element = valoare;
    elem_creat->urmator = NULL;
    elem_creat->anterior = NULL;

    if (Prim == NULL)
    {
        Prim = elem_creat;
        return;
    }

    if (element_dat->urmator == NULL)
    {
        elem_creat->urmator = NULL;
        elem_creat->anterior = element_dat;
        element_dat->urmator = elem_creat;
        return;
    }

    if (Prim == element_dat)
    {
        elem_creat->urmator=Prim->urmator;
        elem_creat->anterior=Prim;
        Prim->urmator=elem_creat;
        return;
    }

    elem_creat->urmator = element_dat->urmator;
    elem_creat->anterior = element_dat;
    element_dat->urmator->anterior = elem_creat;
    element_dat->urmator = elem_creat;
}

//------------------FUNCTII PENTRU STERGEREA IN LISTE DUBLU INLANTUITE-------------------

void stergereElementListaDubluInlantuita(nod_lista_dublu_inlantuita* Prim,nod_lista_dublu_inlantuita* nod_sters)
{
    if(Prim == NULL) return;  //DACA LISTA ESTE VIDA
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
nod_lista_dublu_inlantuita* cautareValoareLD(nod_lista_dublu_inlantuita* Prim, int valoare)
{
    nod_lista_dublu_inlantuita *p = Prim; //FACEM O COPIE A PrimULUI NOD DIN LISTA

    while (p != NULL && p->element != valoare) //PARCURGEM LISTA PANA CAND GASIM VALOAREA CERUTA
        p = p->urmator;

    return p; //RETURNAM NODUL CARE CONTINE VALOAREA CERUTA

}

//CAUTAREA UNUI ELEMENT DUPA O POZITIE DATA INTR-O LISTA DUBLU INLANTUITA
nod_lista_dublu_inlantuita* cautarePozitieLD(nod_lista_dublu_inlantuita* Prim, int pozitie)
{
    nod_lista_dublu_inlantuita *p=Prim; //FACEM O COPIE A PrimULUI NOD DIN LISTA
    int i = 0;  //POZITIA DE INCEPUT A PrimULUI ELEMENT

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

void afisareListaDubluInlantuitaInserare(nod_lista_dublu_inlantuita* Prim)
{
    settextstyle(3, HORIZ_DIR, 6);
    setbkcolor(BLUE);
    outtextxy(50, 20, "Lista reprezentata grafic este");
    setbkcolor(BLACK);


    nod_lista_dublu_inlantuita* p = Prim;//CREAM O COPIE A PrimULUI NOD

    unsigned int x = 20, y = 120; //COORDONATELE DE INCEPUT PENTRU AFISAREA IMAGINILOR CORESPUNZATOARE
    unsigned int xtext = 30, ytext = 140; //COORDONATELE DE INCEPUT PENTRU AFISAREA VALORILOR CORESPUNZATOARE

    if(p == NULL)
    {
        outtextxy(100,150,"LISTA ESTE VIDA");
        readimagefile("imagini/SAD.jpg",180,200,700,600);
    }

    while (p != NULL)
    {
        if (x <= 660)
        {
            // AFISAREA NODULUI CORESPUNZATOR
            if (p->urmator == NULL && p->anterior == NULL)
                readimagefile("imagini/nod singur lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
            else
                {
                    if(p->anterior == NULL)
                    {
                        readimagefile("imagini/nod inceput lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                        readimagefile("imagini/sageti.jpg", x+150, y, x + 200, y + 60);
                    }
                    else
                        {
                            if(p->urmator == NULL)
                                readimagefile("imagini/nod sfarsit lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                            else
                                {
                                    readimagefile("imagini/nod mijloc lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                                    readimagefile("imagini/sageti.jpg", x+150, y, x + 200, y + 60);
                                }
                        }
                }

            // DIMENSIUNEA TEXTULUI IN FIECARE NOD
            dimensiuneTextAndrei(p->element);

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

void afisareListaDubluInlantuita(nod_lista_dublu_inlantuita *Prim)
{
    settextstyle(3, HORIZ_DIR, 6);
    setbkcolor(BLUE);
    outtextxy(50, 20, "Lista reprezentata grafic este");
    setbkcolor(BLACK);

    nod_lista_dublu_inlantuita* p = Prim;

    unsigned int x = 20, y = 120;
    unsigned int xtext = 30, ytext = 140;

    if(p == NULL)
        {
            outtextxy(100,150,"LISTA ESTE VIDA");
            readimagefile("imagini/SAD.jpg",180,200,700,600);
        }
    while (p != NULL)
    {
        if (x <= 960)  // DACA NU IESE DIN ECRANUL DESTINAT AFISARII
        {
            // AFISAREA NODULUI CORESPUNZATOR
            if (p->urmator == NULL && p->anterior == NULL)
                readimagefile("imagini/nod singur lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
            else
                {
                    if(p->anterior == NULL)
                    {
                        readimagefile("imagini/nod inceput lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                        readimagefile("imagini/sageti.jpg", x+150, y, x + 200, y + 60);
                    }
                    else
                        {
                            if(p->urmator == NULL)
                                readimagefile("imagini/nod sfarsit lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                            else
                                {
                                    readimagefile("imagini/nod mijloc lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                                    readimagefile("imagini/sageti.jpg", x+150, y, x + 200, y + 60);
                                }
                        }
                }

            // DIMENSIUNEA TEXTULUI IN FIECARE NOD
            dimensiuneTextAndrei(p->element);

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

void afisareListaDubluInlantuitaCautare(nod_lista_dublu_inlantuita* Prim,nod_lista_dublu_inlantuita* nodd)
{
    settextstyle(3, HORIZ_DIR, 6); //SELECTAM FONTUL, DIRECTIA SI MARIMEA TEXTULUI
    setbkcolor(BLUE); //SELECTAM FUNDALUL SCRISULUI
    outtextxy(50, 20, "Lista reprezentata grafic este");
    setbkcolor(BLACK);

    nod_lista_dublu_inlantuita* p = Prim; //FACEM O COPIE NODULUI INITIAL DIN LISTA
    nod_lista_dublu_inlantuita* q = nodd; //FACEM O COPIE NODULUI PrimIT LA CAUTARE

    unsigned int x = 20, y = 120; //VOM FOLOSI ACESTE VARIABILE PENTRU A AFISA IMAGINEA
    unsigned int xtext = 30, ytext = 140; //VOM FOLOSI ACESTE VARIABILE PENTRU A AFISA VALOAREA

    if(p == NULL)
        {
            outtextxy(100,150,"LISTA ESTE VIDA");
            readimagefile("imagini/SAD.jpg",180,200,700,600);
        }

    while (p != NULL)
    {
        if (x <= 960)  //DACA NU IESE DIN ECRANUL DESTINAT SCRIERII
        {
            // AFISAREA NODULUI CORESPUNZATOR
            if (p->urmator == NULL && p->anterior == NULL)
            {   //DACA Prim ARE ACELASI ELEMENT CU ELEMENTUL CAUTAT DE NOI DAT IN ANTETUL FUNCTIEI VOM AFISA O IMAGINE CU O SAGEATA
                if(p->element == q->element)
                    readimagefile("imagini/Element cautat singur.jpg", x, y-10, x + 150, y + 60);
                else
                    readimagefile("imagini/nod singur lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
            }
            else
                {
                    if(p->anterior == NULL)
                    {   //DACA Prim ARE ACELASI ELEMENT CU ELEMENTUL CAUTAT DE NOI DAT IN ANTETUL FUNCTIEI VOM AFISA O IMAGINE CU O SAGEATA
                        if(p->element == q->element)
                        {
                            readimagefile("imagini/Element cautat Primul.jpg", x, y-10, x + 150, y + 60);
                            readimagefile("imagini/sageti.jpg", x+150, y, x + 200, y + 60);
                        }
                        else
                            {
                                readimagefile("imagini/nod inceput lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                                readimagefile("imagini/sageti.jpg", x+150, y, x + 200, y + 60);
                            }
                    }
                    else
                        {
                            if(p->urmator == NULL)
                            {   //DACA Prim ARE ACELASI ELEMENT CU ELEMENTUL CAUTAT DE NOI DAT IN ANTETUL FUNCTIEI VOM AFISA O IMAGINE CU O SAGEATA
                                if(p->element == q->element)
                                    readimagefile("imagini/Element cautat ultimul.jpg", x, y-10, x + 150, y + 60);
                                else
                                    readimagefile("imagini/nod sfarsit lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                            }
                            else
                                {   //DACA Prim ARE ACELASI ELEMENT CU ELEMENTUL CAUTAT DE NOI DAT IN ANTETUL FUNCTIEI VOM AFISA O IMAGINE CU O SAGEATA
                                    if(p->element == q->element)
                                    {
                                        readimagefile("imagini/Element cautat interior.jpg", x, y-10, x + 150, y + 60);
                                        readimagefile("imagini/sageti.jpg", x+150, y, x + 200, y + 60);
                                    }
                                    else
                                        {
                                            readimagefile("imagini/nod mijloc lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                                            readimagefile("imagini/sageti.jpg", x+150, y, x + 200, y + 60);
                                        }
                                }
                        }
                }

            // DIMENSIUNEA TEXTULUI IN FIECARE NOD
            dimensiuneTextAndrei(p->element);

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

/// ----------------  STIVE  -------------

void meniuStive()
{
    descriereStiva();
    readimagefile("imagini/undo.jpg",30,730,250,780);
    settextstyle(4, HORIZ_DIR, 4);
    outtextxy(0, 10, " Alege functia ");
    readimagefile("imagini/init stiva.jpg",30, 50, 270, 100); // BUTON 1
    readimagefile("imagini/stiva vida.jpg",30, 120, 270, 170); // BUTON 2
    readimagefile("imagini/golire.jpg",30, 190, 270, 240); // BUTON 3
    readimagefile("imagini/pop.jpg",30, 260, 270, 310); // BUTON 4
    readimagefile("imagini/push.jpg",30, 330, 270, 380); // BUTON 5
    readimagefile("imagini/afis stiva.jpg",30, 400, 270, 450); // BUTON 6

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
        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
        sunet();
        initializareStiva(S);
        goto jump;  // RESET LA BUTON
    }
    else
        if (buton2 == true)
        {
            mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
            sunet();
            esteVidaStiva(S);
            goto jump;
        }
        else
            if (buton3 == true)
            {
                mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                sunet();
                golesteStiva(S);
                goto jump;
            }
            else
                if (buton4 == true)
                {
                    mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                    sunet();
                    eliminareStiva();
                    goto jump;
                }
                else
                    if (buton5 == true)
                    {
                        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                        sunet();
                        adaugareStiva();
                        goto jump;
                    }
                    else
                        if (buton6 == true)
                        {
                            mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                            sunet();
                            afisareStiva(S);
                            goto jump;
                        }
                        else
                            if (butonUndo == true)
                            {
                                mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
                                sunet();
                                cleardevice();
                                meniuPrincipal();
                                goto jump;
                            }
}

void descriereStiva()
{
    cleardevice();
    readimagefile("imagini/next.jpg",640,710,850,790);
    readimagefile("imagini/undo.jpg",30,730,250,780);
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
    readimagefile("imagini/stiva descriere.jpg",480,300,890,650);
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
        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
        sunet();
        cleardevice();
        return;
    }
    else
        if (butonUndo == true)
        {
            mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);
            sunet();
            cleardevice();
            meniuPrincipal();
        }
    delay(40000);   // 1 sec =  1000 ms
    cleardevice();
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
        int h = 0;
        for (int i = 1; i <= S.nrElemente; i++)
        {
            readimagefile("imagini/stiva.jpg",730,700 - h,970,740 - h);
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
        delay(300);
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
    delay(200);
    outtextxy(980, 20, ".");
    delay(200);
    outtextxy(1000, 20, ".");
    delay(200);
    outtextxy(1020, 20, ".");
    setcolor(WHITE);

    delay(500);
    deseneazaOutline(200);

    S.varf = NULL;
    S.nrElemente = 0;

    delay(300);
    setcolor(LIGHTMAGENTA);
    settextstyle(4, HORIZ_DIR, 2);
    bgiout << "stiva S;";
    outstreamxy(10, 470);
    bgiout << "S.varf = NULL;";
    outstreamxy(10, 490);
    delay(300);
    bgiout << "S.nrElemente = 0;";
    outstreamxy(10, 510);
    setcolor(WHITE);

    // STERGERE CE AM SCRIS
    delay(2500);
    setfillstyle(SOLID_FILL,BLACK);
    bar(305,0,1520,795);
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,465,295,725);
}

// ---------- STIVA VIDA ----------
void esteVidaStiva(stiva S)
{
    settextstyle(4, HORIZ_DIR, 4);
    setcolor(LIGHTCYAN);
    outtextxy(600, 20, " Verificare stiva vida");
    delay(200);
    outtextxy(1020, 20, ".");
    delay(200);
    outtextxy(1040, 20, ".");
    delay(200);
    outtextxy(1060, 20, ".");
    rectangle(370,100,1470,200);
    setcolor(WHITE);
    if (S.nrElemente == 0)
    {
        delay(200);
        deseneazaOutline(400);
        delay(300);
        settextstyle(4, HORIZ_DIR, 3);
        bgiout << "Stiva are 0 elemente.";
        outstreamxy(680, 110);
        delay(500);
        setcolor(LIGHTRED);
        outtextxy(635, 150, " Stiva introdusa este vida! ");
        setcolor(WHITE);
    }
    else
    {
        delay(200);
        deseneazaElemente(S);
        delay(300);
        settextstyle(4, HORIZ_DIR, 3);
        outtextxy(680, 140, " Stiva nu este vida! ");
    }

    // STERGERE CE AM SCRIS
    delay(2500);
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
    delay(500);
    // ALGORITMUL DE ELIMINARE
    if (!esteVida(S))
    {
        int top = S.varf->valoare;
        // DESENARE STIVA
        deseneazaElemente(S);
        delay(300);
        pop(S);
        // AFISAREA GRAFICA
        setcolor(LIGHTMAGENTA);
        settextstyle(4, HORIZ_DIR, 1);
        bgiout << "nod* vf_nou;";
        outstreamxy(10, 470);
        delay(300);
        bgiout << "el = S.varf->valoare;";
        outstreamxy(10, 500);
        delay(300);
        bgiout << "vf_nou = S.varf->urm;";
        outstreamxy(10, 530);
        delay(300);
        bgiout << "delete S.varf;";
        outstreamxy(10, 560);
        delay(300);
        readimagefile("imagini/black.jpg", 730, 700 - (S.nrElemente * 45), 970, 740 - (S.nrElemente * 45));
        delay(300);
        bgiout << "S.varf = vf_nou;";
        outstreamxy(10, 590);
        delay(300);
        bgiout << "S.nrElemente--;";
        outstreamxy(10, 620);
        delay(300);
        setcolor(WHITE);
        settextstyle(4, HORIZ_DIR, 3);
        bgiout << "S-a eliminat " << top << " din varful stivei.";
        outstreamxy(640, 130);
    }
    else
    {
        delay(300);
        deseneazaOutline(400);
        delay(300);
        settextstyle(4, HORIZ_DIR, 3);
        bgiout << "Stiva are 0 elemente.";
        outstreamxy(390, 110);
        delay(400);
        setcolor(LIGHTRED);
        outtextxy(390, 140, "Eroare! Nu se poate elimina niciun element. Stiva este goala.");
        setcolor(WHITE);
    }

    // STERGERE CE AM SCRIS
    delay(2500);
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
    delay(500);
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
        delay(300);
        int top = S.varf->valoare;
        // AFISAREA GRAFICA
        setcolor(LIGHTMAGENTA);
        settextstyle(4, HORIZ_DIR, 1);
        bgiout << "S.nrElemente++;";
        outstreamxy(10, 470);
        delay(300);
        bgiout << "vf_nou = new nod;";
        outstreamxy(10, 500);
        delay(300);
        deseneazaOutline(700 - S.nrElemente * 45);
        delay(300);
        readimagefile("imagini/stiva.jpg",730,700 - (S.nrElemente - 1) * 45,970,740 - (S.nrElemente - 1) * 45);
        delay(300);
        setcolor(LIGHTMAGENTA);
        bgiout << "vf_nou->valoare = el;";
        outstreamxy(10, 530);
        delay(300);
        setcolor(WHITE);
        settextstyle(4, HORIZ_DIR, 3);
        bgiout << top;
        outstreamxy(800, 710 - (S.nrElemente - 1) * 45);
        delay(300);
        settextstyle(4, HORIZ_DIR, 1);
        setcolor(LIGHTMAGENTA);
        bgiout << "vf_nou->urm = S.varf;";
        outstreamxy(10, 560);
        delay(300);
        bgiout << "S.varf = vf_nou;";
        outstreamxy(10, 590);
        delay(300);
        setcolor(WHITE);
        settextstyle(4, HORIZ_DIR, 3);
        bgiout << "S-a adaugat " << top << " in varful stivei.";
        outstreamxy(640, 130);
    }
    else
    {
        delay(300);
        deseneazaOutline(400);
        delay(300);
        settextstyle(4, HORIZ_DIR, 3);
        bgiout << "Stiva are 0 elemente.";
        outstreamxy(390, 110);
        delay(300);
        int top = S.varf->valoare;
        // AFISAREA GRAFICA
        setcolor(LIGHTMAGENTA);
        settextstyle(4, HORIZ_DIR, 1);
        bgiout << "S.nrElemente = 1;";
        outstreamxy(10, 470);
        delay(300);
        bgiout << "S.varf = new nod;";
        outstreamxy(10, 500);
        delay(300);
        bgiout << "S.varf->valoare = el;";
        outstreamxy(10, 530);
        delay(300);
        bgiout << "S.varf->urm = NULL;";
        outstreamxy(10, 560);
        delay(300);
        setcolor(WHITE);
        settextstyle(4, HORIZ_DIR, 3);
        bgiout << "S-a adaugat " << top << " in varful stivei.";
        outstreamxy(640, 130);

    }
    // STERGERE CE AM SCRIS
    delay(2500);
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
    delay(200);
    outtextxy(960, 20, ".");
    delay(200);
    outtextxy(980, 20, ".");
    delay(200);
    outtextxy(1000, 20, ".");
    setcolor(WHITE);
    delay(500);
    // ALGORITMUL DE GOLIRE
    if(esteVida(S))
    {
        delay(300);
        deseneazaOutline(400);
        delay(400);
        settextstyle(4, HORIZ_DIR, 3);
        bgiout << "Stiva are 0 elemente.";
        outstreamxy(390, 110);
        delay(500);
        setcolor(LIGHTRED);
        outtextxy(390, 140, "Eroare! Nu se poate goli stiva.");
        setcolor(WHITE);

        // STERGERE CE AM SCRIS
        delay(2500);
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
        delay(300);
        pop(S);
        delay(300);
        // AFISARE GRAFICA
        setcolor(LIGHTMAGENTA);
        settextstyle(4, HORIZ_DIR, 1);
        bgiout << "pop(S);";
        outstreamxy(10, 470);
        delay(300);
        readimagefile("imagini/black.jpg", 730, 700 - (S.nrElemente * 45), 970, 740 - (S.nrElemente * 45));
        delay(300);
        readimagefile("imagini/black.jpg", 10,470,110,495); // stergere "pop(s)"
        setcolor(WHITE);
        settextstyle(4, HORIZ_DIR, 3);
        readimagefile("imagini/black.jpg", 371,101,1469,199); // stergere din chenar
        bgiout << "S-a eliminat " << top << " din varful stivei.";
        outstreamxy(640, 130);
        delay(500);
    }
    // STERGERE CE AM SCRIS
    delay(2500);
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
    delay(300);

    deseneazaElemente(S);

    // STERGERE CE AM SCRIS
    delay(2500);
    setfillstyle(SOLID_FILL,BLACK);
    bar(305,0,1520,795);
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,465,295,725);
}

/// ---------- FUNCTII PENTRU COADA ----------

// ---------- MENIU COADA 1 ----------

void meniuCoada1()
{
    descriereCoada();   // APELAM FUNCTIA DE EDESCRIERE A COZII
    meniuCoada2();      // APELAM FUNCTIA UNDE SUNT GASITE
}

// ---------- MENIU COADA 2 ----------

void meniuCoada2()
{
    //DECLARAM PRIMUL SI ULTIMUL NOD DIN COADA
    nod_coada* fata_cozii = NULL;
    nod_coada* spatele_cozii = NULL;

    jump:
    cleardevice();

    settextstyle(3, HORIZ_DIR, 4);
    outtextxy(400, 30, "O coada la gustari pentru catei");
    settextstyle(3, HORIZ_DIR, 3);

    readimagefile("imagini/treat.jpg",50,100,200,250);
    readimagefile("imagini/inapoi coada.jpg",20,600,180,680);
    readimagefile("imagini/stergere element coada.jpg",220,600,380,680);
    readimagefile("imagini/adauga un element coada.jpg",420,600,580,680);
    readimagefile("imagini/element fata cozii.jpg",920,600,1080,680);

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
        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);sunet();
        pop(fata_cozii); // STERGEM PrimUL ELEMENT DIN COADA
        goto jump;
    }
    else
        if (buton2 == true) //BUTON 2 - ADAUGAREA UNUI ELEMENT
        {
            mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);sunet();

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
                mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);sunet();;
                if(element_fata_coada(fata_cozii))
                {
                    mciSendString ("play sunete/bark.mp3", NULL, 0, NULL);

                    // IMAGINE CATEL
                    readimagefile("imagini/dog.jpg", 1100, 580, 1190,700);

                    // DIMENSIUNEA TEXTULUI IN FIECARE NOD
                    dimensiuneTextAndrei(element_fata_coada(fata_cozii));

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
                    mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);sunet();
                    cleardevice();
                    meniuCoada1();
                }
}

// ---------- NOTIUNI TEORETICE DESPRE COADA ----------

void descriereCoada()
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
    readimagefile("imagini/exemplu coada.jpg",910,100,1250,480);

    // CITIREA BUTONULUI PENTRU PAGINA ANTERIOARA
    readimagefile("imagini/inapoi coada.jpg",910,510,1060,580);

    // CITIREA BUTONULUI PENTRU PAGINA URMATOARE
    readimagefile("imagini/next coada.jpg",1110,510,1260,580);

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
        mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);sunet();
        cleardevice();
        meniuCoada2(); //SE DESCHIDE MENIUL URMATOR (CEL CU FUNCTIILE PENTRU COADA)
    }
    else
        if(inapoi == true) //BUTONUL PENTRU PAGINA ANTERIOARA
        {
            mciSendString ("play sunete/sunet.mp3", NULL, 0, NULL);sunet();
            cleardevice();
            meniuPrincipal(); //SE DESCHIDE MENIUL PRINCIPAL
        }

    cleardevice();
}

// ---------- FUNCTIE PENTRU STABILIREA DACA ESTE SAU NU COADA GOALA ----------

bool isEmpty(nod_coada* fata_cozii)
{
    return fata_cozii == NULL;
}

// ---------- INTRODUCEREA UNUI ELEMENT IN COADA ----------

void push(nod_coada* &fata_cozii, nod_coada* &spatele_cozii, int element_coada)
{
    nod_coada* nod_nou_coada = creare_nod_nou_in_coada(element_coada); //CREEM UN NOD NOU IN COADA SI II ATRIBUIM ELEMENTUL DAT

    if(spatele_cozii != NULL)
        spatele_cozii -> urmatorul_din_coada = nod_nou_coada;  //PUNEM NODUL NOU IN SPATELE COZII
    spatele_cozii = nod_nou_coada;

    if(fata_cozii == NULL)
        fata_cozii = nod_nou_coada; //DACA COADA ESTE GOALA PUNEM ELEMENTUL NOU CREAT IN FATA COZII CARE ESTE SIMULTAN
}

// ---------- ELIMINAREA UNUI ELEMENT DIN COADA ----------

int pop(nod_coada* &fata_cozii)
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

int element_fata_coada(nod_coada* fata_cozii)
{
    if(isEmpty(fata_cozii)) //DACA COADA ESTE GOALA RETURNAM 0
        return 0;

    return fata_cozii -> element_coada; // RETURNAM ELEMENTUL DIN FATA COZII
}

// ---------- CREAREA UNUI NOD NOU IN COADA ----------

nod_coada* creare_nod_nou_in_coada(int element_coada)
{
    nod_coada* nod_nou_coada = new nod_coada(); //CREAM UN NOD NOW DE TIP nod_coada
    nod_nou_coada -> element_coada = element_coada; //ATRIBUIM ELEMENTULUI NOULUI NOD CREAT ELEMENTUL DAT
    nod_nou_coada -> urmatorul_din_coada = NULL; //II ASOCIEM URMATORULUI ELEMENT DIN COADA A ELEMENTULUI CREAT VALOARAEA NULL
    return nod_nou_coada; // RETURNAM NODUL CREAT
}

// ---------- AFISAREA COZII ----------

void afisareCoada(nod_coada* fata_cozii)
{
    if(isEmpty(fata_cozii))     //VERIFICAM DACA COADA ESTE GOALA
    {
        outtextxy(300,100,"Nu este niciun catel la coada"); //DACA RASPUNSUL ESTE AFIRMATIV AFISAM UN MEASJ
        readimagefile("imagini/SAD.jpg",180,200,600,500);           //IMPREUNA CU O IMAGINE
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
                    mciSendString ("play sunete/bark1.mp3", NULL, 0, NULL);

                    // AFISAREA NODULUI CORESPUNZATOR
                    readimagefile("imagini/dog.jpg", x, y, x + 100, y + 150);

                    // DIMENSIUNEA TEXTULUI IN FIECARE NOD
                    dimensiuneTextAndrei(p->element_coada);

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
