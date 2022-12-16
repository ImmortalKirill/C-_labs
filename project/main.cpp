//
// Created by kiril on 11.12.2022.
//
#include <iostream>
template <typename T> // any class that supports *, +, -, and conversion of 0 and 1(algebraic ring)
class Imaginary{
public:
    T* _val; // _val[0] - real part, _val[1] - Imaginary part
    Imaginary():_val(new T[2]){
        _val[0] = _val[1] = T(0);
    }
    Imaginary(T re, T im): Imaginary(){
        _val[0] = re;
        _val[1] = im;
    }
    /// copy constructor
    Imaginary(Imaginary<T>& g): Imaginary(){
        _val[0] = g.Re();
        _val[1] = g.Im();
    }
    /// move constructor
    Imaginary(Imaginary<T>&& g){
        _val = g._val;
        g._val = nullptr;
    }
    /// imaginary unit
    Imaginary(char a):Imaginary(){
        _val[0] = T(0);
        _val[1] = T(1);
    }
    /// conversion from reals
    Imaginary(T a): Imaginary(){
        _val[0] = a;
        _val[1] = T(0);
    }
    /// copy assignment operator
    Imaginary<T>& operator =(Imaginary<T> const& g){
        T* tmp__val = new T[2];
        tmp__val[0] = g._val[0];
        tmp__val[1] = g._val[1];
        delete [] _val;
        _val= tmp__val;
        return *this;
    }
    /// copy assignment operator from reals
    Imaginary<T>& operator =(T& g){
        T* tmp_val = new T[2];
        tmp_val[0] = g;
        tmp_val[1] = T(0);
        delete [] _val;
        _val= tmp_val;
        return *this;
    }
    /// move assignment operator
    Imaginary<T>& operator =(Imaginary<T>&& g){
        T* tmp = _val;
        delete tmp;
        _val = g._val;
        g._val = nullptr;
        return *this;
    }
    ~Imaginary(){
        delete[] _val;
    }
    /// each operator also for reals
    ///plus
    Imaginary<T> operator +(Imaginary<T>  g){
        return Imaginary<T>(_val[0] + g._val[0], _val[1] + g._val[1]);
    }
    Imaginary<T> operator +(T g){
        return Imaginary<T>(_val[0] + g, _val[1]);
    }
    /// operator works in reverse real + quaternions
    friend Imaginary<T> operator+(T g1, Imaginary<T> g2){
        return g2+g1;
    }
    /// minus itself
    Imaginary<T> operator -(){
        return Imaginary<T>(-_val[0], -_val[1]);
    }
    ///minus
    Imaginary<T> operator -(Imaginary<T>  g){
        return Imaginary<T>(_val[0] - g._val[0], _val[1] - g._val[1]);
    }
    Imaginary<T> operator -(T g){
        return Imaginary<T>(_val[0] - g, _val[1]);
    }
    /// operator works in reverse real - quaternions
    friend Imaginary<T> operator-(T g1, Imaginary<T> g2){
        return (-g2)+g1;
    }
    ///multiply
    Imaginary<T> operator *(Imaginary<T>  g){
        return Imaginary<T>(_val[0] * g._val[0] - _val[1] * g._val[1], _val[0] * g._val[1] + _val[1] * g._val[0]);
    }
    Imaginary<T> operator *(T g){
        return Imaginary<T>(_val[0] * g, _val[1] * g);
    }
    /// operator works in reverse real * quaternions
    friend Imaginary<T> operator*(T g1, Imaginary<T> g2){
        return g2*g1;
    }
    ///plus equals
    void operator +=(Imaginary<T>  g){
        _val[0] += g._val[0];
        _val[1] += g._val[1];
    }
    void operator +=(T g){
        _val[0] += g;
    }
    ///minus equals
    void operator -=(Imaginary<T>  g){
        _val[0] -= g._val[0];
        _val[1] -= g._val[1];
    }
    void operator -=(T g){
        _val[0] -= g;
    }
    /// times equals
    void operator *=(Imaginary<T>  g){
        T a = _val[0] * g._val[0] - _val[1] * g._val[1];
        T b = _val[0] * g._val[1] + _val[1] * g._val[0];
        _val[0] = a;
        _val[1] = b;
    }
    void operator *=(T g){
        _val[0] *= g;
        _val[1] *= g;
    }

