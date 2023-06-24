#include<iostream>
#include<string>
using namespace std;
char findDigitAtPosition(long long position){
    long long start=1;
    long long lenght=1;
    while(position>lenght)
    {
        position-=lenght;
        lenght=to_string(++start).length();
    }
    string number= to_string(start);
    return number[position-1];
} 
int main()
{
    int q;
    cin>>q;
    for(int  i= 0; i<q; i++)
    {
        long long k;
        cin>>k;
        char digit=findDigitAtPosition(k);
        cout<<digit<<endl;

    }
    return 0;
}