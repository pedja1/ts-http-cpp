//
// Created by pedja on 23.8.16..
//

#ifndef TS_HTTP_CPP_NETWORK_H
#define TS_HTTP_CPP_NETWORK_H


class INetwork
{
public:
    virtual ~INetwork() {}
    virtual bool isNetworkAvailable() = 0;
};


#endif //TS_HTTP_CPP_NETWORK_H
