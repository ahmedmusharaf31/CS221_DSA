// #include <iostream>
// using namespace std;

// int main()
// {
//     int tt;
//     cin >> tt;
//     while (tt--)
//     {
//         int tc;
//         cin >> tc;
//         int arr[tc];

//         for (int i = 0; i < tc; i++)
//         {
//             cin >> arr[i];
//         }

//         for (int i = 0; i < tc - 1; i++)
//         {
//             for (int j = i + 1; j < tc; j++)
//             {
//                 if (arr[i] > arr[j])
//                 {
//                     int temp = arr[i];
//                     arr[i] = arr[j];
//                     arr[j] = temp;
//                 }
//             }
//         }

//         for (int i = 0; i < tc; i++)
//         {
//             if (arr[i] == 0 && i < tc -1)
//             {
//                 arr[i] = arr[i + 1];
//             }
//         }

//         arr[0] += 1;

//         int var = 1;
//         for (int i = 0; i < tc; i++)
//         {
//             var *= arr[i];
//         }

//         cout << var << endl;
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int tt;
//     cin >> tt;
//     int temp1;
//     while (tt--)
//     {
//         int tc;
//         cin >> tc;
//         int arr[tc];
//         for (int i = 0; i < tc; i++)
//         {
//             cin >> temp1;
//             if(temp1<0){
//                 temp1 *= -1;
//             }
//             arr[i]=temp1;
//         }
//     int min = arr[0];
//     for(int i =1; i<tc; i++){
//         if(arr[i]<min){
//             min=arr[i];
//         }
//     }
//     cout<<min;
//     return 0;
// }
// }

