class Solution {
    int answer = -1;
    boolean[] visited = new boolean[10];
    public void dfs(int idx, int hp, int arrsize, int ret, int[][] dg) {
        if (ret > answer) answer = ret;
        
        for (int i=0; i<arrsize; i++){
            if (dg[i][0] <= hp && !visited[i]){
                visited[i] = true;
                dfs(i,hp-dg[i][1], arrsize, ret+1, dg);
                visited[i] = false;
            }
        }
    }
    
    public int solution(int k, int[][] dungeons) {
        int arrsize = dungeons.length;
        for (int i=0; i<arrsize; i++){
            if (dungeons[i][0] <= k){
                visited[i] = true;
                dfs(i,k-dungeons[i][1],arrsize,1,dungeons);
                visited[i] = false;
                }
            }
        return answer;
    }
}