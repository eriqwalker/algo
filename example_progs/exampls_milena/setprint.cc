#include <iomanip>
#include <iostream>
#include <set>
#include <string>

using namespace std;

const int ITEM_W = 2;
const int NUM_PER_COLUMN = 3;

void printSet(const char* word, set<int> s) {
    int num = 1;
    
    cout << word << "\n{";
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << setw(ITEM_W) << it;
    }
}
