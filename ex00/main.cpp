#include "Account.hpp"
#include "Bank.hpp"
#include <iostream>

struct AccountOperations {
    double depositAmount;
    double withdrawAmount;
    double loanAmount;
};

int testBankOperations(Bank& myBank, std::string name, int accountId, AccountOperations accountOps);
void testErrorCases(Bank& myBank);

int main() {
    // Initialize bank
    Bank myBank(10000);
    std::cout << "\nBank initialized with funds: $" << myBank.getBankFunds() << std::endl;
    
    std::cout << "\nACCOUNT CREATION " << std::endl;
   
    // testErrorCases(myBank);

    // Create accounts
    const Account* acc1 = myBank.createAccount("Manon L.");
    AccountOperations accOps1 = { 10000, 300,4000 };
    const Account* acc2 = myBank.createAccount("Antoine H.");
    AccountOperations accOps2 = {2000, 400, 10000};
    const Account* acc3 = myBank.createAccount("Jonny P.");
    AccountOperations accOps3 = {-200, -200, -.02};
    const Account* acc4 = myBank.createAccount("Ema M.");
    AccountOperations accOps4 = {20, 200, 30};

    
    // Display account information using operator<<
    std::cout << "\nCreated accounts:" << std::endl;
    std::cout << "  " << *acc1 << std::endl;
    std::cout << "  " << *acc2 << std::endl;
    std::cout << "  " << *acc3 << std::endl;
    std::cout << "  " << *acc4 << std::endl;
            
    std::cout << "\nTest Error - Name empty:" << std::endl;
    myBank.modifyAccount(acc1->getId(), "");
   
    std::cout << "\nTest Error - Non-existent account ID:" << std::endl;
    myBank.modifyAccount(9999, "Fake Account");
    std::cout << "\n Modify Account" << std::endl;
    myBank.modifyAccount(acc1->getId(), "Manon Lecuyer");
    
    testBankOperations(myBank, acc1->getName(), acc1->getId(), accOps1);
    testBankOperations(myBank, acc2->getName(), acc2->getId(), accOps2);
    testBankOperations(myBank, acc3->getName(), acc3->getId(), accOps3);
    testBankOperations(myBank, acc4->getName(), acc4->getId(), accOps4);
    
    return 0;
}

int testBankOperations(Bank& myBank, std::string name, int accountId, AccountOperations accountOps)
{

    std::cout << "\nBANKING OPERATIONS - " << name << "'s Account" << std::endl;
    std::cout << "\nBANK FUNDS: $" << myBank.getBankFunds() << std::endl;

    std::cout << "\nInitial balance: " << myBank.getBalance(accountId) << std::endl;
    
    std::cout << "\nDepositing $" << accountOps.depositAmount << " ..." << std::endl;
    myBank.deposit(accountId, accountOps.depositAmount);
    std::cout << "New balance: "<< myBank.getBalance(accountId) << std::endl;
    
    std::cout << "\nAttempting to withdraw $" << accountOps.withdrawAmount << " ..." << std::endl;
    myBank.withdraw(accountId, accountOps.withdrawAmount);
    std::cout << "New balance: " << myBank.getBalance(accountId) << std::endl;
    
    std::cout << "\nDepositing $" << accountOps.depositAmount*2 << " ..." << std::endl;
    myBank.deposit(accountId, accountOps.depositAmount*2);
    std::cout << "New balance: " << myBank.getBalance(accountId) << std::endl;
    
    std::cout << "\nWithdrawing $" << accountOps.withdrawAmount*10 << " ..." << std::endl;
    myBank.withdraw(accountId, accountOps.withdrawAmount*10);
    std::cout << "New balance: "<< myBank.getBalance(accountId) << std::endl;
    
    std::cout << "\nLOAN OPERATIONS" << std::endl;
    
    std::cout << "\nRequesting loan of $" << accountOps.loanAmount   << " ..." << std::endl;
    myBank.giveLoan(accountId, accountOps.loanAmount);
    std::cout << "Account balance after loan: " << myBank.getBalance(accountId) << std::endl;
    
    std::cout << "\nBank funds after loan: " << myBank.getBankFunds() << std::endl;
    
    std::cout << "\nACCOUNT DELETION" << std::endl;
    
    std::cout << "\nDeleting " << name << "'s account..." << std::endl;
    myBank.deleteAccount(accountId);
    
    std::cout << "\nTest completed successfully!" << std::endl;
    return (0);
}


