#include <iostream>
using namespace std;

//anak kiri = (parent * 2) + 1
//anak kanan = (parent * 2) + 2
void findMax(int node[], int index){
    int max = node[index];
    while(node[index] != 0){
        max = node[index];
        index = (index * 2) + 2;
    }
}