
#pragma once

#include <vector>
#include <iostream>


class Graph {

    int v_num = 0;
    std::vector<std::vector<int>> adj;

public:

    Graph(int v_num): v_num(v_num), adj(v_num) {};
    friend Graph read_graph(std::istream&);
};

Graph read_graph(std::istream& in);
