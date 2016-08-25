//
// Created by pedja on 23.8.16..
//

#ifndef TS_HTTP_CPP_INTERNET_H
#define TS_HTTP_CPP_INTERNET_H

class Request;

class Response
{
public:
    int code = -1;
    std::string responseMessage;
    std::string responseDetailedMessage;
    std::string responseDataString;
    void* responseData;
    std::string request;

    bool isResponseOk()
    {
        return code > 0 && code < 400;
    }
};

class IInternet
{
public:
    virtual ~IInternet() {}
    /**
     * Executes HTTP POST request and returns response as string<br>
     * This method will not check if response code from server is OK ( &lt; 400)<br>
     *
     * @param request request builder object, used to build request. cannot be null
     * @param streamToString true if you want to convert input stream to string, if true you shouldn't try to use InputStream after
     * @return server response as string
     */
    virtual Response executeHttpRequest(Request* request) = 0;
};

#endif //TS_HTTP_CPP_INTERNET_H
