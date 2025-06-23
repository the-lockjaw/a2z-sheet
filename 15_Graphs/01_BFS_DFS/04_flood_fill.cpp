/*
733. Flood Fill
Easy

You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:
    Begin with the starting pixel and change its color to color.
    Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
    Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
    The process stops when there are no more adjacent pixels of the original color to update.

Return the modified image after performing the flood fill.

Example 1:
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]

Explanation:
From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not horizontally or vertically connected to the starting pixel.

Example 2:
Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]

Explanation:
The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.

Constraints:
    m == image.length
    n == image[i].length
    1 <= m, n <= 50
    0 <= image[i][j], color < 216
    0 <= sr < m
    0 <= sc < n
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void print_matrix(vector<vector<int>> v)
{
    for (auto a : v)
    {
        for (auto b : a)
            cout << b << " ";
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                              int color)
{
    int m = image.size();
    int n = image[0].size();
    queue<pair<int, int>> q;

    int init_color = image[sr][sc];
    image[sr][sc] = color;
    q.push({sr, sc});

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = dy[i] + y;
            if (nx < 0 || nx >= m || ny < 0 || ny >= n ||
                image[nx][ny] == color)
                continue;
            if (image[nx][ny] == init_color)
            {
                image[nx][ny] = color;
                q.push({nx, ny});
            }
        }
    }
    return image;
}

int main()
{
    vector<vector<int>> q = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1;
    int sc = 1;
    int color = 2;
    vector<vector<int>> ans = floodFill(q, sr, sc, color);
    print_matrix(ans);

    vector<vector<int>> r = {{0, 0, 0}, {0, 0, 0}};
    int sr1 = 1;
    int sc1 = 0;
    int color1 = 2;
    vector<vector<int>> ans1 = floodFill(r, sr1, sc1, color1);
    print_matrix(ans1);
}