
#include <iostream>
using namespace std;
int main()
{
    string input ="2+3=5";
    char op[]={ '+', '-', '*', '/','=' };
    int numOperator=sizeof(op)/sizeof(op[0]);

    char foundOp[50];
    int countt=0;

    for (int i=0;i<input.size();i++)
    {
        char ch=input[i];
       for(int j=0;j<numOperator;j++)
       {
           if(ch==op[j])
           {
               foundOp[countt++]=ch;
               break;
           }
       }
    }

    for (int i=0;i<countt;i++)
    {
        cout<< "Operator"<<i+1<< ":"<< foundOp[i]<<endl;
    }
    cout<< "Number of operator :"<< countt <<endl;

    return 0;
}
