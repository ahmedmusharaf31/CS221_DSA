// #include <iostream>
// using namespace std;

// int first_occurrence(int arr[], int size, int key)
// {
//     int s = 0;
//     int e = size - 1;
//     int ans = -1;
//     int mid = (s + e) / 2;
//     while (s <= e)
//     {
//         if (arr[mid] == key)
//         {
//             ans = mid;
//             e = mid - 1;
//         }
//         if (key > arr[mid])
//         {
//             s = mid + 1;
//         }
//         else
//         {
//             e = mid - 1;
//         }
//         mid = (s + e) / 2;
//     }
//     return ans;
// }

// int last_occurrence(int arr[], int size, int key)
// {
//     int s = 0;
//     int e = size - 1;
//     int ans = -1;
//     int mid = (s + e) / 2;
//     while (s <= e)
//     {
//         if (arr[mid] == key)
//         {
//             ans = mid;
//             s = mid + 1;
//         }
//         if (key > arr[mid])
//         {
//             s = mid + 1;
//         }
//         else
//         {
//             e = mid - 1;
//         }
//         mid = (s + e) / 2;
//     }
//     return ans;
// }

// int main()
// {
//     int array[11] = {1, 2, 3, 3, 4, 5, 6, 3, 3, 3, 9};
//     cout << "First occurrence of element 3 is at index " << first_occurrence(array, 11, 3) << endl;
//     cout << "Last occurrence of element 3 is at index " << last_occurrence(array, 11, 3) << endl;
//     return 0;
// }

#include <iostream>
#include <array>
using namespace std;

int firstOccurance(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int mid = (s + e) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        mid = (s + e) / 2;
    }
    return ans;
}
int lastOccurance(int arr[], int n, int w)
{
    int s = 0;
    int e = n - 1;
    int mid = (s + e) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == w)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] > w)
        {
            e = mid - 1;
        }
        else if (arr[mid] < w)
        {
            s = mid + 1;
        }
        mid = (s + e) / 2;
    }
    return ans;
}
int main()
{
    int arr[6] = {1, 2, 3, 12, 12, 12};
    cout << "First occurance index is " << firstOccurance(arr, 6, 12) << endl;
    cout << "last occurance index is " << lastOccurance(arr, 6, 12) << endl;
    return 0;
}
