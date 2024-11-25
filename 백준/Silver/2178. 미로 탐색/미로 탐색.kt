import java.util.LinkedList
import java.util.Queue
import java.util.Scanner

var arr = Array(100,{IntArray(100) { 0 } });
var visited = Array(100, {IntArray(100) { 0 } });
val dy : Array<Int> = arrayOf(1,0,-1,0);
val dx : Array<Int> = arrayOf(0,1,0,-1);
fun main(){
    val sc = Scanner(System.`in`)
    var n : Int = sc.nextInt();
    var m : Int = sc.nextInt();
    for (i in 0..<n){
        var tmp : String = sc.next();
        for (j in 0..<m){
                arr[i][j] = tmp[j] - '0';
            }
    }
    var q : Queue<Array<Int>> = LinkedList();
    visited[0][0] = 1;
    var start = arrayOf(0,0);
    q.add(start);
    while(q.isNotEmpty()){
        var temp : Array<Int> = q.peek();
        var y = temp[0];
        var x = temp[1];

        q.poll();

        for (i in 0..3){
            var ny = y + dy[i];
            var nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
            if (arr[ny][nx] == 0 || visited[ny][nx] != 0) continue;
            visited[ny][nx] = visited[y][x] +1;
            var next = arrayOf(ny,nx);
            q.add(next);
        }
    }
    print(visited[n-1][m-1])
}
