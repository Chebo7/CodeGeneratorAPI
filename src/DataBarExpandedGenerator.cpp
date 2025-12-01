#include "../include/DataBarExpandedGenerator.h"

std::string DataBarExpandedGenerator::generate(const std::string &text,
                                               int margin, int size) {
  writer.setMargin(margin);
  writer.setEncoding(ZXing::CharacterSet::UTF8);
  ZXing::BitMatrix matrix = writer.encode(text, size, size);

  return ZXing::ToSVG(matrix);
}