#include <iostream>
#include <vector>
using namespace std;

#define NUM_OF_INDEX 20

class HashMap{
    private:
        //ARRAY DINAMIS UNTUK MENYIMPAN DATA YANG COLISION
        vector<int> temp;

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
            //JIKA HASH TABLE KOSONG, DATA AKAN LANGSUNG DIINSERT
            if(database[index] == 0){
                database[index] = data;
            }else{
                //JIKA TIDAK, DATA AKAN DIMASUKAN DALAM ARRAY DINAMIS DAN AKAN DIPROSES JIKA SEMUA DATA SUDAH SELESAI
                temp.push_back(data);
            }
        }

        //FUNGSI MASUKAN DATA DALAM ARRAY DINAMIS KE DALAM HASH TABLE, JIKA TERJADI COLISION, INDEX AKAN BERGESER SATU
        //PROSES INI AKAN DILAKUKAN TERUS HINGGA DITEMUKAN INDEX YANG KOSONG PADA HASH TABLE
        void linerProbing(int database[]){
            for(int data:temp){
                int p = getBigestPrime(NUM_OF_INDEX);
                int index = data % p;
                while(database[index] != 0){
                    index++;
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
        int val = (rand() % 50) + 1;
        cout << val << " ";
        hashMap.hashing(database, val);
    }
    cout << endl;
    hashMap.linerProbing(database);
    for(int i=0; i<NUM_OF_INDEX; i++){
        cout << "[" << i << "] : " << database[i] << endl;
    }
}