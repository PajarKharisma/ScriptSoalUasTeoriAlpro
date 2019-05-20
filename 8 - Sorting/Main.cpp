#include <iostream>
#include <conio.h> //delete this line if you use linux
#include <stdlib.h>
#include <ctime>
using namespace std; 

int counter = 0;

//CLASS MERGE SORT
class MergeSort{
    private:
        //PROSES MENGGABUNGKAN DATA ARRRAY DAN MENGURUTKANNYA
        void merge(int *arr, int l, int m, int r){
            int i, j, k; 
            int n1 = m - l + 1; 
            int n2 =  r - m;
            int *L = new int[n1];
            int *R = new int[n2]; 
        
            for (i = 0; i < n1; i++) 
                L[i] = arr[l + i]; 
            for (j = 0; j < n2; j++) 
                R[j] = arr[m + 1+ j]; 
        
            i = 0;
            j = 0; 
            k = l;
            while (i < n1 && j < n2){ 
                counter++;
                if (L[i] <= R[j]) { 
                    arr[k] = L[i]; 
                    i++; 
                } 
                else{ 
                    arr[k] = R[j]; 
                    j++; 
                } 
                k++; 
            } 

            while (i < n1){ 
                arr[k] = L[i]; 
                i++; 
                k++; 
            } 

            while (j < n2){ 
                arr[k] = R[j]; 
                j++; 
                k++; 
            }
            delete L;
            L = NULL;
            delete R;
            R = NULL;
        }

    public: 
        //PROSES MEMBAGI ARRAY
        void mergeSort(int *arr, int l, int r){ 
            if (l < r){ 
                int m = l+(r-l)/2; 
                mergeSort(arr, l, m); 
                mergeSort(arr, m+1, r); 
                merge(arr, l, m, r); 
            } 
        }
};

class QuickSort{
    private:
        //PROSES MEMPARTISI ARRAY BERDASARKAN PIVOT, PIVOT DIAMBIL DARI ELEMEN PERTAMA
        int partisi(int *data, int low, int high){
            int pivot = low;
            int i = low;
            for (int j=low+1; j<=high; j++){
                counter++;
                if (data[j] < data[pivot]){
                    i++;
                    swap(data[i], data[j]);
                }
            }
            swap(data[pivot], data[i]);
            return i;
        }

    public:
        void quickSort(int *data, int low, int high){
            if (low < high){
                int pi = partisi(data, low, high);
                quickSort(data, low, pi-1);
                quickSort(data, pi+1, high);
            }
        }
};

class HeapSort{
    private:
        //PROSES BUILD HEAP TREE BERDASARKAN DATA ARRAY
        void heapify(int *arr, int n, int i) { 
            int largest = i;
            int l = 2*i + 1;
            int r = 2*i + 2;
            
            if (l < n && arr[l] > arr[largest]) 
                largest = l; 

            if (r < n && arr[r] > arr[largest]) 
                largest = r; 

            if (largest != i){ 
                swap(arr[i], arr[largest]); 
                heapify(arr, n, largest); 
            } 
        } 

    public:
        //PROSES HEAPSORT DENGAN MENGAMBIL DATA ROOT
        void heapSort(int *arr, int n){
            for (int i = n / 2 - 1; i >= 0; i--) 
                heapify(arr, n, i); 

            for (int i=n-1; i>=0; i--){ 
                swap(arr[0], arr[i]);
                heapify(arr, i, 0); 
            } 
        }
};

class RadixSort{
    private:
        int getMax(int *arr, int n){ 
            int mx = arr[0]; 
            for (int i = 1; i < n; i++) 
                if (arr[i] > mx) 
                    mx = arr[i]; 
            return mx; 
        } 

        void countSort(int *arr, int n, int exp){ 
            int output[n]; // output array 
            int i, count[10] = {0}; 
        
            for (i = 0; i < n; i++) 
                count[ (arr[i]/exp)%10 ]++; 
        
            for (i = 1; i < 10; i++) 
                count[i] += count[i - 1]; 
        
            for (i = n - 1; i >= 0; i--){ 
                output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
                count[ (arr[i]/exp)%10 ]--; 
            }

            for (i = 0; i < n; i++) 
                arr[i] = output[i]; 
        } 

    public:
        void radixsort(int *arr, int n){
            int m = getMax(arr, n);
            for (int exp = 1; m/exp > 0; exp *= 10) 
                countSort(arr, n, exp); 
            }
};

class BubbleSort{
    public:
        void bubbleSort(int *data, int n){
            for(int i=0; i<n; i++){
                for(int j=0; j<n-1; j++){
                    counter++;
                    if(data[j] > data[j+1]){
                        swap(data[j],data[j+1]);
                    }
                }
            }
        }
};

class SelectionSort{
    public:
        void selectionSort(int *data, int n){
            for(int i=0; i<n; i++){
                int minIndex = i;
                for(int j=i+1; j<n; j++){
                    counter++;
                    if(data[j] < data[minIndex]){
                        minIndex = j;
                    }
                }
                swap(data[i], data[minIndex]);
            }
        }
};

void printArray(int arr[], int n, string title){
    cout << title << " : ";
	for (int i=0; i<n; ++i) 
		cout << arr[i] << " ";
	cout << endl; 
} 

int main() { 
    HeapSort hs;
    MergeSort ms;
    QuickSort qs;
    RadixSort rs;
    BubbleSort bs;
    SelectionSort ss;

    int n;
    int *data;


    cout << "Input banyak data : ";
    cin >>  n;
    data = new int[n];

    //int arr[] = {71, 70, 98, 25, 35, 73, 27, 8, 84, 20, 12, 28};
    for(int i=0; i<n; i++){
        int val = (rand()%100)+1;
        data[i] = val;
    }

    //ms.mergeSort(data, 0, n-1);
    qs.quickSort(data, 0, n-1);
    //bs.bubbleSort(data, n);
    printArray(data, n, "Hasil : ");
    cout << "Jumlah Perbandingan : " << counter << endl;

    getch(); //delete this line if you use linux
} 