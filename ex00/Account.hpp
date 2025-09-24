#ifndef _ACCOUNT_HPP_
#define _ACCOUNT_HPP_

#include <cstring>
#include <iostream>

class Account
{
private:
    int _id;
    std::string _name;

public:
    Account();
    Account(int id, const std::string &name);
    ~Account(void);
    void initialize(int id, const std::string &name);
    int getId(void) const;
    const std::string &getName(void) const;
    void setName(const std::string &newName);
    friend std::ostream& operator<<(std::ostream& p_os, const Account& account);
};

#endif