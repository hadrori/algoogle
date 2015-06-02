---
layout: post
title: "JOI 春合宿 2007 SALT TREE XV"
date: 2014-08-26T21:37:00+09:00
comments: true
category: JOI
tags: [tree]
---

[SALT TREE XV](http://joisc2007.contest.atcoder.jp/tasks/joisc2007_salt)

#### 問題概要

****

木が与えられる. 2人のプレイヤーは交互に以下のいずれかの操作をし, 最初に操作ができなくなった方が負ける. 先手は必ず勝てるので, AIに必ず勝つプログラムを書け.  

* まだ取られていない頂点を1つ取る. この際その頂点に張られている辺も取られる.
* まだ取られていない辺を1つ取る.


#### 解法

****

相手の番に辺の数も頂点の数も偶数になるように頂点か辺を取れば良い.


#### コード

****

{{< includeCode "/JOI/2007/Salt.cpp" "cpp" >}}