void testErrorCases(Bank& myBank) {
    std::cout << "\n--- COMPREHENSIVE ERROR TESTING ---" << std::endl;
    
    // Create a test account for error testing
    const Account* testAcc = myBank.createAccount("Error Test Account");
    int testId = testAcc->getId();
    
    std::cout << "\nCreated test account: " << *testAcc << std::endl;
    std::cout << "Initial bank funds: $" << myBank.getBankFunds() << std::endl;
    
    // 1. DEPOSIT ERRORS
    std::cout << "\n=== DEPOSIT ERROR TESTS ===" << std::endl;
    
    std::cout << "Test: Negative deposit amount" << std::endl;
    myBank.deposit(testId, -100.0);  // Should be rejected
    std::cout << "Balance after negative deposit: $" << myBank.getBalance(testId) << std::endl;
    
    std::cout << "\nTest: Zero deposit amount" << std::endl;
    myBank.deposit(testId, 0.0);     // Should be rejected
    std::cout << "Balance after zero deposit: $" << myBank.getBalance(testId) << std::endl;
    
    std::cout << "\nTest: Deposit to non-existent account" << std::endl;
    myBank.deposit(9999, 100.0);     // Should fail gracefully
    
    // 2. WITHDRAWAL ERRORS
    std::cout << "\n=== WITHDRAWAL ERROR TESTS ===" << std::endl;
    
    // First, deposit some money for withdrawal tests
    std::cout << "Setting up test account with $500..." << std::endl;
    myBank.deposit(testId, 500.0);
    std::cout << "Test account balance: $" << myBank.getBalance(testId) << std::endl;
    
    std::cout << "\nTest: Insufficient funds withdrawal" << std::endl;
    myBank.withdraw(testId, 1000.0); // Should fail - not enough money
    std::cout << "Balance after failed withdrawal: $" << myBank.getBalance(testId) << std::endl;
    
    std::cout << "\nTest: Negative withdrawal amount" << std::endl;
    myBank.withdraw(testId, -50.0);  // Should be rejected
    std::cout << "Balance after negative withdrawal: $" << myBank.getBalance(testId) << std::endl;
    
    std::cout << "\nTest: Zero withdrawal amount" << std::endl;
    myBank.withdraw(testId, 0.0);    // Should be rejected
    std::cout << "Balance after zero withdrawal: $" << myBank.getBalance(testId) << std::endl;
    
    std::cout << "\nTest: Withdrawal from non-existent account" << std::endl;
    myBank.withdraw(9999, 100.0);    // Should fail gracefully
    
    // 3. LOAN ERRORS
    std::cout << "\n=== LOAN ERROR TESTS ===" << std::endl;
    
    std::cout << "Current bank funds: $" << myBank.getBankFunds() << std::endl;
    
    std::cout << "\nTest: Loan exceeding bank funds" << std::endl;
    double excessiveLoan = myBank.getBankFunds() + 1000.0;
    myBank.giveLoan(testId, excessiveLoan); // Should fail - not enough bank funds
    std::cout << "Balance after failed excessive loan: $" << myBank.getBalance(testId) << std::endl;
    std::cout << "Bank funds after failed loan: $" << myBank.getBankFunds() << std::endl;
    
    std::cout << "\nTest: Negative loan amount" << std::endl;
    myBank.giveLoan(testId, -1000.0); // Should be rejected
    std::cout << "Balance after negative loan: $" << myBank.getBalance(testId) << std::endl;
    
    std::cout << "\nTest: Zero loan amount" << std::endl;
    myBank.giveLoan(testId, 0.0);     // Should be rejected
    std::cout << "Balance after zero loan: $" << myBank.getBalance(testId) << std::endl;
    
    std::cout << "\nTest: Loan to non-existent account" << std::endl;
    myBank.giveLoan(9999, 1000.0);    // Should fail gracefully
    
    // 4. ACCOUNT DELETION ERRORS
    std::cout << "\n=== ACCOUNT DELETION ERROR TESTS ===" << std::endl;
    
    std::cout << "Test: Delete non-existent account" << std::endl;
    myBank.deleteAccount(9999);       // Should fail gracefully
    
    std::cout << "\nTest: Delete negative account ID" << std::endl;
    myBank.deleteAccount(-1);         // Should fail gracefully
    
    // 5. BALANCE QUERY ERRORS
    std::cout << "\n=== BALANCE QUERY ERROR TESTS ===" << std::endl;
    
    std::cout << "Test: Get balance of non-existent account" << std::endl;
    try {
        double balance = myBank.getBalance(9999); // Might throw exception
        std::cout << "Balance of non-existent account: $" << balance << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // 6. EDGE CASES
    std::cout << "\n=== EDGE CASES ===" << std::endl;
    
    std::cout << "Test: Very large amounts" << std::endl;
    myBank.deposit(testId, 1000000000.0); // Very large deposit
    std::cout << "Balance after huge deposit: $" << myBank.getBalance(testId) << std::endl;
    
    std::cout << "\nTest: Very small positive amounts" << std::endl;
    myBank.deposit(testId, 0.01);     // Very small deposit
    std::cout << "Balance after tiny deposit: $" << myBank.getBalance(testId) << std::endl;
    
    // 7. ACCOUNT NAME EDGE CASES
    std::cout << "\n=== ACCOUNT NAME EDGE CASES ===" << std::endl;
    
    std::cout << "Test: Empty account name" << std::endl;
    const Account* emptyNameAcc = myBank.createAccount("");
    if (emptyNameAcc) {
        std::cout << "Created account with empty name: " << *emptyNameAcc << std::endl;
    }
    
    std::cout << "\nTest: Very long account name" << std::endl;
    std::string longName(1000, 'X'); // 1000 character name
    const Account* longNameAcc = myBank.createAccount(longName);
    if (longNameAcc) {
        std::cout << "Created account with very long name (length: " << longName.length() << ")" << std::endl;
    }
    
    std::cout << "\nTest: Special characters in account name" << std::endl;
    const Account* specialAcc = myBank.createAccount("John @#$%^&*() Doe");
    if (specialAcc) {
        std::cout << "Created account: " << *specialAcc << std::endl;
    }
    
    std::cout << "\n=== ERROR TESTING COMPLETED ===" << std::endl;
}