    /// get real part
    T Re(){
        return _val[0];
    }
    /// get imaginary part
    T Im(){
        return _val[1];
    }
    /// module squared |a|^2
    T ModuleSq(){
        return _val[0]*_val[0]+_val[1]*_val[1];
    }
    /// conjurate of a: a - b*i
    Imaginary<T> Conj(){
        return Imaginary<T>(_val[0], -_val[1]);
    }
};

template <typename T>
/// print Imaginary in form a + bi
std::ostream& operator <<(std::ostream &os, const Imaginary<T> &im) {
    return os<<im._val[0]<<" + "<<im._val[1]<<"i"<<'\n';
}

template <typename T>
class Quaternion{
public:
    T* _val;/* _val[0] - real part,
                 _val[1] - Imaginary part
                 _val[2] - j-part
                 _val[3] - k-part*/
    Quaternion():_val(new T[4]){
        _val[0] = _val[1] = _val[2] = _val[3] = T(0);
    }
    Quaternion(T re, T i, T j, T k): Quaternion(){
        _val[0] = re;
        _val[1] = i;
        _val[2] = j;
        _val[3] = k;
    }
    /// basic quaternion units: "i", "j", "k"
    Quaternion(char a): Quaternion(){
        // you give a char i, j or k and it creates a unit
        if (a == 'i'){
            _val[1] = T(1);
        }
        else {
            if (a == 'j'){
                _val[2] = T(1);
            }
            else {
                if (a == 'k'){
                    _val[3] = T(1);
                }
            }
        }
    }
    /// conversion from reals
    Quaternion(T a): Quaternion(){
        _val[0] = a;
    }
    /// conversion from imaginary
    Quaternion(Imaginary<T> a): Quaternion(){
        _val[0] = a._val[0];
        _val[1] = a._val[1];
    }
    /// copy constructor
    Quaternion(const Quaternion<T>& g): Quaternion(){
        _val[0] = g._val[0];
        _val[1] = g._val[1];
        _val[2] = g._val[2];
        _val[3] = g._val[3];
    }
    /// copy assignment operator
    Quaternion<T>& operator =(Quaternion<T> const& g){
        T* tmp_val = new T[4];
        tmp_val[0] = g._val[0];
        tmp_val[1] = g._val[1];
        tmp_val[2] = g._val[2];
        tmp_val[3] = g._val[3];
        delete [] _val;
        _val= tmp_val;
        return *this;
    }
    /// copy assignment operator from reals
    Quaternion<T>& operator =(T& g){
        T* tmp_val = new T[4];
        tmp_val[0] = g;
        tmp_val[1] = tmp_val[2] = tmp_val[3] = T(0);
        delete [] _val;
        _val= tmp_val;
        return *this;
    }
    /// copy assignment operator from imaginary
    Quaternion<T>& operator =(Imaginary<T>& g){
        T* tmp_val = new T[4];
        tmp_val[0] = g._val[0];
        tmp_val[1] = g._val[1];
        tmp_val[2] = T(0);
        tmp_val[3] = T(0);
        delete [] _val;
        _val= tmp_val;
        return *this;
    }
    /// move assignment operator
    Quaternion<T>& operator =(Quaternion<T>&& g){
        T* tmp = _val;
        delete[] tmp;
        _val = g.val;
        g._val = nullptr;
        return *this;
    }

    ~Quaternion(){
        delete[] _val;
    }
    /// each operator also for reals and imaginary
    ///plus
    Quaternion<T> operator +(Quaternion<T>  g){
        return Quaternion<T>(_val[0] + g._val[0], _val[1] + g._val[1], _val[2] + g._val[2], _val[3] + g._val[3]);
    }

    Quaternion<T> operator +(Imaginary<T>  g){
        return Quaternion<T>(_val[0] + g._val[0], _val[1] + g._val[1], _val[2], _val[3]);
    }
    /// operator works in reverse imaginary + quaternions
    friend Quaternion<T> operator+(Imaginary<T> g1, Quaternion<T> g2){
        return g2+g1;
    }
    Quaternion<T> operator +(T g){
        return Quaternion<T>(_val[0] + g, _val[1], _val[2], _val[3]);
    }
    /// operator works in reverse real + quaternion
    friend Quaternion<T> operator+(T g1, Quaternion<T> g2){
        return g2+g1;
    }

    /// minus itself
    Quaternion<T> operator -(){
        return Quaternion(-_val[0],-_val[1], -_val[2], -_val[3]);
    }

