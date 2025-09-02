class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
     int n = points.size();
     int result = 0;

     //Brute Approach
    //  for(int i=0; i<n; i++){
    //     // A
    //     int x1 = points[i][0];
    //     int y1 = points[i][1];

    //     for(int j=0; j<n; j++){
    //         if(i == j) continue;

    //         //B
    //         int x2 = points[j][0];
    //         int y2 = points[j][1];

    //         if(x2 >= x1 && y2 <= y1){

    //             bool isInsidePoint = false;
    //             for(int k=0; k<n; k++){
    //                 if(k == i || k == j) continue;

    //                 int x3 = points[k][0];
    //                 int y3 = points[k][1];

    //                 if(x3 >= x1 && x3 <= x2 && y3 <= y1 && y3 >= y2){
    //                     isInsidePoint = true;
    //                     break;
    //                 }
    //             }
    //         if(!isInsidePoint){
    //             result++;
    //         }
    //         }
    //     }
    //  }
    // return result;

    sort(points.begin(), points.end(), [](vector<int> &points1,vector<int> &points2){
        if(points1[0] == points2[0]){
            return points1[1] > points2[1];
        }
        return points1[0] < points2[0];
    });

        for(int i=0; i<n; i++){
            //A
            int x1 = points[i][0];
            int y1 = points[i][1];
            
            int maxY = INT_MIN;
            for(int j=i+1; j<n; j++){
                //B
                int x2 = points[j][0];
                int y2 = points[j][1];   

                if(y2 > y1) continue;
                if(maxY < y2){
                    result++;
                    maxY = y2;
                }    
            }
  
        }
    return result;
    }
};