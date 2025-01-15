class Solution
{
public:
    int lastRemaining(int n)
    {
        int first = 1, last = n;
        int step = 1;
        for (int round = 0, remaining = n; remaining > 1; remaining >>= 1, step <<= 1, ++round)
        {

            if (round % 2)
            {
                last -= step;
                if (remaining % 2)
                {
                    first += step;
                }
            }
            else
            {

                first += step;
                if (remaining % 2)
                {
                    last -= step;
                }
            }
        }
        return first;
    }
};