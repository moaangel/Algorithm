import java.util.*;

class Solution {
    public List<Integer> solution(int n) {
        int[] answer = {};
        List<Integer> arr = new ArrayList<Integer>();
        int num = n;
        while(num != 0 && num != 1){
            for (int i=2; i<=num; i++){                
                if (num % i == 0){
                    if(arr.contains(i) == false) {arr.add(i);}
                    num /= i;
                    break;
                }
            }
        }
        return arr;
    }
}