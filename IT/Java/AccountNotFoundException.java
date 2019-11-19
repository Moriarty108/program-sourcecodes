public class AccountNotFoundException extends Exception {
    @Override
    public String toString() {
        return "AccountNotFoundException : Account Not Found";
    }
}