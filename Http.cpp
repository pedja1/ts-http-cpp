//
// Created by pedja on 23.8.16..
//

#include "Http.h"

bool LOGGING = false;

Http::Http(INetwork *_network, IInternet *_internet, IUI *_ui, ITextManager *_textManager)
{
    network = _network;
    internet = _internet;
    ui = _ui;
    textManager = _textManager;
}
