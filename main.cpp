#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(set<Goat> trip);
void delete_goat(set<Goat> &trip);
void add_goat(set<Goat> &trip, string [], string []);
void display_trip(set<Goat> trip);
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

    int choice = 0;
    set<Goat> goatList;
    do {
        choice = main_menu();

        if (choice == 1) {
            add_goat(goatList, names, colors);
        }
        if (choice == 2) {
            delete_goat(goatList);
        }
        if (choice == 3) {
            display_trip(goatList);
        }
        if (choice == 4) {
            cout << "\tYou have chosen to exit the program. Goodbye!" << endl;
        }
    } while (choice != 4);

    
    return 0;
}

int main_menu() {
    int c;  // holds choice
    cout << "*** GOAT MANAGER 3001 ***" << endl
         << "[1] Add a goat" << endl
         << "[2] Delete a goat" << endl
         << "[3] List goats" << endl
         << "[4] Quit" << endl
         << "Choice: ";
    cin >> c;
    while (c < 1 || c > 4) {
        cout << "\tError! Please enter a number 1-4: ";
        cin >> c;
    }
    cout << endl;

    return c;
}

void display_trip(set<Goat> trip) {
    if (trip.size() == 0) {
        cout << "Error! No goats in the trip. Going back to menu." 
             << endl << endl;
    }
    else {
        int i = 1;  //counter
        cout << "Current trip: " << endl;
        for (Goat g : trip) {
            cout << "\t[" << i++ << "] " << g.get_name()
                << " (" << g.get_age() << ", " << g.get_color() << ")" << endl;
        }
        cout << endl;
    }
}

void delete_goat(set<Goat> &trip) {
    int d, p = 1;
    if (trip.size() == 0) {
        cout << "Error! No goats in the trip. Going back to menu." 
             << endl << endl;
    }
    else {
        display_trip(trip);
        cout << "Please enter the number of the goat to be deleted: ";
        cin >> d;
        while (d < 1 || d > trip.size()) {
            cout << "Error! Please enter a number between 1-" 
                << trip.size() << ": ";
            cin >> d;
        }
        auto it = trip.begin();
        for (int i = 1; i < d; i++)
            it++;

        cout << it->get_name() << " has been erased" << endl << endl;
        trip.erase(it);
    }
}

void add_goat(set<Goat> &trip, string n[], string c[]) {
    int r = 0;
    string tempN, tempC;
    r = rand() % (SZ_NAMES + 1);
    tempN = n[r];
    r = rand() % (SZ_COLORS + 1);
    tempC = c[r];
    r = rand() % (MAX_AGE + 1);
    Goat tempG(tempN, r, tempC);

    trip.insert(tempG);
    cout << "A goat has been added to the list." << endl << endl;
}