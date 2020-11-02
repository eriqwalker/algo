/*
 * This is a program for practicing vectors
 * since it's been awhile since you've worked
 * with C++ I thought this would be a good
 * idea for you to do.
 * */
#include <iostream>
#include <vector>

int main() {
    std::vector<int> myvector(10); // 1- zero-initialized ints
    //assign some values
    for (unsigned i = 0; i < myvector.size(); i++) {
        myvector.at(i) = i;
    }
    
    std::cout << "myvector contains:";
    for (unsigned i = 0; i < myvector.size();i++) {
        std::cout << ' ' << myvector.at(i);
    }
    
    std::cout << std::endl;
    
    return 0;
}
