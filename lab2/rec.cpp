//
// Created by kiril on 10.03.2022.
//
#include <iostream>
#include <cmath>
float f(float x){
    return x;
}
float g(float x){
    return x;
}
float rec_sum(float *a, int size){
    if (size == 1){
        return a[0];
    }
    int k = size/2;
    return rec_sum(a, k)+rec_sum(a+k, size-k);
}
float mean(float const psi[], float const pdf[], float const dx, unsigned size){
    auto *arr = new float[size];
    for(int i = 0; i < size; i++){
        arr[i] = psi[i]*pdf[i];
    }
    float k = rec_sum(arr, size)*dx;
    delete[] arr;
    return k;
}
int main(){
    float a, b;
    int n;
    std::cin >> a >> b >> n;
    float dx = (b-a)/n;
    auto *psi = new float[n];
    auto *pdf = new float[n];
    for(int i = 0; i < n; i++){
        psi[i] = f(a+dx*i+dx/2);
        pdf[i] = g(a+dx*i+dx/2);
    }
    std::cout << mean(psi, pdf, dx, n) << '\n';
}