    ///minus
    Quaternion<T> operator -(Quaternion<T>  g){
        return Quaternion<T>(_val[0] - g._val[0], _val[1] - g._val[1], _val[2] - g._val[2], _val[3] - g._val[3]);
    }
    Quaternion<T> operator -(Imaginary<T>  g){
        return Quaternion<T>(_val[0] - g._val[0], _val[1] - g._val[1], _val[2], _val[3]);
    }
    /// operator works in reverse imaginary - quaternion
    friend Quaternion<T> operator-(Imaginary<T> g1, Quaternion<T> g2){
        return (-g2)+g1;
    }

    Quaternion<T> operator -(T g){
        return Quaternion<T>(_val[0] - g, _val[1], _val[2], _val[3]);
    }
    /// operator works in reverse real - quaternion
    friend Quaternion<T> operator-(T g1, Quaternion<T> g2){
        return (-g2)+g1;
    }

    /// multiply
    Quaternion<T> operator *(Quaternion<T>  g){
        T k[4] = {_val[0], _val[1], _val[2], _val[3]};
        T g_k[4] = {g._val[0], g._val[1], g._val[2], g._val[3]};
        T a1 = k[0]*g_k[0] - k[1]*g_k[1] - k[2]*g_k[2] - k[3]*g_k[3];
        T a2 = k[0]*g_k[1] + g_k[0]*k[1] + k[2]*g_k[3] - g_k[2]*k[3];
        T a3 = k[0]*g_k[2] + g_k[0]*k[2] + k[3]*g_k[1] - g_k[3]*k[1];
        T a4 = k[0]*g_k[3] + g_k[0]*k[3] + k[1]*g_k[2] - g_k[1]*k[2];
        return Quaternion<T>(a1, a2, a3, a4);
    }
    Quaternion<T> operator *(Imaginary<T>  g){
        return (*this)*Quaternion<T>(g);
    }
    /// operator works in reverse imaginary*quaternion
    friend Quaternion<T> operator*(Imaginary<T> g1, Quaternion<T> g2){
        return g2*g1;
    }
    Quaternion<T> operator *(T g){
        return (*this)*Quaternion<T>(g);
    }
    /// operator works in reverse imaginary*quaternion
    friend Quaternion<T> operator*(T g1, Quaternion<T> g2){
        return g2*g1;
    }
    /// plus equals
    void operator +=(Quaternion<T>  g){
        Quaternion<T> a = (*this)+g;
        _val = a._val;
    }
    void operator +=(Imaginary<T>  g){
        Quaternion<T> a = (*this)+g;
        _val = a._val;
    }
    void operator +=(T g){
        Quaternion<T> a = (*this)+g;
        _val = a._val;
    }
    ///minus equals
    void operator -=(Quaternion<T>  g){
        Quaternion<T> a = (*this)-g;
        _val = a._val;
    }
    void operator -=(Imaginary<T>  g){
        Quaternion<T> a = (*this)-g;
        _val = a._val;
    }
    void operator -=(T g){
        Quaternion<T> a = (*this)-g;
        _val = a._val;
    }
    /// times equals
    void operator *=(Quaternion<T>  g){
        Quaternion<T> a = (*this)*g;
        _val = a._val;
    }
    void operator *=(Imaginary<T>  g){
        Quaternion<T> a = (*this)*g;
        _val = a._val;
    }
    void operator *=(T g){
        Quaternion<T> a = (*this)*g;
        _val = a._val;
    }

    /// get real part
    T Re(){
        return _val[0];
    }
    /// get Imaginary part
    T Im(){
        return _val[1];
    }
    /// get j-part
    T j(){
        return _val[2];
    }
    /// get k-part part
    T k(){
        return _val[3];
    }
    /// module squared |a|^2
    T ModuleSq(){
        return _val[0]*_val[0]+_val[1]*_val[1]+_val[2]*_val[2]+_val[3]*_val[3];
    }
    /// conjurate of a: a - b*i - c*j-d*k
    Quaternion<T> Conj(){
        return Quaternion<T>(_val[0], -_val[1], -_val[2], -_val[3]);
    }
};

template <typename T>
/// print Quaternion in form a + bi + cj + dk
std::ostream& operator <<(std::ostream &os, const Quaternion<T> &q) {
    return os<<q._val[0]<<" + "<<q._val[1]<<"i + "<<q._val[2]<<"j + "<<q._val[3]<<"k"<<'\n';
}

int main(){
 Quaternion<int> k('k');
 Quaternion<int> i('i');
 Quaternion<int> j('j');
 Imaginary<int> i1('i');
 std::cout<<i<<j<<k;
 Quaternion<int> b = i*j+k;
 std::cout << b;



}
