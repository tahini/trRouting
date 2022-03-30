#ifndef TR_RESULT_TO_RESPONSE
#define TR_RESULT_TO_RESPONSE

#include "json.hpp"
#include "parameters.hpp"
#include "routing_result.hpp"

namespace TrRouting
{
  
  /**
   * @brief Converts a routing result object to a json response
   */
  class ResultToResponse {
  public:
    virtual nlohmann::json resultToJsonString(RoutingResult& result, RouteParameters& params) = 0;
    virtual nlohmann::json noRoutingFoundResponse(RouteParameters& params) = 0;
  };

}

#endif // TR_RESULT_TO_RESPONSE
