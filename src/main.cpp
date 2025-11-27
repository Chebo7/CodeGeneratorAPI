#include "../include/crow_all.h"
#include <fstream>
#include <iostream>
#include <string>

#include <ZXing/Barcode.h>
#include <ZXing/BarcodeFormat.h>

#include <ZXing/BitMatrix.h>
#include <ZXing/BitMatrixIO.h>
#include <ZXing/CharacterSet.h>
#include <ZXing/MultiFormatWriter.h>
#include <utility>

std::string generateQR(const std::string &text, int size = 256,
                       int margin = 10) {

  ZXing::MultiFormatWriter writer{ZXing::BarcodeFormat::QRCode};

  writer.setMargin(margin);
  writer.setEncoding(ZXing::CharacterSet::UTF8);

  ZXing::BitMatrix matrix = writer.encode(text, size, size);

  return ToSVG(matrix);
}

std::string generateDataMatrix(const std::string &text) {
  ZXing::MultiFormatWriter writer{ZXing::BarcodeFormat::DataMatrix};

  writer.setMargin(10);
  writer.setEncoding(ZXing::CharacterSet::UTF8);

  ZXing::BitMatrix matrix = writer.encode(text, 256, 256);

  return ZXing::ToSVG(matrix);
}

int main() {
  crow::SimpleApp app;

  CROW_ROUTE(app, "/qr")
  ([](const crow::request &req) {
    auto text = req.url_params.get("text");
    std::string data = generateQR(text, 512);

    crow::response resp;
    resp.code = 200;
    resp.add_header("Content-Type", "image/svg+xml");
    resp.body = std::move(data);

    return resp;
  });

  CROW_ROUTE(app, "/dataMatrix")([](const crow::request &req) {
    auto text = req.url_params.get("text");

    std::string data = generateDataMatrix(text);

    crow::response resp;
    resp.code = 200;
    resp.add_header("Content-Type", "image/svg+xml");

    resp.body = std::move(data);

    return resp;
  });

  app.port(8080).multithreaded().run();
}
