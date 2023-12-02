#include<bits/stdc++.h>

using namespace std;


struct  Trie
{
	map<char,Trie> child;

	int cont=0;

	int end_word=0;

	void add(string& s, int i=0){
		cont++;
		if(i<(int)s.size()){
			child[s[i]].add(s,i+1);
		}
		else{
			end_word++;
		}
	}

	void remove(string& s, int i=0){
		cont--;
		if(i<(int)s.size()){
			child[s[i]].remove(s,i+1);
		}
		else{
			end_word--;
		}
	}

	int word_frequency(string& s, int i=0){
		if(i==(int)s.size()){
			return end_word;
		}
		if(child.count(s[i])){
			return child[s[i]].word_frequency(s,i+1);
		}
		return 0;
	}

	int count_words_prefix(string& s, int i=0){
		if(i==(int)s.size()){
			return cont;
		}
		if(child.count(s[i])){
			return child[s[i]].count_words_prefix(s,i+1);
		}

		return 0;
	}
};

int main(){
	int q, t;

	cin>>q;

	string s;

	Trie trie;
	while(q--){
		cin>>t;

		cin>>s;

		if(t==1){
			trie.add(s);
		}
		else if(t==2){
			trie.remove(s);
		}
		else{
			cout<< trie.count_words_prefix(s)<<'\n';
		}
	}

	return 0;
}