#pragma once

#include "Code39Generator.h"
#include "Code93Generator.h"
#include "DataBarExpandedGenerator.h"
#include "DataBarGenerator.h"
#include "DataMatrixGenerator.h"
#include "IBarcodeGenerator.h"
#include "ItfGenerator.h"
#include "QrCodeGenerator.h"
#include "UpcAGenerator.h"
#include "UpcEGenerator.h"
#include <memory>
#include <string>
class BarcodeFactory {
public:
  static std::unique_ptr<IBarcodeGenerator> create(const std::string type);
};
