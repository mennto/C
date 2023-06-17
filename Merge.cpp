#include <iostream>
#include <chrono>

using namespace std;


int mergeSort(int* arr,int size) {
    int sizeA = size / 2;
    int sizeB = size - sizeA;
    
    if (sizeA > 1) {
        mergeSort(arr, sizeA);
    }
    if (sizeB> 1) {
        mergeSort(arr+sizeA, sizeB);
    }

    int* arrMerged = new int[size];

    for (int i = 0,iA=0,iB=0; i < size; i++) {
        if (iA == sizeA || iB == sizeB) {
            if (iA == sizeA) {
                arrMerged[i] = *(arr + sizeA + iB);
                iB++;
            }
            else{
                arrMerged[i] = *(arr + iA);
                iA++;
            }
        }
        else {
            if (*(arr + iA) < *(arr + sizeA + iB)) {
                arrMerged[i] = *(arr + iA);
                iA++;
            }
            else {
                arrMerged[i] = *(arr + sizeA + iB);
                iB++;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        arr[i] = arrMerged[i];
    }

    return 1; 
}


int main() {
    auto start = std::chrono::high_resolution_clock::now();
    cout << "Enter size of Array: ";
    int n;
    cin >> n;
    cout << "Enter array elements: ";
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergeSort(arr,n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    cout <<"time: "<< duration.count();

    return 0;
}