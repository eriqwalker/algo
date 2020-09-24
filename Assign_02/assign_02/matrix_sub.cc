/*
 * Eriq Walker
 * z1908120
 * CSCI-340-2
 * 
 * I certify that this is my own work and where appropriate an extension
 *  of the starter code provided for the assignment.
 * 
 * */

#include "matrix.h"

//function for opening files. If either of the files that is meant to
//be opened can't be, then it tells the user which one and exits the
//program with a nonzero code
void open_files(ifstream &is1, ifstream &is2) {
    is1.open(FILE1);
    is2.open(FILE2);
    if (!is1 || !is2) {
        if (!is1.is_open())
            cerr << "ERROR: 'matrix01.dat' failed to open.\n";
        if (!is2.is_open()) 
            cerr << "ERROR: 'matrix02.dat' failed to open.\n";
        exit(1);
    }
}

//function meant to read data from a file and store it in the matrix
//that is passed along with the file
void read_data(ifstream &is, vector<vector<int>> &m) {
    unsigned i = 0;
    unsigned j = 0;
    while (is) {
        if (j == m[0].size()) {
            j = 0;
            i++;
        }
        is >> m[i][j];
        j++;
    }
}


//function meant to print out the matrix that is passed in
//prints the lenghts of the columns and rows, followed by a 
//separator and the matrix, printed out cell by cell
void print_data(const vector<vector<int>> &m) {
    cout << m.size() << " x " << m[0].size() 
         << "\n----------------------------------------------------------------------" 
         << endl;
    for (unsigned i = 0; i < m.size(); i++) {
        for (unsigned j = 0; j < m[i].size(); j++) {
            cout << setw(ITEM_W) << m[i][j];
        }
        cout << endl;
    }
}


//function meant to multiply the first two matrices passed 
//in and storing the results in the third matrix that is passed.
void gen_data(
    const vector<vector<int>> &A,
    const vector<vector<int>> &B,
          vector<vector<int>> &C)
    {

    for (unsigned i = 0; i < C.size(); i++) {
        for (unsigned j = 0; j < C.size(); j++) {
            for (unsigned k = 0; k < A[0].size(); k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
    
}




