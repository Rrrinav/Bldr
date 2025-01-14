#define B_LDR_IMPLEMENTATION
#include <cstdlib>  // For std::exit

#include "./b_ldr.hpp"

int main(int argc, char *argv[])
{
  // Check if the executable needs to be rebuilt and restart if necessary
  BLD_REBUILD_YOURSELF_ONCHANGE();

  b_ldr::Command cmd = {};
  b_ldr::print_metadata();

  std::cout << "Hello, World!" << std::endl;

  //cmd.parts = {"g++", "hello.cpp", "-o", "hello"};
  //if (b_ldr::execute(cmd) <= 0)
  //  return EXIT_FAILURE;

  b_ldr::execute_shell("curl -s 'wttr.in/jammu?format=4'");

  std::string output;
  if (b_ldr::read_process_output({"pkg-config", "--libs", "raylib"}, output))
    std::cout << output << std::endl;

  if (b_ldr::read_shell_output("cal", output))
    std::cout << output << std::endl;

  return 0;
}
