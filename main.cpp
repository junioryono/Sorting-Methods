// Name: Amer Yono
// Student ID: 200711334
// Email: yono004@cougars.csusm.edu

#include <iostream>
using namespace std;

void swap(int *firstValue, int *secondValue) {
    int temp = *firstValue;
    *firstValue = *secondValue;
    *secondValue = temp;
}

void print(int A[], int len) {
    for (int i = 0; i < len; i++)
        if (i == len - 1) cout << A[i] << "\n";
        else cout << A[i] << ", ";
}
  
void selectionSort(int A[], int len) {    
    for (int i = 0; i < len - 1; i++) {  
        int firstValue = i;
        for (int secondValue = i + 1; secondValue < len; secondValue++)
            if (A[secondValue] < A[firstValue]) firstValue = secondValue;
            swap(&A[firstValue], &A[i]);
    }
}

void bubbleSort(int A[], int len) {
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - i - 1; j++)
            if (A[j] > A[j + 1])
                swap(&A[j], &A[j + 1]);
}

void insertionSort(int A[], int len) {
    for (int i = 1; i < len; i++) {
        int shift = A[i];
        int pivot = i - 1;

        while (pivot >= 0 && A[pivot] > shift) { 
            A[pivot + 1] = A[pivot];
            pivot = pivot - 1;
        }

        A[pivot + 1] = shift;
    } 
}

void quick(int A[], int low, int high) {
    int lowTemp = low;
    int highTemp = high;
    int pivot = A[(lowTemp + highTemp) / 2];
    int temp;

    while (lowTemp <= highTemp) {
        while (A[lowTemp] < pivot) lowTemp++;
        while (A[highTemp] > pivot) highTemp--;

        if (lowTemp <= highTemp) {
            swap(&A[lowTemp], &A[highTemp]);
            lowTemp++;
            highTemp--;
        }
    }

    if (highTemp > low) quick(A, low, highTemp);
    if (lowTemp < high) quick(A, lowTemp, high);
}

void quickSort(int A[], int len) {
    quick(A, 0, len);
}

void merge(int A[], int leftArray[], int leftCount, int rightArray[], int rightCount) {
    int i = 0;
    int leftIndex = 0;
    int rightIndex = 0;

    while (leftIndex < leftCount && rightIndex < rightCount) {
        if (leftArray[leftIndex] < rightArray[rightIndex]) {
            A[i] = leftArray[leftIndex];
            leftIndex++;
        } else {
            A[i] = rightArray[rightIndex];
            rightIndex++;
        }
        i++;
    }

    while (leftIndex < leftCount) {
        A[i] = leftArray[leftIndex];
        leftIndex++;
        i++;
    }

    while (rightIndex < rightCount) {
        A[i] = rightArray[rightIndex];
        rightIndex++;
        i++;
    }
}

void mergeSort(int A[], int len) {
    if (len < 2) return;

    int half = len / 2;

    int* leftArray = new int[sizeof(int) * half];
    int* rightArray = new int[sizeof(int) * half];

    for (int i = 0; i < half; i++) leftArray[i] = A[i];
    for (int i = half; i < len; i++) rightArray[i - half] = A[i];
    
    mergeSort(leftArray, half);
    mergeSort(rightArray, len - half);
    merge(A, leftArray, half, rightArray, len - half);

    delete[] leftArray;
    delete[] rightArray;
}

int main() {
    int arraySelectionSort[] = { 96, 252, 1, 37, 12 };
    int arraySelectionSortLength = sizeof(arraySelectionSort) / sizeof(arraySelectionSort[0]);

    cout << "Before Selection Sort:\n";
    print(arraySelectionSort, arraySelectionSortLength);
    cout << "After Selection Sort:\n";
    selectionSort(arraySelectionSort, arraySelectionSortLength);
    print(arraySelectionSort, arraySelectionSortLength);

    cout << endl;

    int arrayBubbleSort[] = { 29, 96, 32, 151, 6 };
    int arrayBubbleSortLength = sizeof(arrayBubbleSort) / sizeof(arrayBubbleSort[0]);

    cout << "Before Bubble Sort:\n";
    print(arrayBubbleSort, arrayBubbleSortLength);
    cout << "After Bubble Sort:\n";
    bubbleSort(arrayBubbleSort, arrayBubbleSortLength);
    print(arrayBubbleSort, arrayBubbleSortLength);

    cout << endl;

    int arrayInsertionSort[] = { 12, 11, 13, 5, 6 }; 
    int arrayInsertionSortLength = sizeof(arrayInsertionSort) / sizeof(arrayInsertionSort[0]); 

    cout << "Before Insertion Sort:\n";
    print(arrayInsertionSort, arrayInsertionSortLength);
    insertionSort(arrayInsertionSort, arrayInsertionSortLength);
    cout << "After Insertion Sort:\n";
    print(arrayInsertionSort, arrayInsertionSortLength);

    cout << endl;

    int arrayQuickSort[] = { 263, 121, 151, 231, 195 }; 
    int arrayQuickSortLength = sizeof(arrayQuickSort) / sizeof(arrayQuickSort[0]); 

    cout << "Before Quick Sort:\n";
    print(arrayQuickSort, arrayQuickSortLength);
    quickSort(arrayQuickSort, arrayQuickSortLength - 1);
    cout << "After Quick Sort:\n";
    print(arrayQuickSort, arrayQuickSortLength);

    cout << endl;

    int arrayMergeSort[] = { 56, 64, 22, 94, 12 }; 
    int arrayMergeSortLength = sizeof(arrayMergeSort) / sizeof(arrayMergeSort[0]); 

    cout << "Before Merge Sort:\n";
    print(arrayMergeSort, arrayMergeSortLength);
    mergeSort(arrayMergeSort, arrayMergeSortLength);
    cout << "After Merge Sort:\n";
    print(arrayMergeSort, arrayMergeSortLength);

    return 0;
}