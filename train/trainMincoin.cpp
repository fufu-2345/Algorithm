#include <iostream>
#include <vector>

using namespace std;
int maxx=(1LL<<31)-1;
vector<int> coins = {1, 3, 4, 5};
int amount = 333;

/*
int minCoins(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, maxx);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coins.size(); j++) { 
            int coin = coins[j];
            if (i >= coin) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    if (dp[amount] == maxx) {
        return -1;
    } else {
        return dp[amount];
    }
}
*/

int mincoins(){
	vector<int> memo(amount+1,maxx);
	memo[0]=0;
	for(int money=0;money<=amount;money++){
		for(int i=0;i<coins.size();i++){
			int coin=coins[i];
			if(coin<=money){
				int temp=memo[money-coin]+1;
				if(temp<memo[money]){
					memo[money]=temp;
				}
			}
		}
	}
	return memo[amount];
}

int main() {
    cout << mincoins() << endl;
    
    return 0;
}

