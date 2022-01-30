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

// trieNode* traverse(trieNode* root,string word){
// 	if(root == NULL){
// 		return NULL;
// 	}

// 	trieNode* curr = root;
// 	trieNode* child = curr;
// 	for(int i = 0;i < word.length();i++){
// 		int index = word[i] - 'a';
// 		child = curr->children[index];

// 		if(child){
// 			curr = child;
// 		}
// 	}
// 	return child;
// }

// void autocomp(trieNode* root,string word,string output = ""){
// 	trieNode* temp = traverse(root,word);

// 	if(temp == NULL){
// 		cout<<"No suggestions\n";
// 		insert(word,root);
// 		return;
// 	}

// 	if(temp->isterminal){
// 		cout<<word+output<<endl;
// 	}

// 	rep(i,0,26){
// 		if(temp->children[i]){
// 			string stemp = output;
// 			output += temp->children[i]->data;
// 			autocomp(temp->children[i],word,output);
// 		}
// 	}
// }

void autocomp(trieNode* root,string word,string output = ""){
	
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
		autocomp(root,st);
	}
}