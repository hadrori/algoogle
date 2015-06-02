---
layout: post
title: "Codeforces 396C On Changing Tree"
date: 2014-07-03T23:23:00+09:00
comments: true
category: Codeforces
tags: [tree, binary-indexed-tree]
---

[On Changing Tree](http://codeforces.com/contest/396/problem/C)

#### 問題概要

****

木に対して以下のクエリを処理しろ

* 頂点vを根とする部分木の各頂点uにx-k\*(depth[u]-depth[v])を加えろ
* 頂点vの値を答えよ

#### 解法

****

オイラーツアーして木の頂点をdfs順の列にする.  
こうすることで各頂点を根とする部分木を区間で得られる.  
1つ目のクエリについて, 各頂点にx+k\*depth[v]を加えると考える.  
そうすると, 各頂点に足された数の総和は区間の始めに足して終わりに引くのとで累積和を考えればよい.  
あとは足しすぎた分を引くことを考える.  
拡張点はk\*depth[u]だけ多く足されている. depth[u]は定数なのでその頂点に関係する各kの総和が分かればよい.  
これも同じように累積和をとればよいことがわかる.  
  
2つ目のクエリは, 上の考察から1つ目の累積和から2つ目の累積和と深さの積を引けば良い.
  
区間の和はBITで効率的に管理できるので, BITを2つ用意してこれを実装する.

#### コード

****

{{< includeCode "/Codeforces/396C.cpp" "cpp" >}}
