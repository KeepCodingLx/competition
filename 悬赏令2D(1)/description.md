# 最大值计数

## Limits
时间限制：1s

空间限制：256MB

## Description
记一个数列的“MC值”为该数列中最大值的出现次数。例如，数列$1,3,4,1,3,4$中，最大值为$4$，且$4$出现了$2$次，则该数列的“MC值”为$2$。

小F有一个长度为$n$的数列$\{a_n\}$，其中的每一个数都是正整数，且每一个数都**小于等于**$m$。现在，请你帮小F求出所有可能的$\{a_n\}$的“MC值”之和。由于答案可能很大，请对$998244353$取模。

## Input
仅一行，$2$个数，依次表示$n,m$。

## Output
仅一行，一个数，表示所求答案。

## Samples

#### Sample Input 1
```
2 2
```

#### Sample Output 1
```
6
```

#### Sample Input 2
```
4 3
```

#### Sample Output 2
```
144
```

#### Explanation
在第一组样例中，所有可能的数列及其MC值如下：

|数列|MC值|
|---|---|
|1,1|2|
|1,2|1|
|2,1|1|
|2,2|2|

因此答案为$2+1+1+2=6$。

## Data Range
|子任务|特殊性质|分值|
|---|---|---|
|1|$n^m\le 10^7$|$10$|
|2|$mn \le 10^7$|$20$|
|3|$m\le 10^6$|$20$|
|4|$n\le 5000$|$20$|
|5|无|$30$|

对于100%的数据，$1 \le mn \le 10^{12}$。