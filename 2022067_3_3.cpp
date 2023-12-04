#include <iostream>
using namespace std;

// Merge two sorted subarrays into a single sorted subarray
void merge(int array[], int const left, int const mid, int const right)
{
    // Calculate sizes of the two subarrays to be merged
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temporary arrays to hold the subarrays
    auto *leftArray = new int[subArrayOne];
    auto *rightArray = new int[subArrayTwo];

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOne; i++)
    {
        leftArray[i] = array[left + i];
    }
    for (int j = 0; j < subArrayTwo; j++)
    {
        rightArray[j] = array[mid + 1 + j];
    }

    // Merge the two subarrays back into the original array
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of leftArray[], if there are any
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of rightArray[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }

    // Free the memory allocated for temporary arrays
    delete[] leftArray;
    delete[] rightArray;
}

// Iterative Merge Sort (Implicit use of Stack)
void mergeSort(int array[], int size)
{
    // Iterate over different subarray sizes
    for (int currentSize = 1; currentSize <= size - 1; currentSize *= 2)
    {
        // Iterate over subarrays of the current size
        for (int left = 0; left < size - 1; left += 2 * currentSize)
        {
            int mid = min(left + currentSize - 1, size - 1);
            int right = min(left + 2 * currentSize - 1, size - 1);

            // Merge the subarrays
            merge(array, left, mid, right);
        }
    }
}

// Print an array
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    // Given array
    int arr[] = {7, 8, 9, 4, 7, 2, 1, 6, 8, 17, 16};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    // Display the original array
    cout << "Given array is:\n";
    printArray(arr, arr_size);

    // Sort the array using iterative merge sort
    mergeSort(arr, arr_size);

    // Display the sorted array
    cout << "\nSorted array is:\n";
    printArray(arr, arr_size);

    return 0;
}
