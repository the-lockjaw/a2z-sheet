// follow-up of last question, just print the subarray for which you got the maximum sum
#include <iostream>
using namespace std;

void print_subarray(int arr[], int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int max_subarray_sum(int arr[], int n)
{
    int sum = arr[0];
    int ans = arr[0];
    int start = 0;
    int end = 0;
    for (int i = 1; i < n; i++)
    {
        if (sum < 0)
        {
            start = end = i;
            sum = 0;
        }
        sum += arr[i];
        if (sum > ans)
        {
            end = i;
            ans = sum;
        }
    }
    cout << "Start = " << start << endl;
    cout << "End = " << end << endl;
    cout << "Printing max subarray : ";
    print_subarray(arr, start, end);
    return ans;
}

int main()
{
    int arr[] = {1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int ans = max_subarray_sum(arr, size);
    cout << "Maximum subarray sum = " << ans << endl;
}