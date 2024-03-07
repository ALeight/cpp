/**
 *   Skjelett for obligatorisk oppgave nr 3 i PROG1003 - OOP.
 *
 *   Programmet inneholder en oversikt over studenter og ansatt på en skole.
 *   Disse er identifisert via sitt UNIKE student-/ansattnummer,
 *   og alle ligger lagret i EN <map>. Brukeren/programmet kan:
 *       - se ALLE personene som er lagret i datastrukturen (map'en)
 *       - legge inn en ny student/ansatt
 *       - endre data om en gitt student/ansatt
 *       - HELE datastrukturen leses fra/skrives til fil
 *
 *   @file    OBLIG3.TPL
 *   @author  Frode Haug, NTNU
 */


#include <iostream>                //  cout, cin
#include <fstream>                 //  ifstream, ofstream
#include <string>
#include <map>
#include "LesData2.h"              //  Verktøykasse for lesing av diverse data
using namespace std;


/**
 *  Person (med navn).
 */
class Person {
private:
    string navn;
public:
    Person()  {  navn = "";  }
    Person(ifstream & inn);
    virtual void endreData() = 0;
    virtual void lesData();
    virtual void skrivData() const;
    virtual void skrivTilFil(ofstream & ut) const;
};


/**
 *  Student (med studieprogram/klasse og antall studiepoeng).
 */
class Student : public Person {
private:
    string studieprogram;
    float  stp;
public:
    Student()  {  studieprogram = "";  stp = 0.0F;  }
    Student(ifstream & inn);
    virtual void endreData();
    virtual void lesData();
    virtual void skrivData() const;
    virtual void skrivTilFil(ofstream & ut) const;
};


/**
 *  Ansatt (med rom-/kontornummer og årslønn).
 */
class Ansatt : public Person {
private:
    string rom;
    int    lonn;
public:
    Ansatt()  {  rom = "";  lonn = 0;  }
    Ansatt(ifstream & inn);
    virtual void endreData();
    virtual void lesData();
    virtual void skrivData() const;
    virtual void skrivTilFil(ofstream & ut) const;
};


void endreEnPerson();
void lesFraFil();
void nyPerson();
void skrivAllePersoner();
void skrivMeny();
void skrivTilFil();


map <int, Person*> gPersoner;      ///<  Datastrukturen med alle personene.


/**
 *  Hovedprogrammet:
 */
int main(void)  {
    char kommando;

    lesFraFil();

    skrivMeny();
    kommando = lesChar("Kommando");

    while (kommando != 'Q') {
        switch (kommando) {
            case 'N':  nyPerson();               break;
            case 'A':  skrivAllePersoner();      break;
            case 'E':  endreEnPerson();          break;
            default:   skrivMeny();              break;
        }
        kommando = lesChar("Kommando");
    }

    skrivTilFil();

    return 0;
}


// ---------------------------------------------------------------------------
//                       DEFINISJON AV KLASSE-FUNKSJONER:
// ---------------------------------------------------------------------------

/**
 *  Leser navnet fra fil.
 *
 *  @param   inn  - Filobjektet egne data leses inn fra
 */
Person::Person(ifstream & inn) {
    getline(inn, navn);
}


/**
 *  Leser navnet fra brukeren/tastaturet.
 */
void Person::lesData() {
    cout << "\nNavn på person ";
    getline(cin, navn);
}


/**
 *  Skriver ut navnet til/på skjermen.
 */
void Person::skrivData() const {
    cout << navn << "\n";
}


/**
 *  Skriver ut navnet til fil.
 *
 *  @param   ut  - Filobjektet egne data skrives ut til
 */
void Person::skrivTilFil(ofstream & ut) const {
    ut << navn;
}


// ---------------------------------------------------------------------------

/**
 *  Leser studiepoeng og studieprogram/klasse fra fil.
 *
 *  @param   inn  - Filobjektet egne data leses inn fra
 */
Student::Student(ifstream & inn) : Person(inn) {
    getline(inn, studieprogram);
    inn >> stp; inn.ignore();
}


/**
 *  Tilbyr brukren å endre på alle egne data.
 *
 *  @see  skrivData()
 */
void Student::endreData() {
    char ch;

    if ((ch=lesChar("j/N")) == 'J') {
        getline(cin, studieprogram);
        cin >> stp; cin.ignore();
    } else
        cout << "Avbryter.\n\n";
}


/**
 *  Leser baseklassens data, studieprogram/klasse og studiepoeng fra brukeren.
 *
 *  @see   Person::lesData()
 */
