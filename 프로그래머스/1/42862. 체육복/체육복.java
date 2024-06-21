
import java.util.HashSet;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        HashSet<Integer> lostnum = new HashSet<>();
        HashSet<Integer> resnum = new HashSet<>();
        for (int i : reserve){
            resnum.add(i);
        }
        
        for (int i : lost){
            if (resnum.contains(i)){
                resnum.remove(i);
            }
            else{
                lostnum.add(i);
            }
        }
        for (int i : resnum){
            if(lostnum.contains(i-1)){
                lostnum.remove(i-1);
            }
            else if(lostnum.contains(i+1)){
                lostnum.remove(i+1);
            }
        }
        answer = n-lostnum.size();
        return answer;
    }
}