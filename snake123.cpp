#include<iostream>
#include<windows.h>
#include<fstream>

#include<deque>
#include<conio.h>
#include <time.h>
#include <string>
#include <cstdlib>
#include <ctime>

#include<vector>
#include <locale.h>
#include <windows.h>
#include<deque>
#include <time.h>


#define szer 70
#define wysokosc 25

using namespace std;
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);//kolor
COORD c;

time_t usuwa_t=clock(),usuwa_delay=8000;//czas po jakim ma usuwac trutke
size_t l    ;
bool b,p;
int k;

 enum bonu{wzrost,trutka};//wyliczenia bonusow

void wypiszlista()//nie uzyte
{cout<<"Lista top 10:"<<endl;
ifstream cos("top10.txt");
int i=1,y;
string x;

while(cos>>x>>y)
{
    cout<<i<<")"<<x<<" "<<y<<endl;
i++;
}
system("pause");
}




void xoy(char x,char y)//ustawia kursor
{
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(h,c);
}
class snake{
    public:
     time_t snake_t,snake_delay;//predkosc weza
     deque<char>x,y;//wspolrzedne weza
     int rozmiar;
     int kolor;
     enum Ruch{gora,prawo,dol,lewo}ruch;//kierunki poruszania sie
     void koniecgry();
     void zakonczenie();
};
class bonus{
    public:
    time_t bonus_t,bonus_delay;//czas powstawania bonusow

    deque<char>bonusX,bonusY;//wspolrzedne bonusu
    deque<bonu>bonus;//rodzaj bonusu
    vector <int>rodzaj;
    void koniecgry2();
    void usun(int ktory);

};
void bonus::usun(int ktory)//usuwa bonus by nie dzialal juz
        {
         rodzaj.erase(rodzaj.begin()+ktory);
        bonusX.erase(bonusX.begin()+ktory);
        bonusY.erase(bonusY.begin()+ktory);
        bonus.erase(bonus.begin()+ktory);

        }
void bonus::koniecgry2()//zeruje wartosci by mozna bylo na nowo grac
{bonus_t =clock();
bonus_delay=1500;
      bonusX.clear();
        bonusY.clear();
        bonus.clear();

}
void snake::koniecgry()//zeruje wartosci pozwala wybrac kolor
{int i;
    system("cls");

{k=0;
     while(k!=1 or k!=2 or k!=3 or k!=4 or k!=5 or k!=6 or k!=7 or k!=8 or k!=9 or k!=10 or k!=11 or k!=12 or k!=13 or k!=14 or k!=15)//sprawdza czy wybrano z dostepnych czy sie pomylono
    {cout<<"wybierz kolor weza"<<endl;
   SetConsoleTextAttribute(h,1);
    cout<<"1-granat"<<endl;
    SetConsoleTextAttribute(h,2);
cout<<"2-ciemny zielony"<<endl;
SetConsoleTextAttribute(h,3);
cout<<"3-turkus"<<endl;
SetConsoleTextAttribute(h,4);
cout<<"4-ciemno czerwony"<<endl;
SetConsoleTextAttribute(h,5);
cout<<"5-fiolet"<<endl;
SetConsoleTextAttribute(h,6);
cout<<"6-oliwkowy"<<endl;
SetConsoleTextAttribute(h,7);
cout<<"7-jasno szary"<<endl;
SetConsoleTextAttribute(h,8);
cout<<"8 szary"<<endl;
SetConsoleTextAttribute(h,9);
cout<<"9-niebieski"<<endl;
SetConsoleTextAttribute(h,10);
cout<<"10-zielony"<<endl;
SetConsoleTextAttribute(h,11);
cout<<"11-jasno niebieski"<<endl;
SetConsoleTextAttribute(h,12);
cout<<"12-czerwony"<<endl;
SetConsoleTextAttribute(h,13);
cout<<"13-magneta"<<endl;
SetConsoleTextAttribute(h,14);
cout<<"14-zolty"<<endl;
SetConsoleTextAttribute(h,15);
cout<<"15-bialy"<<endl;
    cin>>k;
    if(k==1 or k==2 or k==3 or k==4 or k==5 or k==6 or k==7 or k==8 or k==9 or k==10 or k==11 or k==12 or k==13 or k==14 or k==15)
        break;
        else{
        cin.clear();//zeruje cin zeby byl pusty
cin.ignore();
        }
    }
    system("cls");


 snake_t=clock();
    snake_delay=75;//predkosc weza

    kolor=k;
    rozmiar=1;
    ruch=gora;
    p=0;
    system("cls");
    SetConsoleTextAttribute(h,10);

    for(i=-1;i<szer;i++)//wypisuja plansze
        cout<<(char)219;
        cout<<endl;
        for(i=0;i<=wysokosc;i++)
        {cout<<(char)219;
        xoy(szer+1,i);
        cout<<(char)219<<endl;}
        for(i=-2;i<szer;i++)
        cout<<(char)219;

        x.clear();
        y.clear();



        x.push_front(szer/2);
        y.push_front(wysokosc/2);
        xoy(x.front(),y.front());
        cout<<(char)219;}

        }
    void snake::zakonczenie()
    {
        cout<<"GAME-OVER"<<endl;
        cout<<"twoj wynik to:"<<endl;
        cout<<x.size()<<endl;
        int h;
        h=x.size();

        int v=0,i,min,w=0;
        string x,n;
        int y;
        int t[10]{};
        string t1[10];
        ifstream lista("top10.txt");

        while(lista>>x>>y)//wpisuje z pliku do tabeli
        {t[v]=y;
        t1[v]=x;
        v++;

        }
        for(i=0;i<10;i++)
        {
            if(h>t[i])//sprawdza na ktora pozycje wrzucic nasz wynik
                w++;
        }

        if(w>0)
        {
            cout<<"Dostales sie do 10 najlepszych graczy podaj swoja nazwe!!!"<<endl;
            cin>>n;

        for(i=0;i<w-1;i++)
        {t[9-i]=t[8-i];
         t1[9-i]=t1[8-i];

        }//przestawia wiersze z wynikami
        t[10-w]=h;
        t1[10-w]=n;
    ofstream zap("top10.txt");
for(i=0;i<10;i++)
{
    zap<<t1[i];
    zap<<" "<<t[i]<<endl;//wpisuje do pliku

    cout<<i+1<<")"<<t1[i]<<" ";
    cout<<t[i]<<endl;
}



    }cout<<"nacisnij dowolny przycisk by powrocic do menu"<<endl;
    getch();}

