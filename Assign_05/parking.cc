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
#include <deque>
#include <stack>

using namespace std;

typedef struct {
    int id;         //start at 1
    string plate;   //license plate for the car
    int moves;      //times car has moved
} CAR;

///////////Prototypes////////////
void get_input_vals(const string&, char&, string&);
void arrival(const CAR&, deque<CAR>&);
void departure(const string&, deque<CAR>&, stack<CAR>&);
CAR make_car(int, string, int);
void swap_stack(stack<CAR>&);

//main
int main() {
    string line, plate;
    char act;
    int id = 1;
    deque<CAR> garage;
    stack<CAR> temp;
    while(cin) {
        getline(cin, line);
        if (line.size() > 0) {
            get_input_vals(line, act, plate);
            if (act == 'A') {
                arrival(make_car(id, plate, 0), garage);
                id++;
            }
            else if (act == 'D') {
                departure(plate, garage, temp);
            }
            else cout << "'" << act << "': invalid action!\n";
        }
    }
    
    return 0;
}

////////////Function Implimentations/////////////
void get_input_vals(const string &line, char &act, string &plate) {
    act = line.substr(0, line.find(':'))[0];
    plate = line.substr(line.find(':')+1, line.rfind(':')-2);
}

void arrival(const CAR &car, deque<CAR> &D) {
    cout << car.plate << " arrives" << endl;
    if (D.size() >= 10) {
        cout << "The garage is full!\n";
        return;
    }
    D.push_back(car);
}

void departure(const string &plate, deque<CAR> &D, stack<CAR> &S) {
    bool found = false;
    cout << plate << " departs" << endl;
    for (auto it = D.begin(); it != D.end(); it++) {
        if (it->plate.compare(plate) == 0) found = true;
    }
    
    if (found) {
        for (auto it = D.begin(); it != D.end(); it++) {
            if (it->plate.compare(plate) == 0) {
                D.erase(it);
                if (S.size() != 0) {
                    swap_stack(S);
                }
                
                break;
            } else {
                S.push(*it);
                D.pop_front();
            }
        }
    } else cout << "No car with license plate \"" << plate << "\" in garage.\n";
    
    
    //for (pos = 0; pos < D.size(); pos++) {
      //  if (D[pos].plate == plate) {
        //    D.erase(pos);
        //}
        //else S.push(D.pop_front());
    //}
    
    
    auto temp = D;
    auto temps = S;
}

CAR make_car(int id, string plate, int moves) {
    CAR c;
    c.id = id;
    c.plate = plate;
    c.moves = moves;
    
    return c;
}

void swap_stack(stack<CAR> &S) {
    if (S.size()%2 == 0) {
        for (unsigned i = 0; i < (S.size()/2); i++) {
            
        }
    }
}


