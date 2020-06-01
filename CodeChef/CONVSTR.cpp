#include<bits/stdc++.h>
using namespace std;


void solve(int n,string a,string b)
{
  vector<set<int>> ans;
    for(int i=0;i<n;i++)
    {
      if(a[i] < b[i])
      {
        cout<<-1<<"\n";
        return;
      }
    }
    for(char c='z';c>='a';c--)
    {
      bool present=0;
      //vector<int> val;
      set<int> val;
      for(int i=0;i<n;i++)
      {
        if(b[i] == c && a[i] != c)
        {
          val.insert(i);
        }
      }
      if(!present && !val.empty())
      {
        for(int i=0;i<n;i++)
        {
          if(a[i] == c)
          {
            present = 1;
            val.insert(i);
          }
        }
      }
      if(!present & !val.empty())
      {
        cout<<-1<<"\n";
        return;
      }
      if(!val.empty())
        ans.push_back(val);
      for(auto x:val)
        a[x] = c;
    }
    cout<<ans.size()<<"\n";
    for(auto x:ans)
    {
      cout<<x.size()<<" ";
      for(auto y:x)
        cout<<y<<" ";
      cout<<endl;
    }
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    string a,b;
    cin>>a;
    cin>>b;
    solve(n,a,b);
  }
}
