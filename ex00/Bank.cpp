#include "Bank.hpp"
int Bank::_accountId = 0;

Bank::Bank(double initialFunds) { _bankFunds = initialFunds; }

Bank::~Bank(void) {}

// Account management
bool Bank::createAccount(Account &account, const std::string &name)
{
    if (name.empty() || name.length() >= 100)
    {
        std::cout << "Error: Creating account - Name is invalid" << std::endl;
        return false;
    }
    // Account newAccount(newId, name);
    int newId = ++_accountId;
    account.initialize(newId, name);
    _accounts.push_back(&account);
    _balances[newId] = 0.0;

    return newId;
}

void Bank::deleteAccount(int accountId)
{
    if (!accountExists(accountId))
    {
        std::cout << "Error: Account " << accountId << " does not exist" << std::endl;
        return;
    }
    for (std::vector<Account *>::iterator it = _accounts.begin(); it != _accounts.end(); it++)
    {
        if ((*it)->getId() == accountId)
        {
            _accounts.erase(it);
            break;
        }
    }
    _balances.erase(accountId);
    return;
}

// Money operations
void Bank::deposit(int accountId, double amount)
{
    if (amount <= 0)
    {
        std::cout << "Error: invalid amount" << std::endl;
        return;
    }
    
    if (!accountExists(accountId))
    {
        std::cout << "Error: Account " << accountId << " does not exist" << std::endl;
        return;
    }
    double bankFee = amount * 0.05;

    _balances[accountId] += amount - bankFee;
    _bankFunds += bankFee;
    return;
}

void Bank::withdraw(int accountId, double amount)
{
    if (amount <= 0)
    {
        std::cout << "Error: invalid amount" << std::endl;
        return;
    }
    if (!accountExists(accountId))
    {
        std::cout << "Error: Account " << accountId << " does not exist" << std::endl;
        return;
    }
    if (_balances[accountId] < amount)
    {
        std::cout << "Insufficient funds" << std::endl;
        return;
    }
    _balances[accountId] -= amount;
    return;
}

void Bank::giveLoan(int accountId, double amount)
{
    if (amount <= 0)
        return;
    if (!accountExists(accountId))
    {
        std::cout << "Error: Account " << accountId << " does not exist" << std::endl;
        return;
    }

    if (_bankFunds < amount)
    {
        std::cout << "Bank Insufficient funds for loan" << std::endl;
        return;
    }
    _balances[accountId] += amount;
    _bankFunds -= amount;
    return;
}

bool Bank::modifyAccount(int accountId, const std::string &newName)
{
    if (newName.empty())
    {
        std::cout << "Error: New name cannot be empty" << std::endl;
        return false;
    }
    // Find the account in our internal list
    for (std::vector<Account *>::iterator it = _accounts.begin(); it != _accounts.end(); it++)
    {
        if ((*it)->getId() == accountId)
        {
            std::string oldName = (*it)->getName();
            (*it)->setName(newName); // <-- This will now work!
            std::cout << "✓ Account " << accountId << " name changed from '"
                      << oldName << "' to '" << newName << "'" << std::endl;
            return true;
        }
    }
    std::cout << "Error: Account with ID " << accountId << " not found" << std::endl;
    return false;
}

double Bank::getBalance(int accountId) const
{
    if (!accountExists(accountId))
    {
        std::cout << "Error: Account " << accountId << " does not exist" << std::endl;
        return 0;
    }
    return _balances.at(accountId);
}

// Bank Operations
double Bank::getBankFunds() const
{
    return _bankFunds;
}

bool Bank::accountExists(int accountId) const
{
    return _balances.find(accountId) != _balances.end();
}