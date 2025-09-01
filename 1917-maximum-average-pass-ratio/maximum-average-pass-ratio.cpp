class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    //     int n = classes.size();

    //     vector<double> pr(n);
    //     for(int i=0; i<n; i++){
    //         double ratio = (double)classes[i][0]/classes[i][1];
    //         pr[i] = ratio;
    //     }
        
    //     while(extraStudents--){
    //         vector<double> newpr(n);
    //         for(int i=0; i<n; i++){
    //             double newratio = (double)(classes[i][0] + 1)/(classes[i][1] + 1);
    //             newpr[i] = newratio;
    //         }

    //         int maxIndex = 0; 
    //         double bestDela = 0.0;
    //         for(int i=0; i<n; i++){
    //             double delta = newpr[i] - pr[i];
    //             if(delta > bestDelta){
    //                 bestDelta = delta;
    //                 maxIndex = i;
    //             }
    //         }

    //         pr[maxIndex] = newpr[maxIndex];
    //         classes[maxIndex][0]++;
    //         classes[maxIndex][1]++;
    //     }

    //     double result = 0.0;
    //     for(int i=0; i<n; i++){
    //         result += pr[i];
    //     }
    // return result/n;


    //Optimised Approach
    int n = classes.size();
    priority_queue<pair<double,int>> pq;
        for(int i=0; i<n; i++){
            double pr = (double)classes[i][0]/classes[i][1];
            double newpr = (double)(classes[i][0]+1)/(classes[i][1] + 1);
            double delta =  newpr - pr;
            pq.push({delta, i});
        }
    
        while(extraStudents--){
                auto it = pq.top();
                pq.pop();

                double delta = it.first;
                int maxIndex = it.second;

                classes[maxIndex][0]++;
                classes[maxIndex][1]++;


                //In the next cylce we have to upadate the maxHeap values of the changed class
                double pr = (double)classes[maxIndex][0]/classes[maxIndex][1];
                double newpr = (double)(classes[maxIndex][0]+1)/(classes[maxIndex][1] + 1);
                delta =  newpr - pr;
                pq.push({delta, maxIndex});

        }
        double result = 0.0;
        for(int i=0; i<n; i++){
            result += (double)classes[i][0] / classes[i][1];
        }
    return result /n;
    }
};