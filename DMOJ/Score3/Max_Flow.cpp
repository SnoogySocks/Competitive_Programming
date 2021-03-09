// https://dmoj.ca/problem/acmtryouts0a
// 02/2021

import java.io.*;
import java.util.*;

public class Main {
    
    static Scanner scr = new Scanner(System.in);
    public static void main(String[] args) {
        
        // Get the test cases
        int t = scr.nextInt();
        for (int i = 0; i<t; ++i) {
            
            // Get the problem size
            int n = scr.nextInt();
            
            // Record the max value
            int max = 0;
            for (int j = 0; j<n; ++j) {
                int a = scr.nextInt();
                
                // Find the max value
                max = Math.max(max, a);
            }
            System.out.println(max);
        }
        
    }
}
