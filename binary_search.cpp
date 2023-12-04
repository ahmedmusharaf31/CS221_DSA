#include <iostream>
using namespace std;

int binary_search(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    int array[7] = {22, 33, 44, 55, 66, 77, 88};
    int array_index = binary_search(array, 7, 88);
    cout << "Element 88 is found at " << array_index << " index ";
    cout << "\n";
    return 0;
}

// #include <iostream>
// using namespace std;

// int main()
// {
//     const int num = 9;
//     int arr[num];
//     cout << "Input: ";
//     for (int i = 0; i < num; i++)
//     {
//         cin >> arr[i];
//     }
//     for (int i = 0; i < num - 1; i += 2)
//     {
//         for (int j = i + 2; j < num; j += 2)
//         {
//             if (arr[i] < arr[j])
//             {
//                 int temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
//     for (int i = 1; i < num - 1; i += 2)
//     {
//         for (int j = i + 2; j < num; j += 2)
//         {
//             if (arr[i] > arr[j])
//             {
//                 int temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
//     cout << "\nOutput: ";
//     for (int i = 0; i < num; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }
