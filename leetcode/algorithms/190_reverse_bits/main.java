class ReverseBits {
   /**
    * Complexities:
    *   - Time Complexity: O(1)
    *   - Space Complexity: O(1)
    */
   public int reverseBits(int n) {
      StringBuilder stringBuilder = new StringBuilder(Integer.toBinaryString(n)).reverse();

      while (stringBuilder.length() < 32) {
         stringBuilder.append("0");
      }

      return (int) Long.parseLong(stringBuilder.toString(), 2);
   }


   // Solution
   /**
    * Solution 1
    * 
    * Complexities:
    *   - Time Complexity: O(1)
    *   - Space Complexity: O(1)
    */
   public int solution1(int n) {
      int result = 0;

      for (int i = 0; i < 32; i++) {
         result <<= 1;

         result |= (n & 1);

         n >>>= 1;
      }

      return result;
   }

   /**
    * Solution 2
    * 
    * Divide and Conquer
    * 
    * Complexities:
    *   - Time Complexity: O(1)
    *   - Space Complexity: O(1)
    */
   public int solution2(int n) {
      n = ((n & 0xffff0000) >>> 16) | ((n & 0x0000ffff) << 16);
      n = ((n & 0xff00ff00) >>> 8) | ((n & 0x00ff00ff) << 8);
      n = ((n & 0xf0f0f0f0) >>> 4) | ((n & 0x0f0f0f0f) << 4);
      n = ((n & 0xcccccccc) >>> 2) | ((n & 0x33333333) << 2);
      n = ((n & 0xaaaaaaaa) >>> 1) | ((n & 0x55555555) << 1);

      return n;
   }
}
