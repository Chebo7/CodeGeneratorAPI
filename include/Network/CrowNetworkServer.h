#pragma once

#include "../Barcode/BarcodeFactory.h"
#include "../Barcode/IBarcodeGenerator.h"
#include "INetworkServer.h"
#include "crow_all.h"

class CrowNetworkServer : public virtual INetworkServer {
private:
  crow::SimpleApp app_;

public:
  void start() override;
  void configure(int port) override;
  crow::SimpleApp &getApp();
};