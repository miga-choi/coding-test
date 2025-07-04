class JewelsAndStones {
  int numJewelsInStones(String jewels, String stones) {
    List<int> numsArray = List<int>.filled(128, 0);
    for (int i = 0; i < jewels.length; i++) {
      numsArray[jewels[i].codeUnitAt(0)] = 1;
    }

    int count = 0;
    for (int i = 0; i < stones.length; i++) {
      count += numsArray[stones[i].codeUnitAt(0)];
    }

    return count;
  }


  // Solution
  // Solution 1
  int solution1(String jewels, String stones) {
    int ctr = 0;

    for (int i = 0; i < jewels.length; i++) {
      for (int j = 0; j < stones.length; j++) {
        if (jewels[i] == stones[j]) {
          ctr++;
        }
      }
    }

    return ctr;
  }

  // Solution 2
  int solution2(String jewels, String stones) {
    return stones.split("").where(jewels.contains).length;
  }
}
