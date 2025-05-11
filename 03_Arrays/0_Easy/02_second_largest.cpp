#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

int second_largest(int n, int arr[]){
    if (n<2)
    {
        return -1;
    }
    
    int maxi = INT_MIN;
    int maxi_2 = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        // You should also check that arr[i] != maxi, otherwise the second largest may just be the same as the largest (which is incorrect if all values are the same or the max is repeated).
        if (arr[i] > maxi && arr[i] != maxi)
        {
            maxi_2 = maxi;
            maxi = arr[i];
        }else if (arr[i]>maxi_2)
        {
            maxi_2 = arr[i];
        }        
    }

    return maxi_2;
}

int main()
{
    int arr[] = {1, 2, 3, 45, 5, 4, 0, 1, 132, 4267, 346, 52, 21};
    int size = sizeof(arr) / sizeof(arr[0]);
    int ans = second_largest(size,arr);
    cout << "Second largest element = " << ans << endl;
    return 0;
}