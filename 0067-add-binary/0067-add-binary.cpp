class Solution {
public:
    string addBinary(string a, string b) {
        string result="";
        int i=a.length()-1;
        int j=b.length()-1;
        int carry=0;
        int temp=0;

        while(i>-1 && j>-1)
        {   
            cout<<(int)(a[i]-'0')<<" "<<(int)(b[j]-'0')<<" ";
            temp=carry+(int)(a[i]-'0')+(int)(b[j]-'0');
            cout<<temp<<endl;
            if(temp%2==0)
                result="0"+result;
            else 
                result='1'+result;

            if(temp>1)
                carry=1;
            else
                carry=0;
            i--;
            j--;
        }

        while(i>-1)
        {
            cout<<(int)(a[i]-'0')<<endl;
            temp=carry+(int)(a[i]-'0');
            cout<<temp<<endl;

            if(temp%2==0)
                result="0"+result;
            else 
                result='1'+result;

            if(temp>1)
                carry=1;
            else
                carry=0;
            i--;
        }

        while(j>-1)
        {
            cout<<(int)(b[j]-'0')<<endl;
            temp=carry+(int)(b[j]-'0');
            cout<<temp<<endl;

            if(temp%2==0)
                result="0"+result;
            else 
                result='1'+result;

            if(temp>1)
                carry=1;
            else
                carry=0;
            j--;
        }

        if(carry==1)
            result='1'+result;

        return result;
    }
};