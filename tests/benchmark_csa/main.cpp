#include "server_http.hpp"
#include "client_http.hpp"

//Added for the json-example
#define BOOST_SPIRIT_THREADSAFE

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <iterator>
#include <curses.h>

#include <boost/optional.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/program_options.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/filesystem.hpp>

#include "toolbox.hpp"
#include "gtfs_fetcher.hpp"
#include "csv_fetcher.hpp"
#include "cache_fetcher.hpp"
#include "calculation_time.hpp"
#include "parameters.hpp"
#include "scenario.hpp"
#include "calculator.hpp"
#include "program_options.hpp"
#include "bench.hpp"

int assertCacheOk(TrRouting::Calculator *calculator) {
    if (calculator->countAgencies() == 0)
    {
        std::cout << "no agencies";
        return -1;
    }
    else if (calculator->countServices() == 0)
    {
        std::cout << "no services";
      return -1;
    }
    else if (calculator->countNodes() == 0)
    {
        std::cout << "no nodes";
      return -1;
    }
    else if (calculator->countLines() == 0)
    {
      return -1;
    }
    else if (calculator->countPaths() == 0)
    {
      return -1;
    }
    else if (calculator->countScenarios() == 0)
    {
      return -1;
    }
    else if (calculator->countConnections() == 0  || calculator->countTrips() == 0)
    {
      return -1;
    }
    return 0;
}

int benchmarkCurrentParams(TrRouting::Calculator *calculator) {
    int nbIter = 10;
    double results[nbIter];
    for (int i = 0; i < nbIter; i++) {
        double start = get_time();
        calculator->alternativesRouting();
        double end = get_time();
        results[i] = end - start;
    }
    std::cout << "results: ";
    double resultSum = 0;
    for (int i = 0; i < nbIter; i++) {
        std::cout << results[i];
        resultSum += results[i];
    }
    std::cout << std::endl;
    return resultSum / nbIter;
}

int main(int argc, char** argv) {

    TrRouting::Parameters algorithmParams;

    algorithmParams.projectShortname       = "mon_test";
    algorithmParams.cacheDirectoryPath     = "./";
    algorithmParams.osrmWalkingPort        = "5000";
    algorithmParams.osrmWalkingHost        = "http://localhost";
    algorithmParams.serverDebugDisplay     = false;

    TrRouting::CacheFetcher cacheFetcher    = TrRouting::CacheFetcher();
    algorithmParams.cacheFetcher = &cacheFetcher;
    
    TrRouting::Calculator calculator(algorithmParams);
    std::cout << "preparing calculator..." << std::endl;
    int dataStatus = calculator.prepare();

    if (assertCacheOk(&calculator) != 0) {
        std::cout << "Invalid cache" << std::endl;
        return 1;
    }

    calculator.params.setDefaultValues();
    double result = benchmarkCurrentParams(&calculator);
    std::cout << "Average timing: " << result << std::endl;

    return 0;
}