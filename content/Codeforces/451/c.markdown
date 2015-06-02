---
layout: post
title: "Codeforces 451C Predict Outcome of the Game"
date: 2014-07-25T10:27:00+09:00
comments: true
category: Codeforces
tags: [math]
---

[Predict Outcome of the Game](http://codeforces.com/problemset/problem/451/C)

#### 問題概要

****

3チームがn回試合をする.  
k試合が終わった時点でのチーム1とチーム2, チーム2とチーム3の勝ち数の差の絶対値がそれぞれ与えられる.  
このとき, 残りの試合が終わった時点で全チームの勝ち数が同じになることはあり得るか.

#### 解法

****

nが3で割り切れない場合は少なくとも1チームが負けるのでダメ.  
チーム1の勝ち数をxとすると,  
k = 3*x+d\[0\]+d\[1\]  
が成り立つ. ここでd\[i\]は入力の値ではなく, 勝ち数の差(絶対値を外したもの)  
dの正負をそれぞれ試してそれがkになるとき  
x = (k-d\[0\]-d\[1\])/3  
となる(ただし3で割り切ること)  
あとはこれからチーム2とチーム3の勝ち数が出せるので, どのチームもn/3を超えなければyesになる


#### コード

****

{{< includeCode "/Codeforces/451C.cpp" "cpp" >}}
