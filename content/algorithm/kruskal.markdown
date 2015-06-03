---
type: algorithm
title: "Kruskal法"
tags: [spanning-tree]
comments: true
sharing: true
---

#### 基本情報
  
***
 | 
|:--|:--|
計算量 | `$O(E \log V)$`
用途| 最小全域木(森)を求める
  
E := 辺の数  
V := 頂点数  
  
  
#### 解説

***

グラフの辺のリストをコストの小さい方から処理していき, 辺の両端の頂点が同じ木に属していなければその辺を使う.  
同じ木に属しているかどうかの判定には[Union-Find](./union-find.html)を利用する.  

#### コード

***

{{< includeCode "/algorithm/kruskal.cpp" "cpp" >}}


#### 問題

***  
