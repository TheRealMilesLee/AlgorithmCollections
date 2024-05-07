#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief This function performs a deep first search on a graph
 * @param graph is the adjacency matrix of the graph
 * @param visited is the vector that keeps track of the visited nodes
 * @param v is the current node
 */
void DeepFirstSearch(vector<vector<int>> &graph, vector<int> &visited, int v);

int main()
{
  int n = 5;
  vector<vector<int>> graph(n, vector<int>(n, 0));
  vector<int> visited(n, 0);

  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 0}, {1, 3},
                               {2, 0}, {2, 3}, {2, 4}, {3, 1},
                               {3, 2}, {3, 4}, {4, 2}, {4, 3}};
  int numEdges = edges.size();
  for (int i = 0; i < numEdges; i++)
  {
    int src = edges[i][0];
    int dest = edges[i][1];
    graph[src][dest] = 1;
  }

  DeepFirstSearch(graph, visited, 0);

  return 0;
}

void DeepFirstSearch(vector<vector<int>> &graph, vector<int> &visited, int v)
{
  visited[v] = 1;
  cout << v << " ";
  for (int i = 0; i < graph.size(); i++)
  {
    if (graph[v][i] == 1 && visited[i] == 0)
    {
      DeepFirstSearch(graph, visited, i);
    }
  }
}
