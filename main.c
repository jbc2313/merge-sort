#include <stdio.h>


void listArray(int *pntr, int size) {
    int x; 
    for (x = 0; x < size; x++) {
        printf("array[%d]=%d\n", x, pntr[x]);
    };
};

void sort(int *pntr, int low, int mid, int high) {
    int x, y, z;
    int nLow = mid - low + 1;
    int nHigh = high - mid;
    int lowArr[nLow], highArr[nHigh];

    // copy to both temp arrays
    for (x = 0; x < nLow; x++) {
        lowArr[x] = pntr[low + x];
    };
    for (y = 0; y < nHigh; y++) {
        highArr[y] = pntr[mid + low + y];
    };
    
    // merge temp arrays back together pntr[low...high]
    
    // index of lowArr
    x = 0;
    // index of highArr
    y = 0;
    // index of merged arrays
    z = low;

    while (x < nLow && y < nHigh) {
        if (lowArr[x] <= highArr[y]) {
            pntr[z] = lowArr[x];
            x++;
        } else {
            pntr[z] = highArr[y];
            y++;
        };
        z++;
    };

    while (x < nLow) {
        pntr[z] = lowArr[x];
        x++;
        z++;
    };

    while (y < nHigh) {
        pntr[z] = highArr[y];
        y++;
        z++;
    };

};

void merge (int *pntr, int low, int high) {
    if ( low < high ) {
        // (low + high)/2 will work too, below prevents overflow 
        int mid = low + (high - 1) / 2;
        merge(pntr, low, mid);
        merge(pntr, mid+low, high);
        sort(pntr, low, mid, high);

    }
};



int main() {
    int array[] = { 2, 12, 3, 1, 29, 9, 8, 15, 13 };
    int size = sizeof(array) / sizeof(array[0]);
    listArray(array, size);
    merge(array, 0, size - 1);
    printf("Array was sorted!");
    listArray(array, size);
    return 0;
};
