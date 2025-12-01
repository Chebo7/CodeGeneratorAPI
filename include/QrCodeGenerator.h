#pragma once
#include "IBarcodeGenerator.h"
#include <ZXing/Barcode.h>
#include <ZXing/BarcodeFormat.h>
#include <ZXing/BitMatrix.h>
#include <ZXing/BitMatrixIO.h>
#include <ZXing/CharacterSet.h>
#include <ZXing/Matrix.h>
#include <ZXing/MultiFormatWriter.h>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>

class QrCodeGenerator : public virtual IBarcodeGenerator {
private:
  ZXing::MultiFormatWriter writer{ZXing::BarcodeFormat::QRCode};

public:
  std::string generate(const std::string &text, int margin, int size);
};