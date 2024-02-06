/*
 * Task 5 in OOPROG
 *
 * @author Bendik S. Kristoffersen
 */

#include "iostream"
#include "../EKSEMPLER/LesData2.h"
using namespace std;

const int STRLEN = 40;
const int MAXFORELESNINGER = 10;

struct Forelesning{
    char emne[STRLEN/2],
        foreleser[STRLEN],
        sted[STRLEN/2];
    int timeStart, minStart,
        timeSlutt, minSlutt;
};

void forelesningLesData(Forelesning* f);
void forelesningSkrivData(Forelesning* f);


/*
 * Main program start:
 */
int main(){
    Forelesning fl[MAXFORELESNINGER];

    for (int i = 0; i < MAXFORELESNINGER; i++){
        forelesningLesData(&fl[MAXFORELESNINGER]);
    }


    return 0;
}


/*
 * Leser inn all data om en forelesning
 */
void forelesningLesData(Forelesning* f){
    cout << "\nNavn paa emne?"; cin.getline(f->emne, STRLEN/2);
    cout << "\nHvilken foreleser?"; cin.getline(f->foreleser, STRLEN);
    cout << "\nHvilket klasserom?"; cin.getline(f->sted, STRLEN/2);
    cout << lesInt("\nTimestart?", 0, 45); cin >> f->timeStart;
    cout << lesInt("\nMinuttstart?", 0, 45); cin >> f->minStart;
    cout << lesInt("\nTimeslutt?", 0, 45); cin >> f->timeSlutt;
    cout << lesInt("\nMinuttslutt?", 0, 45); cin >> f->minSlutt;
}

// test

/*
 * Skriver ut all data om én forelesning
 *
 * @param f - struct'en som får skrevet sin data
 */
void forelesningSkrivData(Forelesning* f){
    int a[STRLEN];

    // if the input minute is singular digit, add zero in front

    forelesningLesData(&f[MAXFORELESNINGER]);
}