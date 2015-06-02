---
layout: post
title: "JOI 春合宿 2007 Fiber"
date: 2014-08-28T02:28:00+09:00
comments: true
category: JOI
tags: [union-find]
---

[Fiber](http://joisc2007.contest.atcoder.jp/tasks/joisc2007_fiber)

#### 問題概要

****

グラフが与えられるので, あと何本辺を追加すれば連結になるか

#### 解法

****

Union-Find木でグループを管理して, 各ペアを順に見てまだ違うグループだったら辺を追加する.  
この追加した辺の数を答えれば良い.

#### コード

****

{{< includeCode "/JOI/2007/Fiber.cpp" "cpp" >}}
