#include <iostream>
using namespace std;
int a[1000000];

void swap(int &x, int &y) {
    int z = x;
    x = y;
    y = z;
}
//스왑함수. 주소값을 받아오네요

int choosePivot(int low, int high) {
    return low + (high-low)/2;
}
//피봇 정하는 함수. 중간 따리에 넣는것을 볼수있고

int partition(int low, int high) {
    int pivotIndex = choosePivot(low, high);
    int pivotValue = a[pivotIndex];
    swap(a[pivotIndex], a[high]);
    int storeIndex = low;
    for (int i=low; i<high; i++) {
        if (a[i] < pivotValue) {
            swap(a[i], a[storeIndex]);
            storeIndex += 1;
        }
    }
    swap(a[storeIndex], a[high]);
    return storeIndex;
}
void quicksort(int low, int high) {
    if (low < high) {
        int pivot = partition(low, high);
        quicksort(low, pivot-1);
        quicksort( pivot+1, high);
    }
}
int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    quicksort(0, n-1);
    for (int i=0; i<n; i++) {
        printf("%d\n",a[i]);
    }
    return 0;
}