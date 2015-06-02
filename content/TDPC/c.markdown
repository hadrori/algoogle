---
layout: post
title: "Typical DP Contest C - トーナメント"
date: 2014-05-13T17:20:00+09:00
comments: true
category: TDPC
tags: [dp]
---

[C - トーナメント](http://tdpc.contest.atcoder.jp/tasks/tdpc_tournament)

#### 問題概要

****

#### 解法

****


m人目がnラウンド目を勝つ確率をメモ化再帰した #Code1  

<div> $ {\displaystyle

memo[m][n] = \sum_{i = left}^{right} memo[m][n-1] * memo[i][n-1] /(1 + 10^{(R_i-R_m)/400})

} $</div>

left, rightは2分木のmのn-1ラウンド目のところの兄弟を根とした葉の範囲  

![tdpc-c](/images/tdpc-c-01.png)

DP解 #Code2  

<div> $ {\displaystyle

 dp[j][0] = 0

} $</div>

<div> $ {\displaystyle

 dp[j][i] = \sum_{a = left}^{right} dp[j][i-1] * dp[a][i-1] /(1 + 10^{(R_a-R_j)/400})

} $</div>


#### コード

****

\#code1

{{< includeCode "/TDPC/C.d" "d" >}}

\#code2

{{< includeCode "/TDPC/C.cpp" "cpp" >}}
