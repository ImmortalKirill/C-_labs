//
// Created by kiril on 10.03.2022.
//
#include <iostream>
#include <cmath>
float f(float x){
    return x;
}
float g(float x){
    return 1;
}
float fma_sum(float *a, int size){

    return a[0];
}
float round_1(float x, int n){
    auto t = static_cast<float>(1ul<<(n)) + 1ul;
    return t*x + (x - t*x);
}
float mean(float const psi[], float const pdf[], float const dx, unsigned size){
    float sum_fma = 0;
    for(int i = 0; i < size; i++){
        sum_fma =round_1( sum_fma+pdf[i]*psi[i], 6);
    }
    return sum_fma*dx;
}
int main(){
    float a, b;
    int n;
    std::cin >> a >> b >> n;
    float dx = (b-a)/n;
    //auto *arr = new float[n];
    //auto *arr_round = new float[n];
    auto *psi = new float[n];
    auto *pdf = new float[n];
    for (int i = 0; i < n; i++) {
        psi[i] = f(a + dx * i + dx / 2);
        pdf[i] = g(a + dx * i + dx / 2);
    }
    std::cout << mean(psi, pdf, dx, n) << '\n';
}
