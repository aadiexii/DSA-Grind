class Solution {
public:
    int findClosest(int x, int y, int z) {
        while(true){
              if(x==z && y != z){
                return 1;
              }
              else if(y==z && x != z){
                return 2;
              }
              else if(x==z && y == z){
                return 0;
              }
            
            if(x < z && y > z){
            x++;
            y--;
            }
            else if(x<z && y< z){
                x++;
                y++;
            }
            else if(x>z && y > z){
                x--;
                y--;
            }
            else{
                x--;
                y++;
            }
        }
    return -1;
    }
};