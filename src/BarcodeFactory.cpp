#include "../include/BarcodeFactory.h"
#include <memory>

std::unique_ptr<IBarcodeGenerator>
BarcodeFactory::create(const std::string type) {
  if (type == "QrCode") {
    return std::make_unique<QrCodeGenerator>();
  } else if (type == "DataMatrix") {
    return std::make_unique<DataMatrixGenerator>();
  } else if (type == "UpcA") {
    return std::make_unique<UpcAGenerator>();
  } else if (type == "UpcE") {
    return std::make_unique<UpcEGenerator>();
  } else if (type == "Itf") {
    return std::make_unique<ItfGenerator>();
  } else if (type == "Code39") {
    return std::make_unique<Code39Generator>();
  } else if (type == "Code93") {
    return std::make_unique<Code93Generator>();
  } else if (type == "Code128") {
    return std::make_unique<Code128Generator>();
  } else if (type == "Codabar") {
    return std::make_unique<CodabarGenerator>();
  } else if (type == "Aztec") {
    return std::make_unique<AztecGenerator>();
  } else if (type == "Pdf417") {
    return std::make_unique<Pdf417Generator>();
  } else if (type == "Ean13") {
    return std::make_unique<Ean13Generator>();
  } else if (type == "Ean8") {
    return std::make_unique<Ean8Generator>();
  }

  return std::make_unique<QrCodeGenerator>();
}