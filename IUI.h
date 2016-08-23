//
// Created by pedja on 23.8.16..
//


#ifndef TS_HTTP_CPP_UI_H
#define TS_HTTP_CPP_UI_H

#include <string>
class IUI
{
public:
    virtual ~IUI() {}

    virtual void showToast(std::string message) const = 0;
    virtual void showToast(std::string message, unsigned long duration) const = 0;
};
#endif //TS_HTTP_CPP_UI_H