/**
* Task 4 OOPROG
 *
 * Using structs, we want to find which values are largest,
 * comparing two different times of day
 *
 * @author Bendik S. Kristoffersen
*/


#include "iostream"     // cout, cin
using namespace std;


struct Tid{
    int time,
        min,
        sekund;
};


struct Tid storst(struct Tid t1, struct Tid t2) {
    int total1 = t1.time * 3600 + t1.min * 60 + t1.sekund;
    int total2 = t2.time * 3600 + t2.min * 60 + t2.sekund;

    if (total1 > total2){
        return t1;
    } else {
        return t2;
    }
}


/**
 * Main program start:
 */
int main(){
    Tid tid1 = {19, 25, 36};
    Tid tid2 = {11, 26, 37};
    Tid tid3 = {10, 25, 38};
    Tid tid4 = {13, 28, 39};

    int total1 = storst(tid1, tid2).time * 3600 + storst(tid1, tid2).min * 60 +
                 storst(tid1, tid2).sekund;
    int total2 = storst(tid3, tid4).time * 3600 + storst(tid3, tid4).min * 60 +
                 storst(tid3, tid4).sekund;

    // Alternative method as opposed to the one above
    // Returns an int to each member of the struct
    int storstTime = storst(storst(tid1, tid2), storst(tid3, tid4)).time;

    int storstMin = storst(storst(tid1, tid2), storst(tid3, tid4)).min;

    int storstSek = storst(storst(tid1, tid2), storst(tid3, tid4)).sekund;

    if (total1 > total2){
        //cout << "First is biggest:\t" << storstTime << ":" << storstMin << ":" << storstSek;
        cout << "First is biggest:\t" << storst(tid1, tid2).time << ":" << storst(tid1, tid2).min <<
                ":" << storst(tid1, tid2).sekund;
    } else {
        cout << "Second is biggest\n";
        cout << storst(tid3, tid4).time << ":" << storst(tid3, tid4).min <<
             ":" << storst(tid3, tid4).sekund;
    }

    return 0;
}
