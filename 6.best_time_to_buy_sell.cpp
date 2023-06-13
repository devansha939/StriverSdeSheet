// simple constructive , alsoc can be said dp bcz mini remembering the past
#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n=prices.size();
    int mini=prices[0],profit=0;
    for(int i=1;i<n;i++){
        int temp_profit = prices[i]-mini;
        profit=max(profit,temp_profit);
        mini = min(mini,prices[i]);
    }
    return profit;
}
