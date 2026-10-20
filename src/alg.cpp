
#include "alg.hpp"

using namespace std;

namespace {

    // Kosaraju 1: DFS по исходному графу
    //  Вершины складываются в order по времени выхода
    void dfs_order(const Graph& g, int v, vector<char>& used, vector<int>& order) {
        used[v] = 1;
        for (int to : g.adj()[v])
            if (!used[to])
                dfs_order(g, to, used, order);
        order.push_back(v);
    }

    // Kosaraju 2: DFS по транспонированному графу
    //  Помечает номером 'c' одну компоненту сильной связности
    void dfs_comp(const vector<vector<int>>& radj, int v, int c, vector<int>& comp) {
        comp[v] = c;
        for (int to : radj[v])
            if (comp[to] == -1)
                dfs_comp(radj, to, c, comp);
    }

}

vector<int> reachable_from_all(const Graph& g) {

    const int n = g.v_num();
    if (n == 0)
        return {};

    // Порядок выхода DFS на исходном графе
    vector<int> order;
    order.reserve(n);
    vector<char> used(n, 0);
    for (int v = 0; v < n; ++v)
        if (!used[v])
            dfs_order(g, v, used, order);

    // Транспонированный граф (все ребра развернуты)
    vector<vector<int>> radj(n);
    for (int v = 0; v < n; ++v)
        for (int to : g.adj()[v])
            radj[to].push_back(v);

    // Разметка компонент сильной связности
    vector<int> comp(n, -1);
    int c_num = 0;
    for (int i = n - 1; i >= 0; --i) {
        const int v = order[i];
        if (comp[v] == -1) {
            dfs_comp(radj, v, c_num, comp);
            ++c_num;
        }
    }

    // Полустепень исхода каждой компоненты в конденсации
    vector<char> has_out(c_num, 0);
    for (int v = 0; v < n; ++v)
        for (int to : g.adj()[v])
            if (comp[v] != comp[to])
                has_out[comp[v]] = 1;

    // Сток (компонента без исходящих ребер) должен быть ровно один
    int sink = -1;
    for (int c = 0; c < c_num; ++c) {
        if (!has_out[c]) {
            if (sink != -1)
                return {}; // Второй сток: ответа нет
            sink = c;
        }
    }

    // Ответ
    vector<int> ans;
    for (int v = 0; v < n; ++v)
        if (comp[v] == sink)
            ans.push_back(v);
    return ans;
}