import java.util.Scanner

fun main(){
    val sc = Scanner(System.`in`)
    var num = sc.nextInt();
    var str = sc.next();

    if (num == 1){
        var str1 = str.substring(0,1);
        str1 += str.substring(1,str.length);
        println(str1)

        var start =0;
        var str2 = "";
        for (i in 0..<str.length){
            if (i != 0 && str[i] >= 'A' && str[i] <= 'Z') {
                str2 += str.substring(start,i).lowercase();
                str2 += '_';
                start = i;
            }
        }
        str2 += str.substring(start, str.length).lowercase();
        println(str2)

        var str3 = str[0].uppercase();
        str3 += str.substring(1,str.length);
        println(str3)
    }
    else if (num == 2){
        var start = 0;
        var str1 = "";
        for (i in 0..<str.length){
            if (str[i] == '_') {
                if(start == 0) str1 += str.substring(start, i).lowercase();
                else{
                    str1 += str.substring(start,start+1).uppercase()
                    str1 += str.substring(start+1,i)
                }
                start = i+1;
            }
        }
        if(str1.length == 0){
            str1 += str.substring(start,str.length).lowercase();
        }
        else {
            str1 += str.substring(start, start + 1).uppercase();
            str1 += str.substring(start + 1, str.length);
        }
        println(str1)
        println(str)
        var str3 = str1[0].uppercase();
        str3 += str1.substring(1,str1.length);
        println(str3)
    }
    else{
        var str1 = str[0].lowercase();
        str1+= str.substring(1,str.length);
        println(str1);
        var str2 = "";
        var start =0;
        for (i in 0..<str1.length){
            if (str1[i] >= 'A' && str1[i] <= 'Z'){
                str2 += str1.substring(start,i).lowercase();
                str2 += '_';
                start = i;
            }
        }
        str2 += str1.substring(start,str1.length).lowercase();
        println(str2);
        var str3 = str.substring(0,1).uppercase();
        str3 += str.substring(1,str.length);
        println(str3)
    }
}