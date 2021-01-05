#include<iostream>
#include<windows.h>
#include<MMsystem.h>
#include <fstream>
#include <graphics.h>
#include <queue>
using namespace std;
//------------FUNCTII LA COADA-------
struct nod_coada
{
    int element_coada;
    nod_coada* urmatorul_din_coada;
};

nod_coada* nod_Nou_coada(int element_coada)
{
    nod_coada* nod_nou_coada = new nod_coada();
    nod_nou_coada -> element_coada = element_coada;
    nod_nou_coada -> urmatorul_din_coada = NULL;
    return nod_nou_coada;
}

bool isEmpty(nod_coada* fata_cozii)
{
    return fata_cozii == NULL;
}

void push(nod_coada* &fata_cozii, nod_coada* &spatele_cozii, int element_coada)
{
    nod_coada* nod_nou_coada = nod_Nou_coada(element_coada);

    if(spatele_cozii != NULL)
        spatele_cozii -> urmatorul_din_coada = nod_nou_coada;

    spatele_cozii = nod_nou_coada;
    if(fata_cozii == NULL)
        fata_cozii = nod_nou_coada;
}

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
int element_fata_coada(nod_coada* fata_cozii)
{
    if(isEmpty(fata_cozii))
        return 0;
    return fata_cozii -> element_coada;
}
//-------------SFARSIT FUNCTII COADA--------------

//Memorarea unei liste dublu inlantuite
struct nod_lista_dublu_inlantuita
{
    int element;      //elementul memorat
    nod_lista_dublu_inlantuita* urmator;   //Memorarea legaturii catre urmatorul nod
    nod_lista_dublu_inlantuita* anterior;  //Memorarea legaturii catre nodul anterior
};
nod_lista_dublu_inlantuita* prim = NULL;    //Declararea listei vida


//------------FUNCTII UTILIZATE-----------------
//void meniuPrincipal();
void fereastra();
void dimensiuneText(int element);
void meniuListeDubluInlantuite();
void meniuCoada();
void descriereCoada();
void meniuCoadaAdevarat();
void meniuInserareLD();
void descriereListaDubluInlantuita();
void stergereElementLD(nod_lista_dublu_inlantuita* elem);
void stergereElementPozitie(nod_lista_dublu_inlantuita* &prim, int pozitie);
void stergereElementValoare(nod_lista_dublu_inlantuita* &prim, int valoare);
nod_lista_dublu_inlantuita* cautareValoareLD(nod_lista_dublu_inlantuita* prim, int valoare);
nod_lista_dublu_inlantuita* cautarePozitieLD(nod_lista_dublu_inlantuita* prim, int pozitie);
void inserareInceputListaDubluInlantuita(nod_lista_dublu_inlantuita* &prim, int valoare);
void inserareFinalListaDubluInlantuita(nod_lista_dublu_inlantuita* &prim, int valoare);
void afisareListaDubluInlantuita_val(nod_lista_dublu_inlantuita* prim);
void afisareListaDubluInlantuita_poz(nod_lista_dublu_inlantuita* prim);
void meniuInserareLD();
void meniuStergereLD();
void meniuCautareLD();
void citesteSir(char text[100], char afisare[100], int x, int y, bool stergere);
int nrElemente;
// ---------- INITIALIZARE FEREASTRA ----------

void fereastra()
{
    initwindow(1400, 700, " Meniu Biblioteca cu Liste ");
}

void dimensiuneText(int element)
{
     if(element >=0 && element<100)
        settextstyle(3, HORIZ_DIR, 3);
    else
        if(element >= 100 && element < 1000)
            settextstyle(3, HORIZ_DIR, 2);
        else
            if(element >=1000 && element <100000)
                settextstyle(3, HORIZ_DIR, 1);
}

//--------------------------------Crearea listei dublu Inlantuite
void creareListaDubluInlantuita(nod_lista_dublu_inlantuita*& prim,int n,int Valoarea[20])
{
    for(int i=0;i<n;i++)
    inserareFinalListaDubluInlantuita(prim,Valoarea[i]);
}
//--------------------------------------FUNCTIA DE CITIRE----------------------------------------

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

// ---------- AFISAREA UNEI LISTE DUBLU-INLANTUITE ----------
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

// CONSOLA
void afisareLD(nod_lista_dublu_inlantuita* prim)
{
    while (prim != NULL)
    {
        cout << prim->element << "\n"; // Afisam numarul stocat
        prim = prim->urmator;         // Mutam elementul curent la urmatorul element din lista
    }
}

