#include "../include/BarcodeFactory.h"

#include "../include/crow_all.h"

#include <memory>
#include <string>

#include <ZXing/BarcodeFormat.h>

#include <ZXing/BitMatrix.h>
#include <ZXing/BitMatrixIO.h>
#include <ZXing/CharacterSet.h>
#include <ZXing/MultiFormatWriter.h>
#include <utility>

int main() {
  crow::SimpleApp app;

  CROW_ROUTE(app, "/barcode")([](const crow::request &req) {
    auto type = req.url_params.get("type");
    auto text = req.url_params.get("text");
    auto margin = req.url_params.get("margin");
    auto size = req.url_params.get("size");
    std::unique_ptr<IBarcodeGenerator> generator = BarcodeFactory::create(type);
    std::string matrix =
        generator->generate(text, std::stoi(margin), std::stoi(size));

    crow::response resp;
    resp.code = 200;
    resp.add_header("Content-Type", "image/svg+xml");
    resp.body = std::move(matrix);

    return resp;
  });

  app.port(80).multithreaded().run();
}
