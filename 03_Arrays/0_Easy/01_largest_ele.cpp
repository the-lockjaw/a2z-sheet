#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;

int main(){
    int arr[] = {1,2,3,45,5,4,0,1,132,4267,346,52,21};
    // we must start checking from the minimum value possible as if all elements are equal to INT_MIN then that will be the answer.
    int maxi = INT_MIN;
    int size = sizeof(arr)/sizeof(arr[0]);
    if (size==0)
    {
        cout<<"No elements present"<<endl;
        return 0;
    }
    for (int i = 0; i < size; i++)
    {
        maxi = max(arr[i],maxi);
    }
    cout<<"Maximum element = "<<maxi<<endl;
    return 0;
}