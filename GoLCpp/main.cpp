#include <iostream>
#include <vector>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <latch>

using namespace std;
std::mutex mut;

void print(std::vector<std::vector<int>> &arr){
    for (int i = 0; i < arr.size(); ++i) {
        std::cout<< "|";
        for (int j = 0; j < arr[0].size(); ++j) {
            if (arr[i][j]==1){
                std::cout<<" ■ ";
            }
            else{
                std::cout<<"   ";       //□  ⬜
            }
        }
        std::cout<< "|" <<std::endl;
    }

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
void lineInThread(std::vector<std::vector<int>> &arr, std::latch &latch, int line){
    int counter = 0;
    std::vector<int> tmpLine;
    tmpLine.resize(arr.size());

    for(int cell = 0; cell< arr[line].size(); ++cell){
        surroundings(line, cell, arr, counter);
        if (arr[line][cell] && counter<2 ){                                   //otocenae znamenko >
            tmpLine[cell]= 0;
        }
        else if (arr[line][cell] && (counter == 2 || counter == 3 )){
            tmpLine[cell]= 1;
        }
        else if (arr[line][cell] && counter >3){
        tmpLine[cell]= 0;
        }
        else if (!arr[line][cell] && counter==3 ){
            tmpLine[cell]= 1;
        }

    }
    latch.count_down();
    mut.lock();
    std::copy(begin(tmpLine), end(tmpLine), std::begin(arr[line]));
//    arr[line].emplace(tmpLine.cbegin(), tmpLine.cend());
    mut.unlock();

}
void hello(int i){
    std::cout<<"hello pandemic world "<<i<<std::endl;
}


void paralelRound(std::vector<std::vector<int>> &arr){
    std::vector<std::vector<int>> tmp;
    std::vector<std::thread> threads;
    std::vector<int> row;
    std::latch latch(arr.size());
    tmp.resize(arr.size());
    for (int i = 0; i < arr.size(); ++i) {
        tmp[i].resize(arr[i].size());
    }

    for (int th = 0; th < arr.size(); ++th){
        threads.emplace_back(std::thread(lineInThread,std::ref(arr), std::ref(latch), th));
    }

    for (std::thread & th : threads){
        if (th.joinable())
            th.join();
    }
}

void round(std::vector<std::vector<int>> &arr){
    std::vector<std::vector<int>> tmp;
    tmp.resize(arr.size());
    for (int i = 0; i < arr.size(); ++i) {
        tmp[i].resize(arr[i].size());
    }

    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr[i].size(); ++j) {
            int counter = 0;
	   surroundings(i, j, arr, counter);
	  //	std::cout<< counter<<std::endl;
            if (arr[i][j] && counter<2 ){                                   //otocenae znamenko >
                tmp[i][j]= 0;
            }
            else if (arr[i][j] && (counter == 2 || counter == 3 )){
                tmp[i][j]= 1;
            }
            else if (arr[i][j] && counter >3){
                tmp[i][j]= 0;
            }
            else if (!arr[i][j] && counter==3 ){
                tmp[i][j]= 1;
            }

//            else std::cout << "kurwa (with flowers) "<<counter << " "<<tmp[i][j] <<std::endl;
        }
    }
    arr=tmp;
}


int main() {
    std::vector<std::vector<int>> playingBoard= {{0, 0, 0, 0, 0, 0},
                                                 {0, 0, 0, 1, 0, 0},
                                                 {0, 1, 0, 0, 1, 0},
                                                 {0, 1, 0, 0, 1, 0},
                                                 {0, 0, 1, 0, 0, 0},
                                                 {0, 0, 0, 0, 0, 0}};
//    std::vector<std::vector<int>> playingBoard= {{1, 1},
//                                                 {1, 0}};

    print(playingBoard);
   // system("clear");
    paralelRound(playingBoard);
    print(playingBoard);


    return 0;
}
