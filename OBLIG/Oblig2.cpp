/*
 * Obligatory 2 in OOPROG
 *
 * Mainly about inheritance
 * The program contains some superclasses for animals, animals in water and in air
 * And some subclasses (different animals living on land or in water)
 *
 * @author Bendik S. Kristoffersen
 */


#include "iostream"   // cout
#include "iomanip"    // setw
#include "string"     // string-class
#include "vector"     // vector
#include "LesData2.h" // Toolbox


void writeMenu();


/*
 * Animal (baseclass - containing name of the animal)
 */
class Animal {
private:
    std::string name;
public:
    Animal() { readData(); }

    void readData() { std::cout << "\nWhats the name of the animal?"; getline(std::cin, name); }
    void writeData() const { std::cout << "\nThe animals name is " << name << "!"; }
};


/*
 * Animals on land (with weight of that animal)
 */
class AnimalOnLand : public Animal {
private:
    int weight;
public:
    AnimalOnLand() { readData(); writeData(); }

    void readData() { weight = lesInt("\nWhat does this animal weigh in kg?", 1, 500); }
    void writeData() const { std::cout << "\nThe animal weighs " << weight << "kgs!"; }
};


/*
 * Animals in water (with bool seeing if they can also walk on land for a brief moment)
 */
class AnimalInWater : public Animal {
private:
    bool hybr;
public:
    AnimalInWater() { readData(); writeData(); }

    void readData() { if (lesInt("\nCan this animal survive for some time on land (0-no/1-Yes)?", 0, 1) == 1)
                        hybr=true; else hybr=false; }
    void writeData() const { std::cout << "\nThis animal " << (hybr ? "can": "cannot") << "live on land."; }
};


/*
 * Crustacean (with size)
 */
class Crustacean : public AnimalInWater {
private:
    int size;
public:
    Crustacean() { readData(); writeData(); }

    void readData() { std::cout << lesInt("\nWhat's the size of this crustacean in mm ", 1, 120); }
    void writeData() const { if (size < 10) std::cout << "\nThat is a small crustacean!";
                             else std::cout << "\nDecently sized crustacean!"; }
};


/*
 * Fish (with number of gills entered by user)
 */
class Fish : public AnimalInWater {
private:
    int gills;
public:
    Fish() { readData(); writeData(); }

    void readData() { std::cout << lesInt("\nNumber of gills ", 1, 100); }
    void writeData() const { std::cout << "Woa this fish has " << gills << " gills!!"; }


};


/*
 * Insect (with bool checking if user likes insects)
 */
class Insect : public AnimalOnLand {
private:
    bool appr;
public:
    Insect() { readData(); writeData(); }

    void readData() { if (lesInt("\nDo you like insects (0=no/1=Yes)", 0, 1) == 1)
                                                            appr=true; else appr=false; }
    void writeData() const { std::cout << "Oh, so you " << (appr ? "":"DON'T") << "like insects!"; }
};


/*
 * Subclass of Animals on land
 */
class Bird : public AnimalOnLand {
private:
    int wingspan = 0;
public:
    Bird() { readData(); writeData(); }

    void readData () { wingspan = lesInt("\nWingspan of bird in cm: ", 1, 240); }
    void writeData() const { std::cout << "\nBirds wingspan is " << wingspan << " cm."; }
};


/*
 * Main Program start:
 */
int main(){
    Bird* b;        // Pointer to different Animal-objects
    Insect* i;
    Fish* f;
    Crustacean* c;
    char cmnd;


    writeMenu();
    cmnd = lesChar("\nCommand");

    while (cmnd != 'Q') {
        switch(cmnd) {
            case 'I':
                i = new Insect();
                delete i;
                break;
            case 'B':
                b = new Bird();
                delete b;
                break;
            case 'C':
                c = new Crustacean();
                delete c;
                break;
            case 'F':
                f = new Fish();
                delete f;
                break;
            default: writeMenu();
        }
        cmnd = lesChar("\nCommand");
    }


    return 0;
}


/*
 * Menu showing users options
 */
void writeMenu(){
    std::cout << "\n\tWhat animal do you wish to create?"
              << "\n\t'I' - Insect"
              << "\n\t'F' - Fish"
              << "\n\t'C' - Crustacean"
              << "\n\t'B' - Bird"
              << "\n\t'Q' - Quit program"
              << "\n";
}