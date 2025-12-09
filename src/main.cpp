#include "../include/Barcode/BarcodeFactory.h"
#include "../include/Network/BarcodeHandler.h"
#include "../include/Network/CrowNetworkServer.h"
#include "../include/Network/crow_all.h"
#include <ZXing/BarcodeFormat.h>
#include <ZXing/BitMatrix.h>
#include <ZXing/BitMatrixIO.h>
#include <ZXing/CharacterSet.h>
#include <ZXing/MultiFormatWriter.h>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>

int main() {
  CrowNetworkServer server;
  server.configure(50329);

  BarcodeHandler barcodeHandler(server.getApp());
  barcodeHandler.start();

  // CROW_ROUTE(server.getApp(), "/barcode")([](const crow::request &req) {
  //   auto type = req.url_params.get("type");
  //   auto text = req.url_params.get("text");
  //   auto margin = req.url_params.get("margin");
  //   auto size = req.url_params.get("size");
  //   std::unique_ptr<IBarcodeGenerator> generator =
  //   BarcodeFactory::create(type);

  //   std::string matrix;
  //   crow::response resp;
  //   try {
  //     matrix = generator->generate(text, std::stoi(margin), std::stoi(size));

  //     resp.code = 200;
  //     resp.add_header("Content-Type", "image/svg+xml");
  //     resp.body = std::move(matrix);
  //   } catch (const std::invalid_argument &ex) {
  //     std::cerr << ex.what() << std::endl;
  //     resp.code = 400;
  //     resp.add_header("Content-Type", "text/html");
  //     resp.body = std::move(matrix);
  //   }

  //   return resp;
  // });
  server.start();
}
