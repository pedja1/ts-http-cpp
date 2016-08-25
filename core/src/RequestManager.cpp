//
// Created by pedja on 23.8.16..
//

#include "RequestManager.h"

RequestManager* RequestManager::s_instance = NULL;

RequestManager* RequestManager::instance()
{
    if (!s_instance)
        throw std::invalid_argument("RequestManager cannot be null");
    return s_instance;
}

void RequestManager::initialize(RequestManager *requestManager)
{
    if (!requestManager)
        throw std::invalid_argument("RequestManager cannot be null");
    s_instance = requestManager;
}