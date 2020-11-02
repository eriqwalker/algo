#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void print_sort(multimap<string, int> m, string n) {
    vector<int> nums;
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->first == n) {
            nums.push_back(it->second);
        }
    }
    sort(nums.begin(), nums.end());
    for (auto it = nums.begin(); it != nums.end(); it++) {
        cout << n << ": " << *it << endl;
    }
}


int main() {
    multimap<string, int> studentMap;
    string name;
    int num;
    
    while(cin) {
        cin >> name;
        cin >> num;
        if (name != "")
            studentMap.insert(pair<string, int>(name, num));
        name = "";
        num = 0;
    }
    
    print_sort(studentMap, "Joe");
    print_sort(studentMap, "Sue");
    
    for (auto it = studentMap.begin(); it != studentMap.end(); it++) {
        //if (it->first == "Joe")
            //cout << it-> first << " " << it->second << endl;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
