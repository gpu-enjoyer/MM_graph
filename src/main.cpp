
#include <fstream>
#include <iostream>

#include "graph.hpp"

using namespace std;


int main(int argc, char* argv[]) {

    if (argc != 2) {
        cerr << "usage: " << argv[0] << " graph.txt\n";
        return 1;
    }

    ifstream in(argv[1]);

    if (!in) {
        cerr << "can\'t open file: " << argv[1] << '\n';
        return 1;
    }

    try {
        Graph g = read_graph(in);
    }
    catch (const exception& e) {
        cerr << "error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
