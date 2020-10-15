#include <iostream>
#include <random>
#include <thread>
#include <future>
#include <mutex>
std::mutex mtx;


#define THREADS 10

std::random_device rd;
int circle = 0, square = 0;

double monte(int interval){
    double randX, randY, dist, pi;
    for (int i = 0; i < pow(interval, 2); ++i) {
        randX= double(rd() % (interval)) / interval;
        randY= double(rd() % (interval + 1)) / interval;
        dist=pow(randX, 2)+pow(randY, 2);
        if (dist<=1){
            ++circle;
        }
        ++square;
        pi= double (4*circle)/square;
    }
    return pi;
}

void partialMonte (int interval){
    double randX, randY, dist;
    std::vector<int> tmp;
    for (int i = 0; i < pow(interval, 2)/THREADS; ++i) {
        randX= double(rd() % (interval + 1)) / interval;
        randY= double(rd() % (interval + 1)) / interval;
        dist=pow(randX, 2)+pow(randY, 2);
        mtx.lock();
        if (dist<=1){
            ++circle;
        }
        ++square;
        mtx.unlock();

    }
}

double paralelMonte(int interval){
    double pi;
    std::vector<std::thread> threads;
    for (int i = 0; i < THREADS; ++i) {
        threads.push_back(std::thread(partialMonte, interval));

    }
    for (auto & thread : threads) {
        if (thread.joinable()){
            thread.join();
        }
    }
    pi= double (4*circle)/square;

    return pi;
}

int main() {
    std::cout <<paralelMonte(5000);
    return 0;
}
