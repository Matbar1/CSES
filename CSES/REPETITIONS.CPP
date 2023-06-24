#include<iostream>
#include<string>
using namespace std;
int main(){
    string dna;
    cin>>dna;
    int maxRepetation=1;
    int currentRepatation=1;
    for(int i=0; i< dna.length(); i++)
    {
        if(dna[i]==dna[i-1])
        {
            currentRepatation++;
            maxRepetation=max( maxRepetation,currentRepatation);
            
        }
        else {
        currentRepatation=1;
    }
}
cout<<maxRepetation<<endl;
return 0;
    
}