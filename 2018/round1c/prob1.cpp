#include <iostream>  // includes cin to read from stdin and cout to write to stdout
#include <string>
#include <vector>
#include <sstream>      // std::istringstream

using namespace std;  // since cin and cout are both in namespace std, this saves some text
unsigned long long int in_arr[100000];
unsigned long long int weight_arr[100000];
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

void stringvec_tointarr(std::vector<std::string> numarr) {
    for ( int i = 0; i<numarr.size(); ++i) {
        istringstream( numarr.at(i).c_str())>> in_arr[i];
    } 
}

void print_in_arr() {
    //   cout << "sample_size = " << sample_size << endl; 
    cout << " in_arr# ";
    for ( int j = 0; j<sample_size; ++j) {
        cout << in_arr[j] << " ";
    }
    cout << endl;
}

void small_sort () {
    std::vector<int> v(in_arr, in_arr + sample_size);

    for ( int i = 0; i<sample_size; ++i) {
                }
}

void big_sort() {
}
void build_weight_arr() {
    for ( int i = sample_size -1 ; i>0; --i) {
        for ( int j=sample_size -2; j >=0; --j) {
            weight_arr[i] += weight_arr[j];
        }
    }
}

int main() {
    int num_of_cases;
    string temp_string, sample_size_string, num_of_cases_string;

    std::getline (std::cin,num_of_cases_string);
    stringstream geek(num_of_cases_string);
    geek >> num_of_cases;

    for (int i = 1; i <= num_of_cases; ++i) {
        std::getline (std::cin,sample_size_string);
        stringstream geek2(sample_size_string);
        geek2 >> sample_size;


        std::getline (std::cin,temp_string);
        std::vector<std::string> numarr = split(temp_string, ' ');
        stringvec_tointarr(numarr);

        build_weight_arr();
        for ( int i = 0; i<sample_size; ++i) {
            if( weight_arr[i]*6 <= in_arr[i]) {
                cout << "Case : " << i<< endl;}}
        
        

        if (sample_size == 100000) { 
            big_sort();
        }
        else {
            small_sort();
        }

print_in_arr();
        cout << "Case #" << i << ": OK" << endl;
    }
    return 0;
}
