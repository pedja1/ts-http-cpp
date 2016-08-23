//
// Created by pedja on 23.8.16..
//

#include <iostream>
#include "Request.h"
#include <sstream>

Request::Request(Method _method)
{
    method = _method;
}

Request *Request::setFileParamName(std::string _fileParamName)
{
    fileParamName = _fileParamName;
    return this;
}

Request *Request::setRequestBody(std::string _requestBody)
{
    requestBody = _requestBody;
    if(!requestBody.empty())
        setPostMethod(BODY);
    return this;
}

Request *Request::setContentType(std::string _contentType)
{
    contentType = _contentType;
    return this;
}

Request *Request::setPostMethod(PostMethod _postMethod)
{
    postMethod = _postMethod;
    if(postMethod != BODY && !requestBody.empty())
    {
        if(LOGGING) std::cout << "Warning. requestBody is not empty, it will be ignored since new PostMethod is not PostMethod.BODY";
    }
    if(postMethod != FORM_DATA && (files.size() > 0))
    {
        if(LOGGING) std::cout << "Warning. Files will be ignored since new PostMethod is not PostMethod.FORM_DATA";
    }
    return this;
}

Request *Request::setFiles(std::vector<UploadFile> _files)
{
    files = _files;
    if(files.size() > 0)
        setPostMethod(FORM_DATA);
    return this;
}

Request *Request::setRequestUrl(std::string _requestUrl)
{
    requestUrl = _requestUrl;
    return this;
}

Request* Request::setMaxRetires(int _maxRetires)
{
    maxRetries = _maxRetires;
    return this;
}

int Request::getMaxRetries()
{
    return maxRetries;
}

Request *Request::addParam(std::string key, std::string value, bool forceAddToUrl)
{
    if(key.empty() || (!allowEmptyValues && value.empty()))
    {
        if(LOGGING) std::cout << "RequestBuilder >> addParam : param not set";
        return this;
    }
    if(forceAddToUrl || method == GET || method == DELETE)
    {
        urlParams.insert(key, encodeString(value));
    }
    else if(method == POST || method == PUT)
    {
        postParams.insert(key, value);
    }
    return this;
}

Request *Request::addParam(std::string key, int value, bool forceAddToUrl)
{
    Request::addParam(key, std::to_string(value), forceAddToUrl);
    return this;
}

Request *Request::addParam(std::string key, long value, bool forceAddToUrl)
{
    Request::addParam(key, std::to_string(value), forceAddToUrl);
    return this;
}

Request *Request::addParam(std::string key, float value, bool forceAddToUrl)
{
    Request::addParam(key, std::to_string(value), forceAddToUrl);
    return this;
}

Request *Request::addParam(std::string key, double value, bool forceAddToUrl)
{
    Request::addParam(key, std::to_string(value), forceAddToUrl);
    return this;
}

Request *Request::addParam(std::string key, bool value, bool forceAddToUrl)
{
    Request::addParam(key, std::to_string(value), forceAddToUrl);
    return this;
}

Request *Request::addUrlPart(std::string value)
{
    if(value.empty())
    {
        if(LOGGING)std::cout << "RequestBuilder >> addParam : param not set");
        return this;
    }
    if(builder->str().length() == 0)
    {
        if(!requestUrl.empty() && !requestUrl.back() == '/')
            *builder << "/";
    }
    else if(!builder->str().back() == '/')
    {
        *builder << "/";
    }
    *builder << value.front() == '/' ? value.substr(1, value.length()) : value;
    return this;
}

Request *Request::addUrlPart(int value)
{
    Request::addUrlPart(std::to_string(value));
    return this;
}

Request *Request::addUrlPart(double value)
{
    Request::addUrlPart(std::to_string(value));
    return this;
}

Request *Request::addUrlPart(float value)
{
    Request::addUrlPart(std::to_string(value));
    return this;
}

Request *Request::addUrlPart(bool value)
{
    Request::addUrlPart(std::to_string(value));
    return this;
}

Request *Request::addUrlPart(long value)
{
    Request::addUrlPart(std::to_string(value));
    return this;
}

Request *Request::addHeader(std::string key, std::string value)
{
    headers.insert(key, value);
    return this;
}

std::string Request::getUrlParams()
{
    std::string urlParts = builder->str();
    std::stringstream tmpBuilder;
    for(auto kv : urlParams)
    {
        if(tmpBuilder.str().find('?') == std::string::npos)
            tmpBuilder << '?';
        else
            tmpBuilder << '&';
        tmpBuilder << kv.first << '=' << kv.second;
    }
    return urlParts.empty() ? "" : urlParts + tmpBuilder.str();
}

Request *Request::setResponseMessagePolicy(ResponseMessagePolicy* _responseMessagePolicy)
{
    responseMessagePolicy = _responseMessagePolicy;
    return this;
}

Method Request::getMethod()
{
    return method;
}

PostMethod Request::getPostMethod()
{
    return postMethod;
}

std::string Request::getContentType()
{
    return contentType;
}

std::string Request::getRequestBody()
{
    return requestUrl;
}

std::vector<UploadFile> *Request::getFiles()
{
    return &files;
}

std::string Request::getFileParamName()
{
    return fileParamName;
}

std::string Request::getParam(std::string param)
{
    std::string urlParam = ((auto)urlParams.find(param)).first;
    if(!urlParam.empty())
        return urlParam;
    std::string postParam = ((auto)postParam.find(param)).first;
    if(!postParam.empty())
        return postParam;
    return 0;
}

bool Request::setAllowEmptyValues()
{
    return allowEmptyValues;
}

IRequestHandler* Request::getRequestHandler()
{
    return requestHandler;
}

Request *Request::setRequestHandler(IRequestHandler* _requestHandler)
{
    requestHandler = _requestHandler;
    return this;
}
