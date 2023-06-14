class Solution {
public:
    int maxVowels(string s, int k) {
        // vector<char> alpha;
        // for(int i=0;i<26;i++)
        //     alpha.push_back((char)('a'+i));
        int vowels=0;
        int maxVow=-1;
        int f=0;
        int b=0;
        for(f=0;f<s.length();f++)
        {
            if(s[f]=='a' || s[f]=='e' || s[f]=='i' || s[f]=='o' ||s[f]=='u')
                vowels++;
            if(f==k-1)
                break;
        }
        maxVow=max(vowels,maxVow);

        cout<<f<<" "<<b;
        while(f<s.length())
        {
            if(s[b]=='a' || s[b]=='e' || s[b]=='i' || s[b]=='o' ||s[b]=='u')
                vowels--;
            b++;
            f++;
            if(s[f]=='a' || s[f]=='e' || s[f]=='i' || s[f]=='o' ||s[f]=='u')
                vowels++;
            maxVow=max(vowels,maxVow);
        }
        return maxVow;
    }
};