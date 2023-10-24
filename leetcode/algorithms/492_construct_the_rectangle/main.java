class ConstructTheRectangle {
    public int[] constructRectangle(int area) {
        int w = Double.valueOf(Math.sqrt(area)).intValue();
        while (area % w != 0) {
            w--;
        }
        int[] result = { area / w, w };
        return result;
    }


    // Best Solution
    public int[] bestSolution(int area) {
        int w = (int) Math.sqrt(area);
        while (area % w != 0) w--;
        return new int[] { area / w, w };
    }
}