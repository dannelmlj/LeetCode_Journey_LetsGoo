class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        if image[sr][sc] == color:
            return image 
        starting_pixel = image[sr][sc]
        image[sr][sc] = color
        
        if sc-1 >=0 and image[sr][sc-1] == starting_pixel:
            image = self.floodFill(image, sr, sc-1,color)
            image[sr][sc-1] = color
        if sc+1 <= len(image[0])-1 and image[sr][sc+1] == starting_pixel: 
            image = self.floodFill(image, sr, sc+1, color)
            image[sr][sc+1] = color
        if sr-1 >= 0 and image[sr-1][sc] == starting_pixel:
            image = self.floodFill(image, sr-1,sc, color)
            image[sr-1][sc] = color
        if sr+1 <= len(image)-1 and image[sr+1][sc] == starting_pixel:
            image = self.floodFill(image, sr+1, sc, color)
            image[sr+1][sc] = color
        
        return image