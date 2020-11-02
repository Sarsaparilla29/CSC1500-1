#include <iostream>
#include <string>

void hammingCheck(int code[7]){
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    int totalSum = 0;
    sum1 = (code[0] + code[2] + code[4] + code[6]);
    sum2 = (code[1] + code[2] + code[5] + code[6]);
    sum2 = (code[3] + code[4] + code[5] + code[6]);
    totalSum = sum1 + sum2 + sum3;
    std::cout << "Sum1: " << sum1 << std::endl;
    std::cout << "Sum2: " << sum2 << std::endl;
    std::cout << "Sum3: " << sum3 << std::endl;
    std::cout << "Total Sum: " << totalSum << std::endl;

    if(totalSum > 0){
        code[totalSum] = 0;
    }
    else{
        code[totalSum] = 1;
    }
    for(int i = 0; i < 7; i++){
        std::cout << code[i];
    }
    std::cout << std::endl;

    std::cout << "Correct Message: ";
    std::cout << code[2];
    std::cout << code[4];
    std::cout << code[5];
    std::cout << code[6];
    std::cout << std::endl;



}

int main(){
    int HammingArr[7];

    //Program Header
    std::cout << "Hamming Receiver" << std::endl;
    std::cout << "----------------" << std::endl;
    //User input
    std::cout << "Hamming Array: ";
    for(int i = 0; i < 7; i++){
        std::cin >> HammingArr[i];
    }
    std::cout << std::endl;
    //s1 = (m3 + m5 + m7);
    //s2 = (m3 + m6 + m7);
    //s3 = (m5 + m6 + m7);
    hammingCheck(HammingArr);
    
    
    for(int i = 0; i < 7; i++){
        std::cout << HammingArr[i] << std::endl;
    }


    std::cout << "END OF PROGRAM" << std::endl;
    return 0;
}
