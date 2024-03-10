struct Node{
    Node* links[2];
    Node(){
        links[0] = NULL;
        links[1] = NULL;
    }
    void insert(int bit,Node* node){
        links[bit] = node;
    }
    bool exist(int bit){
        return links[bit]!=NULL;
    }
    Node* next(int bit){
        return links[bit];
    }
};

class Solution {
public:
     void insert(int num , Node* root){
         Node *temp = root;
            for(int j=31;j>=0;j--){
                if((num&1<<j) > 0){
                    if(!temp->exist(1)) temp->insert(1,new Node());
                    temp = temp->next(1);
                } 
                else{
                    if(!temp->exist(0)) temp->insert(0,new Node());
                    temp = temp->next(0);
                }
            }
     }
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Node* root = new Node();
        for(int i=0;i<n;i++){
            insert(nums[i],root);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int t = 0;
            Node *temp = root;
            for(int j=31;j>=0;j--){
                if((nums[i]&1<<j) > 0){
                    if(temp->exist(0)) temp = temp->next(0);
                    else{
                        temp=temp->next(1);
                        t = t|(1<<j);
                    } 
                }
                else{
                    if(temp->exist(1)){
                        temp = temp->next(1);
                        t = t|(1<<j);
                    }
                    else temp = temp->next(0);
                }
            }
            ans = max(ans,t^nums[i]);
        }
        return ans;
    }
};
