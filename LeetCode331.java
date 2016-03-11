//accepted
//是否考虑过把preorder换成其他order

public class Solution {
    public boolean isValidSerialization(String preorder) {
        String[] nodes = preorder.split(",");
        int sum = 1;
        for(String node:nodes) {
            sum--;
            if(sum < 0) {return false;}
            if(!node.equals("#")) {sum = sum+2;}
        }
        if(sum!=0) {return false;}
        return true;
    }
}