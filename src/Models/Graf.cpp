#include "Graf.hpp"
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <chrono>
#include <functional>

void Graf::validateNonEmpty(char node) const {
        if (node == '\0') {
            throw std::invalid_argument("Node tidak boleh kosong !!");
        } else if (!std::isupper(node)) {
            throw std::invalid_argument("Node harus menggunakan capital character !!");
        }
    }

void Graf::printConnections(const std::vector<Edge>& edges) const {
    for (const auto& edge : edges) {
        std::cout << edge.nextVertex << " (Total Rute: " << edge.totalRute << ") ";
    }
}

void Graf::setStartNode(char node) {
    validateNonEmpty(node);
    startNode = node;
}

void Graf::setEndNode(char node) {
    validateNonEmpty(node);
    endNode = node;
}

char Graf::getStartNode() const {
    return startNode;
}

char Graf::getEndNode() const {
    return endNode;
}

void  Graf::addEdge(char currVertex, char nextVertex, int totalRute) {
    Edge edge{currVertex, nextVertex, totalRute};
    adjList[currVertex].push_back(edge);
    adjList[nextVertex].push_back(edge); // Untuk graf tidak ter-arah
}

void Graf::printGraf() {
    for (const auto& vertex : adjList) {
        std::cout << "Vertex " << vertex.first << " is connected to: ";
        if (vertex.second.empty()) {
            std::cout << "No connections";
        } else {
            printConnections(vertex.second);
        }
        std::cout << std::endl;
    }
}

void Graf::algoDijkstra() {
    std::unordered_map<char, int> distance;
    std::unordered_map<char, char> predecessor;

    for (const auto& entry : adjList) {
        distance[entry.first] = std::numeric_limits<int>::max();
    }
    distance[startNode] = 0;

    using P = std::pair<int, char>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    pq.push({0, startNode});

    while (!pq.empty()) {
        char vertex = pq.top().second;
        pq.pop();

        std::cout << vertex << " ";

        for (const auto& edge : adjList[vertex]) {
            char nextVertex = edge.nextVertex;
            int weight = edge.totalRute;

            if (distance[vertex] + weight < distance[nextVertex]) {
                distance[nextVertex] = distance[vertex] + weight;
                predecessor[nextVertex] = vertex;
                pq.push({distance[nextVertex], nextVertex});
            }
        }

        if (vertex == endNode) {
            break;
        }
    }

    // Print the shortest path
    if (distance[endNode] == std::numeric_limits<int>::max()) {
        std::cout << "No path from " << startNode << " to " << endNode << std::endl;
        return;
    }

    std::stack<char> path;
    char currentNode = endNode;
    while (currentNode != startNode) {
        path.push(currentNode);
        currentNode = predecessor[currentNode];
    }
    path.push(startNode);

    std::cout << "\nShortest path from " << startNode << " to " << endNode << ": ";
    while (!path.empty()) {
        std::cout << path.top() << " ";
        path.pop();
    }

    std::cout << "\nTotal distance: " << distance[endNode] << std::endl;
}


void Graf::algoBFS() {
    std::queue<char> queue;
    std::set<char> visited;
    std::unordered_map<char, char> predecessor;
    std::unordered_map<char, int> totalRute; // Menyimpan totalRute untuk setiap node

    queue.push(this->startNode);
    visited.insert(this->startNode);
    totalRute[this->startNode] = 0;

    bool pathFound = false;

    while (!queue.empty()) {
        char vertex = queue.front();
        queue.pop();

        std::cout << vertex << " ";

        if (vertex == this->endNode) {
            pathFound = true;
            break; // Stop when we reach the endNode
        }

        for (const auto& edge : adjList[vertex]) {
            char nextVertex = edge.nextVertex;
            int weight = edge.totalRute;

            if (visited.find(nextVertex) == visited.end()) {
                visited.insert(nextVertex);
                queue.push(nextVertex);
                predecessor[nextVertex] = vertex;
                totalRute[nextVertex] = totalRute[vertex] + weight;
            }
        }
    }

    // Print the path and total distance
    if (!pathFound) {
        std::cout << "No path from " << this->startNode << " to " << this->endNode << std::endl;
        return;
    }

    std::stack<char> path;
    char currentNode = this->endNode;
    while (currentNode != this->startNode) {
        path.push(currentNode);
        currentNode = predecessor.at(currentNode);
    }
    path.push(this->startNode);

    std::cout << "\nPath from " << this->startNode << " to " << this->endNode << ": ";
    while (!path.empty()) {
        std::cout << path.top() << " ";
        path.pop();
    }

    std::cout << "\nTotal distance: " << totalRute[this->endNode] << std::endl;
}


void Graf::algoDFS() {
    std::stack<char> stack;
    std::set<char> visited;
    std::unordered_map<char, char> predecessor;
    std::unordered_map<char, int> totalRute;

    stack.push(this->startNode);
    visited.insert(this->startNode);
    totalRute[this->startNode] = 0;

    bool pathFound = false;

    while (!stack.empty()) {
        char vertex = stack.top();
        stack.pop();

        std::cout << vertex << " ";

        if (vertex == this->endNode) {
            pathFound = true;
            break; // Stop when we reach the endNode
        }

        for (const auto& edge : adjList[vertex]) {
            char nextVertex = edge.nextVertex;
            int weight = edge.totalRute;

            if (visited.find(nextVertex) == visited.end()) {
                visited.insert(nextVertex);
                stack.push(nextVertex);
                predecessor[nextVertex] = vertex;
                totalRute[nextVertex] = totalRute[vertex] + weight;
            }
        }
    }

    // Print the path and total distance
    if (!pathFound) {
        std::cout << "No path from " << this->startNode << " to " << this->endNode << std::endl;
        return;
    }

    std::stack<char> path;
    char currentNode = this->endNode;
    while (currentNode != this->startNode) {
        path.push(currentNode);
        currentNode = predecessor.at(currentNode);
    }
    path.push(this->startNode);

    std::cout << "\nPath from " << this->startNode << " to " << this->endNode << ": ";
    while (!path.empty()) {
        std::cout << path.top() << " ";
        path.pop();
    }

    std::cout << "\nTotal distance: " << totalRute[this->endNode] << std::endl;
}
