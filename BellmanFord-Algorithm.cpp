#include <climits>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

struct Edge
{
  int source, destination, weight;
};
/**
 * @brief Bellman-Ford algorithm to find the shortest path from the source vertex to all other vertices in the graph
 * @param edges is the vector of edges in the graph
 * @param numVertices is the number of vertices in the graph
 * @param source is the source vertex
 */
void bellmanFord(const vector<Edge> &edges, int numVertices, int source);

int main()
{
  vector<Edge> edges = {{0, 1, 4}, {0, 2, 5}, {1, 2, -2}, {1, 3, 6}, {2, 3, 1}};  // Example edges
  int numVertices = 4;                                                            // Number of vertices in the graph
  int source = 0;                                                                 // Source vertex

  bellmanFord(edges, numVertices, source);

  return 0;
}

void bellmanFord(const vector<Edge> &edges, int numVertices, int source)
{
  vector<int> distance(numVertices, INT_MAX);
  distance[source] = 0;

  // Relax all edges numVertices - 1 times
  for (int i = 1; i <= numVertices - 1; ++i)
  {
    for (const auto &edge : edges)
    {
      if (distance[edge.source] != INT_MAX && distance[edge.source] + edge.weight < distance[edge.destination])
      {
        distance[edge.destination] = distance[edge.source] + edge.weight;
      }
    }
  }

  // Check for negative weight cycles
  for (const auto &edge : edges)
  {
    if (distance[edge.source] != INT_MAX && distance[edge.source] + edge.weight < distance[edge.destination])
    {
      cout << "Graph contains negative weight cycle\n";
      return;
    }
  }

  // Print shortest distances
  cout << "Vertex   Distance from Source\n";
  for (int i = 0; i < numVertices; ++i)
  {
    cout << i << "\t\t" << distance[i] << "\n";
  }
}
