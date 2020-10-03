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
#include <fstream>
#include <algorithm>

using namespace std;

//prototypes
void get_words(map<string, int>&);
void print_words(const map<string, int>&);
void clean_entry(const string&, string&);
void my_tolower(char &c);
int  mapcount(const map<string, int>&);

//tolower function
void my_tolower(char &c) {
    c = tolower(c);
}

//counting the number of words total in the map by adding all
//of the frequencies together
int mapcount(const map<string, int>& m) {
    int count = 0;
    for (auto it = m.begin(); it != m.end(); ++it) {
        count += it->second;
    }
    
    return count;
}

//gets a word from the input stream and removes punctuation
//cleans all the words by calling clean_entry
void get_words(map<string, int>& m) {
    //This will need modification because it will take it in, clean it
    //then add it, not add it, clean it, add it, delete it, like you're
    //trying to do.
    string toClean = "";
    string cleaned = "";
    ifstream in;
    in.open("assignment04.in");
    while(in) {
        in >> toClean;
        clean_entry(toClean, cleaned);
        m[cleaned]++;
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
        cout << left << setw(ITEM_W) << it->first << " : " << setw(5) << it->second; 
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
        if ( isalnum(A[i]) && i < firstChar) firstChar = i;
        if (!isalnum(A[i]) && i > firstChar) lastChar  = i;
    }
    if (!(firstChar == lastChar)) {
        B = A.substr(firstChar, lastChar-firstChar);
        for_each(B.begin(), B.end(), my_tolower);
    }
}


int main() {
    map<string, int> words;
    get_words(words);
    print_words(words);
    
    cout << "\nno of words in input stream  : " << mapcount(words) << endl;
    cout << "no of words in output stream : " << words.size() << endl;
    
    return 0;
}

//word    extra
//it      2
//you     1
//period  1
//however 1