#include <iostream>  // includes cin to read from stdin and cout to write to stdout
#include <string>
#include <vector>
#include <sstream>      // std::istringstream
//#include <stdlib.h>     /* atoi */



using namespace std;  // since cin and cout are both in namespace std, this saves some text

unsigned long long int in_arr[100];
int sample_size;

std::vector<std::string> split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

void print_in_arr() {
    //   cout << "sample_size = " << sample_size << endl; 
    cout << " in_arr# ";
    for ( int j = 0; j<sample_size; ++j) {
        cout << in_arr[j] << " ";
    }
    cout << endl;
}

void stringvec_tointarr(std::vector<std::string> numarr) {
    for ( int i = 0; i<numarr.size(); ++i) {
        //        in_arr[i] = stoi(numarr.at(i));
        //        in_arr[i] = atoi(numarr.at(i).c_str())
        istringstream( numarr.at(i).c_str())>> in_arr[i];
        //        std::string::size_type sz;
    } 
}

void troubleSort() {
    bool done = false;
    unsigned long long int temp = 0;
    while (!done) {
        done = true;
        for ( int i = 0; i<sample_size-2; ++i) {
//            cout << __FUNCTION__ << "i  in for = " << i << endl;
//            cout << "i and +2 " << in_arr[i] << ", " << in_arr[i+2] << endl;
            if (in_arr[i] > in_arr[i+2]) {
//                cout << __FUNCTION__ << "i = " << i << endl;
                done = false;
                temp = in_arr[i];
                in_arr[i] = in_arr[i+2];
                in_arr[i+2] = temp;
            }
        }
    }
}

int getbadindex() {
    int badindex = -1;
    for ( int i = 0; i<sample_size-1; ++i) {
        if (in_arr[i] > in_arr[i+1]) {
            return i;
        }
    }
    return -1;
}

int main() {
    int num_of_cases;
    int temp_int;
    string temp_string, sample_size_string, num_of_cases_string;

    //cin >> num_of_cases;  // read t. cin knows that t is an int, so it reads it as such.
    std::getline (std::cin,num_of_cases_string);
    stringstream geek(num_of_cases_string);
    geek >> num_of_cases;
    //    cout << "num_of_cases"<< num_of_cases << endl;

    for (int i = 1; i <= num_of_cases; ++i) {
        //    cin >> sample_size; 
        std::getline (std::cin,sample_size_string);
        stringstream geek2(sample_size_string);
        geek2 >> sample_size;
        //        cout << "sample_size "<< sample_size << endl;
        //std::getline (std::cin,sample_size_string);
        //        cout << "sample_size "<< sample_size << endl;
        //cout << "sample_size string  "<< sample_size_string << endl;

        std::getline (std::cin,temp_string);
        //        stringstream geek3(temp_string);
        //        cin >> temp_string;
        //        geek3 >> temp_string;
        //        cout << "geek3 " << geek3 << endl;
        //        cout << "temp string " << temp_string << endl;
        std::vector<std::string> numarr = split(temp_string, ' ');
        stringvec_tointarr(numarr);

        /*
           for (int j = 0; i < sample_size; ++j) {
           cin >> temp_int;
           in_arr[j] = temp_int;
           }
           */
        //cout << "numarr " << numarr << endl;
//        print_in_arr();
//        cout << "going to trouble " << endl;
        troubleSort();
//        print_in_arr();

        int badindex = getbadindex();
        if (badindex == -1) {
            cout << "Case #" << i << ": OK" << endl;
        }
        else {
            cout << "Case #" << i << ": " << badindex << endl;
        }
    }
    return 0;
}
