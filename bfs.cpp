#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;

// Function to perform BFS and find the shortest path
vector<string> findShortestPath(const vector<vector<int>>& graph, int start, int destination) {
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);
    vector<int> parent(numNodes, -1);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        if (current == destination) {
            break;  // We've reached the destination, no need to continue BFS
        }

        for (int neighbor = 0; neighbor < numNodes; neighbor++) {
            if (graph[current][neighbor] == 1 && !visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = current;
            }
        }
    }

    // Reconstruct the path from destination to start
    vector<string> shortestPath;
    int current = destination;
    while (current != -1) {
        shortestPath.insert(shortestPath.begin(), to_string(current));
        current = parent[current];
    }

    return shortestPath;
}

int main() {
    ifstream inputFile("network.txt"); // Read the network from a text file
    int numNodes, numEdges;
    inputFile >> numNodes >> numEdges;

    vector<vector<int>> graph(numNodes, vector<int>(numNodes, 0));

    for (int i = 0; i < numEdges; i++) {
        int node1, node2;
        inputFile >> node1 >> node2;
        graph[node1][node2] = 1;
        graph[node2][node1] = 1;  // Assuming bidirectional connections
    }

    string startLocation = "A";
    string destinationLocation = "G";

    // Find the indices of the start and destination nodes
    int startIndex, destinationIndex;
    map<string, int> nodeIndex;
    for (int i = 0; i < numNodes; i++) {
        string nodeName;
        inputFile >> nodeName;
        nodeIndex[nodeName] = i;
        if (nodeName == startLocation) {
            startIndex = i;
        }
        if (nodeName == destinationLocation) {
            destinationIndex = i;
        }
    }

    inputFile.close();

    vector<string> shortestPath = findShortestPath(graph, startIndex, destinationIndex);

    cout << "The shortest path from " << startLocation << " to " << destinationLocation << " is: ";
    for (const string& node : shortestPath) {
        cout << node;
        if (node != destinationLocation) {
            cout << " -> ";
        }
    }
    cout << endl;

    return 0;
}

