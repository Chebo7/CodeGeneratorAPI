#include "../../include/Network/BarcodeHandler.h"

#include <memory>
#include <string>
#include <utility>

void BarcodeHandler::start() {
  std::cout << "TESTREDE" << std::endl;
  CROW_ROUTE(app_, "/barcode")([](const crow::request &req) {
    auto type = req.url_params.get("type");
    auto margin = req.url_params.get("margin");
    auto size = req.url_params.get("size");
    auto text = req.url_params.get("text");

    std::unique_ptr<IBarcodeGenerator> generator = BarcodeFactory::create(type);

    std::string matrix;
    crow::response resp;

    matrix = generator->generate(text, std::stoi(margin), std::stoi(size));

    resp.code = 200;
    resp.add_header("Content-Type", "image/svg+xml");
    resp.body = std::move(matrix);

    return resp;
  });
}