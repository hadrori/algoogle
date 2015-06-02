---
layout: post
title: "Codeforces 459C Pashmak and Buses"
date: 2014-08-16T18:40:00+09:00
comments: true
category: Codeforces
tags: [math]
---

[Pashmak and Buses](http://codeforces.com/contest/459/problem/C)

#### 問題概要

****

n人をk台のバスに割り当てるのをd日分考えるとき, どの2人もd日間ずっと一緒に割り当てられることがないように割り当てろ.  
無理なら−1

#### 解法

****

n人にそれぞれ0からn-1の番号を割り当てる.  
またバスに割り当てる方法は`$k^d$`ある.  
つまりn-1までがk進法でd桁以内で全て区別可能ならそのような割り当てが存在して, それはk進数で表現した番号になる.  
表現出来ない場合は`$k^d \leq n-1$`となるとき.  
両辺logを取れば`$ d \log k \leq \log (n-1) $`  

#### コード

****

{{< includeCode "/Codeforces/459C.cpp" "cpp" >}}
