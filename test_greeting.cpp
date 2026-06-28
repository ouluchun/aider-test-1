#include <cstdio>
#include <cstdlib>
#include <memory>
#include <string>

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        return 1;
    }
    std::string arg = argv[1];
    std::string cmd = "python3 show_greeting.py " + arg;
    std::string output = exec(cmd.c_str());
    while (!output.empty() && (output.back() == '\n' || output.back() == '\r')) {
        output.pop_back();
    }
    std::string expected = "Hey " + arg;
    if (output != expected) {
        return 2;
    }
    return 0;
}
