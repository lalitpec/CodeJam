#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std; 
#define GREEDYATTEMPT 40
//#define GREEDYATTEMPT 3

//ofstream myfile;
int a_value;
int fill_length;
int fill_arr[67][3];
int get_x, get_y;
int send_x, send_y;
int midx = 500;
int midy = 500;
int startx, starty;

void flusharray() {
    for (int i = 0; i < fill_length; ++i) {
        for (int j = 0; j < 3; ++j) {
            fill_arr[i][j] = 0;
        }
    }
}

void init_startxy() {
    midx += rand() % 30 - 15; 
    midy += rand() % 30 - 15; 
    startx = midx - (fill_length/2);
    starty = midy - 1;
}

void send_x_y(int x, int y) {
//    myfile << "sending " << x << "," << y << endl;
    cout << x+startx << " " << y+starty << endl;
//    myfile << "sending(translated) " << x+startx << "," << y+starty << endl;
}

bool get_x_y() {
    int x,y;
    cin >> x >> y;
//    myfile << "got x,y :" << x<< ","<< y << endl;
    if (x == 0 && y == 0) {
//        myfile << "got true"<< endl;
        return true;
    }
    fill_arr[x-startx][y-starty] = 1;
    return false;
}
/*
void print_arr(){
//    myfile << "array situation: \n:";
    for (int i = 0; i < fill_length; ++i) {
        for (int j = 0; j < 3; ++j) {
//            myfile << fill_arr[i][j] << " ";
        }
//        myfile << endl;
    }
//    myfile << endl;
}
*/
bool greedyfill() {
    for (int i = 0; i < fill_length/3; i++) {
        for (int j=0; j< GREEDYATTEMPT; j++) {
//            myfile << "fill attempt " << j << endl;
            send_x_y(3*i + 1, 1);
            if (get_x_y()) { return true; }
        }
//        print_arr();
    }
    // one more for the remaining row
    if (fill_length%3 != 0) {
        for (int j=0; j< GREEDYATTEMPT; j++) {
//            myfile << "fill attempt " << j << endl;
            send_x_y(fill_length-2,1);
            if (get_x_y()) { return true; }
        }
    }
    return false;
}

bool completefill() {

    int i = 1;
    while (fill_arr[0][0] == 0){
//myfile << "situation " << i << endl; i++;
        send_x_y(1,1);
        if (get_x_y()) { return true; }
    }
    while (fill_arr[0][2] == 0){
//myfile << "situation " << i << endl; i++;
        send_x_y(1,1);
        if (get_x_y()) { return true; }
    }
    while (fill_arr[0][1] == 0){
//myfile << "situation " << i << endl; i++;
        send_x_y(1,1);
        if (get_x_y()) { return true; }
    }
    while (fill_arr[fill_length-1][0] == 0){
//myfile << "situation " << i << endl; i++;
        send_x_y(fill_length-2,1);
        if (get_x_y()) { return true; }
    }
    while (fill_arr[fill_length-1][2] == 0){
//myfile << "situation " << i << endl; i++;
        send_x_y(fill_length-2,1);
        if (get_x_y()) { return true; }
    }
    while (fill_arr[fill_length-1][1] == 0){
//myfile << "situation " << i << endl; i++;
        send_x_y(fill_length-2,1);
        if (get_x_y()) { return true; }
    }

    while (fill_arr[1][0] == 0){
//myfile << "situation " << i << endl; i++;
        send_x_y(1,1);
        if (get_x_y()) { return true; }
//myfile << "situation " << i << endl; i++;
        send_x_y(2,1);
        if (get_x_y()) { return true; }
    }
    while (fill_arr[1][2] == 0){
        send_x_y(1,1);
//myfile << "situation " << i << endl; i++;
        if (get_x_y()) { return true; }
        send_x_y(2,1);
//myfile << "situation " << i << endl; i++;
        if (get_x_y()) { return true; }
    }
    while (fill_arr[1][1] == 0){
        send_x_y(1,1);
//myfile << "situation " << i << endl; i++;
        if (get_x_y()) { return true; }
        send_x_y(2,1);
//myfile << "situation " << i << endl; i++;
        if (get_x_y()) { return true; }
    }
    while (fill_arr[fill_length-2][0] == 0){
        send_x_y(fill_length-2,1);
//myfile << "situation " << i << endl; i++;
        if (get_x_y()) { return true; }
        send_x_y(fill_length-3,1);
//myfile << "situation " << i << endl; i++;
        if (get_x_y()) { return true; }
    }
    while (fill_arr[fill_length-2][2] == 0){
        send_x_y(fill_length-2,1);
//myfile << "situation " << i << endl; i++;
        if (get_x_y()) { return true; }
        send_x_y(fill_length-3,1);
//myfile << "situation " << i << endl; i++;
        if (get_x_y()) { return true; }
    }
    while (fill_arr[fill_length-2][1] == 0){
        send_x_y(fill_length-2,1);
//myfile << "situation " << i << endl; i++;
        if (get_x_y()) { return true; }
        send_x_y(fill_length-3,1);
//myfile << "situation " << i << endl; i++;
        if (get_x_y()) { return true; }
    }

    for (int i = 2; i < fill_length-3; i++) {
        for (int j = 0; j < 3; j++) {
            while ( fill_arr[i][j] == 0) {
                send_x_y(i-1,1);
                if (get_x_y()) { return true; }
                send_x_y(i,1);
                if (get_x_y()) { return true; }
                send_x_y(i+1,1);
                if (get_x_y()) { return true; }
            }
        }
    }
}

int main() {
    int num_of_cases;
    srand (time(NULL));

    cin >> num_of_cases;
    //myfile.open ("log.txt");
    //myfile << "num of cases " << num_of_cases << endl;

    for (int i = 1; i <= num_of_cases; ++i) {

        //myfile << "case number " << i << endl;
        cin >> a_value;
        fill_length = (a_value/3) + 1;
        //myfile << "avalue, fill_length " << a_value<< " "<< fill_length << endl;

        init_startxy();
        //myfile << "startx, starty " << startx << " " << starty << endl;
        flusharray();
//        print_arr();
        if (greedyfill()) { continue; }
//        print_arr();
        if (completefill()) { continue; }
//        print_arr();

    }

    //myfile.close();
    return 0;
}