void Student::lesData() {
    Person::lesData();
    cout << "\nStudieprogram "; getline(cin, studieprogram);
    cout << "\nAntall studiepoeng "; cin >> stp;
    cin.ignore();
}


/**
 *  Skriver baseklassens data, studieproram/klasse og studiepoeng til skjerm.
 *
 *  @see  Person::skrivData()
 */
void Student::skrivData() const {
    Person::skrivData();
    cout << studieprogram << ": " << stp << " poeng.\n";
}


/**
 *  Skriver 'S', baseklassens data, studiepoeng og studieprogram til fil.
 *
 *  @param   ut  - Filobjektet egne data skrives ut til
 *  @see     Person::skrivTilTil(...)
 */
void Student::skrivTilFil(ofstream & ut) const {
    ut << "S";
    Person::skrivData();
    ut << stp << " " << studieprogram;
}


// ---------------------------------------------------------------------------

/**
 *  Leser årslønn og rom/kontor fra fil.
 *
 *  @param   inn  - Filobjektet egne data leses inn fra
 */
Ansatt::Ansatt(ifstream & inn) : Person(inn) {
    inn >> lonn; inn.ignore();
    getline(inn, rom);
}


/**
 *  Tilbyr brukeren å endre på alle egne data.
 *
 *  @see  skrivData()
 */
void Ansatt::endreData() {
    char sj;

    // Tolket denne som at brukeren, hvis ja, får endret på alle data
    // uten å velge hvilke av de to som ønskes
    if ((sj=lesChar("Ønsker du å endre data (j/N)?")) == 'J'){
        cout << "Nytt rom "; getline(cin, rom);
        cout << "Endring i årslønn "; cin >> lonn; cin.ignore();
    }
}


/**
 *  Leser baseklassens data, rom/kontor og årslønn fra brukeren.
 *
 *  @see   Person::lesData()
 */
void Ansatt::lesData() {
    Person::lesData();
    cout << "\nHvilket rom "; getline(cin, rom);
    cout << "\nÅrslønn "; cin >> lonn;
}


/**
 *  Skriver baseklassens data, rom/kontor og årslønn til/på skjermen.
 *
 *  @see  Person::skrivData()
 */
void Ansatt::skrivData() const {
    Person::skrivData();
    cout << rom << " " << lonn;
}


/**
 *  Skriver 'A', baseklassens data, årslønn og rom/kontor.
 *
 *  @param   ut  - Filobjektet egne data skrives ut til
 *  @see     Person::skrivTilTil(...)
 */
void Ansatt::skrivTilFil(ofstream & ut) const {
    ut << 'A';
    Person::skrivData();
    ut << lonn << " " << rom;
}


// ---------------------------------------------------------------------------
//                       DEFINISJON AV ANDRE FUNKSJONER:
// ---------------------------------------------------------------------------

/**
 *  Lar brukeren (om mulig) endre dataene for et avledet objekt (subklasse).
 *
 *  @see   virtual Person::endreData()
 */
void endreEnPerson() {

}


/**
 *  Leser ALLE personer inn fra fil, og legger de inn i 'gPersoner'.
 */
void lesFraFil() {
    int nr;
    char bkv;

    ifstream innA("./OBLIG/Oblig3.dta");

    if (!innA) {
        cout << "Kunne ikke åpne!";
        return;
    }
    while (innA >> nr >> bkv) {
        innA.ignore();
        switch(bkv) {
            case 'A':
                gPersoner[nr] = new Ansatt(innA);
                break;
            case 'B':
                gPersoner[nr] = new Student(innA);
                break;
            default: cout << "Noe gikk galt.";
                return;
        }
    }
}


/**
 *  Legger inn (om mulig) en ny person.
 *
 *  @see   virtual Person::lesData()
 */
void nyPerson() {
    //  LAG INNMATEN
}


/**
 *  Skriver alle dataene om alle personene ut på skjermen.
 *
 *  @see   virtual Person::skrivData()
 */
void skrivAllePersoner() {
    //  LAG INNMATEN
}


/**
 *  Skriver programmets menyvalg/muligheter på skjermen.
 */
void skrivMeny() {
    cout << "\nFølgende kommandoer er tilgjengelig:\n"
         << "\tN - Ny person (student eller ansatt)\n"
         << "\tA - skriv Alle personer\n"
         << "\tE - Endre EN gitt person\n"
         << "\tQ - Quit / avslutt\n\n";
}


/**
 *  Skriver hele datastrukturen til fil.
 *
 *  @see   virtual Person::skrivTilFil(...)
 */
void skrivTilFil() {
    //  LAG INNMATEN
}