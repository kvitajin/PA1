#include <iostream>
#include <vector>
#include <cstdlib>
#include <omp.h>

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

void round(std::vector<std::vector<int>> &arr){
    std::vector<std::vector<int>> tmp;
    tmp.resize(arr.size());
    for (int i = 0; i < arr.size(); ++i) {
        tmp[i].resize(arr[i].size());
    }
#pragma omp parallel default(shared)
    {
#pragma omp for schedule(static) nowait
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr[i].size(); ++j) {
            int counter = 0;
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
            if (arr[i][j] && counter < 2) {                                   //otocenae znamenko >
                tmp[i][j] = 0;
            } else if (arr[i][j] && (counter == 2 || counter == 3)) {
                tmp[i][j] = 1;
            } else if (arr[i][j] && counter > 3) {
                tmp[i][j] = 0;
            } else if (!arr[i][j] && counter == 3) {
                tmp[i][j] = 1;
            }
            else{
                tmp[i][j] = 0;
            }

        }
    }
    arr = tmp;
    }
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
    round(playingBoard);
    round(playingBoard);
    round(playingBoard);
//    for (auto & i : playingBoard) {
//        for (int j : i) {
//            std::cout<<" "<<j<<" ";
//        }
//        std::cout<<std::endl;;
//    }
//    std::cout<<std::endl;
    print(playingBoard);


    return 0;
}
