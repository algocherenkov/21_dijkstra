#include "dijkstra.h"
#include <algorithm>
#include <climits>
#include <cassert>
#include <map>

namespace {
int getMinMark(std::map<int, int>& mark) {
    int minMark = (*mark.begin()).second;
    int minVertex = (*mark.begin()).first;
    for(const auto& v: mark)
    {
        if(v.second < minMark)
        {
            minMark = v.second;
            minVertex = v.first;
        }
    }
    return minVertex;
}
}

namespace graphs {


std::vector<int> dijkstra(std::vector<std::vector<std::pair<int, int> > > &graph, int initVertex)
{
    assert(static_cast<size_t>(initVertex) < graph.size());
    std::map<int, int> mark;
    std::vector<int> distance;
    distance.resize(graph.size(), 0);
    for(size_t i = 0; i < graph.size(); i++)
        mark[i] = INT_MAX;

    mark[initVertex] = 0;

    while(!mark.empty())
    {
        int v = getMinMark(mark);
        for(auto& vertex: graph[v])
            if(mark.count(vertex.first) && ((mark[v] + vertex.second) < mark[vertex.first]))            
                mark[vertex.first] = mark[v] + vertex.second;

        distance[v] = mark[v];
        mark.erase(v);
    }

    return distance;
}

}

