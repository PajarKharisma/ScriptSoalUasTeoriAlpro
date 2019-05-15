#include <iostream>
#include <conio.h>
using namespace std;

int main(){
    int data[] = {1, 11, 31, 62, 71, 81, 12, 2, 13, 23};
    int n = sizeof(data)/sizeof(data[0]);

    for(int i=0; i<n; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(data[j] < data[minIndex]){
                minIndex = j;
            }
        }
        swap(data[minIndex], data[i]);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(data[j]%10 > data[j+1]%10){
                swap(data[j], data[j+1]);
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << data[i] << " ";
    }

    getch();
}