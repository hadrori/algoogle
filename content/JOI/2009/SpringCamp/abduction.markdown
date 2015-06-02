---
layout: post
title: "JOI 春合宿 2009 Abduction"
date: 2014-09-06T03:54:00+09:00
comments: true
category: JOI
tags: [dp]
---

[ABduction](http://joisc2009.contest.atcoder.jp/tasks/joisc2009_abduction)

#### 問題概要

****

h\*wの格子上を移動した時の左右の方向転換だけわかっている(その格子からはみ出るような移動はない).  
このとき, 左下から右上に行く方法は何通りあるか

#### 解法

****

縦方向の移動と横方向の移動を分けて考える.  
左か下に行くときを負の距離の移動とすると  
縦方向の移動の総和はh,  
横方向の移動の総和はwになる.  
  
よって各方向についてDPしてやればよい.  
ある移動で移動する距離で配るDPをする感じ.  
dp\[i\] := 距離iになる場合の数  
として, 更新は累積和を取る感じでやればよい(移動0が許されないことに注意する).  

#### コード

****

{{< includeCode "/JOI/2009/Abduction.cpp" "cpp" >}}
