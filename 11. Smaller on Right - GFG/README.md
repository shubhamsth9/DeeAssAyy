# 11. Smaller on Right
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given an array <strong>arr</strong>[] of <strong>N</strong> elements. The task is to count maximum number&nbsp;of distinct smaller elements on right side of any array element. For example, in {10, 6, 9, 7, 20, 19, 21, 18, 17, 16}, the result is 4.&nbsp; Note that 20 has maximum 4 smaller elements on right side. Other elements have less count, for example 10 has 3 smaller elements on right side.</span></p>

<p><span style="font-size:18px"><strong>Input:</strong><br>
First line of input contains number of testcases T. For each testcase, first line of input contains number of elements in the array and next line contains array elements.</span></p>

<p><span style="font-size:18px"><strong>Output:</strong><br>
For each testcase, print the maximum count of smaller elements on right side. </span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= T &lt;= 100<br>
1 &lt;= N &lt;= 10<sup>5</sup><br>
1 &lt;= arr[i] &lt;= 10<sup>6</sup></span></p>

<p><span style="font-size:18px"><strong>Example:<br>
Input:</strong><br>
4<br>
10<br>
10 6 9 7 20 19 21 18 17 16<br>
5<br>
5 4 3 2 1<br>
5<br>
1 2 3 4 5</span><br>
<span style="font-size:18px">5<br>
1 2 3 2 1</span></p>

<p><span style="font-size:18px"><strong>Output:</strong><br>
4<br>
4<br>
0<br>
2</span></p>

<p><span style="font-size:18px"><strong>Explanation:</strong></span></p>

<p><span style="font-size:18px"><strong>Testcase 1:</strong> Number of smaller elements on right side of every element (from left to right) in the array are 3 0 1 0 4 3 3 2 1 and 0 respecitvely. Maximum of all these counts is 4.<br>
<strong>Testcase 2:</strong> Number of smaller elements on right side of every element (from left to right) in the array are 4 3 2 1 and 0 respecitvely. Maximum of all these counts is 4.</span></p>
 <p></p>
            </div>