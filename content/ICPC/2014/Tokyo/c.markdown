---
layout: post
title: "ACM-ICPC Tokyo Regional 2014 C Shopping"
date: 2014-10-24T03:06:00+09:00
comments: true
category: ICPC
tags: [implementation]
---

[Shopping](http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=ICPCOOC2014&pid=C)

#### 問題概要

****

0が入り口, n+1が出口の道に1~nの店がある.  
dに行ってからcに行きたいという情報がm個来る.  
ただしc＜d  
これらを満たしつつ全ての店を回るのに必要な最小の移動距離を求めよ


#### 解法

****

与えられる各順番について, その区間はちょうど1回往復する.  
つまり被った区間はマージしてしまえばよい.  
被覆される区間の長さ\*2+n+1  
が答え

#### コード

****

{{< includeCode "/ICPC/2014/Tokyo/C.cpp" "cpp" >}}
