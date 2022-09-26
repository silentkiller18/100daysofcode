class Solution {
public:
  
        int countPrimes(int n) {
int count=0;
vector prime(n+1,true);
for(int i=2;i<n;i++)
{
if(prime[i])
{
count++;
for(int j=i*2;j<n;j=j+i)
{
prime[j]=false;
}
}

    }
    return count;
}
};