#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
using namespace std;

vector<string> bfs(unordered_map<string, vector<string>>& graph, const string& start, const string& end) 
{
    vector<string> path;
    queue<vector<string>> q;
    q.push({ start });
    if (start == end)
    {
        return { start };
    }    
    while (!q.empty())
    {
        path = q.front();
        q.pop();
        string node = path.back();
        if (node == end)
        {
            return path;
        }
        if (graph.find(node) != graph.end())
        {
            vector<string> neighbors = graph[node];
            for (const string& neighbor : neighbors) 
            {
                if (find(path.begin(), path.end(), neighbor) == path.end()) 
                {
                    vector<string> new_path = path;
                    new_path.push_back(neighbor);
                    q.push(new_path);
                }
            }
        }
    }
    return {};
}

vector<string> find_paths(unordered_map<string, vector<string>>& graph, vector<pair<string, string>>& pairs)
{
    vector<string> paths;
    for (const auto& pair : pairs)
    {
        const string& start = pair.first;
        const string& end = pair.second;
        vector<string> path = bfs(graph, start, end);
        if (!path.empty())
        {
            paths.push_back(accumulate(path.begin(), path.end(), string(),
                [](const string& acc, const string& node) {
                    return acc.empty() ? node : acc + " " + node;
                }));
        }
        else 
        {
            paths.push_back("no_path");
        }
    }
    return paths;
}

int main()
{
    int n, m;
    cin >> n >> m;
    unordered_map<string, vector<string>> graph;
    for (int i = 0; i < n; ++i)
    {
        string vertex;
        cin >> vertex;
        graph[vertex] = vector<string>();
    }
    for (int i = 0; i < m; ++i)
    {
        string u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    int k;
    cin >> k;
    vector<pair<string, string>> pairs;
    for (int i = 0; i < k; ++i) 
    {
        string start, end;
        cin >> start >> end;
        pairs.push_back(make_pair(start, end));
    }
    vector<string> paths = find_paths(graph, pairs);
    for (const string& path : paths)
    {
        cout << path << endl;
    }
    return 0;
}