/*
    Time Complexity: O(V + E)
    Space Complexity: O(V)
    
    where V is the number of nodes and E is the number of edges in the given Graph.  
*/

#include <iostream>
using namespace std;

#define MOD 1000000007

#include <vector>

int dfs(int src, vector<int> &dp, vector<vector<int>> &graph)
{
    if (dp[src] != -1)
    {
        return dp[src];
    }

    int count = 1;
    for (int i = 0; i < graph[src].size(); i++)
    {
        count = (count + dfs(graph[src][i], dp, graph)) % MOD;
    }

    return dp[src] = count;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int V, E, S;
    cin >> V >> E >> S;

    vector<vector<int>> graph(V + 1);
    vector<int> dp(V + 1, -1);
    for (int i = 0; i < E; i++)
    {
        int src, des;
        cin >> src >> des;

        graph[src].push_back(des);
    }

    int totalWays = dfs(S, dp, graph);
    cout << totalWays;

    return 0;
}
