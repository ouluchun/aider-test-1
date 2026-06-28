#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cassert>

std::string run_command(const std::string& cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe) throw std::runtime_error("popen failed");
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    if (!result.empty() && (result.back() == '\n' || result.back() == '\r')) {
        result.pop_back();
    }
    return result;
}

int main() {
    // Test with argument
    std::string cmd = "./hello_world my_test";
    std::string output = run_command(cmd);
    assert(output == "Hello, world!");

    // Test without argument
    cmd = "./hello_world";
    output = run_command(cmd);
    assert(output == "Hello, world!");

    return 0;
}
