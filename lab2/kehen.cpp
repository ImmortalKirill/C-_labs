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
float kehn(float *a, int size){
    float err = 0, sum = 0;
    for(int i = 0; i < size; i++){
        float c = a[i] - err;
        float z = sum + c;
        err = z - sum - c;
        sum = z;
    }
    return sum;
}
float usual(float *x, int size){
    float sum = 0;
    for(int i =0; i  < size; i++){
        sum += x[i];
    }
    return sum;
}
float mean(float const psi[], float const pdf[], float const dx, unsigned size){
    auto *arr = new float[size];
    for(int i = 0; i < size; i++){
        arr[i] = psi[i]*pdf[i];
    }
    float k = kehn(arr, size)*dx;
    delete[] arr;
    return k;
}
int main(){
    float a, b;
    int n;
    std::cin >> a >> b >> n;
    float dx = (b - a) / n;
    auto *psi = new float[n];
    auto *pdf = new float[n];
    for (int i = 0; i < n; i++) {
        psi[i] = f(a + dx * i + dx / 2);
        pdf[i] = g(a + dx * i + dx / 2);
    }
    std::cout << mean(psi, pdf, dx, n) << '\n';
}
