
#include <iostream>  // includes cin to read from stdin and cout to write to stdout
#include <string>
#include <cmath>

using namespace std; 

double a_value;
double arr[3][3];

void init_arr() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            arr[i][j] = 0.00;
        }
    }
}

void print_arr() {
    cout.precision(17);
    string line;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            line.append (std::to_string(arr[i][j]));
            line.append(" ");
        }
        line.pop_back();
        cout << line << endl;
        line.clear();
    }
}

void get_angles() {
    cout.precision(17);
    if ( a_value == 1) {
        arr[0][0] = 0.5;
        arr[1][1] = 0.5;
        arr[2][2] = 0.5;
        return;
    }
    else if  ( a_value < sqrt(2)) {
//        double x = cos (M_PI/4.00);
//        double y = sin (M_PI/4.00);
//        cout << "x, y " << x<< " " << y << endl;
/*
        arr[0][0] = x/2.0000;
        arr[0][1] = cos(x)/2.0000;
        arr[1][0] = -cos(x)/2.0000;
        arr[1][1] = sin(x)/2.0000;
        arr[2][2] = 0.5;
*/
        double param = pow(a_value,2) -1.0000;
        double x = asin((pow(a_value,2) -1.0000)) / 2.0000;
        double result = asin (param);
        result /= (double)2.000;

//        cout << "result " << result << endl;
//        cout << "x " << x << endl;
//        cout << "xnew " << (x*180.0)/M_PI << endl;
        
        
        arr[0][0] = sin(result)/2.0000;
        arr[0][1] = cos(result)/2.0000;
        arr[1][0] = -cos(result)/2.0000;
        arr[1][1] = sin(result)/2.0000;
        arr[2][2] = 0.5;
    }
    else {
        double param = (a_value / (sqrt(2)+1));
        double result = acos (param);

        arr[0][0] = sin(M_PI/4)/2.0000;
        arr[0][1] = cos(M_PI/4)/2.0000;
        arr[0][2] = sin(result)/2.0000;

        arr[1][0] = -cos(M_PI/4)/2.0000;
        arr[1][1] = sin(M_PI/4)/2.0000;
        arr[1][2] = sin(result)/2.0000;

        arr[2][0] = sin(M_PI/4)/2.0000;
        arr[2][1] = sin(M_PI/4)/2.0000;
        arr[2][2] = -sin(result)/2.0000;
    }
}

int main () {
    cout.precision(17);
    int num_of_cases;
    cin >> num_of_cases; 
    for (int i = 1; i <= num_of_cases; ++i) {
        cin >> a_value; 
        init_arr();
        cout << "Case #" << i << ":" << endl;
        get_angles();
        print_arr();
    }
    return 0;
}
