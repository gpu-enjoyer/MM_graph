
#include "graph.hpp"

#include <string>
#include <stdexcept>

Graph read_graph(istream& in) {

    int v_num, e_num;

    if (!(in >> v_num >> e_num))
        throw runtime_error("header format: V E");

    if (v_num < 0 || e_num < 0)
        throw runtime_error("header: negative size");

    vector<int> from(e_num, -1), to(e_num, -1);

    for (int v = 0; v < v_num; ++v) {
        for (int e = 0; e < e_num; ++e) {

            int x;

            if (!(in >> x))
                throw runtime_error("row " + to_string(v) + ": expected " + to_string(e_num) + " values");

            if (x < -1 || x > 1)
                throw runtime_error("row " + to_string(v) + ", col " + to_string(e) + ": bad value");

            if (x == -1) {
                if (from[e] != -1) // initial value
                    throw runtime_error("col " + to_string(e) + ": more than one -1");
                from[e] = v;
            }
            else if (x == 1) {
                if (to[e] != -1) // initial value
                    throw runtime_error("col " + to_string(e) + ": more than one +1");
                to[e] = v;
            }
        }
    }

    Graph g(v_num);

    for (int e = 0; e < e_num; ++e) {
        if (from[e] == -1 || to[e] == -1)
            throw runtime_error("col " + to_string(e) + ": edge must contain -1 and +1");
        g.adj[from[e]].push_back(to[e]);
    }

    return g;
}
