#include <iostream>
#include <vector>
#include <set>
using namespace std;

void print_vector(vector<int> &v)
{
    for (auto a : v)
        cout << a << " ";
    cout << endl;
}

// two pointers or set or map
vector<int> find_union(vector<int> &a, vector<int> &b)
{
    set<int> st;
    for (auto x : a)
    {
        st.insert(x);
    }
    for(auto x : b){
        st.insert(x);
    }

    vector<int> ans;
    for(auto x : st){
        ans.push_back(x);
    }
    return ans;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {2, 3, 4, 4};
    vector<int> u = find_union(a, b);
    print_vector(u);
}