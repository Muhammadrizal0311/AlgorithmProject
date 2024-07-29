#ifndef GRAF_H
#define GRAF_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <set>
#include <functional>

/**
 * @struct Edge
 * @brief Mewakili sebuah sisi dalam graf dengan simpul awal, simpul akhir, dan total jarak rute.
 */
struct Edge {
    char currentVertex;  ///< Simpul awal dari sisi
    char nextVertex;     ///< Simpul akhir dari sisi
    int totalRute;       ///< Jarak rute dalam kilometer
};

/**
 * @class Graf
 * @brief Mewakili sebuah graf dengan metode untuk menambahkan sisi, mencetak graf, dan mencari rute menggunakan berbagai algoritma.
 */
class Graf {
private:
    char startNode;  ///< Simpul awal dari graf
    char endNode;    ///< Simpul akhir dari graf
    std::unordered_map<char, std::vector<Edge>> adjList;  ///< Daftar ketetanggaan yang mewakili graf

public:
    /**
     * @brief Menambahkan sebuah sisi ke dalam graf.
     * @param currVertex Simpul awal dari sisi
     * @param nextVertex Simpul akhir dari sisi
     * @param totalRute Jarak rute dalam kilometer
     */
    void addEdge(char currVertex, char nextVertex, int totalRute);

    /**
     * @brief Mencetak semua sisi dalam graf.
     */
    void printGraf();

    /**
     * @brief Mencari rute menggunakan algoritma Breadth-First Search (BFS).
     * @author
     *  Nama    : Muhammad Rizal
     *  NIM     : 411231097
     */
    void algoBFS();

    /**
     * @brief Mencari rute menggunakan algoritma Dijkstra untuk jalur terpendek.
     * @author
     *  Nama    : Aditya Saputra
     *  NIM     : 411231139
     */
    void algoDijkstra();

    /**
     * @brief Mencari rute menggunakan algoritma Depth-First Search (DFS).
     * @author
     *  Nama    : Neny Rahmawati
     *  NIM     : 411231098
     */
    void algoDFS();

    /**
     * @brief Memvalidasi bahwa simpul yang ditentukan tidak kosong.
     * @param node Simpul yang akan divalidasi
     * @throw std::invalid_argument jika simpul kosong
     */
    void validateNonEmpty(char node) const;

    /**
     * @brief Mencetak koneksi (sisi) dari daftar sisi yang diberikan.
     * @param edges Daftar sisi yang akan dicetak
     */
    void printConnections(const std::vector<Edge>& edges) const;

    /**
     * @brief Mengatur simpul awal untuk perjalanan.
     * @param node Simpul awal
     */
    void setStartNode(char node);
    
    /**
     * @brief Mengatur simpul akhir untuk perjalanan.
     * @param node Simpul akhir
     */
    void setEndNode(char node);
    
    /**
     * @brief Mendapatkan simpul awal dari graf.
     * @return Simpul awal
     */
    char getStartNode() const;
    
    /**
     * @brief Mendapatkan simpul akhir dari graf.
     * @return Simpul akhir
     */
    char getEndNode() const;
};

#endif
