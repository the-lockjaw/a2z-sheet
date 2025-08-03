#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinaryTree{
private:
	TreeNode* root;

	TreeNode* build_tree(vector<int> &arr, int i){
		if(i >= arr.size() || arr[i] == -1)return nullptr;

		TreeNode* root = new TreeNode(arr[i]);
		root->left = build_tree(arr,2*i+1);
		root->right = build_tree(arr,2*i+2);

		return root;
	}

	TreeNode* array_to_tree(vector<int> &arr){
		if(arr.empty())return nullptr;
		return build_tree(arr,0);
	}

	void delete_tree(TreeNode* root){
		if(!root) return;
		delete_tree(root->left);
		delete_tree(root->right);
		delete root;
	}
public:
	// level order but with -1 for null pointers
	void print(){
		if(!root){
			cout<<"Empty tree!\n";
			return;
		}

		vector<TreeNode*> level;
		level.push_back(root);
		while(!level.empty()){
			vector<TreeNode*> next_level;
			bool last_level = true;

			for(TreeNode* node:level){
				if(!node) cout<<"-1 ";
				else{
					cout<<node->val<<" ";
					next_level.push_back(node->left);
					next_level.push_back(node->right);
					if(node->left||node->right)last_level = false;
				}
			}
			cout<<"\n";

			if(last_level)break;
			else level = next_level;
		}
	}

	TreeNode* tree_root(){
		return root;
	}

	BinaryTree():root(nullptr){}
	BinaryTree(vector<int> &arr){
		root = array_to_tree(arr);
	}
	~BinaryTree(){
		delete_tree(root);
	}

	void create(vector<int> &arr){
		delete_tree(root);
		root = array_to_tree(arr);
	}

	void clear(){
		delete_tree(root);
		root = nullptr;
	}
};

vector<vector<int>> level_order(TreeNode* root){
	if(!root)return {};
	vector<vector<int>> ans;
	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty()){
		int size = q.size();
		vector<int> level;
		for(int i = 0; i < size; i++){
			TreeNode* node = q.front();
			q.pop();
			if(node->left)q.push(node->left);
			if(node->right)q.push(node->right);
			level.push_back(node->val);
		}
		ans.push_back(level);
	}
	return ans;
}

void print_matrix(vector<vector<int>> &v){
	for(auto a : v){
		for(auto b : a)
			cout<<b<<" ";
		cout<<"\n";
	}
	cout<<"\n";
}

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin>>v[i];

	BinaryTree tree(v);

	vector<vector<int>> ans = level_order(tree.tree_root());
	cout<<"Level Order Traversal: \n";
	print_matrix(ans);
	
	tree.clear();
}