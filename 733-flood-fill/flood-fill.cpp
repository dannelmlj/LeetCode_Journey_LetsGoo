class Solution {
public:
    void ans(vector<vector<int>>& image, int sr, int sc, int color, int curr){

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color){
            return image;
        }
        int farRight = image[0].size() - 1;
        int farDown = image.size() -1;
        int first = image[sr][sc];
        image[sr][sc] = color;
        if(sc > 0 && image[sr][sc-1] == first){
            floodFill(image, sr,sc-1,color);     
        }
        if(sc < farRight && image[sr][sc+1] == first){
            floodFill(image, sr,sc+1,color);
        }
        if(sr < farDown && image[sr+1][sc] == first){
            floodFill(image, sr+1,sc,color);
        }
        if(sr > 0 && image[sr-1][sc] == first){
            floodFill(image, sr-1,sc,color);
        }
        // cout<<image.size();
        return image;
    }
};