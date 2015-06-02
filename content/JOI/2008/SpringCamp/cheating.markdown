---
layout: post
title: "JOI 春合宿 2008 Cheating"
date: 2014-09-04T02:36:00+09:00
comments: true
category: JOI
tags: [binary-search]
---

[Cheating](http://joisc2008.contest.atcoder.jp/tasks/joisc2008_cheating)

#### 問題概要

****

m人の要注意人物がいる.  
監視カメラがn個あってこれらの配置を考えたい.  
要注意人物が横と縦のどちらでも監視されるようにしたいとき, 監視カメラがカバーしなければいけない幅の最大値の最小を求めよ

#### 解法

****

幅を2分探索すればよい.  
判定はまだ監視されてないならその点を端として監視カメラを設置していってn個で縦横をカバーできるか見る.  


#### コード

****

{{< includeCode "/JOI/2008/Cheating.cpp" "cpp" >}}
