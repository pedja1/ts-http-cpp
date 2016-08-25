//
// Created by pedja on 23.8.16..
//

#ifndef TS_HTTP_CPP_REQUESTMANAGER_H
#define TS_HTTP_CPP_REQUESTMANAGER_H


#include <stdexcept>

class RequestManager
{
    static RequestManager* s_instance;

public:
    static RequestManager *instance();

    static void initialize(RequestManager *requestManager);

    virtual ~RequestManager(){};

};


#endif //TS_HTTP_CPP_REQUESTMANAGER_H
