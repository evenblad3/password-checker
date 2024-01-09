#include "PasswordCheck.h"
#include <iostream>
#include <vector>
#include <limits>

int main(){
    PasswordCheck thePassword;
    std::string myPassword;
    std::cout << "Welcome to our website! Please create a password. It must be at least ten characters long with at least two uppercase letters, at least two lowercase letters, at least two digits, and at least two special characters. It also must be different from your five previous passwords." << std::endl;
    std::getline(std::cin, myPassword);  
    int numOfPasses = 0;

    
    std::cout << "Your recent passwords are (includes current password): ";
    const std::vector<std::string>& recentPasswords = thePassword.getRecentPasswords();
    for (const auto& password : recentPasswords){
        std::cout << password << "    ";
    }
    std::cout << std::endl;
    std::cout << "If there are no passwords listed, that means you have no recent passwords." << std::endl;

    std::cout << "Password length requirement: ";
    if(thePassword.sizeCheck(myPassword)){
        std::cout << "Pass!" << std::endl;
        numOfPasses += 1;
    }
    else{
        std::cout << "Fail" << std::endl;
    }

    std::cout << "Uppercase letter requirement: ";
    if(thePassword.upperCheck(myPassword)){
        std::cout << "Pass!" << std::endl;
        numOfPasses += 1;
    }
    else{
        std:: cout << "Fail" << std::endl;
    }

    std::cout << "Lowercase requirement: ";
    if(thePassword.lowerCheck(myPassword)){
        std::cout << "Pass!" << std::endl;
        numOfPasses += 1;
    }
    else{
        std::cout << "Fail" << std::endl;
    }

    std::cout << "Digit requirement: ";
    if(thePassword.numCheck(myPassword)){
        std::cout << "Pass!" << std::endl;
        numOfPasses += 1;
    }
    else{
        std::cout << "Fail" << std::endl;
    }

    std::cout << "Special character requirement: ";
    if(thePassword.symbolCheck(myPassword)){
        std::cout << "Pass!" << std::endl;
        numOfPasses += 1;
    }
    else{
        std::cout << "Fail" << std::endl;
    }

    std::cout << "Password uniqueness requirement: ";
    if(thePassword.uniquePassword(myPassword)){
        std::cout << "Pass!" << std::endl;
        numOfPasses += 1;
    }
    else{
        std::cout << "Fail" << std::endl;
    }

    if(numOfPasses == 6){
        thePassword.enterNewPassword(myPassword);
        std::cout << "All requirements passed. This is now your new password!" << std::endl;
    }
    else{
        std::cout << "The entered password does not pass all requirements." << std::endl;
    }

    numOfPasses = 0;

    return 0;
}