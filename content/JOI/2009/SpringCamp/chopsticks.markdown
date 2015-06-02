---
layout: post
title: "JOI 春合宿 2009 Chopsticks"
date: 2014-09-09T00:43:00+09:00
comments: true
category: JOI
tags: [dp]
---

[Chopsticks](http://joisc2009.contest.atcoder.jp/tasks/joisc2009_chopsticks)

#### 問題概要

****

橋をN個の部分に分けて, それぞれの場所に塗る色が決まっている.  
一度に塗れるのは連続した区間だけ.  
重ね塗りをすることもできる(その場合色は上書きされる).  
最小で何回塗れば目的の色にできるか.

#### 解法

****

DPする.  
dp\[l\]\[r\] := 区間\[l,r)を正しく塗るのに必要な最小回数  
とすれば, 区間\[l,r)はそれを2つに分解したものの和のうち最小になるものになるはず.  
ただし区間の始点と終点が同じ文字の場合, 1回塗るのを省けることに注意する.

#### コード

****

{{< includeCode "/JOI/2009/Chopsticks.cpp" "cpp" >}}
