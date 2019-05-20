#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

#define NUM_OF_INDEX 20

class HashMap{
    private:
        //FUNGSI MENCARI NILAI PRIMA TERKECIL KURANG DARI N
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
        //FUNGSI MEMASUKAN DATA KE DALAM HASH TABLE
        void hashing(int database[], int data){
            int p = getBigestPrime(NUM_OF_INDEX);
            int index = data % p;
            //JIKA INDEX HASH TABLE KOSONG, DATA AKAN LANGSUNG DIINSERT
            if(database[index] == 0){
                database[index] = data;
            }else{
                //JIKA TIDAK, AKAN DICARIKAN INDEX LAIN DENGAN ATURAN QUADRATIC
                int i = 1;
                int newPos = index;
                while(database[newPos] != 0){
                    int quadratic = pow(i, 2);
                    newPos = (index + quadratic) % NUM_OF_INDEX;
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
        int val = (rand() % (NUM_OF_INDEX * 2)) + 1;
        hashMap.hashing(database, val);
    }

    for(int i=0; i<NUM_OF_INDEX; i++){
        cout << "[" << i << "] : " << database[i] << endl;
    }
}