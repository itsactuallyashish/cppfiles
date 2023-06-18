auto valid=[&](vector<vector<int>>&grid,int x,int y)->bool{
                int n=grid.size(),m=grid[0].size();
                if(x>=n|| x<0 || y>=m || y<0 || grid[x][y]==0)
                    return false;
                return true;
                
            };

string dir="ULRD";
            int x[]={-1,0,0,1};
            int y[]={0,-1,1,0};
            for(int k=0;k<4;k++){
                if(valid(grid,i+x[k],j+y[k])){   
                    
                }
            }