// first approach using extra 2d vector

#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>>final=matrix;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                for(int k=0;k<n;k++){
                        final[i][k]=0;
                }
                for(int k=0;k<m;k++){
                         final[k][j]=0;
                }
            }
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            matrix[i][j]=final[i][j];
        }
    }
}

// second approach by changing in matrix itself

#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	int m = matrix.size();
    int n = matrix[0].size();
        // vector<vector<int>>final=matrix;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                for(int k=0;k<n;k++){
                    if(matrix[i][k]!=0)matrix[i][k]=INT_MIN+1;
                }
                for(int k=0;k<m;k++){
                     if(matrix[k][j]!=0)matrix[k][j]=INT_MIN+1;
                }
            }
        }
    }
        
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==INT_MIN+1) matrix[i][j]=0;
        }
    }
}

// third approach by using 1d boolean vector

#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
		int m = matrix.size();
        int n = matrix[0].size();
		
        vector<bool>row(m,0);
        vector<bool>col(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i]==1||col[j]==1) matrix[i][j]=0;
            }
        }
}

// most optimal
#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	int n = matrix.size();
	int m = matrix[0].size();
	bool col1=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix[i][j]==0){
				matrix[i][0]=0;
				if(j!=0)matrix[0][j]=0;
				else col1=0;
			}
		}
	}

	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(matrix[i][j]!=0){
				if(matrix[i][0]==0||matrix[0][j]==0){
					matrix[i][j]=0;
				}
			}
		}
	}

	if(matrix[0][0]==0){
		for(int j=1;j<m;j++)matrix[0][j]=0;
	}
	if(col1==0){
		for(int i=0;i<n;i++)matrix[i][0]=0;
	}
}
