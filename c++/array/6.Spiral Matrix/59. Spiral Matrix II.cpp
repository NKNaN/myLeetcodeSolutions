class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i = 0;
        int j = 0;
        bool up = false;
        bool down = false;
        bool left = false;
        bool right = true;
        vector<vector<int>> mat(n, vector<int>(n));
        int num = 0;
        if (n == 1) {
            mat[0][0] = 1;
            return mat;
        }
        while (num < n*n - 1) {
            if (right) {
                int target = n - i;
                for (; j < target; j++) {
                    // cout<<"i: "<<i<<"j: "<<j<<endl;
                    mat[i][j] = num+1;
                    ++num;
                }
                right = false;
                down = true;
                --j;
                --num;
                // cout<<"right"<<endl;
                cout<<num<<endl;
                continue;
            }
            if (down) {
                int target = n - i;
                for (; i < target; i++) {
                    // cout<<"i: "<<i<<"j: "<<j<<endl;
                    mat[i][j] = num+1;
                    ++num;
                }
                down = false;
                left = true;
                --i;
                --num;
                // cout<<"down"<<endl;
                cout<<num<<endl;
                continue;
            }
            if (left) {
                int target = n - 1 - i;
                for (; j >= target ; j--) {
                    // cout<<"i: "<<i<<"j: "<<j<<endl;
                    mat[i][j] = num+1;
                    ++num;
                }
                left = false;
                up = true;
                ++j;
                --num;
                // cout<<"left"<<endl;
                cout<<num<<endl;
                continue;
            }
            if (up) {
                int target = j + 1;
                cout<<target<<endl;
                for (; i >= target; i--) {
                    // cout<<"i: "<<i<<"j: "<<j<<endl;
                    mat[i][j] = num+1;
                    ++num;
                }
                up = false;
                right = true;
                ++i;
                --num;
                // cout<<"up"<<endl;
                cout<<num<<endl;
                continue;
            }
            
        }
        return mat;
    }
};