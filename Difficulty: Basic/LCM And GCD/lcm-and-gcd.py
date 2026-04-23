class Solution:
    def lcmAndGcd(self, a : int, b : int) -> List[int]:
        original_a,original_b = a,b
        
        while(b>0):
            a,b=b,a%b
        
        gcd=a;
        
        lcm = original_a*original_b // gcd;
            
        return [lcm,gcd];
                