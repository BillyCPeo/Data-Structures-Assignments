/*Billy Peo
Assignment 10
Professor Wu*/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjacencyList;
    int numVertices;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjacencyList.resize(vertices);
    }

    void addEdge(int from, int to) {
        adjacencyList[from].push_back(to);
    }

    void breadthFirstTraversal(int startVertex) {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        cout << "Breadth First Traversal: ";

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int neighbor : adjacencyList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        cout << endl;
    }

    void depthFirstTraversal(int startVertex) {
        vector<bool> visited(numVertices, false);
        stack<int> s;

        visited[startVertex] = true;
        s.push(startVertex);

        cout << "Depth First Traversal: ";

        while (!s.empty()) {
            int current = s.top();
            bool foundUnvisited = false;

            for (int neighbor : adjacencyList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    s.push(neighbor);
                    foundUnvisited = true;
                    break;
                }
            }

            if (!foundUnvisited) {
                cout << current << " ";
                s.pop();
            }
        }

        cout << endl;
    }
};

int main() {
    Graph g(6); // Create a graph with 6 vertices (0 to 5)

    // Add edges (directed graph)
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(4, 5);

    // Perform traversals from vertex 0
    g.breadthFirstTraversal(0);
    g.depthFirstTraversal(0);

    return 0;
}

