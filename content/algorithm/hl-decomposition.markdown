---
type: page
title: "HL分解"
comments: true
sharing: true
---

#### 基本情報
  
***

計算量(構築) | `$O(N)$`
計算量(LCA) | `$O(\log N)$`
  
N := 頂点数

#### 解説

***

木のパスを重さごとに分割する.  
ある頂点vから伸びる重い辺とは, vの子のうち部分木の大きさがが最大の頂点への辺のこと.  
これによって作られる連続するHeavy-Edgeをまとめて列として扱うことができる.  
各辺集合をSegment-Treeで管理することが多い.  
[Heavy-Light Decomposition](http://math314.hateblo.jp/entry/2014/06/24/220107)がよくまとまっている.

#### コード

***

{{< includeCode "/algorithm/hl-decomposition.cpp" "cpp" >}}


#### 問題

***  
{% for post in site.tags['heavy-light-decomposition'] %}
* [{{post.title | cdata_escape}}]({{post.url}})
{% endfor %}
