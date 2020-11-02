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
            else cout << "'" << act << "': invalid action!\n\n";
        }
    }
    
    return 0;
}

////////////Function Implimentations/////////////

//Takes the info from the input file and assigns it to the proper variables
void get_input_vals(const string &line, char &act, string &plate) {
    act   = line.substr(0, line.find(':'))[0];
    plate = line.substr(line.find(':')+1, line.rfind(':')-2);
}

//If a car arrives and the garage is not full then it is added to the deque
//otherwise it prints a message that the garage is full and the car is ignored
void arrival(const CAR &car, deque<CAR> &D) {
    cout << "Car " << car.id << " with license plate \"" << car.plate << "\" is arrived." << endl;
    if (D.size() >= 10) {
        cout << "    But the garage is full!\n\n";
        return;
    }
    cout << endl;
    D.push_back(car);
}


//If the car is found by the plate, then it is removed by pulling all
//cars from in front of it out, incrementing their moves, deleting the
//departing car, and replacing the moved cars
//if the car is not found, then a message is printed saying that there
//is no car with that plate in the garage
void departure(const string &plate, deque<CAR> &D, stack<CAR> &S) {
    bool found = false;
    
    //searches garage for plate, if found, it sets the var to true and breaks
    for (auto it = D.begin(); it != D.end(); it++) {
        if (it->plate.compare(plate) == 0) {
            found = true;
            break;
        }
    }
    
    //if the plate was found then it runs this loop
    if (found) {
        //goes through all cars until the one that is leaving is found
        for (auto it = D.begin(); it != D.end(); it++) {
            it->moves++;
            if (it->plate.compare(plate) == 0) {
                cout << "Car " << it->id << " with license plate \"" << plate << "\" is departed,\n";
                cout << "    car was moved " << it->moves
                     << (it->moves == 1 ? " time" : " times")
                     << " in the garage.\n\n";
                D.erase(it);
                int n = S.size();
                //putting all the cars back in the garage
                for (int i = 0; i < n; i++) {
                    D.push_front(S.top());
                    S.pop();
                }
                break;
            } 
            //moving the cars from the garage so that the leaving car can get out
            else {
                S.push(D.front());
                D.pop_front();
            }
            
        }
    } 
    //message for if the plate is not found
    else cout << "No car with license plate \"" << plate << "\" in garage.\n";
}

//function for creating the car struct so that it can be passed
CAR make_car(int id, string plate, int moves) {
    CAR c;
    c.id = id;
    c.plate = plate;
    c.moves = moves;
    
    return c;
}


