/*
 * Eriq Walker
 * z1908120
 * CSCI-340-2
 * 
 * I certify that this is my own work and where appropriate an extension
 *  of the starter code provided for the addignment.
 * 
 * */

#include "rgi.h"

// Add needed constants
const int VEC_SIZE = 200,
          LOW = 1,
          HIGH = 10000,
          SEED = 1;

// Generates and adds the random numbers to our vector
void genRndNums(vector<int> &v) {
    srand(SEED);
    for(int i = 0; i < VEC_SIZE; i++) {
        v[i] = rand()%((HIGH-LOW)+1)+LOW;
    }
}

// Prints all the items in our vector with a set width and 
// output design
void printVec(const vector<int> &v) {
    const int NO_ITEMS = 12, ITEM_W = 5;
    int count = 0;
    for (int i = 0; i < VEC_SIZE; i++) {
        if (count == NO_ITEMS) {
            count = 0;
            cout << endl;
        }
        cout << setw(ITEM_W) << v[i] << ' ';
        count++;
    }
    cout << endl;
}

int main() {
    vector<int> v(VEC_SIZE);
    genRndNums(v);
    // Sorts our vector using STL sort
    sort(v.begin(), v.end());
    printVec(v);
    
    return 1;
}


