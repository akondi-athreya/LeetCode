class Bank {
public:
    vector<long long> bank;
    int n;
    Bank(vector<long long>& balance) {
        bank = balance;
        n = (int)bank.size();
    }

    bool validAccount(int acc) {
        return acc >= 1 && acc <= n;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (!validAccount(account1) || !validAccount(account2)) return false;
        if (bank[account1 - 1] < money) return false;
        bank[account1 - 1] -= money;
        bank[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (!validAccount(account)) return false;
        bank[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (!validAccount(account)) return false;
        if (bank[account - 1] < money) return false;
        bank[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */