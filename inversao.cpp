#include<bits/stdc++.h>

using namespace std;

template <typename T>
void printVector(const std::vector<T>& vec) {
    for (const T& element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

vector<int> coordinate_compression(vector<int> &val, int n){
	vector<int> uniq_val=val;
	

	sort(uniq_val.begin(),uniq_val.end());

	uniq_val.erase(unique(uniq_val.begin(),uniq_val.end()), uniq_val.end());

	vector<int> compressed_val(n);

	for(int i=0; i<n; i++){
		int idx= lower_bound(uniq_val.begin(),uniq_val.end(),val[i]) - uniq_val.begin();
		compressed_val[i]=idx;
	}

	return compressed_val;
}

class  SegTree{
    vector<long long> st;
    int size;

    int el_neutro = 0;

    int f(int a, int b){
        return a+b;
    }

    int query(int id, int stl, int str, int l, int r){
        if(str < l || r < stl){
            return el_neutro;
        }


        if(stl >= l and str <= r){
        	//cout<<"achou: "<<st[id]<< " id: "<<id<< " stl: "<<stl<< " str: "<<str<<endl;
            return st[id];
        }

        int mid = (str+stl)/2;

        return f(query(id*2+1,stl,mid,l,r),query(id*2+2,mid+1,str,l,r));
    }

    void update(int id, int stl, int str, int i, int amm){
        if(stl == i and str == i){
        	//cout<< "update -> i: "<<i<< " id: "<<id<<endl;
            st[id] += amm;
            return;
        }

        if(stl > i or str < i)
            return;
        int mid = (stl + str)/2;
        update(id*2+1,stl,mid,i,amm);
        update(id*2+2,mid+1,str,i,amm);
        st[id] = f(st[id*2+1],st[id*2+2]);
    }


    public:
        SegTree(int n):  st(4*n,0){size = n;}
        int query(int l, int  r){return query(0,0,size-1,l,r);}
        void update(int i, int amm){update(0,0,size-1,i,amm);}
};



int main(){
	int n;
	long long cont=0;

	cin>>n;

	vector<int> val(n);

	for(int i=0; i<n; i++){
		cin>>val[i];
	}

	
	vector<int> compressed_val = coordinate_compression(val,n);

	//printVector(compressed_val);

	//reverse(compressed_val.begin(), compressed_val.end());

	SegTree Seg= SegTree(n);

	for(int i=0; i<n; i++){
		Seg.update(compressed_val[i],1);
		//cout<< "real_val: "<<val[i]<<" l: " <<0<< " r: "<< compressed_val[i]-1 << "\n";
		int q=Seg.query(0,compressed_val[i]-1);
		//cout<< "query: "<<q<< " i: "<<i<<" i-q: "<<i-q <<endl;
		cont+= (i-q);
	}

	cout<< cont<< '\n';
}