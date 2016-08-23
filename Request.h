//
// Created by pedja on 23.8.16..
//

#ifndef TS_HTTP_CPP_REQUEST_H
#define TS_HTTP_CPP_REQUEST_H

#include <string>
#include <unordered_map>
#include <vector>
#include "IRequestHandler.h"
#include "IResponseHandler.h"
#include "ResponseHandlerImpl.h"


extern std::string DEFAULT_REQUEST_URL;

/**
  * HTTP method used for this request*/
enum Method
{
    POST, GET, PUT, DELETE,
};

/**
  * Method for making HTTP POST request*/
enum PostMethod
{
    /**
     * Data will be sent as raw bytes(or text), you should specify Content-Type if you use this method<br>
     * You must set data with {@link #setRequestBody(String)}*/
            BODY,

    /**
     * This is used for normal HTTP posts, when you just need to send text to server<br>
     * This is default method*/
            X_WWW_FORM_URL_ENCODED,

    /**
     * This mus be used if you are sending file to the server*/
            FORM_DATA
};

class std::stringstream;

class Request
{
    std::stringstream *builder;
    std::unordered_map <std::string, std::string> urlParams;
    Method method;
    std::string requestUrl = DEFAULT_REQUEST_URL;

    /**
     * Method for POST request<br>
     * For now either {@link PostMethod#BODY}, {@link PostMethod#X_WWW_FORM_URL_ENCODED} or {@link PostMethod#FORM_DATA}<br>
     * Cannot be null<br>
     * Default is {@link PostMethod#X_WWW_FORM_URL_ENCODED}*/
    PostMethod postMethod = X_WWW_FORM_URL_ENCODED;

    /**
     * Content type for request<br>
     * Only used if PostMethod is {@link PostMethod#BODY}'*/
    std::string contentType = "text/plain";

    /**
      * Raw body if post method is {@link PostMethod#BODY}*/
    std::string requestBody;

    /**
      * Post parameter name for file upload<br>
      * Used only with {@link PostMethod#FORM_DATA}<br>*/
    std::string fileParamName;

    /**
      * Array of files to upload to server<br>
      * Used only with {@link PostMethod#FORM_DATA}<br>*/
    std::vector<UploadFile> files;
    int maxRetries = 3;
    int retiresLeft = maxRetries;
    bool allowEmptyValues;
    ResponseMessagePolicy *responseMessagePolicy = DEFAULT_RESPONSE_MESSAGE_POLICY;
    IRequestHandler *requestHandler;

public:
    /**
     * Create new request builder<br>
     * If no other option is specified default options are:
     * <pre>
     * * requestUrl - {@link #DEFAULT_REQUEST_ROOT}
     * * postMethod - {@link PostMethod#X_WWW_FORM_URL_ENCODED}
     * * contentType - "text/plain"
     * </pre>
     * @param method HTTP method for this request*/
    Request(Method);

    std::unordered_map <std::string, std::string> headers, postParams;

public:
    /**Set parameter name for file that is uploading to server.
     * @param fileParamName name of the file param
     * @return this obejct for method chaining*/
    Request *setFileParamName(std::string);

    /**
     * Set request body.<br>
     * This is only used with {@link PostMethod#BODY}
     * @param body body for this request
     * @return this object for method chaining*/

    Request *setRequestBody(std::string);

    /**
     * Set request content-type.<br>
     * This is only used with {@link PostMethod#BODY}
     * @param contentType content type for for request (application/json)
     * @return this object for method chaining*/
    Request *setContentType(std::string);

    /**
     * Set HTTP POST method to use
     * @param postMethod HTTP POST method
     * @return this object for method chaining*/
    Request *setPostMethod(PostMethod);

    /**
    * Set list of files for uploading
    * @param files list of files to upload
    * @see UploadFile
    * @return same object for method chaining*/
    Request *setFiles(std::vector<UploadFile>);

    /**
     * Set url root for this request. url on which all params will be added. for example<br>
     * <b>http://www.example.com/api.json/</b>users/register
     * Bolded is url that you should specify here
     * @param url url as described above
     * @return this object for method chaining*/
    Request *setRequestUrl(std::string);

    /**
     * Set maximum number of retries if request fails due to network or other errors
     * @param maxRetries max retries
     * @return this object for method chaining*/
    Request* setMaxRetires(int);

    /**
     * @return Max possible retries
     * */
    int getMaxRetries();

