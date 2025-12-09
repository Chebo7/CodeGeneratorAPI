#pragma once
#include "../../include/Barcode/BarcodeFactory.h"
#include "../../include/Barcode/IBarcodeGenerator.h"
#include "IRouteHandler.h"
#include "crow_all.h"

class BarcodeHandler : public virtual IRouteHandler {

public:
  BarcodeHandler(crow::SimpleApp &app) : IRouteHandler(app) {};
  void start() override;
};