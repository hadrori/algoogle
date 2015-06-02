---
layout: post
title: "ACM-ICPC Tokyo Regional 2014 D Space Golf"
date: 2014-10-24T03:06:00+09:00
comments: true
category: ICPC
tags: [math]
---

[Space Golf](http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=ICPCOOC2014&pid=D)

#### 問題概要

****

弾を射出して距離dの位置の地面にちょうど当てたい.  
バウンドがb回まで許される.  
途中に障害物が立っているので避けなければならない.  
以上を満たす最小の初速を求めよ

#### 解法

****

バウンド回数ごとに分けて考える.  
長さxを飛ばすのに必要な初速は発射角を`$\theta$`とすると  

<div> $ {\displaystyle

\sqrt{\frac{x}{sin(2\theta)}}

} $</div>

つまり発射角は45度が基本的に最適.  
45度で不可能なら可能な最小の角が最適.  
正確には45度に一番近いものだが, 45度が無理ならそれ未満も無理なので最小の角になる.  
あとはバウンド回数ごとにminを取れば良い

#### コード

****

{{< includeCode "/ICPC/2014/Tokyo/D.cpp" "cpp" >}}
