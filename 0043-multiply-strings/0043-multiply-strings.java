class Solution {
    static char [] hash={'0','1','2','3','4','5','6','7','8','9'};

    public String multiply(String num1, String num2) {

        if(num1.compareTo("0")==0 || num2.compareTo("0")==0)
            return "0";

        int len=num2.length();
        StringBuilder product=new StringBuilder();
        
        for(int i=len-1;i>-1;i--)
        {
            StringBuilder temp=mul(num1, num2.charAt(i));
            temp=addZero(temp, len-1-i);
            System.out.println("Individual: "+temp);
            product=add(product, temp);
            System.out.println("After Addition: "+product);
        }

        return product.toString();    
    }

    public static StringBuilder mul(String num1, char num2)
    {
        int carry=0;
        int t=0;
        int len=num1.length();

        StringBuilder product= new StringBuilder();

        for(int i=len-1;i>-1;i--)
        {
            t=carry+( num1.charAt(i)-'0' )*( num2-'0' );
            carry=t/10;
            product.insert(0, hash[t%10]);
        }

        if(carry!=0)
            product.insert(0, hash[carry]);

        return product;
    }

    public static StringBuilder addZero(StringBuilder str, int num) {
        for (int i = 0; i < num; i++)
            str.append('0');

        return str;
    }

        public static StringBuilder add(StringBuilder num1, StringBuilder num2) {
        StringBuilder sum = new StringBuilder();
        int i = num1.length() - 1;
        int j = num2.length() - 1;

        int carry = 0;

        while (i > -1 && j > -1) {
            int t = carry + num1.charAt(i) - '0' + num2.charAt(j) - '0';
            sum.insert(0, hash[t % 10]);
            carry = t / 10;
            i--;
            j--;
        }

        while (i > -1) {
            int t = carry + num1.charAt(i) - '0';
            sum.insert(0, hash[t % 10]);
            carry = t / 10;
            i--;
        }

        while (j > -1) {
            int t = carry + num2.charAt(j) - '0';
            sum.insert(0, hash[t % 10]);
            carry = t / 10;
            j--;
        }

        if (carry == 1)
            sum.insert(0, '1');

        return sum;
    }

}