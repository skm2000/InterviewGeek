    #include <iostream>
    #include <vector>
    using namespace std;
     
    const double e = 0.00000001;
     
    int main(){
    	int n,d;
    	cin>>n>>d;
    	
    	vector <int> a(n+1);
    	
    	for(int i=1;i<=n;i++)
    		cin>>a[i];
    	
    	double l=0,r=100;
    	int L,R;
    	
    	while(l+e<r){
    		
    		double x=(l+r)/2;
     
    		vector<double> p(n+1);
    		vector<int> m(n+1);
    		
    		p[0]=0;
    		for(int i=1;i<=n;i++){
    			p[i]=(double)a[i]-x+p[i-1];
    		}
    		
    		m[0]=0;
    		for(int i=1;i<=n;i++){
    			m[i]=m[i-1];
    			if(p[i]<p[m[i-1]])
    				m[i]=i;
    		}
    		
    		int index=0;
    		for(int i=d;i<=n;i++){
    			if(p[i]-p[m[i-d]]>=0){
    				index = i;
    				break;
    			}
    		}
    		
    		if(index!=0){
    			l=x;
    			L=m[index-d]+1;
    			R=index;
    		}
    		else
    			r=x;
    	}
    	
    	cout<<L<<" "<<R<<endl;
    }