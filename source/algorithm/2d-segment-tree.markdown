---
layout: page
title: "Segment Tree(2D RMQ)"
comments: true
sharing: true
---

#### 基本情報
  
***

計算量(構築) | {% m %}O(HW){% em %}
計算量(クエリ) | {% m %}O(\log H\log W){% em %}

H : 高さ  
W : 幅
  
#### 解説

***

単純にSegment Treeを2次元に拡張したもの.

#### コード

***

{% include_code algorithm/2d-segtree.cpp %}

#### 問題

***

[AOJ 1068 School of Killifish](/aoj/1068/)
