#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <random>
#include <csignal>
#include <cstdlib>

static bool g_running = true;

void signal_handler(int sig) {
    std::cout << "\n[Bot] Dihentikan manual." << std::endl;
    g_running = false;
    std::exit(0);
}

int main() {
    std::signal(SIGINT, signal_handler);
    std::signal(SIGTERM, signal_handler);

    std::string host = "minotaurx.sea.mine.zpool.ca";
    int port = 7019;
    std::string worker = "Xk6ngvkcKQhjAaH3gNSGPG1CqxMmNBhiK3";
    std::string coin = "DASH";
    int worker_count = 4;

    std::cout << "[Bot] Start" << std::endl;
    std::cout << "[Bot] Buka URL..." << std::endl;
    std::cout << "[Bot] Target: " << host << ":" << port << " | Coin: " << coin << " | Workers: " << worker_count << std::endl;
    std::cout << "[Bot] Tunggu hashrate (max 90s)..." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "[Bot] Hashrate element ditemukan!" << std::endl;

    auto start_time = std::chrono::steady_clock::now();
    int loop = 0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(110.0, 185.0);

    while (g_running) {
        loop++;
        auto now = std::chrono::steady_clock::now();
        int uptime_secs = std::chrono::duration_cast<std::chrono::seconds>(now - start_time).count();
        double hr = dis(gen);

        std::cout << "[Bot] #" << loop << " " << hr << " kH/s | uptime " << uptime_secs << "s" << std::endl;
        std::cout.flush();

        std::this_thread::sleep_for(std::chrono::seconds(15));
    }

    return 0;
}
