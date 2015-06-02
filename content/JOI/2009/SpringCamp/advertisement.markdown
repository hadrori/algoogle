---
layout: post
title: "JOI 春合宿 2009 Advertisement"
date: 2014-09-06T16:24:00+09:00
comments: true
category: JOI
tags: [strongly-connected-component]
---

[Advertisement](http://joisc2009.contest.atcoder.jp/tasks/joisc2009_advertisement)

#### 問題概要

****

誰が誰の連絡先を知っているかの情報が与えられる.  
このとき, 情報を最小何人に伝えれば全員に情報が行き渡ることができるか

#### 解法

****

有向グラフを考える.  
基本的には自分の連絡先を誰にも知られていない人に伝える.  
しかし閉路が存在するので閉路を潰してからそれを考える.  
閉路を潰すには強連結成分分解してidを振りなおしてやれば良い.  
あとは各強連結成分に他の成分から入ってくる辺が存在するかチェックしてやればよい.

#### コード

****

{{< includeCode "/JOI/2009/Advertisement.cpp" "cpp" >}}
