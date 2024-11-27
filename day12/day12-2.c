#include <iostream>
using namespace std;


int solution(int n)
{
    int ans = 0;
    
    while (n > 0) {
        // n이 홀수인 경우 (점프 필요)
        if (n % 2 == 1) {
            ans++;
        }
        // 순간이동: n을 2로 나눔
        n /= 2;
    }

    return ans;
}

// 테스트 코드
int main() {
    cout << "Result for 5: " << solution(5) << endl;     // 출력: 2
    cout << "Result for 6: " << solution(6) << endl;     // 출력: 2
    cout << "Result for 5000: " << solution(5000) << endl; // 출력: 5

    return 0;
}
