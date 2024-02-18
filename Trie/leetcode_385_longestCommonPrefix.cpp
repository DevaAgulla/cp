struct Node{
    Node *arr[10];
    //bool isEnd;
};

void insert(Node *node,int num){
    string str = to_string(num);
    for(int i=0;i<str.size();i++){
        if(node->arr[str[i]-'0']==NULL){
             Node *temp = new Node();
            node->arr[str[i]-'0'] = temp;
        }
        node = node->arr[str[i]-'0'];
    }
}

int getPrefix(Node *node,int num){
    string str = to_string(num);
    int cnt = 0;
    for(int i=0;i<str.size();i++){
        if(node->arr[str[i]-'0']==NULL)break;
        node = node->arr[str[i]-'0'];
        cnt++;
    }
    return cnt;
}
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Node *par = new Node();
        for(int i=0;i<arr1.size();i++){
            insert(par,arr1[i]);
        }
        int ans = 0;
        for(int i=0;i<arr2.size();i++){
            int cnt = getPrefix(par,arr2[i]);
            ans = max(ans,cnt);
        }
        return ans;
    }
};
