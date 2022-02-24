#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
const int size = 60;
const int accuracy = 1000;
bool neighbour_check(int (&arr)[size], int x){
    /* checks if a dislocation moves or not
     * returns False if a dislocation has neighbours */
    return ((arr[x-1]+arr[x+1])%9 == 0) ;
}
void change(int &x, int &y){
    if (x==9){
        y = 9;
    }
    else x = 9;
}
void move(int (&arr)[size], int x, int choice){
    /* moves a dislocation(x, y) according to the choice*/
    if (choice == 0){change(arr[x-1], arr[x]); }
    else {change(arr[x+1], arr[x]); }
}
void rearrange(int (&arr)[size]) {
    for (int i = 0; i < size; i++) {
        if ((i != 0) and (i != size-1)) {
            if (arr[i] != 2) { arr[i] = arr[i] / 9; }
            else { arr[i] = 1; }
        }
        else if(arr[i] == 9){arr[i] = 1;}
    }
}
void print(int arr[size]){
    for(int i = 0;i < size;i++){
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}
int main_loop(int (&crystal)[size]){
    std::mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count()); // for windows
    std::uniform_int_distribution<int> dist(0, 1);
    int changes = -1, steps = 0;
    while(changes != 0) {
        steps++;
        changes = 0;
        for(int i = 1;i < size-1;i++){
            if(neighbour_check(crystal, i) and crystal[i] == 1){
                int choice = dist(rng);
                move(crystal, i, choice);
                changes++;
            }
            else if (crystal[i] == 1){crystal[i] = 2;}
        }
        if (changes != 0) {
            rearrange(crystal);
            //print(crystal);
        }
    }
    return steps-1;
}
void random_array(int (&crystal)[size], int dis_area){
    std::mt19937 rng1(std::chrono::system_clock::now().time_since_epoch().count()); // for windows
    std::uniform_int_distribution<int> dist(0, size-1);
    for(int i = 0; i < dis_area; i++){
        int check = 1;
        while(check!= 0) {
            int k1 = dist(rng1);
            if (crystal[k1] != 1){
                crystal[k1] = 1;
                check = 0;
            }
        }
    }

}
int main() {
    std::ofstream fout_steps;
    std::ofstream fout_rel;
    fout_steps.open("C:/Users/kiril/C-_labs/lab1/exercise 3/ex3_part2_steps.txt", std::ios:: app);
    fout_rel.open("C:/Users/kiril/C-_labs/lab1/exercise 3/ex3_part2_rel.txt", std::ios:: app);
    int dis_area = 1;
    while(dis_area < 50) {
        float mean = 0;
        for (int i = 0; i < accuracy; i++) {
            int crystal[size] = {0};
            random_array(crystal, dis_area);
            mean += main_loop(crystal);
        }
        dis_area+=1;
        std::cout << float(dis_area) / float(size * size) << ' ' << mean / accuracy << '\n';
        fout_steps << mean / accuracy << '\n';
        fout_rel << float(dis_area) / float(size * size) << '\n';
    }
    fout_rel.close();
    fout_steps.close();
}

