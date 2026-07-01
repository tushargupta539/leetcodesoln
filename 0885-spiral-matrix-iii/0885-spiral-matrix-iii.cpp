class Solution {
public:
vector<vector<int>>direction{{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
     

     int steps=0;
     int dir=0;
     vector<vector<int>>res;
     res.push_back({rStart,cStart});
     while(res.size()<rows*cols)
     {
        if(dir==0||dir==2)steps++;
        for(int count=0;count<steps;count++)
        {
            rStart=rStart+direction[dir][0];
            cStart=cStart+direction[dir][1];
            if(rStart>=0&&rStart<rows&&cStart>=0&&cStart<cols)
            {
                  res.push_back({rStart,cStart});
            }
        }
        dir=(dir+1)%4;
     }

        return res;
    }
};