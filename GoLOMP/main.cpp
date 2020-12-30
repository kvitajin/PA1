#include <iostream>
#include <vector>
#include <cstdlib>
#include <omp.h>
#include <thread>

using namespace std::chrono_literals;

void print(std::vector<std::vector<int>> &arr){
    for (int col = 0; col < arr[0].size(); ++col) {
        std::cout << "---";
    }
    std::cout << "--" << std::endl;

    for (int i = 0; i < arr.size(); ++i) {
        std::cout<< "|";
        for (int j = 0; j < arr[0].size(); ++j) {
            if (arr[i][j]==1){
//                std::cout<<" "<<arr[i][j]<<" ";//<<" ■ ";
                std::cout<<" ■ ";
            }
            else{
//                std::cout<<" "<<arr[i][j]<<" ";//<<"   ";       //□  ⬜
                std::cout<<"   ";

            }
        }
        std::cout<< "|" <<std::endl;
    }
    for (int col = 0; col < arr[0].size(); ++col) {
        std::cout << "---";
    }
    std::cout << "--" << std::endl;

}

void surroundings(int &i, int &j, std::vector<std::vector<int>> &arr, int &counter) {
    for (int k = i - 1; k < i + 2; ++k) {
        for (int l = j - 1; l < j + 2; ++l) {
            if (k >= 0 &&
                l >= 0 &&
                k < arr.size() &&
                l < arr[0].size() &&
                (!(k == i && l == j))) { //meze
                if (arr[k][l] == 1) {    //sousedi
                    ++counter;
                }
            }
        }
    }

}
void lineInThread(std::vector<std::vector<int>> &arr, std::vector<int> &result, int line) {
    int counter = 0;
    std::vector<int> tmpLine;

    for (int cell = 0; cell < arr[line].size(); ++cell) {
        counter = 0;
        surroundings(line, cell, arr, counter);
        if (arr[line][cell] && counter < 2)                         tmpLine.push_back(0);
        else if (arr[line][cell] && (counter == 2 || counter == 3)) tmpLine.push_back(1);
        else if (arr[line][cell] && counter > 3)                    tmpLine.push_back(0);
        else if (!arr[line][cell] && counter == 3)                  tmpLine.push_back(1);
        else                                                        tmpLine.push_back(0);
    }

    result = tmpLine;
}

void parallelRound(std::vector<std::vector<int>> &arr) {
    std::vector<std::vector<int>> tmp;
    std::vector<int> row;

    tmp.resize(arr.size());

#pragma omp parallel for
    for (int lineId = 0; lineId < arr.size(); ++lineId) {
        lineInThread(arr, tmp[lineId], lineId);
    }

    arr = tmp;
}

int main() {
//    std::vector<std::vector<int>> playingBoard= {{0, 0, 0, 0, 0, 0},
//                                                 {0, 0, 0, 1, 0, 0},
//                                                 {0, 1, 0, 0, 1, 0},
//                                                 {0, 1, 0, 0, 1, 0},
//                                                 {0, 0, 1, 0, 0, 0},
//                                                 {0, 0, 0, 0, 0, 0}};
//    std::vector<std::vector<int>> playingBoard= {{1, 1},
//                                                 {1, 0}};
    std::vector<std::vector<int>> playingBoard= {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    print(playingBoard);
    while (true){
        parallelRound(playingBoard);
        #if defined(_WIN_32)
                system("cls")
        #endif
        #if defined(linux)
                std::cout << "\033[2J\033[1;1H";
        #endif
        print(playingBoard);
        std::this_thread::sleep_for(100ms);
    }
    parallelRound(playingBoard);

    print(playingBoard);


    return 0;
}
