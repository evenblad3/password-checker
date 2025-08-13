#ifndef PASSWORDCHECK_H
#define PASSWORDCHECK_H

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <iostream>

class PasswordCheck{
public:
    PasswordCheck();
    ~PasswordCheck();
    bool sizeCheck(std::string password);
    void enterNewPassword(std::string password);
    bool upperCheck(std::string password);
    bool lowerCheck(std::string password);
    bool numCheck(std::string password);
    bool symbolCheck(std::string password);
    bool uniquePassword(std::string password);
    void printRecentPasswords(std::vector<std::string> passwords);
    const std::vector<std::string>& getRecentPasswords() const;

private:
    std::vector<std::string> recentPasswords = {};
    void loadRecentPasswords();
    void saveRecentPasswords();
};

#endif
