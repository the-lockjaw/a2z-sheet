/*
207. Course Schedule
Medium

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Constraints:
    1 <= numCourses <= 2000
    0 <= prerequisites.length <= 5000
    prerequisites[i].length == 2
    0 <= ai, bi < numCourses
    All the pairs prerequisites[i] are unique.
*/
// Kahn's Algorithm (Iterative Topo Sort)
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> topo_sort_using_kahn(int v, vector<int> adj_list[])
{
    queue<int> q;
    vector<int> indegree(v, 0);
    vector<int> ans;

    for (int i = 0; i < v; i++)
        for (auto a : adj_list[i])
            indegree[a]++;

    for (int i = 0; i < v; i++)
        if (!indegree[i])
        {
            q.push(i);
            ans.push_back(i);
        }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto a : adj_list[node])
        {
            indegree[a]--;
            if (!indegree[a])
            {
                q.push(a);
                ans.push_back(a);
            }
        }
    }

    return ans;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> adj_list[numCourses];
    for (auto a : prerequisites)
        adj_list[a[1]].push_back(a[0]);

    vector<int> topo = topo_sort_using_kahn(numCourses, adj_list);

    return topo.size() == numCourses;
}

int main()
{
    int num_courses = 2;
    vector<vector<int>> prereq = {{1, 0}, {0, 1}};
    bool ans = canFinish(num_courses, prereq);
    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}