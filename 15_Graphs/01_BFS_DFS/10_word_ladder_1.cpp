/*
127. Word Ladder
Hard

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

    Every adjacent pair of words differs by a single letter.
    Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
    sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

Constraints:
    1 <= beginWord.length <= 10
    endWord.length == beginWord.length
    1 <= wordList.length <= 5000
    wordList[i].length == beginWord.length
    beginWord, endWord, and wordList[i] consist of lowercase English letters.
    beginWord != endWord
    All the words in wordList are unique.
*/

#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    queue<pair<string, int>> q;
    q.push({beginWord, 1});

    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(beginWord);

    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (word == endWord)
            return steps;

        for (int i = 0; i < word.length(); i++)
        {
            char original = word[i];
            for (char j = 'a'; j <= 'z'; j++)
            {
                word[i] = j;
                if (st.find(word) != st.end())
                {
                    q.push({word, steps + 1});
                    st.erase(word);
                }
            }
            word[i] = original;
        }
    }
    return 0;
}

int main()
{
    string begin_word = "hit";
    string end_word = "fog";
    vector<string> word_list = {"hot", "dot", "dog", "lot", "log", "cog", "fog"};
    int ans = ladderLength(begin_word, end_word, word_list);
    cout << "Answer = " << ans << endl;
}