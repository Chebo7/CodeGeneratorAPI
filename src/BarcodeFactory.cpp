#include "../include/BarcodeFactory.h"
#include <memory>

std::unique_ptr<IBarcodeGenerator>
BarcodeFactory::create(const std::string type) {
  if (type == "Qr") {
    return std::make_unique<QrGenerator>();
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
  }

  return std::make_unique<QrGenerator>();
}