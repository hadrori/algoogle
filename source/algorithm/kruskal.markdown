---
layout: page
title: "Kruskal法"
comments: true
sharing: true
---

#### 基本情報
  
***

計算量 | {% m %}O(E \log V){% em %}
用途| 最小全域木(森)を求める
  
E := 辺の数  
V := 頂点数  
  
  
#### 解説

***

グラフの辺のリストをコストの小さい方から処理していき, 辺の両端の頂点が同じ木に属していなければその辺を使う.  
同じ木に属しているかどうかの判定には[Union-Find](./union-find.html)を利用する.  

#### コード

***

{% include_code algorithm/kruskal.cpp %}


#### 問題

***  
{% for post in site.tags['spanning-tree'] %}
* [{{post.title | cdata_escape}}]({{post.url}})
{% endfor %}