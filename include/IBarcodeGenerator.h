#pragma once
#include <string>

class IBarcodeGenerator {
private:
public:
  IBarcodeGenerator() = default;
  virtual std::string generate(const std::string &text, int margin,
                               int size) = 0;
};