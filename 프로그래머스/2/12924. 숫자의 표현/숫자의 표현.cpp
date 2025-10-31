int solution(int n) {
    int answer = 0;
    int start = 1, end = 2;
    int sum = 3;
    if(n == 1 || n == 2)return 1;
    while (start <= n/2 + 1) {  
        if (sum == n) {
            answer++;
            sum -= start;
            start++;
        } else if (sum < n) {
            end++;
            sum += end;
        } else {  
            sum -= start;
            start++;
        }
    }

    return answer + 1;  
}
