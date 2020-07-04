#include<iostream>
#include<cstdlib>

using namespace std;

/////////////// CLASS Node ///////////////
template<typename data>
class Node
{
    public:
        data key;
        Node<data> *parent;
        Node<data> *left;
        Node<data> *right;
    public:
        //paramaterized + default constructor
        Node(data value=0){ key=value,parent=NULL,left=NULL,right=NULL;};
};

/////////////// CLASS Bin_Tree ///////////////
template<typename data>
class Bin_Tree:public Node<data>
{
    public:
        Node<data> *root;

    public:
        //default-constructor
        Bin_Tree(){ root=NULL; };
        int height(Node<data> *node);
        void insert_node(data value);//Insertion only happens at node;

        //INORDER TREE WALK
        void inorder_tree_walk(Node<data> *node);
        void inorder_tree_walk_seq(){ inorder_tree_walk(root); };

        //PREORDER TREE WALK
        void preorder_tree_walk(Node<data> *node);
        void preorder_tree_walk_seq(){ preorder_tree_walk(root); };

        //POSTORDER TREE WALK
        void postorder_tree_walk(Node<data> *node);
        void postorder_tree_walk_seq(){ postorder_tree_walk(root); };

        //LEVELORDER TREE WALK
        void levelorder_tree_walk(Node<data> *node);
        void levelorder_tree_walk_seq(){ levelorder_tree_walk(root); };

        //2D(PLANE) REPRESENTATION
        void PLANE_REPRESENTATION()
        {

        }
};

template<typename data>
int Bin_Tree<data>::height(Node<data> *node)
{
    //if(node->left==NULL && node->right==NULL)
    if(node==NULL)
        return -1;

    else
        return (max(height(node->left),height(node->right))+1);
}

template<typename data>
void Bin_Tree<data>::insert_node(data value)
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

template<typename data>
void Bin_Tree<data>::levelorder_tree_walk(Node<data> *node)
{

}
int main()
{
    int keyvalues[10]={7,77,36,99,9,4,3,87,10,100};
    Bin_Tree<int> T;
    for(int i=0;i<10;i++)//or one can use rand() to generate random keyvalues .
        T.insert_node(keyvalues[i]);

    cout<<"INORDER TREE WALK SEQUENCE:  ";
    T.inorder_tree_walk_seq();
    cout<<endl;

    cout<<"PREORDER TREE WALK SEQUENCE:  ";
    T.preorder_tree_walk_seq();
    cout<<endl;

    cout<<"POSTORDER TREE WALK SEQUENCE:  ";
    T.postorder_tree_walk_seq();
    cout<<endl;

    cout<<"HEIGHT OF TREE: ";
    cout<<T.height(T.root)<<endl;
    return 0;
}
