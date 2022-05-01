解法: 
- 算法: 快慢指针,模拟
- 时间复杂度: <img src="https://render.githubusercontent.com/render/math?math=O(n)">
- 空间复杂度可以用快慢指针实现<img src="https://render.githubusercontent.com/render/math?math=O(1)">,只需用`slow`记录操作字符串后的最后一个位置,用`resize(slow)`得到处理完毕的字符串
```
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        extract(s),extract(t);
        return s==t;
    }
    void extract(string& s){
        int slow=0;
        for(auto c:s){
            if(c=='#') {
                if(slow>0) slow--;
            }else s[slow++]=c;
        }
        s.resize(slow);
    }
};
```


<h2><a href="https://leetcode.com/problems/backspace-string-compare/">844. Backspace String Compare</a></h2><h3>Easy</h3><hr><div><p>Given two strings <code>s</code> and <code>t</code>, return <code>true</code> <em>if they are equal when both are typed into empty text editors</em>. <code>'#'</code> means a backspace character.</p>

<p>Note that after backspacing an empty text, the text will continue empty.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "ab#c", t = "ad#c"
<strong>Output:</strong> true
<strong>Explanation:</strong> Both s and t become "ac".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "ab##", t = "c#d#"
<strong>Output:</strong> true
<strong>Explanation:</strong> Both s and t become "".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "a#c", t = "b"
<strong>Output:</strong> false
<strong>Explanation:</strong> s becomes "c" while t becomes "b".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code><span>1 &lt;= s.length, t.length &lt;= 200</span></code></li>
	<li><span><code>s</code> and <code>t</code> only contain lowercase letters and <code>'#'</code> characters.</span></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Can you solve it in <code>O(n)</code> time and <code>O(1)</code> space?</p>
</div>
