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
#include <set>

using std::set;

//function that handles the removal of all nonprimes
//m*m <= n stops the check once we reach and process
//the squareroot of the upper limit
//m*k <= n makes sure that we only check what is in
//our bounds for checking
void sieve(set<int>& s, int n) {
    for (int m = 2; m*m <= n; m++) {
        for (int k = 2; m*k <= n; k++) {
            s.erase(m*k);
        }
    }
}

//function for printing out the numbers that are
//left inside our set, which is only primes
//used and iterator to print the nums
void print_primes(const set<int>& s) {
    const int NO_ITEMS = 16;
    const int ITEM_W = 5;
    int count = 0;
    
    for(auto i = s.begin(); i != s.end(); ++i) {
        if (count != 0 && count%NO_ITEMS == 0) std::cout << '\n';
        std::cout << std:: setw(ITEM_W) << *i;
        count++;
    }
    std::cout << '\n';
}

//main function 
//takes input to determine the upper range of our 
//numbers and fills the set with all the numbers from 
//2-limit, since we already know that 0 and 1 will be removed
//it then calls the other two functions that do most of the work
int main() {
    int limit;
    set<int> nums;
    std::cout << "Upper limit for the set of primes: ";
    std::cin  >> limit;
    for(int i = 2; i <= limit; ++i) 
        nums.insert(i);
        
    sieve(nums, limit);
    print_primes(nums);
    
    return 0;
}
