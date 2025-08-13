#include "PasswordCheck.h"

PasswordCheck::PasswordCheck(){
    loadRecentPasswords();
}

PasswordCheck::~PasswordCheck(){
    saveRecentPasswords();
}

bool PasswordCheck::sizeCheck(std::string password){
    return password.size() >= 10;
        
}

void PasswordCheck::enterNewPassword(std::string password){
    recentPasswords.push_back(password);
    if(recentPasswords.size() > 5){
        recentPasswords.erase(recentPasswords.begin());
    }
}

bool PasswordCheck::upperCheck(std::string password){
    int i = 0;
    int upperCount = 0;
    while(i < password.size()){
        if(isupper(password[i])){
            upperCount += 1;
        }
        i += 1;
    }
    return upperCount >= 2;
}

bool PasswordCheck::lowerCheck(std::string password) {
    int i = 0;
    int lowerCount = 0;
    while(i < password.size()){
        if(islower(password[i])){
            lowerCount += 1;
        }
        i += 1;
    }
    return lowerCount >= 2;
}

bool PasswordCheck::numCheck(std::string password){
    int i = 0;
    int numberCount = 0;
    while(i < password.size()){
        if(isdigit(password[i])){
            numberCount += 1;
        }
        i += 1;
    }
    return numberCount >= 2;
}

bool PasswordCheck::symbolCheck(std::string password){
    int i = 0; 
    int symbolCount = 0;
    while(i < password.size()){
        if(!isupper(password[i]) && !islower(password[i]) && !isdigit(password[i])){
            symbolCount += 1;
        }
        i += 1;
    }
    return symbolCount >= 2;
}

bool PasswordCheck::uniquePassword(std::string password){
    if(std::count(recentPasswords.begin(), recentPasswords.end(), password) > 0){
        return false;
    }
    return true;
}

void PasswordCheck::printRecentPasswords(std::vector<std::string> passwords){
    if (!recentPasswords.empty()){
        std::cout << "Your recent most passwords are:\n";
        for (const auto& password : recentPasswords){
            std::cout << "=> " << password << "\n";
        }
    }
}

const std::vector<std::string>& PasswordCheck::getRecentPasswords() const {
    return recentPasswords;
}

void PasswordCheck::loadRecentPasswords(){
    std::ifstream file("recentPasswords.txt", std::ios::out | std::ios::app);
    if (!file){
        std::cout << "recentPasswords.txt not found.\n";
    } else {
        std::string password;
        while (std::getline(file, password)) recentPasswords.push_back(password);
    }
}

void PasswordCheck::saveRecentPasswords(){
    std::ofstream file("recentPasswords.txt");
    for (const auto& password : recentPasswords){
        file << password << std::endl;
    }
    file.close();
}
