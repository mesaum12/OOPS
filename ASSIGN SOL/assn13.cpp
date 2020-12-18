#include<iostream>
using namespace std;
class Node
{
   int data;
   Node *next;
   public:
   void set_data(int value)
   {
       data=value;
   }
   void set_next(Node *ptr)
   {
       next=ptr;
   }
   Node* get_next(){
       return next;
   }
   int get_data()
   {
       return data;
   }
};
class LinkedList
{
   Node *root;
   public:
   Node* set_root(){root=nullptr;return root;}
   Node* create_node(int data);
   void append_node(Node **root,int data);
   void delete_node(Node **root,int data);
   void print_list(Node *ptr);
   void search_node(Node *root,int data);
   void delete_front(Node **ptr);
   
};

Node* LinkedList::create_node(int data)
{
    Node *ptr;
    ptr=new Node;
    ptr->set_data(data);
    ptr->set_next(nullptr);
    return ptr;
}
void LinkedList::append_node(Node **root,int data)
{
   Node *ptr1=create_node(data);
   if(*root==nullptr)
   {
       *root=ptr1;
   }
   else
   {
     Node *temp=*root;
     while(temp->get_next()!=nullptr)
        temp=temp->get_next();
     temp->set_next(ptr1);
   }
   
}
void LinkedList::delete_node(Node **root,int data)
{
    Node *temp=*root;
    if(temp==nullptr){
        cout<<"List is empty\n";
        return;
    }
    else if(temp->get_data()==data)
    {
        *root=(*root)->get_next();
         delete temp;
    }
    else
    {
        Node *prev=temp;
        while(temp!=nullptr && temp->get_data()!=data)
        {
            prev=temp;
            temp=temp->get_next();
        }
        if(temp==nullptr)
        {
            cout<<"Data not found\n";
        }
        else
        {
            prev->set_next(temp->get_next());
            delete(temp);
        }
        
    }
    
}
void LinkedList::print_list(Node *root)
{
    Node *temp=root;
    if((root)==nullptr){
        cout<<"The list is empty\n";
        return;
    }
    while(temp!=nullptr)
    {
        cout<<temp->get_data()<<" ";
        temp=temp->get_next();
    }
    cout<<"\n";
}
void LinkedList::search_node(Node *root,int data)
{
    if(root==nullptr)
    {
        cout<<"Data not present \n";
        return;
    }
    else
    {
        Node *temp=root;
        while(temp && temp->get_data()!=data)
        {
            temp=temp->get_next();
        }

        if(temp==nullptr)
        cout<<"Data not found\n";

        else
        {
            cout<<"The data is present\n";
        }
    }
    
}
void LinkedList::delete_front(Node **root)
{
    if(*root==nullptr)
    {
        cout<<"The list is empty\n";
        return;
    }
    else
    {
        Node *temp=*root;
        *root=(*root)->get_next();
        delete temp;
    }
    
}
int main()
{
    Node *root;
    LinkedList *ll;
    ll=new LinkedList;
    root=ll->set_root();
    int data,choice;
    while(1)
    {
        
        cout<<"1.Append a node\n";
    cout<<"2.Print the list\n";
    cout<<"3.Search data in the list\n";
    cout<<"4.Delete a node \n";
    cout<<"5.Delete front node of the list\n";
    cout<<"6.Exit the program\n";
    cout<<"Enter your choice\n";
    cin>>choice;
         switch(choice)
         {
      case 1:
           // int data;
            cout<<"Enter the data to be appended to the list \n";
            cin>>data;
            ll->append_node(&root,data);
            break;
      case 2:
            cout<<"Printing the list\n";
            ll->print_list(root);
            break;
      case 3:
            //int data 
            cout<<"Enter the data to be searched\n";
            cin>>data;
            ll->search_node(root,data);
            break;
      case 4:
            cout<<"Enter the data of the node to be deleted\n";
            cin>>data;
            ll->delete_node(&root,data);
            break;
      case 5:
            ll->delete_front(&root);
            break;
      case 6:
            exit(0);
      default:
             cout<<"Please enter valid choice\n";

          }
    }
    delete(ll);
    return 0;
}