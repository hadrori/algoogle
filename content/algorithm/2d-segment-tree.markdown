---
type: algorithm
title: "Segment Tree(2D RMQ)"
comments: true
sharing: true
---

#### 基本情報
  
***

計算量(構築) | `$O(HW)$`
計算量(クエリ) | `$O(\log H\log W)$`

H : 高さ  
W : 幅
  
#### 解説

***

単純にSegment Treeを2次元に拡張したもの.

#### コード

***

{{< includeCode "/algorithm/2d-segtree.cpp" "cpp" >}}

#### 問題

***

[AOJ 1068 School of Killifish](/AOJ/1068/)
