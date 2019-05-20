    for(int i=0; i<n; i++){
        int val = (rand()%100)+1;
        data[i] = val;
    }

    qs.quickSort(data, 0, n-1);
    printArray(data, n, "quick : ");