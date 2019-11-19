public class WithdrawLimitException extends Exception {
    @Override
    public String toString() {
        return "WithDrawLimitException - Limit Exceeded";
    }
}