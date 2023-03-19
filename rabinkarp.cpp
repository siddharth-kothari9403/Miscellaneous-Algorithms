#include <bits/stdc++.h>
#define d 256
using namespace std;

void search(char pat[], char str[], int q){
	int m=strlen(pat), n=strlen(str);
	int i,j;
	int p=0, t=0, h=1;

	for (i=0; i<m; i++){
		p=(d*p + pat[i])%q;
		t=(d*t + str[i])%q;
		h=(h*d)%q;
	}

	for (i=0; i<=n-m; i++){
		if (p==t){
			for (j=0; j<m; j++){
				if (str[i+j] != pat[j]){
					break;
				}
			}
			if (j==m){
				cout<<"Pattern found at index "<<i<<endl;
			}
		}else{
			t=(t*d + str[i+m]-(str[i]*h))%q;

			if (t<0)
				t=t+q;

		}
	}
}

int main(){
	char txt[]="geeks for geeks";
	char pat[]="geek";

	int q=101;
	search(pat,txt,q);
	return 0;
}

// see copy for explanation
