#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
void towerOfHanoi(int n, int from_rod, int to_rod, int aux_rod){ 
	if (n == 1) 
	{ 
		cout<<from_rod<<" "<<to_rod<<"\n"; 
		return; 
	} 
	towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
	cout<<from_rod<<" "<<to_rod<<"\n"; 
	towerOfHanoi(n - 1, aux_rod, to_rod, from_rod); 
} 
int main(){
	fio;
	int n; cin>>n;
	cout<<((1<<n) -1)<<"\n";
	towerOfHanoi(n, 1, 3, 2);
 
	return 0;
}