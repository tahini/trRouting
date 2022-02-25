#ifndef TR_RESULT_TO_V2_RESPONSE
#define TR_RESULT_TO_V2_RESPONSE

#include "json.hpp"
#include "routing_result.hpp"
#include "parameters.hpp"
#include "result_to_response.hpp"

namespace TrRouting
{
  /**
   * @brief Convert a result object to a json object for the version 2 trRouting API, as described in docs/APIv2.yml
   */
  class ResultToV2Response: public ResultToResponse {
  public:
    virtual nlohmann::json resultToJsonString(RoutingResult& result, RouteParameters& params) override;
    virtual nlohmann::json noRoutingFoundResponse(RouteParameters& params) override;
  };

}

#endif // TR_RESULT_TO_V2_RESPONSE
