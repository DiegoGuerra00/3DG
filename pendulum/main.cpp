// main.cpp
#include "window.hpp"

int main(int argc, char **argv) {
  try {
    abcg::Application app(argc, argv);
    Window window;
    app.run(window);
  } catch (std::exception const &e) {
    fmt::print("Exception: {}\n", e.what());
    return -1;
  }
  return 0;
}