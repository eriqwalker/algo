#include <iostream>
#include <list>
#include <string>

using namespace std;







int main()
{
    // Intialize firstname with following list "Bob", "Joe", "Sue", "Tom", "Hank"
    // Intialize lastname with following list "Newhart", "Jonas", "Dey", "Jones", "Aaron"
    list<string> firstname = {"Bob", "Joe", "Sue", "Tom", "Hank"};
    list<string> lastname = {"Newhart", "Jonas", "Dey", "Jones", "Aaron"};
    list<string> fullname;

    // Concatenate firstname and lastname separated by a space into a new string fullname
   for(int i = 0; i < 5; i++) 
   {
       fullname.push_back(firstname.front() + " " + lastname.front());
       firstname.pop_front();
       lastname.pop_front();

   }

    // Print out each fullname on a single line
    for(list<string>::iterator it = fullname.begin(); it != fullname.end(); it++)
    {
        cout << *it << endl;
    }
}
