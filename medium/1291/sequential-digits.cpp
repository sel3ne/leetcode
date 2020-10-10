class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
	{
        vector<int> V;
        for (int i = 1; i <= 9; i++)
        {
            int ans = 0;
            for(int j = i; j <= 9; j++)
            {
                ans = ans * 10 + j;
                if(ans <= high && ans >= low)
                {
                    V.push_back(ans);
                }
            }
        }
        sort(V.begin(),V.end());
        return V;
    }
};
