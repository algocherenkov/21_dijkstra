#include "dijkstra.h"
#include <string>
#include <ctime>
#include <chrono>
#include <random>
#include <iterator>
#include <map>

#define BOOST_TEST_MODULE test_main

#include <boost/test/included/unit_test.hpp>

using namespace boost::unit_test;
BOOST_AUTO_TEST_SUITE(test_suite_main)

/*graph for test purposes was taken from lecture*/

BOOST_AUTO_TEST_CASE(Demukron_sort_and_Tarian_sort_test)
{
    std::vector<std::vector<std::pair<int, int>>> testGraph;
    std::vector<std::pair<int, int>> temp;
    temp.emplace_back(1, 7);
    temp.emplace_back(2, 9);
    temp.emplace_back(5, 14);
    testGraph.push_back(temp);
    temp.clear();

    temp.emplace_back(0, 7);
    temp.emplace_back(2, 10);
    temp.emplace_back(3, 15);
    testGraph.push_back(temp);
    temp.clear();

    temp.emplace_back(0, 9);
    temp.emplace_back(1, 10);
    temp.emplace_back(3, 11);
    temp.emplace_back(5, 2);
    testGraph.push_back(temp);
    temp.clear();

    temp.emplace_back(1, 15);
    temp.emplace_back(2, 11);
    temp.emplace_back(4, 6);
    testGraph.push_back(temp);
    temp.clear();

    temp.emplace_back(3, 6);
    temp.emplace_back(5, 9);
    testGraph.push_back(temp);
    temp.clear();

    temp.emplace_back(0, 14);
    temp.emplace_back(2, 2);
    temp.emplace_back(4, 9);
    testGraph.push_back(temp);
    temp.clear();

    auto result = graphs::dijkstra(testGraph, 0);

    BOOST_CHECK_MESSAGE(result.size() == 6, "wrong result size");
    BOOST_CHECK_MESSAGE(result[0] == 0, "wrong shortest distance");
    BOOST_CHECK_MESSAGE(result[1] == 7, "wrong shortest distance");
    BOOST_CHECK_MESSAGE(result[2] == 9, "wrong shortest distance");
    BOOST_CHECK_MESSAGE(result[3] == 20, "wrong shortest distance");
    BOOST_CHECK_MESSAGE(result[4] == 20, "wrong shortest distance");
    BOOST_CHECK_MESSAGE(result[5] == 11, "wrong shortest distance");
}
BOOST_AUTO_TEST_SUITE_END()
