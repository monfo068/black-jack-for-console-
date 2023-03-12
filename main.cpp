#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <windows.h>
#include <fstream>
#include <time.h>
using namespace std;
void troppo()
{
  cout << "dottore non puo puntare piu di quanto ha, non deve diventare ludopatico!!" << endl;
}
void manouno(int gio[], int cru[])
{
  int app, app3;
  for (int i = 0; i < 2; i++)
  {
    app3 = rand() % 3;
    if (app3 == 0)
    {
      gio[i] = 10;
    }
    if ((app3 == 1) || (app3 == 2))
    {
      app = rand() % 10 + 2;
      gio[i] = app;
    }
    //
    app3 = rand() % 3;
    if (app3 == 0)
    {
      cru[i] = 10;
    }
    if ((app3 == 1) || (app3 == 2))
    {
      app = rand() % 10 + 2;
      cru[i] = app;
    }
    //
    app3 = rand() % 3;
    if (app3 == 0)
    {
      gio[i] = 10;
    }
    if ((app3 == 1) || (app3 == 2))
    {
      app = rand() % 10 + 2;
      gio[i] = app;
    }
    //
    app3 = rand() % 3;
    if (app3 == 0)
    {
      cru[i] = 10;
    }
    if ((app3 == 1) || (app3 == 2))
    {
      app = rand() % 10 + 2;
      cru[i] = app;
    }
  }
}
void mano2(int gio[],int g2[],int cru[]){
int app, app3;
  for (int i = 1; i < 3; i++)
  {
    app3 = rand() % 3;
    if (app3 == 0)
    {
      gio[i] = 10;
    }
    if ((app3 == 1) || (app3 == 2))
    {
      app = rand() % 10 + 2;
      gio[i] = app;
    }
    //
    app3 = rand() % 3;
    if (app3 == 0)
    {
      cru[i] = 10;
    }
    if ((app3 == 1) || (app3 == 2))
    {
      app = rand() % 10 + 2;
      cru[i] = app;
    }
    //
    app3 = rand() % 3;
    if (app3 == 0)
    {
      gio[i] = 10;
    }
    if ((app3 == 1) || (app3 == 2))
    {
      app = rand() % 10 + 2;
      gio[i] = app;
    }
    //
    app3 = rand() % 3;
    if (app3 == 0)
    {
      cru[i] = 10;
    }
    if ((app3 == 1) || (app3 == 2))
    {
      app = rand() % 10 + 2;
      cru[i] = app;
    }
  }
}
void blackjack(int cru[], int credit, int punt)
{
  cout << "blackjack" << endl;
  if ((cru[0] + cru[1]) == 21)
  {
    cout << endl
         << "pareggio";
  }
  else
  {
    cout << "Hai vinto" << endl;
    credit += punt + punt;
  }
}
void giocate(int gio[], int cru[], int punt, int credit, string name, string contr)
{
  int so = gio[0] + gio[1], sc = cru[0] + cru[1], controllo = 0, a = 0, app2 = 2;
  string pesca = "y";
  cout << name << " le tue carte sono " << gio[0] << " " << gio[1] << endl
       << "somma delle tue carte " << gio[0] + gio[1] << endl
       << "carta croupier " << cru[0] << endl;
  do
  {
    cout << endl
         << "vuoi pescare? scrivi [y]es o [n]ot ";
    cin >> pesca;
    if (pesca == "y")
    {
      for (int i = app2; i < app2 + 1; i++)
      {
        a = rand() % 10 + 2;
        if ((so > 21) && (a == 11))
        {
          gio[i] = 1;
        }
        else
        {
          gio[i] = a;
          so += gio[i];
        }
      }
      cout << "carte: ";
      for (int i = 0; i < app2 + 1; i++)
      {
        cout << gio[i] << " ";
      }
      cout << endl
           << "somma delle carte=" << so;
      if (so > 21)
      {
        controllo = 10;
        if (controllo == 10)
        {
          cout << endl
               << name << " hai sballato!!";
          credit -= punt;
          pesca = "n";
        }
      }    
      app2++;
    }
  } while (pesca != "n");
  if (controllo != 10)
  {
    do
    {
      sc += rand() % 10 + 2;
      cout << "il crupier ha " << sc << endl;
    } while (sc < 17);
    if (sc < 22)
    {
      if ((sc > so) || (sc == so))
      {
        cout << name << " hai perso!!";
        credit -= punt;
      }
      else
      {
        cout << name << " hai vinto!!";
        credit += punt;
      }
    }
    else
    {
      cout << name << " hai vinto!! il crupier ha sballato!! ";
      credit += punt;
    }
  }
  cout << endl
       << "vuoi continuare? scrivi [y]es o [n]ot ";
  cin >> contr;
  cout << endl
       << "hai " << credit << " fish" << endl;
}
void divisione(int gio[], int cru[], int punt, int credit, string name, string contr){
  const int  n = 10 ; 
  int g2[n];
  string vf ; 
  g2[0]=gio[1];
  gio[1]=0;
  mano2(gio,g2,cru);
  cout << "mano 1:";
  for (int i = 0 ; i<10 ; i++){
    cout << gio [ i]<<" ";
  }
  int so = gio[0] + gio[1], sc = cru[0] + cru[1], controllo = 0, a = 0, app2 = 2;
  string pesca = "y";
  do
  {
    cout << endl
         << "vuoi pescare? scrivi [y]es o [n]ot ";
    cin >> pesca;
    if (pesca == "y")
    {
      for (int i = app2; i < app2 + 1; i++)
      {
        a = rand() % 10 + 2;
        if ((so > 21) && (a == 11))
        {
          gio[i] = 1;
        }
        else
        {
          gio[i] = a;
          so += gio[i];
        }
      }
      cout << "carte: ";
      for (int i = 0; i < app2 + 1; i++)
      {
        cout << gio[i] << " ";
      }
      cout << endl
           << "somma delle carte=" << so;

      if (so > 21)
      {
        controllo = 10;
        if (controllo == 10)
        {
          cout << endl
               << name << " hai sballato!!";
          credit -= punt;
          pesca = "n";
        }
      }
      app2++;
    }
  } while (pesca != "n");
  controllo = 0;
  a = 0;
  app2 = 2;
  pesca = "y";
  cout << "mano 2:";
  for (int i = 0 ; i<10; i++){
    cout << g2[i]<<" ";
  }
  do
  {
    cout << endl
         << "vuoi pescare? scrivi [y]es o [n]ot ";
    cin >> pesca;
    if (pesca == "y")
    {
      for (int i = app2; i < app2 + 1; i++)
      {
        a = rand() % 10 + 2;
        if ((so > 21) && (a == 11))
        {
          g2[i] = 1;
        }
        else
        {
          g2[i] = a;
          so += g2[i];
        }
      }
      cout << "carte: ";
      for (int i = 0; i < app2 + 1; i++)
      {
        cout << g2[i] << " ";
      }
      cout << endl
           << "somma delle carte=" << so;

      if (so > 21)
      {
        controllo = 10;
        if (controllo == 10)
        {
          cout << endl
               << name << " hai sballato!!";
          credit -= punt;
          pesca = "n";
        }
      }
      app2++;
    }
  } while (pesca != "n");
  int apps,apps2;
  for (int i = 0 ; i < 10 ; i++){
    apps+=gio[i];
    apps2+=g2[i];
  }
    do
    {
      sc += rand() % 10 + 2;
      cout << "il crupier ha " << sc << endl;
    } while (sc < 17);
    if (sc < 22)
    {
      if ((sc > apps) || (sc == apps))
      {
        cout << name << " hai perso!! con la prima mano";
        credit -= punt;
      }
      else
      {
        cout << name << " hai vinto!!";
        credit += punt;
      }
      cout << endl ;
      if ((sc > apps2) || (sc == apps2))
      {
        cout << name << " hai perso!! con la seconda mano";
        credit -= punt;
      }
      else
      {
        cout << name << " hai vinto!!";
        credit += punt;
      }
    }
    else
    {
      cout << name << " hai vinto!! il crupier ha sballato!! ";
      credit += punt+punt;
    }
}
int main()
{
  srand(time(0)); 
  const int n = 10;
  int gio[n] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, cru[n], punt = 0, credit = 10000;
  string name, contr = "", div ="y";
  cout << "Benvenuto questo e' il gioco del BLACK-JACK come ti vuoi chiamare: ";
  cin >> name;
  cout << endl
       << "hai " << credit << " fish fanne buon uso " << endl;
  if (credit > 1)
  {
    do
    {
      do
      {
        if (punt > credit)
        {
          troppo();
        }
        cout << "quanto vuoi puntare: ";
        cin >> punt;
      } while (punt > credit);
      manouno(gio, cru);
      if ((gio[0] + gio[1]) == 21)
      {
        blackjack(cru, credit, punt);
      }
      if (gio[0]==gio[1]){
        cout << "vuoi dividere? [y]es o [n]o ";
        cin >> div ; 
        if (div == "y"){
          credit-=punt;
          divisione(gio, cru, punt, credit, name, contr);
        }
      }
      if (((gio[0] + gio[1]) != 21)||(div!="y"))
      {
        giocate(gio, cru, punt, credit, name, contr);
      }
    } while (contr != "n");
  }
  return 0;
}