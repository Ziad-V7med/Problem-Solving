#include <bits/stdc++.h>
#define matador std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using namespace std;

int main()
{
    matador 
    int t; cin>>t;
    while (t--)
    {
       string s,hf1,hf2,mid; cin>>s; vector<int>freq(26); int cnt{}; 
       for (int i = 0; i < s.size(); i++) freq[s[i]-'a']++;
       for (int i = 0; i < 26; i++)
       {
         if(freq[i] % 2 == 1) {
            cnt++;
            mid = char(i+'a');
         }
       }
       if(cnt>1) cout<<"impossible\n";
       else {
         for (int i = 0; i < 26; i++)
         {
            int tmp = freq[i] / 2;
            while (tmp--) hf1.push_back(i+'a');
        }
        for (int i = hf1.size()-1; i >= 0; i--) hf2.push_back(hf1[i]);
        cout<<hf1+mid+hf2<<"\n";
       }
    } 
}





