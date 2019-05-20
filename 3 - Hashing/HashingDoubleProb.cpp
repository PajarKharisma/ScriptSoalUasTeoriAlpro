#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

#define NUM_OF_INDEX 30

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

        //FUNGSI HASH KEDUA. AKAN DIJALANKAN JIKA TERJADI COLISION
        int hash2(int data){
            int p = getBigestPrime(NUM_OF_INDEX);
            return p - (data % p);
        }

    public:
        //FUNGSI MEMASUKAN DATA DALAM TABLE HASH
        void hashing(int database[], int data){
            int p = getBigestPrime(NUM_OF_INDEX);
            int index = data % p;
            //JIKA TABLE KOSONG, DATA AKAN LANGSUNG DIMASUKAN
            if(database[index] == 0){
                database[index] = data;
            }else{
                //JIKA TABLE SUDAH DIISI MAKA AKAN DICARI INDEX LAIN DENGAN MENGGUNAKAN FUNGSI HASH2
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