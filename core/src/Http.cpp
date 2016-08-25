//
// Created by pedja on 23.8.16..
//

#include "Http.h"

bool LOGGING = false;

Http* Http::s_instance = NULL;

Http* Http::instance()
{
    if (!s_instance)
        throw std::invalid_argument("You must initialize Http first. Call initialize()");
    return s_instance;
}

void Http::initialize(INetwork *network, IInternet *internet, IUI *ui, ITextManager *textManager)
{
    assertNetwork(network);
    assertInternet(internet);
    assertUi(ui);
    assertTm(textManager);
    s_instance = new Http(network, internet, ui, textManager);
}

Http::Http(INetwork *_network, IInternet *_internet, IUI *_ui, ITextManager *_textManager)
{
    network = _network;
    internet = _internet;
    ui = _ui;
    textManager = _textManager;
}
