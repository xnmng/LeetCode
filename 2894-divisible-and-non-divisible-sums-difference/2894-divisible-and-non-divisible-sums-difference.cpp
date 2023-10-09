class Solution {
public:
    int differenceOfSums(int n, int m) {
        /*
            sum of nums [1, ..., n] := n * (n+1) / 2
            
            number of elements that are divisible by m from [1, ..., n] = (n / m)
            
            first (n / m) elements divisible by m :=
                m = 1 * m
                2m = 2 * m
                ...
                km = k * m  (where k = n / m)
                
            sum of first elements divisible by m := m + ... + km
                                                    
                                                    = (m) * (1 + ... + k)
                                                    
                                                    = (m) * (k) * (k + 1) / 2
                                                        
            ans = nums in [1, ..., n] not divisible by m
                    - nums in [1, ..., n] divisible by m
                
                = nums in [1, ..., n] - nums in [1, ..., n] divisible by m
                    - nums in [1, ..., n] divisible by m
                
                = nums in [1, ..., n] - 2 * nums in [1, ..., n] divisible by m

                = (n * (n+1) / 2) - 2 * ((m) * (k) * (k + 1) / 2)
                
                = (n * (n+1) / 2) - 2 * ((m) * (n / m) * ((n / m) + 1) / 2) 
                    because we know k = n / m
        */
        return n * (n+1) / 2 - 2 * (m * (n / m) * ((n / m) + 1) / 2);
    }
};