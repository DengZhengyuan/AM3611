//
// Created by Zhengyuan Deng on 2019/11/21.
//

#include <cmath>
#include "List.h"

template<class type>
List<type>::List(int length) {
    m_length = length;
    m_vector = new type[m_length];
}

template<class type>
List<type>::~List() {
    delete[] m_vector;
}

template<class type>
int List<type>::getLength() {
    return m_length;
}

template<class type>
type & List<type>::operator [] (int index) {
    return m_vector[index];
}

template<class type>
type List<type>::sum() {
    type result = 0;
    for (int i = 0; i < m_length; i++) {
        result += m_vector[i];
    }
    return result;
}

template<class type>
type List<type>::pNorm(double p) {
    double result,
           sum = 0.;
    for (int i = 0; i < m_length; i++) {
        sum += pow(abs(m_vector[i]), p);
    }
    result = pow(sum, 1/p);
    return result;
}

//template<class type>
//const type &List<type>::operator[](int index) {
//    return <#initializer#>;
//}


