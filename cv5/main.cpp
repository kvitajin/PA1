#include <iostream>
#include <bits/stdc++.h>

std::vector<std::tuple<double, int>> data;

void count(int nOfK){
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<size_t> mtp(0, data.size()-1);
    std::cout << mtp <<std::endl;

    std::vector<std::tuple<double, int>> means(nOfK)
    for (auto& cluster: means) {
        cluster=data[]
    }
}


void pickPoints(){
    int ammountOfRecords= data.size();

}


int main() {
    data.emplace_back(1.983, 59);
    data.emplace_back(4.333, 76);
    data.emplace_back( 5.1, 96);
    data.emplace_back(2.367, 63);
    data.emplace_back(1.8, 53);
    data.emplace_back(4, 77);
    data.emplace_back(1.667, 64);
    data.emplace_back(2.9, 63);
    data.emplace_back(3.833, 78);
    data.emplace_back(4.05, 81);
    data.emplace_back(3.417, 64);
    data.emplace_back(4.117, 79);
    data.emplace_back(2.133, 67);
    data.emplace_back(4.7, 88);
    data.emplace_back(2.417, 50);
    data.emplace_back(4.467, 74);
    data.emplace_back(1.783, 46);
    data.emplace_back(3.5, 87);
    data.emplace_back(2.4, 53);
    data.emplace_back(4.8, 76);

    count();




    return 0;
}
