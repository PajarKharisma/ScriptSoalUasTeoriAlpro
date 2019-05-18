#include <iostream>
using namespace std;

int main(){
    int data[] = {20, 40, 10, 15, 50, 48, 22, 30, 35, 19};
    int n = sizeof(data) / sizeof(data[0]);
    cout << "sizeof(data) : " << sizeof(data) << endl;
    cout << "sizeof(data[0]) : " << sizeof(data[0]) << endl;

    int sum = 0;
    for(int i=0; i<n; i++){
        sum += data[i];
    }

    cout << sum << endl;
}