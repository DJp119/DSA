int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int floorValue = -1;
    while(node){
        if(node->data==x){
            floorValue=node->data;
            // return floorValue;
            break;
        }
        else if(node->data > x){
            floorValue=node->data;
            node=node->left;
        }
        else{
            node=node->right;
        }
    }
    return floorValue;
}
