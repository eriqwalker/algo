#include <iostream>
#include <iomanip>
#include <set>

using std::set;

void sieve(set<int>& s, int n) {
    for (int m = 2; m*m <= n; m++) {
        for (int k = 2; m*k <= n; k++) {
            s.erase(m*k);
        }
    }
}

void print_primes(const set<int>& s) {
    const int NO_ITEMS = 16;
    const int ITEM_W = 5;
    int count = 0;
    
    /*for (unsigned i = 0; i < s.size(); i++) {
        std::cout << std::setw(ITEM_W) << s[i] << ' ';
        if (i != 0 && i%NO_ITEMS == 0) std::cout << std::endl;
    }*/
    for(auto i = s.begin(); i != s.end(); ++i) {
        if (count != 0 && count%NO_ITEMS == 0) std::cout << '\n';
        std::cout << std:: setw(ITEM_W) << *i;
        count++;
    }
}

int main() {
    int limit;
    set<int> nums;
    std::cout << "Upper limit for the set of primes: ";
    std::cin  >> limit;
    for(int i = 2; i <= limit; ++i) {
        nums.insert(i);
        //std::cout << i << std::endl;
    }
    sieve(nums, limit);
    print_primes(nums);
    
    return 0;
}
