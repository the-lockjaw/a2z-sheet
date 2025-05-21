#include<iostream>
using namespace std;

int search(int arr[], int target, int n){
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==target)
        {
            ans = i;
            break;
        }
    }
    return ans;
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int target = 2;
    int size = sizeof(arr)/sizeof(arr[0]);
}