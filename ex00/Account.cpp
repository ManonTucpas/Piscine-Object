#include "Account.hpp"

Account::Account (int id, const std::string& name): _id(id), _name(name) {}

Account::~Account() {}

int Account::getId(void) const { return _id; }

const std::string& Account::getName(void) const { return _name; }

void Account::setName(const std::string& newName) {
    if (!newName.empty()) {
        _name = newName;
    }
}

std::ostream& operator<<(std::ostream& p_os, const Account& account) {
    p_os << "[ Account ID: " << account.getId() << " ] - [ Account Name: " << account.getName() << " ]";
    return p_os;
}