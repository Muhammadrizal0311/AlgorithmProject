#ifndef GRAF_H
#define GRAF_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <set>
#include <functional>


/**
 * @struct Deklarasi tipedata dan bentuk object Edges
 */
struct Edge {
    char currentVertex;
    char nextVertex;
    int totalRute;
};

/**
 * @class Melakukan deklarasi sebuah object atau blue print, dan kita juga bisa melaukan deklarasi variable lainnya
 */
class Graf {
private:
    char startNode, endNode;
    std::unordered_map<char, std::vector<Edge>> adjList;


public:
    /**
     * Menambahkan Edges atau Simpul pada sebuah Graf yang ada
     * @param currVertex    : Berfungsi untuk menyimpan titik Vertex awal
     * @param nextVertex    : Berfungsi untuk menyimpan titik Vertex selanjut nya
     * @param totalRute     : Berfungsi untuk menyimpan total Rute dalam satuan Km dengan Google Maps
     * @return void
     */
    void addEdge(char currVertex, char nextVertex, int totalRute);

    /**
     * Melakukan pencetakan semua simpul / Edges yang telah di tambahkan 
     */
    void printGraf();

    /**
     * Dibawah ini adalah sebuah fungsi untuk pencarian rute dengan Algoritma BFS
     * @author      Nama    : Muhammad Rizal
     * @details     NIM     : 411231097
     */
    void algoBFS();

    // Implementasi algoritma Dijkstra
    void algoDijkstra();

    // Implementasi algoritma DFS
    void algoDFS();


    void printVisited(const std::set<char>& visited);


    void validateNonEmpty(char node) const;


    void printConnections(const std::vector<Edge>& edges) const;

    /**
     * Setter untuk startNode sebagai titik awal dari perjalanan
     * @param node      : Node dengan tipe Character
     */
    void setStartNode(char node);
    
    /**
     * Setter untuk endENode sebagai titik akhir dari perjalanan
     * @param node      : Node dengan tipe Character
     */
    void setEndNode(char node);
    
    // Getter untuk startNode
    char getStartNode() const;
    
    // Getter untuk endNode
    char getEndNode() const;
};
#endif