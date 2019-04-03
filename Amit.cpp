#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    int m;
    cin>>m;
    char n;
    cin.get(n);
    while(m--)
    	{
        	char o[1002],r[101000];
        	cin>>o>>r;

        	int l = strlen(o);
        	int h = strlen(r);

        	int o_abc[26] = {0}; // stores the frequency of each character in needle.
        	int f = 0;
        	for(int i=0;i<l;i++)
            	o_abc[o[i]-'a']++;

        	int checker_abc[26] = {0}; // stores frequency of each character in haystack

        	for(int i=0;i<l;i++)
        		{
            			checker_abc[r[i]-'a']++;
        		}

        	for(int i=l;i<h;i++)
        		{
            			//first check if found;
            			int found = 1;
            			for(int k=0;k<26;k++)
           				 {
                				if(o_abc[k] != checker_abc[k])
                					{
                    						found = 0;
                    						break;
                					}
            				 }
            				if(found)
            					{
                					f=1;
                					break;
            					}

            				checker_abc[r[i-l]-'a']--;
            				checker_abc[r[i]-'a']++;
        		}
       			int found = 1;
        		for(int k=0;k<26 && !f;k++)
        			{
                			if(o_abc[k] != checker_abc[k])
                				{
                    					found = 0;break;
                				}
            			}	
            			if(found) f=1;

       			 if(!f)
        		cout<<"NO"<<endl;
        		else
       		 	cout<<"YES"<<endl;
    	}
    return 0;
}
