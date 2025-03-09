#include <stdio.h>

// Function to display the menu
void displayMenu() {
    printf("\n🏧 ATM Simulator 🏧\n");
    printf("1️⃣ Deposit Money\n");
    printf("2️⃣ Withdraw Money\n");
    printf("3️⃣ Check Balance\n");
    printf("4️⃣ Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    float balance = 1000.00;  // Initial balance
    float amount;

    printf("\n💰 Welcome to the ATM Simulator! 💰\n");

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Deposit
                printf("💵 Enter amount to deposit: ");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("✅ Successfully deposited ₹%.2f\n", amount);
                } else {
                    printf("❌ Invalid amount! Deposit must be greater than ₹0.\n");
                }
                break;

            case 2: // Withdraw
                printf("🏧 Enter amount to withdraw: ");
                scanf("%f", &amount);
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    printf("✅ Successfully withdrawn ₹%.2f\n", amount);
                } else if (amount > balance) {
                    printf("❌ Insufficient balance! You only have ₹%.2f\n", balance);
                } else {
                    printf("❌ Invalid amount! Withdrawal must be greater than ₹0.\n");
                }
                break;

            case 3: // Check balance
                printf("💳 Your current balance: ₹%.2f\n", balance);
                break;

            case 4: // Exit
                printf("🚪 Exiting... Thank you for using the ATM!\n");
                return 0;

            default:
                printf("❌ Invalid choice! Please enter 1, 2, 3, or 4.\n");
        }
    }

    return 0;
}
