//
// Created by kiril on 11.12.2022.
//
#include <iostream>
template <typename T>
class Imaginary{
private:
    T* val; // val[0] - real part, val[1] - Imaginary part
public:
    Imaginary():val(new T[2]){}
    Imaginary(T re, T im): Imaginary(){
        val[0] = re;
        val[1] = im;
    }
    /// imaginary unit
    Imaginary(char a):Imaginary(){
        val[0] = 0;
        val[1] = 1;
    }
    /// conversion from reals
    Imaginary(T a): Imaginary(){
        val[0] = a;
        val[1] = 0;
    }
    /// copy assignment operator
    Imaginary<T>& operator =(Imaginary<T>& g){
        T* tmp_val = new T[2];
        tmp_val[0] = g.Re();
        tmp_val[1] = g.Im();
        delete [] val;
        val= tmp_val;
        return *this;
    }
    /// copy assignment operator from reals
    Imaginary<T>& operator =(T& g){
        T* tmp_val = new T[2];
        tmp_val[0] = g;
        tmp_val[1] = 0;
        delete [] val;
        val= tmp_val;
        return *this;
    }
    /// move assignment operator
    Imaginary<T>& operator =(Imaginary<T>&& g){

    }
    /// move assignment operator from reals
    Imaginary<T>& operator =(T&& g){

    }
    ~Imaginary(){
        delete[] val;
    }
    /// each operator also for reals
    ///plus
    Imaginary<T>& operator +(Imaginary<T> & g){}
    Imaginary<T>& operator +(T & g){}
    ///minus
    Imaginary<T>& operator -(Imaginary<T> & g){}
    Imaginary<T>& operator -(T & g){}
    ///multiply
    Imaginary<T>& operator *(Imaginary<T> & g){}
    Imaginary<T>& operator *(T & g){}
    ///plus equals
    void operator +=(Imaginary<T> & g){}
    void operator +=(T & g){}
    ///minus equals
    void operator -=(Imaginary<T> & g){}
    void operator -=(T & g){}
    /// times equals
    void operator *=(Imaginary<T> & g){}
    void operator *=(T & g){}
    /// minus itself
    Imaginary<T>& operator -(){}
    /// get real part
    T Re(){
        return val[0];
    }
    /// get imaginary part
    T Im(){
        return val[1];
    }
    /// module squared |a|^2
    T ModuleSq(){
        return val[0]*val[0]+val[1]*val[1];
    }
    /// conjurate of a: a - b*i
    Imaginary<T>& Conj(){
        return Imaginary<T>(val[0], -val[1]);
    }
};
template <typename T>
class Quaternion{
private:
    T* val;/* val[0] - real part,
                 val[1] - Imaginary part
                 val[2] - j-part
                 val[3] - k-part*/

public:
    Quaternion():val(new T[4]){}
    Quaternion(T re, T i, T j, T k): Quaternion(){
        val[0] = re;
        val[1] = i;
        val[2] = j;
        val[3] = k;
    }
    /// basic quaternion units: "i", "j", "k"
    Quaternion(char a): Quaternion(){
        // you give a char i, j or k and it creates a unit
    }
    /// conversion from reals
    Quaternion(T a): Quaternion(){}
    /// conversion from imaginary
    Quaternion(Imaginary<T> a): Quaternion(){}
    /// copy assignment operator
    Quaternion<T>& operator =(Quaternion<T>& g){

    }
    /// copy assignment operator from reals
    Quaternion<T>& operator =(T& g){

    }
    /// copy assignment operator from imaginary
    Quaternion<T>& operator =(Imaginary<T>& g){

    }
    /// move assignment operator
    Quaternion<T>& operator =(Quaternion<T>&& g){

    }
    /// move assignment operator from reals
    Quaternion<T>& operator =(T&& g){

    }
    /// move assignment operator from imaginary
    Quaternion<T>& operator =(Imaginary<T>&& g){

    }
    ~Quaternion(){
        delete[] val;
    }
    /// each operator also for reals and imaginary
    ///plus
    Quaternion<T>& operator +(Quaternion<T> & g){}
    Quaternion<T>& operator +(Imaginary<T> & g){}
    Quaternion<T>& operator +(T & g){}

    ///minus
    Quaternion<T>& operator -(Quaternion<T> & g){}
    Quaternion<T>& operator -(Imaginary<T> & g){}
    Quaternion<T>& operator -(T & g){}

    /// multiply
    Quaternion<T>& operator *(Quaternion<T> & g){}
    Quaternion<T>& operator *(Imaginary<T> & g){}
    Quaternion<T>& operator *(T & g){}
    /// plus equals
    void operator +=(Quaternion<T> & g){}
    void operator +=(Imaginary<T> & g){}
    void operator +=(T & g){}
    ///minus equals
    void operator -=(Quaternion<T> & g){}
    void operator -=(Imaginary<T> & g){}
    void operator -=(T & g){}
    /// times equals
    void operator *=(Quaternion<T> & g){}
    void operator *=(Imaginary<T> & g){}
    void operator *=(T & g){}
    /// minus itself
    Quaternion<T> & operator -(){}
    /// get real part
    T Re(){
        return val[0];
    }
    /// get Imaginary part
    T Im(){
        return val[1];
    }
    /// get j-part
    T j(){
        return val[2];
    }
    /// get k-part part
    T k(){
        return val[3];
    }
    /// module squared |a|^2
    T ModuleSq(){
        return val[0]*val[0]+val[1]*val[1]+val[2]*val[2]+val[3]*val[3];
    }
    /// conjurate of a: a - b*i - c*j-d*k
    Quaternion<T>& Conj(){
        return Quaternion<T>(val[0], -val[1], -val[2], -val[3]);
    }
};
int main(){
 Imaginary<int> a('i');
 Imaginary<int> b(5, 3);
 b = 5;
}
