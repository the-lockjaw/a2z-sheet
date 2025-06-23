/*
210. Course Schedule II
Medium

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

Example 2:
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

Example 3:
Input: numCourses = 1, prerequisites = []
Output: [0]

Constraints:
    1 <= numCourses <= 2000
    0 <= prerequisites.length <= numCourses * (numCourses - 1)
    prerequisites[i].length == 2
    0 <= ai, bi < numCourses
    ai != bi
    All the pairs [ai, bi] are distinct.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct DetectCycleGraph
    {
        int V;
        vector<vector<int>> edges;
        vector<int> order;

        DetectCycleGraph(int n)
        {
            V = n;
            edges.resize(n);
        }

        void addEdge(int i, int j) { edges[i].push_back(j); }

        bool isCycleUtil(int node, vector<bool> &visited,
                         vector<bool> &curRec)
        {
            if (!visited[node])
            {
                visited[node] = true;
                curRec[node] = true;

                for (int neighbor : edges[node])
                {
                    if (!visited[neighbor] &&
                        isCycleUtil(neighbor, visited, curRec))
                        return true;
                    else if (curRec[neighbor])
                        return true;
                }

                order.push_back(node);
            }
            curRec[node] = false;
            return false;
        }

        vector<int> isCycle()
        {
            vector<bool> visited(V, false);
            vector<bool> curRec(V, false);

            for (int i = 0; i < V; ++i)
            {
                if (!visited[i] && isCycleUtil(i, visited, curRec))
                    return {}; // Return empty vector on cycle
            }

            return order;
        }
    };

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        DetectCycleGraph graph(numCourses);

        for (auto &pre : prerequisites)
            graph.addEdge(pre[0], pre[1]);

        vector<int> order = graph.isCycle();
        if (order.empty())
            return {}; 
        return order;
    }
};