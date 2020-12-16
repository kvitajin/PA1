#include <iostream>
#include <vector>
#include <cstdlib>
#include <thread>
#include <mutex>

std::mutex mut;

void print(std::vector<std::vector<int>> &arr){
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
void lineInThread(std::vector<std::vector<int>> &arr, int line){
    int counter = 0;
    std::vector<int> tmpLine;
//    tmpLine.resize(arr.size());

    for(int cell = 0; cell< arr[line].size(); ++cell){
        counter=0;
        surroundings(line, cell, arr, counter);
//        std::cout<< line<<cell<<counter<<std::endl;
//        tmpLine.push_back(counter);
        if (arr[line][cell] && counter<2 )                          tmpLine.push_back(0);
        else if (arr[line][cell] && (counter == 2 || counter == 3 ))tmpLine.push_back(1);
        else if (arr[line][cell] && counter >3)                     tmpLine.push_back(0);
        else if (!arr[line][cell] && counter==3 )                   tmpLine.push_back(1);
        else                                                        tmpLine.push_back(0);
    }
    for (int i : tmpLine) {
        std::cout<<" "<< i<<" ";
    }
    std::cout<<std::endl;
    //    mut.lock();
    //    arr[line]=tmpLine;
    //    mut.unlock();
//    std::cout<< line<<tmpLine[0]<<tmpLine[2]<<std::endl;

}



void paralelRound(std::vector<std::vector<int>> &arr){
    std::vector<std::vector<int>> tmp;
    std::vector<std::thread> threads;
    std::vector<int> row;
    tmp.resize(arr.size());
    for (int i = 0; i < arr.size(); ++i) {
        tmp[i].resize(arr[i].size());
    }

    threads.reserve(arr.size());
for (int th = 0; th < arr.size(); ++th){
        threads.emplace_back(std::thread(lineInThread,std::ref(arr), th));
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
//	  	std::cout<< counter<<std::endl;
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
    std::cout<<std::endl;
    print(playingBoard);


    return 0;
}
