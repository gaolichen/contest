#include<iostream.h>
#define MAXN 100
#define elem_t int
#define comp(a,b) ((a)-(b))

struct btree_t{
	elem_t a;
	btree_t *left,*right;
};

btree_t btree[MAXN];
btree_t *head;

btree_t* mybsearch(btree_t *key){
	btree_t *tmp,*pre;
	if(head==NULL){
		head=key;
		return head->left=head->right=NULL;
	}
	tmp=pre=head;
	while(tmp!=NULL){
		if(!comp(tmp->a,key->a))
			return tmp;
		else if(comp(tmp->a,key->a)<0){
			pre=tmp;
			tmp=tmp->right;
		}
		else {
			pre=tmp;
			tmp=tmp->left;
		}
	}
	if(tmp==pre->left){
		pre->left=key;
	}
	else pre->right=key;
	return key->left=key->right=NULL;
}

void dataprint(elem_t a){
	cout<<a<<endl;
}
void btreeprint(btree_t *head){
	if(head==NULL)return;
	if(head->left!=NULL)
		btreeprint(head->left);
	dataprint(head->a);
	if(head->right!=NULL)
		btreeprint(head->right);
}

elem_t a[100];

int main(){
	int n,i;
	while(cin>>n){
		head=NULL;
		for(i=0;i<n;i++){
			cin>>btree[i].a;
			mybsearch(&btree[i]);
		}
		cout<<head->a<<endl;
//		cout<<(head==NULL)<<endl;
		btreeprint(head);
	}
	return 0;
}