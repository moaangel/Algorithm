class Solution {
    static int ret = 55;
    static int[] visited = new int[52];
    public void dfs(String start, String end, String[] words, int cnt){
        if (start.equals(end)){
            if(ret > cnt) ret = cnt;
            return;
        }
        if (cnt > ret) return;
        
        for (int i=0; i<words.length; i++){
            if (visited[i] == 0){
                int temp =0;
                for (int j=0; j<start.length(); j++){
                    if (start.charAt(j) != words[i].charAt(j))temp++;
                }
                if (temp == 1){
                    visited[i] = 1;
                    dfs(words[i],end, words, cnt+1);
                    visited[i] = 0;
                }
            }
        }
    }
    
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        dfs(begin,target,words,0);
        if (ret != 55)answer = ret;
        return answer;
    }
}