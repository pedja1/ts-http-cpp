//
// Created by pedja on 23.8.16..
//

#ifndef TS_HTTP_CPP_RESPONSEHANDLERIMPL_H
#define TS_HTTP_CPP_RESPONSEHANDLERIMPL_H


#include "IResponseHandler.h"


extern ResponseMessagePolicy* DEFAULT_RESPONSE_MESSAGE_POLICY;

class ResponseHandlerImpl : public IResponseHandler
{
public:
    virtual void onResponse(int requestCode, int responseStatus, ResponseParser *responseParser) override;
    ResponseHandlerImpl(int requestCode, ResponseParser* responseParser, ResponseMessagePolicy* responseMessagePolicy = DEFAULT_RESPONSE_MESSAGE_POLICY);
};


#endif //TS_HTTP_CPP_RESPONSEHANDLERIMPL_H
