---
type: page
title: "最小費用流"
comments: true
sharing: true
---

#### 基本情報
  
***

計算量 | `$O(FE\log V)$`
用途| 最大流を求める
  
E := 辺の数
V := 頂点数
F := 流量

#### 解説

***

#### コード

***

{{< includeCode "/algorithm/min-cost-flow.cpp" "cpp" >}}


#### 問題

***  

{% for post in site.tags['min-cost-flow'] %}
* [{{post.title | cdata_escape}}]({{post.url}})
{% endfor %}
