class Solution {
public:
    vector<int> number={1, 4, 5, 9, 10, 40, 50 ,90, 100, 400, 500, 900, 1000};
    vector<string> roman={"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    string intToRoman(int num) {
        string rom_exp="";
        int temp;

        while(num>0)
        {
            temp=findNumber(num);
            num=num-temp;
            rom_exp=rom_exp+roman[findIndex(temp)];
        }
        return rom_exp;
    }

    int findIndex(int n)
    {
        int temp;
        int index=-1;
        for(int i=0;i<number.size();i++)
        {
            if(number[i]>n)
                break;
            temp=number[i];
            index++;
        }
        return index;
    }

    int findNumber(int n)
    {
        int temp;
        for(int i=number.size()-1;i>=0;i--)
        {
            temp=number[i];
            if(number[i]<=n)
                break;
        }
        return temp;
    }
};