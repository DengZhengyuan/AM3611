//
// Created by Zhengyuan Deng on 2019/11/21.
//

#ifndef AM3611_ASSIGNMENT_5_LIST_H
#define AM3611_ASSIGNMENT_5_LIST_H

template <class type>
class List
{
private:
    type *m_vector;
    int m_length;
public:
    explicit List(int length);
    ~List();
    int getLength();
    type & operator [](int index);
    type sum();
    type pNorm(double p = 2);
};


#endif //AM3611_ASSIGNMENT_5_LIST_H
