#include <functional>
#include <iostream>
#include <csignal>
#include <string>
#include <thread>
#include <chrono>

namespace {
std::function<void(int)> shutdown_handler;
void signal_handler(int signal) { shutdown_handler(signal); }
} // namespace

int main(int argc, char *argv[]) {
  std::signal(SIGINT, signal_handler);
  //MyTCPServer server;
  std::string hhh{"hello world!"};
  shutdown_handler = [&](int signal) {
    std::cout << hhh << std::endl << "Server shutdown...\n";
    //server.shutdown();
  };
  //server.do_work_for_ever();
  std::this_thread::sleep_for(std::chrono::seconds(10));
}
