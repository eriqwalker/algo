#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector <int> v1;
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(6);
    
    cout << v1.front() << v1.back() << endl;
    
    for (auto it = v1.begin(); it != v1.end(); it++) 
        cout << *it;
    cout << endl;
    
    return 0;
}
