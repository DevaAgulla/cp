#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    if(n==1){
	        cout << "YES" << endl;
	        cout << 1 << endl;
	        continue;
	    }
	    else if(n==2){
	        cout << "NO" << endl;
	        continue;
	    }
	    
	    deque<int> three,four;
	    three.push_back(1);
	    three.push_back(3);
	    three.push_back(2);
	    four.push_back(2);
	    four.push_back(1);
	    four.push_back(4);
	    four.push_back(3);
	    int i=4;
	    if(n&1){
	         i=4;
	          while(i<n){
	            three.push_back(i);
	            three.push_front(i+1);
	            i+=2;
	         }
	         cout << "YES" << endl;
	        while(!three.empty()){
	            cout << three.front() << " ";
	            three.pop_front();
	        }
	    }
	    else{
	         i=5;
	          while(i<n){
	            four.push_back(i);
	            four.push_front(i+1);
	            i+=2;
	        }
	        cout << "YES" << endl;
	        while(!four.empty()){
	            cout << four.front() << " ";
	            four.pop_front();
	        }
	    }
	    cout << endl;
	}

}
