#include "../../include/Network/CrowNetworkServer.h"

void CrowNetworkServer::configure(int port) { port_ = port; }

void CrowNetworkServer::start() { app_.port(port_).multithreaded().run(); }

crow::SimpleApp &CrowNetworkServer::getApp() { return app_; }