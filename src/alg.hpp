
#pragma once

#include <vector>

#include "graph.hpp"

// Возвращает отсортированный по возрастанию список вершин,
//  достижимых из всех остальных вершин графа.
// Пустой вектор - таких вершин нет.
// Сложность по времени и памяти O(V + E)
std::vector<int> reachable_from_all(const Graph& g);
