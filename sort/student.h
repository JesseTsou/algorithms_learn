//
// Created by Administrator on 2018/9/16.
//

#ifndef SELECTIONSORT_STUDENT_H
#define SELECTIONSORT_STUDENT_H
#include <iostream>
#include <string>

using namespace std;

struct student{
    string name;
    int score;

    bool operator<(const student &otherStudent){
        return score != otherStudent.score ? score < otherStudent.score : name < otherStudent.name;
    }

    friend ostream &operator<<(ostream &os, const student &student1){
        os<<"student: " << student1.name<<" "<< student1.score<<endl;
        return os;
    }
};


#endif //SELECTIONSORT_STUDENT_H
