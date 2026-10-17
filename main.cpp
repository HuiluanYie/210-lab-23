// COMSC-210 | Lab 23 | Huiluan Yie

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <cstdlib>
#include <ctime>
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

    // declaration
    list<Goat> trip;

    main_menu();

    delete_goat(trip);

    return 0;
}

int main_menu()
{
    // main_menu() outputs the GM3K1 engine and then obtains, 
    //              validates, and returns the user's choice.
    // arguments: none
    // returns: the integer the user choose
    int choice;
    cout << "\n*** GOAT MANAGER 3001 *** \n";
    cout << "[1] Add a goat \n";
    cout << "[2] Delete a goat \n";
    cout << "[3] List goats \n";
    cout << "[4] Quit \n";
    cout << "Choice --> ";
    do
    {
        cin >> choice;
        if (choice < 1 || choice > 4)
        {
            cout << "invalid input! Please enter a number on the menu\n";
            cout << "Choice --> ";
        }
    } while (choice < 1 || choice > 4);
    return choice;
}

void add_goat(list<Goat> &trip, string n[], string c[])
{
    int i = rand() % SZ_NAMES + 1;
    int a = rand() % MAX_AGE + 1;
    int j = rand() % SZ_COLORS + 1;
    Goat g(n[i], a, c[j]);
    trip.push_back(g);
}

int select_goat(list<Goat> trip)
{
    display_trip(trip);
    int goat;
    cout << "Select a certain goat, refer by the integer: \n";
    cout << "Choice --> ";
    do
    {
        cin >> goat;
        if (goat < 1 || goat > trip.size())
        {
            cout << "invalid input! Please enter a number on the list\n";
            cout << "Choice --> ";
        }
    } while (goat < 1 || goat > trip.size());
    return goat;
}

void delete_goat(list<Goat> &trip)
{
    int g = select_goat(trip);
    auto it = trip.begin();
    
    // move the iterater to the goat to delete
    for (int i = 0; i < g; i++)
    {
        it++;
    }
    trip.erase(it);
}

void display_trip(list<Goat> trip)
{
    int i = 1;
    for (Goat g:trip)
    {
       cout << "[" << i << "] "<< g.get_name() << " (" << g.get_age() << ", " << g.get_color() << ")\n";
       i++;
    }
}