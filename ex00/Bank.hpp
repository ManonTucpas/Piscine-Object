#ifndef _BANK_HPP_
#define _BANK_HPP_

#include <iostream>
#include <string>
#include <map>
#include <list>
#include "Account.hpp"

class Bank
{

    private:
        static int _accountId; // Static variable shared accross all Bank Instances
        std::list<Account> _accounts;
        std::map<int, double> _balances; // key: accountId - value: balance
        double _bankFunds;
        
        bool accountExists(int accountId) const;
       
    public:
        Bank(double initialFunds);
        ~Bank(void);

         // Account management
        const Account *createAccount(const std::string &name); // Read-only access with const
        void deleteAccount(int accountId);
        // Money operations
        void deposit(int accountId, double amount);
        void withdraw(int accountId, double amount);
        void giveLoan(int accountId, double amount);
        bool modifyAccount(int accountId, const std::string& newName);

        double getBalance(int accountId) const;
        double getBankFunds() const;
};

#endif