//--------------DESCRIERE LISTA DUBLU INLANTUITA------------------------
void descriereListaDubluInlantuita()
{
    cleardevice();
    readimagefile("next.jpg",640,710,850,790);
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(330,50, "Informatii despre listele dublu inlantuite");
    settextstyle(4, HORIZ_DIR, 1);
    outtextxy(150, 150, "       Listele dublu inlantuite sunt structuri de date dinamice omogene. Ele au aceleasi");
    outtextxy(150, 180, "caracteristici de baza ca si listele liniare simplu inlantuite. Diferenta fata de aceastea");
    outtextxy(150, 210, "consta in faptul ca, pentru fiecare nod, se retine si adresa elementului anterior, ceea ce ");
    outtextxy(150, 240, "permite traversarea listei in ambele directii. Lista dublu inlantuita poate fi reprezentata");
    outtextxy(150, 270, "grafic astfel:");

   //-------------------INTREB ANA AICI----------------------------//

    readimagefile("Exemplu lista dublu inlantuita.jpg",150,300,1250,650);
    //---------BUTON PENTRU PAGINA URMATOARE-----------------
    readimagefile("pagina urmatoare.jpg",600,650,800,700);
    bool gata = false, buton = false;
    int x,y;
    do
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x = mousex();
            y = mousey();
            if(x >= 600 && x <= 800 && y >=650  && y <= 700)
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
    delay(15000);   // 1 sec =  1000 ms
    cleardevice();
}

//------------------FUNCTII PENTRU STERGEREA IN LISTE DUBLU INLANTUITE-------------------

//stergerea unui elemnt dintr-o ListaDubluInlantuita
void stergereElementLD(nod_lista_dublu_inlantuita* elem)
{
    elem->anterior->urmator = elem->urmator;
    elem->urmator->anterior = elem->anterior;
    delete elem;
}
//stergerea unui element de pe o pozitite data Liste Dublu Inlantuite
void stergereElementPozitie(nod_lista_dublu_inlantuita* &prim, int pozitie)
{
    if (pozitie == 0)
    {
        nod_lista_dublu_inlantuita* sters = prim;
        prim = prim->urmator;
        prim->anterior = NULL;
        delete sters;
    }
    else
    {
        nod_lista_dublu_inlantuita* predecesor = cautarePozitieLD(prim, pozitie);
        stergereElementLD(predecesor);
    }
}
//Stergere element dupa o valoare
void stergereElementValoare(nod_lista_dublu_inlantuita* &prim, int valoare)
{
    //In cazul in care elementul vizat este capul listei noastre
    if(prim->element == valoare)
    {
        nod_lista_dublu_inlantuita* sters = prim;
        prim = prim->urmator;
        prim->anterior = NULL;
        delete sters;
        return;
    }
    //Parcurgem lista si cautam elementul cerut
    nod_lista_dublu_inlantuita* elem = prim;
    while (elem->urmator != NULL && elem->urmator->element != valoare)
        elem = elem->urmator;
    //Daca am gasit nodul, il stergem
        stergereElementLD(elem);


}

