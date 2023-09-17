import java.util.ArrayList;
import java.util.List;

class BinaryWatch {
    public List<String> readBinaryWatch(int turnedOn) {
        List<String> result = new ArrayList<String>();

        // hours
        for (int h = 0; h < 12; h++) {
            // minutes
            for (int m = 0; m < 60; m++) {
                if (Integer.bitCount(h) + Integer.bitCount(m) == turnedOn) {
                    result.add(String.format("%d:%02d", h, m));
                }
            }
        }

        return result;
    }


    // Best Solution
    public List<String> bestSolution(int turnedOn) {
        List<String> times = new ArrayList<>();
        for (int h = 0; h < 12; h++)
            for (int m = 0; m < 60; m++)
                if (Integer.bitCount(h * 64 + m) == turnedOn)
                    times.add(String.format("%d:%02d", h, m));
        return times;
    }
}
