#include <iostream>
#include <graphics.h>
#include <winbgim.h>

using namespace std;

// ---------- INITIALIZARE FEREASTRA ----------
void fereastra()
{
    initwindow(1200, 700, " Meniu Biblioteca cu Liste ");
    floodfill(100, 100, BLACK);
}

// ---------- BUTON UNDO ----------
void butonUNDO()
{
    rectangle(20,620,250, 680);
    settextstyle(4, HORIZ_DIR, 1);
    outtextxy(30, 640, " Inapoi la meniu ");

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

// ---------- MENIU FUNCTII INSERARE ----------
void meniuInserare()
{
    butonUNDO();

    // BUTON 1
    rectangle(440,250,800, 310);
    settextstyle(4, HORIZ_DIR, 1);
    outtextxy(450, 270, " Inserare la inceputul listei ");

    // BUTON 2
    rectangle(440,350,800, 410);
    settextstyle(4, HORIZ_DIR, 1);
    outtextxy(450, 370, " Inserare la sfarsitul listei ");

    // BUTON 3
    rectangle(440,450,800, 510);
    settextstyle(4, HORIZ_DIR, 1);
    outtextxy(450, 470, " Inserare dupa un nod dat ");

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
            if(x >= 440 && x <= 800 && y >= 250 && y <= 310) //buton 1
            {
                gata = true;
                buton1 = true;
            }
            else
                if(x >= 440 && x <= 800 && y >= 350 && y <= 410)  //buton 2
                {
                    gata = true;
                    buton2 = true;
                }
                else
                    if(x >= 440 && x <= 800 && y >= 450 && y <= 510) //buton 3
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

// ---------- MENIU PENTRU LISTE SIMPLU-INLANTUITE ----------
void meniuListeSimpluInlantuite()
{
    butonUNDO();

    // BUTON 1
    rectangle(440,250,750, 310);
    settextstyle(4, HORIZ_DIR, 1);
    outtextxy(530, 270, " Lista vida ");

    // BUTON 2
    rectangle(440,350,750, 410);
    settextstyle(4, HORIZ_DIR, 1);
    outtextxy(540, 370, " Inserare ");

    // BUTON 3
    rectangle(440,450,750, 510);
    settextstyle(4, HORIZ_DIR, 1);
    outtextxy(530, 470, " Stergere ");

    // BUTON 4
    rectangle(440,550,750, 610);
    settextstyle(4, HORIZ_DIR, 1);
    outtextxy(540, 570, " Afisare ");

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
            if(x >= 440 && x <= 750 && y >= 250 && y <= 310) //buton 1
            {
                gata = true;
                buton1 = true;
            }
            else
                if(x >= 440 && x <= 750 && y >= 350 && y <= 410)  //buton 2
                {
                    gata = true;
                    buton2 = true;
                }
                else
                    if(x >= 440 && x <= 750 && y >= 450 && y <= 510) //buton 3
                    {
                        gata = true;
                        buton3 = true;
                    }
                    else
                        if(x >= 440 && x <= 750 && y >= 550 && y <= 610)  //buton 4
                        {
                            gata = true;
                            buton4 = true;
                        }
        }
    } while (!gata);
    cleardevice();
    if(buton1 == true)
    {
        outtextxy(380, 100, " Lista simplu-inlantuita este Vida");
        //listaVida();
    }
    else
        if(buton2 == true)
        {
            outtextxy(450, 100, " Alege functia de inserare ");
            meniuInserare();
        }
        else
            if(buton3 == true)
            {
                outtextxy(450, 100, " Alege functia de stergere ");
                //meniuStergere();
            }
            else
                if(buton4 == true)
                {
                    outtextxy(440, 100, " Afisarea unei liste simplu-inlantuite");
                    //afisare();
                }

}

// ---------- MENIU PRINCIPAL ----------
void butoaneMeniuPrincipal()
{
    setcolor(RED);
    setlinestyle(2,1,2);
    // BUTON 1
    rectangle(440,250,750, 310);
    settextstyle(4, HORIZ_DIR, 1);
    setcolor(WHITE);
    outtextxy(450, 270, " Liste simplu-inlantuite ");

    // BUTON 2
    setcolor(RED);
    rectangle(440,350,750, 410);
    settextstyle(4, HORIZ_DIR, 1);
    setcolor(WHITE);
    outtextxy(450, 370, " Liste dublu-inlantuite ");

    // BUTON 3
    setcolor(RED);
    rectangle(440,450,750, 510);
    settextstyle(4, HORIZ_DIR, 1);
    setcolor(WHITE);
    outtextxy(550, 470, " Stive ");

    // BUTON 4
    setcolor(RED);
    rectangle(440,550,750, 610);
    settextstyle(4, HORIZ_DIR, 1);
    setcolor(WHITE);
    outtextxy(550, 570, " Cozi ");


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
            if(x >= 440 && x <= 750 && y >= 250 && y <= 310)
            {
                gata = true;
                buton1 = true;
            }
            else
                if(x >= 440 && x <= 750 && y >= 350 && y <= 410)
                {
                    gata = true;
                    buton2 = true;
                }
                else
                    if(x >= 440 && x <= 750 && y >= 450 && y <= 510)
                    {
                        gata = true;
                        buton3 = true;
                    }
                    else
                        if(x >= 440 && x <= 750 && y >= 550 && y <= 610)
                        {
                            gata = true;
                            buton4 = true;
                        }
        }
    } while (!gata);
    cleardevice();
    if(buton1 == true)
    {
        outtextxy(320, 100, " Alege functia pentru liste simplu-inlantuite ");
        meniuListeSimpluInlantuite();
    }
    else
        if(buton2 == true)
        {
            outtextxy(320, 100, " Alege functia pentru liste dublu-inlantuite ");
        }
        else
            if(buton3 == true)
            {
                outtextxy(400, 100, " Alege functia pentru stive ");
            }
            else
                if(buton4 == true)
                {
                    outtextxy(400, 100, " Alege functia pentru cozi");
                }
}

void meniu()
{
    // ---------- TITLU MENIU ----------
    settextstyle(4, HORIZ_DIR, 3);
    outtextxy(400, 100, " Alege structura de date ");


    butoaneMeniuPrincipal();

}

int main()
{
    fereastra();
    meniu();



    // CLEANUP
    getch();
    closegraph();
    return 0;
}
