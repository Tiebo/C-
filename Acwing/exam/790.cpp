#include <iostream>

using namespace std;

int main() {
    double x;
    cin >> x;
    // 确定边界值
    double l = -10000, r = 100000;
    // 注意循环条件处理精度问题
    while (r - l > 1e-8) {
        // 找中间值
        double mid = (l + r) / 2;
        // 判断
        if (mid * mid * mid < x) l = mid;
        else r = mid;
    }
    printf("%.6f", r);
    return 0;
}