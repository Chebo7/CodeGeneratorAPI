#pragma once

#include "DataBarGenerator.h"
#include "DataMatrixGenerator.h"
#include "IBarcodeGenerator.h"
#include "ItfGenerator.h"
#include "QrGenerator.h"
#include "UpcAGenerator.h"
#include <memory>
#include <string>
class BarcodeFactory {
public:
  static std::unique_ptr<IBarcodeGenerator> create(const std::string type);
};
