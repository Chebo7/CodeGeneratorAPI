#include "../include/BarcodeFactory.h"
#include <memory>

std::unique_ptr<IBarcodeGenerator>
BarcodeFactory::create(const std::string type) {
  if (type == "QRCode") {
    return std::make_unique<QRCodeGenerator>();
  } else if (type == "DataMatrix") {
    return std::make_unique<DataMatrixGenerator>();
  } else if (type == "UPCA") {
    return std::make_unique<UpcAGenerator>();
  } else if (type == "ITF") {
    return std::make_unique<ItfGenerator>();
  } else if (type == "DataBar") {
    return std::make_unique<DataBarGenerator>();
  } else if (type == "DataBarExpanded") {
    return std::make_unique<DataBarExpandedGenerator>();
  } else if (type == "Code39") {
    return std::make_unique<Code39Generator>();
  } else if (type == "Code93") {
    return std::make_unique<Code93Generator>();
  }

  return std::make_unique<QRCodeGenerator>();
}