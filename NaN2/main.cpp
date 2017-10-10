#include <iostream>
#include <thread>
#include <ratio>
#include <vector>
#include <ctime>
#include <chrono>

#include "network/proud_server.h"
#include "world/world.h"

#include "logger/logger.h"

using namespace nan2;

int main() {
#ifdef _DEBUG
  L_DEBUG << "DEBUG Mode";
#endif

  // Initiate ProudServer
  ProudServer* server = ProudServer::instance();
  World* world = World::instance();
  server->Initialize();

  std::chrono::high_resolution_clock::time_point last_system_time(std::chrono::high_resolution_clock::now());

  while (1) {
    std::chrono::high_resolution_clock::time_point cur_system_time(std::chrono::high_resolution_clock::now());
    std::chrono::duration<double, std::milli> time_span = cur_system_time - last_system_time;
    server->Process();
    world->Update(time_span.count());
    std::chrono::high_resolution_clock::time_point after_cur_system_time(std::chrono::high_resolution_clock::now());
    std::chrono::duration<double, std::milli> aft_time_span = after_cur_system_time - cur_system_time;
    int dt = aft_time_span.count();

    last_system_time = cur_system_time;

    dt = (16 - dt > 0 ? 16 - dt : 0);
    this_thread::sleep_for(std::chrono::milliseconds(dt));
  }
}