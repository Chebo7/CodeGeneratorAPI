#pragma once

class INetworkServer {
protected:
  int port_ = 0;

public:
  INetworkServer() = default;
  virtual void start() = 0;
  virtual void configure(int port) = 0;
};