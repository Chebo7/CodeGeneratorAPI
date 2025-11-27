#pragma once
#include "IBarcodeGenerator.h"
#include <ZXing/Barcode.h>
#include <ZXing/BarcodeFormat.h>
#include <ZXing/MultiFormatWriter.h>
#include <memory>
#include <string>

class QrGenerator : public virtual IBarcodeGenerator {
private:
  ZXing::MultiFormatWriter writer{ZXing::BarcodeFormat::QRCode};

public:
  std::string generate(const std::string &text, int margin, int size);
};