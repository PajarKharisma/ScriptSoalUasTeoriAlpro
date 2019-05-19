#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

#define NUM_OF_INDEX 30

class HashMap{
    private:
        int getBigestPrime(int val){
            bool isPrime = false;
            int bigestPrime = -1;
            while(!isPrime && val >= 0){
                int cek = 0;
                for(int i=1; i<=val; i++){
                    if(val % i == 0){
                        cek++;
                    }
                }
                if(cek <= 2){
                    isPrime = true;
                    bigestPrime = val;
                }
                val--;
            }
            return bigestPrime;
        }

        int hash2(int data){
            int p = getBigestPrime(NUM_OF_INDEX);
            return p - (data % p);
        }

    public:
        void hashing(int database[], int data){
            int p = getBigestPrime(NUM_OF_INDEX);
            int index = data % p;
            if(database[index] == 0){
                database[index] = data;
            }else{
                int i=1;
                int newPos = index;
                while(database[newPos] != 0){
                    newPos = (index + (i * hash2(data))) % NUM_OF_INDEX;
                    i++;
                }   
                database[newPos] = data;
            }
        }
};

int main(){
    HashMap hashMap;
    int database[NUM_OF_INDEX] = {0};
    int n = NUM_OF_INDEX / 2;

    for(int i=0; i<n; i++){
        int val = (rand() % (NUM_OF_INDEX * 3)) + 1;
        //cout << val << " ";
        hashMap.hashing(database, val);
    }

    cout << endl;

    for(int i=0; i<NUM_OF_INDEX; i++){
        cout << "[" << i << "] : " << database[i] << endl;
    }
}