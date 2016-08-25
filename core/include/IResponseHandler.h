//
// Created by pedja on 23.8.16..
//

#ifndef TS_HTTP_CPP_RESPONSEHANDLER_H
#define TS_HTTP_CPP_RESPONSEHANDLER_H

enum ResponseMessageFormat
{
    show_as_toast, show_as_dialog, show_as_notification/*this one is stupid*/
};

class ResponseParser;

class IResponseHandler
{
public:
    virtual ~IResponseHandler() {}
    /**
     * Called if response from server is successful and doesn't contains errors
     * @param requestCode unique request code for this request
     * @param responseStatus status of the response
     * @param responseParser ResponseParser instance returned from {@link RequestHandler#handleRequest(int, Request, boolean)}
     * */
    virtual void onResponse(int requestCode, int responseStatus, ResponseParser* responseParser) = 0;
};

class ResponseMessagePolicy
{
    bool showSuccessMessages = true, showErrorMessages = false;
    /**
      * Not supported yet
      * */
    ResponseMessageFormat responseMessageFormat;

public:
    bool isShowSuccessMessages() const
    {
        return showSuccessMessages;
    }

    ResponseMessagePolicy* setShowSuccessMessages(bool showSuccessMessages)
    {
        ResponseMessagePolicy::showSuccessMessages = showSuccessMessages;
        return this;
    }

    bool isShowErrorMessages() const
    {
        return showErrorMessages;
    }

    ResponseMessagePolicy* setShowErrorMessages(bool showErrorMessages)
    {
        ResponseMessagePolicy::showErrorMessages = showErrorMessages;
        return this;
    }

    ResponseMessageFormat getResponseMessageFormat() const
    {
        return responseMessageFormat;
    }

    ResponseMessagePolicy* setResponseMessageFormat(ResponseMessageFormat responseMessageFormat)
    {
        ResponseMessagePolicy::responseMessageFormat = responseMessageFormat;
        return this;
    }
};

#endif //TS_HTTP_CPP_RESPONSEHANDLER_H
