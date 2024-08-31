#pragma once

#include <vector>
#include "graph_template.hpp"
#include "dijkstra.hpp"

/**
 * @brief Tree Diameter (木の直径)
 */
template<class T> int tree_diameter(Graph<Edge<T>> &graph) {
    Dijkstra<T> ds(graph);
    int idx = max_element(ds.dist.begin(), ds.dist.end()) - ds.dist.begin();
    ds.init(idx);
    return *max_element(ds.dist.begin(), ds.dist.end());
}