#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

void findAttackedComputers(int N, int M, vector<vector<int>>& connections, int attackedComputer)
{
    vector<vector<int>> graph(N + 1);
    vector<bool> attacked(N + 1, false);
    set<int> attackedSet;
    for (int i = 0; i < M; i++)
    {
        int u = connections[i][0];
        int v = connections[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    queue<int> q;
    q.push(attackedComputer);
    attacked[attackedComputer] = true;
    attackedSet.insert(attackedComputer);
    while (!q.empty()) 
    {
        int currentComputer = q.front();
        q.pop();
        for (int i = 0; i < graph[currentComputer].size(); i++)
        {
            int neighbor = graph[currentComputer][i];
            if (!attacked[neighbor]) 
            {
                q.push(neighbor);
                attacked[neighbor] = true;
                attackedSet.insert(neighbor);
            }
        }
    }
    cout << attackedSet.size() << endl;
    for (auto computer : attackedSet)
    {
        cout << computer << " ";
    }
}

int main()
{
    int N, M, s;
    cin >> N >> M;
    vector<vector<int>> connections(M, vector<int>(2));
    for (int i = 0; i < M; i++) 
    {
        cin >> connections[i][0] >> connections[i][1];
    }
    cin >> s;
    findAttackedComputers(N, M, connections, s);
    return 0;
}