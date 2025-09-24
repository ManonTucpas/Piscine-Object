#include "Account.hpp"

Account::Account() : _id(-1), _name("") {}

Account::Account(int id, const std::string &name) : _id(id), _name(name) {}

Account::~Account() {}

void Account::initialize(int id, const std::string &name)
{
    _id = id;
    _name = name;
}

int Account::getId(void) const { return _id; }

const std::string &Account::getName(void) const
{
    return _name;
}

void Account::setName(const std::string &newName)
{
    if (!newName.empty())
    {
        _name = newName;
    }
}

std::ostream &operator<<(std::ostream &p_os, const Account &account)
{
    if (account.getId() == -1 && account.getName().empty())
    {
        p_os << "Account[EMPTY/UNINITIALIZED]";
    }
    else
    {
        p_os << "[ Account ID: " << account.getId() << " ] - [ Account Name: " << account.getName() << " ]";
    }
    return p_os;
}