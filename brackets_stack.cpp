#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
int main()
{
    string arr;
    cin>>arr;
    int len=arr.length();
    stack<char>s;
    char x;
    int flag=0;
    for(int i=0;i<len;i++)
    {
        if(arr[i]=='{')
        {
            s.push('}');
        }
        else if(arr[i]=='(')
        {
            s.push(')');
        }
        else if(arr[i]=='[')
        {
            s.push(']');
        }
        else if(arr[i]=='}')
        {
            x=s.top();
            if(arr[i]==x)
            {
                s.pop();
                continue;
            }
            else
            {
                flag=1;
                break;
            }
        }
        else if(arr[i]==')')
        {
            x=s.top();
            if(arr[i]==x)
            {
                s.pop();
                continue;
            }
            else
            {
                flag=1;
                break;
            }
        }
        else if(arr[i]==']')
        {
            x=s.top();
                  if(arr[i]==x)
                    {
                      s.pop();
                      continue;
                    } else
                     {
                      flag=1;
                      break;
                    }
         }
         else
         {
             continue;
         }

     }
                    
                    if(flag==0)
                    cout<<"valid "<<endl;
                    else
                    cout<<"invalid"<<endl;    
        return 0;
 }
