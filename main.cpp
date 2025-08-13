#include "PasswordCheck.h"
#include <iostream>
#include <vector>
#include <limits>

int main(){
    PasswordCheck thePassword;
    std::string myPassword;
    std::cout << "Welcome to our website! Please create a password.\n";
    std::cout << "Requirements: \n";
    std::cout << "- At least ten characters long\n";
    std::cout << "- At least two uppercase letters\n";
    std::cout << "- At least two lowercase letters\n";
    std::cout << "- At least two digits\n";
    std::cout << "- At least two special characters\n";
    std::cout << "- It also must be different from your five previous passwords.\n\n";
    std::cout << "Please enter your password: ";
    std::getline(std::cin, myPassword);
    std::cout << std::endl;
    int numOfPasses = 0;

    const std::vector<std::string>& recentPasswords = thePassword.getRecentPasswords();
    thePassword.printRecentPasswords(recentPasswords);

    std::cout << std::endl;
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
        std::cout << "\nAll requirements passed. This is now your new password!" << std::endl;
    }
    else{
        std::cout << "The entered password does not pass all requirements." << std::endl;
    }

    numOfPasses = 0;

    return 0;
}
