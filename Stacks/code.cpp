//1. Minimum Bracket Reversal............

//  2.  Celebrity Problem......

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        stack<int>st;
        int n=mat.size();
        for(int i=0;i<n;i++){
            st.push(i);
        }
         while(st.size()!=1){
               int a=st.top();
               st.pop();
               int b=st.top();
               
               if(!mat[a][b]){
                   st.pop();
                   st.push(a);
               }
         }
         int celebrityindex=st.top();
         for(int i=0;i<n;i++){
             if(mat[celebrityindex][i]!=0 && i!=celebrityindex){
                 celebrityindex=-1;
                 break;
             }
         }
          for(int i=0;i<n;i++){
             if(mat[i][celebrityindex]!=1 ){
                 celebrityindex=-1;
                 break;
             }
         }
         
         
        return celebrityindex;
    }
};


// 3. online Stock Span 
class StockSpanner {
public:

stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1;
        while(!st.empty() && st.top().first<=price){
            span+=st.top().second;
            st.pop();
        }
        st.push({price,span});
         return span;
    }
};


// 4. Next Greater Element

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        stack<int>st;
        int n=arr.size();
        st.push(-1);
        int i=n-1;
        for(int i=n-1;i>=0;i--){
            
            while (st.top()!=-1 && st.top()<=arr[i]) { //equal and st.top()!=-1 lagana bhul rhi thi
                st.pop();
            }
            
            int temp=arr[i];
            arr[i]=st.top();
            
            st.push(temp);          
        }
        return arr;
        
    }
};






