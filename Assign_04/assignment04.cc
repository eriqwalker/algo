/*
 * Eriq Walker
 * z1908120
 * CSCI-340-2
 * 
 * I certify that this is my own work and where appropriate an extension
 *  of the starter code provided for the assignment.
 * 
 * */

#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>

using namespace std;

//prototypes
void get_words(map<string, int>&);
void print_words(const map<string, int>&);
void clean_entry(const string&, string&);


//gets a word from the input stream and removes punctuation
//cleans all the words by calling clean_entry
void get_words(map<string, int>& m) {
    //This will need modification because it will take it in, clean it
    //then add it, not add it, clean it, add it, delete it, like you're
    //trying to do.
    string cleantemp = "";
    m.insert({"Test" , 1});
    m.insert({"Test.", 1});
    m.insert({"Test.", 1});
    m.insert({"Test/", 1});
    m.insert({"Test?", 1});
    m.insert({"Test,", 1});
    m.insert({"Test!", 1});
    
    for (auto it = m.begin(); it != m.end(); ++it) {
        clean_entry(it->first, cleantemp);
        m[cleantemp]++;
    }
}

//prints the words and their frequencies, as well as the 
//number of nonempty words and the number of distinct words
//in the stream
void print_words(const map<string, int>& m) {
    const int ITEM_W = 16;
    const int NO_ITEMS = 3;
    int count = 0;
    
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (count != 0 && count%NO_ITEMS == 0) cout << endl;
        cout << left << setw(ITEM_W) << it->first << ": " << it->second << "   "; 
        count++;
    }
    cout << endl;
}

//cleans a word from its punctuation, first arguement is the
//original word in the stream and the second contains the same
//word after cleaning
void clean_entry(const string& A, string& B) {
    unsigned firstChar = A.size(), lastChar = A.size();
    for (unsigned i = 0; i < lastChar; i++) {
        if (isalnum(A[i]) && i < firstChar) firstChar = i;
        if (!isalnum(A[i]) && i > firstChar) lastChar = i;
    }
    B = A.substr(firstChar, lastChar-firstChar);
}


int main() {
    map<string, int> words;
    get_words(words);
    print_words(words);
    
    return 0;
}
