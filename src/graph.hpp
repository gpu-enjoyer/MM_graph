
#pragma once

#include <vector>
#include <iostream>

using namespace std;


class Graph {

    int v_num = 0;
    vector<vector<int>> adj;

public:

    Graph(int v_num): v_num(v_num), adj(v_num) {};
    friend Graph read_graph(istream&);
};

Graph read_graph(istream& in);
