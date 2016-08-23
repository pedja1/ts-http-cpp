//
// Created by pedja on 23.8.16..
//

#ifndef TS_HTTP_CPP_HTTP_H
#define TS_HTTP_CPP_HTTP_H

#include <stdexcept>
#include "IInternet.h"
#include "INetwork.h"
#include "IUI.h"
#include "ITextManager.h"

#define LOG_TAG "ts-http"

extern bool LOGGING;

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
    static Http *instance()
    {
        if (!s_instance)
            throw std::invalid_argument("You must initialize Http first. Call initialize()");
        return s_instance;
    }

    static void initialize(INetwork *network, IInternet *internet, IUI *ui, ITextManager *textManager)
    {
        assertNetwork(network);
        assertInternet(internet);
        assertUi(ui);
        assertTm(textManager);
        s_instance = new Http(network, internet, ui, textManager);
    }

public:
    const INetwork *network;
    const IInternet *internet;
    const IUI *ui;
    const ITextManager *textManager;

    Http(INetwork *network, IInternet *internet, IUI *ui, ITextManager *textManager);
};


#endif //TS_HTTP_CPP_HTTP_H
