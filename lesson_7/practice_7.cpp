#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

// створюємо клас BankBalance, у якому будуть описані всі можливі операції з банківською 
// карткою

class BankBalance {
public: 
    BankBalance() {
        balance = 0;
    }

    void add_money(float amount) {
        this->balance += amount;
        this->total_balance += amount;
    }

    bool withdraw(float amount) {
        if (amount > this->balance) {
            return false;
        } else{ 
            this->balance -= amount;
            this->total_balance -= amount;
            return true;
        }
    }

    float get_balance() {
        return this->balance;
    }

    float get_total_balance() {
        return this->total_balance;
    }

    void accrual_of_interest() {
        this->total_balance -= this->balance;
        this->balance *= (1 + this->interest_rent / 100);
        this->total_balance += this->balance;
    }

private:
    float balance;
    static float interest_rent;
    static float total_balance;
};

// створюємо клас Wallet, який буде мати масив з декількома картками, можливостями додати
// ще картку, провести операції з катркою яку вкаже користувач та порахувати загальний 
// баланс (суму грошей на цсіх картках у гаманцю)

class Wallet {
private:
    static const int SIZE = 10;
    BankBalance* arr[SIZE];

public:
    Wallet() {
        for (int i = 0; i < SIZE; i++) {
            arr[i] = nullptr;
        }
    }

    bool insert() {
        for (int i = 0; i < SIZE; i++) {
            if (arr[i] == nullptr) {
                arr[i] = new BankBalance();
                return true;
            }
        }
        return false;
    }

    int number_of_accounts() {
        int count = 0;
        for (int i = 0; i < SIZE; i++) {
            if (arr[i] != nullptr) {
                count++;
            }
        }
        return count;
    }

    void deposit(int number, float amount) {
        if ((number <= this->number_of_accounts()) && (number > 0)) {
            arr[number - 1]->add_money(amount);
            cout << "The operation is successful." << endl;
        } else {
            cout << "Wrong index." << endl;
        }
    }

    void withdraw_money(int number, float amount) {
        if ((number <= this->number_of_accounts()) && (number > 0)) {
            if (arr[number - 1]->withdraw(amount)) {
                cout << "The operation is successful." << endl;
            } else {
                cout << "You don't have enough money." << endl;
            }
        } else {
            cout << "Wrong index." << endl;
        }
    }

    void accr_interest(int number) {
        if ((number <= this->number_of_accounts()) && (number > 0)) {
            arr[number - 1]->accrual_of_interest();
            cout << "The operation is successful." << endl;
        } else {
            cout << "Wrong index." << endl;
        }
    }

    void output() {
        cout << "Balance: " << endl;
        for (int i = 0; i < this->number_of_accounts(); i++) {
            cout << "Card " << i + 1 << ": " << arr[i]->get_balance() << endl;
        }
        cout << "Total balance: " << arr[0]->get_total_balance() << endl;
    }
};


float BankBalance::interest_rent = 5.5;
float BankBalance::total_balance = 0;

int main() {
    bool flag = true;
    int choice;
    float amount;
    int number;
    int accounts;
    Wallet* wallet = new Wallet();
    while (flag) {
        cout << "\n1. Add a card" << endl;
        cout << "2. Deposit money" << endl;
        cout << "3. Withdraw money" << endl;
        cout << "4. Accrual of interest" << endl;
        cout << "5. Output" << endl;
        cout << "6. Finish program\n" << endl;
        cin >> choice;
        switch(choice) {
            case 1:
                if (wallet->insert()) {
                    cout << "You have created a new card." << endl;
                } else {
                    cout << "You do not have free space for a new card." << endl;
                }
                break;
            case 2:
                accounts = wallet->number_of_accounts();
                cout << "Enter number of card (from 1 - to " << accounts << "): " << endl;
                cin >> number;
                cout << "Enter amount of money you want to put on your card: " << endl;
                cin >> amount;
                wallet->deposit(number, amount);
                break;
            case 3:
                accounts = wallet->number_of_accounts();
                cout << "Enter number of card (from 1 - to " << accounts << "): " << endl;
                cin >> number;
                cout << "Enter amount of money you want to withdraw from your card: " << endl;
                cin >> amount;
                wallet->withdraw_money(number, amount);
                break;
            case 4:
                accounts = wallet->number_of_accounts();
                cout << "Enter number of card (from 1 - to " << accounts << "): " << endl;
                cin >> number;
                wallet->accr_interest(number);
                break;
            case 5:
                wallet->output();
                break;
            case 6:
                cout << "Thank you for using this program." << endl;
                flag = false;
                break;
            default: 
                cout << "Invalid choice." << endl;
                break;
        }
    }
    return 0;
}
