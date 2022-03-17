//
// Created by kiril on 10.03.2022.
//
#include <iostream>
#include <cmath>
double f(double x){
    return x;
}
double g(double x){
    return 1;
}
double kehn(double *a, int size){
    double err = 0, sum = 0;
    for(int i = 0; i < size; i++){
        double c = a[i] - err;
        double z = sum + c;
        err = z - sum - c;
        sum = z;
    }
    return sum;
}
double usual(double *x, int size){
    double sum = 0;
    for(int i =0; i  < size; i++){
        sum += x[i];
    }
    return sum;
}
double mean(double const psi[], double const pdf[], double const dx, unsigned size){
    auto *arr = new double[size];
    for(int i = 0; i < size; i++){
        arr[i] = psi[i]*pdf[i];
    }
    double k = kehn(arr, size)*dx;
    delete[] arr;
    return k;
}
int main(){
    double a, b;
    int n;
    std::cin >> a >> b >> n;
    double dx = (b - a) / n;
    auto *psi = new double[n];
    auto *pdf = new double[n];
    for (int i = 0; i < n; i++) {
        psi[i] = f(a + dx * i + dx / 2);
        pdf[i] = g(a + dx * i + dx / 2);
    }
    std::cout << mean(psi, pdf, dx, n) << '\n';
}

