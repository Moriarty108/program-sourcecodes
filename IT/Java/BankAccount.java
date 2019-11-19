public class BankAccount {
    private int accountNumber;
    private float balance;
    private static float WITHDRAW_LIMIT = 500000;

    public BankAccount(int accountNumber, float balance) {
        this.accountNumber = accountNumber;
        this.balance = balance;
    }

    public int getAccountNumber() {
        return this.accountNumber;
    }

    public float getBalance() {
        return this.balance;
    }

    public void deposit(float amount) {
        this.balance += amount;
    }

    public void withdraw(float amount) throws WithdrawLimitException, LowBalanceException {
        if (amount > BankAccount.WITHDRAW_LIMIT) {
            throw new WithdrawLimitException();
        }

        else {
            if (amount > this.balance)
                throw new LowBalanceException();
            else
                this.balance -= amount;
        }
    }

    @Override
    public String toString() {
        return "BankAccount [accountNumber=" + accountNumber + ", balance=" + balance + "]";
    }

}