class Solution {
public:
void dfs(vector<vector<int>>&ans,int row,int column,int color,vector<vector<int>>&image,int delrow[],int delcol[],int incol)
{   int n=image.size();
    int m=image[0].size();
    ans[row][column]=color;
    for(int i=0;i<4;i++)
    {
        int nr=row+delrow[i];
        int nc=column+delcol[i];
        if(nr>=0&&nr<n&&nc>=0&&nc<m&&image[nr][nc]==incol&&ans[nr][nc]!=color)
        {
           dfs(ans,nr,nc,color,image,delrow,delcol,incol);
        }
    }



}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial=image[sr][sc];
        
        image[sr][sc]=color;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vector<vector<int>>ans=image;
        dfs(ans,sr,sc,color,image,delrow,delcol, initial);

        return ans;
    }
};