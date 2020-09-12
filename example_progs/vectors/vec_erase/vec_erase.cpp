#include <iostream>
#include <vector>

int main() {
    std::vector <int> myvector;
    //set values(from 1 to 10)
    for(int i = 1; i <= 10; i++) myvector.push_back(i);
    //erase 7th element
    myvector.erase(myvector.begin()+6);
    //erase the first 3 elements
    myvector.erase(myvector.begin(), myvector.begin()+3);
    
    std::cout << "myvector contains:";
    for(unsigned i = 0; i < myvector.size(); ++i)
        std::cout << ' ' << myvector[i];
    std::cout << std::endl;
    
    return 0;
}
