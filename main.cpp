#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    /*list<Goat> tempL;
    for (int i = 0; i < 10; i++)
        add_goat(tempL, names, colors);
    
    display_trip(tempL);
    delete_goat(tempL);
    display_trip(tempL);*/
    return 0;
}

int main_menu() {
    int choice;
    cout << "*** GOAT MANAGER 3001 ***" << endl
         << "[1] Add a goat" << endl
         << "[2] Delete a goat" << endl
         << "[3] List goats" << endl
         << "[4] Quit" << endl
         << "Choice: ";
    cin >> choice;
    while (choice < 1 || choice > 4) {
        cout << "\tError! Please enter a number 1-4: ";
        cin >> choice;
    }

    return choice;
}

void display_trip(list<Goat> trip) {
    int i = 1;  //counter
    cout << "Current trip: " << endl;
    for (Goat g : trip) {
        cout << "[" << i++ << "] " << g.get_name()
             << " (" << g.get_age() << ", " << g.get_color() << ")" << endl;
    }
}

void delete_goat(list<Goat> &trip) {
    int d, p = 1;
    display_trip(trip);
    cout << "Please enter the number of the goat to be deleted: ";
    cin >> d;
    while (d < 1 || d > trip.size()) {
        cout << "Error! Please enter a number between 1 -" 
             << trip.size() << ": ";
        cin >> d;
    }
    auto it = trip.begin();
    for (int i = 1; i < d; i++)
        it++;

    trip.erase(it);
}

void add_goat(list<Goat> &trip, string n[], string c[]) {
    int r = 0;
    string tempN, tempC;
    r = rand() % (SZ_NAMES + 1);
    tempN = n[r];
    r = rand() % (SZ_COLORS + 1);
    tempC = c[r];
    r = rand() % (MAX_AGE + 1);
    Goat tempG(tempN, r, tempC);

    trip.push_back(tempG);
}