//
// Created by pedja on 23.8.16..
//

#ifndef TS_HTTP_CPP_HTTP_H
#define TS_HTTP_CPP_HTTP_H

#include <stdexcept>

#define LOG_TAG "ts-http"

extern bool LOGGING;

class IInternet;
class INetwork;
class IUI;
class ITextManager;

class Http
{
    static Http *s_instance;

    static void assertInternet(IInternet *internet)
    {
        if (!internet)
            throw new std::invalid_argument("IInternet cannot be null");
    }

    static void assertNetwork(INetwork *network)
    {
        if (!network)
            throw new std::invalid_argument("INetwork cannot be null");
    }

    static void assertUi(IUI *ui)
    {
        if (!ui)
            throw new std::invalid_argument("IUI cannot be null");
    }

    static void assertTm(ITextManager *tm)
    {
        if (!tm)
            throw new std::invalid_argument("TextManager cannot be null");
    }

public:
    static Http *instance();
    static void initialize(INetwork *network, IInternet *internet, IUI *ui, ITextManager *textManager);

public:
    const INetwork *network;
    const IInternet *internet;
    const IUI *ui;
    const ITextManager *textManager;

    Http(INetwork *network, IInternet *internet, IUI *ui, ITextManager *textManager);
};


#endif //TS_HTTP_CPP_HTTP_H
