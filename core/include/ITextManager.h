//
// Created by pedja on 23.8.16..
//

#ifndef TS_HTTP_CPP_ITEXTMANAGER_H
#define TS_HTTP_CPP_ITEXTMANAGER_H


#include <string>

class ITextManager
{
public:
    virtual ~ITextManager(){};
    virtual std::string getText(std::string key) const = 0;
};


#endif //TS_HTTP_CPP_ITEXTMANAGER_H
