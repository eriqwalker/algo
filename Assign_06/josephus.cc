/*
 * Eriq Walker
 * z1908120
 * CSCI-340-2
 * 
 * I certify that this is my own work and where appropriate an extension
 *  of the starter code provided for the assignment.
 * 
 * */

#include "josephus.h"

//workhorse of the program
int main() {
    //data needed from the .d file
    args in;
    //list of names that will be generated
    list<string> names;
    int j, i = 0;
    //count of how many names have been eliminated
    unsigned cnt = 0;
    
    //gets the data from the .d file and generates
    //the list of names
    init_vals(names, in);
    
    //prints the starting list of names
    print_list(names, cnt);
    
    //iterator for use later
    auto p = names.begin();
    
    //this is where most of the work happens
    while (names.size() != 1) {
        //getting the Mth person from the list
        j = (i + (in.M-1))%names.size();
        i = j;
        //resetting the interator
        p = names.begin();
        //moving to the position of the person we are eliminating
        advance(p, j);
        //erasing the person to be eliminated
        names.erase(p);
        //increasing elimination count
        cnt++;
        
        //if for deciding when to print the names again
        if (cnt%in.K == 0 || names.size() == 1) 
            print_list(names, cnt);
    }
    
    return 0;
}

//gets data from the .d file and stores it in the args struct
//also generates the list of names that we will be using for
//this program, using the STL generate function
void init_vals(list<string> &L, args &in) {
    cin >> in.N
        >> in.M
        >> in.K;
    
    cout << "Number of people? "      << in.N << endl;
    cout << "Index for elimination? " << in.M << endl;
    cout << "Index for printing? "    << in.K << endl;
    
    L.resize(in.N);
    generate(L.begin(), L.end(), SEQ(in.N));
}

//prints out the list of remaining people
void print_list(const list<string> &L, const unsigned &cnt) {
    int i = 0;
    const int ITEM_NO = 12;
    
    //for the first time this function is called
    if (cnt == 0) {
        cout << "\nInitial group of people\n";
        cout << "-----------------------\n";
    } 
    
    //every call after the first one
    else {
        cout << "\nAfter eliminating " << cnt << "th person\n";
        cout << "----------------------------";
        //this is to fix the formatting for when the print is called 
        //when there are less than 10 people eliminated, otherwise it
        //is off
        if (cnt > 9) cout << "-";
        cout << endl;
    }
    
    //this actually prints out the people remaining
    for (auto it = L.begin(); it != L.end(); it++) {
        cout << *it << " ";
        i++;
        if (i%ITEM_NO == 0 && i != 0) cout << endl;
    }
    cout << endl;
}
