   void connect(TreeLinkNode *root) {
        if(root==NULL) return;
        TreeLinkNode* node;
        TreeLinkNode* prenode;
        queue<TreeLinkNode*> q;
        q.push(root);
        int levelNumber=1,count=1,levelCount=0;
        bool mark=false;
        while(!q.empty()){
            node=q.front();
            if(mark){
                prenode->next=q.front();
            }
            prenode=q.front();
            q.pop();
            mark=true;
            levelCount++;
            if(node->left!=NULL) {q.push(node->left); ++count;}
            if(node->right!=NULL) {q.push(node->right); ++count;}
            if(levelCount==levelNumber){
                levelNumber=count;
                 mark=false;
            }
        }
        
    }
