import java.lang.*;
import java.util.*;
import java.math.BigInteger;

class mmax{
	public static void main(String[] args){
		Scanner ip=new Scanner(System.in);
		long t = ip.nextInt();
		while(t!=0){
			long ans=0;
			BigInteger n = new BigInteger(ip.next());
			BigInteger k = new BigInteger(ip.next()); 
			long cnt1 = (k.mod(n)).longValue();
			long n1 = n.longValue();
			long cnt0 = cnt1-n1;
			cnt0 = Math.abs(cnt0);
			if( cnt1==cnt0 ){
				System.out.println(2*cnt1-1);
			}
			else if( cnt1<cnt0){
				System.out.println(2*cnt1);
			}
			else{
				System.out.println(2*cnt0);
			}
			t-=1;
		}
	}
}