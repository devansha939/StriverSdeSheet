//Prob->https://www.codingninjas.com/codestudio/problems/search-in-a-2d-matrix_8230773?challengeSlug=striver-sde-challenge&leftPanelTab=1
//Prob2->(a slight variation) https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1

// naive approach using extra sapce and binary search -> wor for first one
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m = mat.size(),n=mat[0].size();
    vector<int>vec;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            vec.push_back(mat[i][j]);
        }
    }
    int i=0,j=n*m-1;
    while(i<=j){
        int mid = (i+j)/2;
        if(vec[mid]==target){
            return 1;
        }
        else if (vec[mid]>target){
            j=mid-1;
        }
        else{
            i=mid+1;
        }
    }
    return 0;
}

// better approach using binary search on each row and not using any extra space -> work for both
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m = mat.size(),n=mat[0].size();
    
    for(int i=0 ; i<m ;i++){
        int l=0,r=n-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(mat[i][mid]==target){
                return 1;
            }
            else if (mat[i][mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
    }
    return 0;
}

// optimal for 2nd one and better for first one
class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int target)
	{
	    // your code here
	    int m = mat.size(),n=mat[0].size();
        int i=0,j=n-1;
        while(i<m&&j>=0){
            if(mat[i][j]==target){
                return 1;
            }
            else if(mat[i][j]>target){
                j-=1;
            }
            else{
                i+=1;
            }
        }
        return 0;
	}
};

// optimal for fist one O(log(m*n))
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m = mat.size(),n=mat[0].size();
    int i=0,j=n*m-1;
    while(i<=j){
        int mid=(i+j)/2;
        int row = mid/n;
        int col = mid%n;

        if(mat[row][col]==target){
            return 1;
        }
        else if(mat[row][col]>target){
            j=mid-1;
        }
        else{
            i=mid+1;
        }
    }
    return 0;
}
