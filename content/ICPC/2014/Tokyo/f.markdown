---
layout: post
title: "ACM-ICPC Tokyo Regional 2014 F There is No Alternative"
date: 2014-10-24T03:06:00+09:00
comments: true
category: ICPC
tags: [spanning-tree]
---

[There is No Alternative](http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=ICPCOOC2014&pid=F)

#### 問題概要

****

最小全域木を作るのに必ず必要になる辺の数とそのコストの和を求めよ

#### 解法

****

最小全域木を作ってみる.  
必ず必要な辺はそれに含まれる.  
あとはその辺それぞれを使わないで最小全域木を作り, 非連結か重さが増える場合必要.

#### コード

****

{{< includeCode "/ICPC/2014/Tokyo/F.cpp" "cpp" >}}
