class Solution {
    public int solution(int[][] dots) {
        int answer = 0;
        int xsize = 0;
        int ysize =0;
        if (dots[0][0] == dots[1][0]) xsize = dots[0][1] - dots[1][1];
        else if (dots[0][0] == dots[2][0]) xsize = dots[0][1] - dots[2][1];
        else if (dots[0][0] == dots[3][0]) xsize = dots[0][1] - dots[3][1];
        
        
        if (dots[0][1] == dots[1][1]) ysize = dots[0][0] - dots[1][0];
        else if (dots[0][1] == dots[2][1]) ysize = dots[0][0] - dots[2][0];
        else if (dots[0][1] == dots[3][1]) ysize = dots[0][0] - dots[3][0];
        
        answer = xsize * ysize;
        if (answer < 0) answer = -answer;
        return answer;
    }
}