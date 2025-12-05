#pragma once

#include "crow_all.h"

class INetworkServer {
private:
  crow::SimpleApp app_;

public:
  INetworkServer() = default;
  virtual void start() = 0;
  virtual void configure() = 0;
};