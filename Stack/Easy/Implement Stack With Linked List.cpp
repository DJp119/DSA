class Stack
{
public:
int count;
Node*head=NULL;
Node* trave=NULL;
    Stack()
    {
        count=0;
    }
 
    int getSize()
    {

        return count;

    }
    bool isEmpty()

    {

        if(trave==NULL){

            return true;

        }

        else{

            return false;

        }

    }

 

    void push(int data)

    {

        Node* new_Node=new Node(data);

        if(trave==NULL){

            head=new_Node;

            trave=head;

        }

        else{

            new_Node->next=trave;

            trave=new_Node;

        }

        count++;

    }

 

    void pop()

    {

        if(trave==NULL){

            

            return;

        }

        else{

            Node* temp=trave;

            trave=trave->next;

            delete(temp);

            count--;

        }

        

    }

 

    int getTop()

    {

        if(trave==NULL){

            return -1;

        }else

        return trave->data;

    }

};


https://www.codingninjas.com/studio/problems/implement-stack-with-linked-list_1279905?leftPanelTabValue=PROBLEM
