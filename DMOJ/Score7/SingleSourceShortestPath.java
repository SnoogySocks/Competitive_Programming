import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;

    static ArrayList<road>[] roads;

    public static void main(String[] args) throws IOException {

        int numHouses = readInt(), numRoads = readInt();

        roads = new ArrayList[numHouses + 1];
        for (int n = 1; n <= numHouses; n++) {
            roads[n] = new ArrayList<>();
        }
        for (int n = 0; n < numRoads; n++) {
            int x = readInt();
            int y = readInt();
            int seconds = readInt();

            roads[x].add(new road(y, seconds));
            roads[y].add(new road(x, seconds));
        }
        for (int n = 1; n <= numHouses; n++) {
                pr.println(SSSP(numHouses, n));
        }

        pr.close();

    }
    static int SSSP (int numHouses, int houseOfDate) {

        boolean isFastestRoute = false;
        int[] time = new int[numHouses + 1];
        Arrays.fill(time, Integer.MAX_VALUE);
        time[1] = 0;

        PriorityQueue<road> scenarios = new PriorityQueue<>();
        scenarios.add(new road(1, 0));

        while (!scenarios.isEmpty() && !isFastestRoute) {

            road cur = scenarios.poll();
            if (cur.seconds <= time[cur.house]) {

                for (road adjHouse : roads[cur.house]) {

                    if (time[cur.house] + adjHouse.seconds < time[adjHouse.house]) {
                        time[adjHouse.house] = time[cur.house] + adjHouse.seconds;
                        scenarios.add(new road(adjHouse.house, time[adjHouse.house]));
                    }
                    if (!scenarios.isEmpty() && time[houseOfDate] < scenarios.peek().seconds) {
                        isFastestRoute = true;
                        break;
                    }

                }

            }

        }

        return (time[houseOfDate] != Integer.MAX_VALUE) ? time[houseOfDate] : -1;
    }
    public static class road implements Comparable<road> {
        int house;
        int seconds;
        public road(int house, int seconds) {
            this.house = house;
            this.seconds = seconds;
        }
        @Override
        public int compareTo(road x) {
            return seconds - x.seconds;
        }
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine().trim());
        }
        return st.nextToken();
    }
    static long readLong() throws IOException {
        return Long.parseLong(next());
    }
    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }
    static double readDouble() throws IOException {
        return Double.parseDouble(next());
    }
    static String readLine() throws IOException {
        return br.readLine().trim();
    }
}
