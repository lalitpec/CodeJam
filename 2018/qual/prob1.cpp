#include <iostream>  // includes cin to read from stdin and cout to write to stdout
#include <string>
using namespace std;  // since cin and cout are both in namespace std, this saves some text

int attack_arr[30];
int attacksz;

unsigned long long int shield;

void print_attack_arr() {
    cout << " attack_arr# ";
    for ( int j = 0; j<attacksz; ++j) {
        cout << attack_arr[j] << " ";
    }
    cout << endl;
}

unsigned long long int getdamage() {
    unsigned long long int hitsize = 1;
    unsigned long long int damage = 0;
    for ( int i = 0; i<attacksz; ++i) {
        if ( attack_arr[i] == 0 ) { hitsize *= 2; }
        if ( attack_arr[i] == 1 ) { damage += hitsize; }
    }
    return damage;
}

bool isZeroOnepresent() {
    for ( int i = 0; i<attacksz-1; i++) {
//        cout << __FUNCTION__ <<" current i value is  " << i<< endl;
        if( attack_arr[i] == 0 && attack_arr[i+1] == 1) {
//            cout << __FUNCTION__ <<" zero found at " << i<< endl;
            return true;
        }
    }
    return false;
}

bool isSwapPossible() {
    return isZeroOnepresent();
}

void doOneSwap() {
    for ( int i = attacksz-2; i>=0; --i) {
        if( attack_arr[i] == 0 && attack_arr[i+1] == 1) {
//            cout << __FUNCTION__ <<" swap done at " << i<< endl;
            attack_arr[i] = 1;
            attack_arr[i+1] = 0;
            return;
        }
    }
}

int getswaps() {
    int num_of_swaps = 0;
//    cout << "getdamage = "<< getdamage() <<"shield "<<  shield << endl;
    if (getdamage() <= shield) { return 0; }
    else {
        while (isSwapPossible()) {
//            cout << "did one swap" << endl;
            doOneSwap();
            num_of_swaps++;
//            cout << "new getdamage = "<< getdamage() <<"shield "<<  shield << endl;
            if(getdamage() <= shield) return num_of_swaps;
        }
        return -1;
    }
}

int main() {
    int num_of_cases;
    string attack;

    cin >> num_of_cases;  // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 1; i <= num_of_cases; ++i) {
        cin >> shield >> attack; 

        attacksz = attack.length();
        for ( int j = 0; j<attacksz; ++j) {
            (attack.at(j) == 'C')?attack_arr[j] = 0:attack_arr[j] = 1;
        }
        // parameters filled 

        //        cout << "Case #" << i << ": " << shield << " " << attack << endl;
        //        cout << "Case #" << i << " " << getdamage() << endl;
//        cout << "Case #" << i << ": " << shield << " " << attack << endl;
//        print_attack_arr();

        int numswaps = getswaps();
        if (numswaps == -1)
            cout << "Case #" << i << ": " << "IMPOSSIBLE" << endl;
        else 
            cout << "Case #" << i << ": " << numswaps << endl;
    }
    return 0;
}
