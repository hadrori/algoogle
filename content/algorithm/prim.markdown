---
type: page
title: "Prim法"
comments: true
sharing: true
---

#### 基本情報
  
***

計算量 | `$O(E \log V)$`
用途| 最小全域木を求める
  
E := 辺の数  
V := 頂点数  

  
#### 解説

***

すでに到達した頂点の集合からまだ到達していない頂点の集合への辺のうち, コストが最小のものを選んでいくことで最小全域木を構成する.  
Dijkstra法と似ている.  

#### コード

***

{{< includeCode "/algorithm/prim.cpp" "cpp" >}}


#### 問題

***  

{% for post in site.tags['spanning-tree'] %}
* [{{post.title | cdata_escape}}]({{post.url}})
{% endfor %}
