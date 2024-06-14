class Solution {
    public int solution(int[] num_list) {
        int answer = 0;
        int add = 0;
        int mul = 1;
        for (int i=0; i<num_list.length; i++){
            mul *= num_list[i];
            add += num_list[i];
        }
        add *= add;
        if (add > mul) answer = 1;
        return answer;
    }
}