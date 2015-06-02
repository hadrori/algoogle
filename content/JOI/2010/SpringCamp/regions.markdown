---
layout: post
title: "JOI 春合宿 2010 Regions"
date: 2014-09-17T00:40:00+09:00
comments: true
category: JOI
tags: [binary-search, dp]
---

[Regions](http://joisc2010.contest.atcoder.jp/tasks/joisc2010_regions)

#### 問題概要

****

頂点数Nの木構造で, 各辺には距離が与えられる.  
この木をM個の木に分解するとき, それぞれの木の直径のうち最大のものを最小化しろ.

#### 解法

****

距離を2分探索する.  
木を根付き木と考えることにする. また頂点vから親への辺の長さをdist\[v\]とする.   
ある直径x以内でM個の木に分割できるかは以下のDPを葉からしながら, 分割する回数を数えれば良い.  
  
dp\[v\] = 頂点vを含む分割された木のうち, vから葉までの最長の距離  
  
頂点vからその親uに辺を伸ばすとき  
dp\[v\]+dist\[v\]がxを超えるならその辺で分割.  
dp\[u\]+dp\[v\]+dist\[v\]がxを超えるなら, 小さくなる方だけ繋いで大きい方の辺で分割(これは直径の両端がv以外でvで折れた形になってるやつ).  
それ以外ならそのまま繋いでmax(dp\[u\], dp\[v\]+dist\[v\])  
  
この分割数がM回未満だったら直径x以内でM個の木に分割できる.

#### コード

****

{{< includeCode "/JOI/2010/regions.cpp" "cpp" >}}
