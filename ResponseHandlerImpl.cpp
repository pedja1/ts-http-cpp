//
// Created by pedja on 23.8.16..
//

#include "ResponseHandlerImpl.h"
#include "ResponseParser.h"
#include "Http.h"

ResponseMessagePolicy* DEFAULT_RESPONSE_MESSAGE_POLICY = new ResponseMessagePolicy();

ResponseHandlerImpl::ResponseHandlerImpl(int requestCode, ResponseParser* responseParser, ResponseMessagePolicy* responseMessagePolicy = DEFAULT_RESPONSE_MESSAGE_POLICY)
{
    if(!responseParser)return;
    if (responseParser->getResponseStatus() == RESPONSE_STATUS_SUCCESS)
    {
        if(!responseParser->getResponseMessage().empty() && responseMessagePolicy->isShowSuccessMessages())
            Http::instance()->ui->showToast(responseParser->getResponseMessage());
    }
    else
    {
        if(responseMessagePolicy->isShowErrorMessages())
        {
            Http::instance()->ui->showToast(!responseParser->getResponseMessage().empty() ? responseParser->getResponseMessage() : Http::instance()->textManager->getText("unknown_error"));
        }
    }
    onResponse(requestCode, responseParser->getResponseStatus(), responseParser);
}

void ResponseHandlerImpl::onResponse(int requestCode, int responseStatus, ResponseParser *responseParser)
{

}
