#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

bool lastnameSort(const std::string &A, const std::string & B) {
    unsigned int i = 0;
    while((i < A.length()) && (i < B.length())) {
        if (tolower(A[i]) > tolower(B[i])) return true;
        else if(tolower(A[i]) < tolower(B[i])) return false;
        ++i; 
    }
    return( A.length() > B.length()); 
}

int main() {
    // Intialize firstname with following list "Bob", "Joe", "Sue", "Tom", "Hank"

    // Intialize lastname with following list "Newhart", "Jonas", "Dey", "Jones", "Aaron"
    list<string> firstname = {"Bob" , "Joe", "Sue", "Tom", "Hank"};
    list<string> lastname = {"Newhart", "Jonas", "Dey", "Jones", "Aaron"};
    list<string> fullname;


    // Concatenate firstname and lastname separated by a space into a new string fullname
    const int LIST_SIZE = firstname.size();
    for(int i = 0; i < LIST_SIZE; i++) {
       fullname.push_back(firstname.front() + " " + lastname.front());
       firstname.pop_front();
       lastname.pop_front();
    }
    
    fullname.sort(lastnameSort);
    
    // Print out each fullname on a single line
    for(list<string>::iterator it = fullname.begin(); it != fullname.end(); it++) {
        cout << *it << endl;
    }

}

/*
bool compare_nocase(const std::string &A, const std::string & B) {
unsigned int i = 0;
 while((i < A.length()) && (i < B.length())) {
 if (tolower(A[i]) < tolower(B[i])) return true;
 else if(tolower(A[i]) > tolower(B[i])) return false;
 ++i; }
 return( A.length() < B.length()); }
 
 int main() {
 list<string> L;
 L.push_back("one"); L.push_back("two"); L.push_back("Three");
 L.sort();
 cout << "L contains:";
 for(auto it = L.begin(); it != L.end(); ++it) cout << ' ' << *it;
 cout << endl;
 L.sort(compare_nocase); // uses new function for comparison
 cout << "L contains:";
 for(auto it = L.begin(); it != L.end(); ++it) cout << ' ' << *it;
 cout << endl;
 return 0; }
 // L contains: Three one two
*/
