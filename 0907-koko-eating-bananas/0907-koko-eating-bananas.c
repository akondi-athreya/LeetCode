long long find(int *piles,int n , long long mid)
{
    long long ans=0;
    for(int i=0 ; i<n ; i++)
    {
        if(piles[i] % mid == 0)
        {
            ans += piles[i]/mid;
        }
        else
        {
            ans += piles[i]/mid + 1;
        }
    }
    return ans;
}

int minEatingSpeed(int* piles, int pilesSize, int h){
    long long low = 1;
    long long high = 1e9;
    while(low <= high)
    {
        long long mid = (low + high)>> 1;
        long long time = find(piles , pilesSize , mid);
        if(time > h)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}