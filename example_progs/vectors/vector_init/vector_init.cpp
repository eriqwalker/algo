//iterator loop pattern
/*
 * for(auto i = container.begin(); i != container.end(); ++i) {cout << *i;}
 * 
 * can also use this one with a while:
 * 
 * auto p = container.begin();
 * while(p != container.end()) {cout << *p; ++p;}
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(4);
    v1.push_back(7);
    
    vector<int> v2(v1);
    vector<int> v3(3);
    
    v3.at(0) = 4;
    v3.at(1) = 6;
    v3.at(2) = 4;
    
    vector<int> v4(4, 2);
    vector<int> v5(v2.begin(), v2.end());
    
    for(unsigned i = 0; i < v1.size(); i++)
        cout << v1.at(i) << ' ' << v2[i] << ' ' << v3.at(i) << ' ' << v4.at(i) << ' ' << v5.at(i) << endl;
    
    return 0;    
}
