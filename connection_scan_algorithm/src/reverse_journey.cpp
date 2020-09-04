#include "calculator.hpp"
#include "json.hpp"

namespace TrRouting
{

  RoutingResult Calculator::reverseJourney(int bestDepartureTime, int bestAccessNodeIndex, int bestAccessTravelTime, int bestAccessDistance)
  {
  
    RoutingResult    result;
    nlohmann::json   json;
    int              nodesCount           {1};
    int              i                    {0};
    int              reachableNodesCount  {0};
    bool             foundRoute           {false};

    int transferableModeIdx {modeIndexesByShortname["transferable"]};

    std::vector<int> resultingNodes;
    if (params.returnAllNodesResult)
    {
      nodesCount     = nodes.size();
      json["nodes"]  = nlohmann::json::array();
      resultingNodes = std::vector<int>(nodesCount);
      std::iota (std::begin(resultingNodes), std::end(resultingNodes), 0); // generate sequencial indexes of each nodes
    }
    else if (bestDepartureTime > -1) // route found
    {
      foundRoute = true;
      resultingNodes.push_back(bestAccessNodeIndex);
    }

    if (foundRoute || params.returnAllNodesResult)
    {

      std::deque<std::tuple<int,int,int,int,int,short,int>> journey;
      std::tuple<int,int,int,int,int,short,int>         resultingNodeJourneyStep;
      std::tuple<int,int,int,int,int,short,int>         emptyJourneyStep {-1,-1,-1,-1,-1,-1,-1};
      std::tuple<int,int,int,int,int,short,short,int,int,int,short,short> * journeyStepEnterConnection; // connection tuple: departureNodeIndex, arrivalNodeIndex, departureTimeSeconds, arrivalTimeSeconds, tripIndex, canBoard, canUnboard, sequenceinTrip
      std::tuple<int,int,int,int,int,short,short,int,int,int,short,short> * journeyStepExitConnection;
      std::vector<boost::uuids::uuid>                   lineUuids;
      std::vector<int>                                  linesIdx;
      std::vector<std::string>                          modeShortnames;
      std::vector<boost::uuids::uuid>                   agencyUuids;
      std::vector<boost::uuids::uuid>                   unboardingNodeUuids;
      std::vector<boost::uuids::uuid>                   boardingNodeUuids;
      std::vector<boost::uuids::uuid>                   tripUuids;
      std::vector<int>                                  tripsIdx;
      std::vector<int>                                  inVehicleTravelTimesSeconds; // the in vehicle travel time for each segment
      std::vector<std::tuple<int, int, int, int, int>>  legs; // tuple: tripIdx, lineIdx, pathIdx, start connection index, end connection index
      nlohmann::json stepJson = {};
      nlohmann::json nodeJson = {};

      Node *   journeyStepNodeDeparture;
      Node *   journeyStepNodeArrival;
      Trip *   journeyStepTrip;
      Line *   journeyStepLine;
      Mode     journeyStepMode;
      Path *   journeyStepPath;
      Agency * journeyStepAgency;
      
      int totalInVehicleTime       { 0}; int transferArrivalTime    {-1}; int firstDepartureTime   {-1};
      int totalWalkingTime         { 0}; int transferReadyTime      {-1}; int numberOfTransfers    {-1};
      int totalWaitingTime         { 0}; int departureTime          {-1}; int boardingSequence     {-1};
      int totalTransferWalkingTime { 0}; int arrivalTime            {-1}; int unboardingSequence   {-1};
      int totalTransferWaitingTime { 0}; int inVehicleTime          {-1}; int bestEgressNodeIndex  {-1};
      int totalDistance            { 0}; int distance               {-1};
      int inVehicleDistance        {-1}; int totalInVehicleDistance { 0}; int totalWalkingDistance { 0};
      int totalTransferDistance    {-1}; int accessDistance         { 0}; int egressDistance       { 0};
      int journeyStepTravelTime    {-1}; int accessWalkingTime      {-1};
      int transferTime             {-1}; int egressWalkingTime      {-1};
      int waitingTime              {-1}; int accessWaitingTime      {-1};
  
      for (auto & resultingNodeIndex : resultingNodes)
      {
        
        legs.clear();
        journey.clear();
        lineUuids.clear();
        linesIdx.clear();
        boardingNodeUuids.clear();
        unboardingNodeUuids.clear();
        tripUuids.clear();
        tripsIdx.clear();
        modeShortnames.clear();
        inVehicleTravelTimesSeconds.clear();
        
        totalInVehicleTime          =  0; transferArrivalTime    = -1; firstDepartureTime   = -1;
        totalWalkingTime            =  0; transferReadyTime      = -1; numberOfTransfers    = -1;
        totalWaitingTime            =  0; departureTime          = -1; boardingSequence     = -1;
        totalTransferWalkingTime    =  0; arrivalTime            = -1; unboardingSequence   = -1;
        totalTransferWaitingTime    =  0; inVehicleTime          = -1; bestEgressNodeIndex  = -1;
        totalDistance               =  0; distance               = -1; 
        inVehicleDistance           =  0; totalInVehicleDistance =  0; totalWalkingDistance =  0;
        totalTransferDistance       =  0; accessDistance         =  0; egressDistance       =  0;
        journeyStepTravelTime       = -1; accessWalkingTime      = -1; 
        transferTime                = -1; egressWalkingTime      = -1; 
        waitingTime                 = -1; accessWaitingTime      = -1; 
        
        // recreate journey:
        resultingNodeJourneyStep = reverseAccessJourneys[resultingNodeIndex];
        
        if (resultingNodeJourneyStep == emptyJourneyStep) // ignore nodes with no route
        {
          continue;
        }
        //std::cerr << nodes[bestEgressNodeIndex].get()->name << std::endl;
        i = 0;
        while ((std::get<journeyIndexes::FINAL_ENTER_CONNECTION>(resultingNodeJourneyStep) != -1 && std::get<journeyIndexes::FINAL_EXIT_CONNECTION>(resultingNodeJourneyStep) != -1))
        {
          if (journey.size() > 0)
          {
            std::get<journeyIndexes::TRANSFER_TRAVEL_TIME>(journey[journey.size()-1]) = std::get<journeyIndexes::TRANSFER_TRAVEL_TIME>(resultingNodeJourneyStep);
            std::get<journeyIndexes::TRANSFER_DISTANCE>(journey[journey.size()-1])    = std::get<journeyIndexes::TRANSFER_DISTANCE>(resultingNodeJourneyStep);
          }
          journey.push_back(resultingNodeJourneyStep);
          bestEgressNodeIndex      = std::get<connectionIndexes::NODE_ARR>(*reverseConnections[std::get<journeyIndexes::FINAL_EXIT_CONNECTION>(resultingNodeJourneyStep)].get());
          resultingNodeJourneyStep = reverseJourneys[bestEgressNodeIndex];
          
          i++;
        }
        
        if (!params.returnAllNodesResult)
        {
          json["steps"] = nlohmann::json::array();
          journey.push_front(std::make_tuple(-1,-1,-1,-1,nodesAccessTravelTime[resultingNodeIndex],-1,nodesAccessDistance[resultingNodeIndex]));
        }
        journey.push_back(std::make_tuple(-1,-1,-1,-1,nodesEgressTravelTime[bestEgressNodeIndex],-1,nodesEgressDistance[bestEgressNodeIndex]));
               
        i = 0;
        int journeyStepsCount = journey.size();
        for (auto & journeyStep : journey)
        {
          
          if (std::get<journeyIndexes::FINAL_ENTER_CONNECTION>(journeyStep) != -1 && std::get<journeyIndexes::FINAL_EXIT_CONNECTION>(journeyStep) != -1)
          {
            // journey tuple: final enter connection, final exit connection, final footpath
            journeyStepEnterConnection  = reverseConnections[std::get<journeyIndexes::FINAL_ENTER_CONNECTION>(journeyStep)].get();
            journeyStepExitConnection   = reverseConnections[std::get<journeyIndexes::FINAL_EXIT_CONNECTION>(journeyStep)].get();
            journeyStepNodeDeparture    = nodes[std::get<connectionIndexes::NODE_DEP>(*journeyStepEnterConnection)].get();
            journeyStepNodeArrival      = nodes[std::get<connectionIndexes::NODE_ARR>(*journeyStepExitConnection)].get();
            journeyStepTrip             = trips[std::get<journeyIndexes::FINAL_TRIP>(journeyStep)].get();
            journeyStepAgency           = agencies[journeyStepTrip->agencyIdx].get();
            journeyStepLine             = lines[journeyStepTrip->lineIdx].get();
            journeyStepPath             = paths[journeyStepTrip->pathIdx].get();
            journeyStepMode             = modes[journeyStepLine->modeIdx];
            transferTime                = std::get<journeyIndexes::TRANSFER_TRAVEL_TIME>(journeyStep);
            distance                    = std::get<journeyIndexes::TRANSFER_DISTANCE>(journeyStep);
            inVehicleDistance           = 0;
            departureTime               = std::get<connectionIndexes::TIME_DEP>(*journeyStepEnterConnection);
            arrivalTime                 = std::get<connectionIndexes::TIME_ARR>(*journeyStepExitConnection);
            boardingSequence            = std::get<connectionIndexes::SEQUENCE>(*journeyStepEnterConnection);
            unboardingSequence          = std::get<connectionIndexes::SEQUENCE>(*journeyStepExitConnection);
            inVehicleTime               = arrivalTime   - departureTime;
            waitingTime                 = departureTime - transferArrivalTime;
            transferArrivalTime         = arrivalTime   + transferTime;
            transferReadyTime           = transferArrivalTime;

            if (journey.size() > i + 1 && std::get<journeyIndexes::FINAL_ENTER_CONNECTION>(journey[i+1]) != -1)
            {
              transferReadyTime += (std::get<connectionIndexes::MIN_WAITING_TIME_SECONDS>(*reverseConnections[std::get<journeyIndexes::FINAL_ENTER_CONNECTION>(journey[i+1])].get()) >= 0 ? std::get<connectionIndexes::MIN_WAITING_TIME_SECONDS>(*reverseConnections[std::get<journeyIndexes::FINAL_ENTER_CONNECTION>(journey[i+1])].get()) : params.minWaitingTimeSeconds);
            }

            totalInVehicleTime         += inVehicleTime;
            totalWaitingTime           += waitingTime;
            if (transferableModeIdx != journeyStepLine->modeIdx)
            {
              numberOfTransfers += 1;
            }
            lineUuids.push_back(journeyStepLine->uuid);
            linesIdx.push_back(journeyStepTrip->lineIdx);
            modeShortnames.push_back(journeyStepMode.shortname);
            inVehicleTravelTimesSeconds.push_back(inVehicleTime);
            agencyUuids.push_back(journeyStepAgency->uuid);
            boardingNodeUuids.push_back(journeyStepNodeDeparture->uuid);
            unboardingNodeUuids.push_back(journeyStepNodeArrival->uuid);
            tripUuids.push_back(journeyStepTrip->uuid);
            tripsIdx.push_back(std::get<journeyIndexes::FINAL_TRIP>(journeyStep));
            legs.push_back(std::make_tuple(std::get<journeyIndexes::FINAL_TRIP>(journeyStep), journeyStepTrip->lineIdx, journeyStepTrip->pathIdx, boardingSequence - 1, unboardingSequence - 1));
            
            if (unboardingSequence - 1 < journeyStepPath->segmentsDistanceMeters.size()) // check if distances are available for this path
            {
              for (int seqI = boardingSequence - 1; seqI < unboardingSequence; seqI++)
              {
                inVehicleDistance += journeyStepPath->segmentsDistanceMeters[seqI];
              }
              totalDistance += inVehicleDistance;
              if (transferableModeIdx == journeyStepLine->modeIdx)
              {
                totalWalkingDistance     += inVehicleDistance;
                totalWalkingTime         += inVehicleTime;
                totalTransferDistance    += inVehicleDistance;
                totalTransferWalkingTime += inVehicleTime;
              }
              else
              {
                totalInVehicleDistance += inVehicleDistance;
              }
            }
            else
            {
              inVehicleDistance      = -1;
              totalDistance          = -1;
              totalInVehicleDistance = -1;
            }

            if (i == 1) // first leg
            {
              firstDepartureTime  = departureTime;
              accessWaitingTime   = waitingTime;
            }
            else
            {
              totalTransferWaitingTime += waitingTime;
            }
            
            if (!params.returnAllNodesResult)
            {
              stepJson                         = {};
              stepJson["action"]               = "board";
              stepJson["agencyAcronym"]        = journeyStepAgency->acronym;
              stepJson["agencyName"]           = journeyStepAgency->name;
              stepJson["agencyUuid"]           = boost::uuids::to_string(journeyStepAgency->uuid);
              stepJson["lineShortname"]        = journeyStepLine->shortname;
              stepJson["lineLongname"]         = journeyStepLine->longname;
              stepJson["lineUuid"]             = boost::uuids::to_string(journeyStepLine->uuid);
              stepJson["pathUuid"]             = boost::uuids::to_string(journeyStepPath->uuid);
              stepJson["modeName"]             = journeyStepMode.name;
              stepJson["mode"]                 = journeyStepMode.shortname;
              stepJson["tripUuid"]             = boost::uuids::to_string(journeyStepTrip->uuid);
              stepJson["legSequenceInTrip"]    = boardingSequence;
              stepJson["stopSequenceInTrip"]   = boardingSequence;
              stepJson["nodeName"]             = journeyStepNodeDeparture->name;
              stepJson["nodeCode"]             = journeyStepNodeDeparture->code;
              stepJson["nodeUuid"]             = boost::uuids::to_string(journeyStepNodeDeparture->uuid);
              stepJson["nodeCoordinates"]      = {journeyStepNodeDeparture->point.get()->longitude, journeyStepNodeDeparture->point.get()->latitude};
              stepJson["departureTime"]        = Toolbox::convertSecondsToFormattedTime(departureTime);
              stepJson["departureTimeSeconds"] = departureTime;
              stepJson["waitingTimeSeconds"]   = waitingTime;
              stepJson["waitingTimeMinutes"]   = Toolbox::convertSecondsToMinutes(waitingTime);
              json["steps"].push_back(stepJson);

              stepJson                                = {};
              stepJson["action"]                      = "unboard";
              stepJson["agencyAcronym"]               = journeyStepAgency->acronym;
              stepJson["agencyName"]                  = journeyStepAgency->name;
              stepJson["agencyUuid"]                  = boost::uuids::to_string(journeyStepAgency->uuid);
              stepJson["lineShortname"]               = journeyStepLine->shortname;
              stepJson["lineLongname"]                = journeyStepLine->longname;
              stepJson["lineUuid"]                    = boost::uuids::to_string(journeyStepLine->uuid);
              stepJson["pathUuid"]                    = boost::uuids::to_string(journeyStepPath->uuid);
              stepJson["modeName"]                    = journeyStepMode.name;
              stepJson["mode"]                        = journeyStepMode.shortname;
              stepJson["tripUuid"]                    = boost::uuids::to_string(journeyStepTrip->uuid);
              stepJson["legSequenceInTrip"]           = unboardingSequence;
              stepJson["stopSequenceInTrip"]          = unboardingSequence + 1;
              stepJson["nodeName"]                    = journeyStepNodeArrival->name;
              stepJson["nodeCode"]                    = journeyStepNodeArrival->code;
              stepJson["nodeUuid"]                    = boost::uuids::to_string(journeyStepNodeArrival->uuid);
              stepJson["nodeCoordinates"]             = {journeyStepNodeArrival->point.get()->longitude, journeyStepNodeArrival->point.get()->latitude};
              stepJson["arrivalTime"]                 = Toolbox::convertSecondsToFormattedTime(arrivalTime);
              stepJson["arrivalTimeSeconds"]          = arrivalTime;
              stepJson["inVehicleTimeSeconds"]        = inVehicleTime;
              stepJson["inVehicleTimeMinutes"]        = Toolbox::convertSecondsToMinutes(inVehicleTime);
              stepJson["inVehicleDistanceMeters"]     = inVehicleDistance;
              json["steps"].push_back(stepJson);
            }
            if (i < journeyStepsCount - 2) // if not the last transit leg
            {
              totalTransferWalkingTime += transferTime;
              totalWalkingTime         += transferTime;
              if (totalDistance != -1)
              {
                totalDistance += distance;
              }
              totalWalkingDistance     += distance;
              totalTransferDistance    += distance;
              if (!params.returnAllNodesResult)
              {
                stepJson                         = {};
                stepJson["action"]               = "walking";
                stepJson["type"]                 = "transfer";
                stepJson["travelTimeSeconds"]    = transferTime;
                stepJson["travelTimeMinutes"]    = Toolbox::convertSecondsToMinutes(transferTime);
                stepJson["distanceMeters"]       = distance;
                stepJson["departureTime"]        = Toolbox::convertSecondsToFormattedTime(arrivalTime);
                stepJson["arrivalTime"]          = Toolbox::convertSecondsToFormattedTime(transferArrivalTime);
                stepJson["departureTimeSeconds"] = arrivalTime;
                stepJson["arrivalTimeSeconds"]   = transferArrivalTime;
                stepJson["readyToBoardAt"]       = Toolbox::convertSecondsToFormattedTime(transferReadyTime);
                json["steps"].push_back(stepJson);
              }
            }
          }
          else // access or egress journey step
          {
            
            transferTime          = std::get<journeyIndexes::TRANSFER_TRAVEL_TIME>(journeyStep);
            distance              = std::get<journeyIndexes::TRANSFER_DISTANCE>(journeyStep);
            if (totalDistance != -1)
            {
              totalDistance += distance;
            }
            totalWalkingDistance += distance;
            if (i == 0) // access
            {
              
              transferArrivalTime  = (initialDepartureTimeSeconds != -1 ? initialDepartureTimeSeconds : bestDepartureTime) + transferTime;
              transferReadyTime    = transferArrivalTime;

              if (journey.size() > i + 1 && std::get<journeyIndexes::FINAL_ENTER_CONNECTION>(journey[i+1]) != -1)
              {
                transferReadyTime += (std::get<connectionIndexes::MIN_WAITING_TIME_SECONDS>(*reverseConnections[std::get<journeyIndexes::FINAL_ENTER_CONNECTION>(journey[i+1])].get()) >= 0 ? std::get<connectionIndexes::MIN_WAITING_TIME_SECONDS>(*reverseConnections[std::get<journeyIndexes::FINAL_ENTER_CONNECTION>(journey[i+1])].get()) : params.minWaitingTimeSeconds);
              }

              totalWalkingTime    += transferTime;
              accessWalkingTime    = transferTime;
              accessDistance       = distance;
              if (!params.returnAllNodesResult)
              {
                stepJson                         = {};
                stepJson["action"]               = "walking";
                stepJson["type"]                 = "access";
                stepJson["travelTimeSeconds"]    = transferTime;
                stepJson["travelTimeMinutes"]    = Toolbox::convertSecondsToMinutes(transferTime);
                stepJson["distanceMeters"]       = distance;
                stepJson["departureTime"]        = Toolbox::convertSecondsToFormattedTime((initialDepartureTimeSeconds != -1 ? initialDepartureTimeSeconds : bestDepartureTime));
                stepJson["arrivalTime"]          = Toolbox::convertSecondsToFormattedTime(transferArrivalTime);
                stepJson["departureTimeSeconds"] = bestDepartureTime;
                stepJson["arrivalTimeSeconds"]   = transferArrivalTime;
                stepJson["readyToBoardAt"]       = Toolbox::convertSecondsToFormattedTime(transferReadyTime);
                json["steps"].push_back(stepJson);
                
              }
            }
            else // egress
            {
              totalWalkingTime   += transferTime;
              egressWalkingTime   = transferTime;
              transferArrivalTime = arrivalTime + transferTime;
              egressDistance      = distance;
              if (!params.returnAllNodesResult)
              {
                stepJson                         = {};
                stepJson["action"]               = "walking";
                stepJson["type"]                 = "egress";
                stepJson["travelTimeSeconds"]    = transferTime;
                stepJson["travelTimeMinutes"]    = Toolbox::convertSecondsToMinutes(transferTime);
                stepJson["distanceMeters"]       = distance;
                stepJson["departureTime"]        = Toolbox::convertSecondsToFormattedTime(arrivalTime);
                stepJson["arrivalTime"]          = Toolbox::convertSecondsToFormattedTime(arrivalTime + transferTime);
                stepJson["departureTimeSeconds"] = arrivalTime;
                stepJson["arrivalTimeSeconds"]   = arrivalTime + transferTime;
                json["steps"].push_back(stepJson);
              }
              arrivalTime = transferArrivalTime;
            }
          }
          i++;
        }
                
        if (params.returnAllNodesResult)
        {
          if (std::get<journeyIndexes::FINAL_ENTER_CONNECTION>(reverseAccessJourneys[resultingNodeIndex]) != -1)
          {
            departureTime = std::get<connectionIndexes::TIME_DEP>(*reverseConnections[std::get<journeyIndexes::FINAL_ENTER_CONNECTION>(reverseAccessJourneys[resultingNodeIndex])].get()) - std::get<connectionIndexes::MIN_WAITING_TIME_SECONDS>(*reverseConnections[std::get<journeyIndexes::FINAL_ENTER_CONNECTION>(reverseAccessJourneys[resultingNodeIndex])].get());
            if (arrivalTimeSeconds - departureTime <= params.maxTotalTravelTimeSeconds)
            {
              reachableNodesCount++;
              nodeJson                           = {};
              nodeJson["id"]                     = boost::uuids::to_string(nodes[resultingNodeIndex].get()->uuid);
              nodeJson["departureTime"]          = Toolbox::convertSecondsToFormattedTime(departureTime);
              nodeJson["departureTimeSeconds"]   = departureTime;
              nodeJson["totalTravelTimeSeconds"] = arrivalTimeSeconds - departureTime;
              nodeJson["numberOfTransfers"]      = numberOfTransfers;
              json["nodes"].push_back(nodeJson);
            }
          }
        }
        else if (!params.returnAllNodesResult)
        {
          if (json["steps"].size() > 0)
          {

            json["status"]                                         = "success";
            json["origin"]                                         = { origin->longitude,      origin->latitude      };
            json["destination"]                                    = { destination->longitude, destination->latitude };
            json["departureTime"]                                  = initialDepartureTimeSeconds != -1 ? Toolbox::convertSecondsToFormattedTime(initialDepartureTimeSeconds) : Toolbox::convertSecondsToFormattedTime(bestDepartureTime);
            json["arrivalTime"]                                    = Toolbox::convertSecondsToFormattedTime(arrivalTime);
            json["departureTimeSeconds"]                           = initialDepartureTimeSeconds != -1 ? initialDepartureTimeSeconds : bestDepartureTime;
            json["arrivalTimeSeconds"]                             = arrivalTime;
            json["totalTravelTimeMinutes"]                         = Toolbox::convertSecondsToMinutes(arrivalTime - (initialDepartureTimeSeconds != -1 ? initialDepartureTimeSeconds : bestDepartureTime));
            json["totalTravelTimeSeconds"]                         = arrivalTime - (initialDepartureTimeSeconds != -1 ? initialDepartureTimeSeconds : bestDepartureTime);
            json["totalDistanceMeters"]                            = totalDistance;
            json["totalInVehicleTimeMinutes"]                      = Toolbox::convertSecondsToMinutes(totalInVehicleTime);
            json["totalInVehicleTimeSeconds"]                      = totalInVehicleTime;
            json["totalInVehicleDistanceMeters"]                   = totalInVehicleDistance;
            json["totalNonTransitTravelTimeMinutes"]               = Toolbox::convertSecondsToMinutes(totalWalkingTime);
            json["totalNonTransitTravelTimeSeconds"]               = totalWalkingTime;
            json["totalNonTransitDistanceMeters"]                  = totalWalkingDistance;
            json["numberOfBoardings"]                              = numberOfTransfers + 1;
            json["numberOfTransfers"]                              = numberOfTransfers == -1 ? 0 : numberOfTransfers;
            json["transferWalkingTimeMinutes"]                     = Toolbox::convertSecondsToMinutes(totalTransferWalkingTime);
            json["transferWalkingTimeSeconds"]                     = totalTransferWalkingTime;
            json["transferWalkingDistanceMeters"]                  = totalTransferDistance;
            json["accessTravelTimeMinutes"]                        = Toolbox::convertSecondsToMinutes(accessWalkingTime);
            json["accessTravelTimeSeconds"]                        = accessWalkingTime;
            json["accessDistanceMeters"]                           = accessDistance;
            json["egressTravelTimeMinutes"]                        = Toolbox::convertSecondsToMinutes(egressWalkingTime);
            json["egressTravelTimeSeconds"]                        = egressWalkingTime;
            json["egressDistanceMeters"]                           = egressDistance;
            json["transferWaitingTimeMinutes"]                     = Toolbox::convertSecondsToMinutes(totalTransferWaitingTime);
            json["transferWaitingTimeSeconds"]                     = totalTransferWaitingTime;
            json["firstWaitingTimeMinutes"]                        = Toolbox::convertSecondsToMinutes(accessWaitingTime);
            json["firstWaitingTimeSeconds"]                        = accessWaitingTime;
            json["totalWaitingTimeMinutes"]                        = Toolbox::convertSecondsToMinutes(totalWaitingTime);
            json["totalWaitingTimeSeconds"]                        = totalWaitingTime;
            json["departureTimeToMinimizeFirstWaitingTime"]        = Toolbox::convertSecondsToFormattedTime(bestDepartureTime);
            json["departureTimeSecondsToMinimizeFirstWaitingTime"] = bestDepartureTime;
            json["minimizedTotalTravelTimeMinutes"]                = Toolbox::convertSecondsToMinutes(arrivalTime - bestDepartureTime);
            json["minimizedTotalTravelTimeSeconds"]                = arrivalTime - bestDepartureTime;
            json["minimumWaitingTimeBeforeEachBoardingMinutes"]    = Toolbox::convertSecondsToMinutes(params.minWaitingTimeSeconds);
            json["minimumWaitingTimeBeforeEachBoardingSeconds"]    = params.minWaitingTimeSeconds;
            
            result.travelTimeSeconds             = arrivalTime - (initialDepartureTimeSeconds != -1 ? initialDepartureTimeSeconds : bestDepartureTime);
            result.arrivalTimeSeconds            = arrivalTime;
            result.departureTimeSeconds          = (initialDepartureTimeSeconds != -1 ? initialDepartureTimeSeconds : bestDepartureTime);
            result.minimizedDepartureTimeSeconds = bestDepartureTime;
            result.numberOfTransfers             = numberOfTransfers;
            result.inVehicleTravelTimeSeconds    = totalInVehicleTime;
            result.transferTravelTimeSeconds     = totalTransferWalkingTime;
            result.waitingTimeSeconds            = totalWaitingTime;
            result.accessTravelTimeSeconds       = accessWalkingTime;
            result.egressTravelTimeSeconds       = egressWalkingTime;
            result.transferWaitingTimeSeconds    = totalTransferWaitingTime;
            result.firstWaitingTimeSeconds       = accessWaitingTime;
            result.nonTransitTravelTimeSeconds   = totalWalkingTime;
            result.legs                          = legs;
            result.lineUuids                     = lineUuids;
            result.linesIdx                      = linesIdx;
            result.modeShortnames                = modeShortnames;
            result.agencyUuids                   = agencyUuids;
            result.boardingNodeUuids             = boardingNodeUuids;
            result.unboardingNodeUuids           = unboardingNodeUuids;
            result.tripUuids                     = tripUuids;
            result.tripsIdx                      = tripsIdx;
            result.inVehicleTravelTimesSeconds   = inVehicleTravelTimesSeconds;
            result.status                        = "success";
            
          }
        }
      }
    }
    else // no route found
    {
      json["status"]                     = "no_routing_found";
      json["origin"]                     = { origin->longitude,      origin->latitude      };
      json["destination"]                = { destination->longitude, destination->latitude };
      json["arrivalTime"]                = Toolbox::convertSecondsToFormattedTime(arrivalTimeSeconds);
      json["arrivalTimeSeconds"]         = arrivalTimeSeconds;
      result.status                      = "no_routing_found";
      result.travelTimeSeconds           = -1;
      result.arrivalTimeSeconds          = arrivalTimeSeconds;
      result.numberOfTransfers           = -1;
      result.inVehicleTravelTimeSeconds  = -1;
      result.transferTravelTimeSeconds   = -1;
      result.waitingTimeSeconds          = -1;
      result.accessTravelTimeSeconds     = -1;
      result.egressTravelTimeSeconds     = -1;
      result.transferWaitingTimeSeconds  = -1;
      result.firstWaitingTimeSeconds     = -1;
      result.nonTransitTravelTimeSeconds = -1;
    }

    if (params.returnAllNodesResult)
    {
      json["numberOfReachableNodes"]  = reachableNodesCount;
      json["percentOfReachableNodes"] = round(10000 * (float)reachableNodesCount / (float)(nodesCount))/100.0;
    }

    result.json = json;
    
    return result;
  }

}
