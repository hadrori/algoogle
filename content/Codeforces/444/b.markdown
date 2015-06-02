---
layout: post
title: "Codeforces 444B DZY Loves FFT"
date: 2014-08-23T16:45:00+09:00
comments: true
category: Codeforces
tags: [math]
---

[DZY Loves FFT](http://codeforces.com/contest/444/problem/B)

#### 問題概要

****

a, b(aは1~nの順列, bはd個の1とn-d個の0の順列)があるとき

<div> $ {\displaystyle

c_i = max\{a_{j}b_{i-j} \mid j \leq i\}

} $</div>
で表されるcの列を求めよ.

#### 解法

****

dが小さいとき, 1となるbの位置を列挙しておけばそれぞれの位置に対してaの値を見ればcをO(nd)で求められる.  
dが大きいとき, 各位置で1になる確率が高くなるのでaの値が大きいものから最大になる場所を埋めていけば良い.  
既に埋まっている場所を候補から除外しておけば各位置で1になる確率が高いことからどんどん候補が減っていくはず.  
bは擬似乱数によって生成されるので悪意ある入力は考慮しなくて良い.  
今回は候補をpriority_queueに入れて, 現在の値が出現しなくなる位置まで取り出してその位置で最大値になれるか確認するのと, なれない場合ははpriority_queueに戻すという操作で実装した.


#### コード

****

{{< includeCode "/Codeforces/444B.cpp" "cpp" >}}
