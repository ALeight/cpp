/**
 * Week 1 Task 2.
 */

#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;


const int MINTEMP   = -70;   ///<  Absolutt laveste mulige temperatur.
const int MAXTEMP   =  70;   ///<  Absolutt høyeste mulige temperatur.
const int MAXNEDBOR = 200;   ///<  Absolutt høyeste mulige nedbør pr.døgn.
const int MINDAGER  =   5;   ///<  Minimum antall dager i en måned.
const int MAXDAGER  =  31;   ///<  Maksimum antall dager i en måned.

/**
 *  Hovedprogrammet:
 */
int main ()  {
    char svar;
    int  antDager = 0,
            min,
            max,
            nedbor,
            totMin = 0,
            totMax = 0,
            totNedbor = 0,
            mestNedbor = -1,
            nedborDag = 0;


    cout << "\nLese inn vêrdata for en maaned (J/n): ";
    cin >> svar;
    svar = toupper(svar);

    while (svar != 'N') {
        do {
            cout << "Antall dager i maaneden ( "<<MINDAGER<< "-" <<MAXDAGER<<" )";
            cin >> antDager;
        } while (antDager < MINDAGER  ||  antDager > MAXDAGER);

        for (int i = 0;  i <= antDager;  i++)  {
            cout <<"\nDag nr" << setw(2) << i <<":\n";

            do {
                cout <<"\tMinimumstemp ("<< setw(2) << MINTEMP <<
                        " til "<< setw(2) << MAXTEMP <<"): ";
                cin >> min;
            } while(min < MINTEMP ||  min > MAXTEMP);
            totMin += min;

            do {
                cout <<"\tMaksimumstemp ("<< setw(2) << MINTEMP <<
                        " til "<< setw(2) << MAXTEMP <<"): ";
                cin >> max;
            } while(max < min  ||  max > MAXTEMP);
            totMax += max;

            do {
                cout <<"\tNedbor (0 til "<<MAXNEDBOR<<"): ";
                cin >> nedbor;
            } while(nedbor < 0  ||  nedbor > MAXNEDBOR);
            totNedbor += nedbor;

            if (nedbor > mestNedbor){
                mestNedbor = nedbor;
                nedborDag = i;
            }
        }


        cout << fixed << setprecision(2) <<
                "\n\nGjennomsnittlig min.temp: "<<(float)totMin/antDager<<" grader C\n";
        cout << fixed << setprecision(2) <<
                "Gjennomsnittlig max.temp: "<<(float)totMax/antDager<<" grader C\n";
        cout << fixed << setprecision(2) <<
                "Gjennomsnittlig nedbør: "<<(float)totNedbor/antDager<<" mm\n";
        cout << fixed << setprecision(2) <<
                "Total nedbør i måneden:   "<<totNedbor<<" mm\n";

        cout <<"\nLese inn værdata for en måned til (J/n): ";
        cin >> svar;
        svar = toupper(svar);
    }

    cout <<"\n\n\nHa en fortsatt god (vêr(syk))dag!\n\n";

    return 0;
}