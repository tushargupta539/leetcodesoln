class Solution {
public:
    void dfs(vector<vector<int>>&ans,vector<vector<int>>&image,int row,int col,int color,int incolor,int n,int m)
    {
        ans[row][col]=color;
        if(row-1>=0&&ans[row-1][col]==incolor)
        {
            dfs(ans,image,row-1,col,color,incolor,n,m);//top
        }
        if(row+1<n&&ans[row+1][col]==incolor)
        {
             dfs(ans,image,row+1,col,color,incolor,n,m);//bottom
        }
        if(col-1>=0&&ans[row][col-1]==incolor)
        {
             dfs(ans,image,row,col-1,color,incolor,n,m);//left
        }
        if(col+1<m&&ans[row][col+1]==incolor)
        {
             dfs(ans,image,row,col+1,color,incolor,n,m);//right
        }
    
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int incolor=image[sr][sc];
        vector<vector<int>>ans=image;
        int n=image.size();
        int m=image[0].size();
        if (incolor == color) return image;

      dfs(ans,image,sr,sc,color,incolor,n,m);

       return ans; 
    }
};