    /**
     * Add parameters for request
     * Encoding of parameter is taken care of
     * @param key parameter for this request. Passing null will not set action
     * @param value value of this parameter. Passing null or "" will not set parameter if mAllowEmptyValues is false
     * @param forceAddToUrl if true, params will be added to url regardless of the HTTP method
     * * @return same object for method chaining
     * */
    Request *addParam(std::string key, std::string value, bool forceAddToUrl = false);

    /**
     * Add parameters for request
     * Encoding of parameter is taken care of
     * @param key parameter for this request. Passing null will not set action
     * @param value value of this parameter
     * @param forceAddToUrl if true, params will be added to url regardless of the HTTP method
     * @return same object for method chaining
     * */
    Request *addParam(std::string key, int value, bool forceAddToUrl = false);

    /**
     * Add parameters for request
     * Encoding of parameter is taken care of
     * @param key parameter for this request. Passing null will not set action
     * @param value value of this parameter
     * @param forceAddToUrl if true, params will be added to url regardless of the HTTP method
     * @return same object for method chaining
     * */
    Request *addParam(std::string key, long value, bool forceAddToUrl = false);

    /**
     * Add parameters for request
     * Encoding of parameter is taken care of
     * @param key parameter for this request. Passing null will not set action
     * @param value value of this parameter
     * @param forceAddToUrl if true, params will be added to url regardless of the HTTP method
     * @return same object for method chaining
     * */
    Request *addParam(std::string key, float value, bool forceAddToUrl = false);

    /**
     * Add parameters for request
     * Encoding of parameter is taken care of
     * @param key parameter for this request. Passing null will not set action
     * @param value value of this parameter
     * @param forceAddToUrl if true, params will be added to url regardless of the HTTP method
     * @return same object for method chaining
     * */
    Request *addParam(std::string key, double value, bool forceAddToUrl = false);

    /**
     * Add parameters for request
     * Encoding of parameter is taken care of
     * @param key parameter for this request. Passing null will not set action
     * @param value value of this parameter
     * @param forceAddToUrl if true, params will be added to url regardless of the HTTP method
     * @return same object for method chaining
     * */
    Request *addParam(std::string key, bool value, bool forceAddToUrl = false);

    /**
     * Add url part
     * @param part url encoded param eg.: www.example.com/controller/action/{parame1}/{param2}
     * @return same object for method chaining
     * */
    Request *addUrlPart(std::string);

    /**
     * Add url part
     * @param part url encoded param eg.: www.example.com/controller/action/{parame1}/{param2}
     * @return same object for method chaining
     * */
    Request *addUrlPart(int);

    /**
     * Add url part
     * @param part url encoded param eg.: www.example.com/controller/action/{parame1}/{param2}
     * @return same object for method chaining
     * */
    Request *addUrlPart(long);

    /**
     * Add url part
     * @param part url encoded param eg.: www.example.com/controller/action/{parame1}/{param2}
     * @return same object for method chaining
     * */
    Request *addUrlPart(float);

    /**
     * Add url part
     * @param part url encoded param eg.: www.example.com/controller/action/{parame1}/{param2}
     * @return same object for method chaining
     * */
    Request *addUrlPart(double);

    /**
     * Add url part
     * @param part url encoded param eg.: www.example.com/controller/action/{parame1}/{param2}
     * @return same object for method chaining
     * */
    Request *addUrlPart(bool);

    /**
     * Add HTTP request header
     * @param header key for this heade (Content-Type)
     * @param value value for this header (application/json)
     * @return this for method chaining*/
    Request *addHeader(std::string key, std::string value);

    /**
     * @return generate url parameters string. eg. username=pedja&amp;password=123456
     * */
    std::string getUrlParams();

    /**
     * Set the ResponseMessagePolicy
     * @see com.tehnicomsolutions.http.ResponseHandler.ResponseMessagePolicy
     * @param responseMessagePolicy policy
     * @return this for call chain*/
    Request *setResponseMessagePolicy(ResponseMessagePolicy*);

    Method getMethod();

    PostMethod getPostMethod();

    std::string getContentType();

    std::string getRequestBody();

    std::vector<UploadFile>* getFiles();

    std::string getFileParamName();

    std::string getParam(std::string);

    bool setAllowEmptyValues();

    IRequestHandler* getRequestHandler();

    Request *setRequestHandler(IRequestHandler*);
};

class UploadFile
{
public:
    std::string url, fileName, mimeType;
};

#endif //TS_HTTP_CPP_REQUEST_H