//-----------------MENIU PENTRU STERGEREA IN LISTE DUBLU INLANTUITE-----
void meniuStergereLD()
{    int Valoarea[20], n, i;
    char afisare[100], vectText[100], numar[100];
    // Colorare text
    setcolor(YELLOW);
    setbkcolor(BLACK);
    settextstyle(3, HORIZ_DIR, 3);
    outtextxy(20,10,"Va rugam introduceti numerele din lista");

    //Functia de citire a textului in mod grafic in sirul afisare
    citesteSir("Cate numere doriti sa contina lista? ", afisare, 20, 40, false);


    nrElemente = atoi(afisare);  // conversie ascii -> int din sirul afisare
    n = nrElemente;
    for (i=0; i<n; i++)
    {
        itoa(i,numar,10); // conversie int -> ascii in sirul "numar"
        strcpy(vectText,"Nodul ");
        strcat(vectText,numar);
        strcat(vectText," are valoarea egala cu: ");

        citesteSir(vectText,afisare, 30, 70 + 30 * i, false); // citire valoare corespunzatoare in vector pe poz i.

        Valoarea[i] = atoi(afisare); // valoarea lui Valoarea[i] in vector

       // evidentiaza(Valoarea[i], i, 1, LIGHTGREEN);
    }

    creareListaDubluInlantuita(prim,n,Valoarea);
    jump:
    cleardevice();
    afisareListaDubluInlantuita(prim);


    readimagefile("inapoi.jpg",1100,310,1350,390);
    settextstyle(3, HORIZ_DIR, 4);
    outtextxy(1100, 10, " Alege functia ");
    outtextxy(1100, 50, "  de stergere ");
    // BUTON 1
    readimagefile("Stergerea primei aparitii a unei valori date.jpg",1100, 100, 1350, 180);
    // BUTON 2
    readimagefile("Stergerea unui element dupa o pozitie data.jpg",1100, 200, 1350, 280);
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
                        if (x >=1100 && x <= 1350 && y >= 310 && y <= 390) //inapoi
                        {
                            gata = true;
                            buton3 = true;
                        }
        }
    } while (!gata);

    if (buton1 == true)
    {
        settextstyle(3, HORIZ_DIR, 3);
        outtextxy(1100,410,"Ce numar doriti");
        outtextxy(1100,440,"  sa stergeti? " );

        //Functia de citire a textului in mod grafic in sirul afisare
        citesteSir("numarul: ", afisare, 1110, 470, false);

        int valoare= atoi(afisare);  // conversie ascii -> int din sirul afisare
        stergereElementValoare(prim,valoare);
        goto jump;  // RESET LA BUTON
    }
    else
        if (buton2 == true)
        {   settextstyle(3, HORIZ_DIR, 3);
            outtextxy(1100,410,"Ce nod doriti");
            outtextxy(1100,440," sa stergeti? ");

            //Functia de citire a textului in mod grafic in sirul afisare
            citesteSir("numarul: ", afisare, 1110, 470, false);

            int pozitie= atoi(afisare);  // conversie ascii -> int din sirul afisare
            stergereElementPozitie(prim, pozitie);
            goto jump;  // RESET LA BUTON
        }
            else
                if (buton3 == true)
                {
                    meniuListeDubluInlantuite();
                }
}
//------------------FUNCTII PENTRU CAUTAREA IN LISTE DUBLU INLANTUITE---

//Cautarea unui element dupa o valoare data LD
nod_lista_dublu_inlantuita* cautareValoareLD(nod_lista_dublu_inlantuita* prim, int valoare)
{
    while (prim != NULL && prim->element != valoare)
        prim = prim->urmator;
    return prim;
}
//Cautarea unui element dupa o pozitie data LD

nod_lista_dublu_inlantuita* cautarePozitieLD(nod_lista_dublu_inlantuita* prim, int pozitie)
{
    int i = 0;  //Pozitia curenta
    //Parcurgem lista pana la pozitia curenta, sau
    //pana ajungem la ultimul element al listei
    while (prim != NULL && i < pozitie)
    {
        prim = prim->urmator;
        i++;
    }
    //In cazul in care am gasit pozitia ceruta, o returnam
    if (i == pozitie)
        return prim;
    else
        return NULL;
}

