//
// Created by pedja on 23.8.16..
// Default response parser, with basic functionality, you will probably want to extend this to do your stuff
//

#ifndef TS_HTTP_CPP_RESPONSEPARSER_H
#define TS_HTTP_CPP_RESPONSEPARSER_H

#include <string>

class IInternet;

enum Status
{
    /**
     * success - server returned http code &lt; 400 and response is also ok */
    RESPONSE_STATUS_SUCCESS,
    /**
     * server error - server returned http code &gt;= 400*/
    RESPONSE_STATUS_SERVER_ERROR,
    /**
     * server error - server returned http code &gt;= 400*/
    RESPONSE_STATUS_RESPONSE_ERROR,
    /**
     * client error - client wasnt able to reach server (network error, server unavailable...)*/
    RESPONSE_STATUS_CLIENT_ERROR,
    /**
      * response cancelled - response was cancelled*/
    RESPONSE_STATUS_CANCELLED
};

class Response;

class ResponseParser
{
protected:
    Response *response;
    void* parseObject;

public:
    ResponseParser(std::string);
    ResponseParser(Response*);

    void* getParseObject();
    Response* getServerResponse();
    int getResponseStatus();
    std::string getResponseMessage();
};


#endif //TS_HTTP_CPP_RESPONSEPARSER_H
