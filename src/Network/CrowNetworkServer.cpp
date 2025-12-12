#include "../../include/Network/CrowNetworkServer.h"

void CrowNetworkServer::configure(int port) {
  port_ = port;

  CROW_ROUTE(app_, "/barcode")([](const crow::request &req) {
    auto type = req.url_params.get("type");
    auto text = req.url_params.get("text");
    auto margin = req.url_params.get("margin");
    auto size = req.url_params.get("size");
    std::unique_ptr<IBarcodeGenerator> generator = BarcodeFactory::create(type);

    std::string matrix;
    crow::response resp;
    try {
      matrix = generator->generate(text, std::stoi(margin), std::stoi(size));

      resp.code = 200;
      resp.add_header("Content-Type", "image/svg+xml");
      resp.body = std::move(matrix);
    } catch (const std::invalid_argument &ex) {
      std::cerr << ex.what() << std::endl;
      resp.code = 400;
      resp.add_header("Content-Type", "text/html");
      resp.body = std::move(matrix);
    }

    return resp;
  });
}

void CrowNetworkServer::start() { app_.port(port_).multithreaded().run(); }

crow::SimpleApp &CrowNetworkServer::getApp() { return app_; }