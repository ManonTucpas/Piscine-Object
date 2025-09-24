#include "Account.hpp"
#include "Bank.hpp"
#include <iostream>

struct AccountOperations
{
    double depositAmount;
    double withdrawAmount;
    double loanAmount;
};

int testBankOperations(Bank &myBank, std::string name, int accountId, AccountOperations accountOps);
void testErrorCases(Bank &myBank);

int main()
{
    // Initialize bank
    Bank myBank(10000);
    std::cout << "\nBank initialized with funds: $" << myBank.getBankFunds() << std::endl;

    std::cout << "\nACCOUNT CREATION " << std::endl;

    // Create accounts
    Account acc1;
    myBank.createAccount(acc1, "Manon L.");
    AccountOperations accOps1 = {10000, 300, 4000};
    Account acc2;
    myBank.createAccount(acc2, "Antoine L.");
    AccountOperations accOps2 = {2000, 400, 10000};
    Account acc3;
    myBank.createAccount(acc3, "Ema S.");
    AccountOperations accOps3 = {-200, -200, -.02};
    Account acc4;
    myBank.createAccount(acc4, "Jonhy D.");
    AccountOperations accOps4 = {20, 200, 30};

    // Display account information using operator<<
    std::cout << "\nCreated accounts:" << std::endl;
    std::cout << acc1 << std::endl;
    std::cout << acc2 << std::endl;
    std::cout << acc3 << std::endl;
    std::cout << acc4 << std::endl;

    std::cout << "\nTest Error - Name empty:" << std::endl;
    myBank.modifyAccount(acc1.getId(), "");

    std::cout << "\nTest Error - Non-existent account ID:" << std::endl;
    myBank.modifyAccount(9999, "Fake Account");
    std::cout << "\n Modify Account" << std::endl;
    myBank.modifyAccount(acc1.getId(), "Manon Lecuyer");

    testBankOperations(myBank, acc1.getName(), acc1.getId(), accOps1);
    testBankOperations(myBank, acc2.getName(), acc2.getId(), accOps2);
    testBankOperations(myBank, acc3.getName(), acc3.getId(), accOps3);
    testBankOperations(myBank, acc4.getName(), acc4.getId(), accOps4);

    return 0;
}