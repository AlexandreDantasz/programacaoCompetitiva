using System;
using System.Collections.Generic;

class Answer
{
    public string strResponse { get; set; } = string.Empty;
    public bool status = false;
}

class Codeforces 
{
    private static Answer Solution(string s, string t)
    {
        int pointerA= 0, pointerB = 0;
        char[] sTemp = s.ToCharArray();
        Answer answer = new Answer();

        while (pointerA < sTemp.Length && pointerB < t.Length)
        {
            if (sTemp[pointerA] != '?' && sTemp[pointerA] != t[pointerB])
                pointerA++;
            else
                sTemp[pointerA++] = t[pointerB++];
        }

        answer.status = (pointerB == t.Length);
        answer.strResponse = (new string(sTemp)).Replace('?', 'a');
        return answer;

    }
    
    public static void Main(string[] args)
    {
        int c = int.Parse(Console.ReadLine());

        while (c-- != 0)
        {
            string s = Console.ReadLine(), t = Console.ReadLine();
            var ans = Solution(s, t);

            if (ans.status)
            {
                Console.WriteLine("YES");
                Console.WriteLine(ans.strResponse);
            }
            else 
                Console.WriteLine("NO");
        }
    }
}