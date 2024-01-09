#include "PasswordCheck.h"
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>

bool PasswordCheck::sizeCheck(std::string password){
    if(password.size() >= 10){
        return true;
    }
    return false;
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
    if(upperCount >= 2){
        return true;
    }
    return false;
}
bool PasswordCheck::lowerCheck(std::string password){
    int i = 0;
    int lowerCount = 0;
    while(i < password.size()){
        if(islower(password[i])){
            lowerCount += 1;
        }
        i += 1;
    }
    if(lowerCount >= 2){
        return true;
    }
    return false;
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
    if(numberCount >= 2){
        return true;
    }
    return false;
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
        if(symbolCount >= 2){
            return true;
        }
        return false;
}
bool PasswordCheck::uniquePassword(std::string password){
    if(std::count(recentPasswords.begin(), recentPasswords.end(), password) > 0){
        return false;
    }
    return true;
}
const std::vector<std::string>& PasswordCheck::getRecentPasswords() const {
    return recentPasswords;
}