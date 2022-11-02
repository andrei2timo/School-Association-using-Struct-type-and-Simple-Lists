#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
#include <graphics.h>
#include <conio.h>
using namespace std;
struct elev
{
    char nume[30];
    char prenume[30];
    int nr_note;
    float  note[10];
    float nota_la_teza;
    float medie;
};
struct nod
{
    elev info;
    nod *next;
};
int n,i,ok;
int d1=35,d2=120,d3=0;
char a1[10],a[10],b[10],c[10],d[10],e[10];
void adaugare(nod *&p,nod *&u,elev x)
{
    nod *q=new nod;
    q->info=x;
    q->next=NULL;
    if(p==0)
        p=u=q;
    else
    {
        u->next=q;
        u=q;
    }
}
void citire(nod *&p,nod *&u,char clasa[5])
{
    strcat(clasa,".in");
    ifstream f(clasa);
    elev x;
    int s=0;
    float media;
    f>>n;
    for(i=1; i<=n; i++)
    {
        f.get();
        f.get(x.nume,30);
        f.get();
        f.get(x.prenume,30);
        f.get();
        f>>x.nr_note;
        for(int j=1; j<=x.nr_note; j++)
        {
            f>>x.note[j];
            s=s+x.note[j];
        }
        media=(float)(s/x.nr_note);
        s=0;
        f>>x.nota_la_teza;
        x.medie=(float)(3*media+x.nota_la_teza)/4;
        adaugare(p,u,x);
    }
}
void afisare(nod *p)
{
    while(p)
    {
        cout<<"Elevul: "<<p->info.nume<<" "<<p->info.prenume<<" are "<<p->info.nr_note;
        cout<<" note: ";
        for(i=1; i<=p->info.nr_note; i++)
            cout<<p->info.note[i]<<" ";
        cout<<" iar nota in teza este "<<p->info.nota_la_teza<<endl;
        cout<<"Media generala: "<<p->info.medie<<endl;
        p=p->next;
        cout<<endl;
    }
    cout<<endl;
}
void afisare2(nod *p)
{
    while(p)
    {
        for(int i=1; i<=n; i++)
        {
            outtextxy(200,70,"Situatia elevilor:");
            setcolor(3);
            outtextxy(d1,d2+d3,"Elevul: ");
            outtextxy(2*d1+d2/6,d2+d3,p->info.nume);
            outtextxy(2*d1+d2/2,d2+d3,p->info.prenume);
            outtextxy(2*d1+d2-d2/6+25,d2+d3,"are");
            d3=d3+20;
            itoa(p->info.nr_note,a1,10);
            outtextxy(2*d1+d2-d2/6+d2/4+25,d2+d3-20,a1);
            outtextxy(2*d1+d2-d2/6+d2/4+10+25,d2+d3-20,"note: ");
            for(i=1; i<=p->info.nr_note; i++)
            {
                itoa(p->info.note[i],a,10);
                strcat(b," ");
                strcat(b,a);
            }
            outtextxy(2*d1+d2-d2/6+d2/4+70,d2+d3-20,b);
            outtextxy(2*d1+250,d2+d3-20," si nota in teza: ");
            itoa(p->info.nota_la_teza,d,10);
            outtextxy(3*d1+380,d2+d3-20,d);
            p=p->next;
        }
        cout<<endl;
    }
}
float medie(nod *p);
void afisare3(nod *p)
{
    float y=medie(p);
    while(p)
    {
        if(p->info.medie==y)
        for(int i=1; i<=n; i++)
        {
            outtextxy(200,70,"Situatia elevilor:");
            setcolor(3);
            outtextxy(d1,d2+d3,"Elevul: ");
            outtextxy(2*d1+d2/6,d2+d3,p->info.nume);
            outtextxy(2*d1+d2/2,d2+d3,p->info.prenume);
            outtextxy(2*d1+d2-d2/6+25,d2+d3,"are");
            d3=d3+20;
            itoa(p->info.nr_note,a1,10);
            outtextxy(2*d1+d2-d2/6+d2/4+25,d2+d3-20,a1);
            outtextxy(2*d1+d2-d2/6+d2/4+10+25,d2+d3-20,"note: ");
            for(i=1; i<=p->info.nr_note; i++)
            {
                itoa(p->info.note[i],a,10);
                strcat(b," ");
                strcat(b,a);
            }
            outtextxy(2*d1+d2-d2/6+d2/4+70,d2+d3-20,b);
            outtextxy(2*d1+250,d2+d3-20," si nota in teza: ");
            itoa(p->info.nota_la_teza,d,10);
            outtextxy(3*d1+380,d2+d3-20,d);
            p=p->next;
        }
        cout<<endl;
    }
}
void cautare_elev(nod *p,elev x)
{
    while(p!=NULL)
    {
        if(stricmp(x.nume,p->info.nume)==0)
        {
            setcolor(4);
            outtextxy(d1,d2+d3,"Elevul: ");
            outtextxy(2*d1+d2/6,d2+d3,p->info.nume);
            outtextxy(2*d1+d2/2,d2+d3,p->info.prenume);
            outtextxy(2*d1+d2-d2/6+25,d2+d3,"are");
            d3=d3+20;
            itoa(p->info.nr_note,a1,10);
            outtextxy(2*d1+d2-d2/6+d2/4+25,d2+d3-20,a1);
            outtextxy(2*d1+d2-d2/6+d2/4+10+25,d2+d3-20,"note: ");
            for(i=1; i<=p->info.nr_note; i++)
            {
                itoa(p->info.note[i],a,10);
                strcat(b," ");
                strcat(b,a);
            }
            outtextxy(2*d1+d2-d2/6+d2/4+70,d2+d3-20,b);
            outtextxy(2*d1+250,d2+d3-20," si nota in teza: ");
            itoa(p->info.nota_la_teza,d,10);
            outtextxy(3*d1+330,d2+d3-20,d);
            p=p->next;
            cout<<endl;
            ok=1;
        }
        p=p->next;
    }
    cout<<endl;
}
void generare_fereastra_grafica()
{
    int W,H,x=10,d=80;
    int l=60;
    H=x*l+d-200;
    W=x*l+d;
    initwindow(W,H,"* * * SCOALA * * *");
    floodfill(10,10,0);
}
void generare_fereastra_grafica2()
{
    int W,H,x=10,d=100;
    int l=50;
    H=x*l+d;
    W=x*l+d*8;
    initwindow(W,H,"* * * ELEVI * * *");
    floodfill(10,10,0);
}
float medie(nod *p)
{
    float m=p->info.medie;
    while(p)
    {
        if(p->info.medie>m)
            m=p->info.medie;
        p=p->next;
    }
    return m;
}
void ordonare_dupa_medie(nod *p)
{
    nod *a,*b;
    elev aux;
    for(a=p; a->next!=NULL; a=a->next)
        for(b=a->next; b!=NULL; b=b->next)
            if(b->info.medie>a->info.medie)
            {
                aux=b->info;
                b->info=a->info;
                a->info=aux;
            }
}
void Meniu(nod *p,nod *u)
{
    elev x;
    char ch,clasa[5];
    generare_fereastra_grafica();
    outtextxy(35,50,"Acesta este meniul . Va rugam sa selectati una dintre optiunile apasand una dintre tastele 1 -> 7:");
    outtextxy(35,120,"Apasati tasta 1 daca doriti sa cititi datele dintr-un fisier precizat (XI -A,B,C,D,E,F).");
    outtextxy(35,140,"Apasati tasta 2 daca doriti sa cautati un elev.");
    outtextxy(35,160,"Apasati tasta 3 daca doriti sa afisati media cea mai mare a clasei.");
    outtextxy(35,180,"Apasati tasta 4 daca doriti sa afisati elevii cu media cea mai mare a clasei.");
    outtextxy(35,200,"Apasati tasta 5 daca doriti sa afisati elevii descrescator dupa medie.");
    outtextxy(35,220,"Apasati tasta 6 daca doriti sa iesiti din aplicatie.");
    clearmouseclick(WM_LBUTTONDOWN);
    while(!kbhit())
    {
        ch=_getch();
        if(ch=='1')
        {
            cout<<"Ati apasat tasta "<<ch<<"."<<endl<<endl;
            cout<<"Citirea datelor se va face dintr-un fisier precizat!"<<endl;
            cin>>clasa;
            generare_fereastra_grafica();
            citire(p,u,clasa);
            afisare2(p);
            ///afisare(p);
        }
        else if(ch=='2')
        {
            cout<<"Ati apasat tasta "<<ch<<"."<<endl;
            cout<<"Citirea datelor se va face dintr-un fisier precizat!"<<endl;
            cin>>clasa;
            citire(p,u,clasa);
            cout<<"Introduceti numele unui elev: ";
            cin.get();
            cin.get(x.nume,30);
            generare_fereastra_grafica2();
            cautare_elev(p,x);
            if(ok==0)
                ///cout<<"Nu se gaseste elevul";
            {
                settextstyle(0,0,3);
                setcolor(4);
                outtextxy(100,100,"Elevul nu se gaseste in aceasta clasa!");
            }
        }
        else if(ch=='3')
        {
            cout<<"Ati apasat tasta "<<ch<<"."<<endl<<endl;
            cout<<"Citirea datelor se va face dintr-un fisier precizat!"<<endl;
            cin>>clasa;
            citire(p,u,clasa);
            generare_fereastra_grafica();
            ///cout<<"Cea mai mare medie este : "<<medie(p);
            settextstyle(0,0,2);
            setcolor(9);
            outtextxy(100,100,"Cea mai mare medie a clasei este: ");
            float y=medie(p);
            char a1[10];
            settextstyle(0,0,7);
            itoa(y,a1,10);
            outtextxy(300,200,a1);
        }
        else if(ch=='4')
        {
            cout<<"Ati apasat tasta "<<ch<<"."<<endl<<endl;
            cout<<"Citirea datelor se va face dintr-un fisier precizat!"<<endl;
            cin>>clasa;
            citire(p,u,clasa);
            generare_fereastra_grafica();
            afisare3(p);

        }
        else if(ch=='5')
        {
            cout<<"Ati apasat tasta "<<ch<<"."<<endl;
            cout<<"Citirea datelor se va face dintr-un fisier precizat!"<<endl;
            cin>>clasa;
            citire(p,u,clasa);
            ordonare_dupa_medie(p);
            generare_fereastra_grafica2();
            afisare2(p);
        }
        else if(ch=='6')
        {
            cout<<"Ati apasat tasta "<<ch<<"."<<endl;
            break;
        }
    }
}
int main()
{
    nod *p=0,*u;
    Meniu(p,u);
    return 0;
}
