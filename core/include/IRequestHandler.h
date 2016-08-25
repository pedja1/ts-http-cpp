//
// Created by pedja on 23.8.16..
//

#ifndef TS_HTTP_CPP_REQUESTHANDLER_H
#define TS_HTTP_CPP_REQUESTHANDLER_H

class Request;
class ResponseParser;

class IRequestHandler
{
public:
    virtual ~IRequestHandler() {}
    /**
     * Here you should make network request and return ResponseParser instance
     * @param requestCode unique request code for this request
     * @param builder RequestBuilder instance
     * @param sync if this request is done on caller thread or async
     * @return ResponseParser to be passed to other methods*/
    virtual ResponseParser* handleRequest(int requestCode, Request* request, bool sync) = 0;

    /**
     * Called before request is executed
     * @param requestCode unique request code for this request
     * @param sync if this request is done on caller thread or async
     * */
    virtual void handlePreRequest(int requestCode, bool sync) = 0;

    /**
     * Called when request is done
     * @param requestCode unique request code for this request
     * @param builder RequestBuilder instance
     * @param sync if this request is done on caller thread or async
     * @param parser ResponseParser instance returned from {@link #handleRequest(int, Request, boolean)}*/
    virtual void handlePostRequest(int requestCode, Request* request, ResponseParser* responseParser, bool sync) = 0;

    /**
     * Called when request is done
     * @param requestCode unique request code for this request
     * @param sync if this request is done on caller thread or async
     * @param parser ResponseParser instance returned from {@link #handleRequest(int, Request, boolean)}*/
    virtual void handleRequestCancelled(int requestCode, ResponseParser* responseParser, bool sync) = 0;
};


#endif //TS_HTTP_CPP_REQUESTHANDLER_H
