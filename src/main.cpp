#include "../include/Barcode/BarcodeFactory.h"
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

  server.start();
}
