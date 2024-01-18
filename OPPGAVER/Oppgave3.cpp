/**
* Task 3 in OOPROG
 *
 * @author Bendik S. Kristoffersen
*/


#include "iostream"     // input, output
#include "iomanip"      // fixed, setprecision
#include "LesData2.h"    // Frode's header
using namespace std;


const int MINTEMP = -70;
const int MAXTEMP = 70;
const int MAXNEDBOR = 200;
const int MINDAGER = 28;
const int MAXDAGER = 31;


float gjennomsnitt(const int v1, const int v2);
int lesInt(const char t[], const int min, const int max);

/**
 * Main program start:
 */
int main(){
    char svar;
    int antDager,
        min,
        max,
        nedbor,
        totMin,
        totMax,
        totNedbor,
        mestNedbor,
        nedborDag;

    svar = lesInt("\nLese inn data for maaned", 0, 1);

    while (svar == 1){
        antDager = lesInt("\nAntall dager i maaneden", MINDAGER, MAXDAGER);

        totMin = totMax = totNedbor = 0;    // Have to initialize
        mestNedbor = -1; nedborDag = 0;     // so they don't output rubbish

        for (int i = 1; i <= antDager; i++){
            cout << "\nDag nr." << setw(2) << i << ":\n";

            min = lesInt("Maksimumtemp", MINTEMP, MAXTEMP);
            totMin += min;

            totMax += lesInt("Maksimumtemp", min, MAXTEMP);

            nedbor = lesInt("Nedbor", 0, MAXNEDBOR);
            totNedbor += nedbor;

            if (nedbor > mestNedbor){   // Funnet dag med mest nedbør
                mestNedbor = nedbor;
                nedborDag = i;
            }
        }

        cout << "\nGjennomsnittlig minste temp: "
             << gjennomsnitt(totMin, totMax) << " grader C\n";
        cout << "\nGjennomsnittlig maks temp: "
             << gjennomsnitt(totMax, antDager) << " grader C\n";
        cout << "\nGjennomsnittlig nedbor: " << gjennomsnitt(totNedbor, antDager)
             << " mm\n";
        cout << "\nTotalt nedbor: " << setw(2) << totNedbor << " mm\n";
        cout << "\nMest nedbor dag nr: " << nedborDag << "med " << mestNedbor << " mm\n";

        svar = lesInt("Run program again", 0, 1);
    }

    cout << "Ha en fortsatt fin veeerdag!";

    return 0;
}

/**
 *
 * @param v1 - numerator
 * @param v2 - denominator
 * @return   - float value of v1 / v2
 */
float gjennomsnitt(const int v1, const int v2){
    return (static_cast <float> (v1) / v2);
}

