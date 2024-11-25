import java.util.Scanner

var arr : Array<Int> = Array(9){0};
var psum :Int =0;
fun main(){
    val sc = Scanner(System.`in`)
    for (i in 0..<9){
        var temp : Int = sc.nextInt();
        psum += temp;
        arr[i] = temp;
    }
    var a : Int = 0;
    var b: Int =0;
    for (i in 0..<9){
        for (j in i+1..<9){
            if (psum-(arr[i] + arr[j]) == 100){
                a = i;
                b = j;
            }
        }
    }
    var ret : Array<Int> = Array(7){0};
    var j : Int =0;
    for (i in 0..<9){
        if (i == a || i == b)continue;
        ret[j] = arr[i];
        j++;
    }
    ret.sort();
    for (i in ret){
        println(i);
    }
}