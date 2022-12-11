//
// Created by kiril on 01.04.2022.
//
#include <iostream>
int place(int arr[30], int len){
    int width= 0, res = -1;
    for(int i=0; i<30;i++){
        if(arr[i] == 0){
            width+=1;
        }
        else{width = 0;}
        if(width >= len){
            res = i-width+1;
            break;
        }
    }
    return res;
}
int main(){
    std::cout << (-5)/std::abs(-5);

}
