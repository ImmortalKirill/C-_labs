#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
const int size = 8;
const int accuracy = 1000;
bool neighbour_check(int (&arr)[size][size], int x, int y){
    /* checks if a dislocation moves or not
     * returns False if a dislocation has neighbours */
    return ((arr[x-1][y]+arr[x+1][y]+arr[x][y-1]+arr[x][y+1])%9 == 0) ;
}
void change(int &x, int &y){
    if (x==9){
        y = 9;
    }
    else x = 9;
}
void move(int (&arr)[size][size], int x, int y, int choice){
    /* moves a dislocation(x, y) according to the choice*/
    if (choice == 0){change(arr[x-1][y], arr[x][y]); }
    else if (choice == 1){change(arr[x+1][y], arr[x][y]); }
    else if (choice == 2){change(arr[x][y-1], arr[x][y]); }
    else {change(arr[x][y+1], arr[x][y]);}
}
void rearrange(int (&arr)[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++){
            if ((i != 0) and (i != size-1) and (j!= 0) and (j != size-1)) {
                if (arr[i][j] != 2) { arr[i][j] = arr[i][j] / 9; }
                else { arr[i][j] = 1; }
            } else if(arr[i][j] == 9){arr[i][j] = 1;}
        }
    }
}
void print(int arr[size][size]){
    for(int i = 0;i < size;i++){
        for(int j = 0;j < size;j++){
            std::cout << arr[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}
int main_loop(int (&crystal)[size][size]){
    std::mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count()); // for windows
    std::uniform_int_distribution<int> dist(0, 3);
    int changes = -1, steps = 0;
    while(changes != 0) {
        steps++;
        changes = 0;
        for(int i = 1;i < size-1;i++){
            for(int j = 1;j < size-1;j++){
                if(neighbour_check(crystal, i, j) and crystal[i][j] == 1){
                    int choice = dist(rng);
                    move(crystal, i, j, choice);
                    changes++;
                }
                else if (crystal[i][j] == 1){crystal[i][j] = 2;}
            }
        }
        if (changes != 0) {
            rearrange(crystal);
            print(crystal);
        }
    }
    return steps-1;
}
void random_array(int (&crystal)[size][size], int dis_area){
    std::mt19937 rng1(std::chrono::system_clock::now().time_since_epoch().count()); // for windows
    std::uniform_int_distribution<int> dist(0, size-1);
    for(int i = 0; i < dis_area; i++){
        int check = 1;
        while(check!= 0) {
            int k1 = dist(rng1), k2 = dist(rng1);
            if (crystal[k1][k2] != 1){
                crystal[k1][k2] = 1;
                check = 0;
            }
        }
    }

}
int main() {
    int crystal[size][size] = {0};
    random_array(crystal, 10);
    std::cout << main_loop(crystal)<< '\n';
}





