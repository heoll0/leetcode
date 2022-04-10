class Solution {
public:
    int mySqrt(int x) {
        if(x == 0){
            return 0;
        }
        double C = x, x0 = x;
        double xi = (x0*x0 + C) / (2*x0);
        while(abs(xi - x0) > 1e-5){
            x0 = xi;
            xi = (x0*x0 + C) / (2*x0);
        }
    return int(xi);
    }
};