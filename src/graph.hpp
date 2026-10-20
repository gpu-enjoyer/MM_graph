
#pragma once

#include <vector>
#include <iostream>

class Graph {

    int v_num_ = 0;
    std::vector<std::vector<int>> adj_;

public:

    Graph(int v_num): v_num_(v_num), adj_(v_num) {};

    int v_num() const { return v_num_; }
    const std::vector<std::vector<int>>& adj() const { return adj_; }

    friend Graph read_graph(std::istream&);
};

Graph read_graph(std::istream& in);
