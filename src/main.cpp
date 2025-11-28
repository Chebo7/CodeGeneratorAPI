#include "../include/DataMatrixGenerator.h"
#include "../include/QrGenerator.h"
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

int main() {
  crow::SimpleApp app;
  QrGenerator qr;
  DataMatrixGenerator dM;

  CROW_ROUTE(app, "/qr")([&qr](const crow::request &req) {
    auto text = req.url_params.get("text");
    std::string data = qr.generate(text, 10, 128);

    crow::response resp;
    resp.code = 200;
    resp.add_header("Content-Type", "image/svg+xml");
    resp.body = std::move(data);

    return resp;
  });

  CROW_ROUTE(app, "/DataMatrix")([&dM](const crow::request &req) {
    auto text = req.url_params.get("text");

    std::string data = dM.generate(text, 10, 128);

    crow::response resp;
    resp.code = 200;
    resp.add_header("Content-Type", "image/svg+xml");

    resp.body = std::move(data);

    return resp;
  });

  app.port(8080).multithreaded().run();
}
