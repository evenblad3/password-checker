#ifndef PASSWORDCHECK_H
#define PASSWORDCHECK_H
#include <string>
#include <vector>

class PasswordCheck{
    public:
      bool sizeCheck(std::string password);
      void enterNewPassword(std::string password);
      bool upperCheck(std::string password);
      bool lowerCheck(std::string password);
      bool numCheck(std::string password);
      bool symbolCheck(std::string password);
      bool uniquePassword(std::string password);
      const std::vector<std::string>& getRecentPasswords() const;

    private:
      std::vector<std::string> recentPasswords = {};    
};

#endif