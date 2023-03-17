#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
// ora devo verificare la funzionalita' della divisione poi verificare che il programma sia coerente e inserire allegro(grand rottura di scatole)
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
void mano2(int gio[], int g2[], int cru[])
{
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
void blackjack(int cru[], int &credit, int &punt, string &contr)
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
  cout << endl
       << "vuoi continuare? scrivi [y]es o [n]ot ";
  cin >> contr;
  cout << endl
       << "hai " << credit << " fish" << endl;
}
void giocate(int gio[], int cru[], int &punt, int &credit, string name, string &contr)
{
  int so = gio[0] + gio[1], sc = cru[0] + cru[1], controllo = 0, a = 0, app2 = 2, mae = 0, yu = 0;
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
    cout << "crupier mano:";
    for (int i = 0; i < 2; i++)
    {
      cout << cru[i] << " ";
    }
    cout << endl;
    do
    {

      yu = 2;
      mae = rand() % 10 + 2;
      cru[yu] = mae;
      sc += mae;
      cru[yu] = mae;
      cout << "mano crupier:";
      for (int i = 0; i < 10; i++)
      {
        if (cru[i] != 0)
        {
          cout << cru[i] << " ";
        }
      }
      yu++;
      cout << "il crupier ha " << sc << endl;
      for (int i = 0; i < 10; i++)
      {
        if (sc > 22)
        {
          if (cru[i] == 11)
          {
            cru[i] = 1;
          }
        }
      }
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
void divisione(int gio[], int cru[], int &punt, int &credit, string name, string contr)
{
  const int n = 10;
  int gio2[n] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, app = 0, app2 = 0, app3 = 2, app4 = 2, so = 0, so2 = 0, sc = 0, yu = 0, mae = 0, it = 0;
  string scelta = " ", scelta2 = " ";
  gio2[0] = gio[1];
  gio[1] = 0;
  app = rand() % 3;
  if (app == 0)
  {
    app2 = rand() % 10 + 2;
    gio[1] = app2;
  }
  if ((app == 1) || (app == 2))
  {
    gio[1] = 10;
  }
  app = rand() % 3;
  if (app == 0)
  {
    app2 = rand() % 10 + 2;
    gio2[1] = app2;
  }
  if ((app == 1) || (app == 2))
  {
    gio2[1] = 10;
  }
  so = gio[0] + gio[1];
  so2 = gio2[0] + gio2[1];
  do
  {
    cout << "mano 1:";
    for (int i = 0; i < 10; i++)
    {
      if (gio[i] != 0)
      {
        cout << gio[i] << " ";
      }
    }
    cout << " somma=" << gio[0] + gio[1] << endl;
    cout << "mano 1 vuoi pescare? scrivi [y]es o [n]ot: ";
    cin >> scelta;
    if (scelta != "n")
    {
      app = rand() % 3;
      if (app == 0)
      {
        app2 = rand() % 10 + 2;
        gio[app3] = app2;
        so += app2;
      }
      if ((app == 1) || (app == 2))
      {
        gio[app3] = 10;
        so += 10;
      }
    }
    app3++;
  } while ((scelta != "n") && (so < 22));
  if (so > 21)
  {
    cout << "hai sballato con la prima mano" << endl;
  }
  do
  {
    cout << "mano 2:";
    for (int i = 0; i < 10; i++)
    {
      if (gio2[i] != 0)
      {
        cout << gio2[i] << " ";
      }
    }
    cout << " somma=" << gio2[0] + gio2[1] << endl;
    cout << "mano 2 vuoi pescare? scrivi [y]es o [n]ot: ";
    cin >> scelta2;
    if (scelta != "n")
    {
      app = rand() % 3;
      if (app == 0)
      {
        app2 = rand() % 10 + 2;
        gio2[app4] = app2;
        so2 += app2;
      }
      if ((app == 1) || (app == 2))
      {
        gio2[app4] = 10;
        so2 += 10;
      }
    }
    app4++;
  } while ((scelta2 != "n") && (so2 < 22));
  if (so2 > 21)
  {
    cout << "hai sballato con la seconda mano" << endl;
  }
  if ((so > 21) && (so2 > 21))
  {
    cout << "hai sballato con entrabbe le mani" << endl;
  }
  if (so < 22)
  {
    cout << "crupier mano:";
    for (int i = 0; i < 2; i++)
    {
      cout << cru[i] << " ";
    }
    cout << endl;
    do
    {
      yu = 2;
      mae = rand() % 10 + 2;
      cru[yu] = mae;
      sc += mae;
      cru[yu] = mae;
      cout << "mano crupier:";
      for (int i = 0; i < 10; i++)
      {
        if (cru[i] != 0)
        {
          cout << cru[i] << " ";
        }
      }
      yu++;
      cout << "il crupier ha " << sc << endl;
    } while (sc < 17);
    if (sc < 22)
    {
      if ((sc > so) || (sc == so))
      {
        cout << name << " hai perso!! con la prima mano ";
        credit -= punt;
      }
      else
      {
        cout << name << " hai vinto!! con la prima mano ";
        credit += punt;
      }
    }
    else
    {
      cout << name << " hai vinto con la prima mano!! il crupier ha sballato!!";
      credit += punt;
      it++;
    }
  }
  if (so2 < 22)
  {
    if (sc < 22)
    {
      if ((sc > so2) || (sc == so2))
      {
        cout << name << " hai perso!! con la seconda mano ";
        credit -= punt;
      }
      else
      {
        cout << name << " hai vinto!! con la seconda mano ";
        credit += punt;
      }
    }
    if (it == 1)
    {
      cout << name << " hai vinto con la seconda mano!!  il crupier ha sballato!!";
      credit += punt;
    }
  }
  cout << endl
       << "vuoi continuare? scrivi [y]es o [n]ot ";
  cin >> contr;
  cout << endl
       << "hai " << credit << " fish" << endl;
}
void reg()
{
  srand(time(0));
  const int n = 10;
  int gio[n] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, cru[n] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, punt = 0, credit = 10000;
  string name, contr = "", div = "y";
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
        blackjack(cru, credit, punt, contr);
      }
      if (gio[0] == gio[1])
      {
        cout << gio[0] << " " << gio[1] << endl
             << "somma carte=" << gio[0] + gio[1] << endl;
        cout << "vuoi dividere? [y]es o [n]o ";
        cin >> div;
        if (div == "y")
        {
          credit -= punt;
          divisione(gio, cru, punt, credit, name, contr);
        }
      }
      if (((gio[0] + gio[1]) != 21) || (div != "y"))
      {
        giocate(gio, cru, punt, credit, name, contr);
      }
    } while (contr != "n");
  }
}
void regole()
{
  system("start www.pokerstars.it/casino/how-to-play/blackjack/rules");
}
int main()
{
  int a = 0;
  cout << "1 GIOCA " << endl
       << "2 REGOLE" << endl;
  do
  {
    cin >> a;
  } while ((a != 1) && (a != 2));
  if (a == 1)
  {
    reg();
  }
  if (a == 2)
  {
    regole();
    cout << "Ora sei pronto a giocare" << endl;
    reg();
  }
  return 0;
}
