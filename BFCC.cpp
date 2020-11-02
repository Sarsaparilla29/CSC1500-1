//=====================================================================================
//Student: Jacob Bennett
//Title: Brute Force Code Cracker
//Description: The Brute Force Code Cracker, will take a cipher inputted by the user
//  and will shift each letter a certain amount over in order to "crack" the cipher.
//=====================================================================================
#include <iostream>
#include <string>
#include <vector>

class codeCracker {
    private:
        std::string cipher = "";
    public:
        void setCipher(std::string acipher) {cipher = acipher;}
        std::string getCipher() {return cipher;}
        void decryptor();
        void ASCIICon();
        //void display(); //may be deleted later
        std::vector<int> aValues;

        // LowerCase, UpperCase and ASCII values
        char lowerCase[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        int lowerDigits[26] = {97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122};
        char upperCase[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        int upperDigits[26] = {65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90};

};

void codeCracker::ASCIICon(){
    for(int i = 0; i < cipher.size(); i++){
        if(isupper(cipher[i])){
            for(int j = 0; j < 26; j++){
                if(cipher[i] == upperCase[j]){
                    aValues.push_back(upperDigits[j]);
                }
            }
        }
        else if(islower(cipher[i])){
            for(int j = 0; j < 26; j++){
                if(cipher[i] == lowerCase[j]){
                    aValues.push_back(lowerDigits[j]);
                }
            }
        }
        else{
            aValues.push_back(32);
        }
    }
}

void codeCracker::decryptor(){
    for(int i = 0; i < 26; i++){
        std::cout << i + 1 << ". ";
        for(int j = 0; j < cipher.size(); j++){
            int num = 0;
            if(aValues[j] > 64 && aValues[j] < 91){
                num = (aValues[j] + i - 65) % 26 + 65; 
                std::cout << upperCase[num - 65];
            }
            else if(aValues[j] > 96 && aValues[j] < 123){
                num = (aValues[j] + i - 97) % 26 + 97;
                std::cout << lowerCase[num - 97];
            }
            else{
                std::cout << " ";
            }

        }
        std::cout << std::endl;

    }

}


/*void codeCracker::display(){
    for(int i = 0; i < cipher.size(); i++){
        std::cout << aValues[i] << std::endl;
    }
    std::cout << cipher << std::endl;
}*/


int main(){
    codeCracker code;
    std::string cipher = "";
    std::cout << "Brute Force Code Cracker" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "Cipher: ";
    getline(std::cin, cipher);
    code.setCipher(cipher);
    code.ASCIICon();
    code.decryptor();
    //code.display();

    std::cout << "END OF PROGRAM" << std::endl;
    return 0;
}