void afisareListaDubluInlantuita_poz_val(nod_lista_dublu_inlantuita* prim,nod_lista_dublu_inlantuita* nodd)
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
                 {if(p==nodd)readimagefile("Element cautat singur.jpg", x, y, x + 150, y + 60);
                      else readimagefile("nod singur lista dublu inlantuita.jpg", x, y, x + 150, y + 60);}
                 else { if(p->anterior == NULL) {if(p==nodd)
                                                 {readimagefile("Element cautat primul.jpg", x, y, x + 150, y + 60);
                                                  readimagefile("sageti.jpg", x+150, y, x + 200, y + 60);}
                                                 else {readimagefile("nod inceput lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                                                  readimagefile("sageti.jpg", x+150, y, x + 200, y + 60);}}
                        else {if(p->urmator == NULL)
                                {if(p==nodd)readimagefile("Element cautat ultimul.jpg", x, y, x + 150, y + 60);
                                  else readimagefile("nod sfarsit lista dublu inlantuita.jpg", x, y, x + 150, y + 60);}
                              else {if(p==nodd){readimagefile("Element cautat interior.jpg", x, y, x + 150, y + 60);
                                                 readimagefile("sageti.jpg", x+150, y, x + 200, y + 60);}
                                    else {readimagefile("nod mijloc lista dublu inlantuita.jpg", x, y, x + 150, y + 60);
                                          readimagefile("sageti.jpg", x+150, y, x + 200, y + 60);}}
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
//------------------MENIU PENTRU CAUTAREA IN LISTE DUBLU INLANTUITE-----
void meniuCautareLD()
{int Valoarea[20], n, i;
    char afisare[100], vectText[100], numar[100];
    // Colorare text
    setcolor(YELLOW);
    setbkcolor(BLACK);
    settextstyle(3, HORIZ_DIR, 3);
    outtextxy(20,10,"Va rugam introduceti numerele din lista");

    //Functia de citire a textului in mod grafic in sirul afisare
    citesteSir("Cate numere doriti sa contina lista? ", afisare, 20, 40, false);


    nrElemente = atoi(afisare);  // conversie ascii -> int din sirul afisare
    n = nrElemente;
    for (i=0; i<n; i++)
    {
        itoa(i,numar,10); // conversie int -> ascii in sirul "numar"
        strcpy(vectText,"Nodul ");
        strcat(vectText,numar);
        strcat(vectText," are valoarea egala cu: ");

        citesteSir(vectText,afisare, 30, 70 + 30 * i, false); // citire valoare corespunzatoare in vector pe poz i.

        Valoarea[i] = atoi(afisare); // valoarea lui Valoarea[i] in vector

       // evidentiaza(Valoarea[i], i, 1, LIGHTGREEN);
    }
    creareListaDubluInlantuita(prim,n,Valoarea);

    cleardevice();
    jump:
    afisareListaDubluInlantuita(prim);
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
    {
        settextstyle(3, HORIZ_DIR, 3);
        outtextxy(1100,410,"Ce pozitie doriti");
        outtextxy(1100,440,"  sa cautati? " );

        //Functia de citire a textului in mod grafic in sirul afisare
        citesteSir("pozitia: ", afisare, 1110, 470, false);
        int valoare= atoi(afisare);  // conversie ascii -> int din sirul afisare
        cleardevice();
        afisareListaDubluInlantuita_poz_val(prim,cautarePozitieLD(prim,valoare));
        goto jump;  // RESET LA BUTON
    }
    else
        if (buton2 == true)
        {   settextstyle(3, HORIZ_DIR, 3);
        outtextxy(1100,410,"Ce valoare doriti");
        outtextxy(1100,440,"    sa cautati?  ");

        //Functia de citire a textului in mod grafic in sirul afisare
        citesteSir("valoarea: ", afisare, 1110, 470, false);

        int valoare= atoi(afisare);  // conversie ascii -> int din sirul afisare
            cleardevice();
            afisareListaDubluInlantuita_poz_val(prim,cautareValoareLD(prim,valoare));
            goto jump;  // RESET LA BUTON
        }
            else
                if (buton3 == true)
                {
                    meniuListeDubluInlantuite();
                }
}
//------------------FUNCTII PENTRU INSERAREA IN LISTE DUBLU INLANTUITE--
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
//------------------MENIU INSERARE LD------------------
void meniuInserareLD()
{   int Valoarea[20], n, i;
    char afisare[100], vectText[100], numar[100];
    // Colorare text
    setcolor(YELLOW);
    setbkcolor(BLACK);
    settextstyle(3, HORIZ_DIR, 3);
    outtextxy(20,10,"Va rugam introduceti numerele din lista");

    //Functia de citire a textului in mod grafic in sirul afisare
    citesteSir("Cate numere doriti sa contina lista? ", afisare, 20, 40, false);


    nrElemente = atoi(afisare);  // conversie ascii -> int din sirul afisare
    n = nrElemente;
    for (i=0; i<n; i++)
    {
        itoa(i,numar,10); // conversie int -> ascii in sirul "numar"
        strcpy(vectText,"Nodul ");
        strcat(vectText,numar);
        strcat(vectText," are valoarea egala cu: ");

        citesteSir(vectText,afisare, 30, 70 + 30 * i, false); // citire valoare corespunzatoare in vector pe poz i.

        Valoarea[i] = atoi(afisare); // valoarea lui Valoarea[i] in vector

       // evidentiaza(Valoarea[i], i, 1, LIGHTGREEN);
    }

    creareListaDubluInlantuita(prim,n,Valoarea);
    jump:
    cleardevice();
    afisareListaDubluInlantuita(prim);
    readimagefile("inapoi.jpg",1100,310,1350,390);
    settextstyle(3, HORIZ_DIR, 4);
    outtextxy(1100, 10, " Alege functia ");
    outtextxy(1100, 50, "  de inserare ");
    // BUTON 1
    readimagefile("Inserare element dat la inceputul listei.jpg",1100, 100, 1350, 180);
    // BUTON 2
    readimagefile("Inserare element dat la finalul listei.jpg",1100, 200, 1350, 280);
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
    {   settextstyle(3, HORIZ_DIR, 3);
        outtextxy(1100,410,"Ce numar doriti");
        outtextxy(1100,450,"  sa inserati? " );

        //Functia de citire a textului in mod grafic in sirul afisare
        citesteSir("numarul: ", afisare, 1110, 480, false);

        int valoare= atoi(afisare);  // conversie ascii -> int din sirul afisare
        inserareInceputListaDubluInlantuita(prim, valoare);
        goto jump;  // RESET LA BUTON
    }
    else
        if (buton2 == true)
        {  settextstyle(3, HORIZ_DIR, 3);
        outtextxy(1100,410,"Ce numar doriti");
        outtextxy(1100,430,"  sa inserati? " );

        //Functia de citire a textului in mod grafic in sirul afisare
        citesteSir("numarul: ", afisare, 1110, 450, false);

        int valoare= atoi(afisare);  // conversie ascii -> int din sirul afisare
        inserareFinalListaDubluInlantuita(prim, valoare);
        goto jump;  // RESET LA BUTON
        }
            else
                if (buton3 == true)
                {
                    meniuListeDubluInlantuite();
                }
}
//-----------------MENIU PENTRU LISTE DUBLU INLANTUITE--------------------
void meniuListeDubluInlantuite()
{
    descriereListaDubluInlantuita();
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(400, 50, " Alege functia pentru listele dublu inlantuite ");

    // BUTON 1 - INSERAREA UNUI ELEMENT DAT
    readimagefile("Inserare element dat.jpg",550,100,850,200);

    // BUTON 2 - STERGEREA UNUI ELEMENT DAT
    readimagefile("Stergere element.jpg",550,250,850,350);

    // BUTON 3 - CAUTAREA UNUI ELEMENT DAT
    readimagefile("Cautarea unui element dat.jpg", 550, 400, 850, 500);

    // BUTON 4 - UNDO
    readimagefile("inapoi.jpg",550,550,850,650);

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
            if (x >= 550 && x <= 850 && y >= 100 && y <= 200) //BUTON 1 - INSERARE
            {
                gata = true;
                buton1 = true;
            }
            else
                if (x >= 550 && x <= 850 && y >= 250 && y <= 350)  //BUTON 2 - STERGERE
                {
                    gata = true;
                    buton2 = true;
                }
                else
                    if (x >= 550 && x <= 850 && y >= 400 && y <= 500) //BUTON 3 - CAUTARE
                    {
                        gata = true;
                        buton3 = true;
                    }
                            else
                                if (x >= 550 && x <= 850 && y >= 550 && y <= 650)
                                {
                                    gata = true;
                                    inapoi = true;
                                }
        }
    } while (!gata);
    cleardevice();

    if (buton1 == true)  // Creare lista
    {
        meniuInserareLD();
    }
    else
        if (buton2 == true)  // Verificare daca lista este vida
        {
            meniuStergereLD();
        }
        else
            if (buton3 == true)  // Functie pt aflarea lungimii listei
            {
                meniuCautareLD();
            }
            else
                    if (inapoi == true)
                            {
                                cleardevice();
                               // meniuPrincipal();
                            }
}
//------------Meniu principal------------
/*void meniuPrincipal()
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
      //  meniuListeSimpluInlantuite();
    }
    else
        if (buton2 == true)
        {   meniuListeDubluInlantuite();

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
                     meniuCozi();

                }
}*/
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
    {
        delay(0);
        cleardevice();
        return;
    }
    else if(inapoi == true)
        {cleardevice();
        // meniuPrincipal();
        }
    delay(15000);   // 1 sec =  1000 ms
    cleardevice();
}

void meniuCoadaAdevarat()
{   jump:
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
                    if (x >= 920 && x <= 850 && y >= 680  && y <= 1080) //BUTON 3 - FRONT
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
    cleardevice();

    if (buton1 == true)  // STERGERE
    {

    }
    else
        if (buton2 == true) //PUSH
        { char afisare[100];
        outtextxy(600,620,"Ce catel doriti");
        outtextxy(600,640," sa adaugati? " );

        //Functia de citire a textului in mod grafic in sirul afisare
        citesteSir(" catel ", afisare, 600, 660 , false);

        int valoare= atoi(afisare);  // conversie ascii -> int din sirul afisare

        goto jump;
        // RESET LA BUTON

        }
        else
            if (buton3 == true)  // FRONT
            {

            }
            else
                    if (inapoi == true)  //BACK
                            { cleardevice();
                              meniuCoada();
                            }
}
void meniuCoada()
{   descriereCoada();
    meniuCoadaAdevarat();
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
    meniuCoada();
    cleanup();
}
 void sunet()
{
        PlaySound(TEXT("song.wav"),NULL,SND_SYNC);
}
int main()
{
    interfataGrafica();
    sunet();
    return 0;
}
