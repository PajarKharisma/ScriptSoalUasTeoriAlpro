#include <iostream>
#include <vector>
using namespace std;

#define NUM_OF_INDEX 10

class HashMap{
    private:
        vector<int> temp;

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

    public:
        void hashing(int database[], int data){
            int p = getBigestPrime(NUM_OF_INDEX);
            int index = data % p;
            if(database[index] == 0){
                database[index] = data;
            }else{
                temp.push_back(data);
            }
        }

        void linerProbing(int database[]){
            for(int data:temp){
                int p = getBigestPrime(NUM_OF_INDEX);
                int index = data % p;
                while(database[index] != 0){
                    index++;
                    if(index > NUM_OF_INDEX - 1)
                        index = index % NUM_OF_INDEX;
                }
                database[index] = data;
            }
        }
};

int main(){
    HashMap hashMap;
    int database[NUM_OF_INDEX] = {0};
    for(int i=0; i<NUM_OF_INDEX; i++){
        int val = (rand() % 10) + 1;
        cout << val << " ";
        hashMap.hashing(database, val);
    }
    cout << endl;
    hashMap.linerProbing(database);
    for(int i=0; i<NUM_OF_INDEX; i++){
        cout << "[" << i << "] : " << database[i] << endl;
    }
}