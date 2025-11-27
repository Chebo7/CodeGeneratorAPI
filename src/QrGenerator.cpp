#include "../include/QrGenerator.h"
#include <ZXing/Barcode.h>
#include <ZXing/BarcodeFormat.h>
#include <ZXing/BitMatrix.h>
#include <ZXing/BitMatrixIO.h>
#include <ZXing/CharacterSet.h>
#include <ZXing/Matrix.h>
#include <ZXing/MultiFormatWriter.h>
#include <stdexcept>
#include <string>
#include <utility>

std::string QrGenerator::generate(const std::string &text, int margin,
                                  int size) {
  writer.setMargin(margin);
  writer.setEncoding(ZXing::CharacterSet::UTF8);
  ZXing::BitMatrix matrix = writer.encode(text, size, size);

  return ZXing::ToSVG(matrix);
}