//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String A = br.readLine().trim();
            Solution ob = new Solution();
            String ans = ob.FirstNonRepeating(A);
            out.println(ans);
        }
        out.close();
    }
}

// } Driver Code Ends


class Solution
{
    public String FirstNonRepeating(String A)
    {
        // code here
        int[] count = new int[26]; // Array to keep track of character frequencies
        Queue<Character> queue = new LinkedList<>(); // Queue to maintain the order of characters
        
        StringBuilder result = new StringBuilder();
        
        for (char ch : A.toCharArray()) {
            count[ch - 'a']++; // Increment the count of the character
            
            // Add the character to the queue if its count is 1
            if (count[ch - 'a'] == 1) {
                queue.offer(ch);
            }
            
            // Remove characters from the queue if their count is more than 1
            while (!queue.isEmpty() && count[queue.peek() - 'a'] > 1) {
                queue.poll();
            }
            
            if (queue.isEmpty()) {
                result.append('#');
            } else {
                result.append(queue.peek());
            }
        }
        
        return result.toString();
    }
}
