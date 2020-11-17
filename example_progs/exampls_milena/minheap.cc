#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

template <typename T> class minheap {
    vector<T> elem;
    int size;
    
    public:
    minheap(int);
    void insert(T);
    T deleteMin();
    void printLevel();
    void printArray();
};

template<typename T> minheap<T>::minheap(int s) {
    elem = vector<T>();
    size = s;
    make_heap(elem.begin(), elem.end(), less<T>());
    sort_heap(elem.begin(), elem.end(), less<T>());
}
template<typename T> void minheap<T>::insert(T val) {
    if (elem.size() >= size) return;
    elem.push_back(val);
    push_heap(elem.begin(), elem.end());
    sort_heap(elem.begin(), elem.end(), less<T>());
}
template<typename T>    T minheap<T>::deleteMin()   {
    pop_heap(elem.begin(), elem.end());
    elem.pop_back();
    sort_heap(elem.begin(), elem.end(), less<T>());
}
template<typename T> void minheap<T>::printLevel()  {
    int j = 0;
    for (int i = 0; i < elem.size(); i++) {
        if (i == (j) || i == j-1) {
            if (i != 0) cout << endl;
            if (j == 0) j++;
            j*=2;
        }
        cout << elem[i] << " ";
    }
    cout << endl;
}
template<typename T> void minheap<T>::printArray()  {
    sort(elem.begin(), elem.end());
    for (int i = 0; i < elem.size(); i++) {
        cout << elem[i] << " ";
    }
    cout << endl;
} 

int main() {
    minheap<int> test(20);
    for (int i = 0; i < 20; i++) {
        test.insert(i);
    }
    //test.printArray();
    //test.deleteMin();
    test.printLevel();
    
    
    return 0;
}
