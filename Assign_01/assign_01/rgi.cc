#include "rgi.h"

// Add needed constants
const int VEC_SIZE = 200,
          LOW = 1,
          HIGH = 10000,
          SEED = 1;

// Add code for genRndNums
void genRndNums(vector<int> &v) {
    srand(SEED);
    for(int i = 0; i < VEC_SIZE; i++) {
        v.at(i) = rand()%HIGH+LOW;
    }
}

// Add code for printVec
void printVec(const vector<int> &v) {
    for(int i = 0; i < VEC_SIZE; i++) 
        cout << v.at(i) << "|";
}

int main() {
// Declare vector v
    vector<int> v(VEC_SIZE);
    
// Generate random numbers to fill vector v	
    genRndNums(v);
    
// Using STL sort sort v
    sort(v.begin(), v.end());
    
// Print vector of sorted random numbers
    printVec(v);
    
    return 1;
}


