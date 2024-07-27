#include "./src/Models/Graf.cpp"
#include <iostream>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

int main() {
    Graf myGraf;
    
    myGraf.addEdge('Z', 'A', 6);
    myGraf.addEdge('Z', 'S', 11);
    myGraf.addEdge('Z', 'M', 7);
    myGraf.addEdge('Z', 'B', 8);
    myGraf.addEdge('M', 'D', 8);
    myGraf.addEdge('M', 'C', 5);
    myGraf.addEdge('M', 'B', 8);
    myGraf.addEdge('D', 'C', 8);
    myGraf.addEdge('C', 'B', 8);
    myGraf.addEdge('C', 'E', 8);
    myGraf.addEdge('A', 'B', 10);
    myGraf.addEdge('A', 'N', 7);
    myGraf.addEdge('S', 'A', 6);
    myGraf.addEdge('S', 'R', 12);
    myGraf.addEdge('F', 'N', 7);
    myGraf.addEdge('F', 'A', 8);
    myGraf.addEdge('R', 'H', 16);
    myGraf.addEdge('R', 'I', 12);
    myGraf.addEdge('I', 'H', 18);
    myGraf.addEdge('H', 'G', 11);
    myGraf.addEdge('H', 'S', 8);
    myGraf.addEdge('G', 'F', 5);
    myGraf.addEdge('G', 'S', 8);
    myGraf.addEdge('F', 'S', 8);
    myGraf.addEdge('N', 'B', 8);
    myGraf.addEdge('N', 'Q', 6);
    myGraf.addEdge('N', 'L', 5);
    myGraf.addEdge('F', 'L', 7);
    myGraf.addEdge('B', 'E', 10);
    myGraf.addEdge('B', 'O', 10);
    myGraf.addEdge('B', 'Q', 9);
    myGraf.addEdge('E', 'O', 8);
    myGraf.addEdge('Q', 'O', 5);
    myGraf.addEdge('Q', 'K', 8);
    myGraf.addEdge('O', 'K', 8);
    myGraf.addEdge('L', 'Q', 4);
    myGraf.addEdge('L', 'K', 11);
    myGraf.addEdge('L', 'P', 9);
    myGraf.addEdge('P', 'K', 7);
    myGraf.addEdge('P', 'J', 10);
    myGraf.addEdge('K', 'J', 9);

    std::cout << "Mencetak hasil input Edges: " << std::endl;
    myGraf.printGraf();
    std::cout << std::endl;
    
    try {
        myGraf.setStartNode('Z'); // Set startNode
        myGraf.setEndNode('J');   // Set endNode

        std::cout << "Mencetak start Node pencarian: " << myGraf.getStartNode() << std::endl;
        std::cout << "Mencetak end Node pencarian: " << myGraf.getEndNode() << std::endl;
        
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }


    auto t1 = high_resolution_clock::now(); //Awal perhitungan algortima pencarian rute

    std::cout << "DFS visited starting from vertex " << myGraf.getStartNode() << ": ";
    myGraf.algoDFS();
    std::cout << std::endl;

    auto t2 = high_resolution_clock::now(); //Awal perhitungan algortima pencarian rute

    // Menghitung durasi dalam milidetik
    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    std::cout << "Waktu eksekusi: " << ms_int.count() << " ms\n";

    return 0;
}