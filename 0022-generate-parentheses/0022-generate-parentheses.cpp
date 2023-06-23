class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string para="";
        createPara(result, n*2,para,0,0);
        return result;
    }

    void createPara(vector<string>& brackets, int count, string para, int lbrack, int rbrack)
    {   
        // cout<<endl<<endl<<"Count is: "<<count<<endl;
        if(count==0)
        {   
            // cout<<"Pushing: "<<para<<endl;
            // cout<<"ending"<<endl;
            brackets.push_back(para);
            return;
        }
        
        if(lbrack<count+rbrack)
        {   
            // cout<<"Going left"<<endl;
            // cout<<"Current string: "<<para<<endl;
            createPara(brackets, count-1, para+"(", lbrack+1, rbrack);
        }

        if(lbrack-rbrack>0)
        {
            // cout<<"Going right"<<endl;
            // cout<<"Current string: "<<para<<endl;
            createPara(brackets, count-1, para+")", lbrack, rbrack+1);
        }
        // cout<<"ending"<<endl;

    }
};