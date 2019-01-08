#include "calculator.hpp"

namespace TrRouting
{
  
  void Calculator::reset(bool resetAccessPaths)
  {
    
    calculationTime = algorithmCalculationTime.getDurationMicrosecondsNoStop();
    
    std::fill(nodesTentativeTime.begin(),        nodesTentativeTime.end(),   MAX_INT);
    std::fill(nodesReverseTentativeTime.begin(), nodesReverseTentativeTime.end(), -1);
    //std::fill(nodesD.begin(), nodesD.end(), MAX_INT);
    //std::fill(nodesReverseTentativeTime.begin(), nodesReverseTentativeTime.end(), std::deque<std::pair<int,int>>(1, std::make_pair(MAX_INT, MAX_INT));
    std::fill(nodesAccessTravelTime.begin(),     nodesAccessTravelTime.end(),     -1);
    std::fill(nodesEgressTravelTime.begin(),     nodesEgressTravelTime.end(),     -1);
    if (resetAccessPaths)
    {
      accessFootpaths.clear();
      egressFootpaths.clear();
    }
    std::fill(tripsEnterConnection.begin(),      tripsEnterConnection.end(),      -1);
    std::fill(tripsExitConnection.begin(),       tripsExitConnection.end(),       -1);
    std::fill(tripsEnterConnectionTransferTravelTime.begin(), tripsEnterConnectionTransferTravelTime.end(), MAX_INT);
    std::fill(tripsExitConnectionTransferTravelTime.begin(),  tripsExitConnectionTransferTravelTime.end(),  MAX_INT);
    //std::fill(tripsReverseTime.begin(), tripsReverseTime.end(), MAX_INT);
    std::fill(tripsEnabled.begin(),          tripsEnabled.end(), 1);
    std::fill(tripsUsable.begin(),           tripsUsable.end(),  -1);
    std::fill(forwardJourneys.begin(),       forwardJourneys.end(),       std::make_tuple(-1,-1,-1,-1,-1,-1));
    std::fill(forwardEgressJourneys.begin(), forwardEgressJourneys.end(), std::make_tuple(-1,-1,-1,-1,-1,-1));
    std::fill(reverseJourneys.begin(),       reverseJourneys.end(),       std::make_tuple(-1,-1,-1,-1,-1,-1));
    std::fill(reverseAccessJourneys.begin(), reverseAccessJourneys.end(), std::make_tuple(-1,-1,-1,-1,-1,-1));
    
    departureTimeSeconds = -1;
    arrivalTimeSeconds   = -1;
    
    if(params.odTrip != NULL && params.forwardCalculation == true)
    {
      departureTimeSeconds = params.odTrip->departureTimeSeconds;
    }
    else if (params.departureTimeSeconds != -1)
    {
      departureTimeSeconds = params.departureTimeSeconds;
    }
    else if (params.departureTimeHour != -1 && params.departureTimeMinutes != -1)
    {
      departureTimeSeconds = params.departureTimeHour * 3600 + params.departureTimeMinutes * 60;
    }
    if (params.arrivalTimeSeconds != -1)
    {
      arrivalTimeSeconds = params.arrivalTimeSeconds;
    }
    else if(params.arrivalTimeHour != -1 && params.arrivalTimeMinutes != -1)
    {
      arrivalTimeSeconds = params.arrivalTimeHour * 3600 + params.arrivalTimeMinutes * 60;
    }





    if (params.debugDisplay)
      std::cerr << "-- reset and preparations -- " << algorithmCalculationTime.getDurationMicrosecondsNoStop() - calculationTime << " microseconds\n";
    calculationTime = algorithmCalculationTime.getDurationMicrosecondsNoStop();


    int i {0};


    // fetch nodes footpaths accessible from origin using params or osrm fetcher if not provided:
    minAccessTravelTime = MAX_INT;
    maxEgressTravelTime = -1;
    minEgressTravelTime = MAX_INT;
    maxAccessTravelTime = -1;
    
    if (!params.returnAllNodesResult || departureTimeSeconds >= -1)
    {
      if (resetAccessPaths)
      {
        if(params.odTrip != NULL && params.odTrip->accessFootpathsStartIndex >= 0 && params.odTrip->accessFootpathsEndIndex >= 0 && params.odTrip->accessFootpathsEndIndex >= params.odTrip->accessFootpathsStartIndex)
        {
          accessFootpaths.assign(odTripFootpaths.begin() + params.odTrip->accessFootpathsStartIndex, odTripFootpaths.begin() + params.odTrip->accessFootpathsEndIndex);
        }
        else if (params.accessNodesIdx.size() > 0 && params.accessNodeTravelTimesSeconds.size() == params.accessNodesIdx.size())
        {
          i = 0;
          for (auto & accessNodeIdx : params.accessNodesIdx)
          {
            accessFootpaths.push_back(std::make_pair(accessNodeIdx, params.accessNodeTravelTimesSeconds[i]));
            i++;
          }
        }
        else
        {
          accessFootpaths = OsrmFetcher::getAccessibleNodesFootpathsFromPoint(params.origin, nodes, params.accessMode, params);
        }
      }
    
      for (auto & accessFootpath : accessFootpaths)
      {
        nodesAccessTravelTime[accessFootpath.first] = accessFootpath.second;
        forwardJourneys[accessFootpath.first]       = std::make_tuple(-1, -1, -1, -1, accessFootpath.second, -1);
        nodesTentativeTime[accessFootpath.first]    = departureTimeSeconds + accessFootpath.second + params.minWaitingTimeSeconds;
        if (accessFootpath.second < minAccessTravelTime)
        {
          minAccessTravelTime = accessFootpath.second;
        }
        if (accessFootpath.second > maxAccessTravelTime)
        {
          maxAccessTravelTime = accessFootpath.second;
        }
        //std::cerr << "origin_node: " << nodes[accessFootpath.first].name << " - " << Toolbox::convertSecondsToFormattedTime(nodesTentativeTime[accessFootpath.first]) << std::endl;
        //std::cerr << std::to_string(nodes[accessFootpath.first].id) + ",";
      }
    }
  
  
  
  
    if (!params.returnAllNodesResult || arrivalTimeSeconds >= -1)
    {
      if (resetAccessPaths)
      {
        // fetch nodes footpaths accessible to destination using params or osrm fetcher if not provided:
        if(params.odTrip != NULL && params.odTrip->egressFootpathsStartIndex >= 0 && params.odTrip->egressFootpathsEndIndex >= 0 && params.odTrip->egressFootpathsEndIndex >= params.odTrip->egressFootpathsStartIndex)
        {
          egressFootpaths.assign(odTripFootpaths.begin() + params.odTrip->egressFootpathsStartIndex, odTripFootpaths.begin() + params.odTrip->egressFootpathsEndIndex);
        }
        else if (params.egressNodesIdx.size() > 0 && params.egressNodeTravelTimesSeconds.size() == params.egressNodesIdx.size())
        {
          egressFootpaths.reserve(params.egressNodesIdx.size());
          i = 0;
          for (auto & egressNodeIdx : params.egressNodesIdx)
          {
            egressFootpaths.push_back(std::make_pair(egressNodeIdx, params.egressNodeTravelTimesSeconds[i]));
            i++;
          }
        }
        else
        {
          egressFootpaths = OsrmFetcher::getAccessibleNodesFootpathsFromPoint(params.destination, nodes, params.accessMode, params);
        }
      }
      
      for (auto & egressFootpath : egressFootpaths)
      {
        nodesEgressTravelTime[egressFootpath.first]     = egressFootpath.second;
        reverseJourneys[egressFootpath.first]           = std::make_tuple(-1, -1, -1, -1, egressFootpath.second, -1);
        nodesReverseTentativeTime[egressFootpath.first] = arrivalTimeSeconds - egressFootpath.second;
        if (egressFootpath.second > maxEgressTravelTime)
        {
          maxEgressTravelTime = egressFootpath.second;
        }
        if (egressFootpath.second < minEgressTravelTime)
        {
          minEgressTravelTime = egressFootpath.second;
        }
        //nodesD[egressFootpath.first]                = egressFootpath.second;
        //result.json += "origin_node: " + nodes[accessFootpath.first].name + " - " + Toolbox::convertSecondsToFormattedTime(nodesTentativeTime[accessFootpath.first]) + "\n";
        //result.json += std::to_string((int)(ceil(egressFootpath.second))) + ",";
      }
    }
    
    //std::cerr << "-- maxEgressTravelTime = " << maxEgressTravelTime << std::endl;





    if (params.debugDisplay)
      std::cerr << "-- access and egress footpaths -- " << algorithmCalculationTime.getDurationMicrosecondsNoStop() - calculationTime << " microseconds\n";
    calculationTime = algorithmCalculationTime.getDurationMicrosecondsNoStop();






    // disable trips according to parameters:
    i = 0;
    for (auto & trip : trips)
    {
      if (params.onlyServicesIdx.size() > 0)
      {
        if (std::find(params.onlyServicesIdx.begin(), params.onlyServicesIdx.end(), trip.serviceIdx) == params.onlyServicesIdx.end())
        {
          tripsEnabled[i] = -1;
        }
      }
      
      if (params.onlyLinesIdx.size() > 0)
      {
        if (std::find(params.onlyLinesIdx.begin(), params.onlyLinesIdx.end(), trip.lineIdx) == params.onlyLinesIdx.end())
        {
          tripsEnabled[i] = -1;
        }
      }
      
      if (params.onlyModesIdx.size() > 0)
      {
        if (std::find(params.onlyModesIdx.begin(), params.onlyModesIdx.end(), trip.modeIdx) == params.onlyModesIdx.end())
        {
          tripsEnabled[i] = -1;
        }
      }
      
      if (params.onlyAgenciesIdx.size() > 0)
      {
        if (std::find(params.onlyAgenciesIdx.begin(), params.onlyAgenciesIdx.end(), trip.agencyIdx) == params.onlyAgenciesIdx.end())
        {
          tripsEnabled[i] = -1;
        }
      }
      
      
      
      if (params.exceptServicesIdx.size() > 0)
      {
        if (std::find(params.exceptServicesIdx.begin(), params.exceptServicesIdx.end(), trip.serviceIdx) != params.exceptServicesIdx.end())
        {
          tripsEnabled[i] = -1;
        }
      }
      
      if (params.exceptLinesIdx.size() > 0)
      {
        if (std::find(params.exceptLinesIdx.begin(), params.exceptLinesIdx.end(), trip.lineIdx) != params.exceptLinesIdx.end())
        {
          tripsEnabled[i] = -1;
        }
      }
      
      if (params.exceptModesIdx.size() > 0)
      {
        if (std::find(params.exceptModesIdx.begin(), params.exceptModesIdx.end(), trip.modeIdx) != params.exceptModesIdx.end())
        {
          tripsEnabled[i] = -1;
        }
      }
      
      if (params.exceptAgenciesIdx.size() > 0)
      {
        if (std::find(params.exceptAgenciesIdx.begin(), params.exceptAgenciesIdx.end(), trip.agencyIdx) != params.exceptAgenciesIdx.end())
        {
          tripsEnabled[i] = -1;
        }
      }
      
      i++;
    }
    




    if (params.debugDisplay)
      std::cerr << "-- filter trips -- " << algorithmCalculationTime.getDurationMicrosecondsNoStop() - calculationTime << " microseconds\n";
    calculationTime = algorithmCalculationTime.getDurationMicrosecondsNoStop();





  }



}
