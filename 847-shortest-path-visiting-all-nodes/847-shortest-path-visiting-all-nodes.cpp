class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
           
        int n=graph.size(),j,pathlen=0;
        
        queue<vector<int>> q; //gonnna store  NODE TRAVERSED 
        set<pair<int,int>> st;
        
        //going to every node & making FIRST traversing node each
        for(int i=0;i<n;i++) 
        {
            vector<int> vec(3,0);
            int path=0;
            int mask= (1<<i); // as visted array is static , BUT this method is dynammic
            int node=i;
            
            vec[0]=path;
            vec[1]=node;
            vec[2]=mask;
            
            //putting the current first node credentials
            q.push(vec);
            st.insert({node,mask});
        }
        
        
        //now all first ndoe is not its ready for traversal
        
        while(q.size())
        {
            auto z=q.front();
            q.pop();
            
            //if all bits in above array are found to be set
            if(z[2]==(1<<n)-1)
            {
                pathlen=z[0];
                break;
            }
            
            //now traversing through every node
            for(auto &j: graph[z[1]])
            {
                int mask = z[2]|(1<<j); // bitwise or for adding for next upcoming nodes

                //if state is ndoe visited yet
                if(st.count({j,mask})==0)
                {
                    vector<int> vec(3,0);
                    int path=z[0]+1;
                    int node=j;
                    // int mask=
                    
                    vec[0]=path;
                    vec[1]=node;
                    vec[2]=mask;
                    q.push(vec);
                    st.insert({j,mask});
                }              
                
            }
        }
        
        return pathlen;
    }
};