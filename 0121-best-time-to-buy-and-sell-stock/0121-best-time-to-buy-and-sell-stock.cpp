class Solution {
public:
    int maxProfit(vector<int>& price) {
        int sell=0;
        int buy=INT_MAX;
        int profit=0;

        for(int i=0;i<price.size();i++)
        {
            if(price[i]<buy)
            {
                cout<<"Buy price updated to: "<<price[i]<<endl;
                buy=price[i];
            }
            
            else if(profit<price[i]-buy)
            {   
                cout<<"Sell price updated to: "<<price[i]<<endl;
                profit=price[i]-buy;
                 cout<<"Profit price updated to: "<<profit<<endl;
            }

        }
        
        cout<<"Profit: "<<profit<<endl;
        if(profit<0)
            return 0;
        return profit;
    }
};