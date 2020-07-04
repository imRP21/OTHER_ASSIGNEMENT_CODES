#include<iostream>
#include<cstdlib>

using namespace std;

/////////////// STRUCTURE Node ///////////////
template<typename data>
struct Node
{
    data key;
    Node<data> *parent;
    Node<data> *left;
    Node<data> *right;
    //CONSTRUCTOR   CAN BE USED IN STRUCTURE
    Node(data value=0){ key=value,parent=NULL,left=NULL,right=NULL;};
};

/////////////// CLASS Bin_Tree ///////////////
template<typename data>
class Bin_Tree
{
    Node<data> *root;

    public:
        //default-constructor
        Bin_Tree(){ root=NULL; };
        void insert(data t);
        void display();

        //INORDER TREE WALK
        void inorder_tree_walk(Node<data> *node);
        void inorder_tree_walk_seq(){ inorder_tree_walk(root); };

        //PREORDER TREE WALK
        void preorder_tree_walk(Node<data> *node);
        void preorder_tree_walk_seq(){ preorder_tree_walk(root); };

        //POSTORDER TREE WALK
        void postorder_tree_walk(Node<data> *node);
        void postorder_tree_walk_seq(){ postorder_tree_walk(root); };
};

template<typename data>//Insertion only happens at node;
void Bin_Tree<data>::insert(data value)
{
    Node<data> *t=new Node<data>(value);

    if(!root)
    {
        root=t;
        cout<<"ROOT OF TREE IS: "<<root->key<<endl;
    }
    else
    {
        Node<data> *ptr=root,*parent_tmp=NULL;

        while(ptr)
        {
            parent_tmp=ptr;
            if(ptr->key>value)
                ptr=ptr->left;
            else
                ptr=ptr->right;
        }
        if(parent_tmp->key>value)
            parent_tmp->left=t;
        else
            parent_tmp->right=t;

        t->parent=parent_tmp;
    }
}

template<typename data>
void Bin_Tree<data>::inorder_tree_walk(Node<data> *node)
{
    if(!node)
        return ;

    inorder_tree_walk(node->left);
    cout<<node->key<<" ";
    inorder_tree_walk(node->right);
}

template<typename data>
void Bin_Tree<data>::preorder_tree_walk(Node<data> *node)
{
    if(!node)
        return ;

    cout<<node->key<<" ";
    preorder_tree_walk(node->left);
    preorder_tree_walk(node->right);
}

template<typename data>
void Bin_Tree<data>::postorder_tree_walk(Node<data> *node)
{
    if(!node)
        return ;

    postorder_tree_walk(node->left);
    postorder_tree_walk(node->right);
    cout<<node->key<<" ";
}
int main()
{
    int keyvalues[10]={7,77,36,99,9,4,3,87,9,100};
    Bin_Tree<int> T;
    for(int i=0;i<10;i++)//or we can use rand() to generate random values .
        T.insert(keyvalues[i]);

    cout<<"INORDER TREE WALK SEQUENCE:  ";
    T.inorder_tree_walk_seq();
    cout<<endl;

    cout<<"PREORDER TREE WALK SEQUENCE:  ";
    T.preorder_tree_walk_seq();
    cout<<endl;

    cout<<"POSTORDER TREE WALK SEQUENCE:  ";
    T.postorder_tree_walk_seq();
    cout<<endl;

    return 0;
}
