---
layout: post
title: "JOI 春合宿 2007 Mall"
date: 2014-08-26T01:38:00+09:00
comments: true
category: JOI
tags: [imos-method]
---

[Mall](http://joisc2007.contest.atcoder.jp/tasks/joisc2007_mall)

#### 問題概要

****

h\*wのマスに使用可能な場所とそうでない場所がある.  
購入可能ならそのコストが, そうでないならｰ1が入力で与えられる.  
今b\*aのエリアを買いたい.  
その最小のコストを求めよ. ただし必ず買えるようなエリアが1つは存在するとする.

#### 解法

****

imos法で2次元累積和をとって最小値を求めれば良い.  
購入不可能な場所は適当に大きい値を入れておく.

#### コード

****

{{< includeCode "/JOI/2007/Mall.cpp" "cpp" >}}
