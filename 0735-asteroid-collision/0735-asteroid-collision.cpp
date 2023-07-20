class Solution
{
public:
    int mod(int x)
    {
        if (x > 0)
            return x;
        else
            return -x;
    }

    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> stack;
        int j = asteroids.size() - 1;
        for (j; j >= 0; j--)
        {
            int i = asteroids[j];
            if (!stack.empty() && stack.top() < 0 && i > 0)
            {   
                if (!stack.empty() && stack.top() == -i)
                    stack.pop();
                else 
                {   
                    while (!stack.empty() && mod(stack.top()) < mod(i) && stack.top() < 0 && i > 0)
                        stack.pop();
                    

                    if(stack.empty())
                        stack.push(i);

                    else if(stack.top() == -i)
                        stack.pop();

                    else if(!(stack.top() < 0 && i > 0))
                        stack.push(i);
                    
        
                }
            }

            else
                stack.push(i);
            
        }

        vector<int> result;

        while (!stack.empty())
        {
            result.push_back(stack.top());
            stack.pop();
        }

        return result;
    }
};