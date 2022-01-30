#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define rep(i,k,n) for(int i = k;i < n;++i)
#define pb push_back
#define mk make_pair
#define f first
#define s second


class trieNode{
public:
	trieNode** children;
	bool isterminal;
	char data;
	trieNode(char data){
		this->data = data;
		rep(i,0,26){
			children[i] = NULL;
		}
		isterminal = false;
	}
};

void insert(string s,trieNode* root){
	if(s.empty()){
		root->isterminal = true;
		return;
	}

	int index = s[0] - 'a';
	trieNode* child;

	if(root->children[index]){
		child = root->children[index];
	}else{
		child = new trieNode(s[0]);
		root->children[index] = child;
	}

	insert(s.substr(1),child);
}

void allpossiblesubs(trieNode* root,string word,string output = ""){
	if(root==NULL){
		return;
	}
	if(root->isterminal){
		cout<<word+output<<endl;
	}
	for(int i = 0;i < 26;i++){
		if(root->children[i] != NULL){
			string temp=output;
			output+=root->children[i]->data;
			allpossiblesubs(root->children[i],word,output);
			output=temp;
		}
	}
}

int main(){
	int n;
	cin>>n;

	trieNode* root = new trieNode('\0');
	rep(i,0,n){
		string s;
		cin>>s;
		insert(s,root);
	}

	int q;
	cin>>q;
	while(q--){
		string st;
		cin>>st;
		allpossiblesubs(root,st);
	}
}