#include <iostream>
#include <graphics.h>
#include <winbgim.h>

using namespace std;

void backgroundColor()
{
    //setbkcolor(WHITE);


}

// ---------- INITIALIZARE FEREASTRA ----------
void fereastra()
{
    initwindow(1200, 700, " Meniu Biblioteca cu Liste ");
    backgroundColor();
}

// ---------- BUTON UNDO ----------
void butonUNDO()
{
    readimagefile("undo.jpg",20,620,250,680);

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
    backgroundColor();
    butonUNDO();
}

void inserareSfarsit()
{
    backgroundColor();
    butonUNDO();
}

void inserareDupaNod()
{
    backgroundColor();
    butonUNDO();
}

// ---------- MENIU FUNCTII INSERARE ----------
void meniuInserare()
{
    backgroundColor();
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
    backgroundColor();
    butonUNDO();

    // BUTON 1
    readimagefile("vida.jpg",440,230,750,290);

    // BUTON 2
    readimagefile("inserare.jpg",440,330,750,390);

    // BUTON 3
    readimagefile("stergere.jpg",440,430,750, 490);

    // BUTON 4
    readimagefile("afisare.jpg",440,530,750, 590);

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
            if(x >= 440 && x <= 750 && y >= 230 && y <= 290) //buton 1
            {
                gata = true;
                buton1 = true;
            }
            else
                if(x >= 440 && x <= 750 && y >= 330 && y <= 390)  //buton 2
                {
                    gata = true;
                    buton2 = true;
                }
                else
                    if(x >= 440 && x <= 750 && y >= 430 && y <= 490) //buton 3
                    {
                        gata = true;
                        buton3 = true;
                    }
                    else
                        if(x >= 440 && x <= 750 && y >= 530 && y <= 590)  //buton 4
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
    backgroundColor();

    // BUTON 1
    readimagefile("liste s i.jpg",440,210,750,280);

    // BUTON 2
    readimagefile("liste d i.jpg",440,310,750, 380);

    // BUTON 3
    readimagefile("stive.jpg",440,410,750, 480);

    // BUTON 4
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
            if(x >= 440 && x <= 750 && y >= 210 && y <= 280)
            {
                gata = true;
                buton1 = true;
            }
            else
                if(x >= 440 && x <= 750 && y >= 310 && y <= 380)
                {
                    gata = true;
                    buton2 = true;
                }
                else
                    if(x >= 440 && x <= 750 && y >= 410 && y <= 480)
                    {
                        gata = true;
                        buton3 = true;
                    }
                    else
                        if(x >= 440 && x <= 750 && y >= 510 && y <= 580)
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
    backgroundColor();

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
