#include <iostream>
#include <string>
using namespace std;

const int ALPHABET_SIZE = 26;

struct Trie {

	int index;
	Trie* child[ALPHABET_SIZE];
	Trie()
	{
		for (int i = 0; i < ALPHABET_SIZE; i++)
			child[i] = NULL;
		index = -1;
	}
};
bool insert(Trie* root, string str, int index)
{
	Trie* node = root;
	for (int i = 0; i < str.size(); i++) {
		int ind = 0;
		ind = str[i] - 'a';
		/* making new path if not already */
		if (node->child[ind] == NULL) {
			node->child[ind] = new Trie();
		}

		// go to next node
		node = node->child[ind];
	}

	// Mark leaf (end of word) and store
	// index of word in arr[]
	if (node->index == -1) {// first time leaf is being added
		node->index = index;
		return true;
	}
	return false;
}
//basically a DFS, but one that checks if something is a word by checking index
void printWords(Trie* node, string arr[])
{
	if (node == NULL)
		return;

	for (int i = 0; i < ALPHABET_SIZE; i++) {
		if (node->child[i] != NULL) {

			/* if leaf node then print key*/
			if (node->child[i]->index != -1)
				cout << arr[node->child[i]->index] << endl;

			printWords(node->child[i], arr);
		}
	}
}

int main(){
	string arr[5000];
	string s;
	int len;
	int ind=0;
	bool first;
	Trie* trie = new Trie();
	while(cin>>s){
		if(s=="quinie"){
			break;
		}
		string in = "";
		len = s.length();
		for(int i=0;i<len;i++){
			if('A'<=s[i] && s[i]<='Z'){
				in += s[i]-'A'+'a';
			}else if('a'<=s[i] && s[i]<='z'){
				in += s[i];
			}else{//if some other char like punctuation - split words else continue.
				if(in.length()>0){
					if(insert(trie,in,ind)){
						arr[ind]=in;
						ind++;
					}
					in="";
				}
			}
		}
		if(insert(trie,in,ind)){
			arr[ind]=in;
			ind++;
		}
	}
	printWords(trie,arr);

	return 0;
}
