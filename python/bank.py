class BankAccount:
    def __init__(self, account_number, account_holder, balance=0.0):
        self.account_number = account_number
        self.account_holder = account_holder
        self.balance = balance

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            print(f"Deposited: ₹{amount:.2f}")
        else:
            print("Deposit amount must be positive!")

    def withdraw(self, amount):
        if amount <= 0:
            print("Withdrawal amount must be positive!")
        elif amount > self.balance:
            print("Insufficient balance!")
        else:
            self.balance -= amount
            print(f"Withdrew: ₹{amount:.2f}")

    def display(self):
        print("\n--- Account Details ---")
        print(f"Account Number : {self.account_number}")
        print(f"Account Holder : {self.account_holder}")
        print(f"Current Balance: ₹{self.balance:.2f}")
        print("------------------------\n")


if __name__ == "__main__":
    
    acc1 = BankAccount("123456789", "Alice", 1000)

    # Perform operations
    acc1.display()
    acc1.deposit(500)
    acc1.withdraw(200)
    acc1.withdraw(1500)  
    acc1.display()
