//
// Created by pedja on 23.8.16..
//

#include "ResponseParser.h"

ResponseParser::ResponseParser(std::string _response)
{
    response = new Response;
    response->code = 200;
    response->responseDataString = _response;
}

ResponseParser::ResponseParser(Response *_response)
{
    response = _response;
}

void *ResponseParser::getParseObject()
{
    return parseObject;
}

Response *ResponseParser::getServerResponse()
{
    return response;
}

int ResponseParser::getResponseStatus()
{
    if(response->code < 0)
        return RESPONSE_STATUS_CLIENT_ERROR;
    else if(response->code < 400)
        return RESPONSE_STATUS_SUCCESS;
    else
        return RESPONSE_STATUS_SERVER_ERROR;
}

std::string ResponseParser::getResponseMessage()
{
    return response->responseMessage;
}
