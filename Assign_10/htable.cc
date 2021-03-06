/*
 * Eriq Walker
 * z1908120
 * CSCI-340-2
 * 
 * I certify that this is my own work and where appropriate an extension
 *  of the starter code provided for the assignment.
 * 
 * */
 
#include "htable.h"

#define N1 10  // num of decimal digits
#define N2 26  // num of upper-case letters

// Hash function, you may NOT modify this function
int HT::hash(const string &s) {
  int n = (N2 * N1) * (s[0] - 'A') + N1 * (s[1] - 'A') + (s[2] - '0');

  return n % hsize;
}

// You will complete the code below ...
//constructor
HT::HT(const unsigned &hs) {
    hTable.resize(hs);
    hsize = hs;
}

//destructor
HT::~HT() {
    hTable.clear();
    pTable.clear();
}

//inserts a new entry if it doesn't already exist
void HT::insert(const Entry &e) {
    int pos = hash(e.key);
    list<Entry> &l = hTable[pos];
    auto succ = find_if(l.begin(),
                        l.end(),
                        [e](const Entry& x) {
                            return x.key == e.key;
                        }
    );
    
    if (succ != l.cend()) cout << " not inserted - duplicate key!!!\n";
    else {
        cout << " entry = " << setw(2) << right << pos << endl;
        hTable[pos].push_front(e);
        pTable.push_back(&hTable[pos].front());
    }
}

//searches for an item, if key doesn't exist then it says it's not in the table
void HT::search(const string &s) {
    int pos = hash(s);
    list<Entry> &l = hTable[pos];
    auto succ = find_if(l.begin(),
                        l.end(),
                        [s](const Entry& x) {
                            return x.key == s;
                        }
    );
    
    if (succ != l.cend()) cout << " ==> number: " << setw(4) << right << succ->num << " - item: " << succ->desc << endl;
    else cout << " not in table!!\n";
}

//printing out the entries
void HT::hTable_print() {
    int c = 0;
    bool first = true;
    for (unsigned i = 0; i < hTable.size(); i++) {
        c++;
        if (hTable[i].empty()) {
            c++;
            if (c-i == 1) cout << endl;
            if (first) cout << endl;
        } else {
            c++;
            if (!hTable[i].empty()) {
                c = i;
                for (auto it = hTable[i].begin(); it != hTable[i].end(); it++) {
                    cout << setw(4) << i << ":  " << it->key << "  -  " 
                         << setw(4) << right << it->num << "  -  " << it->desc << endl;
                }
            }
        }
        first = false;
    }
}

//helper function
bool test(Entry *a, Entry *b) {
    return(a->key.compare(b->key) < 0);
}

//sorts and then prints the ptable
void HT::pTable_print() {
    sort(pTable.begin(), pTable.end(), test);
    
    for (unsigned i = 0; i < pTable.size(); i++) {
        cout << "  " << setw(4) << pTable[i]->key << "  - " << setw(5) << pTable[i]->num << "  -  " << pTable[i]->desc << endl;
    }
}














