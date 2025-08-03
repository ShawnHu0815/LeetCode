#include "../include/ILeetCodeQuestion.h"
#include <iostream>

using namespace std;

class FengkuangQ2 : public ILeetCodeQuestion {
public:
    void run() override {
        cout << "开始运行模板：" << std::endl;
//        freopen("input.txt", "r", stdin);
        vector<int> pixels = {1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,11,11,11,11,12,12,12,12,13,13,13,13,14,14,14,14,
                            15,15,15,15,16,16,16,16};
        vector<int> ans = flipImage(4, pixels);
        for(int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << " ";
        }
    }

private:
    vector<int> flipImage(int width, vector<int>& pixels) {
        vector<int> ans;
        for(int row = 0; row < width; ++row) {
            for(int col=1;col<=width;col++){
                int fullRow = row*(width*4) + width * 4;
                int colBegin = fullRow - col*4;
                copyOnePixel(pixels, ans, colBegin);
            }
        }
        return ans;
    }

    void copyOnePixel(vector<int>& pixels, vector<int>&ans, int begin){
        for(int i = 0; i < 4; ++i) {
            ans.emplace_back(pixels[begin + i]);
        }
    }
};