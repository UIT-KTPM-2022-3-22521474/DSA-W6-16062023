#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> convertToAdjacencyList(vector<vector<int>>& adjacencyMatrix) 
{
    int n = adjacencyMatrix.size();
    vector<vector<int>> adjacencyList(n);
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (adjacencyMatrix[i][j] == 1) 
            {
                adjacencyList[i].push_back(j + 1);
            }
        }
    }
    return adjacencyList;
}

int main() 
{
    int n;
    cin >> n;
    vector<vector<int>> adjacencyMatrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> adjacencyMatrix[i][j];
        }
    }
    vector<vector<int>> adjacencyList = convertToAdjacencyList(adjacencyMatrix);
    for (int i = 0; i < n; i++) 
    {
        if (adjacencyList[i].size() > 0) 
        {
            cout << i + 1 << "->";
            for (int j = 0; j < adjacencyList[i].size(); j++) 
            {
                cout << adjacencyList[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