void zapiszlista()
{

}


int main()
{
   poczatek:
    snake wonsz;
    system("cls");
    srand(time(NULL));
    fstream plik;
    string pom1,nick[10];
    char wybor;
    long long int wyniki[10];
    int i{},pom2,z=0,p=true;

    plik.open("top10.txt",ios::in);
    while(plik>>pom1>>pom2)
    {
        nick[i]=pom1;
        wyniki[i]=pom2;
        i++;
    }

    plik.close();

    while(p=true)
    {
    cout<<"|||||| ||   ||  ||||  ||  || ||||"<<endl;  //Wyswietlane menu
    cout<<"||     |||  || ||  || || ||  ||"<<endl;  //Wyswietlane menu
    cout<<"  ||   || | || |||||| ||||   ||||"<<endl;   //Wyswietlane menu
    cout<<"    || ||  ||| ||  || || ||  ||"<<endl;  //Wyswietlane menu
    cout<<"|||||| ||   || ||  || ||  || ||||"<<endl;  //Wyswietlane menu


    cout<<endl<<endl<<"1) Start"<<endl;  //Wyswietlane menu
    cout<<"2) Instrukcja"<<endl;  //Wyswietlane menu
    cout<<"3) Tabela wynikow"<<endl;  //Wyswietlane menu
    cout<<"4) Wyjdz z gry"<<endl<<endl;  //Wyswietlane menu

    cin>>wybor;

    switch(wybor)//wybiera co ma zrobic
    {
    case'1':
        system("cls");
        z++;
        break;
    case'2':
        system("cls");
        cout<<"Witaj w grze snake. W naszej grze chodzi o to aby zbierac niebieskie $ by zdobywac PKT, a"<<endl;
        cout<<"czerwonych unikac aby pozostac jak najdluzej w grze.Poruszasz sie przy pomocy w,s,a,d wraz z wzrostem snake'a wzrasta jego predkosc"<<endl<<"Zyczymy milej zabawy i powodzenia :)"<<endl<<endl;
        cout<<"Aby wrocic do menu kliknij dowolny klawisz";
        getch();
        system("cls");
        break;
    case'3':
        system("cls");
        cout<<"Tablica wynikow :"<<endl<<endl;
        for(i=0;i<10;i++)
            cout<<i+1<<"\t"<<nick[i]<<"\t"<<wyniki[i]<<" PKT"<<endl;

        cout<<endl<<endl<<"Aby wrocic do menu kliknij dowolny klawisz";
        getch();
        system("cls");
        break;
    case'4':
        system("cls");
        cout<<"Dziekujemy za skorzystanie z naszej gry i zapraszamy ponownie :D"<<endl<<endl<<endl;
        cout<<"Created by : Michal Rojczyk & Dominik Mas"<<endl;
        exit(0);
        break;
    default:
        system("cls");
        continue;
        break;

    }
    if(z!=0)//ma wyskoczyc by wlaczyc gre
        break;
    }

k=0;
     while(k!=1 or k!=2 or k!=3 or k!=4 or k!=5 or k!=6 or k!=7 or k!=8 or k!=9 or k!=10 or k!=11 or k!=12 or k!=13 or k!=14 or k!=15)
    {cout<<"wybierz kolor weza"<<endl;
   SetConsoleTextAttribute(h,1);
    cout<<"1-granat"<<endl;
    SetConsoleTextAttribute(h,2);
cout<<"2-ciemny zielony"<<endl;
SetConsoleTextAttribute(h,3);
cout<<"3-turkus"<<endl;
SetConsoleTextAttribute(h,4);
cout<<"4-ciemno czerwony"<<endl;
SetConsoleTextAttribute(h,5);
cout<<"5-fiolet"<<endl;
SetConsoleTextAttribute(h,6);
cout<<"6-oliwkowy"<<endl;
SetConsoleTextAttribute(h,7);
cout<<"7-jasno szary"<<endl;
SetConsoleTextAttribute(h,8);
cout<<"8 szary"<<endl;
SetConsoleTextAttribute(h,9);
cout<<"9-niebieski"<<endl;
SetConsoleTextAttribute(h,10);
cout<<"10-zielony"<<endl;
SetConsoleTextAttribute(h,11);
cout<<"11-jasno niebieski"<<endl;
SetConsoleTextAttribute(h,12);
cout<<"12-czerwony"<<endl;
SetConsoleTextAttribute(h,13);
cout<<"13-magneta"<<endl;
SetConsoleTextAttribute(h,14);
cout<<"14-zolty"<<endl;
SetConsoleTextAttribute(h,15);
cout<<"15-bialy"<<endl;
    cin>>k;
    if(k==1 or k==2 or k==3 or k==4 or k==5 or k==6 or k==7 or k==8 or k==9 or k==10 or k==11 or k==12 or k==13 or k==14 or k==15)
        break;
        else{
        cin.clear();
cin.ignore();
system("cls");
        }
    }
    system("cls");


 wonsz.snake_t=clock();
    wonsz.snake_delay=75;

    wonsz.kolor=k;
    wonsz.rozmiar=1;
    wonsz.ruch=wonsz.gora;
    p=0;
    system("cls");
    SetConsoleTextAttribute(h,10);

    for(i=-1;i<szer;i++)//wypisuje plANSZE
        cout<<(char)219;
        cout<<endl;
        for(i=0;i<=wysokosc;i++)
        {cout<<(char)219;
        xoy(szer+1,i);
        cout<<(char)219<<endl;}
        for(i=-2;i<szer;i++)
        cout<<(char)219;

        wonsz.x.clear();
        wonsz.y.clear();



        wonsz.x.push_front(szer/2);
        wonsz.y.push_front(wysokosc/2);
        xoy(wonsz.x.front(),wonsz.y.front());
        cout<<(char)219;









    srand(time(NULL));
    int f=0,oooo,bb=0;
i=0;

bonus bn;//tworzy obiekt

   bn.koniecgry2();//zeruje wartosci


start:


    if(kbhit())
    {
        switch(getch())
    {case 'P':
        case 'p':
        if(p)
            p=0;
        else
            p=1;
        case 'W':
    case 'w':
        if(wonsz.ruch!=wonsz.dol)//sprawdza by nie poruszac sie w przecwina strone
            wonsz.ruch=wonsz.gora;
        break;
          case 'S':
    case 's':
        if(wonsz.ruch!=wonsz.gora)
            wonsz.ruch=wonsz.dol;
        break;
          case 'A':
    case 'a':
        if(wonsz.ruch!=wonsz.prawo)
            wonsz.ruch=wonsz.lewo;
        break;
          case 'D':
    case 'd':
        if(wonsz.ruch!=wonsz.lewo)
            wonsz.ruch=wonsz.prawo;
        break;
    }}
    if(p)//pauzuje
        goto start;
    if(clock()-wonsz.snake_t>wonsz.snake_delay)
    {wonsz.snake_t=clock();
        wonsz.x.push_front(wonsz.x.front());
wonsz.y.push_front(wonsz.y.front());
switch(wonsz.ruch)//sterowanie wenzem
{
    case wonsz.gora:
    wonsz.y.front()--;
    break;
      case wonsz.dol:
    wonsz.y.front()++;
    break;
      case wonsz.prawo:
    wonsz.x.front()++;
    break;
      case wonsz.lewo:
    wonsz.x.front()--;
    break;
}
for(i=4;i<wonsz.x.size();i++)
{
    if(wonsz.x.front()==wonsz.x[i] and wonsz.y.front()==wonsz.y[i])//sprawdza czy waz sie nie zjadl
         {
system("cls");
wonsz.zakonczenie();
        system("pause");

    bn.koniecgry2();
    goto poczatek;

   }
}
if(wonsz.x.front()==0 || wonsz.x.front()==szer+1 || wonsz.y.front()==0 || wonsz.y.front()==wysokosc+1)//sprawdza czy nie wjedzie w sciane
   {
    system("cls");
    wonsz.zakonczenie();


    bn.koniecgry2();
    goto poczatek;
}


    SetConsoleTextAttribute(h,k);
xoy(wonsz.x.front(),wonsz.y.front());//ustawia kursor
cout<<(char)219;
SetConsoleTextAttribute(h,15);
xoy(0,wysokosc+2);
cout<<"dlugosc twojego wonsza to:    "<<wonsz.x.size()<<"           ";//wypisuje dlugosc weza

l=bn.bonus.size();
b=false;
   for(size_t i=0;i<l;++i)
            {
                if(wonsz.x.front()==bn.bonusX[i]&&wonsz.y.front()==bn.bonusY[i])//sprawdza czy wonsz zjadl bonusa
                    {
                               switch(bn.bonus[i])
                               {
                                   case wzrost:


                                   b=true;
                                   bn.usun(i);//usuwa bonus
                                   break;

                                    case trutka:
                                     system("cls");
                                wonsz.zakonczenie();//konczy gre
                                    system("pause");

                                     bn.koniecgry2();
                                     goto poczatek;

                                    break;
                               }

                               }
                               //bn.bonusX[i]=bn.bonusX.front();
                               //bn.bonusY[i]=bn.bonusY.front();
                               //bn.bonusX.pop_front();
                               //bn.bonusY.pop_front();
                    }
            if(b!=true)//waz zjadl pokarm i rosnie
            {
                xoy(wonsz.x.back(),wonsz.y.back());
                cout<< (char) 32;//powoduje wrazenie ze waz sie porusza poniewaz zamazuje tam gdzie waz byl wczesniej
                wonsz.x.pop_back();
                wonsz.y.pop_back();


    wonsz.snake_delay=75-2*wonsz.x.size();//zwieksza predkosc weza
                wonsz.rozmiar++;
            }}
int ccc=0;
if(clock() - usuwa_t>usuwa_delay)
        {usuwa_t=clock();

         l=bn.bonus.size();
                  for(time_t i=1;i<l;++i)
                  {
                      if(bn.bonus[i]==1)//sprawdza czy na indeksie i-tym jest trutka
                  {


                  xoy(bn.bonusX[i],bn.bonusY[i]);
                  cout<<(char) 32;//zamazuje znaczek
               bn.usun(i);//usuwa bonus
                       break;
                  }}


                  }



    if(clock() - bn.bonus_t>bn.bonus_delay)//czas pojawiania sie bonusu
        {bn.bonus_t=clock();

            //oooo=rand()%100;
            if(bb<2)//sprawdza ile stworzylo pokarmow
                oooo=0;
            else//tworzy trutke
                oooo=1;
        if(oooo==0)
            bb++;
        if(oooo==1)
            bb=0;
            bn.bonus.push_front(bonu(oooo));

            bn.bonusX.push_front(rand()%szer+1);
         bn.bonusY.push_front(rand()%wysokosc+1);//wybiera wspolrzedne bonusu



             point:

              l=bn.bonus.size();
                  for(size_t i=1;i<1;++i)
            {
                if(bn.bonusX.front()==bn.bonusX[i]&&bn.bonusY.front()==bn.bonusY[i])
                    {
                                bn.bonusX.front()=rand()%szer+1;
                                bn.bonusY.front()=rand()%wysokosc+1;//sprawdza  by ine stworzyc bonusu w miejsce juz istniejacego

                    goto point;}
            }




         l=wonsz.x.size();
               for(size_t i=0;i<l;i++)
            {
                if(bn.bonusX.front()==wonsz.x[i]&&bn.bonusY.front()==wonsz.y[i])//sprawdza by nie stworzono bonusu tam gdzie jest waz
                    {
                                bn.bonusX.front()=rand()%szer+1;
                                bn.bonusY.front()=rand()%wysokosc+1;

                    goto point;
                    }
            }
 xoy(bn.bonusX.front(),bn.bonusY.front());
    switch(bn.bonus.front())
        {
            case wzrost:
                SetConsoleTextAttribute(h,11);
                bn.rodzaj.push_back(1);//daje odpowiednie kolor bonusu w zaleznosci od rodzaju
                b=false;
                break;

            case trutka:

                SetConsoleTextAttribute(h,12);
                bn.rodzaj.push_back(0);

                break;
        }




        cout<<'$';






        }


goto start;//wraca do poczatku
}
