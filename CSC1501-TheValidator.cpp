#include <iostream>
#include <string>
#include <iomanip> //setw()
#include <vector> //vectors
using namespace std;

//Validator class for implies statement
class theValidator {
    public:
        bool implies(bool input1, bool input2);
        
};
//implies function
bool theValidator::implies(bool input1, bool input2){
    bool result = 0;
    result = !(input1 && !input2);
    return result;
}

//Propositional logic statement is invalid when all props are true but conclusion is false
int main() {
    //create theValidator object and bool variables
    theValidator obj;
    bool r;
    bool a;
    bool t;
    bool e;

    //Truth Tables
    int rocket[16] = {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};
    int astronaut[16] = {0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1};
    int trained[16] = {0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1};
    int educated[16] = {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
    //setw() constants
    const int w = 10; 
    const int x = 15;
    const int y = 10;
    const int z = 14;
    //vector to track number of invalids;
    vector<int> invalid;

    //Propositional Statements
    cout << "                         The Validator                        " << endl;
    cout << "--------------------------------------------------------------\n" << endl;
    cout << "Propositional Statements: " << endl;
    cout << "If someone has a rocket, that implies they're an astronaut." << endl;
    cout << "If someone is an astronaut, that implies they're highly trained." << endl;
    cout << "If someone is highly trained, that implies they're educated.\n" << endl;
    
    //Conclusion Statement
    cout << "Conclusion Statement: " << endl;
    cout << "A person is educated, that implies they have a rocket.\n" << endl;
    //Output Values
    cout << "===========================================================================================================" << endl;
    cout << "(R)ocket" << setw(x) << "(A)stronaut" << setw(x) << "(T)rained" << setw(x) << "(E)ducated" 
        << setw(w) << "R->A" << setw(w) << "A->T" << setw(w) << "T->E" << setw(w) << "E->R" << setw(13) << "Conclusion" << "|" << endl;
    cout << "===========================================================================================================" << endl;
    
    for(int i=0; i < 16; i++){
        //initialize variables
        r = rocket[i];
        a = astronaut[i];
        t = trained[i];
        e = educated[i];
        string conclusion= ""; 

        //if statement to determine valid or invalid    
        if((obj.implies(r,a) != false && obj.implies(a,t) != false && (obj.implies(t,e) != false) &&
                 (obj.implies(obj.implies(obj.implies(obj.implies(r,a), obj.implies(a,t)),
                            obj.implies(t,e)), obj.implies(e,r)) == false))){
            conclusion = "INVALID";
            invalid.push_back(i); 
            }
        else{
            conclusion = "VALID";
        }
        //cout '0' or '1' here
        cout << setw(8) << to_string(r) << setw(x) << to_string(a) << setw(x) << to_string(t) << setw(x) << to_string(e) << setw(w)
            << to_string(obj.implies(r,a)) << setw(w) 
            << to_string(obj.implies(a,t)) << setw(w) 
            << to_string(obj.implies(t,e)) << setw(w)
            << to_string(obj.implies(e,r)) << setw(13) 
            << conclusion << "|" << endl;
    }
    //if statement to print out number of Invalids and their location
    if(invalid.size() > 0){
        cout << "The propositional logical statements are found to be invalid " << invalid.size() << " times." << endl;
        cout << "Invalid for (in form{r,a,t,e}): ";
        for(int j = 0; j < invalid.size(); j++){
                cout << "{" << rocket[invalid[j]] << "," << astronaut[invalid[j]] << "," << trained[invalid[j]] << "," << educated[invalid[j]] << "} "; 
        }
    }
    //end of program
    cout << "\nEnd of The Validator" << endl;
    return 0;
}
