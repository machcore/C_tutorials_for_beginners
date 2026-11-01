#include <stdio.h>
#include "oper.h"

int main() {
    
    int totalNum = readTotalStudents();
    float studentList[100];

    for (int i = 0; i < totalNum; i++) {
        studentList[i] = readGrade(i+1);
    }
    printf("\n");
    int pass = passingRecord(studentList, totalNum);
    printResult(
        totalNum,
        avgGrade(studentList, totalNum),
        max(studentList, totalNum),
        min(studentList, totalNum),
        pass,
        totalNum - pass,
        passingPercent(totalNum, pass)
    );


}
