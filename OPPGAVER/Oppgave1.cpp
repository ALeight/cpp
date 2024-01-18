/**
 *   Løsningsforslag til oppgave nr 17.
 *
 *   @file	  OPPG_17.C
 *   @author  Frode Haug, NTNU

 */


#include <iostream>                //  printf, scanf
#include <cctype>                  //  toupper
#include <iomanip>                 // setprecision
using namespace std;

const int MAXLOPERE = 10;         ///<  Max. antall løpere å lese tider for.

/**
 *  Hovedprogrammet:
 */
int main()  {
    int distanse,
            ant500,
            min, sek, hundr,
            antallLopere;
    float poeng;
    char  brukerSvar;

    do  {
        do  {
            cout << "\nSkriv en skøytedistanse (500, 1500, 3000, 5000):  ";
            cin >> distanse;     //  Leser en distanse.
        } while (distanse != 500   &&  distanse != 1500 &&
                 distanse != 3000  &&  distanse != 5000); // Gjentar til lovlig.

        ant500 = distanse / 500;      //  Beregner antall 500-metre i distansen.

        do  {
            cout << "\nAntall lopere to lese tider for (1-"<< MAXLOPERE<<"):";
            cin >> antallLopere;
        } while (antallLopere < 1  ||  antallLopere > MAXLOPERE);

        for (int i = 1;  i <= antallLopere;  i++)  {
            do  {
                cout << "\nTid (mm ss hh):  ";
                cin >> min >> sek >> hundr;
            } while (min < 0  ||  sek < 0  || hundr < 0);

            //  Beregner poengsummen:
            poeng =  ((min*60) + sek + (hundr/100.0)) / ant500;
            // fixed for significant numbers
            cout << fixed << setprecision(3) << "\tPoengsum:  " << poeng;       // Skriver denne, med 3 desimaler.
        }

        cout << "\n\nLese tider om en ny distanse (j/N):  ";
        cin >> brukerSvar;
        brukerSvar = toupper(brukerSvar);
    } while (brukerSvar == 'J');              //  Gjenta HELE proogrammet?

    return 0;
}