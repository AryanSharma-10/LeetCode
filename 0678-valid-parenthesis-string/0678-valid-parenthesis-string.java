public class pair{
    char paran;
    int index;

    pair(char paran, int index)
    {
        this.paran = paran;
        this.index = index;
    }

    public String toString()
    {
        return "value: "+paran+" index: "+index;
    }
}

class Solution {
    public boolean checkValidString(String s) {
        int len = s.length();
        Stack <pair> para = new Stack<>();
        Stack <pair> ast = new Stack<>();

        for(int i = 0 ; i < len ; i++)
        {
            if(s.charAt(i) == '(')
            {
                para.push(new pair(s.charAt(i), i));
            }
            else if(s.charAt(i) == ')')
            {
                if(!para.isEmpty() && para.peek().paran == '(')
                    para.pop();
                else
                    para.push(new pair(s.charAt(i), i));
            }
            else
                ast.push(new pair(s.charAt(i), i));
        }

        if(ast.size() >= para.size() && !para.isEmpty())
        {
            while(!ast.isEmpty() && !para.isEmpty())
            {
                pair currAst = ast.pop();

                if(para.peek().paran == '(' && para.peek().index < currAst.index)
                    para.pop();
                
                else if(para.peek().paran == ')' && para.peek().index > currAst.index)
                    para.pop();
            }
        }

        return para.isEmpty();
    }
}