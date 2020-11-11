#include <iostream>
#include <vector>


void print(std::vector<std::vector<int>> &arr){
    for (int i = 0; i < arr.size(); ++i) {
        std::cout<< "|";
        for (int j = 0; j < arr[0].size(); ++j) {
            if (arr[i][j]==1){
                std::cout<<" ■ ";
            }
            else{
                std::cout<<"   ";
            }
        }
        std::cout<< "|" <<std::endl;
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
            for (int k = i - 1; k < i + 2; ++k) {
                for (int l = j - 1; l < j + 2; ++l) {
//                    std::cout <<i<< " "<<j<< " "<<k<< " "<<l<< " " <<counter<< " "<< std::endl;
                    if (k >= 0 &&
                        l >= 0 &&
                        k < arr.size() &&
                        l < arr[0].size() &&
                        (k != i && l != j)) {                    //meze
//                            std::cout << "tu1\n";
//                        for (int m = 0; m < arr.size(); ++m) {
//                            for (int n = 0; n < arr[0].size(); ++n) {
//                                std::cout<< arr[m][n] << " ";
//                            }
//                            std::cout<<std::endl;
//                        }
//                        std::cout << "tu2\n";

                        if (arr[k][l] == 1) {              //sousedi
                                ++counter;
//                            std::cout << "tu2.5\n";
                        }
//                        std::cout << "tu2.7\n";

                    }
//                    std::cout << "tu2.8\n";

                }
//                std::cout << "tu2.9\n";
            }
            tmp[0].insert(tmp[0].begin(),1);

//            print(tmp);

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
//    print(tmp);
}


int main() {
    std::vector<std::vector<int>> playingBoard= {{0, 1, 0, 0, 0, 0},
                                                 {0, 0, 0, 1, 0, 0},
                                                 {0, 1, 0, 0, 1, 0},
                                                 {0, 1, 0, 0, 1, 0},
                                                 {0, 0, 1, 0, 0, 0},
                                                 {0, 0, 0, 0, 0, 0}};
    print(playingBoard);
    round(playingBoard);
    print(playingBoard);


    return 0;
}
