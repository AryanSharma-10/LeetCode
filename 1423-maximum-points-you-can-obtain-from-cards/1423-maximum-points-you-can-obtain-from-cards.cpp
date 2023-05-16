class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int points=0;

        for(int i=0;i<k;i++)
            points+=cardPoints[i];

        int temp=points;
        int count=0;

        for(int i=cardPoints.size()-1;count<k;i--)
        {
            temp-=cardPoints[k-1-count];
            temp+=cardPoints[i];

            points=max(points,temp);
            
            count++;
        }

        return points;
    }
};
