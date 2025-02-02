import java.sql.SQLOutput;
import java.util.Scanner;
import java.util.*;

public class Main{
    static int n, mp, mf, ms, mv, mc = 500000;
    static List<Integer> p = new ArrayList<>();
    static List<Integer> f = new ArrayList<>();
    static List<Integer> s = new ArrayList<>();
    static List<Integer> v = new ArrayList<>();
    static List<Integer> c = new ArrayList<>();
    static List<Integer> ans = new ArrayList<>();
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        mp = sc.nextInt();
        mf = sc.nextInt();
        ms = sc.nextInt();
        mv = sc.nextInt();
        for (int i=0; i<n; i++){
            int pi=0,fi=0,si=0,vi=0,ci=0;
            pi = sc.nextInt();
            fi = sc.nextInt();
            si = sc.nextInt();
            vi = sc.nextInt();
            ci = sc.nextInt();
            p.add(pi);
            f.add(fi);
            s.add(si);
            v.add(vi);
            c.add(ci);
        }
        for (int i=0; i < (1 << n); i++){
            int pSum=0, fSum=0, sSum=0, vSum =0, cSum = 0;
            List<Integer> temp = new ArrayList<>();
            for (int j=0; j<n; j++){
                if((i & (1 << j))!= 0){
                    temp.add(j+1);
                    pSum += p.get(j);
                    fSum += f.get(j);
                    sSum += s.get(j);
                    vSum += v.get(j);
                    cSum += c.get(j);
                }
            }
            if (mc < cSum)continue;
            if (pSum >= mp && fSum >= mf && sSum >= ms && vSum >= mv){
                if (mc == cSum){
                    int checkNum = Math.min(temp.size(), ans.size());
                    boolean flag = false;
                    for (int k =0; k<checkNum; k++){
                        if(ans.get(k) == temp.get(k))continue;
                        if(ans.get(k) > temp.get(k)){
                            flag = true;
                            ans = temp;
                            break;
                        }
                        else {
                            flag = true;
                            break;
                        }
                    }
                    if(!flag){
                        if (ans.size() > temp.size())ans = temp;
                    }
                    continue;
                }
                mc = cSum;
                ans = temp;
            }
        }
        if(mc == 500000){
            System.out.println(-1);
            return;
        }
        System.out.println(mc);
        for (Integer num : ans){
            System.out.print(num + " ");
        }
    }
}