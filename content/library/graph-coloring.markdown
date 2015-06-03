---
type: algorithm
title: "彩色数"
tags: [graph-coloring]
comments: true
sharing: true
---

#### 基本情報
  
***

 | 
|:--|:--|
計算量 | `$O(2^{N}N)$`
空間 | `$O(N)$`
  
N := 頂点数

#### 解説

***

頂点数Nのグラフの彩色数を求める.  
試しに塗ってみるのではなく, 包除原理を用いることによって求める.  
[指数時間アルゴリズム入門](http://www.slideshare.net/wata_orz/ss-12131479)(P58)を参照のこと.  
  
自明な枝刈り探索によって指数の底を1.6ぐらいに落とせるらしい.  

#### コード

***

{{< includeCode "/algorithm/graph-coloring.cpp" "cpp" >}}

#### 問題

***

