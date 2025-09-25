#include "Account.hpp"
#include "Bank.hpp"
#include <iostream>

struct AccountOperations {
    double depositAmount;
    double withdrawAmount;
    double loanAmount;
};

// Helper function pour afficher les sections
void printSection(const std::string& title) {
    std::cout << "\n========================================" << std::endl;
    std::cout << title << std::endl;
    std::cout << "========================================" << std::endl;
}

// Test basic account creation
void testAccountCreation(Bank& myBank, Account& acc1, Account& acc2, Account& acc3, Account& acc4) {
    printSection("TEST 1: Account Creation");
    
    myBank.createAccount(acc1, "Manon L.");
    myBank.createAccount(acc2, "Antoine L.");
    myBank.createAccount(acc3, "Ema S.");
    myBank.createAccount(acc4, "Jonhy D.");
    
    std::cout << "Created accounts:" << std::endl;
    std::cout << "  " << acc1 << std::endl;
    std::cout << "  " << acc2 << std::endl;
    std::cout << "  " << acc3 << std::endl;
    std::cout << "  " << acc4 << std::endl;
}

// Test account modification
void testAccountModification(Bank& myBank, Account& acc1) {
    printSection("TEST 2: Account Modification");
    
    std::cout << "Valid modification:" << std::endl;
    myBank.modifyAccount(acc1.getId(), "Manon Lecuyer");
    std::cout << "Updated account: " << acc1 << std::endl;
}

// Test modification errors
void testModificationErrors(Bank& myBank, Account& acc1) {
    printSection("TEST 3: Modification Errors");
    
    std::cout << "Test: Empty name" << std::endl;
    myBank.modifyAccount(acc1.getId(), "");
    
    std::cout << "\nTest: Non-existent account ID" << std::endl;
    myBank.modifyAccount(9999, "Fake Account");
    
    std::cout << "\nTest: Negative account ID" << std::endl;
    myBank.modifyAccount(-1, "Invalid Account");
}

// Test normal banking operations
void testNormalOperations(Bank& myBank, Account& acc1) {
    printSection("TEST 4: Normal Banking Operations");
    
    AccountOperations ops1 = {1000, 300, 4000};
    std::cout << "\nTesting " << acc1.getName() << "'s account:" << std::endl;
    std::cout << "Initial balance: $" << myBank.getBalance(acc1.getId()) << std::endl;
    
    myBank.deposit(acc1.getId(), ops1.depositAmount);
    std::cout << "After deposit: $" << myBank.getBalance(acc1.getId()) << std::endl;
    
    myBank.withdraw(acc1.getId(), ops1.withdrawAmount);
    std::cout << "After withdrawal: $" << myBank.getBalance(acc1.getId()) << std::endl;
    
    myBank.giveLoan(acc1.getId(), ops1.loanAmount);
    std::cout << "After loan: $" << myBank.getBalance(acc1.getId()) << std::endl;
    std::cout << "Bank funds: $" << myBank.getBankFunds() << std::endl;
}

// Test error cases with negative amounts
void testNegativeAmounts(Bank& myBank, Account& acc3) {
    printSection("TEST 5: Negative Amounts (Error Handling)");
    
    AccountOperations invalidOps = {-200, -200, -0.02};
    
    std::cout << "Testing " << acc3.getName() << "'s account with invalid amounts:" << std::endl;
    std::cout << "Initial balance: $" << myBank.getBalance(acc3.getId()) << std::endl;
    
    std::cout << "\nTest: Negative deposit (-200)" << std::endl;
    myBank.deposit(acc3.getId(), invalidOps.depositAmount);
    
    std::cout << "\nTest: Negative withdrawal (-200)" << std::endl;
    myBank.withdraw(acc3.getId(), invalidOps.withdrawAmount);
    
    std::cout << "\nTest: Negative loan (-0.02)" << std::endl;
    myBank.giveLoan(acc3.getId(), invalidOps.loanAmount);
    
    std::cout << "Final balance: $" << myBank.getBalance(acc3.getId()) << std::endl;
}

// Test insufficient funds scenarios
void testInsufficientFunds(Bank& myBank, Account& acc4) {
    printSection("TEST 6: Insufficient Funds");
    
    std::cout << "Testing " << acc4.getName() << "'s account:" << std::endl;
    
    myBank.deposit(acc4.getId(), 100);
    std::cout << "Balance after $100 deposit: $" << myBank.getBalance(acc4.getId()) << std::endl;
    
    std::cout << "\nTest: Withdraw more than balance ($500)" << std::endl;
    myBank.withdraw(acc4.getId(), 500);
    std::cout << "Balance after failed withdrawal: $" << myBank.getBalance(acc4.getId()) << std::endl;
}

// Test bank insufficient funds for loan
void testBankInsufficientFunds(Bank& myBank, Account& acc2) {
    printSection("TEST 7: Bank Insufficient Funds for Loan");
    
    std::cout << "Testing " << acc2.getName() << "'s account:" << std::endl;
    std::cout << "Current bank funds: $" << myBank.getBankFunds() << std::endl;
    
    double excessiveLoan = myBank.getBankFunds() + 1000;
    std::cout << "\nTest: Requesting loan exceeding bank funds ($" << excessiveLoan << ")" << std::endl;
    myBank.giveLoan(acc2.getId(), excessiveLoan);
    
    std::cout << "Bank funds after failed loan: $" << myBank.getBankFunds() << std::endl;
}

// Test account deletion
void testAccountDeletion(Bank& myBank, Account& acc4) {
    printSection("TEST 8: Account Deletion");
    
    std::cout << "Deleting account: " << acc4 << std::endl;
    myBank.deleteAccount(acc4.getId());
    
    std::cout << "\nTest: Operations on deleted account" << std::endl;
    std::cout << "Trying to deposit on deleted account..." << std::endl;
    myBank.deposit(acc4.getId(), 100);
    
    std::cout << "\nBank funds after deletion: $" << myBank.getBankFunds() << std::endl;
}

int main() {
    std::cout << "╔══════════════════════════════════════╗" << std::endl;
    std::cout << "║    BANK SYSTEM TEST SUITE            ║" << std::endl;
    std::cout << "╚══════════════════════════════════════╝" << std::endl;
    
    // Initialize bank
    Bank myBank(10000);
    std::cout << "\nBank initialized with funds: $" << myBank.getBankFunds() << std::endl;
    
    // Create account objects
    Account acc1, acc2, acc3, acc4;
    
    // Run all tests
    testAccountCreation(myBank, acc1, acc2, acc3, acc4);
    testAccountModification(myBank, acc1);
    testModificationErrors(myBank, acc1);
    testNormalOperations(myBank, acc1);
    testNegativeAmounts(myBank, acc3);
    testInsufficientFunds(myBank, acc4);
    testBankInsufficientFunds(myBank, acc2);
    testAccountDeletion(myBank, acc4);
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "ALL TESTS COMPLETED" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    return 0;
}