//Time Complexity : O(M * N)
//Space Complexity : O(1)
class Solution {
    void dfs(vector<vector<int>>& image, int sr, int sc,int newColor,int rows,int cols,int source)
    {
        //Out of bound condition
        if(sr<0 || sr>=rows || sc<0 || sc>=cols)
            return;
        
        //If img[sr][sc] is not equal to source it(value) won't be changed to newColor
        else if(image[sr][sc]!=source)
            return;
        
        // Change the color
        image[sr][sc] = newColor;
        
        // Recursive calls for all the 4 directions
        dfs(image,sr-1,sc,newColor,rows,cols,source);   //TOP
        dfs(image,sr+1,sc,newColor,rows,cols,source);   //DOWN
        dfs(image,sr,sc-1,newColor,rows,cols,source);   //LEFT
        dfs(image,sr,sc+1,newColor,rows,cols,source);   //RIGHT
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        //This condition stops entering in infinite loop 
        //that is if image[sr][sc] is same as newColor 
        //in that case no operation would be performed and we will return the original image matrix
        if(newColor==image[sr][sc])
            return image;
        
        
        int rows = image.size();
        int cols = image[0].size();
        int source = image[sr][sc]; 
        dfs(image,sr,sc,newColor,rows,cols,source);
        return image;
    }
};