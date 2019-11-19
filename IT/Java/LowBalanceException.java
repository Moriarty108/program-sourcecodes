public class LowBalanceException extends Exception {
    @Override
    public String toString() {
        return "LowBalanceException - Insufficient Balance";
    }
}