import java.util.List;
import java.util.ArrayList;

public class Bank {
    private List<BankAccount> accounts;

    public Bank() {
        accounts = new ArrayList<BankAccount>();
    }

    public void addAccount(BankAccount account) {
        this.accounts.add(account);
    }

    public float getTotalBalance() {
        float balance = 0;
        for (int i = 0; i < this.accounts.size(); i++) {
            balance += this.accounts.get(i).getBalance();
        }
        return balance;
    }

    public BankAccount findAccount(int accountNumber) throws AccountNotFoundException {
        BankAccount ac = null;
        for (int i = 0; i < this.accounts.size(); i++) {
            ac = this.accounts.get(i);
            if (ac.getAccountNumber() != accountNumber)
                ac = null;
        }
        if (ac == null)
            throw new AccountNotFoundException();
        return ac;
    }

    public float getMaxBalance() {
        float max = Integer.MIN_VALUE;
        for (int i = 0; i < this.accounts.size(); i++) {
            float tempBal = this.accounts.get(i).getBalance();
            if (max < tempBal) {
                max = tempBal;
            }
        }

        return max;
    }

    public float getMinBalance() {
        float min = Integer.MAX_VALUE;
        for (int i = 0; i < this.accounts.size(); i++) {
            float tempBal = this.accounts.get(i).getBalance();
            if (min > tempBal) {
                min = tempBal;
            }
        }

        return min;
    }

    public int getCountWithSpecificBal(float amount) {
        int count = 0;

        for (int i = 0; i < this.accounts.size(); i++) {
            BankAccount account = this.accounts.get(i);
            if (account.getBalance() >= amount)
                count++;
        }
        return count;
    }
}