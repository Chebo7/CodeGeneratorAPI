#pragma once
#include "crow_all.h"

class IRouteHandler {
protected:
  crow::SimpleApp app_;

public:
  IRouteHandler(crow::SimpleApp &app) : app_(&app) {};
  virtual void start() = 0;
};