#include <iostream>
#include <stdio.h>
#include <winbgim.h>

#define MAX 50

using namespace std;

int nrElemente;

void print(int element, int poz, int coloana, int culoare)
{
    char ns[MAX];
    itoa(element,ns,10);
    setcolor(culoare);
    rectangle(100+100*coloana,120+30*poz-10,100+100*(coloana+1)-30,
              120+30*poz+20);
    outtextxy(100+100*coloana+30,120+30*poz,ns);
}

void evidentiaza(int element, int poz, int coloana, int culoare)
{
    print(888888,poz,coloana, BLACK);
    print(element,poz,coloana, culoare);
    delay(500);
    print(element,poz,coloana, WHITE);
}

void interclasare(int a[],int p,int m,int q)
{
    int i=p,j=m+1;
    int k=0;
    int temp[10]= {0};
    for (int ii=0; ii<nrElemente; ii++)
        evidentiaza(temp[ii],ii,3,LIGHTCYAN);
    while (i<=m && j<=q)
    {
        evidentiaza(a[i],i,1,LIGHTBLUE);
        evidentiaza(a[i],i,2,LIGHTBLUE);
        evidentiaza(a[j],j,1,LIGHTBLUE);
        evidentiaza(a[j],j,2,LIGHTBLUE);
        if (a[i]<a[j])
        {
            temp[k]=a[i];
            evidentiaza(a[i],i,2,LIGHTCYAN);
            evidentiaza(temp[k],k,3,LIGHTCYAN);
            print(a[i],i,2,BLACK);
            print(a[j],j,2,BLACK);
            k++;
            i++;
        }
        else
        {
            temp[k]=a[j];
            evidentiaza(a[j],j,2,LIGHTCYAN);
            evidentiaza(temp[k],k,3,LIGHTCYAN);
            print(a[i],i,2,BLACK);
            print(a[j],j,2,BLACK);
            k++;
            j++;
        }
    }
    while (i<=m)
    {
        evidentiaza(a[i],i,1,LIGHTGREEN);
        temp[k]=a[i];
        evidentiaza(temp[k],k,3,LIGHTGREEN);
        k++;
        i++;
    }
    while (j<=q)
    {
        evidentiaza(a[j],j,1,LIGHTGREEN);
        temp[k]=a[j];
        evidentiaza(temp[k],k,3,LIGHTGREEN);
        k++;
        j++;
    }
    for (i=0; i<k; i++)
    {
        a[p+i]=temp[i];
        evidentiaza(temp[i],i,3,RED);
        evidentiaza(a[p+i],p+i,1,RED);
    }
}

void mergesort(int a[],int p, int q)
{
    if (p<q)
    {
        int m=(p+q)/2;
        mergesort(a,p,m);
        mergesort(a,m+1,q);
        interclasare(a,p,m,q);
    }
}

void citesteSir(char text[MAX], char afisare[MAX], int x, int y, bool stergere)
{
    strcpy(afisare, "");
    char aux[MAX];
    char key[2];  // sirul in care se pastreaza tasta pe care o apasam la citire
    char tasta;   // tasta pe care se apasa
    char text2[MAX];
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

int main()
{
    int a[20], n, i;
    char afisare[MAX], vectText[MAX], numar[MAX];

    // Initializare fereastra
    initwindow(1000,800,"BibMat");

    // Colorare text
    setcolor(YELLOW);
    setbkcolor(BLACK);
    outtextxy(100,30,"Merge Sort");

    //Functia de citire a textului in mod grafic in sirul afisare
    citesteSir("Dati dimensiunea vectorului, n = ", afisare, 100, 70, false);


    nrElemente = atoi(afisare);  // conversie ascii -> int din sirul afisare
    n = nrElemente;
    for (i=0; i<n; i++)
    {
        itoa(i,numar,10); // conversie int -> ascii in sirul "numar"
        strcpy(vectText,"a[");
        strcat(vectText,numar);
        strcat(vectText,"]=");

        citesteSir(vectText,afisare, 100, 120 + 30 * i, false); // citire valoare corespunzatoare in vector pe poz i.

        a[i] = atoi(afisare); // valoarea lui a[i] in vector

        evidentiaza(a[i], i, 1, LIGHTGREEN);
    }
    for (i=0; i<n; i++)
        cout<<a[i]<<", ";
    cout<<endl;

    mergesort(a,0,n-1);

    for (i=0; i<n; i++)
        cout<<a[i]<<", ";
    cout<<endl;
    return 0;
}
